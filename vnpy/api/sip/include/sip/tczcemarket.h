#ifndef _T_CZCE_MARKET_
#define _T_CZCE_MARKET_
#include "tdef.h"

//*****************************************************************************************
//���Ϸ�������ID������ԭϵͳ���ݣ����·���ID���ÿ���г��ֿ�����

//-----------------------------------֣����-----------------------------------------------
#define ID_CZCE_BASEINFO 4001	 //�ڻ�����Ȩ������Ϣ
#define ID_CZCE_MARKETDATA 4002   //�ڻ�����Ȩ��������
#define ID_CZCE_FORQOUTE 4003	 //ѯ��֪ͨ
#define ID_CZCE_MARKETDATAL2 4004 //�ڻ�����ȨL2��������

#pragma pack(push, 1)
//1.1 ֣�����ڻ�����
typedef struct t_CZCE_FutursMarketData
{
	T_I32 nTime;			//ʱ��(HHMMSSmmmm)
	T_I32 nStatus;			//״̬
	T_I64 iPreOpenInterest; //��ֲ�
	T_U32 uPreClose;		//�����̼�
	T_U32 uPreSettlePrice;  //�����
	T_U32 uOpen;			//���̼�
	T_U32 uHigh;			//��߼�
	T_U32 uLow;				//��ͼ�
	T_U32 uMatch;			//���¼�
	T_I64 iVolume;			//�ɽ�����
	T_I64 iTurnover;		//�ɽ��ܽ��
	T_I64 iOpenInterest;	//�ֲ�����
	T_U32 uClose;			//������
	T_U32 uSettlePrice;		//�����
	T_U32 uHighLimited;		//��ͣ��
	T_U32 uLowLimited;		//��ͣ��
	T_I32 nPreDelta;		//����ʵ��
	T_I32 nCurrDelta;		//����ʵ��
	T_U32 uAskPrice[5];		//������
	T_U32 uAskVol[5];		//������
	T_U32 uBidPrice[5];		//�����
	T_U32 uBidVol[5];		//������
	char sTradingStatus;	//����״̬
	char sRevs[3];			//�����ֶ�
} T_CZCE_FutursMarketData, *PCZCE_FutursMarketData;
//1.2 ֣�����ڻ�������Ϣ
/////��Ʒ����-------------------------------------------------------
///�ڻ�
#define THOST_FTDC_PC_Futures '1'
///�ڻ���Ȩ
#define THOST_FTDC_PC_Options '2'
///���
#define THOST_FTDC_PC_Combination '3'
///����
#define THOST_FTDC_PC_Spot '4'
///��ת��
#define THOST_FTDC_PC_EFP '5'
///�ֻ���Ȩ
#define THOST_FTDC_PC_SpotOption '6'
//��Լ��������-----------------------------------------
///δ����
#define THOST_FTDC_IP_NotStart '0'
///����
#define THOST_FTDC_IP_Started '1'
///ͣ��
#define THOST_FTDC_IP_Pause '2'
///����
#define THOST_FTDC_IP_Expired '3'
//�ֲ�����-------------------------------------------------
///���ֲ�
#define THOST_FTDC_PT_Net '1'
///�ۺϳֲ�
#define THOST_FTDC_PT_Gross '2'

/////////////////////////////////////////////////////////////////////////
//////�ֲ���������
/////////////////////////////////////////////////////////////////////////
///ʹ����ʷ�ֲ�
#define THOST_FTDC_PDT_UseHistory '1'
///��ʹ����ʷ�ֲ�
#define THOST_FTDC_PDT_NoUseHistory '2'

/////////////////////////////////////////////////////////////////////////
///���߱�֤���㷨����
/////////////////////////////////////////////////////////////////////////
///��ʹ�ô��߱�֤���㷨
#define THOST_FTDC_MMSA_NO '0'
///ʹ�ô��߱�֤���㷨
#define THOST_FTDC_MMSA_YES '1'

/////////////////////////////////////////////////////////////////////////
///��Ȩ��������
/////////////////////////////////////////////////////////////////////////
///����
#define THOST_FTDC_CP_CallOptions '1'
///����
#define THOST_FTDC_CP_PutOptions '2'

/////////////////////////////////////////////////////////////////////////
///�����������
/////////////////////////////////////////////////////////////////////////
///�ڻ����
#define THOST_FTDC_COMBT_Future '0'
///��ֱ�۲�BUL
#define THOST_FTDC_COMBT_BUL '1'
///��ֱ�۲�BER
#define THOST_FTDC_COMBT_BER '2'
///��ʽ���
#define THOST_FTDC_COMBT_STD '3'
///���ʽ���
#define THOST_FTDC_COMBT_STG '4'
///�������
#define THOST_FTDC_COMBT_PRT '5'
///ʱ��۲����
#define THOST_FTDC_COMBT_CLD '6'

/////////////////////////////////////////////////////////////////////////
///��Լ����״̬����
/////////////////////////////////////////////////////////////////////////
///����ǰ
#define THOST_FTDC_IS_BeforeTrading '0'
///�ǽ���
#define THOST_FTDC_IS_NoTrading '1'
///��������
#define THOST_FTDC_IS_Continous '2'
///���Ͼ��۱���
#define THOST_FTDC_IS_AuctionOrdering '3'
///���Ͼ��ۼ۸�ƽ��
#define THOST_FTDC_IS_AuctionBalance '4'
///���Ͼ��۴��
#define THOST_FTDC_IS_AuctionMatch '5'
///����
#define THOST_FTDC_IS_Closed '6'

typedef struct t_CZCE_BaseInfo
{
	///��Լ����
	char sInstrumentID[31];
	///����������
	char sExchangeID[9];
	///��Լ����
	char sInstrumentName[21];
	///��Լ�ڽ������Ĵ���
	char sExchangeInstID[31];
	///��Ʒ����
	char sProductID[31];
	///��Ʒ����
	char cProductClass;
	///�������
	T_I32 nDeliveryYear;
	///������
	T_I32 nDeliveryMonth;
	///�м۵�����µ���
	T_I32 nMaxMarketOrderVolume;
	///�м۵���С�µ���
	T_I32 nMinMarketOrderVolume;
	///�޼۵�����µ���
	T_I32 nMaxLimitOrderVolume;
	///�޼۵���С�µ���
	T_I32 nMinLimitOrderVolume;
	///��Լ��������
	T_I32 nVolumeMultiple;
	///��С�䶯��λ,����10000��
	T_I64 i64PriceTick;
	///������
	T_I32 nCreateDate;
	///������
	T_I32 nOpenDate;
	///������
	T_I32 nExpireDate;
	///��ʼ������
	T_I32 nStartDelivDate;
	///����������
	T_I32 nEndDelivDate;
	///��Լ��������״̬
	char cInstLifePhase;
	///��ǰ�Ƿ���
	T_I32 nIsTrading;
	///�ֲ�����
	char cPositionType;
	///�ֲ���������
	char cPositionDateType;
	///��ͷ��֤����,������10000��
	T_I64 i64LongMarginRatio;
	///��ͷ��֤����,������10000��
	T_I64 i64ShortMarginRatio;
	///�Ƿ�ʹ�ô��߱�֤���㷨
	char cMaxMarginSideAlgorithm;
	///������Ʒ����
	char sUnderlyingInstrID[31];
	///ִ�м�,������10000��
	T_I64 i64StrikePrice;
	///��Ȩ����
	char cOptionsType;
	///��Լ������Ʒ����,������10000��
	T_I64 i64UnderlyingMultiple;
	///�������
	char cCombinationType;
} T_CZCE_BaseInfo, *PCZCE_BaseInfo;

///���������̵�ѯ������
typedef struct t_CZCE_ForQuote
{
	///������
	T_I32 nTradingDay;
	///��Լ����
	char sInstrumentID[31];
	///ѯ�۱��
	char sForQuoteSysID[21];
	///ѯ��ʱ��
	T_I32 nForQuoteTime;
	///ҵ������
	int nActionDay;
	///����������
	char sExchangeID[9];
} T_CZCE_ForQuote;
#pragma pack(pop)
#endif //_T_CZCE_MARKET_