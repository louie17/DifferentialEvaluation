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
	 * ��װһ��double���ͣ���Ҫ���ڵ��Ժ����
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
		 * ���ظ�ֵ�����
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
		 * ����ת��Ϊdouble�Ĳ�����
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
	 * ������� C++��׼��DE�쳣�� (std::exception��MSʵ���зǱ�׼���캯��)
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
		 * ���캯����C�ַ�����Ϊ�������ò��������쳣���������Ϣ
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
		 * С��ʹ�á�������쳣���󳬳���Χ����˺������ص�ָ����Ч
		 *
		 * @author louiehan (11/11/2019)
		 *
		 * @return const char* ָ�����쳣��Ϣ��������ַ�����ָ��
		 */
		virtual const char* what() const throw()
		{
			return m_what.c_str();
		}
	};

}
#endif //DE_TYPES_HPP_INCLUDED
