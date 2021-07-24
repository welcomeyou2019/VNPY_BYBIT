//ϵͳ
#ifdef WIN32
#include "stdafx.h"
#endif

#include "vnnh.h"
#include "pybind11/pybind11.h"
#include "nh/stock/NhStockTraderApi.h"


using namespace pybind11;
using namespace nhtd;


//����
#define ONFRONTCONNECTED 0
#define ONFRONTDISCONNECTED 1
#define ONHEARTBEATWARNING 2
#define ONPACKAGESTART 3
#define ONPACKAGEEND 4
#define ONRSPSUBSCRIBETOPIC 5
#define ONRSPUSERLOGIN 6
#define ONRSPUSERLOGOUT 7
#define ONRSPUSERPASSWORDUPDATE 8
#define ONRSPSTOCKINSERT 9
#define ONRSPSTOCKCANCEL 10
#define ONRSPOPTIONSINSERT 11
#define ONRSPOPTIONSCANCEL 12
#define ONRSPQUOTEINSERT 13
#define ONRSPFORQUOTE 14
#define ONRSPQUOTECANCEL 15
#define ONRSPSTOCKLOCK 16
#define ONRSPEXERCISE 17
#define ONRSPEXERCISECANCEL 18
#define ONRSPQRYPARTACCOUNT 19
#define ONRSPQRYSTOCKORDER 20
#define ONRSPQRYOPTIONSORDER 21
#define ONRSPQRYQUOTEORDER 22
#define ONRSPQRYSTOCKTRADE 23
#define ONRSPQRYOPTIONSTRADE 24
#define ONRSPQRYPOSITION 25
#define ONRSPQRYTOPIC 26
#define ONRSPQRYSTOCK 27
#define ONRSPQRYOPTIONS 28
#define ONRTNOPTIONSORDER 29
#define ONRTNSTOCKORDER 30
#define ONRTNQUOTEORDER 31
#define ONRTNOPTIONSTRADE 32
#define ONRTNSTOCKTRADE 33
#define ONRTNEXERCISE 34
#define ONRSPQRYRATE 35
#define ONRSPQRYCLIENT 36
#define ONRSPQRYCLIENTMARGIN 37
#define ONRSPQRYEXERCISE 38
#define ONRTNWITHDRAWDEPOSIT 39
#define ONRSPMARGINCOMBACTION 40
#define ONRTNMARGINCOMBACTION 41
#define ONRSPQRYSSECOMBPOSITION 42
#define ONRSPCOMBEXERCISE 43


///-------------------------------------------------------------------------------------
///C++ SPI�Ļص���������ʵ��
///-------------------------------------------------------------------------------------

//API�ļ̳�ʵ��
class StockTdApi : public CNhStockTraderSpi
{
private:
	CNhStockTraderApi* api;				//API����
	thread task_thread;					//�����߳�ָ�루��python���������ݣ�
	TaskQueue task_queue;			    //�������
	bool active = false;				//����״̬

public:
	StockTdApi()
	{
	};

	~StockTdApi()
	{
		if (this->active)
		{
			this->exit();
		}
	};

	//-------------------------------------------------------------------------------------
	//API�ص�����
	//-------------------------------------------------------------------------------------

	///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
	virtual void OnFrontConnected();

	///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
	///@param nReason ����ԭ��
	///        0x1001 �����ʧ��
	///        0x1002 ����дʧ��
	///        0x2001 ����������ʱ
	///        0x2002 ��������ʧ��
	///        0x2003 �յ�������
	virtual void OnFrontDisconnected(int nReason);

	///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
	///@param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
	virtual void OnHeartBeatWarning(int nTimeLapse);

	///���Ļص���ʼ֪ͨ����API�յ�һ�����ĺ����ȵ��ñ�������Ȼ���Ǹ�������Ļص�������Ǳ��Ļص�����֪ͨ��
	///@param nTopicID ������루��˽���������������������ȣ�
	///@param nSequenceNo �������
	virtual void OnPackageStart(int nTopicID, int nSequenceNo);

	///���Ļص�����֪ͨ����API�յ�һ�����ĺ����ȵ��ñ��Ļص���ʼ֪ͨ��Ȼ���Ǹ�������Ļص��������ñ�������
	///@param nTopicID ������루��˽���������������������ȣ�
	///@param nSequenceNo �������
	virtual void OnPackageEnd(int nTopicID, int nSequenceNo);

	///��������Ӧ��
	virtual void OnRspSubscribeTopic(CStockFtdcDisseminationField *pDissemination, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�û���¼Ӧ��
	virtual void OnRspUserLogin(CStockFtdcRspUserLoginField *pRspUserLogin, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�û��˳�Ӧ��
	virtual void OnRspUserLogout(CStockFtdcRspUserLogoutField *pRspUserLogout, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�û������޸�Ӧ��
	virtual void OnRspUserPasswordUpdate(CStockFtdcUserPasswordUpdateField *pUserPasswordUpdate, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��Ʊ����Ӧ��
	virtual void OnRspStockInsert(CStockFtdcStockInsertRspField *pStockInsert, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��Ʊ����Ӧ��
	virtual void OnRspStockCancel(CStockFtdcStockCancelRspField *pStockCancel, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��Ȩ����Ӧ��
	virtual void OnRspOptionsInsert(CStockFtdcOptionsInsertRspField *pOptionsInsert, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��Ȩ����Ӧ��
	virtual void OnRspOptionsCancel(CStockFtdcOptionsCancelRspField *pOptionsCancel, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��Ȩ����Ӧ��
	virtual void OnRspQuoteInsert(CStockFtdcQuoteInsertRspField *pQuoteInsert, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��Ȩ��������Ӧ��
	virtual void OnRspForQuote(CStockFtdcForQuoteRspField *pForQuote, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///ѯ��Ӧ��
	virtual void OnRspQuoteCancel(CStockFtdcQuoteCancelRspField *pQuoteCancel, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///֤ȯ����Ӧ��
	virtual void OnRspStockLock(CStockFtdcStockLockRspField *pStockLock, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��ȨӦ��
	virtual void OnRspExercise(CStockFtdcExerciseRspField *pExercise, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///������ȨӦ��
	virtual void OnRspExerciseCancel(CStockFtdcExerciseCancelRspField *pExercise, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��Ա�ʽ��ѯӦ��
	virtual void OnRspQryPartAccount(CStockFtdcRspPartAccountField *pRspPartAccount, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��Ʊ������ѯӦ��
	virtual void OnRspQryStockOrder(CStockFtdcRspQryStockOrderField *pOrder, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��Ȩ������ѯӦ��
	virtual void OnRspQryOptionsOrder(CStockFtdcRspQryOptionsOrderField *pOrder, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///���۲�ѯӦ��
	virtual void OnRspQryQuoteOrder(CStockFtdcRspQryQuoteOrderField *pQuote, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��Ʊ�ɽ���ѯӦ��
	virtual void OnRspQryStockTrade(CStockFtdcStockTradeField *pTrade, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��Ȩ�ɽ���ѯӦ��
	virtual void OnRspQryOptionsTrade(CStockFtdcOptionsTradeField *pTrade, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�ֲֲ�ѯӦ��
	virtual void OnRspQryPosition(CStockFtdcRspPositionField *pPosition, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯӦ��
	virtual void OnRspQryTopic(CStockFtdcDisseminationField *pDissemination, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	//��Ʊ��ѯӦ��
	virtual void OnRspQryStock(CStockFtdcRspQryStockField *pStock, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	//��Ȩ��ѯӦ��
	virtual void OnRspQryOptions(CStockFtdcRspQryOptionsField *pOptions, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��Ȩί�лر�
	virtual void OnRtnOptionsOrder(CStockFtdcOptionsOrderField *pOrder);

	///��Ʊί�лر�
	virtual void OnRtnStockOrder(CStockFtdcStockOrderField *pOrder);

	///���ۻر�
	virtual void OnRtnQuoteOrder(CStockFtdcQuoteOrderField *pQuote);

	///��Ȩ�ɽ��ر�
	virtual void OnRtnOptionsTrade(CStockFtdcOptionsTradeField *pTrade);

	///��Ʊ�ɽ��ر�
	virtual void OnRtnStockTrade(CStockFtdcStockTradeField *pTrade);

	///��Ȩ�ر�
	virtual void OnRtnExercise(CStockFtdcExerciseRtnField *pExercise);

	///��ѯ������ϢӦ��
	virtual void OnRspQryRate(CStockFtdcRspQryRateField *pRate, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��Ա�ͻ���ѯӦ��
	virtual void OnRspQryClient(CStockFtdcRspClientField *pRspClient, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�ͻ���֤���ѯӦ��
	virtual void OnRspQryClientMargin(CStockFtdcRspQryClientMarginField *pRspMargin, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��ѯ��ȨӦ��
	virtual void OnRspQryExercise(CStockFtdcExerciseRtnField *pExercise, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����֪ͨ
	virtual void OnRtnWithdrawDeposit(CStockFtdcWithdrawDepositRtnField *pWithdrawDeposit);

	///�ͻ������������
	virtual void OnRspMarginCombAction(CStockFtdcMarginCombActionRspField *pMarginCombAction, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�ͻ��������֪ͨ
	virtual void OnRtnMarginCombAction(CStockFtdcMarginCombActionRtnField *pMarginCombAction);

	///��������ϳֲֲ�ѯӦ��
	virtual void OnRspQrySseCombPosition(CStockFtdcCombPositionRspField *pPosi, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ȨӦ��
	virtual void OnRspCombExercise(CStockFtdcCombExerciseRspField *pExercise, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	//-------------------------------------------------------------------------------------
	//task������
	//-------------------------------------------------------------------------------------

	void processTask();

	void processFrontConnected(Task *task);

	void processFrontDisconnected(Task *task);

	void processHeartBeatWarning(Task *task);

	void processRspSubscribeTopic(Task *task);

	void processRspUserLogin(Task *task);

	void processRspUserLogout(Task *task);

	void processRspUserPasswordUpdate(Task *task);

	void processRspStockInsert(Task *task);

	void processRspStockCancel(Task *task);

	void processRspOptionsInsert(Task *task);

	void processRspOptionsCancel(Task *task);

	void processRspQuoteInsert(Task *task);

	void processRspForQuote(Task *task);

	void processRspQuoteCancel(Task *task);

	void processRspStockLock(Task *task);

	void processRspExercise(Task *task);

	void processRspExerciseCancel(Task *task);

	void processRspQryPartAccount(Task *task);

	void processRspQryStockOrder(Task *task);

	void processRspQryOptionsOrder(Task *task);

	void processRspQryQuoteOrder(Task *task);

	void processRspQryStockTrade(Task *task);

	void processRspQryOptionsTrade(Task *task);

	void processRspQryPosition(Task *task);

	void processRspQryTopic(Task *task);

	void processRspQryStock(Task *task);

	void processRspQryOptions(Task *task);

	void processRtnOptionsOrder(Task *task);

	void processRtnStockOrder(Task *task);

	void processRtnQuoteOrder(Task *task);

	void processRtnOptionsTrade(Task *task);

	void processRtnStockTrade(Task *task);

	void processRtnExercise(Task *task);

	void processRspQryRate(Task *task);

	void processRspQryClient(Task *task);

	void processRspQryClientMargin(Task *task);

	void processRspQryExercise(Task *task);

	void processRtnWithdrawDeposit(Task *task);

	void processRspMarginCombAction(Task *task);

	void processRtnMarginCombAction(Task *task);

	void processRspQrySseCombPosition(Task *task);

	void processRspCombExercise(Task *task);

	//-------------------------------------------------------------------------------------
	//data���ص������������ֵ�
	//error���ص������Ĵ����ֵ�
	//id������id
	//last���Ƿ�Ϊ��󷵻�
	//i������
	//-------------------------------------------------------------------------------------

	virtual void onFrontConnected() {};

	virtual void onFrontDisconnected(int reqid) {};

	virtual void onHeartBeatWarning(int reqid) {};

	virtual void onRspSubscribeTopic(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspUserLogin(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspUserLogout(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspUserPasswordUpdate(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspStockInsert(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspStockCancel(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspOptionsInsert(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspOptionsCancel(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQuoteInsert(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspForQuote(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQuoteCancel(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspStockLock(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspExercise(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspExerciseCancel(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryPartAccount(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryStockOrder(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryOptionsOrder(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryQuoteOrder(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryStockTrade(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryOptionsTrade(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryPosition(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryTopic(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryStock(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryOptions(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRtnOptionsOrder(const dict &data) {};

	virtual void onRtnStockOrder(const dict &data) {};

	virtual void onRtnQuoteOrder(const dict &data) {};

	virtual void onRtnOptionsTrade(const dict &data) {};

	virtual void onRtnStockTrade(const dict &data) {};

	virtual void onRtnExercise(const dict &data) {};

	virtual void onRspQryRate(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryClient(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryClientMargin(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryExercise(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRtnWithdrawDeposit(const dict &data) {};

	virtual void onRspMarginCombAction(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRtnMarginCombAction(const dict &data) {};

	virtual void onRspQrySseCombPosition(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspCombExercise(const dict &data, const dict &error, int reqid, bool last) {};

	//-------------------------------------------------------------------------------------
	//req:���������������ֵ�
	//-------------------------------------------------------------------------------------

	void createStockTdApi(string flowPath);

	string getVersion();

	void release();

	void init(string localIp, string netWorkCard);

	int exit();

	string getTradingDay();

	void registerFront(string address);

	void subscribePrivateTopic(int type);

	void subscribePublicTopic(int type);

	void subscribeUserTopic(int type);

	int reqSubscribeTopic(const dict &req, int reqid);

	int reqUserLogin(const dict &req, int reqid);

	int reqUserLogout(const dict &req, int reqid);

	int reqUserPasswordUpdate(const dict &req, int reqid);

	int reqStockInsert(const dict &req, int reqid);

	int reqStockCancel(const dict &req, int reqid);

	int reqStockLock(const dict &req, int reqid);

	int reqOptionsInsert(const dict &req, int reqid);

	int reqOptionsCancel(const dict &req, int reqid);

	int reqQuoteInsert(const dict &req, int reqid);

	int reqQuoteCancel(const dict &req, int reqid);

	int reqForQuote(const dict &req, int reqid);

	int reqExercise(const dict &req, int reqid);

	int reqExerciseCancel(const dict &req, int reqid);

	int reqQryPartAccount(const dict &req, int reqid);

	int reqQryStockOrder(const dict &req, int reqid);

	int reqQryOptionsOrder(const dict &req, int reqid);

	int reqQryQuoteOrder(const dict &req, int reqid);

	int reqQryStockTrade(const dict &req, int reqid);

	int reqQryOptionsTrade(const dict &req, int reqid);

	int reqQryPosition(const dict &req, int reqid);

	int reqQryTopic(const dict &req, int reqid);

	int reqQryStock(const dict &req, int reqid);

	int reqQryOptions(const dict &req, int reqid);

	int reqQryRate(const dict &req, int reqid);

	int reqQryClient(int reqid);

	int reqQryClientMargin(const dict &req, int reqid);

	int reqQryExercise(const dict &req, int reqid);

	int reqMarginCombAction(const dict &req, int reqid);

	int reqQrySseCombPosition(const dict &req, int reqid);

	int reqCombExercise(const dict &req, int reqid);
};
