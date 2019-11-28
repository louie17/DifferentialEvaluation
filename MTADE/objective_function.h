#ifndef DE_OBJECTIVE_FUNCTION_HPP_INCLUDED
#define DE_OBJECTIVE_FUNCTION_HPP_INCLUDED

// MS compatible compilers support #pragma once

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <memory>

#include "de_types.hpp"
#include "processors.hpp"

/**
* ����Ŀ�꺯���ĳ�����ࡣ
*
* @author louiehan (11/12/2019)
*/
class objective_function
{
private:
	const std::string m_name;
public:
	/**
	* constructs an objective_function object
	*
	* @author louiehan (11/12/2019)
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
	* @author louiehan (11/12/2019)
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
	* @author louiehan (11/12/2019)
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

	virtual double operator()(de::DVectorPtr args)
	{
		double x = (*args)[0];
		double y = (*args)[1];
		double z = (*args)[2];

		return pow(x, 3) + pow(y, 3) + pow(z, 3);
	}

};

#endif //DE_OBJECTIVE_FUNCTION_HPP_INCLUDED