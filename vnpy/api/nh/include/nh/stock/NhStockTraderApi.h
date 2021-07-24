
#if !defined(NH_STOCKTRADERAPI_H)
#define NH_STOCKTRADERAPI_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "NhStockUserApiStruct.h"

#if defined(WIN32)
#ifdef LIB_TRADER_API_EXPORT
#define TRADER_API_EXPORT __declspec(dllexport)
#else
#define TRADER_API_EXPORT __declspec(dllimport)
#endif
#else
#define TRADER_API_EXPORT __attribute__ ((visibility("default")))
#endif

namespace nhtd
{
	class CNhStockTraderSpi
	{
	public:
		///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
		virtual void OnFrontConnected() {};

		///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
		///@param nReason ����ԭ��
		///        0x1001 �����ʧ��
		///        0x1002 ����дʧ��
		///        0x2001 ����������ʱ
		///        0x2002 ��������ʧ��
		///        0x2003 �յ�������
		virtual void OnFrontDisconnected(int nReason) {};

		///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
		///@param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
		virtual void OnHeartBeatWarning(int nTimeLapse) {};

		///���Ļص���ʼ֪ͨ����API�յ�һ�����ĺ����ȵ��ñ�������Ȼ���Ǹ�������Ļص�������Ǳ��Ļص�����֪ͨ��
		///@param nTopicID ������루��˽���������������������ȣ�
		///@param nSequenceNo �������
		virtual void OnPackageStart(int nTopicID, int nSequenceNo) {};

		///���Ļص�����֪ͨ����API�յ�һ�����ĺ����ȵ��ñ��Ļص���ʼ֪ͨ��Ȼ���Ǹ�������Ļص��������ñ�������
		///@param nTopicID ������루��˽���������������������ȣ�
		///@param nSequenceNo �������
		virtual void OnPackageEnd(int nTopicID, int nSequenceNo) {};

		///��������Ӧ��
		virtual void OnRspSubscribeTopic(CStockFtdcDisseminationField *pDissemination, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

		///�û���¼Ӧ��
		virtual void OnRspUserLogin(CStockFtdcRspUserLoginField *pRspUserLogin, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

		///�û��˳�Ӧ��
		virtual void OnRspUserLogout(CStockFtdcRspUserLogoutField *pRspUserLogout, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

		///�û������޸�Ӧ��
		virtual void OnRspUserPasswordUpdate(CStockFtdcUserPasswordUpdateField *pUserPasswordUpdate, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

		///��Ʊ����Ӧ��
		virtual void OnRspStockInsert(CStockFtdcStockInsertRspField *pStockInsert, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

		///��Ʊ����Ӧ��
		virtual void OnRspStockCancel(CStockFtdcStockCancelRspField *pStockCancel, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

		///��Ȩ����Ӧ��
		virtual void OnRspOptionsInsert(CStockFtdcOptionsInsertRspField *pOptionsInsert, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

		///��Ȩ����Ӧ��
		virtual void OnRspOptionsCancel(CStockFtdcOptionsCancelRspField *pOptionsCancel, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

		///��Ȩ����Ӧ��
		virtual void OnRspQuoteInsert(CStockFtdcQuoteInsertRspField *pQuoteInsert, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

		///��Ȩ��������Ӧ��
		virtual void OnRspForQuote(CStockFtdcForQuoteRspField *pForQuote, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

		///ѯ��Ӧ��
		virtual void OnRspQuoteCancel(CStockFtdcQuoteCancelRspField *pQuoteCancel, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

		///֤ȯ����Ӧ��
		virtual void OnRspStockLock(CStockFtdcStockLockRspField *pStockLock, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

		///��ȨӦ��
		virtual void OnRspExercise(CStockFtdcExerciseRspField *pExercise, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

		///������ȨӦ��
		virtual void OnRspExerciseCancel(CStockFtdcExerciseCancelRspField *pExercise, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

		///��Ա�ʽ��ѯӦ��
		virtual void OnRspQryPartAccount(CStockFtdcRspPartAccountField *pRspPartAccount, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

		///��Ʊ������ѯӦ��
		virtual void OnRspQryStockOrder(CStockFtdcRspQryStockOrderField *pOrder, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

		///��Ȩ������ѯӦ��
		virtual void OnRspQryOptionsOrder(CStockFtdcRspQryOptionsOrderField *pOrder, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

		///���۲�ѯӦ��
		virtual void OnRspQryQuoteOrder(CStockFtdcRspQryQuoteOrderField *pQuote, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

		///��Ʊ�ɽ���ѯӦ��
		virtual void OnRspQryStockTrade(CStockFtdcStockTradeField *pTrade, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

		///��Ȩ�ɽ���ѯӦ��
		virtual void OnRspQryOptionsTrade(CStockFtdcOptionsTradeField *pTrade, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

		///�ֲֲ�ѯӦ��
		virtual void OnRspQryPosition(CStockFtdcRspPositionField *pPosition, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

		///�����ѯӦ��
		virtual void OnRspQryTopic(CStockFtdcDisseminationField *pDissemination, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

		//��Ʊ��ѯӦ��
		virtual void OnRspQryStock(CStockFtdcRspQryStockField *pStock, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

		//��Ȩ��ѯӦ��
		virtual void OnRspQryOptions(CStockFtdcRspQryOptionsField *pOptions, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

		///��Ȩί�лر�
		virtual void OnRtnOptionsOrder(CStockFtdcOptionsOrderField *pOrder) {};

		///��Ʊί�лر�
		virtual void OnRtnStockOrder(CStockFtdcStockOrderField *pOrder) {};

		///���ۻر�
		virtual void OnRtnQuoteOrder(CStockFtdcQuoteOrderField *pQuote) {};

		///��Ȩ�ɽ��ر�
		virtual void OnRtnOptionsTrade(CStockFtdcOptionsTradeField *pTrade) {};

		///��Ʊ�ɽ��ر�
		virtual void OnRtnStockTrade(CStockFtdcStockTradeField *pTrade) {};

		///��Ȩ�ر�
		virtual void OnRtnExercise(CStockFtdcExerciseRtnField *pExercise) {};

		///��ѯ������ϢӦ��
		virtual void OnRspQryRate(CStockFtdcRspQryRateField *pRate, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

		///��Ա�ͻ���ѯӦ��
		virtual void OnRspQryClient(CStockFtdcRspClientField *pRspClient, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

		///�ͻ���֤���ѯӦ��
		virtual void OnRspQryClientMargin(CStockFtdcRspQryClientMarginField *pRspMargin, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

		///��ѯ��ȨӦ��
		virtual void OnRspQryExercise(CStockFtdcExerciseRtnField *pExercise, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

		///�����֪ͨ
		virtual void OnRtnWithdrawDeposit(CStockFtdcWithdrawDepositRtnField *pWithdrawDeposit) {};

		///�ͻ������������
		virtual void OnRspMarginCombAction(CStockFtdcMarginCombActionRspField *pMarginCombAction, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
		
		///�ͻ��������֪ͨ
		virtual void OnRtnMarginCombAction(CStockFtdcMarginCombActionRtnField *pMarginCombAction) {};

		///��������ϳֲֲ�ѯӦ��
		virtual void OnRspQrySseCombPosition(CStockFtdcCombPositionRspField *pPosi, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
		
		///�����ȨӦ��
		virtual void OnRspCombExercise(CStockFtdcCombExerciseRspField *pExercise, CStockFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	};

	class TRADER_API_EXPORT CNhStockTraderApi
	{
	public:
		///����TraderApi
	///@param pszFlowPath ����������Ϣ�ļ���Ŀ¼��Ĭ��Ϊ��д��
	///@return ��������UserApi
		static CNhStockTraderApi *CreateFtdcTraderApi(const char *pszFlowPath = "");

		///��ȡϵͳ�汾��
		///@param nMajorVersion ���汾��
		///@param nMinorVersion �Ӱ汾��
		///@return ϵͳ��ʶ�ַ���
		static const char *GetVersion(int &nMajorVersion, int &nMinorVersion);

		///ɾ���ӿڶ�����
		///@remark ����ʹ�ñ��ӿڶ���ʱ,���øú���ɾ���ӿڶ���
		virtual void Release() = 0;

		///��ʼ��
		///@param localIp�����ͨ��tcpdirect�����ͽ������ݣ���Ϊ���ͽ������ݵ�����ip��
		///@param netWorkCard�����ͨ��tcpdirect�����ͽ������ݣ���Ϊ���ͽ������ݵ���������
		///@remark ��ʼ�����л���,ֻ�е��ú�,�ӿڲſ�ʼ����
		virtual void Init(const char *localIp = "", const char *netWorkCard = "") = 0;

		///��ȡ��ǰ������
		///@retrun ��ȡ���Ľ�����
		///@remark ֻ�е�¼�ɹ���,���ܵõ���ȷ�Ľ�����
		virtual const char *GetTradingDay() = 0;

		///ע��ǰ�û������ַ
		///@param pszFrontAddress��ǰ�û������ַ��
		///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:17001����
		///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����17001������������˿ںš�
		virtual void RegisterFront(char *pszFrontAddress) = 0;

		///ע��ص��ӿ�
		///@param pSpi �����Իص��ӿ����ʵ��
		virtual void RegisterSpi(CNhStockTraderSpi *pSpi) = 0;

		///����˽������
		///@param nResumeType ˽�����ش���ʽ
		///        TERT_RESTART:�ӱ������տ�ʼ�ش�
		///        TERT_RESUME:���ϴ��յ�������
		///        TERT_QUICK:ֻ���͵�¼��˽����������
		///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ�˽���������ݡ�
		virtual void SubscribePrivateTopic(SZSE_TE_RESUME_TYPE nResumeType) = 0;

		///���Ĺ�������
		///@param nResumeType �������ش���ʽ
		///        TERT_RESTART:�ӱ������տ�ʼ�ش�
		///        TERT_RESUME:���ϴ��յ�������
		///        TERT_QUICK:ֻ���͵�¼�󹫹���������
		///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ������������ݡ�
		virtual void SubscribePublicTopic(SZSE_TE_RESUME_TYPE nResumeType) = 0;

		///���Ľ���Ա����
		///@param nResumeType ����Ա���ش���ʽ
		///        TERT_RESTART:�ӱ������տ�ʼ�ش�
		///        TERT_RESUME:���ϴ��յ�������
		///        TERT_QUICK:ֻ���͵�¼����Ա��������
		///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ�����Ա�������ݡ�
		virtual void SubscribeUserTopic(SZSE_TE_RESUME_TYPE nResumeType) = 0;

		///����������ʱʱ�䡣
		///@param timeout ������ʱʱ��(��)
		virtual void SetHeartbeatTimeout(unsigned int timeout) = 0;

		///������������
		virtual int ReqSubscribeTopic(CStockFtdcDisseminationField *pDissemination, int nRequestID) = 0;

		///�û���¼����
		virtual int ReqUserLogin(CStockFtdcReqUserLoginField *pReqUserLogin, int nRequestID) = 0;

		///�û��˳�����
		virtual int ReqUserLogout(CStockFtdcReqUserLogoutField *pReqUserLogout, int nRequestID) = 0;

		///�û������޸�����
		virtual int ReqUserPasswordUpdate(CStockFtdcUserPasswordUpdateField *pUserPasswordUpdate, int nRequestID) = 0;

		///��Ʊ��������
		virtual int ReqStockInsert(CStockFtdcStockInsertReqField *pStockInsert, int nRequestID) = 0;

		///��Ʊ��������
		virtual int ReqStockCancel(CStockFtdcStockCancelReqField *pStockCancel, int nRequestID) = 0;

		///֤ȯ��������
		virtual int ReqStockLock(CStockFtdcStockLockReqField *pStockLock, int nRequestID) = 0;

		///��Ȩ��������
		virtual int ReqOptionsInsert(CStockFtdcOptionsInsertReqField *pOptionsInsert, int nRequestID) = 0;

		///��Ȩ��������
		virtual int ReqOptionsCancel(CStockFtdcOptionsCancelReqField *pOptionsCancel, int nRequestID) = 0;

		///��Ȩ��������
		virtual int ReqQuoteInsert(CStockFtdcQuoteInsertReqField *pQuoteInsert, int nRequestID) = 0;

		///��Ȩ������������
		virtual int ReqQuoteCancel(CStockFtdcQuoteCancelReqField *pQuoteCancel, int nRequestID) = 0;

		///ѯ������
		virtual int ReqForQuote(CStockFtdcForQuoteReqField *pForQuote, int nRequestID) = 0;

		///��Ȩ����
		virtual int ReqExercise(CStockFtdcExerciseReqField *pExercise, int nRequestID) = 0;

		///������Ȩ����
		virtual int ReqExerciseCancel(CStockFtdcExerciseCancelReqField *pExerciseCancel, int nRequestID) = 0;

		///�ʽ��ѯ����
		virtual int ReqQryPartAccount(CStockFtdcQryPartAccountField *pQryPartAccount, int nRequestID) = 0;

		///��Ʊ������ѯ����
		virtual int ReqQryStockOrder(CStockFtdcQryStockOrderField *pQryOrder, int nRequestID) = 0;

		///��Ȩ������ѯ����
		virtual int ReqQryOptionsOrder(CStockFtdcQryOptionsOrderField *pQryOrder, int nRequestID) = 0;

		///���۲�ѯ����
		virtual int ReqQryQuoteOrder(CStockFtdcQryQuoteOrderField *pQryQuote, int nRequestID) = 0;

		///��Ʊ�ɽ���ѯ����
		virtual int ReqQryStockTrade(CStockFtdcQryStockTradeField *pQryTrade, int nRequestID) = 0;

		///��Ȩ�ɽ���ѯ����
		virtual int ReqQryOptionsTrade(CStockFtdcQryOptionsTradeField *pQryTrade, int nRequestID) = 0;

		///�ֲֲ�ѯ����
		virtual int ReqQryPosition(CStockFtdcQryPositionField *pQryPosition, int nRequestID) = 0;

		///�����ѯ����
		virtual int ReqQryTopic(CStockFtdcDisseminationField *pDissemination, int nRequestID) = 0;

		//��Ʊ��ѯ����
		virtual int ReqQryStock(CStockFtdcQryStockField *pStock, int nRequestID) = 0;

		//��Ȩ��ѯ����
		virtual int ReqQryOptions(CStockFtdcQryOptionsField *pOptions, int nRequestID) = 0;

		///��ѯ������ϢӦ��
		virtual int ReqQryRate(CStockFtdcQryRateField *pRate, int nRequestID) = 0;

		///��Ա�ͻ���ѯ����
		virtual int ReqQryClient(int nRequestID) = 0;

		///��ѯ��֤������������
		virtual int ReqQryClientMargin(CStockFtdcQryClientMarginField *pRate, int nRequestID) = 0;

		//��Ȩ��ѯ����
		virtual int ReqQryExercise(CStockFtdcQryExerciseField *pExercise, int nRequestID) = 0;

		///�ͻ������������
		virtual int ReqMarginCombAction(CStockFtdcMarginCombActionField *pMarginCombAction, int nRequestID) = 0;

		///�Ͻ�����ϳֲֲ�ѯ����
		virtual int ReqQrySseCombPosition(CStockFtdcCombPositionField *pPosi, int nRequestID) = 0;

		///�����Ȩ����
		virtual int ReqCombExercise(CStockFtdcCombExerciseReqField *pExercise, int nRequestID) = 0;
	protected:
		~CNhStockTraderApi(){};
	};
}
#endif
