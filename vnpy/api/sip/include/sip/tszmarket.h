#ifndef _T_SZ_MARKET_
#define _T_SZ_MARKET_
#include "tdef.h"
//*****************************************************************************************
//���Ϸ�������ID������ԭϵͳ���ݣ����·���ID���ÿ���г��ֿ�����

//-----------------------------------�����г�--------------------------------------
#define ID_SZ_INDEXDATA 2000	   //ָ��(Stock_IndexData)
#define ID_SZ_TRANSACTION 2001	 //�ɽ�(Stock_TransactionEx)
#define ID_SZ_ORDERQUEUE 2002	  //ί�ж���(Stock_OrderQueue_Head+Stock_OrderQueue)
#define ID_SZ_STEPORDER 2003	   //���ί��(Stock_StepOrder)
#define ID_SZ_MARKETDATA 2004	  //��������(Stock_MarketData)
#define ID_SZ_MARKETDATA_L1 2005   //����L1���� ����(Stock_MarketData_L1)
#define ID_SZ_MATCHMARKETDATA 2006 //������飬������ʳɽ������ί�м��������
#define ID_SZ_KLINEDATA 2007	   //������ɷ���K������(T_SZ_Kline)
#define ID_SZ_BASEINFO 2008		   //���֤ȯ������Ϣ(��tszopmarket.h)

#pragma pack(push, 1)
// 1.1 ��Ʊ����
typedef struct t_SZ_StockMarketDataL2 {
	T_I32 nTime;				//ʱ��(HHMMSSmmmm)
	T_I32 nStatus;				//״̬
	T_U32 uPreClose;			//ǰ���̼�
	T_U32 uOpen;				//���̼�
	T_U32 uHigh;				//��߼�
	T_U32 uLow;					//��ͼ�
	T_U32 uMatch;				//���¼�
	T_U32 uAskPrice[10];		//������
	T_U32 uAskVol[10];			//������
	T_U32 uBidPrice[10];		//�����
	T_U32 uBidVol[10];			//������
	T_U32 uNumTrades;			//�ɽ�����
	T_I64 iVolume;				//�ɽ�����
	T_I64 iTurnover;			//�ɽ��ܽ��
	T_I64 iTotalBidVol;			//ί����������
	T_I64 iTotalAskVol;			//ί����������
	T_U32 uWeightedAvgBidPrice; //��Ȩƽ��ί��۸�
	T_U32 uWeightedAvgAskPrice; //��Ȩƽ��ί���۸�
	T_I32 nIOPV;				//IOPV��ֵ��ֵ
	T_I32 nYieldToMaturity;		//����������
	T_U32 uHighLimited;			//��ͣ�� 999999999 ��ʾ����ͣ�۸�����
	T_U32 uLowLimited;			//��ͣ�� -999999999 ,���޷��ű�ʾ��3294967297 ��ʾ�޵�ͣ�۸����ƣ����ڼ۸񲻿���Ϊ������ҵ������д�۸�λ����ʾ�޵�ͣ�۸����ƣ�������ڹ�Ʊ�ֻ����о���ҵ����д 10
	char sPrefix[4];			//֤ȯ��Ϣǰ׺
	T_I32 nSyl1;				//��ӯ��1 2 λС�� ��Ʊ���۸�/����ÿ������ ծȯ��ÿ��ԪӦ����Ϣ
	T_I32 nSyl2;				//��ӯ��2 2 λС�� ��Ʊ���۸�/����ÿ������ ծȯ������������ ����ÿ�ٷݵ�IOPV ��ֵ Ȩ֤�������
	T_I32 nSD2;					//����2���Ա���һ�ʣ�
	char sTradingPhraseCode[8]; //�Ͻ���������ֶκ��岻ͬ���μ�����ע�⣺
	//�����
	//   ��Ʒ�����Ľ��׽׶δ���
	//�� 0 λ��
	//S=����������ǰ��
	//O=���̼��Ͼ���
	//T=��������
	//B=����
	//C=���̼��Ͼ���
	//E=�ѱ���
	//H=��ʱͣ��
	//A=�̺���
	//V=�������ж�
	//�� 1 λ��
	//0=����״̬
	//1=ȫ��ͣ��
	T_I32 nPreIOPV; //����T-1������ʱ��IOPV �����Ϊ����ʱ��Ч
} T_SZ_StockMarketDataL2, *PSZ_StockMarketDataL2;

//1.2 L1���飬�Ͻ�����������ô˽ṹ
typedef struct t_SZ_StockMarketDataL1 {
	T_I32 nTime;				//ʱ��(HHMMSSmmmm)
	T_I32 nStatus;				//״̬
	T_U32 uPreClose;			//ǰ���̼�
	T_U32 uOpen;				//���̼�
	T_U32 uHigh;				//��߼�
	T_U32 uLow;					//��ͼ�
	T_U32 uMatch;				//���¼�
	T_U32 uAskPrice[5];			//������
	T_U32 uAskVol[5];			//������
	T_U32 uBidPrice[5];			//�����
	T_U32 uBidVol[5];			//������
	T_U32 uNumTrades;			//�ɽ�����
	T_I64 iVolume;				//�ɽ�����
	T_I64 iTurnover;			//�ɽ��ܽ��
	T_U32 uHighLimited;			//��ͣ��
	T_U32 uLowLimited;			//��ͣ��
	char sTradingPhraseCode[8]; //�Ͻ���������ֶκ��岻ͬ���μ�����ע�⣺
	//�����
	//   ��Ʒ�����Ľ��׽׶δ���
	//�� 0 λ��
	//S=����������ǰ��
	//O=���̼��Ͼ���
	//T=��������
	//B=����
	//C=���̼��Ͼ���
	//E=�ѱ���
	//H=��ʱͣ��
	//A=�̺���
	//V=�������ж�
	//�� 1 λ��
	//0=����״̬
	//1=ȫ��ͣ��
	T_I32 nPreIOPV; //����T-1������ʱ��IOPV �����Ϊ����ʱ��Ч
	T_I32 nIOPV;	//����IOPV  �����Ϊ����ʱ��Ч
} T_SZ_StockMarketDataL1, *PSZ_StockMarketDataL1;

//���V5����ʳɽ�ί������  ��ӦBinaryЭ���ĵ�4.4.5

typedef struct t_SZ_StepTrade {
	T_U16 usChannelNo;		   //Ƶ������
	T_I64 i64ApplSeqNum;	   //��Ϣ��¼�� ��1��ʼ����
	char sMDStreamID[3];	   //�������
	T_I64 i64BidApplSeqNum;	//��ί����������1��ʼ������0��ʾ�޶�Ӧί��
	T_I64 i64OfferApplSeqNum;  //����ί������,��1��ʼ����,0��ʾ�޶�Ӧί��
	char sSecurityID[8];	   //֤ȯ����
	char sSecurityIDSource[4]; //֤ȯ����Դ 101=����֤ȯ������
	T_I64 i64LastPx;		   //ί�м۸�
	T_I64 i64LastQty;		   //ί������
	char cExecType;			   //�ɽ���� 4=���� F=�ɽ�
	T_I64 i64TransactTime;	 //ί��ʱ��
	char sExtendFields[];	  //��ҵ����չ�ֶ� ������MDStreamID�ֶξ�������MDStreamID=011 ��ʾ�ֻ�����Ʊ������ծȯ�ȣ����о��۽���������飬�ݱ����չ�ֶ�Ϊ��
} T_SZ_STEPTRADE, *PSZ_STEPTRADE;
//MDStreamID=011 �ֻ�����Ʊ������ծȯ�ȣ����о��۽����������
//MDStreamID=021 ��Ѻʽ�ع������������
typedef struct t_SZ_300191ExtendFields {

} T_SZ_300191EXTENDFIELDS, *PSZ_300191EXTENDFIELDS;
//MDStreamID=051 Э�齻�������������
//MDStreamID=052 Э�齻����ʶ�������
typedef struct t_SZ_300591ExtendFields {

} T_SZ_300591EXTENDFIELDS, *PSZ_300591EXTENDFIELDS;

//MDStreamID=071 ת��֤ͨȯ�����������
typedef struct t_SZ_300791ExtendFields {

} T_SZ_300791EXTENDFIELDS, *PSZ_300791EXTENDFIELDS;

//���V5�����ί������

//���ί������ MsgType=30XX92 ��ӦBinaryЭ���ĵ�4.4.4
typedef struct t_SZ_StepOrder {
	T_U16 usChannelNo;		   //Ƶ������
	T_I64 i64ApplSeqNum;	   //��Ϣ��¼�� ��1��ʼ����
	char sMDStreamID[3];	   //�������
	char sSecurityID[8];	   //֤ȯ����
	char sSecurityIDSource[4]; //֤ȯ����Դ 101=����֤ȯ������
	T_I64 i64Price;			   //ί�м۸�
	T_I64 i64OrderQty;		   //ί������
	char cSide;				   //�������� 1=�� 2=�� G=���� F=���
	T_I64 i64TransactTime;	 //ί��ʱ��
	char sExtendFields[];	  //��ҵ����չ�ֶ� ������MDStreamID�ֶξ�������MDStreamID=011 ��ʾ�ֻ�����Ʊ������ծȯ�ȣ����о��۽����������
} T_SZ_STEPORDER, *PSZ_STEPORDER;

/***
**  4.4.4.1 ���о���ҵ�����ί��������չ�ֶΣ� 300192��      �� 4-14-1 ���о���ҵ�����ί��������չ�ֶ�˵��
***/
//MDStreamID=011 �ֻ�����Ʊ������ծȯ�ȣ����о��۽����������
//MDStreamID=021 ��Ѻʽ�ع������������
typedef struct t_SZ_300192ExtendFields {
	char cOrdType; //������� 1=�м� 2=�޼� U=��������

} T_SZ_300192EXTENDFIELDS, *PSZ_300192EXTENDFIELDS;

/***
   **  4.4.4.2 Э�齻��ҵ�����ί��������չ�ֶΣ� 300592��  �� 4-14-2 Э�齻��ҵ�����ί��������չ�ֶζ���
   ***/
//MDStreamID=051 Э�齻�������������
//MDStreamID=052 Э�齻����ʶ�������
typedef struct t_SZ_300592ExtendFields {
	char sConfirmID[8];	//��������Լ����  char[8]    ConfirmID Ϊ�ձ�ʾ����������  ����Ϊ��������
	char sContactor[12];   // ��ϵ��               char[12]
	char sContactInfo[30]; // ��ϵ��ʽ            char[30]

} T_SZ_300592EXTENDFIELDS, *PSZ_300592EXTENDFIELDS;

/***
	**  4.4.4.3 ת��֤ͨȯ����ҵ�����ί��������չ�ֶΣ� 300792��  �� 4-14-3 ת��֤ͨȯ����ҵ�����ί��������չ�ֶζ���
   ***/
//MDStreamID=071 ת��֤ͨȯ�����������
typedef struct t_SZ_300792ExtendFields {
	T_U16 usExpirationDays; // ���ޣ�           uInt16       ��λΪ����
	T_U8 ucExpirationType;  // ��������         uInt8        1=�̶�����
} T_SZ_300792EXTENDFIELDS, *PSZ_300792EXTENDFIELDS;

//1.5 ��������(Queue)
#ifndef _ORDER_QUEUE_
#define _ORDER_QUEUE_

typedef struct t_OrderQueueHead {
	T_I32 nItem; //���ݸ���
} T_OrderQueueHead, *POrderQueueHead;
typedef struct t_OrderQueueItem {
	T_I32 nTime;		  //����ʱ��(HHMMSSmmmm)
	T_I32 nSide;		  //��������('B':Bid 'S':Ask)
	T_I32 nPrice;		  //�ɽ��۸�
	T_I32 nOrders;		  //��������
	T_I32 nABItems;		  //��ϸ����
	T_I32 nABVolume[200]; //������ϸ
} T_OrderQueueItem, *POrderQueueItem;

#endif //#define _ORDER_QUEUE_
typedef struct t_SZ_StockOrderQueue {
	T_OrderQueueHead tHead;
	T_OrderQueueItem tItem[0];

} T_SZ_StockOrderQueue, *PSZ_StockOrderQueue;

//1.6 ָ��
typedef struct t_SZ_StockIndex {
	T_I32 nTime;		  //ʱ��(HHMMSSmmmm)
	T_I32 nOpenIndex;	 //����ָ��
	T_I32 nHighIndex;	 //���ָ��
	T_I32 nLowIndex;	  //���ָ��
	T_I32 nLastIndex;	 //����ָ��
	T_I64 iTotalVolume;   //���������Ӧָ���Ľ�������
	T_I64 iTurnover;	  //���������Ӧָ���ĳɽ����
	T_I32 nPreCloseIndex; //ǰ��ָ��
} T_SZ_StockIndex, *PSZ_StockIndex;

//1.7 ����K��
typedef struct t_SZ_Kline {
	T_U32 uDay;				// ����				YYYYMMDD
	T_I32 nTime;			// ʱ��(����ʱ��)	HHMM
	T_I32 nPreClose;		// ǰ���̼�         ��λ��1/100��
	T_I32 nValOpen;			// ���̼�			��λ��1/100��,����1��ʾ0.0001Ԫ
	T_I32 nValHigh;			// ��߼�			��λ��1/100��
	T_I32 nValLow;			// ��ͼ�			��λ��1/100��
	T_I32 nValClose;		// ���̼�			��λ��1/100��
	T_I64 i64Volume;		// �����ڳɽ���		��λ����֤ȯ����С���׵�λ�������ƱΪ���ɡ�
	T_I64 i64ValTotal;		// �����ڳɽ���		��λ��Ԫ
	T_I64 i64TotalVol;		// �ۼƳɽ���		��λ����֤ȯ����С���׵�λ�������ƱΪ���ɡ�
	T_I64 i64TotalTurnOver; // �ۼƳɽ����		��λ��Ԫ
	T_I32 nTurover;			// ����(�ٷ���)		��λ��1/10000������1��ʾ0.01%
	T_I32 nValIncrease;		// �ǵ�ֵ			��λ��1/100��
} T_SZ_Kline, *PSZ_Kline;   // sizeof() = 48

//1.8 �������
typedef struct t_SZ_StockMarketDataLF {
	T_I32 nTime;				//ʱ��(HHMMSSmmmm)
	T_U32 uPreClose;			//ǰ���̼�
	T_U32 uOpen;				//���̼�
	T_U32 uHigh;				//��߼�
	T_U32 uLow;					//��ͼ�
	T_U32 uMatch;				//���¼�
	T_U32 uAskPrice[10];		//������
	T_U32 uAskVol[10];			//������
	T_U32 uBidPrice[10];		//�����
	T_U32 uBidVol[10];			//������
	T_U32 uNumTrades;			//�ɽ�����
	T_I64 iVolume;				//�ɽ�����
	T_I64 iTurnover;			//�ɽ��ܽ��
} T_SZ_StockMarketDataLF, *PSZ_StockMarketDataLF;

/**
* @brief �����������
*
**/
typedef struct t_TickByTickData {
	char cType;					//ί��:'0' ,�ɽ�:'1'
	union {
		T_SZ_STEPORDER		entrust; //���ί��
		T_SZ_STEPTRADE		 trade;	//��ʳɽ�
	} UttData;

} T_SZ_TickByTickData, *PSZ_TickByTickData;
#pragma pack(pop)
#endif //_T_SZ_MARKET_