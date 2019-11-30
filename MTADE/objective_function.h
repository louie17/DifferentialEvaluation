#ifndef DE_OBJECTIVE_FUNCTION_HPP_INCLUDED
#define DE_OBJECTIVE_FUNCTION_HPP_INCLUDED

// MS compatible compilers support #pragma once

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <memory>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <valarray>

#include "de_types.hpp"
#include "processors.hpp"
#include "de_constraints.hpp"

#define PI 3.14159265

/**
* ����Ŀ�꺯���ĳ�����ࡣ
*
* @author louiehan (11/18/2019)
*/
class objective_function
{
private:
	const std::string m_name;
public:
	/**
	* constructs an objective_function object
	*
	* @author louiehan (11/18/2019)
	*
	* @param name the objective function name
	*/
	objective_function(const std::string& name)
		: m_name(name)
	{
	}

	virtual ~objective_function() {}

	/**
	* ����������ʵ��-������Ҫ�Ż���Ŀ�꺯����
	*
	* Ŀ�꺯������һ��double���͵Ĳ������������ؼ������doubleֵ��
	*
	* args�����е�ÿ��������Ӧ��Լ�������е���ͬ���������磬���Ŀ�꺯����Ҫ����������
	* ��Լ��������ǰ����Ԫ������Ϊ����������Լ��������Ŀ�꺯��operator������ʹ��
	* args������ǰ����ֵ��Ϊ�������������Ժ��Դ������е���������ֵ��
	*
	* @author louiehan (11/18/2019)
	*
	* @param args ��������������ͨ����Ŀ�꺯��ʹ�õı�������ö࣬
	*			  ���Ŀ�꺯��ofֻȡ�����е�ǰn��ֵ�������������ֵ��
	*
	* @return double �������ۣ�������Ҫ�Ż���ֵ��
	*/
	virtual double operator()(de::DVectorPtr args) = 0;

	/**
	* An objective function has a name
	*
	* @author louiehan (11/18/2019)
	*
	* @return const std::string&
	*/
	const std::string& name() const { return m_name; }
};

/**
* Smart pointer to an objective function
*/
typedef std::shared_ptr< objective_function > objective_function_ptr;

/**
* Objective function to optimize is the "sphere function":
*
* f(x,y) = x^2 + y^2
*/
class sphere_function :public objective_function
{
public:
	sphere_function()
		: objective_function("sphere function")
	{
	}

	virtual double operator()(de::DVectorPtr args)
	{
		/**
		* The two function arguments are the elements index 0 and 1 in
		* the argument vector, as defined by the constraints vector
		* below
		*/
		double x = (*args)[0];
		double y = (*args)[1];

		return x*x + y*y;
	}
};

class evaluation_route :public objective_function
{
public:
	evaluation_route()
		: objective_function("Route evaluation function")
	{
	}

	/**
	* ����·���ܳ���
	* 
	* @author louie (11/28/2019)
	*
	*/
	void evaluation_length_cost(const std::valarray<double> &norms, double &length_cost)
	{
		for (auto iter:norms)
		{
			length_cost += iter;
		}

	}

	void evaluation_std_variance_cost(const std::valarray<double> &norms, double &std_variance_cost)
	{
		double sum = norms.sum();
		double mean = sum / norms.size(); //��ֵ  

		double accum = 0.0;
		for(auto d:norms) {
			accum += (d - mean)*(d - mean);
		}

		std_variance_cost = sqrt(accum / (norms.size() - 1)); //��׼��
	}

	void evalution_turn_angle_cost(const de::NVector &diff_vector, const std::valarray<double> &norms, double &angle_cost)
	{
		//�����н�
		std::valarray<double> vetorial_angle(0.0,diff_vector.size()-1);
		//ƫ����yaw angle
		std::valarray<double> yaw_angles(0.0, diff_vector.size() - 1);
		//������pitching angle
		std::valarray<double> pitching_angles(0.0, diff_vector.size() - 1);
		//������rolling angle
		std::valarray<double> rolling_angles(0.0, diff_vector.size() - 1);


		for (size_t i = 0; i < diff_vector.size()-1; i++)
		{
			double tmp=diff_vector[i] * diff_vector[i + 1] / (norms[i] * norms[i + 1]);
			de::Node tmpNode = diff_vector[i + 1] - diff_vector[i];
			//�Ծ�����Ϊ�ο���
			if (tmpNode.altitude()==0.0 && tmpNode.longitude()==0.0)
			{
				pitching_angles[i] = 0;
			}
			else
			{
				pitching_angles[i] = atan2(tmpNode.altitude(), tmpNode.longitude())*180.0 / PI;
			}

			if (tmpNode.latitude()==0.0 && tmpNode.altitude()==0.0)
			{
				rolling_angles[i] = 0;
			}
			else
			{
				rolling_angles[i] = atan2(tmpNode.latitude(), tmpNode.altitude())*180.0 / PI;
			}

			if (tmpNode.latitude()==0.0 && tmpNode.longitude()==0.0)
			{
				yaw_angles[i] = 0;
			}
			else
			{
				yaw_angles[i] = atan2(tmpNode.latitude(), tmpNode.longitude())*180.0 / PI;
			} 
						
			if ( tmp>=0 && tmp <= 1 )
			{
				vetorial_angle[i] = acos(tmp) * 180.0 / PI;
			}
			else
			{ 
				vetorial_angle[i] = (tmp>1) ? 0.0 : 180.0;
			}
		}
		 
		//�������ת��ǳ�����ȫ���ƻ�ʩ�ӳͷ�
		angle_cost = vetorial_angle.max();
	}

	//������ʱû�е�����Ϣ������ֻ��������Ͱ�ȫ���и߶Ⱥ��������ڵ�ĸ߶Ƚ��бȽ�
	double evaluation_route_tabu_cost(de::NVectorPtr args, de::constraint_ptr high_constraint)
	{
		double cost;

		return cost;
	}

	double evaluation_route_mission_cost(de::NVectorPtr args, de::constraint_ptr constraints)
	{
		double cost;
		return cost;
	}

	double evaluation_route_survival_cost(de::NVectorPtr args, de::constraint_ptr constraints)
	{
		double cost;
		return cost;
	}

	virtual double operator()(de::NVectorPtr args,de::constraints_ptr constraints)
	{
		double tabu_cost(0), std_variance_cost(0),mission_cost(0),survival_cost(0), length_cost(0), angle_cost(0);

		NVector diff_vector(args->size() - 1, args->at[0]);
		//DVector norms(args->size() - 1, 0);
		std::valarray<double> norms(0.0, args->size() - 1);
		

		for (size_t i = 0; i <args->size() - 1; i++)
		{
			diff_vector[i] = (*args)[i + 1] - (*args)[i];
			norms[i] = ((*args)[i + 1] - (*args)[i]).norm();
		}

		// �������и߶Ⱥ͵���
		double height_cost = evaluation_route_tabu_cost(args,(*constraints)[3]);
		// �����������ľ���
		double mission_cost = evaluation_route_mission_cost(args, (*constraints)[4]);
		// �����������
		double survival_cost = evaluation_route_survival_cost(args, (*constraints)[5]);
		//�������ȴ���
		evaluation_length_cost(norms, length_cost);
		//�����������
		evaluation_std_variance_cost(norms,std_variance_cost);
		// ��Ӧ��
		double cost = 0.1*length_cost + 0.5*survival_cost + 0.3*mission_cost + 0.1*height_cost;

		return cost;
	}

};

#endif //DE_OBJECTIVE_FUNCTION_HPP_INCLUDED