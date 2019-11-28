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
* 具体目标函数的抽象基类。
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
	* 在派生类中实现-它包含要优化的目标函数。
	*
	* 目标函数接受一个double类型的参数向量并返回计算出的double值。
	*
	* args向量中的每个索引对应于约束向量中的相同索引。例如，如果目标函数需要两个变量，
	* 则将约束向量的前两个元素设置为两个变量的约束，并在目标函数operator（）中使用
	* args向量的前两个值作为两个变量。可以忽略此向量中的所有其他值。
	*
	* @author louiehan (11/12/2019)
	*
	* @param args 参数向量。向量通常比目标函数使用的变量数大得多，
	*			  因此目标函数of只取向量中的前n个值，而忽略其余的值。
	*
	* @return double 函数代价，这是需要优化的值。
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