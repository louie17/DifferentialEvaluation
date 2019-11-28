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
		 * 定义返回double类型成员变量的操作符
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
	* 创建个体节点类
	*
	*/
	class Node
	{
	public:
		Node()
			:m_altitude(0), m_latitude(0), m_longitude(0)
		{
		}
		Node(double altitude, double latitude, double longitude)
			:m_altitude(altitude), m_latitude(latitude), m_longitude(longitude)
		{
		}

		/**
		* 重载运算符()
		*
		* @author louiehan (11/11/2019)
		*
		* @param node 用于拷贝赋值的节点
		*
		* @return *this 返回对当前节点的引用
		*/
		Node &operator()(const Node& node)
		{
			m_altitude = node.m_altitude;
			m_latitude = node.m_latitude;
			m_longitude = node.m_longitude;
			return *this;
		}

		/**
		* 重载赋值运算符
		*
		* @author louiehan (11/11/2019)
		*
		* @param node 用于拷贝赋值的节点
		*
		* @return *this 返回对当前节点的引用
		*/
		Node &operator=(const Node& node)
		{
			m_altitude = node.m_altitude;
			m_latitude = node.m_latitude;
			m_longitude = node.m_longitude;
			return *this;
		}

		double norm() const { return sqrt(pow(m_altitude, 2) + pow(m_latitude, 2) + pow(m_longitude, 2)); }

		double altitude() const { return m_altitude; }
		double latitude() const { return m_latitude; }
		double longitude() const { return m_longitude; }

		void setAltitude(const double &altitude) { m_altitude = altitude; }
		void setLatitude(const double &latitude) { m_latitude = latitude; }
		void setLongitude(const double &longitude) { m_longitude = longitude; }

	private:
		double m_altitude;
		double m_latitude;
		double m_longitude;
	};

	/**
	* 重载运算符-
	*
	* @author louiehan (11/11/2019)
	*
	* @param pnode,lnode 相减的两个节点 
	*
	* @return node 返回差分向量
	*/
	Node operator-(const Node &pnode, const Node &lnode)
	{
		Node node(pnode);
		node.setAltitude(pnode.altitude() - lnode.altitude());
		node.setLatitude(pnode.latitude() - lnode.latitude());
		node.setLongitude(pnode.longitude() - lnode.longitude());
		return node;
	}

	/**
	* a vector of Node instances
	*/
	typedef std::vector< Node > NVector;

	/**
	* shared pointer to a NVector
	*/
	typedef std::shared_ptr< NVector > NVectorPtr;

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
