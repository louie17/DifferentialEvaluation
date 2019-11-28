// MS compatible compilers support #pragma once

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DE_TYPES_HPP_INCLUDED
#define DE_TYPES_HPP_INCLUDED

#include <vector>
#include <exception>

namespace de
{
	/**
	 * 封装一个double类型，主要用于调试和诊断
	 *
	 * @author louiehan (11/11/2019)
	 */
	class Double
	{
	private:
		double m_value;

	public:

		Double(double value)
			: m_value(value)
		{
		}

		Double()
			: m_value(0)
		{
		}

		/**
		 * 重载赋值运算符
		 *
		 * @author louiehan (11/11/2019)
		 *
		 * @param value value to set the Double to
		 *
		 * @return double returns the current value
		 */
		double operator=(double value)
		{
			m_value = value;

			return m_value;
		}

		/**
		 * 定义转换为double的操作符
		 *
		 * @author louiehan (11/11/2019)
		 *
		 * @return double
		 */
		operator double() const
		{
			return m_value;
		}
	};

	/**
	 * a vector of Double instances
	 */
	typedef std::vector< Double > DVector;

	/**
	 * shared pointer to a DVector
	 */
	typedef std::shared_ptr< DVector > DVectorPtr;


	/**
	 * 定义符合 C++标准的DE异常类 (std::exception的MS实现有非标准构造函数)
	 *
	 * @author louiehan (11/11/2019)
	 */
	class exception : public std::exception
	{
	private:
		const std::string m_what;

	public:
		virtual ~exception() throw()
		{
		}
		/**
		 * 构造函数以C字符串作为参数，该参数是与异常相关联的消息
		 *
		 * @author louiehan (11/11/2019)
		 *
		 * @param what
		 */
		exception(const char* what)
			: m_what(what != 0 ? what : "")
		{
		}

		/**
		 * 小心使用——如果异常对象超出范围，则此函数返回的指针无效
		 *
		 * @author louiehan (11/11/2019)
		 *
		 * @return const char* 指向与异常信息相关联的字符串的指针
		 */
		virtual const char* what() const throw()
		{
			return m_what.c_str();
		}
	};

}
#endif //DE_TYPES_HPP_INCLUDED
