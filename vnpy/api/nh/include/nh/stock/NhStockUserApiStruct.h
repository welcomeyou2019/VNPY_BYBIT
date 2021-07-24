
#if !defined(NH_SZSESTRUCT_H)
#define NH_SZSESTRUCT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "NhStockUserApiDataType.h"

namespace nhtd
{

	///��Ӧ��Ϣ
	struct CStockFtdcRspInfoField
	{
		///�������
		TStockFtdcErrorIDType	ErrorID;
		///������Ϣ
		TStockFtdcErrorMsgType	ErrorMsg;
	};


	///��Ȩ��������
	struct CStockFtdcOptionsInsertReqField
	{
		TStockFtdcClOrdIDType 	ClOrdID;				//��Ա�ڲ��������,�������걨ҵ��Χ�ڣ�ͬһ�����׵�Ԫ�Ļ�Ա�ڲ���ű���Ψһ������ϵͳ���ظ�����ǰ̨�ύ��ͬһ�����׵�Ԫ��ͬ�Ļ�Ա�ڲ���Ŷ��������Դ˱���ظ���Ϊ�����ظ����ݡ�
		TStockFtdcSecurityIDType	SecurityID;		//��Լ����
		TStockFtdcOwnerTypeType	OwnerType;	//������������
		TStockFtdcPriceType Price;							//�걨�۸񣬶����м۶��������壬��λ��Ԫ����ȷ��0.0001Ԫ��
		TStockFtdcVolumeType OrderQty;				//�걨�������ţ�
		TStockFtdcSideType  Side;									//��������
		TStockFtdcPositionEffectType PositionEffect;	//����/ƽ��
		TStockFtdcOrdTypeType OrdType;						//��������
		TStockFtdcTimeInForceType TimeInForce; 		//������Чʱ������
		TStockFtdcCoveredOrUncoveredType CoveredOrUncovered;		//���ұ�ǩ
		TStockFtdcPartyIDType PartyID;							//Ͷ�����ʻ�
	};

	///��Ȩ����Ӧ��
	struct CStockFtdcOptionsInsertRspField
	{
		TStockFtdcOrderIDType OrderID;				//�������������
		TStockFtdcExecTypeType	ExecType;			//��ǰ����ִ������
		TStockFtdcOrdStatusType	OrdStatus;			//��ǰ�걨��״̬
		TStockFtdcSecurityIDType	SecurityID;		//��Լ����
		TStockFtdcClOrdIDType	ClOrdID;					//��Ա�ڲ��������
		TStockFtdcTimeType	TransactTimeOnly;	//��������ʱ��
		TStockFtdcPriceType	DiscretionPrice;		//��Ӧ�걨�м�ת�޼۵Ķ�����������дתΪ�޼۶����ļ۸񣬵�λ��Ԫ����ȷ��0.0001Ԫ
		TStockFtdcVolumeType	LeavesQty;				//��Ӧ�걨���м�ת������ʱ��������д�Զ���������������Ӧ�걨���м�ת�޼۵�ʱ��������дתΪ�޼۶���������������Ӧ�걨���޼۶���ʱ����д�����ɹ���������ȱʡ��0
	};

	///��Ȩ��������
	struct CStockFtdcOptionsCancelReqField
	{
		TStockFtdcClOrdIDType 	ClOrdID;				//��Ա�ڲ��������,�������걨ҵ��Χ�ڣ�ͬһ�����׵�Ԫ�Ļ�Ա�ڲ���ű���Ψһ������ϵͳ���ظ�����ǰ̨�ύ��ͬһ�����׵�Ԫ��ͬ�Ļ�Ա�ڲ���Ŷ��������Դ˱���ظ���Ϊ�����ظ����ݡ�
		TStockFtdcClOrdIDType 	OrigClOrdID;		//ԭʼ���׿ͻ����������
		TStockFtdcOrderIDType	OrderID;				//�������������(OrigClOrdID��OrderID����һ������)
	};

	///��Ȩ����Ӧ��
	struct CStockFtdcOptionsCancelRspField
	{
		TStockFtdcOrderIDType OrderID;				//�������������
		TStockFtdcExecTypeType	ExecType;			//��ǰ����ִ������
		TStockFtdcOrdStatusType	OrdStatus;			//��ǰ�걨��״̬
		TStockFtdcSecurityIDType	SecurityID;		//��Լ����
		TStockFtdcClOrdIDType	ClOrdID;					//��Ա�ڲ��������
		TStockFtdcClOrdIDType 	OrigClOrdID;		//ԭʼ���׿ͻ����������
		TStockFtdcTimeType	TransactTimeOnly;	//��������ʱ��
		TStockFtdcPriceType	DiscretionPrice;		//��Ӧ�걨�м�ת�޼۵Ķ�����������дתΪ�޼۶����ļ۸񣬵�λ��Ԫ����ȷ��0.0001Ԫ
		TStockFtdcVolumeType	LeavesQty;				//��Ӧ�걨���м�ת������ʱ��������д�Զ���������������Ӧ�걨���м�ת�޼۵�ʱ��������дתΪ�޼۶���������������Ӧ�걨���޼۶���ʱ����д�����ɹ���������ȱʡ��0
	};

	///��Ȩ��������
	struct CStockFtdcQuoteInsertReqField
	{
		TStockFtdcClOrdIDType 	ClOrdID;		//��Ա�ڲ��������,�������걨ҵ��Χ�ڣ�ͬһ�����׵�Ԫ�Ļ�Ա�ڲ���ű���Ψһ������ϵͳ���ظ�����ǰ̨�ύ��ͬһ�����׵�Ԫ��ͬ�Ļ�Ա�ڲ���Ŷ��������Դ˱���ظ���Ϊ�����ظ����ݡ�
		TStockFtdcSecurityIDType	SecurityID;		//��Լ����
		TStockFtdcOwnerTypeType	OwnerType;		//������������
		TStockFtdcPartyIDType PartyID;			//Ͷ�����ʻ�
		TStockFtdcQuoteReqIDType QuoteReqID;//��������ID,Ԥ���ֶ�,�������Ƕ��������Ӧʱ����д���������ID
		TStockFtdcPriceType BidPx;//�򱨼�
		TStockFtdcPriceType AskPx;//������
		TStockFtdcVolumeType BidSize;//������
		TStockFtdcVolumeType AskSize;//������
		TStockFtdcPositionEffectType BidPositionEffect;//ƽ�ֱ�ʶ���� O�������� �� ��C����ƽ�� ����
		TStockFtdcPositionEffectType AskPositionEffect;//ƽ�ֱ�ʶ���� O�������� �� ��C����ƽ�� ����
	};

	///��Ȩ����Ӧ��
	struct CStockFtdcQuoteInsertRspField
	{
		TStockFtdcOrderIDType OrderID;				//�������������
		TStockFtdcExecTypeType	ExecType;			//��ǰ����ִ������
		TStockFtdcOrdStatusType	OrdStatus;			//��ǰ�걨��״̬
		TStockFtdcClOrdIDType 	ClOrdID;		//��Ա�ڲ��������,�������걨ҵ��Χ�ڣ�ͬһ�����׵�Ԫ�Ļ�Ա�ڲ���ű���Ψһ������ϵͳ���ظ�����ǰ̨�ύ��ͬһ�����׵�Ԫ��ͬ�Ļ�Ա�ڲ���Ŷ��������Դ˱���ظ���Ϊ�����ظ����ݡ�
		TStockFtdcSecurityIDType	SecurityID;		//��Լ����
		TStockFtdcOwnerTypeType	OwnerType;		//������������
		TStockFtdcPartyIDType PartyID;			//Ͷ�����ʻ�
		TStockFtdcQuoteReqIDType QuoteReqID;//��������ID,Ԥ���ֶ�,�������Ƕ��������Ӧʱ����д���������ID
		TStockFtdcPriceType BidPx;//�򱨼�
		TStockFtdcPriceType AskPx;//������
		TStockFtdcVolumeType BidSize;//������
		TStockFtdcVolumeType AskSize;//������
		TStockFtdcPositionEffectType BidPositionEffect;//ƽ�ֱ�ʶ���� O�������� �� ��C����ƽ�� ����
		TStockFtdcPositionEffectType AskPositionEffect;//ƽ�ֱ�ʶ���� O�������� �� ��C����ƽ�� ����
	};

	///��Ȩ������������
	struct CStockFtdcQuoteCancelReqField
	{
		TStockFtdcClOrdIDType 	ClOrdID;			//��Ա�ڲ��������,�������걨ҵ��Χ�ڣ�ͬһ�����׵�Ԫ�Ļ�Ա�ڲ���ű���Ψһ������ϵͳ���ظ�����ǰ̨�ύ��ͬһ�����׵�Ԫ��ͬ�Ļ�Ա�ڲ���Ŷ��������Դ˱���ظ���Ϊ�����ظ����ݡ�
		TStockFtdcClOrdIDType 	OrigClOrdID;		//ԭʼ���׿ͻ����������
		TStockFtdcOrderIDType	OrderID;			//�������������(OrigClOrdID��OrderID����һ������)
	};

	///��Ȩ��������Ӧ��
	struct CStockFtdcQuoteCancelRspField
	{
		TStockFtdcOrderIDType OrderID;				//�������������
		TStockFtdcExecTypeType	ExecType;			//��ǰ����ִ������
		TStockFtdcOrdStatusType	OrdStatus;			//��ǰ�걨��״̬
		TStockFtdcSecurityIDType	SecurityID;			//��Լ����
		TStockFtdcClOrdIDType	ClOrdID;			//��Ա�ڲ��������
		TStockFtdcClOrdIDType 	OrigClOrdID;		//ԭʼ���׿ͻ����������
	};

	///��Ȩ����
	struct CStockFtdcExerciseReqField
	{
		TStockFtdcClOrdIDType 	ClOrdID;				//��Ա�ڲ��������,�������걨ҵ��Χ�ڣ�ͬһ�����׵�Ԫ�Ļ�Ա�ڲ���ű���Ψһ������ϵͳ���ظ�����ǰ̨�ύ��ͬһ�����׵�Ԫ��ͬ�Ļ�Ա�ڲ���Ŷ��������Դ˱���ظ���Ϊ�����ظ����ݡ�
		TStockFtdcSecurityIDType	SecurityID;		//��Լ����
		TStockFtdcOwnerTypeType	OwnerType;	//������������
		TStockFtdcVolumeType OrderQty;				//�걨�������ţ�
		TStockFtdcPartyIDType PartyID;					//Ͷ�����ʻ�
	};

	///��ȨӦ��
	struct CStockFtdcExerciseRspField
	{
		TStockFtdcOrderIDType OrderID;				//�������������
		TStockFtdcClOrdIDType 	ClOrdID;				//��Ա�ڲ��������,�������걨ҵ��Χ�ڣ�ͬһ�����׵�Ԫ�Ļ�Ա�ڲ���ű���Ψһ������ϵͳ���ظ�����ǰ̨�ύ��ͬһ�����׵�Ԫ��ͬ�Ļ�Ա�ڲ���Ŷ��������Դ˱���ظ���Ϊ�����ظ����ݡ�
		TStockFtdcSecurityIDType	SecurityID;		//��Լ����
		TStockFtdcOwnerTypeType	OwnerType;	//������������
		TStockFtdcVolumeType OrderQty;				//�걨�������ţ�
		TStockFtdcPartyIDType PartyID;					//Ͷ�����ʻ�
	};

	///������Ȩ����
	struct CStockFtdcExerciseCancelReqField
	{
		TStockFtdcClOrdIDType 	OrigClOrdID;		//ԭʼ���׿ͻ����������
		TStockFtdcOrderIDType	OrderID;			//�������������(OrigClOrdID��OrderID����һ������)
	};
	///������ȨӦ��
	struct CStockFtdcExerciseCancelRspField
	{
		TStockFtdcClOrdIDType 	 OrigClOrdID;		//ԭʼ���׿ͻ����������
	};

	///ѯ������
	struct CStockFtdcForQuoteReqField
	{
		TStockFtdcSecurityIDType	SecurityID;			//��Լ����
		TStockFtdcOwnerTypeType	OwnerType;			//������������
		TStockFtdcPartyIDType PartyID;				//Ͷ�����ʻ�
		TStockFtdcClOrdIDType	ClOrdID;			//��Ա�ڲ��������
		TStockFtdcQuoteReqIDType QuoteReqID;//��������ID

	};

	///ѯ��Ӧ��
	struct CStockFtdcForQuoteRspField
	{
		TStockFtdcSecurityIDType	SecurityID;			//��Լ����
		TStockFtdcOwnerTypeType	OwnerType;			//������������
		TStockFtdcPartyIDType	PartyID;				//Ͷ�����ʻ�
		TStockFtdcClOrdIDType	ClOrdID;			//��Ա�ڲ��������
		TStockFtdcQuoteReqIDType QuoteReqID;//��������ID
	};

	///��Ȩ֪ͨ
	struct CStockFtdcExerciseRtnField
	{
		TStockFtdcClOrdIDType	ClOrdID;					//��Ա�ڲ��������
		TStockFtdcOrderIDType OrderID;				//�������������
		TStockFtdcSecurityIDType	SecurityID;		//��Լ����
		TStockFtdcOwnerTypeType	OwnerType;	//������������
		TStockFtdcVolumeType OrderQty;				//�걨�������ţ�
		TStockFtdcPartyIDType PartyID;					//Ͷ�����ʻ�
		TStockFtdcTimeType	TransactTimeOnly;	//��������ʱ��
	};

	///��Ȩί�лر�
	struct CStockFtdcOptionsOrderField
	{
		TStockFtdcOrderIDType OrderID;				//�������������
		TStockFtdcClOrdIDType	ClOrdID;					//��Ա�ڲ��������
		TStockFtdcSecurityIDType	SecurityID;		//��Լ����
		TStockFtdcVolumeType TradeQty;				//�ɽ�����
		TStockFtdcVolumeType CancelQty;			//��������,��Ӧ�걨���м�ת������ʱ��������д�Զ���������������Ӧ�걨���м�ת�޼۵�ʱ��������дתΪ�޼۶���������������Ӧ�걨���޼۶���ʱ����д�����ɹ���������ȱʡ��0
		TStockFtdcPriceType Price;							//�걨�۸񣬶����м۶���������
		TStockFtdcVolumeType OrderQty;				//�걨�������ţ�
		TStockFtdcSideType  Side;							//��������
		TStockFtdcPriceType	DiscretionPrice;		//��Ӧ�걨�м�ת�޼۵Ķ�����������дתΪ�޼۶����ļ۸�
		TStockFtdcPositionEffectType PositionEffect;	//����/ƽ��
		TStockFtdcCoveredOrUncoveredType CoveredOrUncovered;		//���ұ�ǩ
		TStockFtdcTimeType TransactTimeOnly;	//����ִ��ʱ��
		TStockFtdcOwnerTypeType	OwnerType;			//������������
		TStockFtdcOrdStatusType OrdStatus;			//��ǰ����״̬
		TStockFtdcOrdTypeType OrdType;				//��������
		TStockFtdcTimeInForceType TimeInForce; 		//������Чʱ������
		TStockFtdcPartyIDType PartyID;				//Ͷ�����ʻ�
		TStockFtdcUserIDType  UserID;				//ԭʼ���������û�����
		TStockFtdcOrdRejReasonType OrdRejReason;		//�����ܾ�ԭ�����
	};

	///��Ȩ�ɽ��ر�
	struct CStockFtdcOptionsTradeField
	{
		TStockFtdcOrderIDType OrderID;				//�������������
		TStockFtdcClOrdIDType	ClOrdID;					//��Ա�ڲ��������
		TStockFtdcExecIDType ExecID;				//�ɽ����
		TStockFtdcSecurityIDType	SecurityID;		//��Լ����
		TStockFtdcPriceType LastPx;						//�ɽ��۸�
		TStockFtdcVolumeType LastQty;					//�ɽ�����
		TStockFtdcVolumeType LeavesQty;			//���γɽ����걨�������
		TStockFtdcSideType  Side;									//��������
		TStockFtdcPositionEffectType PositionEffect;	//����/ƽ��
		TStockFtdcCoveredOrUncoveredType CoveredOrUncovered;		//���ұ�ǩ
		TStockFtdcTimeType TransactTimeOnly;	//����ִ��ʱ��
		TStockFtdcTimeType OrigTime;					//ԭ�ж���������յ�ʱ��
		TStockFtdcExecTypeType ExecType;					//����ִ��״̬��ȡֵ��F=�ɽ�
		TStockFtdcOwnerTypeType	OwnerType;			//������������
		TStockFtdcOrdStatusType OrdStatus;				//��ǰ����״̬
		TStockFtdcPriceType TotalValueTraded;			//�ɽ����
		TStockFtdcPartyIDType PartyID;							//Ͷ�����ʻ�
	};

	///�����֪ͨ
	struct CStockFtdcWithdrawDepositRtnField
	{
		TStockFtdcPartyIDType AccountID;							//�ʽ��ʻ�
		TStockFtdcPartyIDType PartyID;							//Ͷ�����ʻ�
		TStockFtdcPriceType	deposit;								//�����
		TStockFtdcPriceType	withdraw;							//������
	};

	///��Ʊ��������
	struct CStockFtdcStockInsertReqField
	{
		TStockFtdcClOrdIDType 	ClOrdID;				//��Ա�ڲ��������,�������걨ҵ��Χ�ڣ�ͬһ�����׵�Ԫ�Ļ�Ա�ڲ���ű���Ψһ������ϵͳ���ظ�����ǰ̨�ύ��ͬһ�����׵�Ԫ��ͬ�Ļ�Ա�ڲ���Ŷ��������Դ˱���ظ���Ϊ�����ظ����ݡ�
		TStockFtdcSecurityIDType	SecurityID;				//��Լ����
		TStockFtdcOrdTypeType OrdType;					//��������
		TStockFtdcPriceType Price;						//�걨�۸񣬶����м۶��������壬��λ��Ԫ����ȷ��0.001Ԫ��
		TStockFtdcVolumeType OrderQty;					//�걨�������ţ�
		TStockFtdcSideType  Side;						//��������
		TStockFtdcPartyIDType PartyID;					//Ͷ�����ʻ�
		TStockFtdcOwnerTypeType	OwnerType;			//������������
		TStockFtdcTimeInForceType TimeInForce; 	//������Чʱ������
	};

	struct CStockFtdcStockInsertRspField
	{
		TStockFtdcOrderIDType OrderID;			//�������������
		TStockFtdcDateType InsertDate;				//��¼д������
		TStockFtdcTimeType InsertTime;				//����ȷ��ʱ��
		TStockFtdcClOrdIDType ClOrdID;			//��Ա�ڲ��������,
		TStockFtdcSecurityIDType	SecurityID;	//��Լ����
		TStockFtdcOrdTypeType OrdType;					//��������
		TStockFtdcPriceType Price;						//�걨�۸񣬶����м۶���������
		TStockFtdcVolumeType OrderQty;			//�걨�������ţ�
		TStockFtdcSideType  Side;						//��������
		TStockFtdcPartyIDType PartyID;				//Ͷ�����ʻ�
		TStockFtdcVolumeType Qty2;					//���������������޼۶����걨��¼�����ֶ�Ϊ�գ����ڳ�����¼�����ֶ�Ϊʵ�ʳ����������������������嵵��ʱ�ɽ�ʣ���Զ��������м۶���������걨���ֳɽ������ֶ�ȡֵΪ�Զ�����������������걨ȫ���ɽ�������ֶ�ȡֵΪ0��
	};

	///��Ʊ��������
	struct CStockFtdcStockCancelReqField
	{
		TStockFtdcClOrdIDType 	ClOrdID;				//��Ա�ڲ��������,�������걨ҵ��Χ�ڣ�ͬһ�����׵�Ԫ�Ļ�Ա�ڲ���ű���Ψһ������ϵͳ���ظ�����ǰ̨�ύ��ͬһ�����׵�Ԫ��ͬ�Ļ�Ա�ڲ���Ŷ��������Դ˱���ظ���Ϊ�����ظ����ݡ�
		TStockFtdcClOrdIDType 	OrigClOrdID;		//ԭʼ���׿ͻ����������
		TStockFtdcOrderIDType	OrderID;				//�������������
	};

	struct CStockFtdcStockCancelRspField
	{
		TStockFtdcOrderIDType OrderID;			//�������������
		TStockFtdcDateType InsertDate;				//��¼д������
		TStockFtdcTimeType InsertTime;				//����ȷ��ʱ��
		TStockFtdcClOrdIDType ClOrdID;			//��Ա�ڲ��������
		TStockFtdcSecurityIDType	SecurityID;	//��Լ����
		TStockFtdcPriceType Price;						//�걨�۸񣬶����м۶���������
		TStockFtdcVolumeType OrderQty;			//�걨�������ţ�
		TStockFtdcSideType  Side;						//��������
		TStockFtdcPartyIDType PartyID;				//Ͷ�����ʻ�
		TStockFtdcClOrdIDType OrigClOrdId;	//ԭʼ��Ա�ڲ����(����ʱʹ�ö�Ӧ��������ordrec)
		TStockFtdcVolumeType Qty2;					//���������������޼۶����걨��¼�����ֶ�Ϊ�գ����ڳ�����¼�����ֶ�Ϊʵ�ʳ����������������������嵵��ʱ�ɽ�ʣ���Զ��������м۶���������걨���ֳɽ������ֶ�ȡֵΪ�Զ�����������������걨ȫ���ɽ�������ֶ�ȡֵΪ0��
	};

	///֤ȯ��������
	struct CStockFtdcStockLockReqField
	{
		TStockFtdcClOrdIDType 		ClOrdID;				//��Ա�ڲ��������,�������걨ҵ��Χ�ڣ�ͬһ�����׵�Ԫ�Ļ�Ա�ڲ���ű���Ψһ������ϵͳ���ظ�����ǰ̨�ύ��ͬһ�����׵�Ԫ��ͬ�Ļ�Ա�ڲ���Ŷ��������Դ˱���ظ���Ϊ�����ظ����ݡ�
		TStockFtdcSecurityIDType	SecurityID;			//��Լ����
		TStockFtdcVolumeType			OrderQty;			//�걨�������ţ�
		TStockFtdcLockType				Locked;				//������־
		TStockFtdcPartyIDType			PartyID;				//Ͷ�����ʻ�
	};

	struct CStockFtdcStockLockRspField
	{
		TStockFtdcClOrdIDType ClOrdID;			//��Ա�ڲ��������
		TStockFtdcSecurityIDType	SecurityID;	//��Լ����
		TStockFtdcVolumeType OrderQty;			//�걨�������ţ�
		TStockFtdcPartyIDType PartyID;				//Ͷ�����ʻ�
	};

	///��Ʊί��
	struct CStockFtdcStockOrderField
	{
		TStockFtdcOrderIDType OrderID;			//�������������
		TStockFtdcClOrdIDType ClOrdID;			//��Ա�ڲ��������
		TStockFtdcSecurityIDType	SecurityID;	//��Լ����
		TStockFtdcPriceType Price;						//�걨�۸񣬶����м۶���������
		TStockFtdcVolumeType OrderQty;			//�걨�������ţ�
		TStockFtdcSideType  Side;						//��������
		TStockFtdcOrdStatusType OrdStatus;	//��ǰ����״̬
		TStockFtdcVolumeType Qty2;					//���������������޼۶����걨��¼�����ֶ�Ϊ�գ����ڳ�����¼�����ֶ�Ϊʵ�ʳ����������������������嵵��ʱ�ɽ�ʣ���Զ��������м۶���������걨���ֳɽ������ֶ�ȡֵΪ�Զ�����������������걨ȫ���ɽ�������ֶ�ȡֵΪ0��
		TStockFtdcVolumeType TradeQty;			//�ɽ�����
		TStockFtdcPartyIDType PartyID;				//Ͷ�����ʻ�
		TStockFtdcUserIDType  UserID;				//ԭʼ���������û�����
		TStockFtdcOwnerTypeType	OwnerType;			//������������
		TStockFtdcTimeInForceType TimeInForce; 	//������Чʱ������
		TStockFtdcOrdRejReasonType OrdRejReason;		//�����ܾ�ԭ�����
	};

	///��Ʊ�ɽ��ر�
	struct CStockFtdcStockTradeField
	{
		TStockFtdcOrderIDType OrderID;			//�������������
		TStockFtdcTradeIDType TradeID;				//�ɽ����
		TStockFtdcPartyIDType PartyID;				//Ͷ�����ʻ�
		TStockFtdcDateType InsertDate;				//��¼д������
		TStockFtdcTimeType InsertTime;				//�걨ʱ�䣬��ʽΪHHMMSS
		TStockFtdcTimeType TradeTime;			//�ɽ�ʱ�䣬��ʽΪHHMMSS
		TStockFtdcTradeVolumeType	TradeVolume;	//�ɽ�����
		TStockFtdcSideType  Side;						//��������
		TStockFtdcPriceType Cjjg;							//�ɽ��۸�
		TStockFtdcPriceType Cjje;							//�ɽ����
		TStockFtdcSecurityIDType	SecurityID;	//��Լ����
		TStockFtdcClOrdIDType ClOrdID;			//��Ա�ڲ��������
	};

	///���ۻر�
	struct CStockFtdcQuoteOrderField
	{
		TStockFtdcClOrdIDType ClOrdID;			//��Ա�ڲ��������
		TStockFtdcSecurityIDType	SecurityID;	//��Լ����
		TStockFtdcOrdStatusType OrdStatus;	//��ǰ����״̬
		TStockFtdcPartyIDType PartyID;				//Ͷ�����ʻ�
		TStockFtdcUserIDType  UserID;				//ԭʼ���������û�����
		TStockFtdcOwnerTypeType	OwnerType;			//������������
		TStockFtdcQuoteReqIDType QuoteReqID;//��������ID,Ԥ���ֶ�,�������Ƕ��������Ӧʱ����д���������ID
		TStockFtdcPriceType BidPx;//�򱨼�
		TStockFtdcPriceType AskPx;//������
		TStockFtdcVolumeType BidSize;//������
		TStockFtdcVolumeType AskSize;//������
		TStockFtdcPositionEffectType BidPositionEffect;//ƽ�ֱ�ʶ���� O�������� �� ��C����ƽ�� ����
		TStockFtdcPositionEffectType AskPositionEffect;//ƽ�ֱ�ʶ���� O�������� �� ��C����ƽ�� ����
		TStockFtdcOrdRejReasonType OrdRejReason;		//���۾ܾ�ԭ�����
	};

	///��Ϣ�ַ�
	struct CStockFtdcDisseminationField
	{
		///����ϵ�к�
		TStockFtdcSequenceNoType	SequenceSeries;
		///���к�
		TStockFtdcSequenceNoType	SequenceNo;
	};


	///�û���¼����
	struct CStockFtdcReqUserLoginField
	{
		///������
		TStockFtdcDateType	TradingDay;
		///�����û�����
		TStockFtdcUserIDType	UserID;
		///����
		TStockFtdcPasswordType	Password;
		///�û��˲�Ʒ��Ϣ
		TStockFtdcProductInfoType	UserProductInfo;
		///�ӿڶ˲�Ʒ��Ϣ
		TStockFtdcProductInfoType	InterfaceProductInfo;
		///Э����Ϣ
		TStockFtdcProtocolInfoType	ProtocolInfo;
		///�������Ĵ���
		TStockFtdcDataCenterIDType	DataCenterID;
	};

	///�û���¼Ӧ��
	struct CStockFtdcRspUserLoginField
	{
		///������
		TStockFtdcDateType	TradingDay;
		///��¼�ɹ�ʱ��
		TStockFtdcTimeType	LoginTime;
		///����Ա�ڲ��������
		TStockFtdcClOrdIDType	MaxClOrdID;
		///�����û�����
		TStockFtdcUserIDType	UserID;
		///����ϵͳ����
		TStockFtdcTradingSystemNameType	TradingSystemName;
		///�������Ĵ���
		TStockFtdcDataCenterIDType	DataCenterID;
		///��Ա˽������ǰ����
		TStockFtdcSequenceNoType	PrivateFlowSize;
		///����Ա˽������ǰ����
		TStockFtdcSequenceNoType	UserFlowSize;
		///ҵ��������
		TStockFtdcDateType	ActionDay;
	};

	///�û��ǳ�����
	struct CStockFtdcReqUserLogoutField
	{
		///�����û�����
		TStockFtdcUserIDType	UserID;
	};

	///�û��ǳ�Ӧ��
	struct CStockFtdcRspUserLogoutField
	{
		///�����û�����
		TStockFtdcUserIDType	UserID;
	};

	///�û������޸�
	struct CStockFtdcUserPasswordUpdateField
	{
		///�����û�����
		TStockFtdcUserIDType	UserID;
		///������
		TStockFtdcPasswordType	OldPassword;
		///������
		TStockFtdcPasswordType	NewPassword;
	};

	///��Ʊ������ѯ
	struct CStockFtdcQryStockOrderField
	{
		///Ͷ�����ʻ�
		TStockFtdcPartyIDType PartyID;
		///��Ա�ڲ��������
		TStockFtdcClOrdIDType 	ClOrdID;
		///��Լ����
		TStockFtdcSecurityIDType	SecurityID;
	};
	struct CStockFtdcRspQryStockOrderField
	{
		TStockFtdcPartyIDType PartyID;				//Ͷ�����ʻ�
		TStockFtdcDateType InsertDate;				//��¼д������
		TStockFtdcTimeType InsertTime;				//����ȷ��ʱ��
		TStockFtdcClOrdIDType ClOrdID;			//��Ա�ڲ��������,
		TStockFtdcSecurityIDType	SecurityID;	//��Լ����
		TStockFtdcOrdTypeType OrdType;					//��������
		TStockFtdcPriceType Price;						//�걨�۸񣬶����м۶���������
		TStockFtdcVolumeType OrderQty;			//�걨�������ţ�
		TStockFtdcSideType  Side;						//��������
		TStockFtdcVolumeType Qty2;					//���������������޼۶����걨��¼�����ֶ�Ϊ�գ����ڳ�����¼�����ֶ�Ϊʵ�ʳ����������������������嵵��ʱ�ɽ�ʣ���Զ��������м۶���������걨���ֳɽ������ֶ�ȡֵΪ�Զ�����������������걨ȫ���ɽ�������ֶ�ȡֵΪ0��
		TStockFtdcOrdStatusType OrdStatus;	//��ǰ����״̬
	};

	///��Ȩ������ѯ
	struct CStockFtdcQryOptionsOrderField
	{
		///Ͷ�����ʻ�
		TStockFtdcPartyIDType PartyID;
		///��Ա�ڲ��������
		TStockFtdcClOrdIDType 	ClOrdID;
		///��Լ����
		TStockFtdcSecurityIDType	SecurityID;
	};
	struct CStockFtdcRspQryOptionsOrderField
	{
		TStockFtdcPartyIDType PartyID;					//Ͷ�����ʻ�
		TStockFtdcOrderIDType OrderID;				//�������������
		TStockFtdcExecTypeType	ExecType;			//��ǰ����ִ������
		TStockFtdcOrdStatusType	OrdStatus;			//��ǰ�걨��״̬
		TStockFtdcSecurityIDType	SecurityID;		//��Լ����
		TStockFtdcClOrdIDType	ClOrdID;					//��Ա�ڲ��������
		TStockFtdcTimeType	TransactTimeOnly;	//��������ʱ��
		TStockFtdcPriceType	DiscretionPrice;		//��Ӧ�걨�м�ת�޼۵Ķ�����������дתΪ�޼۶����ļ۸񣬵�λ��Ԫ����ȷ��0.0001Ԫ
		TStockFtdcVolumeType	LeavesQty;				//��Ӧ�걨���м�ת������ʱ��������д�Զ���������������Ӧ�걨���м�ת�޼۵�ʱ��������дתΪ�޼۶���������������Ӧ�걨���޼۶���ʱ����д�����ɹ���������ȱʡ��0
		TStockFtdcOwnerTypeType	OwnerType;	//������������
		TStockFtdcPriceType Price;							//�걨�۸񣬶����м۶��������壬��λ��Ԫ����ȷ��0.0001Ԫ��
		TStockFtdcVolumeType OrderQty;				//�걨�������ţ�
		TStockFtdcSideType  Side;									//��������
		TStockFtdcPositionEffectType PositionEffect;	//����/ƽ��
		TStockFtdcOrdTypeType OrdType;						//��������
		TStockFtdcTimeInForceType TimeInForce; 		//������Чʱ������
		TStockFtdcCoveredOrUncoveredType CoveredOrUncovered;		//���ұ�ǩ
		TStockFtdcUserIDType UserID;		//������Ӧ�ĵ�¼�û�
	};

	///���۲�ѯ
	struct CStockFtdcQryQuoteOrderField
	{
		///Ͷ�����ʻ�
		TStockFtdcPartyIDType PartyID;
		///��Ա�ڲ��������
		TStockFtdcClOrdIDType 	ClOrdID;
		///��Լ����
		TStockFtdcSecurityIDType	SecurityID;
	};
	struct CStockFtdcRspQryQuoteOrderField
	{
		TStockFtdcClOrdIDType ClOrdID;			//��Ա�ڲ��������
		TStockFtdcSecurityIDType	SecurityID;	//��Լ����
		TStockFtdcOrdStatusType OrdStatus;	//��ǰ����״̬
		TStockFtdcPartyIDType PartyID;				//Ͷ�����ʻ�
		TStockFtdcUserIDType  UserID;				//ԭʼ���������û�����
		TStockFtdcOwnerTypeType	OwnerType;			//������������
		TStockFtdcQuoteReqIDType QuoteReqID;//��������ID,Ԥ���ֶ�,�������Ƕ��������Ӧʱ����д���������ID
		TStockFtdcPriceType BidPx;//�򱨼�
		TStockFtdcPriceType AskPx;//������
		TStockFtdcVolumeType BidSize;//������
		TStockFtdcVolumeType AskSize;//������
		TStockFtdcPositionEffectType BidPositionEffect;//ƽ�ֱ�ʶ���� O�������� �� ��C����ƽ�� ����
		TStockFtdcPositionEffectType AskPositionEffect;//ƽ�ֱ�ʶ���� O�������� �� ��C����ƽ�� ����
	};

	///��Ʊ�ɽ���ѯ
	struct CStockFtdcQryStockTradeField
	{
		///Ͷ�����ʻ�
		TStockFtdcPartyIDType PartyID;
		///��Լ����
		TStockFtdcSecurityIDType	SecurityID;
		///�ɽ����
		TStockFtdcTradeIDType TradeID;
	};

	///��Ȩ�ɽ���ѯ
	struct CStockFtdcQryOptionsTradeField
	{
		///Ͷ�����ʻ�
		TStockFtdcPartyIDType PartyID;
		///��Լ����
		TStockFtdcSecurityIDType SecurityID;
		///�ɽ����
		TStockFtdcExecIDType ExecID;
	};

	///�ֲֲ�ѯ
	struct CStockFtdcQryPositionField
	{
		///Ͷ�����ʻ�
		TStockFtdcPartyIDType PartyID;
		///��Լ����
		TStockFtdcSecurityIDType SecurityID;
	};

	///�ֲֲ�ѯӦ��
	struct CStockFtdcRspPositionField
	{
		///Ͷ�����ʻ�
		TStockFtdcPartyIDType PartyID;
		///��Լ����
		TStockFtdcSecurityIDType	SecurityID;
		///���ұ��
		TStockFtdcCoveredOrUncoveredType	Converd;
		///��������
		TStockFtdcSideType	Side;
		///���ճֲ�
		TStockFtdcVolumeType	YdPosition;
		///�ֲܳ�
		TStockFtdcVolumeType	Position;
		///���ճֲ�
		TStockFtdcVolumeType	TodayPosition;
		///������ɽ���
		TStockFtdcVolumeType	BuyTradeVolume;
		///�������ɽ���
		TStockFtdcVolumeType	SellTradeVolume;
		///�ֲֳɱ�
		TStockFtdcMoneyType	PositionCost;
		///���ճֲֳɱ�
		TStockFtdcMoneyType	YdPositionCost;
		///ռ�õı�֤��(Ȩ����)
		TStockFtdcMoneyType	UseMargin;
	};

	///�ʽ��ѯ
	struct CStockFtdcQryPartAccountField
	{
		///Ͷ�����ʻ�
		TStockFtdcPartyIDType PartyID;
	};

	///�ʽ��ѯӦ��
	struct CStockFtdcRspPartAccountField
	{
		///Ͷ�����ʻ�
		TStockFtdcPartyIDType PartyID;
		///������
		TStockFtdcDateType	TradingDay;
		///�ϴν���׼����
		TStockFtdcMoneyType	PreBalance;
		///�ڻ�����׼����
		TStockFtdcMoneyType	Balance;
		///�����ʽ�
		TStockFtdcMoneyType	Available;
		///��ǰ��֤���ܶ�
		TStockFtdcMoneyType	CurrMargin;
		///����ı�֤��
		TStockFtdcMoneyType	FrozenMargin;
		///ͨ����ϱ�֤���Żݵ��ܶ�
		TStockFtdcMoneyType	CombMargin;
		///��ȨȨ������֧
		TStockFtdcMoneyType	Premium;
		///�����Ȩ����
		TStockFtdcMoneyType	FrozenPremium;
		///������
		TStockFtdcMoneyType	Commi;
		///�����������
		TStockFtdcMoneyType	FrozenCommi;
		///ƽ��ӯ��
		TStockFtdcMoneyType	CloseProfit;
		///�ֲ�ӯ��
		TStockFtdcMoneyType	PosiProfit;
		///�����
		TStockFtdcMoneyType	Deposit;
		///������
		TStockFtdcMoneyType	Withdraw;
		///����׼����
		TStockFtdcMoneyType	BaseReserve;
		///�����ֶ�
		TStockFtdcMoneyType	SaveDouble1;
		///�����ֶ�
		TStockFtdcMoneyType	SaveDouble2;
		///�����ֶ�
		TStockFtdcMoneyType	SaveDouble3;
	};

	///��Ʊ��ѯ����
	struct CStockFtdcQryStockField
	{
		///��Լ����
		TStockFtdcSecurityIDType	SecurityID;
	};

	///��Ʊ��ѯӦ��
	struct CStockFtdcRspQryStockField
	{
		TStockFtdcSecurityIDType	SecurityID;					//��Լ����
		char contractid[20];//��Լ���״���
		char contractsymbol[21];//��Ȩ��Լ���
		TStockFtdcVolumeType contractmultiplierunit;//��Լ��λ
		TStockFtdcDateType startdate;//�׸�������
		TStockFtdcDateType enddate;//�������
		int updateversion;//��Լ�汾��
		TStockFtdcVolumeType totallongposition;//��ǰ��Լδƽ����
		TStockFtdcPriceType securityclosepx;//��Լǰ���̼�
		TStockFtdcPriceType settlprice;//��Լǰ�����
		TStockFtdcPriceType underlyingclosepx;//���֤ȯǰ����
		char pricelimittype;//�ǵ����������͡�N�����ǵ�����������
		TStockFtdcPriceType dailypriceuplimit;//�Ƿ����޼۸�
		TStockFtdcPriceType dailypricedownlimit;//�������޼۸�
		TStockFtdcMoneyType marginunit;//��λ��֤��
		TStockFtdcMoneyType marginratioparam1;//��֤������������һ
		TStockFtdcMoneyType marginratioparam2;//��֤��������������
		TStockFtdcVolumeType roundlot;//������
		TStockFtdcVolumeType lmtordminfloor;//�����޼��걨����
		TStockFtdcVolumeType lmtordmaxfloor;//�����޼��걨����
		TStockFtdcVolumeType mktordminfloor;//�����м��걨����
		TStockFtdcVolumeType mktordmaxfloor;//�����м��걨����
		TStockFtdcPriceType ticksize;//��С���۵�λ
		TStockFtdcPriceType lastprice;//��Լ���¼۸�����ʵʱ����
	};

	///��Ȩ��ѯ����
	struct CStockFtdcQryOptionsField
	{
		///��Լ����
		TStockFtdcSecurityIDType	SecurityID;
	};

	///��Ȩ��ѯӦ��
	struct CStockFtdcRspQryOptionsField
	{
		TStockFtdcSecurityIDType	SecurityID;					//��Լ����
		char contractid[20];//��Լ���״���
		char contractsymbol[21];//��Ȩ��Լ���
		TStockFtdcSecurityIDType underlyingsecurityid;//���֤ȯ����
		char underlyingsymbol[9];//����֤ȯ֤ȯ����
		char underlyingtype[4];//���֤ȯ����(EBS �C ETF�� ASH �C A��)
		TStockFtdcOptionTypeType optiontype;//��Ȩ����
		TStockFtdcCallOrPutType callorput;//�Ϲ��Ϲ�
		TStockFtdcVolumeType contractmultiplierunit;//��Լ��λ
		TStockFtdcPriceType exerciseprice;//��Ȩ��Ȩ��
		TStockFtdcDateType startdate;//�׸�������
		TStockFtdcDateType enddate;//�������
		TStockFtdcDateType exercisedate;//��Ȩ��Ȩ��
		TStockFtdcDateType deliverydate;//��Ȩ������
		TStockFtdcDateType expiredate;//��Ȩ������
		int updateversion;//��Լ�汾��
		TStockFtdcVolumeType totallongposition;//��ǰ��Լδƽ����
		TStockFtdcPriceType securityclosepx;//��Լǰ���̼�
		TStockFtdcPriceType settlprice;//��Լǰ�����
		TStockFtdcPriceType underlyingclosepx;//���֤ȯǰ����
		char pricelimittype;//�ǵ����������͡�N�����ǵ�����������
		TStockFtdcPriceType dailypriceuplimit;//�Ƿ����޼۸�
		TStockFtdcPriceType dailypricedownlimit;//�������޼۸�
		TStockFtdcMoneyType marginunit;//��λ��֤��
		TStockFtdcMoneyType marginratioparam1;//��֤������������һ
		TStockFtdcMoneyType marginratioparam2;//��֤��������������
		TStockFtdcVolumeType roundlot;//������
		TStockFtdcVolumeType lmtordminfloor;//�����޼��걨����
		TStockFtdcVolumeType lmtordmaxfloor;//�����޼��걨����
		TStockFtdcVolumeType mktordminfloor;//�����м��걨����
		TStockFtdcVolumeType mktordmaxfloor;//�����м��걨����
		TStockFtdcPriceType ticksize;//��С���۵�λ
		TStockFtdcPriceType lastprice;//��Լ���¼۸�����ʵʱ����
	};

	///��Ȩ��������
	struct CStockFtdcQryRateField
	{
		///Ͷ�����ʻ�(�����ֶ�)
		TStockFtdcPartyIDType PartyID;
		///��Լ����
		TStockFtdcSecurityIDType	SecurityID;
	};

	///��������Ϣ
	typedef struct Commi_Info
	{
		TStockFtdcMoneyType	bymoney;				//��������ȡ
		TStockFtdcMoneyType	byvolume;				//��������ȡ
		TStockFtdcMoneyType	maxcommi;			//���
		TStockFtdcMoneyType	mincommi;			//���
	}Commi_Info_t;
	///��Ȩ����Ӧ��
	struct CStockFtdcRspQryRateField
	{
		///Ͷ�����ʻ�
		TStockFtdcPartyIDType PartyID;
		///��Լ����
		TStockFtdcSecurityIDType	SecurityID;
		TStockFtdcMoneyType Margin;			//��Ȩ��֤��
		Commi_Info_t BuyOpenCommi;		//��������
		Commi_Info_t SelOpenCommi;			//����������
		Commi_Info_t CovOpenCommi;		//���ҿ�������
		Commi_Info_t BuyCloseCommi;		//��ƽ������
		Commi_Info_t SelCloseCommi;			//��ƽ������
		Commi_Info_t CovCloseCommi;		//����ƽ������
	};



	///��Ȩ��֤������
	struct CStockFtdcQryClientMarginField
	{
		///Ͷ�����ʻ�(�����ֶ�)
		TStockFtdcPartyIDType PartyID;
		///��Լ����
		TStockFtdcSecurityIDType	SecurityID;
	};
	///��Ȩ��֤��Ӧ��
	struct CStockFtdcRspQryClientMarginField
	{
		///Ͷ�����ʻ�
		TStockFtdcPartyIDType PartyID;
		///��Լ����
		TStockFtdcSecurityIDType	SecurityID;
		TStockFtdcMoneyType Margin;									//��Ȩ��֤��
		TStockFtdcMoneyType MarginRatio;							//��ı�֤����
		TStockFtdcMoneyType MinMarginRatio;					//��ͱ���ϵ��
	};

	///�ͻ���ѯӦ��
	struct CStockFtdcRspClientField
	{
		TStockFtdcPartyIDType PartyID;							//Ͷ�����ʻ�
		TStockFtdcClientTypeType	ClientType;		///Ͷ��������
		TStockFtdcTradStatusType Status;															//����״̬:0:����,1:��ֹ����
	};

	///��Ȩ��ѯ����
	struct CStockFtdcQryExerciseField
	{
		TStockFtdcPartyIDType PartyID;							//Ͷ�����ʻ�
	};

	struct OmlItem
	{
		TStockFtdcSecurityIDType LegSecurityID;	//��Լ����
		char LegSide;			//��Լ����LΪȨ����, SΪ�����
		TStockFtdcCoveredOrUncoveredType CoveredOrUncovered;// ���ұ�ǩ
		TStockFtdcVolumeType LegOrderQty;		//�걨����
	};

	///�ͻ������������
	struct CStockFtdcMarginCombActionField
	{
		TStockFtdcClOrdIDType 	ClOrdID;				//��Ա�ڲ��������,�������걨ҵ��Χ�ڣ�ͬһ�����׵�Ԫ�Ļ�Ա�ڲ���ű���Ψһ������ϵͳ���ظ�����ǰ̨�ύ��ͬһ�����׵�Ԫ��ͬ�Ļ�Ա�ڲ���Ŷ��������Դ˱���ظ���Ϊ�����ظ����ݡ�
		TStockFtdcSecurityIDType CombID;			//��ϲ��Ա���:ĿǰΪ7����ϲ��ԣ�CNSJC��PXSJC��PNSJC��CXSJC��KS��KKS��ZBD
		TStockFtdcOwnerTypeType	OwnerType;				//������������
		TStockFtdcVolumeType OrderQty;					//�걨�������ţ�
		char  Side;						//��������,ȡֵ��B��ʾ��ϣ�C��ʾ���,��ϲ���Ϊ��ZBD��ʱ��������ַ���ֻ��Ϊ��B����
		char SecondaryOrderID[17];//��ϱ���ID,����걨ʱ�����ֶ�Ϊ�ո񣻲���걨ʱ����д������ϵ���ϱ���
		TStockFtdcPartyIDType PartyID;							//Ͷ�����ʻ�
		int NoLeges;//�ɷֺ�Լ����ȡֵ������4������ظ���
		OmlItem item[4];
	};
	///�ͻ��������Ӧ��
	struct CStockFtdcMarginCombActionRspField
	{
		TStockFtdcOrderIDType OrderID;				//�������������
		TStockFtdcClOrdIDType 	ClOrdID;				//��Ա�ڲ��������,�������걨ҵ��Χ�ڣ�ͬһ�����׵�Ԫ�Ļ�Ա�ڲ���ű���Ψһ������ϵͳ���ظ�����ǰ̨�ύ��ͬһ�����׵�Ԫ��ͬ�Ļ�Ա�ڲ���Ŷ��������Դ˱���ظ���Ϊ�����ظ����ݡ�
		TStockFtdcSecurityIDType CombID;			//��ϲ��Ա���:ĿǰΪ7����ϲ��ԣ�CNSJC��PXSJC��PNSJC��CXSJC��KS��KKS��ZBD
		TStockFtdcOwnerTypeType	OwnerType;				//������������
		TStockFtdcVolumeType OrderQty;					//�걨�������ţ�
		char  Side;						//��������,ȡֵ��B��ʾ��ϣ�C��ʾ���,��ϲ���Ϊ��ZBD��ʱ��������ַ���ֻ��Ϊ��B����
		char SecondaryOrderID[17];//��ϱ���ID,����걨ʱ�����ֶ�Ϊ�ո񣻲���걨ʱ����д������ϵ���ϱ���
		TStockFtdcPartyIDType PartyID;							//Ͷ�����ʻ�
		int NoLeges;//�ɷֺ�Լ����ȡֵ������4������ظ���
		OmlItem item[4];
	};
	///�ͻ��������֪ͨ
	struct CStockFtdcMarginCombActionRtnField
	{
		TStockFtdcClOrdIDType	ClOrdID;					//��Ա�ڲ��������
		TStockFtdcExecIDType ExecID;				//�ɽ����
		TStockFtdcSecurityIDType CombID;			//��ϲ��Ա���:ĿǰΪ7����ϲ��ԣ�CNSJC��PXSJC��PNSJC��CXSJC��KS��KKS��ZBD
		TStockFtdcTimeType TransactTimeOnly;	//����ִ��ʱ��
		TStockFtdcTimeType OrigTime;					//ԭ�ж���������յ�ʱ��
		TStockFtdcPartyIDType PartyID;							//Ͷ�����ʻ�
		char  Side;						//��������,ȡֵ��B��ʾ��ϣ�C��ʾ���,��ϲ���Ϊ��ZBD��ʱ��������ַ���ֻ��Ϊ��B����
		char SecondaryOrderID[17];//��ϱ���ID,����걨ʱ�����ֶ�Ϊ�ո񣻲���걨ʱ����д������ϵ���ϱ���
		TStockFtdcVolumeType LastQty;					//ִ���������ţ�
		int NoLeges;//�ɷֺ�Լ����ȡֵ������4������ظ���
		OmlItem item[4];
		TStockFtdcPriceType commargin;//��ϻ��ֺ�֤��ı仯ֵ(���Ϊ�����Ϊ��)
	};
	///��������ϳֲֲ�ѯ����
	struct CStockFtdcCombPositionField
	{
		TStockFtdcPartyIDType PartyID;			//Ͷ�����ʻ�
		char SecondaryOrderID[17];//��ϱ���ID
	};
	///��������ϳֲֲ�ѯӦ��
	struct CStockFtdcCombPositionRspField
	{
		TStockFtdcPartyIDType PartyID;			//Ͷ�����ʻ�
		char SecondaryOrderID[17];//��ϱ���ID
		TStockFtdcVolumeType PosiQty;					//�ֲ�����
		TStockFtdcPriceType commargin;	//�Żݵı�֤��
		int NoLeges;//�ɷֺ�Լ����ȡֵ������4������ظ���
		OmlItem item[4];
	};
	///�����Ȩ����
	struct CStockFtdcCombExerciseReqField
	{
		TStockFtdcClOrdIDType 	ClOrdID;			//��Ա�ڲ��������,�������걨ҵ��Χ�ڣ�ͬһ�����׵�Ԫ�Ļ�Ա�ڲ���ű���Ψһ������ϵͳ���ظ�����ǰ̨�ύ��ͬһ�����׵�Ԫ��ͬ�Ļ�Ա�ڲ���Ŷ��������Դ˱���ظ���Ϊ�����ظ����ݡ�
		TStockFtdcOwnerTypeType	OwnerType;			//������������
		TStockFtdcVolumeType OrderQty;				//�걨�������ţ�
		TStockFtdcPartyIDType PartyID;				//Ͷ�����ʻ�
		TStockFtdcSecurityIDType LegSecurityID1;	//��Լ����
		TStockFtdcVolumeType LegOrderQty1;		//�걨����
		TStockFtdcSecurityIDType LegSecurityID2;	//��Լ����
		TStockFtdcVolumeType LegOrderQty2;		//�걨����
	};

	///�����ȨӦ��
	struct CStockFtdcCombExerciseRspField
	{
		TStockFtdcOrderIDType OrderID;				//�������������
		TStockFtdcClOrdIDType 	ClOrdID;			//��Ա�ڲ��������,�������걨ҵ��Χ�ڣ�ͬһ�����׵�Ԫ�Ļ�Ա�ڲ���ű���Ψһ������ϵͳ���ظ�����ǰ̨�ύ��ͬһ�����׵�Ԫ��ͬ�Ļ�Ա�ڲ���Ŷ��������Դ˱���ظ���Ϊ�����ظ����ݡ�
		TStockFtdcOwnerTypeType	OwnerType;			//������������
		TStockFtdcVolumeType OrderQty;				//�걨�������ţ�
		TStockFtdcPartyIDType PartyID;				//Ͷ�����ʻ�
		TStockFtdcSecurityIDType LegSecurityID1;	//��Լ����
		TStockFtdcVolumeType LegOrderQty1;		//�걨����
		TStockFtdcSecurityIDType LegSecurityID2;	//��Լ����
		TStockFtdcVolumeType LegOrderQty2;		//�걨����
	};
}


#endif
