/****************************************************************
*	Copyright(c)2019-2020 四川大学电子信息学院智能控制研究所
*	All right reserved.
*	
*	文件名称：Scenario.hpp
*	功能：提供XML解析数据封装类声明
*	当前版本：1.0
*	作者：韩露
*	完成日期：2019-11-3
******************************************************************/

#ifndef __SCENARIO__
#define __SCENARIO__

#include<stdexcept>
#include<string>
#include<vector>
#include<memory>
#include<type_traits>
#include<cassert>

namespace sce 
{
	class Vertex;
	class Platform;
	class Rf_values;
	class Rf;
	class Pw_values;
	class Pw;
	class Pri_values;
	class Pri;
	class Scan;
	class Erp;
	class Radar_Mode;
	class Emitter;
	class Weapon;
	class Site;
	class Point;
	class Mission;
	class OwnPlatform;
	class Esm;
	class Ecm;
	class WayPoint;
	class Route;
	class Location;
	class DwellSquence;
	class EsmStrategySection;
	class EsmStrategy;
	class EcmStrategySection;
	class EcmStrategy;
	class PlatformSiteRelation;
	class PlatformEmitterRelation;
	class PlatformWeaponRelation;
	class OwnPlatformEsmRelation;
	class EsmEsmStrategyRelation;
	class OwnPlatformEcmRelation;
	class EcmEcmStrategyRelation;
	class OwnPlatformRouteRelation;

	class Error : public std::runtime_error
	{
	public:
		Error (const std::string &msg)
			:std::runtime_error(std::string("Scenario:").append(msg)) 
		{}

	private:

	};

	class Scenario
	{
	public:
		Scenario(void);
		Scenario(std::shared_ptr<Vertex> ,
			std::shared_ptr<Platform> ,
			std::shared_ptr<Emitter> ,
			std::shared_ptr<Weapon> ,
			std::shared_ptr<Site> ,
			std::shared_ptr<OwnPlatform> ,
			std::shared_ptr<Esm> ,
			std::shared_ptr<Ecm> ,
			std::shared_ptr<Route> ,
			std::shared_ptr<EsmStrategy> ,
			std::shared_ptr<EcmStrategy> ,
			PlatformSiteRelation& ,
			PlatformEmitterRelation& ,
			PlatformWeaponRelation& ,
			OwnPlatformEsmRelation& ,
			EsmEsmStrategyRelation& ,
			OwnPlatformEcmRelation& ,
			EcmEcmStrategyRelation& ,
			OwnPlatformRouteRelation& );

		Scenario(std::vector<std::shared_ptr<Vertex>>& ,
			std::vector<std::shared_ptr<Platform>>& ,
			std::vector<std::shared_ptr<Emitter>>& ,
			std::vector<std::shared_ptr<Weapon>>& ,
			std::vector<std::shared_ptr<Site>>& ,
			std::vector<std::shared_ptr<OwnPlatform>>& ,
			std::vector<std::shared_ptr<Esm>>& ,
			std::vector<std::shared_ptr<Ecm>>& ,
			std::vector<std::shared_ptr<Route>>& ,
			std::vector<std::shared_ptr<EsmStrategy>>& ,
			std::vector<std::shared_ptr<EcmStrategy>>& ,
			std::vector<PlatformSiteRelation>& ,
			std::vector<PlatformEmitterRelation>& ,
			std::vector<PlatformWeaponRelation>& ,
			std::vector<OwnPlatformEsmRelation>& ,
			std::vector<EsmEsmStrategyRelation>& ,
			std::vector<OwnPlatformEcmRelation>& ,
			std::vector<EcmEcmStrategyRelation>& ,
			std::vector<OwnPlatformRouteRelation>& );

        bool isVertexEmpty(void) { return m_ptrVertex.empty() ? true : false; }
        bool isPlatformEmpty(void) { return m_ptrPlatform.empty() ? true : false; }
        bool isEmitterEmpty(void) { return m_ptrEmitter.empty() ? true : false; }
        bool isWeaponEmpty(void) { return m_ptrWeapon.empty() ? true : false; }
        bool isSiteEmpty(void) { return m_ptrSite.empty() ? true : false; }
        bool isOwnPlatformEmpty(void) { return m_ptrOwnPlatform.empty() ? true : false; }
        bool isEsmEmpty(void) { return m_ptrEsm.empty() ? true : false; }
        bool isEcmEmpty(void) { return m_ptrEcm.empty() ? true : false; }
        bool isRouteEmpty(void) { return m_ptrRoute.empty() ? true : false; }
        bool isEsmStrategyEmpty(void) { return m_ptrEsmStrategy.empty() ? true : false; }
        bool isEcmStrategyEmpty(void) {	return m_ptrEcmStrategy.empty() ? true : false;	}

        bool isPlatformSiteRelationEmpty(void) { return m_PlatformSiteRelation.empty() ? true : false; }
        bool isPlatformEmitterRelationEmpty(void) { return m_PlatformEmitterRelation.empty() ? true : false; }
        bool isPlatformWeaponRelationEmpty(void) { return m_PlatformWeaponRelation.empty() ? true : false; }
        bool isOwnPlatformEsmRelationEmpty(void) { return m_OwnPlatformEsmRelation.empty() ? true : false; }
        bool isEsmEsmStrategyRelationEmpty(void) { return m_EsmEsmStrategyRelation.empty() ? true : false; }
        bool isOwnPlatformEcmRelationEmpty(void) { return m_OwnPlatformEcmRelation.empty() ? true : false; }
        bool isEcmEcmStrategyRelationEmpty(void) { return m_EcmEcmStrategyRelation.empty() ? true : false; }
        bool isOwnPlatformRouteRelationEmpty(void) { return m_OwnPlatformRouteRelation.empty() ? true : false; }

		
		std::shared_ptr<Vertex> getPtr2Vertex(const unsigned int& pos);
		std::shared_ptr<Platform> getPtr2Platform(const unsigned int& pos);
		std::shared_ptr<Emitter> getPtr2Emitter(const unsigned int& pos);
		std::shared_ptr<Weapon> getPtr2Weapon(const unsigned int& pos);
		std::shared_ptr<Site> getPtr2Site(const unsigned int& pos);
		std::shared_ptr<OwnPlatform> getPtr2OwnPlatform(const unsigned int& pos);
		std::shared_ptr<Esm> getPtr2Esm(const unsigned int& pos);
		std::shared_ptr<Ecm> getPtr2Ecm(const unsigned int& pos);
		std::shared_ptr<Route> getPtr2Route(const unsigned int& pos);
		std::shared_ptr<EsmStrategy> getPtr2EsmStrategy(const unsigned int& pos);
		std::shared_ptr<EcmStrategy> getPtr2EcmStrategy(const unsigned int& pos);

		PlatformSiteRelation& getPlatformSiteRelation(const unsigned int& pos);
		PlatformEmitterRelation& getPlatformEmitterRelation(const unsigned int& pos);
		PlatformWeaponRelation& getPlatformWeaponRelation(const unsigned int& pos);
		OwnPlatformEsmRelation& getOwnPlatformEsmRelation(const unsigned int& pos);
		EsmEsmStrategyRelation& getEsmEsmStrategyRelation(const unsigned int& pos);
		OwnPlatformEcmRelation& getOwnPlatformEcmRelation(const unsigned int& pos);
		EcmEcmStrategyRelation& getEcmEcmStrategyRelation(const unsigned int& pos);
		OwnPlatformRouteRelation& getOwnPlatformRouteRelation(const unsigned int& pos);


		std::vector<std::shared_ptr<Vertex>>& getAllVertex(void);
		std::vector<std::shared_ptr<Platform>>& getAllPlatform(void);
		std::vector<std::shared_ptr<Emitter>>& getAllEmitter(void);
		std::vector<std::shared_ptr<Weapon>>& getAllWeapon(void);
		std::vector<std::shared_ptr<Site>>& getAllSite(void);
		std::vector<std::shared_ptr<OwnPlatform>>& getAllOwnPlatform(void);
		std::vector<std::shared_ptr<Esm>>& getAllEsm(void);
		std::vector<std::shared_ptr<Ecm>>& getAllEcm(void);
		std::vector<std::shared_ptr<Route>>& getAllRoute(void);
		std::vector<std::shared_ptr<EsmStrategy>>& getAllEsmStrategy(void);
		std::vector<std::shared_ptr<EcmStrategy>>& getAllEcmStrategy(void);

		std::vector<PlatformSiteRelation>& getAllPlatformSiteRelation(void);
		std::vector<PlatformEmitterRelation>& getAllPlatformEmitterRelation(void);
		std::vector<PlatformWeaponRelation>& getAllPlatformWeaponRelation(void);
		std::vector<OwnPlatformEsmRelation>& getAllOwnPlatformEsmRelation(void);
		std::vector<EsmEsmStrategyRelation>& getAllEsmEsmStrategyRelation(void);
		std::vector<OwnPlatformEcmRelation>& getAllOwnPlatformEcmRelation(void);
		std::vector<EcmEcmStrategyRelation>& getAllEcmEcmStrategyRelation(void);
		std::vector<OwnPlatformRouteRelation>& getAllOwnPlatformRouteRelation(void);


		bool setPtr2Vertex(const unsigned int& pos, std::shared_ptr<Vertex> ptr2Entity);
		bool setPtr2Platform(const unsigned int& pos, std::shared_ptr<Platform> ptr2Entity);
		bool setPtr2Emitter(const unsigned int& pos, std::shared_ptr<Emitter> ptr2Entity);
		bool setPtr2Weapon(const unsigned int& pos, std::shared_ptr<Weapon> ptr2Entity);
		bool setPtr2Site(const unsigned int& pos, std::shared_ptr<Site> ptr2Entity);
		bool setPtr2OwnPlatform(const unsigned int& pos, std::shared_ptr<OwnPlatform> ptr2Entity);
		bool setPtr2Esm(const unsigned int& pos, std::shared_ptr<Esm> ptr2Entity);
		bool setPtr2Ecm(const unsigned int& pos, std::shared_ptr<Ecm> ptr2Entity);
		bool setPtr2Route(const unsigned int& pos, std::shared_ptr<Route> ptr2Entity);
		bool setPtr2EsmStrategy(const unsigned int& pos, std::shared_ptr<EsmStrategy> ptr2Entity);
		bool setPtr2EcmStrategy(const unsigned int& pos, std::shared_ptr<EcmStrategy> ptr2Entity);

		void addVertex(std::shared_ptr<Vertex> ptr2Entity);
		void addPlatform(std::shared_ptr<Platform> ptr2Entity);
		void addEmitter(std::shared_ptr<Emitter> ptr2Entity);
		void addWeapon(std::shared_ptr<Weapon> ptr2Entity);
		void addSite(std::shared_ptr<Site> ptr2Entity);
		void addOwnPlatform(std::shared_ptr<OwnPlatform> ptr2Entity);
		void addEsm(std::shared_ptr<Esm> ptr2Entity);
		void addEcm(std::shared_ptr<Ecm> ptr2Entity);
		void addRoute(std::shared_ptr<Route> ptr2Entity);
		void addEsmStrategy(std::shared_ptr<EsmStrategy> ptr2Entity);
		void addEcmStrategy(std::shared_ptr<EcmStrategy> ptr2Entity);

		bool insertPtr2Vertex(const unsigned int& pos, std::shared_ptr<Vertex> ptr2Entity);
		bool insertPtr2Platform(const unsigned int& pos, std::shared_ptr<Platform> ptr2Entity);
		bool insertPtr2Emitter(const unsigned int& pos, std::shared_ptr<Emitter>ptr2Entity);
		bool insertPtr2Weapon(const unsigned int& pos, std::shared_ptr<Weapon> ptr2Entity);
		bool insertPtr2Site(const unsigned int& pos, std::shared_ptr<Site> ptr2Entity);
		bool insertPtr2OwnPlatform(const unsigned int& pos, std::shared_ptr<OwnPlatform> ptr2Entity);
		bool insertPtr2Esm(const unsigned int& pos, std::shared_ptr<Esm> ptr2Entity);
		bool insertPtr2Ecm(const unsigned int& pos, std::shared_ptr<Ecm> ptr2Entity);
		bool insertPtr2Route(const unsigned int& pos, std::shared_ptr<Route> ptr2Entity);
		bool insertPtr2EsmStrategy(const unsigned int& pos, std::shared_ptr<EsmStrategy> ptr2Entity);
		bool insertPtr2EcmStrategy(const unsigned int& pos, std::shared_ptr<EcmStrategy> ptr2Entity);

		bool deleteVertex(const unsigned int& pos);
		bool deletePlatform(const unsigned int& pos);
		bool deleteEmitter(const unsigned int& pos);
		bool deleteWeapon(const unsigned int& pos);
		bool deleteSite(const unsigned int& pos);
		bool deleteOwnPlatform(const unsigned int& pos);
		bool deleteEsm(const unsigned int& pos);
		bool deleteEcm(const unsigned int& pos);
		bool deleteRoute(const unsigned int& pos);
		bool deleteEsmStrategy(const unsigned int& pos);
		bool deleteEcmStrategy(const unsigned int& pos);


		bool setPlatformSiteRelation(const unsigned int& pos, PlatformSiteRelation& relation);
		bool setPlatformEmitterRelation(const unsigned int& pos, PlatformEmitterRelation& relation);
		bool setPlatformWeaponRelation(const unsigned int& pos, PlatformWeaponRelation& relation);
		bool setOwnPlatformEsmRelation(const unsigned int& pos, OwnPlatformEsmRelation& relation);
		bool setEsmEsmStrategyRelation(const unsigned int& pos, EsmEsmStrategyRelation& relation);
		bool setOwnPlatformEcmRelation(const unsigned int& pos, OwnPlatformEcmRelation& relation);
		bool setEcmEcmStrategyRelation(const unsigned int& pos, EcmEcmStrategyRelation& relation);
		bool setOwnPlatformRouteRelation(const unsigned int& pos, OwnPlatformRouteRelation& relation);
		
		void addPlatformSiteRelation(PlatformSiteRelation& relation);
		void addPlatformEmitterRelation(PlatformEmitterRelation& relation);
		void addPlatformWeaponRelation(PlatformWeaponRelation& relation);
		void addOwnPlatformEsmRelation(OwnPlatformEsmRelation& relation);
		void addEsmEsmStrategyRelation(EsmEsmStrategyRelation& relation);
		void addOwnPlatformEcmRelation(OwnPlatformEcmRelation& relation);
		void addEcmEcmStrategyRelation(EcmEcmStrategyRelation& relation);
		void addOwnPlatformRouteRelation(OwnPlatformRouteRelation& relation);

		bool insertPlatformSiteRelation(const unsigned int& pos, PlatformSiteRelation& relation);
		bool insertPlatformEmitterRelation(const unsigned int& pos, PlatformEmitterRelation& relation);
		bool insertPlatformWeaponRelation(const unsigned int& pos, PlatformWeaponRelation& relation);
		bool insertOwnPlatformEsmRelation(const unsigned int& pos, OwnPlatformEsmRelation& relation);
		bool insertEsmEsmStrategyRelation(const unsigned int& pos, EsmEsmStrategyRelation& relation);
		bool insertOwnPlatformEcmRelation(const unsigned int& pos, OwnPlatformEcmRelation& relation);
		bool insertEcmEcmStrategyRelation(const unsigned int& pos, EcmEcmStrategyRelation& relation);
		bool insertOwnPlatformRouteRelation(const unsigned int& pos, OwnPlatformRouteRelation& relation);

		bool deletePlatformSiteRelation(const unsigned int& pos);
		bool deletePlatformEmitterRelation(const unsigned int& pos);
		bool deletePlatformWeaponRelation(const unsigned int& pos);
		bool deleteOwnPlatformEsmRelation(const unsigned int& pos);
		bool deleteEsmEsmStrategyRelation(const unsigned int& pos);
		bool deleteOwnPlatformEcmRelation(const unsigned int& pos);
		bool deleteEcmEcmStrategyRelation(const unsigned int& pos);
		bool deleteOwnPlatformRouteRelation(const unsigned int& pos);

		void setAllVertex(std::vector<std::shared_ptr<Vertex>>& ptr2AllEntities);
		void setAllPlatform(std::vector<std::shared_ptr<Platform>>& ptr2AllEntities);
		void setAllEmitter(std::vector<std::shared_ptr<Emitter>>& ptr2AllEntities);
		void setAllWeapon(std::vector<std::shared_ptr<Weapon>>& ptr2AllEntities);
		void setAllSite(std::vector<std::shared_ptr<Site>>& ptr2AllEntities);
		void setAllOwnPlatform(std::vector<std::shared_ptr<OwnPlatform>>& ptr2AllEntities);
		void setAllEsm(std::vector<std::shared_ptr<Esm>>& ptr2AllEntities);
		void setAllEcm(std::vector<std::shared_ptr<Ecm>>& ptr2AllEntities);
		void setAllRoute(std::vector<std::shared_ptr<Route>>& ptr2AllEntities);
		void setAllEsmStrategy(std::vector<std::shared_ptr<EsmStrategy>>& ptr2AllEntities);
		void setAllEcmStrategy(std::vector<std::shared_ptr<EcmStrategy>>& ptr2AllEntities);

		void setAllPlatformSiteRelation(std::vector<PlatformSiteRelation>& ptr2AllEntities);
		void setAllPlatformEmitterRelation(std::vector<PlatformEmitterRelation>& ptr2AllEntities);
		void setAllPlatformWeaponRelation(std::vector<PlatformWeaponRelation>& ptr2AllEntities);
		void setAllOwnPlatformEsmRelation(std::vector<OwnPlatformEsmRelation>& ptr2AllEntities);
		void setAllEsmEsmStrategyRelation(std::vector<EsmEsmStrategyRelation>& ptr2AllEntities);
		void setAllOwnPlatformEcmRelation(std::vector<OwnPlatformEcmRelation>& ptr2AllEntities);
		void setAllEcmEcmStrategyRelation(std::vector<EcmEcmStrategyRelation>& ptr2AllEntities);
		void setAllOwnPlatformRouteRelation(std::vector<OwnPlatformRouteRelation>& ptr2AllEntities);

	private:
		std::vector<std::shared_ptr<Vertex>> m_ptrVertex;
		//由于Platform中name数据成员为string这种可变长类型，不应直接在容器中放置类对象，而应该使用指针
		std::vector<std::shared_ptr<Platform>> m_ptrPlatform;
		std::vector<std::shared_ptr<Emitter>> m_ptrEmitter;
		std::vector<std::shared_ptr<Weapon>> m_ptrWeapon;
		std::vector<std::shared_ptr<Site>> m_ptrSite;

		std::vector<std::shared_ptr<OwnPlatform>> m_ptrOwnPlatform;
		std::vector<std::shared_ptr<Esm>> m_ptrEsm;
		std::vector<std::shared_ptr<Ecm>> m_ptrEcm;
		std::vector<std::shared_ptr<Route>> m_ptrRoute; 
		std::vector<std::shared_ptr<EsmStrategy>> m_ptrEsmStrategy;
		std::vector<std::shared_ptr<EcmStrategy>> m_ptrEcmStrategy;

		std::vector<PlatformSiteRelation> m_PlatformSiteRelation;
		std::vector<PlatformEmitterRelation> m_PlatformEmitterRelation;
		std::vector<PlatformWeaponRelation> m_PlatformWeaponRelation;
		std::vector<OwnPlatformEsmRelation> m_OwnPlatformEsmRelation;
		std::vector<EsmEsmStrategyRelation> m_EsmEsmStrategyRelation;
		std::vector<OwnPlatformEcmRelation> m_OwnPlatformEcmRelation;
		std::vector<EcmEcmStrategyRelation> m_EcmEcmStrategyRelation;
		std::vector<OwnPlatformRouteRelation> m_OwnPlatformRouteRelation;

	};

	class Vertex
	{
	public:
		
		Vertex(void);
		Vertex(const double &, const double &);
		
		//get latitude and longitude
		const double& getLatitude(void) const;
		const double& getLongitude(void) const;

		//set latitude and longitute
		void setLatitude(const double &);
		void setLongitude(const double &);

	private:
		double m_latitude, m_longitude;
	};

	enum class PlatformType
	{
		LAND = 0,
		AIR = 1,
		SURFACE = 2
	};

	
	class Platform
	{
	public:
		//请注意，数据成员中自定义类虽然都有默认构造函数，但本质上没有完全实例化类对象，
		//由于充满不确定性，调用默认构造可能会引起一些未知错误；
		//此构造函数用于编译器隐含调用，使用者请不要使用默认构造函数
		Platform(void);
		Platform(const std::string &, const PlatformType &);

		//get PlatformName and PlatformType
		const std::string& getPlatformName(void) const;
		const PlatformType& getPlatformType(void) const;

		//set PlatformName and PlatformType
		void setPlatformName(const std::string &);
		void setPlatformType(const PlatformType &);
	private:
		std::string m_name;
		PlatformType m_type;
	};

	class Rf_values
	{
	public:
		Rf_values(void)=default;

		Rf_values(const unsigned int &,
			const unsigned int &,
			const unsigned int &,
			const unsigned int &,
			const unsigned int &);

		//get method
		const unsigned int& getPhaseOrder(void) const;
		const unsigned int& getNumberOfPulses(void) const;
		const unsigned int& getMin(void) const;
		const unsigned int& getMax(void) const;
		const unsigned int& getSweepTime(void) const;

		//set method
		void setPhaseOrder(const unsigned int &);
		void setNumberOfPulses(const unsigned int &);
		void setMin(const unsigned int &);
		void setMax(const unsigned int &);
		void setSweepTime(const unsigned int &);

	private:
		unsigned int m_phaseOrder;
		unsigned int m_numberOfPulses;
		unsigned int m_min;
		unsigned int m_max;
		unsigned int m_sweepTime;
	};

	enum class RfType
	{
		BURST = 0,
		FIX=1
	};

	class Rf
	{
	public:
		//请注意，数据成员中自定义类虽然都有默认构造函数，但本质上没有完全实例化类对象，
		//由于充满不确定性，调用默认构造可能会引起一些未知错误；
		//此构造函数用于编译器隐含调用，使用者请不要使用默认构造函数
		Rf(void);
		Rf(const unsigned int &,
			const unsigned int &,
			const RfType &);

		Rf(const unsigned int &,
			const unsigned int &,
			const Rf_values &, 
			const RfType &);
		Rf(const unsigned int &,
			const unsigned int &,
			const std::vector<Rf_values> &, 
			const RfType &);

		//Rf(const Rf& rf);
		//Rf& operator=(const Rf& rf);

		//get mehtod
		const unsigned int& getRfMin(void) const;
		const unsigned int& getRfMax(void) const;
		const RfType& getRfType(void) const;

		//获取容纳Pri_values的容器对象
		std::vector<Rf_values>& getAllRfValues(void);

		//判断Pri_values值不为空
		bool isValuesEmpty();

		//根据values的索引值获取不同values的对象。
		//在获取values前应判断容器是否为空
		Rf_values& getRfValue(const unsigned int& valueOrder);

		//add Rf_values
		void addRfValues(const Rf_values &);

		//Values值设置/替换
		bool setRfValues(const unsigned int& pos, const Rf_values &);

		//insert Rf_values
		bool insertRfValues(const unsigned int& pos, const Rf_values &);

		//delete Rf_values
		bool deleteRfValues(const unsigned int& pos);

		//set method
		void setRfMin(const unsigned int &);
		void setRfMax(const unsigned int &);
		void setRfType(const RfType &);

		//赋值覆盖，可用此成员函数覆盖住默认构造函数初始化的对象
		void setAllRfValues(const std::vector<Rf_values>&);
		
	private:
		unsigned int m_min;
		unsigned int m_max;
		RfType m_type;
		std::vector<Rf_values> m_values;

	public:
		//const Rf_values &operator[](unsigned int valuesOrder) const;
	};

	class Pw_values
	{
	public:
		
		Pw_values(void);

		Pw_values(const unsigned int & pOrder, const unsigned int & numOfPulses, const unsigned int & min, const unsigned int & max, const unsigned int & sweepTime);

		//get method
		const unsigned int& getPhaseOrder(void) const;
		const unsigned int& getNumberOfPulses(void) const;
		const unsigned int& getMin(void) const;
		const unsigned int& getMax(void) const;
		const unsigned int& getSweepTime(void) const;

		//set method
		void setPhaseOrder(const unsigned int &);
		void setNumberOfPulses(const unsigned int &);
		void setMin(const unsigned int &);
		void setMax(const unsigned int &);
		void setSweepTime(const unsigned int &);

	private:
		unsigned int m_phaseOrder;
		unsigned int m_numberOfPulses;
		unsigned int m_min;
		unsigned int m_max;
		unsigned int m_sweepTime;
	};

	enum class PwType
	{
		FIX = 0
	};

	class Pw
	{
	public:
		//请注意，数据成员中自定义类虽然都有默认构造函数，但本质上没有完全实例化类对象，
		//由于充满不确定性，调用默认构造可能会引起一些未知错误；
		//此构造函数用于编译器隐含调用，使用者请不要使用默认构造函数
		Pw(void);
		Pw(const unsigned int &, 
			const unsigned int &, 
			const PwType &);

		Pw(const unsigned int &,
			const unsigned int &,
			const Pw_values &,
			const PwType &);
		Pw(const unsigned int &,
			const unsigned int &,
			const std::vector<Pw_values > &,
			const PwType &);

		//get mehtod
		const unsigned int& getPwMin(void) const;
		const unsigned int& getPwMax(void) const;
		const PwType& getPwType(void) const;

		//获取容纳Pri_values的容器对象
		std::vector<Pw_values>& getAllPwValues(void);

		//判断Pri_values值不为空
		bool isValuesEmpty();

		//根据values的索引值获取不同values的对象。
		//在获取values前应判断容器是否为空
		Pw_values& getPwValue(unsigned int valueOrder);

		//add Pw_values
		void addPriValues(Pw_values &);

		//Values值设置/替换
		bool setPwValues(const unsigned int& pos, const Pw_values &);

		//insert Pw_values
		bool insertPwValues(unsigned int pos, Pw_values &);
		
		//delete Pw_values
		bool deletePwValues(unsigned int pos);
		
		//set method
		void setPwMin(const unsigned int &);
		void setPwMax(const unsigned int &);
		void setPwType(const PwType &);

		//赋值覆盖，可用此成员函数覆盖住默认构造函数初始化的对象
		void setAllPwValues(const std::vector<Pw_values>&);

	private:
		unsigned int m_min;
		unsigned int m_max;
		PwType m_type;
		std::vector<Pw_values> m_values;

	public:
		//const Pw_values &operator[](unsigned int valuesOrder) const;
	};

	class Pri_values
	{
	public:
		Pri_values(void);
		
		Pri_values(const unsigned int &,
			const unsigned int &,
			const unsigned int &,
			const unsigned int &,
			const unsigned int &);

		//get method
		const unsigned int& getPhaseOrder(void) const;
		const unsigned int& getNumberOfPulses(void) const;
		const unsigned int& getMin(void) const;
		const unsigned int& getMax(void) const;
		const unsigned int& getSweepTime(void) const;

		//set method
		void setPhaseOrder(const unsigned int &);
		void setNumberOfPulses(const unsigned int &);
		void setMin(const unsigned int &);
		void setMax(const unsigned int &);
		void setSweepTime(const unsigned int &);

	private:
		unsigned int m_phaseOrder;
		unsigned int m_numberOfPulses;
		unsigned int m_min;
		unsigned int m_max;
		unsigned int m_sweepTime;
	};

	enum class PriType
	{
		STAGGER = 0,
		SWITCHING=1,
		FIX=2
	};

	class Pri
	{
	public:
		//请注意，数据成员中自定义类虽然都有默认构造函数，但本质上没有完全实例化类对象，
		//由于充满不确定性，调用默认构造可能会引起一些未知错误；
		//此构造函数用于编译器隐含调用，使用者请不要使用默认构造函数
		Pri(void);
		Pri(const unsigned int &,
			const unsigned int &,
			const PriType &);

		Pri(const unsigned int &,
			const unsigned int &,
			const Pri_values &,
			const PriType &);

		Pri(const unsigned int &,
			const unsigned int &,
			const std::vector<Pri_values> &,
			const PriType &);

		//get mehtod
		const unsigned int& getPriMin(void) const;
		const unsigned int& getPriMax(void) const;
		const PriType& getPriType(void) const;

		//获取容纳Pri_values的容器对象
		std::vector<Pri_values>& getAllPriValues(void);

		//判断Pri_values值不为空
		bool isValuesEmpty();

		//根据Pri_value的顺序获取不同Pri_values的对象。
		//在获取Pri_value前应判断容器是否为空
		Pri_values& getPriValue(unsigned int valueOrder);
		
		//set method
		void setPriMin(const unsigned int &);
		void setPriMax(const unsigned int &);
		void setPriType(const PriType &);
		
		//add Pri_values
		void addPriValues(Pri_values &);

		//Values值设置/替换
		bool setPriValues(const unsigned int& pos, const Pri_values &);

		//insert Pri_values
		bool insertPriValues(unsigned int pos, Pri_values &);
		
		//delete Pri_values
		bool deletePriValues(unsigned int pos);

		//赋值覆盖，可用此成员函数覆盖住默认构造函数初始化的对象
		void setAllPriValues(const std::vector<Pri_values>&);
		
	private:
		unsigned int m_min;
		unsigned int m_max;
		PriType m_type;
		std::vector<Pri_values> m_values;

	public: 
		//const Pri_values &operator[](unsigned int valuesOrder) const;
	};

	enum class ScanType
	{
		SECTORIAL=0
	};

	class Scan
	{
	public:
		
		Scan(void);
		Scan(const unsigned int &,
			const unsigned int &,
			const ScanType &);

		//get mehtod
		const unsigned int& getScanMin(void) const;
		const unsigned int& getScanMax(void) const;
		const ScanType& getScanType(void) const;
		
		//set method
		void setScanMin(const unsigned int &);
		void setScanMax(const unsigned int &);
		void setScanType(const ScanType &);
		
	private:
		unsigned int m_min;
		unsigned int m_max;
		ScanType m_type;
	};

	class Erp
	{
	public:
		
		Erp(void);
		Erp(const unsigned int &,
			const unsigned int &);

		//get mehtod
		const unsigned int& getErpMin(void) const;
		const unsigned int& getErpMax(void) const;
		
		//set method
		void setErpMin(const unsigned int &);
		void setErpMax(const unsigned int &);
		

	private:
		unsigned int m_min;
		unsigned int m_max;
	};

	enum class ModeType
	{
		PULSE=0
	};

	class Radar_Mode
	{
	public:
		//请注意，数据成员中自定义类虽然都有默认构造函数，但本质上没有完全实例化类对象，
		//由于充满不确定性，调用默认构造可能会引起一些未知错误；
		//此构造函数用于编译器隐含调用，使用者请不要使用默认构造函数
		Radar_Mode(void);

		Radar_Mode(const std::string &,
			const ModeType &,
			const Rf &,
			const Pw &,
			const Pri &,
			const Scan &,
			const Erp &);

		//get mehtod
		const std::string& getModeCode(void) const;
		const ModeType& getModeType(void) const;
		Rf& getRf(void);
		Pw& getPw(void);
		Pri& getPri(void);
		Scan& getScan(void);
		Erp& getErp(void);

		//set method
		void setModeCode(const std::string &);
		void setModeType(const ModeType &);
		void setRf(Rf &);
		void setPw(Pw &);
		void setPri(Pri &);
		void setScan(const Scan &);
		void setErp(const Erp &);

	private:
		std::string m_modeCode;//直接初始化
		ModeType m_modeType;
		Rf m_rf;
		Pw m_pw;
		Pri m_pri;
		Scan m_scan;
		Erp m_erp;
	};

	class Emitter
	{
	public:
		//请注意，数据成员中自定义类虽然都有默认构造函数，但本质上没有完全实例化类对象，
		//由于充满不确定性，调用默认构造可能会引起一些未知错误；
		//此构造函数用于编译器隐含调用，使用者请不要使用默认构造函数
		Emitter(void);
		Emitter(const std::string &, std::shared_ptr<Radar_Mode>);
		Emitter(const std::string &, std::vector<std::shared_ptr<Radar_Mode>> &);

		//get method
		const std::string& getName(void) const ;

		//获取RadarMode容器对象
		std::vector<std::shared_ptr<Radar_Mode>>& getAllPtr2RadarModes(void);

		bool isRadarModeEmpty(void);

		//按索引获取RadarMode
		const std::shared_ptr<Radar_Mode> getPtr2RadarMode(unsigned int valueOrder) const ;

		//add method
		void addRadarMode(const std::shared_ptr<Radar_Mode>);
		
		//按照索引设置/修改RadarMode
		bool setPtr2RadarMode(unsigned int& pos, std::shared_ptr<Radar_Mode>);

		//insert
		bool insertRadarMode(unsigned int& pos, std::shared_ptr<Radar_Mode>);

		//delete
		bool deleteRadarMode(unsigned int& pos);

		//set method
		void setName(const std::string& name);

		//整体设置修改RadarMode
		void setAllPtr2RadarModes(std::vector<std::shared_ptr<Radar_Mode>>&);

	private:
		std::string m_name{"Emitter1"};
		std::vector<std::shared_ptr<Radar_Mode>> m_ptrRadarMode;
	};

	class Weapon
	{
	public:
		//不用使用标准容器类直接装带有string类型成员数据的类对象，而应该是该对象的指针
		Weapon(void);
		Weapon(const std::string&,const unsigned int&, const unsigned int&);

		const std::string& getName(void) const;
		const unsigned int& getCEPR(void) const;
		const unsigned int& getWeaponAreaCoverage(void) const;

		void setName(const std::string&);
		void setCEPR(const unsigned int&);
		void setWeaponAreaCoverage(const unsigned int&);


	private:
		std::string m_name;
		unsigned int m_cepr;
		unsigned int m_weaponAreaCoverage;
	};

	class Site
	{
	public:
		//不用使用标准容器类直接装带有string类型成员数据的类对象，而应该是该对象的指针
		Site(void);
		Site(const std::string&, const double&, const double&, const double&);

		//get latitude and longitude
		const std::string& getName(void) const;
		const double& getAltitude(void) const;
		const double& getLatitude(void) const;
		const double& getLongitude(void) const;

		//set latitude and longitute
		void setName(const std::string&);
		void setAltitude(const double &);
		void setLatitude(const double &);
		void setLongitude(const double &);

	private:
		std::string m_name;
		double m_altitude;
		double m_latitude;
		double m_longitude;
	};

	class Point
	{
	public:
		Point(void);
		Point(const double&, const double&, const double&);
		Point(const double&, const double&, const double&, const double&, const double&);

		//get latitude and longitude
		const double& getAltitude(void) const;
		const double& getLatitude(void) const;
		const double& getLongitude(void) const;
		const double& getTmin(void) const;
		const double& getTmax(void) const;

		//set latitude and longitute
		void setAltitude(const double &);
		void setLatitude(const double &);
		void setLongitude(const double &);
		void setTmin(const double &);
		void setTmax(const double &);

	private:
		double m_altitude;
		double m_latitude;
		double m_longitude;
		double m_tmin;
		double m_tmax;
	};
	
	enum class MissionType
	{
		STRIKE = 0,
		SUPPORT=1
	};

	class Mission
	{
	public:
		//请注意，数据成员中自定义类虽然都有默认构造函数，但本质上没有完全实例化类对象，
		//由于充满不确定性，调用默认构造可能会引起一些未知错误；
		//此构造函数用于编译器隐含调用，使用者请不要使用默认构造函数
		Mission(void);

		//Mission Type:Strike
		Mission(const MissionType&, const Point&, const Point&, const std::vector<Point>&);
		Mission(const MissionType&, const Point&, const Point&, const Point&);

		//Mission Type:Support
		//此构造函数应该在MissionType为Support时才用此构造函数，但一如前面所说，不保证安全性
		Mission(const MissionType&,const Point&, const Point&);

		const MissionType& getMissionType(void) const ;
		Point& getStartPoint(void);
		Point& getEndPoint(void);

		//获取容纳所有TargetPoints的容器对象
		std::vector<Point>& getAllTargetPoints(void);
		
		bool isTargetPointEmpty(void);

		//返回非常量引用可以连续调用成员变量类的成员函数
		Point& getTargetPoint(unsigned int& pointOrder);

		void addTargetPoint(const Point&);

		bool setTargetPoint(unsigned int& pos, const Point&);

		bool insertTargetPoint(unsigned int& pos, const Point&);

		bool deleteTargetPoint(unsigned int& pos);

		void setMissionType(const MissionType&);
		void setStartPoint(const Point&);
		void setEndPoint(const Point&);
		void setAllTargetPoints(const std::vector<Point>&);


	private:
		MissionType m_type;
		Point m_startPoint;
		Point m_endPoint;
		std::vector<Point> m_targetPoints;
	};
		
	enum class OwnPlatformType
	{
		AIR=0
		
	};

	class OwnPlatform
	{
	public:
		OwnPlatform(void);
		OwnPlatform(const std::string&, const OwnPlatformType&,const double&, const double&, const double&, const double&, const double&, const double&, const Mission&);

		const std::string& getName(void) const;
		const OwnPlatformType& getType(void) const;
		const double& getMaxAcceleration(void)const;
		const double& getMaxDeceleration(void)const;
		const double& getMaxClimbRate(void)const;
		const double& getMaxDiveRate(void)const;
		const double& getMaxSpeed(void)const;
		const double& getMaxTurnRadius(void)const;

		Mission& getMission(void);

		void setName(const std::string&);
		void setType(const OwnPlatformType&);
		void setMaxAcceleration(const double&);
		void setMaxDeceleration(const double&);
		void setMaxClimbRate(const double&);
		void setMaxDiveRate(const double&);
		void setMaxSpeed(const double&);
		void setMaxTurnRadius(const double&);
		void setMission(const Mission&);


	private:
		std::string m_name;
		OwnPlatformType m_type;
		double m_maxAcceleration;
		double m_maxDeceleration;
		double m_maxClimbRate;
		double m_maxDiveRate;
		double m_maxSpeed;
		double m_maxTurnRadius;
		Mission m_mission;
	};

	class Esm
	{
	public:
		Esm(void);
		Esm(const std::string&, const double&, const unsigned int&, const unsigned int&, const unsigned int&, const unsigned int&, const unsigned int&);

		const std::string& getName(void);
		const double& getDwellFreqResolution(void);
		const unsigned int& getTuningStep(void);
		const unsigned int& getRfCovMin(void);
		const unsigned int& getRfCovMax(void);
		const unsigned int& getNumPulsesAcquisition(void);
		const unsigned int& getNumPulsesAlarm(void);

		void setName(const std::string&);
		void setDwellFreqResolution(const double&);
        void setTuningStep(const unsigned int&);
        void setRfCovMin(const unsigned int&);
        void setRfCovMax(const unsigned int&);
        void setNumPulsesAcquisition(const unsigned int&);
        void setNumPulsesAlarm(const unsigned int&);
		
	private:
		std::string m_name;
		double m_dwellFreqResolution;
		unsigned int m_tuningStep;
		unsigned int m_rfCovMin;
		unsigned int m_rfCovMax;
		unsigned int m_numPulsesAcquisition;
		unsigned int m_numPulsesAlarm;
	};

	enum class Tech
	{
		NOISE = 0,
		VGPO = 1,
		FT = 2,
		RGPO = 3
	};

	class Ecm
	{
	public:
		Ecm(void);
		Ecm(const std::string&, const unsigned int&, const unsigned int&, const unsigned int&, const unsigned int&, const Tech&);
		Ecm(const std::string&, const unsigned int&, const unsigned int&, const unsigned int&, const unsigned int&, const std::vector<Tech>&);

		const std::string& getName(void);
		const unsigned int& getPt(void);
		const unsigned int& getGain(void);
		const unsigned int& getRfMin(void);
		const unsigned int& getRfMax(void);

		//获取装填所有Tech的容器对象
		std::vector<Tech>& getAllTechs(void);

		//判断装填所有Tech的容器中是否为空
		bool isTechEmpty(void);

		//根据索引值找寻对应的Tech
		const Tech& getTech(const unsigned int& order);

		//add Tech
		void addTech(const Tech&);

		//对单个Tech进行设置，更改
		bool setTech(const unsigned int& pos, const Tech&);

		//insert Tech
		bool insertTech(const unsigned int& pos, const Tech&);

		//delete Tech
		bool deleteTech(const unsigned int& pos);

		//set method
		void setName(const std::string&);
		void setPt(const unsigned int&);
		void setGain(const unsigned int&);
		void setRfMin(const unsigned int&);
		void setRfMax(const unsigned int&);

		//以容器为单位，整体赋值修改
		void setAllTechs(const std::vector<Tech>&);

	private:
		std::string m_name;
		unsigned int m_pt;
		unsigned int m_gain;
		unsigned int m_rfMin;
		unsigned int m_rfMax;
		std::vector<Tech> m_techName;
	};

	class WayPoint
	{
	public:
		WayPoint(void);
		WayPoint(const unsigned int&, const double&, const double&, const double&, const double&, const double&, const double&);

		//get latitude and longitude
		const unsigned int& getIndex(void) const;
		const double& getAltitude(void) const;
		const double& getLatitude(void) const;
		const double& getLongitude(void) const;
		const double& getTime(void) const;
		const double& getVelocity(void) const;
		const double& getAcceleration(void) const;

		//set latitude and longitute
		void setIndex(const unsigned int &);
		void setAltitude(const double &);
		void setLatitude(const double &);
		void setLongitude(const double &);
		void setTime(const double &);
		void setVelocity(const double&);
		void setAcceleration(const double&);

	private:
		unsigned int m_index;
		double m_altitude;
		double m_latitude;
		double m_longitude;
		double m_time;
		double m_velocity;
		double m_acceleration;
	};

	class Route
	{
	public:
		Route(void);
		Route(const std::string&, const WayPoint&);
		Route(const std::string&, const std::vector<WayPoint>&);

		//get name
		const std::string& getName(void);

		bool isWayPointEmpty(void);

		//get waypoint by index
		WayPoint& getWayPoint(const unsigned int&);

		//get all waypoints
		std::vector<WayPoint>& getAllWayPoints(void);

		//add waypoint
		void addWayPoint(const WayPoint&);

		//insert waypoint by position
		bool insertWayPoint(const unsigned int&, const WayPoint&);

		//set/moditify waypoint by index
		bool setWayPoint(const unsigned int&, const WayPoint&);

		//detele waypoint by index
		bool deleteWayPoint(const unsigned int&);

		//set name
		void setName(const std::string&);

		//set/moditify WayPoints
		void setAllWayPoints(const std::vector<WayPoint>&);

	private:
		std::string m_name;
		std::vector<WayPoint> m_wayPoints;
	};

	class Location
	{
	public:
		Location(void);
		Location(const double&, const double&, const double&);

		//get latitude and longitude
		const double& getAltitude(void) const;
		const double& getLatitude(void) const;
		const double& getLongitude(void) const;

		//set latitude and longitute
		void setAltitude(const double &);
		void setLatitude(const double &);
		void setLongitude(const double &);

	private:
		double m_altitude;
		double m_latitude;
		double m_longitude;
	};

	class DwellSquence
	{
	public:
		DwellSquence(void);
		DwellSquence(const unsigned int&, const unsigned int&, const unsigned int&, const double&, const double&);

		//get method;
		const unsigned int& getIndex(void);
		const unsigned int& getMinFreq(void);
		const unsigned int& getMaxFreq(void);
		const double& getStartTime(void);
		const double& getEndTime(void);

		//set method;
		void setIndex(const unsigned int&);
		void setMinFreq(const unsigned int&);
		void setMaxFreq(const unsigned int&);
		void setStartTime(const double&);
		void setEndTime(const double&);

	private:
		unsigned int m_index;
		unsigned int m_minFreq;
		unsigned int m_maxFreq;
		double m_startTime;
		double m_endTime;
	};

	class EsmStrategySection
	{
	public:
		EsmStrategySection(void);
		EsmStrategySection(const double&, const double&, const Location&, const Location&, const DwellSquence&);
		EsmStrategySection(const double&, const double&, const Location&, const Location&, const std::vector<DwellSquence>&);

		//get method
		const double& getStartTime(void);
		const double& getEndTime(void);
		Location& getStartLocation(void);
		Location& getEndLocation(void);

		bool isDwellSquenceEmpty(void);

		//get DwellSquence by index
		DwellSquence& getDwellSquence(const unsigned int& index);

		//get all DwellSquences
		std::vector<DwellSquence>& getAllDwellSquences(void);

		//add DwellSquence
		void addDwellSquence(const DwellSquence&);

		//insert DwellSquence
		bool insertDwellSquence(const unsigned int& pos, const DwellSquence&);

		//set/moditify DwellSquence
		bool setDwellSquence(const unsigned int& pos, const DwellSquence&);

		//delete DwellSquence
		bool deleteDwellSquence(const unsigned int& index);

		//set/moditify all DwellSquence
		void setDwellSquences(const std::vector<DwellSquence>&);

		void setStartTime(const double&);
		void setEndTime(const double&);
		void setStartLocation(const Location&);
		void setEndLocation(const Location&);

	private:
		double m_startTime;
		double m_endTime;
		Location m_startLocation;
		Location m_endLocation;
		std::vector<DwellSquence> m_dwellSquences;
	};

	class EsmStrategy
	{
	public:
		EsmStrategy(void);
		EsmStrategy(const std::string&, const std::shared_ptr<EsmStrategySection>&);
		EsmStrategy(const std::string&, const std::vector<std::shared_ptr<EsmStrategySection>>&);

		//get method
		const std::string& getName(void) const;

		//获取EsmStrategySection指针容器对象
		std::vector<std::shared_ptr<EsmStrategySection>>& getAllPtr2Sections(void);

		bool isSectionEmpty(void);

		//按索引获取EsmStrategySection
		const std::shared_ptr<EsmStrategySection> getPtr2Section(unsigned int& pos) const;

		//add EsmStrategySection
		void addSection(const std::shared_ptr<EsmStrategySection>);

		//按照索引设置/修改EsmStrategySection
		bool setPtr2Section(unsigned int& pos, std::shared_ptr<EsmStrategySection>);

		//insert EsmStrategySection
		bool insertSection(unsigned int& pos, std::shared_ptr<EsmStrategySection>);

		//delete EsmStrategySection
		bool deleteSection(unsigned int& pos);

		//set name
		void setName(const std::string& name);

		//整体设置修改EsmStrategySection指针容器对象
		void setAllPtr2Sections(std::vector<std::shared_ptr<EsmStrategySection>>&);

	private:
		std::string m_name;
		std::vector<std::shared_ptr<EsmStrategySection>> m_ptrSections;

	};

	
	class EcmStrategySection
	{
	public:
		EcmStrategySection(void);
		EcmStrategySection(const double&, const double&, const Location&, const Location&,const Tech&);

		//get prop
		const double& getStartTime(void);
		const double& getEndTime(void);
		const Location& getStartLocation(void);
		const Location& getEndLocation(void); 
		const Tech& getTechName(void);

		//set prop
		void setStartTime(const double&);
		void setEndTime(const double&);
		void setStartLocation(const Location&);
		void setEndLocation(const Location&);
		void setTechName(const Tech&);

	private:
		double m_startTime;
		double m_endTime;
		Location m_startLocation;
		Location m_endLocation;
		Tech m_tech;
	};

	class EcmStrategy
	{
	public:
		EcmStrategy(void);
		EcmStrategy(const std::string&, const std::shared_ptr<EcmStrategySection>&);
		EcmStrategy(const std::string&, const std::vector<std::shared_ptr<EcmStrategySection>>&);

		//get method
		const std::string& getName(void) const;

		//获取EcmStrategySection指针容器对象
		std::vector<std::shared_ptr<EcmStrategySection>>& getAllPtr2Sections(void);

		//判断EcmStrategySection指针容器对象是否为空
		bool isSectionEmpty(void);

		//按索引获取EsmStrategySection
		const std::shared_ptr<EcmStrategySection> getPtr2Section(unsigned int& pos) const;

		//add EsmStrategySection
		void addSection(const std::shared_ptr<EcmStrategySection>);

		//按照索引设置/修改EsmStrategySection
		bool setPtr2Section(unsigned int& pos, std::shared_ptr<EcmStrategySection>);

		//insert EsmStrategySection
		bool insertSection(unsigned int& pos, std::shared_ptr<EcmStrategySection>);

		//delete EsmStrategySection
		bool deleteSection(unsigned int& pos);

		//set name
		void setName(const std::string& name);

		//整体设置修改EsmStrategySection指针容器对象
		void setAllPtr2Sections(std::vector<std::shared_ptr<EcmStrategySection>>&);

	private:
		std::string m_name;
		std::vector<std::shared_ptr<EcmStrategySection>> m_ptrSections;
	};

	class PlatformSiteRelation
	{
	public:
		//关联关系不应存在默认值
		//PlatformSiteRelation(void);
		PlatformSiteRelation(const std::shared_ptr<Platform>,const std::shared_ptr<Site>);

		//get name;
		const std::string& getPlatformName(void);
		const std::string& getSiteName(void);

		std::shared_ptr<Site> getSite(void);
		std::shared_ptr<Platform> getPlatform(void);

		//set/moditify pointer of Object
		void setPlatform(const std::shared_ptr<Platform>);
		void setSite(const std::shared_ptr<Site>);
		

	private:
		std::shared_ptr<Platform> m_ptrPlatform;
		std::shared_ptr<Site> m_ptrSite;
	};

	class PlatformEmitterRelation
	{
	public:
		//PlatformEmitterRelation(void);
		PlatformEmitterRelation(const std::shared_ptr<Platform>, const std::shared_ptr<Emitter>);

		//get name;
		const std::string& getPlatformName(void);
		const std::string& getEmitterName(void);

		std::shared_ptr<Platform> getPlatform(void);
		std::shared_ptr<Emitter> getEmitter(void);

		//set/moditify pointer of Object
		void setPlatform(const std::shared_ptr<Platform>);
		void setEmitter(const std::shared_ptr<Emitter>);

	private:
		std::shared_ptr<Platform> m_ptrPlatform;
		std::shared_ptr<Emitter> m_ptrEmitter;
	};

	class PlatformWeaponRelation
	{
	public:
		//PlatformWeaponRelation(void);
		PlatformWeaponRelation(const std::shared_ptr<Platform>, const std::shared_ptr<Weapon>);

		//get name;
		const std::string& getPlatformName(void);
		const std::string& getWeaponName(void);

		std::shared_ptr<Platform> getPlatform(void);
		std::shared_ptr<Weapon> getWeapon(void);

		//set/moditify pointer of Object
		void setPlatform(const std::shared_ptr<Platform>);
		void setWeapon(const std::shared_ptr<Weapon>);

	private:
		std::shared_ptr<Platform> m_ptrPlatform;
		std::shared_ptr<Weapon> m_ptrWeapon;
	};

	class OwnPlatformEsmRelation
	{
	public:
		//OwnPlatformEsmRelation(void);
		OwnPlatformEsmRelation(const std::shared_ptr<OwnPlatform>, const std::shared_ptr<Esm>);

		//get name;
		const std::string& getOwnPlatformName(void);
		const std::string& getEsmName(void);

		std::shared_ptr<OwnPlatform> getOwnPlatform(void);
		std::shared_ptr<Esm> getEsm(void);

		//set/moditify pointer of Object
		void setOwnPlatform(const std::shared_ptr<OwnPlatform>);
		void setEsm(const std::shared_ptr<Esm>);

	private:
		std::shared_ptr<OwnPlatform> m_ptrOwnPlatform;
		std::shared_ptr<Esm> m_ptrEsm;
	};

	class EsmEsmStrategyRelation
	{
	public:
		//EsmEsmStrategyRelation(void);
		EsmEsmStrategyRelation(const std::shared_ptr<Esm>, const std::shared_ptr<EsmStrategy>);

		//get name;
		const std::string& getEsmName(void);
		const std::string& getEsmStrategyName(void);

		std::shared_ptr<EsmStrategy> getEsmStrategy(void);
		std::shared_ptr<Esm> getEsm(void);

		//set/moditify pointer of Object
		void setEsm(const std::shared_ptr<Esm>);
		void setEsmStrategy(const std::shared_ptr<EsmStrategy>);

	private:
		std::shared_ptr<Esm> m_ptrEsm;
		std::shared_ptr<EsmStrategy> m_ptrEsmStrategy;
	};

	class OwnPlatformEcmRelation
	{
	public:
		//OwnPlatformEcmRelation(void);
		OwnPlatformEcmRelation(const std::shared_ptr<OwnPlatform>, const std::shared_ptr<Ecm>);

		//get name;
		const std::string& getOwnPlatformName(void);
		const std::string& getEcmName(void);

		std::shared_ptr<OwnPlatform> getOwnPlatform(void);
		std::shared_ptr<Ecm> getEcm(void);

		//set/moditify pointer of Object
		void setOwnPlatform(const std::shared_ptr<OwnPlatform>);
		void setEcm(const std::shared_ptr<Ecm>);

	private:
		std::shared_ptr<OwnPlatform> m_ptrOwnPlatform;
		std::shared_ptr<Ecm> m_ptrEcm;
	};

	class EcmEcmStrategyRelation
	{
	public:
		//EcmEcmStrategyRelation(void);
		EcmEcmStrategyRelation(const std::shared_ptr<Ecm>, const std::shared_ptr<EcmStrategy>);

		//get name;
		const std::string& getEcmName(void);
		const std::string& getEcmStrategyName(void);

		std::shared_ptr<EcmStrategy> getEcmStrategy(void);
		std::shared_ptr<Ecm> getEcm(void);

		//set/moditify pointer of Object
		void setEcm(const std::shared_ptr<Ecm>);
		void setEcmStrategy(const std::shared_ptr<EcmStrategy>);

	private:
		std::shared_ptr<Ecm> m_ptrEcm;
		std::shared_ptr<EcmStrategy> m_ptrEcmStrategy;
	};

	class OwnPlatformRouteRelation
	{
	public:
		//OwnPlatformRouteRelation(void);
		OwnPlatformRouteRelation(const std::shared_ptr<OwnPlatform>, const std::shared_ptr<Route>);

		//get name;
		const std::string& getOwnPlatformName(void);
		const std::string& getRouteName(void);

		std::shared_ptr<OwnPlatform> getOwnPlatform(void);
		std::shared_ptr<Route> getRoute(void);

		//set/moditify pointer of Object
		void setOwnPlatform(const std::shared_ptr<OwnPlatform>);
		void setRoute(const std::shared_ptr<Route>);

	private:
		std::shared_ptr<OwnPlatform> m_ptrOwnPlatform;
		std::shared_ptr<Route> m_ptrRoute;
	};

}

#endif // !__SCENARIO__
