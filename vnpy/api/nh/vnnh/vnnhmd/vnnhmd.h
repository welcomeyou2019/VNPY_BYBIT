//ϵͳ
#ifdef WIN32
#include "stdafx.h"
#endif

#include "vnnh.h"
#include "pybind11/pybind11.h"
#include "nh/md/CNhMdApi.h"


using namespace pybind11;

//����
#define ONFRONTCONNECTED 0
#define ONFRONTDISCONNECTED 1
#define ONHEARTBEATWARNING 2
#define ONRSPERROR 3
#define ONRTNMARKETDATA 4
#define ONRSPUTPLOGIN 5
#define ONRSPUTPLOGOUT 6
#define ONRSPSUBSCRIBE 7
#define ONRSPUNSUBSCRIBE 8
#define ONRSPQRYEXCHANGE 9
#define ONRSPQRYINSTRUMENT 10


///-------------------------------------------------------------------------------------
///C++ SPI�Ļص���������ʵ��
///-------------------------------------------------------------------------------------

//API�ļ̳�ʵ��
class MdApi : public CNhMdSpi
{
private:
	CNhMdApi* api;						//API����
	thread task_thread;					//�����߳�ָ�루��python���������ݣ�
	TaskQueue task_queue;			    //�������
	bool active = false;				//����״̬

public:
	MdApi()
	{
	};

	~MdApi()
	{
		if (this->active)
		{
			this->exit();
		}
	};

	//-------------------------------------------------------------------------------------
	//API�ص�����
	//-------------------------------------------------------------------------------------

	///���ͻ������������ؽ�����ͨ������ʱ����δ��¼ǰ�����÷��������á�
	virtual void OnFrontConnected() ;

	///���ͻ�������������ͨ�����ӶϿ�ʱ���÷��������á�
	virtual void OnFrontDisConnected() ;

	///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
	/* \param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
	****************************************/
	virtual void OnHeartBeatWarning(int nTimeLapse) ;

	/***************************************
	/* \fn    OnRspError
	/* \brief ����Ӧ��
	/* \param ERRORMSGINFO_t & req,����Ӧ����Ϣ
	/* \param TSequenceIDType nRequestID�����������request����Ĵ�����Ϊ��Ӧ����ID������Ϊ0
	/* \return void
	****************************************/
	virtual void OnRspError(ERRORMSGINFO_t &pRspInfo, TSequenceIDType nRequestID) ;

	///����֪ͨ
	virtual void OnRtnMarketData(STKMarketData_t &pData) ;

	/***************************************
	/* \fn    OnRspUtpLogin
	/* \brief ��¼�ϻ�ͳһ����ƽ̨UTP����ʱ��Ӧ
	/* \param RspUtpLoginField_t & req
	/* \param TSequenceIDType nRequestID��
	/* \return void
	****************************************/
	virtual void OnRspUtpLogin(const RspUtpLoginField_t& rsp, TSequenceIDType nRequestID) ;

	/***************************************
	/* \fn    OnRspUtpLogout
	/* \brief ��¼�ϻ�ͳһ����ƽ̨UTP����ʱ��Ӧ
	/* \param RspUtpLogoutField_t & req
	/* \param TSequenceIDType nRequestID
	/* \return void
	****************************************/
	virtual void OnRspUtpLogout(const RspUtpLogoutField_t& rsp, TSequenceIDType nRequestID) ;

	/***************************************
	/* \fn    OnRspSubscribe
	/* \brief ����������������ʱ��Ӧ
	/* \param RspSubscribeField_t & req
	/* \param TSequenceIDType nRequestID
	/* \return void
	****************************************/
	virtual void OnRspSubscribe(const RspSubscribeField_t& rsp, TSequenceIDType nRequestID) ;

	/***************************************
	/* \fn    OnRspUnSubscribe
	/* \brief ȡ������������������ʱ��Ӧ
	/* \param RspUnSubscribeField_t & req
	/* \param TSequenceIDType nRequestID
	/* \return void
	****************************************/
	virtual void OnRspUnSubscribe(const RspUnSubscribeField_t& rsp, TSequenceIDType nRequestID) ;

	/***************************************
	* \fn    OnRspQryExchange
	* \brief ��ѯ����������ʱ��Ӧ
	* \param RspQryExchangeField_t & rsp
	* \param TSequenceIDType nRequestID
	* \return void
	****************************************/
	virtual void OnRspQryExchange(const RspQryExchangeField_t& rsp, TSequenceIDType nRequestID) ;

	/***************************************
	* \fn    OnRspQryInstrument
	* \brief ��ѯ��Լ����ʱ��Ӧ
	* \param RspQryInstrumentField_t & rsp
	* \param TSequenceIDType nRequestID
	* \return void
	****************************************/
	virtual void OnRspQryInstrument(const RspQryInstrumentField_t& rsp, TSequenceIDType nRequestID) ;

	//-------------------------------------------------------------------------------------
	//task������
	//-------------------------------------------------------------------------------------

	void processTask();

	void processFrontConnected(Task *task);

	void processFrontDisConnected(Task *task);

	void processHeartBeatWarning(Task *task);

	void processRspError(Task *task);

	void processRtnMarketData(Task *task);

	void processRspUtpLogin(Task *task);

	void processRspUtpLogout(Task *task);

	void processRspSubscribe(Task *task);

	void processRspUnSubscribe(Task *task);

	void processRspQryExchange(Task *task);

	void processRspQryInstrument(Task *task);

	//-------------------------------------------------------------------------------------
	//data���ص������������ֵ�
	//error���ص������Ĵ����ֵ�
	//id������id
	//last���Ƿ�Ϊ��󷵻�
	//i������
	//-------------------------------------------------------------------------------------

	virtual void onFrontConnected() {};

	virtual void onFrontDisConnected() {};

	virtual void onHeartBeatWarning(int timeLapse) {};

	virtual void onRspError(const dict &data, int reqid) {};

	virtual void onRtnMarketData(const dict &data) {};

	virtual void onRspUtpLogin(const dict &data, int reqid) {};

	virtual void onRspUtpLogout(const dict &data, int reqid) {};

	virtual void onRspSubscribe(const dict &data, int reqid) {};

	virtual void onRspUnSubscribe(const dict &data, int reqid) {};

	virtual void onRspQryExchange(const dict &data, int reqid) {};

	virtual void onRspQryInstrument(const dict &data, int reqid) {};

	//-------------------------------------------------------------------------------------
	//req:���������������ֵ�
	//-------------------------------------------------------------------------------------

	void createMdApi();

	void release();

	void init();

	string getVersion();

	void registerFront(string address);

	void registerNameServer(string server);

	int exit();

	int reqUtpLogin(const dict &req, int reqid);

	int reqUtpLogout(int reqid);

	int reqSubscribe(string symbol, int reqid);

	int reqUnSubscribe(string symbol, int reqid);

	int reqAuthUserPasswor(const dict &req, int reqid);

	int reqQryExchange(const dict &req, int reqid);

	int reqQryInstrument(const dict &req, int reqid);
};
