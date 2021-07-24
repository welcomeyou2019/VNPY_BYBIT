//ϵͳ
#ifdef WIN32
#include "pch.h"
#endif

#include "vnsip.h"
#include "pybind11/pybind11.h"
#include "isipuix.h"


using namespace pybind11;
using namespace api;



///-------------------------------------------------------------------------------------
///C++ SPI�Ļص���������ʵ��
///-------------------------------------------------------------------------------------

//API�ļ̳�ʵ��
class MdApi : public CSipMdSpi
{
private:
	ISIPUIX_EXPORT CSipMdApi* api;      //API����
    bool active = false;                //����״̬
	bool logging = false;

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

	virtual void OnLog(int32_t level, const char *source, const char *slog);
	/*!
	\brief ��¼�ɹ���ص����������涩��
	\param chn ͨ����,һ��ͨ��ʱΪ0,����Ϊ1��ʼ��
	*/

	/*!
	\brief �Ͽ�ʱ�ص�
	\param chn ͨ���š�
	*/
	virtual void OnDisconnect(int32_t chn);

	/*
	\brief ���鶩�Ļص�
	\param errmsg �洢������errcode�������Ϣerrstr�Ľṹ�壬errcodeֵΪ0����ɹ�������ֵΪ�����룬������Ϣ��洢��errstr�ַ�����
	\param errmsg �ṹ���е�channel��mktype��datatype��������ʶ��֤ȯ����codes����ʧ�ܵĶ�Ӧͨ�����г��������������͡�
	*/
	virtual void OnSubscribe(ErrMsg *errmsg);

	/*
	\brief �����˶��ص�
	\param errmsg �洢������errcode�������Ϣerrstr�Ľṹ�壬errcodeֵΪ0����ɹ�������ֵΪ�����룬������Ϣ��洢��errstr�ַ�����
	\param errmsg �ṹ���е�channel��mktype��datatype��������ʶ��֤ȯ����codes�˶�ʧ�ܵĶ�Ӧͨ�����г��������������͡�
	*/
	virtual void OnUnSubscribe(ErrMsg *errmsg);

	/*!
	\brief L2�������ݻص�
	\param mktype �����ĵ��г�����
	\param code ���ĵ�֤ȯ����
	\param dataL2 L2����ṹ��
	*/
	virtual void OnDepthMarketData(MKtype mk_type, char *code, Stock_MarketData *dataL2);

	/*!
	\brief L1�������ݻص�
	\param mktype �����ĵ��г�����
	\param code ���ĵ�֤ȯ����
	\param dataL1 L1����ṹ��
	*/
	virtual void OnMarketData(MKtype mk_type, char *code, StockMarketDataL1 *dataL1);

	/*!
	\brief ָ������ص�
	\param mktype �����ĵ��г�����
	\param code ���ĵ�֤ȯ����
	\param stockindex ָ������ṹ��
	*/
	virtual void OnIndexData(MKtype mk_type, char *code, Stock_IndexData *stockindex);


	/*!
	\brief ί�ж����������ݻص�
	\param mktype �����ĵ��г�����
	\param code ���ĵ�֤ȯ����
	\param orderqueue ί�ж����������ݽṹ��
	*/
	virtual void OnOrderQueue(MKtype mk_type, char *code, StockOrderQueue *orderqueue);

	/*!
	\brief �Ͻ�����ʳɽ��������ݻص�
	\param code ���ĵ�֤ȯ����
	\param steptrade �Ͻ�������������ݽṹ��
	*/
	virtual void OnSHTrade(char *code, t_SH_StockStepTrade *steptrade);

	/*!
	\brief �����ʳɽ��������ݻص�
	\param code ���ĵ�֤ȯ����
	\param steptrade �������������ݽṹ��
	*/
	virtual void OnSZTrade(char *code, T_SZ_STEPTRADE *steptrade);

	/*!
	\brief ������ί���������ݻص�
	\param code ���ĵ�֤ȯ����
	\param steptrade �������������ݽṹ��
	*/
	virtual void OnSZOrder(char *code, T_SZ_STEPORDER *steporder);

	/*!
	\brief �Ͻ���������Ϣ�ص�
	\param code ���ĵ�֤ȯ����
	\param baseinfodata �Ͻ���������Ϣ���ݽṹ��
	*/
	virtual void OnSHBaseInfo(char *code, T_SH_BaseInfo *baseinfodata);

	virtual void OnSZBaseInfo(char *code, t_SZ_BaseInfo *baseinfodata) ;

	/*!
	\brief ����K�߻ص�
	\param mktype �����ĵ��г�����
	\param code ���ĵ�֤ȯ����
	\param kline ����K�����ݽṹ��
	*/
	virtual void OnKline(MKtype mk_type, char *code, T_Kline *kline);


	/*!
	\brief ETF��չ�������ݻص�
	\param mktype �����ĵ��г�����
	\param code ���ĵ�֤ȯ����
	\param etfextdata ETF��չ�������ݽṹ��
	*/
	virtual void OnEtfExtData(MKtype mk_type, char *code, T_ETFEXTENDS *etfextdata);
    //-------------------------------------------------------------------------------------
    //data���ص������������ֵ�
    //error���ص������Ĵ����ֵ�
    //id������id
    //last���Ƿ�Ϊ��󷵻�
    //i������
    //-------------------------------------------------------------------------------------
	virtual void onLog(int level, string source, string slog) {};

	virtual void onDisconnect(int chn) {};

	virtual void onSubscribe(const dict &error) {};

	virtual void onUnSubscribe(const dict &error) {};

	virtual void onDepthMarketData(int mk_type, string code, const dict &data) {};

	virtual void onMarketData(int mk_type, string code, const dict &data) {};

	virtual void onIndexData(int mk_type, string code, const dict &data) {};

	virtual void onOrderQueue(int mk_type, string code, const dict &data) {};

	virtual void onSHTrade(string code, const dict &data) {};

	virtual void onSZTrade(string code, const dict &data) {};

	virtual void onSZOrder(string code, const dict &data) {};

	virtual void onSHBaseInfo(string code, const dict &data) {};

	virtual void onSZBaseInfo(string code, const dict &data) {};

	virtual void onKline(int mk_type, string code, const dict &data) {};

	virtual void onEtfExtData(int mk_type, string code, const dict &data) {};


    //-------------------------------------------------------------------------------------
    //req:���������������ֵ�
    //-------------------------------------------------------------------------------------
	int createMdApi(string sjson, bool logging);

	int login();

	int stop();

	void release();

	int exit();

	int subscribeDepthMarketData(int mk_type, string code);

	int subscribeMarketData(int mk_type, string code);

	int subscribeIndexData(int mk_type, string code);

	int unSubscribeDepthMarketData(int mk_type, string code);

	int unSubscribeMarketData(int mk_type, string code);

	int unSubscribeIndexData(int mk_type, string code);

	int subscribeOrderQueue(int mk_type, string code);

	int unSubscribeOrderQueue(int mk_type, string code);

	int subscribeStepTrade(int mk_type, string code);

	int unSubscribeStepTrade(int mk_type, string code);

	int subscribeStepOrder(int mk_type, string code);

	int unSubscribeStepOrder(int mk_type, string code);

	int subscribeBaseInfo(int mk_type);

	int unSubscribeBaseInfo(int mk_type, string code);

	int subscribeKline(int mk_type, string code);

	int unSubscribeKline(int mk_type, string code);

	int subscribeFutures(int mk_type, string code);

	int unSubscribeFutures(int mk_type, string code);

	int subscribeEtfExt(int mk_type, string code);

	int unSubscribeEtfExt(int mk_type, string code);
};
