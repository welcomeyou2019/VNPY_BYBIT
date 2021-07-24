/*************************
*ժҪ���ϻ��ڻ�����ϵͳ
*�ļ���NhMdApi.h
*      �����˿ͻ��˽ӿ�
*���ߣ��ϻ��ڻ������
*ʱ�䣺20130604
**************************/

#ifndef __CNH_MD_API_H__
#define __CNH_MD_API_H__

#ifdef WIN32
#define MD_API_EXPORT __declspec(dllexport)
#else
#define MD_API_EXPORT
#endif

#include "NHUserApiStruct.h"
#include "NHUserApiErrCode.h"

class CNhMdSpi
{
public:
	///���ͻ������������ؽ�����ͨ������ʱ����δ��¼ǰ�����÷��������á�
	virtual void OnFrontConnected(){};
	
	///���ͻ�������������ͨ�����ӶϿ�ʱ���÷��������á�
	virtual void OnFrontDisConnected(){};

	///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
	/* \param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
	****************************************/
	virtual void OnHeartBeatWarning(int nTimeLapse){};

	/***************************************
	/* \fn    OnRspError
	/* \brief ����Ӧ��
	/* \param ERRORMSGINFO_t & req,����Ӧ����Ϣ
	/* \param TSequenceIDType nRequestID�����������request����Ĵ�����Ϊ��Ӧ����ID������Ϊ0
	/* \return void
	****************************************/
	virtual void OnRspError(ERRORMSGINFO_t &pRspInfo,TSequenceIDType nRequestID) {};

	///����֪ͨ
	virtual void OnRtnMarketData(STKMarketData_t &pData) {};

	/***************************************
	/* \fn    OnRspUtpLogin
	/* \brief ��¼�ϻ�ͳһ����ƽ̨UTP����ʱ��Ӧ
	/* \param RspUtpLoginField_t & req
	/* \param TSequenceIDType nRequestID��
	/* \return void
	****************************************/
	virtual void OnRspUtpLogin(const RspUtpLoginField_t& rsp,TSequenceIDType nRequestID){};
	
	/***************************************
	/* \fn    OnRspUtpLogout
	/* \brief ��¼�ϻ�ͳһ����ƽ̨UTP����ʱ��Ӧ
	/* \param RspUtpLogoutField_t & req
	/* \param TSequenceIDType nRequestID
	/* \return void
	****************************************/
	virtual void OnRspUtpLogout(const RspUtpLogoutField_t& rsp,TSequenceIDType nRequestID){};
	
	/***************************************
	/* \fn    OnRspSubscribe
	/* \brief ����������������ʱ��Ӧ
	/* \param RspSubscribeField_t & req
	/* \param TSequenceIDType nRequestID
	/* \return void
	****************************************/
	virtual void OnRspSubscribe(const RspSubscribeField_t& rsp,TSequenceIDType nRequestID){};
	
	/***************************************
	/* \fn    OnRspUnSubscribe
	/* \brief ȡ������������������ʱ��Ӧ
	/* \param RspUnSubscribeField_t & req
	/* \param TSequenceIDType nRequestID
	/* \return void
	****************************************/
	virtual void OnRspUnSubscribe(const RspUnSubscribeField_t& rsp,TSequenceIDType nRequestID){};

	/***************************************
	* \fn    OnRspQryExchange
	* \brief ��ѯ����������ʱ��Ӧ
	* \param RspQryExchangeField_t & rsp
	* \param TSequenceIDType nRequestID
	* \return void
	****************************************/
	virtual void OnRspQryExchange(const RspQryExchangeField_t& rsp,TSequenceIDType nRequestID){};

	/***************************************
	* \fn    OnRspQryInstrument
	* \brief ��ѯ��Լ����ʱ��Ӧ
	* \param RspQryInstrumentField_t & rsp
	* \param TSequenceIDType nRequestID
	* \return void
	****************************************/
	virtual void OnRspQryInstrument(const RspQryInstrumentField_t& rsp,TSequenceIDType nRequestID){};
};

class MD_API_EXPORT CNhMdApi
{
public:
	/***************************************
	/* \brief ����MdApi
	/* \return ��������UserApi
	****************************************/
	static CNhMdApi *CreateMdApi();

	/***************************************
	/* \brief ɾ���ӿڶ�����
	/* \remark ����ʹ�ñ��ӿڶ���ʱ,���øú���ɾ���ӿڶ���
	****************************************/
	virtual void Release() = 0;

	/***************************************
	/* \brief ��ʼ��
	/* \remark ��ʼ�����л���,ֻ�е��ú�,�ӿڲſ�ʼ����
	****************************************/
	virtual void Init() = 0;

	/***************************************
	/* \brief ��ȡϵͳ�汾��
	/* \param nMajorVersion ���汾��
	/* \param nMinorVersion �Ӱ汾��
	/* \return ϵͳ��ʶ�ַ���
	****************************************/
	virtual const char *GetVersion(int &nMajorVersion, int &nMinorVersion) = 0;

	/***************************************
	/* \brief ע��ǰ�û������ַ
	/* \param pszFrontAddress��ǰ�û������ַ��
	/* \remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:17001���� 
	/* \remark ��tcp��������Э�飬��127.0.0.1�������������ַ����17001������������˿ںš�
	****************************************/
	virtual void RegisterFront(char *pszFrontAddress) = 0;

	/***************************************
	/* \brief ע�����ַ����������ַ(��δʹ��)
	/* \param pszNsAddress�����ַ����������ַ��
	/* \remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:12001���� 
	/* \remark ��tcp��������Э�飬��127.0.0.1�������������ַ����12001������������˿ںš�
	/* \remark RegisterNameServer������RegisterFront
	****************************************/
	virtual void RegisterNameServer(char *pszNsAddress) = 0;
	
	/***************************************
	/*ע��ص��ӿ�
	/* \param pSpi �����Իص��ӿ����ʵ��
	****************************************/
	virtual void RegisterSpi(CNhMdSpi *pSpi) = 0;

	/***************************************
	/* \brief ����������ʱʱ�䡣
	/* \param timeout ������ʱʱ��(��)  
	****************************************/
	virtual void SetHeartbeatTimeout(unsigned int timeout) = 0;
	
	/***************************************
	/* \fn    UtpLoginRequest
	/* \brief ���͵�¼�ϻ�ͳһ����ƽ̨UTP����
	/* \param TSequenceIDType nRequestID �������
	/* \return 0:�ɹ�������ʧ��,���سɹ�ֻ���������ͳɹ�
	/*			 �������ڶ�Ӧ�ص������м��
	****************************************/
	virtual int ReqUtpLogin(ReqUtpLoginField_t& req, TSequenceIDType nRequestID) = 0;

	/***************************************
	* \fn    UtpLogoutRequest
	* \brief ���͵ǳ��ϻ�ͳһ����ƽ̨UTP����
	* \param TSequenceIDType nRequestID �������
	* \return 0:�ɹ�������ʧ��,���سɹ�ֻ���������ͳɹ�
	*			 �������ڶ�Ӧ�ص������м��
	****************************************/
	virtual int ReqUtpLogout(TSequenceIDType nRequestID) = 0;

	/***************************************
	* \fn    SubscribeRequest
	* \brief ���Ͷ���������������,���������ݶ��ĳɹ��Ժ��������Ͽ�����Ҫ���¶���
	* \���û��ɹ�logout�Ժ�ϵͳ���Զ�ȡ���������е�������Ϣ��
	* \param ReqSubscribeField_t & req
	* \param TSequenceIDType nRequestID �������
	* \return 0:�ɹ�������ʧ��,���سɹ�ֻ���������ͳɹ�
	*			 �������ڶ�Ӧ�ص������м��
	****************************************/
	virtual int ReqSubscribe(ReqSubscribeField_t& req,TSequenceIDType nRequestID) = 0;

	/***************************************
	* \fn    UnSubscribeRequest
	* \brief ����ȡ������������������
	* \param ReqUnSubscribeField_t & req
	* \param TSequenceIDType nRequestID �������
	* \return 0:�ɹ�������ʧ��,���سɹ�ֻ���������ͳɹ�
	*			 �������ڶ�Ӧ�ص������м��
	****************************************/
	virtual int ReqUnSubscribe(ReqUnSubscribeField_t& req,TSequenceIDType nRequestID) = 0;

	/***************************************
	* \fn    AuthUserPassworRequest(�÷�����ʱδ��)
	* \brief �����û���֤��������
	* \param ReqAuthUserPassworField_t & req
	* \param TSequenceIDType nRequestID �������
	* \return 0:�ɹ�������ʧ��,���سɹ�ֻ���������ͳɹ�
	*			 �������ڶ�Ӧ�ص������м��
	****************************************/
	virtual int ReqAuthUserPasswor(ReqAuthUserPassworField_t& req,TSequenceIDType nRequestID) = 0;
		
	/***************************************
	* \fn    ReqQryExchange
	* \brief ���Ͳ�ѯ����������
	* \param ReqQryExchangeField_t & req
	* \param TSequenceIDType nRequestID �������
	* \return 0:�ɹ�������ʧ��,���سɹ�ֻ���������ͳɹ�
	*			 �������ڶ�Ӧ�ص������м��
	****************************************/
	virtual int ReqQryExchange(const ReqQryExchangeField_t& req,TSequenceIDType nRequestID) = 0;
	
	/***************************************
	* \fn    ReqQryInstrument
	* \brief ���Ͳ�ѯ��Լ����
	* \param ReqQryInstrumentField_t & req
	* \param TSequenceIDType nRequestID �������
	* \return 0:�ɹ�������ʧ��,���سɹ�ֻ���������ͳɹ�
	*			 �������ڶ�Ӧ�ص������м��
	****************************************/
	virtual int ReqQryInstrument(const ReqQryInstrumentField_t& req,TSequenceIDType nRequestID) = 0;
protected:
	~CNhMdApi();
};

#endif
