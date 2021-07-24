#ifndef _T_SH_MARKET_
#define _T_SH_MARKET_
#include "tdef.h"

//*****************************************************************************************
//���Ϸ�������ID������ԭϵͳ���ݣ����·���ID���ÿ���г��ֿ�����
//-----------------------------------�Ϻ��г�--------------------------------------
#define ID_SH_INDEXDATA 1000	 //ָ��(Stock_IndexData)
#define ID_SH_TRANSACTION 1001   //�ɽ�(Stock_Transaction)
#define ID_SH_ORDERQUEUE 1002	//ί�ж���(Stock_OrderQueue_Head+Stock_OrderQueue)
#define ID_SH_MARKETDATA 1004	//��������(Stock_MarketData)
#define ID_SH_MARKETDATA_L1 1005 //����L1���� �Ϻ�(Stock_MarketData_L1)
#define ID_SH_KLINEDATA 1007	 //�Ͻ������ɷ���K������(T_SH_Kline)
#define ID_SH_BASEINFO 1008		 //�Ͻ�����Ʒ������Ϣ
#define ID_SH_ATPTRADE 1010		 //�Ͻ����̺���ʳɽ�
#define ID_SH_ETFEXTENDS              1011 //�Ͻ���ETF��չ������Ϣ
#pragma pack(push, 1)
// 1.1 ��Ʊ����
typedef struct t_SH_StockMarketDataL2
{
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
	T_U32 uHighLimited;			//��ͣ��
	T_U32 uLowLimited;			//��ͣ��
	char sPrefix[4];			//֤ȯ��Ϣǰ׺
	T_I32 nSyl1;				//��ӯ��1 2 λС�� ��Ʊ���۸�/����ÿ������ ծȯ��ÿ��ԪӦ����Ϣ
	T_I32 nSyl2;				//��ӯ��2 2 λС�� ��Ʊ���۸�/����ÿ������ ծȯ������������ ����ÿ�ٷݵ�IOPV ��ֵ Ȩ֤�������
	T_I32 nSD2;					//����2���Ա���һ�ʣ�
	char sTradingPhraseCode[8]; //�Ͻ���������ֶκ��岻ͬ���μ�����ע�⣺
								//�Ͻ��������ֶ�Ϊ8λ�ַ���������ÿλ��ʾ�ض��ĺ��壬�޶�������ո�
								/*  ��1λ����S����ʾ����������ǰ��ʱ�Σ���C����ʾ���Ͼ���ʱ�Σ���T����ʾ��������ʱ�Σ���B����ʾ����ʱ�Σ���E����ʾ����ʱ�Σ���P����ʾ��Ʒͣ�ƣ���M����ʾ�ɻָ����׵��۶�ʱ�Σ����м��Ͼ��ۣ�����N����ʾ���ɻָ����׵��۶�ʱ�Σ���ͣ���������У�����U����ʾ���̼��Ͼ���ʱ�Σ�
		�̺�̶��۸��ף���I����ʾ����������ǰ��ʱ�Σ� ��A����ʾ���д��ʱ�Σ���H����ʾ��������ʱ�Σ���D����ʾ����ʱ�Σ���F����ʾͣ��
		��2λ�� ��0����ʾ�˲�Ʒ�����������ף���1����ʾ�˲�Ʒ���������ף���������ո�
		��3λ����0����ʾδ���У���1����ʾ�����С�
		��4λ����0����ʾ�˲�Ʒ�ڵ�ǰʱ�β����ܽ����¶����걨����1�� ��ʾ�˲�Ʒ�ڵ�ǰʱ�οɽ��ܽ����¶����걨����������ո�*/

	T_I32 nPreIOPV; //����T-1������ʱ��IOPV �����Ϊ����ʱ��Ч
} Stock_MarketData, T_SH_StockMarketDataL2, *PSH_StockMarketDataL2;

//1.2 �Ͻ���Level-1
typedef struct t_SH_StockMarketDataL1
{
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
								//�Ͻ��������ֶ�Ϊ8λ�ַ���������ÿλ��ʾ�ض��ĺ��壬�޶�������ո�
								/*  ��1λ����S����ʾ����������ǰ��ʱ�Σ���C����ʾ���Ͼ���ʱ�Σ���T����ʾ��������ʱ�Σ���B����ʾ����ʱ�Σ���E����ʾ����ʱ�Σ���P����ʾ��Ʒͣ�ƣ���M����ʾ�ɻָ����׵��۶�ʱ�Σ����м��Ͼ��ۣ�����N����ʾ���ɻָ����׵��۶�ʱ�Σ���ͣ���������У�����U����ʾ���̼��Ͼ���ʱ�Σ�
		�̺�̶��۸��ף���I����ʾ����������ǰ��ʱ�Σ� ��A����ʾ���д��ʱ�Σ���H����ʾ��������ʱ�Σ���D����ʾ����ʱ�Σ���F����ʾͣ��
		��2λ�� ��0����ʾ�˲�Ʒ�����������ף���1����ʾ�˲�Ʒ���������ף���������ո�
		��3λ����0����ʾδ���У���1����ʾ�����С�
		��4λ����0����ʾ�˲�Ʒ�ڵ�ǰʱ�β����ܽ����¶����걨����1�� ��ʾ�˲�Ʒ�ڵ�ǰʱ�οɽ��ܽ����¶����걨����������ո�*/
	T_I32 nPreIOPV;				//����T-1������ʱ��IOPV �����Ϊ����ʱ��Ч
	T_I32 nIOPV;				//����IOPV  �����Ϊ����ʱ��Ч

}StockMarketDataL1, T_SH_StockMarketDataL1, *PSH_StockMarketDataL1;

//1.3 ��ʳɽ�(Transaction)
typedef struct t_SH_StockStepTrade
{
	T_I32 nTradeIndex;   //�ɽ����
	T_I32 nTradeChannel; //�ɽ�ͨ��
	T_I32 nTradeTime;	//�ɽ�ʱ�� HHMMSSmmm
	T_I32 nTradePrice;   //�ɽ��۸� ����10000��
	T_I64 iTradeQty;	 //�ɽ����� ��Ʊ���� Ȩ֤���� ծȯ����
	T_I64 iTradeMoney;   //�ɽ����(Ԫ)
	T_I64 iTradeBuyNo;   //�򷽶�����
	T_I64 iTradeSellNo;  //����������
	char cTradeBSflag;   //�����̱�ʶ B -���̣�������  B-����,������ N δ֪
	char sRes[3];		 //�����ֶ�1

}T_SH_StockStepTrade, *PSH_StockStepTrade; //�Ͻ�����ʳɽ�����Ӧ������UA3201

//1.4 ��������(Queue)
#ifndef _ORDER_QUEUE_
#define _ORDER_QUEUE_
typedef struct t_OrderQueueHead
{
	T_I32 nItem; //���ݸ���
} Stock_OrderQueue_Head, T_OrderQueueHead, *POrderQueueHead;
typedef struct t_OrderQueueItem
{
	T_I32 nTime;		  //����ʱ��(HHMMSSmmmm)
	T_I32 nSide;		  //��������('B':Bid 'S':Ask)
	T_I32 nPrice;		  //�ɽ��۸�
	T_I32 nOrders;		  //��������
	T_I32 nABItems;		  //��ϸ����
	T_I32 nABVolume[200]; //������ϸ
} Stock_OrderQueue, T_OrderQueueItem, *POrderQueueItem;
#endif //_ORDER_QUEUE_

typedef struct t_SH_StockOrderQueue
{
	T_OrderQueueHead tHead;
	T_OrderQueueItem tItem[0];

}StockOrderQueue, T_SH_StockOrderQueue, *PSH_StockOrderQueue;

//1.5 ָ��
typedef struct t_SH_StockIndex
{
	T_I32 nTime;		  //ʱ��(HHMMSSmmmm)
	T_I32 nOpenIndex;	 //����ָ��
	T_I32 nHighIndex;	 //���ָ��
	T_I32 nLowIndex;	  //���ָ��
	T_I32 nLastIndex;	 //����ָ��
	T_I64 iTotalVolume;   //���������Ӧָ���Ľ�������
	T_I64 iTurnover;	  //���������Ӧָ���ĳɽ����
	T_I32 nPreCloseIndex; //ǰ��ָ��
} Stock_IndexData, T_SH_StockIndex, *PSH_StockIndex;

//1.6 ����K��
typedef struct t_SH_Kline
{
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
	T_I32 nTurover;			// ����1
	T_I32 nValIncrease;		// ����2
}T_Kline, T_SH_Kline, *PSH_Kline;   // sizeof() = 48

//1.7 ��Ʒ������Ϣ�ļ��ӿ�cpxxMMDD.txt
//��Ȩ�����ͳ�Ϣ�������100���⣬����N(X)���͵�����������10000�������磬��ֵi64FaceValue������10000�����ֵ
typedef struct t_CPXX
{
	char szStkCode[6];				 //1֤ȯ����	                C6
	char szISIN[12];				 //2ISIN����	                C12       ISIN���루Ԥ������
	T_U32 uUpdateTime;				 //3��¼����ʱ��	          C8        ��ʶ�ӿ��б���¼����ʱ��HH:MM:SS,�����HHMMSSmmm��ʽ������
	char szStkNameZN[8];			 //4����֤ȯ����	          C8        ����֤ȯ����
	char szStkNameEn[10];			 //5Ӣ��֤ȯ����	         C10       Ӣ��֤ȯ���ƣ�Ԥ����
	char szUnderlyingCode[6];		 //6����֤ȯ����	         C6         ����ƷΪȨ֤����תծ������Ʒʱ�����ֶ�Ϊ���Ĳ�Ʒ��֤ȯ���롣
	char szMktClass[4];				 //7�г�����	               C4          ��ASHR����ʾA���г�����BSHR����ʾB���г�����CSHR����ʾ���ʰ��г���ҵƽ̨�����ʲ�����ƻ���ծȯԤ����ȡ��ASHR��
	char szStkClass[6];				 //8֤ȯ���	               C6          ��ES����ʾ��Ʊ����EU����ʾ���𣻡�D����ʾծȯ�� ��RWS����ʾȨ֤����FF����ʾ�ڻ������ο�ISO10962���������ʲ�����ƻ���ծȯԤ����ȡ��D��
	char szStkSubClass[3];			 //9֤ȯ�����	         C3         �Զ�����ϸ֤ȯ���
	char szCurrency[3];				 //10��������	               C3         ���Ҵ���ȡֵ����Ԫ��USD������ң�CNY�����ο�ISO4217��
	T_I64 i64FaceValue;				 //11��ֵ	               N15(3)        ծȯ��ǰ��ֵ����λԪ��������Ʒȡ0.000
	T_I64 i64MatchQty;				 //12����֤ͨȯδ�������� 	N15 	Ԥ��
	char szLastDate[15];			 // 13	���������	  C15        ���ڹ�ծԤ���в�Ʒ��Ϊ��������ڣ���ʽΪYYYYMMDD	C15
	T_U32 uListingData;				 //14��������	         C8         ���Ͻ������ս������ڣ�YYYYMMDD
	T_U32 uProductSETId;			 //15��Ʒ��SET���     N3        ȡֵ��Χ��1��999�� ����������Ʒ��һ�ַ��鷽ʽ�������ڶ���������и��ؾ�����䡣��ֵ��һ���������ڲ���仯��	N3
	T_I64 i64BuyNumUnit;			 //16	��������λ	        N12        �򶩵����걨���������Ǹ��ֶε���������
	T_I64 i64SellNumUnit;			 //17��������λ	        N12        ���������걨���������Ǹ��ֶε���������
	T_I64 i64DecalaredLowestNum;	 //18�޼��걨��������      N12	    �޼��걨��������
	T_I64 i64DecalaredHightestNum;   //19�޼��걨��������       N12	    �޼��걨��������
	T_I64 i64PreClosePrice;			 //20ǰ���̼۸�	    N11(3)        ǰ���̼۸����г�Ȩ��Ϣ��Ϊ��Ȩ��Ϣ��ǰ���̼ۣ� ���ڻ����г�����ʵʱ���꣬ȡֵΪ0.010  �����ʲ�����ƻ��̶���д�������տ��̲ο��۸�	N11(3)
	T_I64 i64PriceLevel;			 //21�۸�λ	    N11(3)        �걨�۸����С�䶯��λ
	char cPriceLimitsType;			 //22�ǵ�����������    C1           ��N����ʾ���ǵ�����������  //��R����ʾ���ǵ����������� //  ��S����ʾ�ع��ǵ�����������// ��F����ʾ���ڲο��۸���ǵ�������// ��P����ʾIPO�������յ��ǵ�����������// ��U����ʾ���κμ۸��ǵ�����������
	T_I64 i64UpLimitsPrice;			 //23�Ƿ����޼۸�  N11(3)	    ����N�����ǵ������ƵĲ�Ʒ�����ֶε��ղ�����ģ�����ǰ���̼ۣ����������н��ײ�ƷΪ���мۣ����㡣
	T_I64 i64LowerLimitPrice;		 //24�������޼۸�  N11(3)	    ���㷽ʽ�ο��Ƿ����޼۸�
	T_I64 i64DividendRatio;			 //25��Ȩ����         N11(6)	    ÿ���͹ɱ���,���ڹ�ծԤ���в�Ʒ��Ϊ��֤���������λΪ%��
	T_I64 i64DividendAmount;		 //26��Ϣ���         N11(6)	    ÿ�ɷֺ���
	char cFinaSubjectFlag;			 //27���ʱ�ı�־        C1	     ��T����ʾ�����ʱ��֤ȯ//  ��F����ʾ�������ʱ��֤ȯ��
	char cMarginSubjectFlag;		 //28��ȯ��ı�־         C1        ��T����ʾ����ȯ���֤ȯ//��F����ʾ������ȯ���֤ȯ��
	char szProdStatusFlag[20];		 //29��Ʒ״̬��־      C20       ���ֶ�Ϊ20λ�ַ�����ÿλ��ʾ�����Ӧ��ҵ���޶�������ո�
	T_I64 i64MPDecalaredLowestNum;   //30�걨��������      N12	    �м��걨��������
	T_I64 i64MPDecalaredHightestNum; //31�걨��������       N12	    �м��걨��������
	char szStkNameZNLong[32];		 //32Ϊ������֤ȯ���ƣ��̣�����λԤ���ֶΣ�ĿǰΪ�ա�
	char szNote[50];				 //33��ע                  C50	     �����ֶΣ�������չ��
									 //����A�ɹ�Ʊ�ͻ���ͨCDR���ؽ��׵Ľ��ײ�Ʒ��
									 //��1λ-15λ����дΪ�ò�Ʒ�г���ͨ��������λΪ�ݣ��Ҷ��룬�󲹿ո�
									 //���ڹ�ծԤ���в�Ʒ����ע�в��������ֶΣ�ÿ���ֶθ��ݸ�ʽ���壬���ձ��ĵ�txt�ļ����뷽ʽԼ�����ֶζ������ֶμ���&�ָ����ֶμ���ʽ��������Ϊ
									 // 1���б귽ʽC1����1����ʾ��ծԤ���������б꣬��2����ʾ��ծԤ���м۸��бꡣ
									 // 2����׼�۸�N11(3)�����۸��б�ʱΪ��׼�۸񣬵������б�ʱΪ��׼�����ʡ�
									 // 3���ο�����N6(2)����λΪ�ꡣ
									 // 4�����ڷ�����N9����λΪ�֡�
} T_CPXX, T_SH_BaseInfo, *PCPXX, *PSH_BaseInfo;

//1.9 ETF��չ������Ϣ
typedef struct t_SH_ETFExtends
{
	T_I32		nTime;				     //ʱ��(HHMMSSmmm)
	T_I32       nIOPV;                   //ETF��ֵ��ֵ
	T_I32       nEtfBuyNum;              //ETF�깺����
	T_I64       i64EtfBuyAmount;         //ETF�깺����
	T_I64       i64EtfBuyMoney;           //ETF�깺���
	T_I32       nEtfSellNum;                //ETF��ر���
	T_I64       i64EtfSellAmount;           //ETF�������
	T_I64       i64EtfSellMoney;            //ETF��ؽ��
	T_I32       nWithDrawBuyNum;         //���볷������
	T_I64       i64WithDrawBuyAmount;    //���볷������
	T_I64       i64WithDrawBuyMoney;     //���볷�����
	T_I32       nWithDrawSellNum;        //������������
	T_I64       i64WithDrawSellAmount;   //������������
	T_I64       i64WithDrawSellMoney;    //�����������
}T_ETFEXTENDS,T_SH_ETFEXTENDS, *PSH_ETFEXTENDS;
;
#pragma pack(pop)
#endif //_T_SH_MARKET_