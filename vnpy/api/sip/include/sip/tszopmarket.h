#ifndef _T_SZOP_MARKET_
#define _T_SZOP_MARKET_

#include "tdef.h"
//////////////////////////////////////////////////////////////////////////
//�����Ȩ����
//////////////////////////////////////////////////////////////////////////

#define  SZOP        11                 //�����Ȩ

#define ID_SZOP_BASEINFO      1     //��Ȩ������Ϣ
#define ID_SZOP_MARKETDATA    2     //��Ȩ��������
#pragma pack(push,1)
//////////////////////////////////////////////////////////////////////////
//�������֤ȯ���빲��  securities_YYYYMMDD.xml

typedef struct t_StockParams
{
	char    sIndustryClassification[4];// ��ҵ����    C4 
	T_I32   nPreviousYearProfitPerShare;//	����ÿ������ 		N10(4)
	T_I32   nCurrentYearProfitPerShare;//	����ÿ������  		N10(4)
	char    cOfferingFlag;//	�Ƿ���ҪԼ�� 	���� 	C1  Y=�� 		N=��
}T_STOCKPARAMS;

//���������ֶ� ���֤ȯ�����루14��15��16��17��18��19��20��23��24��25��26��
typedef struct t_FundParams
{
	T_I64   i64NAV;  //T-1 �ջ���ֵ N13(4) 
}T_FUNDPARAMS;

//ծȯ�����ֶ� BondParams ���֤ȯ�����루5��6��7��8��9��10��11��34��35��
typedef struct t_BondParams
{
	T_I64   i64CouponRate;//    Ʊ��������    N8(4) 
	T_I64   i64IssuePrice;//	���ַ��м�  IssuePrice  N13(4) 
	T_I64   i64Interest;//	ÿ��ԪӦ����Ϣ    N12(8) 
	T_I32	nInterestAccrualDate;//������Ϣ�ջ� 	�θ�Ϣ��Ϣ�� 		N8
	T_I32   nMaturityDate; //	������    N8 		
	char    cOfferingFlag;//����ת�ɻ����� 		C1  Y=�� 		N=��
}T_BONDPARAMS;

// Ȩ֤�����ֶ� WarrantParams ���֤ȯ�����루28��
typedef struct t_WarrantParams
{
	T_I64   i64ExercisePrice; // ��Ȩ�� 		N13(4) 
	T_I64   i64ExerciseRatio; // ��Ȩ����       N10(4) 
	T_I32	nExerciseBeginDate;//  ��Ȩ��ʼ��   N8 
	T_I32   nExerciseEndDate; //	��Ȩ��ֹ��  N8 
	char    cCallOrPut;//	�Ϲ����Ϲ� 	C1  C = Call 	P = Put
	char    cDeliveryType;//	���ʽ		C1   S = ֤ȯ���� C = �ֽ���� 
	T_I64   i64ClearingPrice;//	����۸� 	  N13(4) 
	char    cExerciseType;//	��Ȩ��ʽ   	C1  A = ��ʽ E = ŷʽ 	B = ��Ľ��ʽ
	T_I32	nLastTradeDay;//������� 		  N8 
}T_WARRANTPARAMS;

// ��Ѻʽ�ع����״��������ֶ� RepoParams 	���֤ȯ������(12)
typedef struct t_RepoParams
{
	T_I32   nExpirationDays;//��������  N4
}T_REPOPARAMS;


//////////////////////////////////////////////////////////////////////////
//��Ȩ�����ֶ�  ���֤ȯ�����루29��30)
typedef struct t_OptionParams
{
	char          cCallOrPut;  //�Ϲ����Ϲ� C1 C=Call P=Put
	T_U16         usListType;  //�������� N2  1=Ʒ���¹� 2=���ڼӹ� 3=�����ӹ�	4=�����ӹ�
	T_I32         nDeliveryDay; //��������  N8
	T_I32         nDeliveryMonth; //�����·�  N6  YYYYMM
	char          cDeliveryType; //���ʽ C1  S=֤ȯ���� C=�ֽ����
	T_I32         nExerciseBeginDate;//��Ȩ��ʼ���� N8
	T_I32         nExerciseEndDate;//��Ȩ�������� N8
	T_I64         i64ExercisePrice;//��Ȩ�� N13(4)
	char          cExerciseType;//��Ȩ��ʽ C1 A=��ʽ E=ŷʽ B=��Ľ��ʽ
	T_I32         nLastTradeDay;//������� N8
	T_U16         usAdjustTimes;//�������� N2
	T_I64         i64ContractUnit;//��Լ��λ N15(2)
	T_I64         i64PrevClearingPrice;//���ս���� N13(4)
	T_I64         i64ContractPosition;//��Լ�ֲ���  N18(2)
}T_OPTIONPARAMS,*POPTIONPARAMS;

//��ѡ�������ֶ� ���֤ȯ�����루33��
typedef struct t_PreferredStockParams
{
	char      cOfferingFlag;   //�Ƿ���ת�ɻ����� C1 Y=�� N=��
}T_PREFERREDSTOCKPARAMS;
typedef struct t_BaseInfo
{
	char    sSecurityID[8];         //֤ȯ���� SecurityID C8
	char    sSecurityIDSource[4];   //֤ȯ����Դ 4=ISIN 102=����֤ȯ������ C4
	char    sSymbol[40];            //֤ȯ��� C40
	char    sEnglishName[40];       //Ӣ�ļ�� ������Ȩ��д��Լ���� C40
	char    sISIN[12];              //ISIN���� C12

	char    sUnderlyingSecurityID[8];//����֤ȯ���� C8
	char    sUnderlyingSecurityIDSource[4];   //����֤ȯ����Դ 102=����֤ȯ������ C4
	T_U32   uListDate;              //�������� N8
	T_U16   usSecurityType;         //֤ȯ��� N4
    char    sCurrency[4];           //���Ҵ��� C4   CNY=����� HKD=�۱�
	T_I64   i64QtyUnit;             //������λ ί�������ֶα���Ϊ��֤ȯ������λ�������� N15(2) �˴����ʹ����Ŵ�10000��
	char    cDayTrading;            //�Ƿ�֧�ֵ��ջ�ת���� Y=֧�� N=��֧�� C1
	T_I64   i64PrevClosePx;         //�������̼� N13(4)
	T_U16   usSecurityStatus[20];    //֤ȯ״̬����:
	    //1-ͣ��
		//2-��Ȩ
		//3-��Ϣ
		//4-ST
		//5-*ST
		//6-��������
		//7-��˾������
		//8-�ָ���������
		//9-����ͶƱ
		//10-����������
		//12-�����ɷ�����
		//13-��Լ����
		//14-��ͣ���к�Э��ת��
	T_I64   i64OutstandingShare;    //�ܷ�����  N18(2)
	T_I64   i64PublicFloatShareQuantity; //��ͨ���� N18(2)
	T_I64   i64ParValue;//��ֵ N13(4)
	char    cGageFlag;//�Ƿ����Ϊ������ȯ�ɳ�ֱ�֤��֤ȯ C1  Y=�� N=��
	T_I32   nGageRatio;//�ɳ�ֱ�֤�������� N5(2)
	char    cCrdBuyUnderlying;//�Ƿ�Ϊ���ʱ�� C1 Y=�� N=��
	char    cCrdSellUnderlying;//�Ƿ�Ϊ��ȯ���C1 Y=�� N=��
	T_I32   nPriceCheckMode;  //��ۼ�鷽ʽ N2 0=����� 	1=����������ɽ��� 	2=���������ռ� 	3=��������߽��� 4=��������ͽ���
	char    cPledgeFlag;//�Ƿ����Ѻ��� C1 Y=�� N=��
	T_I64   i64ContractMultiplier;//�Իع���׼ȯ������ N6(5)
	char    sRegularShare[8];//��Ӧ�ع���׼ȯ C8
	char    cQualificationFlag;//�Ƿ���Ҫ�Ը�֤ȯ��Ͷ�����ʵ��Թ���		Y=�� 		N=��
	union T_EXTENDFIELD //����֤ȯ������ usSecurityType ȷ����ṹ �μ����±�3-2���ֵ䶨��
	{
		T_STOCKPARAMS stockParams;    //��Ʊ�����ֶ� StockParams ���֤ȯ�������Ӧ��1��2��3��4��
		T_FUNDPARAMS  fundParams;     //���������ֶ� ���֤ȯ�����루14��15��16��17��18��19��20��23��24��25��26��
		T_BONDPARAMS  bondParams;     //ծȯ�����ֶ� BondParams ���֤ȯ�����루5��6��7��8��9��10��11��34��35��
		T_WARRANTPARAMS warrantParams;// Ȩ֤�����ֶ� WarrantParams ���֤ȯ�����루28��
		T_REPOPARAMS repoParams;      // ��Ѻʽ�ع����״��������ֶ� RepoParams 	���֤ȯ������(12)
		T_OPTIONPARAMS optionParmas;  //��Ȩ�����ֶ�  ���֤ȯ�����루29��30)
		T_PREFERREDSTOCKPARAMS preferedStockParams; //��ѡ�������ֶ� ���֤ȯ�����루33��
	}tExtendParmas;
	  
}T_BASEINFO,*PBASEINFO;
 /* �� 3-2 ֤ȯ�����
		�������  ������
		���� A ��  1
		��С���Ʊ  2
		��ҵ���Ʊ  3
		���� B ��  4
		��ծ �����ط�ծ�� 5
		��ҵծ  6
		��˾ծ  7
		��תծ  8
		˽ļծ  9
		�ɽ���˽ļծ  10
		֤ȯ��˾�μ�ծ  11
		��Ѻʽ�ع�  12
		�ʲ�֧��֤ȯ  13
		���г���Ʊ ETF  14
		���г���Ʊ ETF  15
		�羳 ETF  16
		���г�ʵ��ծȯETF	17
		�ֽ�ծȯ ETF  18
		�ƽ� ETF  19
		���� ETF  20
		�ܸ� ETF  21��Ԥ����
		��Ʒ�ڻ� ETF  22��Ԥ����
		��׼ LOF  23
		�ּ��ӻ���  24
		���ʽ����  25
		���������  26
		Ȩ֤  28
		������Ȩ  29
		ETF ��Ȩ  30
		���ȹ�  33
		֤ȯ��˾����ծ  34
		�ɽ�����˾ծ  35*/



//�ֻ� ���о��۽���ҵ��ο���Ϣ�� cashauctionpramas) cashauctionparams_YYYYMMDD.xml
typedef struct t_CashAuctionParams
{
	char    sSecurityID[8];         //֤ȯ���� C8
	char    sSecurityIDSource[4];      //102 = ����֤ȯ������ C4
	T_I64   i64BuyQtyUpperLimit;    //���������� N15(2)  ��ί������������
	T_I64   i64SellQtyUpperLimit;   //	����������	N15(2)  ��ί������������
	T_I64   i64BuyQtyUnit;//	��������λ 		N15(2)  ÿ����ί�е�ί��������������������λ��������
	T_I64   i64SellQtyUnit; //	��������λ	N15(2)  ÿ����ί�е�ί��������������������λ��������
	T_I64   i64PriceTick;  //	�۸�λ 	N13(4)
	struct  T_PriceLimitSetting //�����޼۲���
	{
		char  cType;// �������� Type C1  O=���̼��Ͼ��� T=�������� 	C=���̼��Ͼ���
		char  cHasPriceLimit;//�����ǵ� ���� C1 Y=��	N=��
		char  cReferPriceType;//  ��׼������ C1 1=���ռ�
		char  cLimitType;  //	�ǵ��������� C1  1=���ȣ��ٷֱȣ� 		2=�۸񣨾���ֵ��
		T_I64 i64LimitUpRate;//    ���Ƿ���	N10(3)
		T_I64 i64LimitDownRate; // �µ����� N10(3)
		T_I64 i64LimitUpAbsolute;//  �����޼� 			N10(4)
		T_I64 i64LimitDownAbsolute;//	  �µ��޼�		N10(4)
		char  cHasAuctionLimit;//  �Ƿ�����Ч���۷�Χ���� 	C1 	Y=�� 	N=��
		char  cAuctionLimitType;// ��Ч��Χ��������		C1  1=���ȣ��ٷֱȣ�2=�۸񣨾���ֵ��
		T_I64 i64AuctionUpDownRate;//��Ч��Χ�ǵ�����	N10(3)
		T_I64 i64AuctionUpDownAbsolute;//	��Ч��Χ�ǵ��۸� 	N10(4)
	}tPriceLimitElement[5];
	char  cMarketMakerFlag;//�����̱�־ C1  ��ʶ�Ƿ��������� Y=��	N=��
}T_CASHAUCTIONPARAMS;


//����Ʒ�ο���Ϣ��Ŀǰ��������Ȩ  derivativeauctionparams_YYYYMMDD.xml

typedef struct t_DerivativeParams
{
	char    sSecurityID[8];         //֤ȯ���� C8
	char    sSecurityIDSource;      //102 = ����֤ȯ������ C4
	T_I64   i64BuyQtyUpperLimit;    //�޼���ί���������� N15(2)
	T_I64   i64SellQtyUpperLimit;   //�޼���ί���������� N15(2)
	T_I64   i64MarketOrderBuyQtyUpperLimit;//  �м����������� N15(2)  �м���ί������������
	T_I64   i64MarketOrderSellQtyUpperLimit;//	�м����������� N15(2)  �м���ί������������
	T_I64   i64QuoteOrderBuyQtyUpperLimit;//	�������������� N15(2)  ������ί������������
	T_I64   i64QuoteOrderSellQtyUpperLimit; //	�������������� 	N15(2)  ������ί������������
	T_I64   i64BuyQtyUnit;          //��������λ N15(2)
	T_I64   i64SellQtyUnit;        //��������λ N15(2)
	T_I64   i64PriceTick;          //�۸�λ N13(4)
	T_I64   i64PriceUpperLimit;     //��ͣ�� N13(4)
	T_I64   i64PriceLowerLimit;     //��ͣ�� N13(4)
	T_I64   i64LastSellMargin;     //������ÿ�ű�֤�� N18(4)
	T_I64   i64SellMargin;         //������ÿ�ű�֤�� N18(4)
	T_I32   nMarginRatioParam1;   //��֤������������һ N4(2)
	T_I32   nMarginRatioParam2;   //��֤������������һ N4(2)
	char    cMarketMakerFlag;     //�����̱�־  C1 Y=�� N=��
}T_DERIVATIVEPARAMS,*PDERIVATIVEPARAMS;

typedef struct t_SZ_BaseInfo 
{
	T_BASEINFO          tBase;      //������Ϣ
	T_CASHAUCTIONPARAMS tCashParams;      //�ֻ� ���о��۽���ҵ��ο���Ϣ
}T_SZ_BASEINFO,*PSZ_BASEINFO;

typedef struct t_SZOP_BaseInfo
{
	T_BASEINFO          tBase;      //������Ϣ
	T_DERIVATIVEPARAMS  tDeParmas;  //����Ʒ��Ϣ

}T_SZOP_BASEINFO,*PSZOP_BASEINFO;  //ID_SZOP_BASEINFO

//ָ�� ��Ϣ indexinfo_YYYYMMDD.xml  
typedef struct t_IndexInfo
{
	char    sSecurityID[8];         //ָ������ C8
	char    sSecurityIDSource[4];      //102 = ����֤ȯ������ C4          
	char    sSymbol[40];            //ָ����� C40
	char    sEnglishName[40];       //Ӣ�ļ�� 
	char    sCurrency[4];           //�������  Currency C4  ���� CNY = �����	HKD = �۱�
	T_I64   i64PrevCloseIdx;       //����ָ����λ  PrevCloseIdx  N18(5)
			
}T_INDEXINFO;

typedef struct t_SZOP_MarketData
{
	T_I32       nTime; //��������ʱ�� HHMMSSmmm��ʽ
	T_U16       usChannelNo; //Ƶ������
	char        sMDStreamID[3] ;//�������
	char        sSecrityID[8];//֤ȯ����
	char        sSecurityIDSource[4];//֤ȯ����Դ 101=����֤ȯ������
	char        sTradingPhaseCode[8];//��Ʒ�����Ľ��׽׶δ��� ��0λ��S=����������ǰ�� O=���̼��Ͼ��� T=�������� B=���� C=���̼��Ͼ��� E=�ѱ��� H=��ʱͣ�� A=�̺��� ��1λ��0=����״̬ 1=ȫ��ͣ��
	T_I64       i64PrevClosePx;//���ռ�
	T_I64       i64NumTrades; //�ɽ�����
	T_I64       i64TotalVolumeTrade;//�ɽ�����
	T_I64       i64TotalValueTrade;//�ɽ��ܽ��

	T_I64       i64LastPrice;//�����
	T_I64       i64OpenPrice;//���̼�
	T_I64       i64HighPrice;//��߼�
	T_I64       i64LowPrice;//��ͼ�
	T_I64       i64BuyAvgPrice;//x3=������ܣ���������Ȩƽ���ۣ�
	T_I64       i64BuyVolumeTrade;//x3=������ܣ���������Ȩƽ���ۣ�
	T_I64       i64SellAvgPrice;//x4=�������ܣ���������Ȩƽ���ۣ�
	T_I64       i64SellVolumeTrade;//x4=�������ܣ���������Ȩƽ���ۣ�
	T_I64       i64OfferPrice[10];//��ί�м۸�
	T_I64       i64OfferQty[10]; //��ί����
	T_I64       i64BidPrice[10];//��ί�м۸�
	T_I64       i64BidQty[10];//��ί����
	T_I64       i64PriceUpperLimit;        //��ͣ�� 999999999.9999 ��ʾ����ͣ�۸�����
	T_I64       i64PriceLowerLimit;        //��ͣ�� ���ڼ۸����Ϊ������ҵ��-999999999.9999 ��ʾ�޵�ͣ�۸����ƣ����ڼ۸񲻿���Ϊ������ҵ������д�۸�λ����ʾ�޵�ͣ�۸����ƣ�������ڹ�Ʊ�ֻ����о���ҵ����д 0.01
	T_I64       i64ContractPosition; //��Լ�ֲ���


	//������Ŀ��� 0=���� 1=���� 2=����� 4=���̼� 7=��߼� 8=��ͼ�
	//x1= ����һ x2=������ x3=������ܣ���������Ȩƽ���ۣ�x4=�������ܣ���������Ȩƽ���ۣ�
	//x5=��Ʊ��ӯ��һ x6=��Ʊ��ӯ�ʶ� x7=����T-1�վ�ֵ x8=����ʵʱ�ο���ֵ(����ETF��IOPV)
	//x9=Ȩ֤����� xe=��ͣ�� xf=��ͣ�� xg=��Լ�ֲ���
}T_SZOP_MARKETDATA,*PSZOP_MARKETDATA;

#pragma pack(pop)

#endif// _T_SZOP_MARKET_
