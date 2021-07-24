/*************************
*ժҪ���ϻ��ڻ�����ϵͳ
*�ļ���NhUserApiDataType.h
*      �����˿ͻ��˽ӿ���������
*���ߣ��ϻ��ڻ������
*ʱ�䣺20130604
**************************/

#ifndef __NH_USERAPI_DATATYPE_H__
#define __NH_USERAPI_DATATYPE_H__

enum TE_RESUME_TYPE
{
	TERT_RESTART = 0,
	TERT_RESUME,
	TERT_QUICK
};

/////////////////////////////////////////////////////////////////////////////////
//���������(0-��ʾ�ɹ�)������Ŷ���μ�Protocol_Error.h
typedef int						TErrorCodeType;
//�ɹ�
const TErrorCodeType			ERROR_SUCCEED					= 0;
//������Ϣ����
typedef char TErrorMessageType[56];

/////////////////////////////////////////////////////////////////////////////////
//���ں�ʱ������(��ʽ yyyy-MM-dd hh:nn:ss)
typedef char					TDateTimeType[21];
//��������(��ʽ yyyy-MM-dd)
typedef char					TDateType[11];
//ʱ������(��ʽ hh:nn:ss)
typedef char					TTimeType[11];
//ʱ���б�����(��ʽ hh:nn:ss)
typedef char					TTimeListType[512];
//long��ʱ������(��λΪ��)
typedef long TLongTimeType;

/////////////////////////////////////////////////////////////////////////
///�������
typedef int TYearType;

/////////////////////////////////////////////////////////////////////////
///�·�����
typedef int TMonthType;

/////////////////////////////////////////////////////////////////////////
///��������
typedef int TMillisecType;

////////////////////////////////////////////////////////////////////////////////
//������������(�����п��ܻ��漰����Ʊ��Ȩ�����⣬���Ի���С������)
typedef double TMdVolumeType;
//��������
typedef long TVolumeType;
//�۸�����
typedef double TPriceType;
//�������
typedef double TMoneyType;
//Int�ͱ����ֶ�����
typedef int TSaveIntType;
//Double�ͱ����ֶ�����
typedef double TSaveDoubleType;
//String�ͱ����ֶ�����
typedef char TSaveStringType[256];
//�ǵ�������
typedef double TRangeType;
//��ʵ������
typedef double TDeltaType;
//������Դ����
typedef char TMdSourceType[56];

/////////////////////////////////////////////////////////////////////////////////
//ÿ�ֺ�Լ��������(������ծ��С��,LIFFEС�ƽ�С��)
typedef double					TProductDotType;
//��С�䶯�۷�������
typedef double					TUpperTickType;
//��С�䶯�۷�ĸ����(�Ƿ�������Ϊ1)
typedef int						TLowerTickType;

////////////////////////////////////////////////////////////////////////////////
//��½������Ϣ����Ҫ����mac��ַ
typedef char					TMachineInfoType[201];
//��֤��������Ԥ����Ϣ
typedef char					TResveredInfoType[256];
//�ϴε�¼������Ϣ
typedef char					TWorkstationInfoType[256];

/////////////////////////////////////////////////////////////////////////
///���Ĺ�������
typedef char TRouteKeyType[100][56];

/////////////////////////////////////////////////////////////////////////////////
//Ip��ַ����(ipv4���15λ,ipv6��󳤶�39λ)
typedef char					TIpType[41];
/////////////////////////////////////////////////////////////////////////////////
//Mac��ַ����
typedef char					TMacAddressType[51];

////////////////////////////////////////////////////////////////////////////////
//�������
typedef int TSequenceIDType;
//��Ӧ�����������
typedef int TRspCodeType;
//��Ӧ�ı�����
typedef char TRspStringType[56];

////////////////////////////////////////////////////////////////////////////////
//������ID����
typedef int TServerIDType;
//��������������
typedef char TServerNameType[56];
//�������б�����
typedef char TExchangeListType[256];

/////////////////////////////////////////////////////////////////////////////////
//OMS״̬����
typedef char					TOMSStatusType;
//����
const TOMSStatusType			OMS_NORMSL						= 'N';
//�ǹ���״̬
const TOMSStatusType			OMS_NOT_WORK				= 'D';

////////////////////////////////////////////////////////////////////////////////
//�û�������
typedef char TUserIDType[56];
//��������
typedef char TPassWordType[56];
//��̬��������
typedef char TOneTimePassWordType[7];
//CA��֤����������(�������ݰ���β,ͨ�����ݰ����Ȼ�ȡ���ݳ���)
typedef char					TCaInfoType[1];
//ca��֤��Ϣ����
typedef char TCAInfoType[256];
//��֤������ʶ��������
typedef char TServerCDKeyType[256];
//��Կ����
typedef char TPublicKeyType[129];

////////////////////////////////////////////////////////////////////////////////
//�����߱�������
typedef char TDevelopCodeType[56];
//��������Ȩ����
typedef char TDevelopLicenseType[256];

/////////////////////////////////////////////////////////////////////////////////
//�����ʺ�����
typedef char					TTradeNoType[21];
/////////////////////////////////////////////////////////////////////////////////
//�ͻ��������
typedef char					TClientNoType[21];
//�ͻ�Ԥ����Ϣ����
typedef char					TReservedInfoType[51];
//����Ա�������
typedef char					TOperatorNoType[11];
//����Ա��������
typedef char					TOperatorNameType[21];

////////////////////////////////////////////////////////////////////////////////
//�Ƿ��������
typedef bool TIsEncryptType;
//��
const TIsEncryptType		IS_ENCRYPT_YES		= true;
//��
const TIsEncryptType		IS_ENCRYPT_NO			= false;

/////////////////////////////////////////////////////////////////////////////////
//�Ƿ�CA��֤����
typedef char					TIsCaLoginType;
//CA��֤��ʽ
const TIsCaLoginType			CA_LOGIN						= 'Y';
//��CA��֤��ʽ
const TIsCaLoginType			NOT_CA_LOGIN					= 'N';

/////////////////////////////////////////////////////////////////////////////////
//�Ƿ�ǿ���޸���������
typedef char					TIsForcePasswordType;
//ǿ���޸�����
const TIsForcePasswordType		FORCE_PWD						= 'Y';
//��ǿ���޸�����
const TIsForcePasswordType		NOT_FORCE_PWD					= 'N';

/////////////////////////////////////////////////////////////////////////////////
//��¼������
typedef char					TLoginNoType[21];
//��¼��������(�ͻ����,����Ա����)
typedef char					TLoginNameType[21];
//��¼��������
typedef	char					TLoginPasswordType[21];
//otp����
typedef char					TOtpPassType[21];

/////////////////////////////////////////////////////////////////////////////////
//��������
typedef char					TPasswordTypeType;
//��������
const TPasswordTypeType			PASSWORD_TYPE_TRADE				= 'T';
//��������
const TPasswordTypeType			PASSWORD_TYPE_QUOTE				= 'Q';
//��֤����
const TPasswordTypeType			PASSWORD_TYPE_AUTH				= 'A';

/////////////////////////////////////////////////////////////////////////////////
//��ѯ֪ͨ����
typedef char					TQryNotifyTypeType;
//�����û�֪ͨ
const TQryNotifyTypeType	QRY_NOTIFY_ALL			= 0;
//ĳ���ض��û�
const TQryNotifyTypeType	QRY_NOTIFY_SPECIFIC			= 1;

/////////////////////////////////////////////////////////////////////////////////
//�г��������
typedef char					TExchangeNoType[11];
//�г���������
typedef char					TExchangeNameType[21];

/////////////////////////////////////////////////////////////////////////////////
//�г�״̬����
typedef char					TExchangeStateType;
//�г�������
const TExchangeStateType		EXCHANGE_STATE_YES				= 'Y';
//�г���ֹ����
const TExchangeStateType		EXCHANGE_STATE_NO				= 'N';
//�г�ֻ��ƽ��
const TExchangeStateType		EXCHANGE_STATE_COVER			= 'C';
//�г�����
const TExchangeStateType		EXCHANGE_STATE_OPEN				= 'O';
//�г����ڽ���״̬
const TExchangeStateType		EXCHANGE_STATE_SETTLE			= 'S';

/////////////////////////////////////////////////////////////////////////////////
//��Ʒ�������(ͬһ�г��ڲ�Ψһ  �г�+��Ʒ����+��Ʒ Ψһ)
typedef char					TCommodityNoType[11];
//��Ʒ��������
typedef char					TCommodityNameType[21];

/////////////////////////////////////////////////////////////////////////////////
//��Ʒ��������
typedef char					TCommodityTypeType;
//�ֻ�
const TCommodityTypeType		COMMODITY_TYPE_GOODS			= 'G';
//�ڻ�
const TCommodityTypeType		COMMODITY_TYPE_FUTURE			= 'F';
//��Ȩ
const TCommodityTypeType		COMMODITY_TYPE_OPTION			= 'O';
//��������
const TCommodityTypeType		COMMODITY_TYPE_SPREAD_MONTH		= 'M';
//��Ʒ������
const TCommodityTypeType		COMMODITY_TYPE_SPREAD_COMMODITY	= 'C';

/////////////////////////////////////////////////////////////////////////////////
//��Ʒ��������
typedef char					TCommodityAttributeType[21];

/////////////////////////////////////////////////////////////////////////////////
//��Ʒ״̬����
typedef char					TCommodityStateType;
//��Ʒ������
const TCommodityStateType		COMMODITY_STATE_YES				= 'Y';
//��Ʒ��ֹ����
const TCommodityStateType		COMMODITY_STATE_NO				= 'N';
//��Ʒֻ��ƽ��
const TCommodityStateType		COMMODITY_STATE_COVER			= 'C';

/////////////////////////////////////////////////////////////////////////////////
//���ʽ����
typedef char					TDeliveryModeType;
//ʵ�ｻ��
const TDeliveryModeType			DELIVERY_MODE_GOODS				= 'G';
//�ֽ𽻸�
const TDeliveryModeType			DELIVERY_MODE_CASH				= 'C';
//��Ȩ��Ȩ
const TDeliveryModeType			DELIVERY_MODE_EXECUTE			= 'E';

/////////////////////////////////////////////////////////////////////////////////
//������ƫ������(0����ͬ���������)
typedef int						TDeliveryDaysType;

/////////////////////////////////////////////////////////////////////////////////
//�ֲֹؼ�������(��ʷ�ֲ�ȫ��Ψһ,���ճֲ�ÿ�β�ѯΨһ)
typedef int						THoldKeyIdType;
//����ؼ�������(���ս�������ȫ��Ψһ)
typedef int						TDeliveryKeyIdType;

/////////////////////////////////////////////////////////////////////////////////
//�ֲּ��㷽ʽ
typedef char					TDepositCalculateModeType;
//����
const TDepositCalculateModeType	DEPOSIT_CALCULATE_MODE_NORMAL	= 'N';
//��Լ���ֲ�
const TDepositCalculateModeType	DEPOSIT_CALCULATE_MODE_CLEAN	= 'C';
//Ʒ������
const TDepositCalculateModeType DEPOSIT_CALCULATE_MODE_LOCK		= 'L';

/////////////////////////////////////////////////////////////////////////////////
//��Լ�������
typedef char					TContractNoType[71];
//��Լ��������
typedef char					TContractNameType[21];
//��Լ����������(��Լ���м��쵽��)
typedef int						TContractLastDays;

/////////////////////////////////////////////////////////////////////////////////
//��Լ��������
typedef char					TContractTypeType;
//���Ⱥ�Լ
const TContractTypeType			CONTRACT_TYPE_SINGLE			= '0';
//��������
const TContractTypeType			CONTRACT_TYPE_SPREAD			= '1';
//��������
const TContractTypeType			CONTRACT_TYPE_SWAP				= '2';
//��Ʒ������
const TContractTypeType			CONTRACT_TYPE_COMMODITY			= '3';

/////////////////////////////////////////////////////////////////////////////////
//��Լ״̬����
typedef char					TContractStateType;
//��Լ������
const TContractStateType		CONTRACT_STATE_YES				= 'Y';
//��Լ��ֹ����
const TContractStateType		CONTRACT_STATE_NO				= 'N';
//��Լֻ��ƽ��
const TContractStateType		CONTRACT_STATE_COVER			= 'C';


///////////////////////////////////////////////////////////////////////////
//��Լ����״̬����
typedef int					TContractTradeStateType;
//��Լδ֪
const TContractTradeStateType		CONTRACT_TRADE_STATE_UNKNOW		= -1;
//����
const TContractTradeStateType		CONTRACT_TRADE_STATE_OPEN			= 0;
//�޺���
const TContractTradeStateType		CONTRACT_TRADE_STATE_NOBONUS		= 1;
//����
const TContractTradeStateType		CONTRACT_TRADE_STATE_AUCTION		= 2;
//����
const TContractTradeStateType		CONTRACT_TRADE_STATE_HALT			= 3;
//����
const TContractTradeStateType		CONTRACT_TRADE_STATE_CLOSE			= 4;
//����ǰ
const TContractTradeStateType		CONTRACT_TRADE_STATE_BEFORE_OPEN	= 5;
//����ǰ
const TContractTradeStateType		CONTRACT_TRADE_STATE_BEFORE_CLOSE	= 6;
//����
const TContractTradeStateType		CONTRACT_TRADE_STATE_FAST			= 7;


///////////////////////////////////////////////////////////////////////////
//ί�б������(ÿ�����׷�������Ψһ��־,�ɷ���������)
typedef int						TOrderIdType;
//���ر������(ÿ�����׷�������Ψһ��־,�ɷ���������)
typedef char					TLocalNoType[21];
//ϵͳ�������(�ϼ�����������Ψһ��־,��ͬ���������ܻ��ظ�)
typedef char					TSystemNoType[64];
//�ɽ����
typedef char					TMatchNoType[71];
//���ر������(ÿ�����׷�������Ψһ��־,�ɷ���������)
typedef char					TFeLocalNoType[sizeof(TLocalNoType) + 1];
//�ɽ�ID
typedef int					TMatchIdType;

///////////////////////////////////////////////////////////////////////////
//������������
typedef unsigned int			TStreamIdType;


///////////////////////////////////////////////////////////////////////////
//�Ƿ���ձ���
typedef char					TIsRiskOrderType;
//�Ƿ��ձ���
const TIsRiskOrderType			RISK_ORDER_YES					= 'Y';
//���Ƿ��ձ���
const TIsRiskOrderType			RISK_ORDER_NO					= 'N';

///////////////////////////////////////////////////////////////////////////
//��������
typedef char					TDirectType;
//����
const TDirectType				DIRECT_BUY						= 'B';
//����
const TDirectType				DIRECT_SELL						= 'S';

///////////////////////////////////////////////////////////////////////////
//��ƽ����
typedef char					TOffsetType;
//��
const TOffsetType				OFFSET_NONE						= 'N';
//����
const TOffsetType				OFFSET_OPEN						= 'O';
//ƽ��
const TOffsetType				OFFSET_COVER					= 'C';
//ƽ��
const TOffsetType				OFFSET_COVER_TODAY				= 'T';

/////////////////////////////////////////////////////////////////////////////////
//ƽ�ַ�ʽ����
typedef char					TCoverModeType;
//�����ֿ�ƽ
const TCoverModeType			COVER_MODE_NONE					= 'N';
//ƽ��δ�˽�
const TCoverModeType			COVER_MODE_UNFINISHED			= 'U';
//���ֺ�ƽ��
const TCoverModeType			COVER_MODE_OPENCOVER			= 'C';
//���֡�ƽ�ֺ�ƽ��
const TCoverModeType			COVER_MODE_COVERTODAY			= 'T';

///////////////////////////////////////////////////////////////////////////
//Ͷ����ֵ����
typedef char					THedgeType;
//��
const THedgeType				HEDGE_NONE						= 'N';
//Ͷ��
const THedgeType				HEDGE_T							= 'T';
//��ֵ
const THedgeType				HEDGE_B							= 'B';

///////////////////////////////////////////////////////////////////////////
//�˹���д������
typedef char					TManualFeeType;
//�˹�
const TManualFeeType			MANUALFEE_YES					= 'Y';
//�Զ�
const TManualFeeType			MANUALFEE_NO					= 'N';


///////////////////////////////////////////////////////////////////////////
//ί������
typedef char					TOrderTypeType;
//�޼�
const TOrderTypeType			ORDER_TYPE_LIMIT				= '1';
//�м�
const TOrderTypeType			ORDER_TYPE_MARKET				= '2';
//�޼�ֹ��
const TOrderTypeType			ORDER_TYPE_STOP_LIMIT			= '3';
//�м�ֹ��
const TOrderTypeType			ORDER_TYPE_STOP_MARKET			= '4';

///////////////////////////////////////////////////////////////////////////
//ί�з�ʽ
typedef char					TOrderWayType;
//�������ӵ�
const char						ORDER_WAY_SELF_ETRADER			= 'E';
//������ӵ�
const char						ORDER_WAY_PROXY_ETRADER			= 'P';
//�ⲿ���ӵ�(�ⲿ����ϵͳ�µ�����ϵͳ¼��)
const char						ORDER_WAY_JTRADER				= 'J';
//�˹�¼�뵥(�ⲿ������ʽ�µ�����ϵͳ¼��)
const char						ORDER_WAY_MANUAL				= 'M';
//carry��
const char						ORDER_WAY_CARRY					= 'C';
//��ʽ������
const char						ORDER_WAY_PROGRAM				= 'S';

///////////////////////////////////////////////////////////////////////////
//ί��ģʽ����
typedef char					TOrderModeType;
//FOK
const TOrderModeType			ORDER_MODE_FOK					= '1';
//FAK��IOC
const TOrderModeType			ORDER_MODE_FAK					= '2';
//������Ч
const TOrderModeType			ORDER_MODE_GFD					= '3';
//ȡ��ǰ��Ч
const TOrderModeType			ORDER_MODE_GTC					= '4';
//ָ������ǰ��Ч
const TOrderModeType			ORDER_MODE_GTD					= '5';

///////////////////////////////////////////////////////////////////////////
//ί��¼������
typedef char					TOrderInputType;
//��
const TOrderInputType			ORDER_INPUT_YES					= 'Y';
//��
const TOrderInputType			ORDER_INPUT_NO					= 'N';

///////////////////////////////////////////////////////////////////////////
//ί��״̬����
typedef char					TOrderStateType;
//ָ��ʧ��
const TOrderStateType			ORDER_STATE_FAIL				= '0';
//������
const TOrderStateType			ORDER_STATE_ACCEPT				= '1';
//�ѹ���
const TOrderStateType			ORDER_STATE_SUPPENDED			= '2';
//���Ŷ�
const TOrderStateType			ORDER_STATE_QUEUED				= '3';
//������(�Ŷ���ʱ״̬)
const TOrderStateType			ORDER_STATE_DELETEING			= '4';
//���޸�(�Ŷ���ʱ״̬)
const TOrderStateType			ORDER_STATE_MODIFYING			= '5';
//���ֳ���
const TOrderStateType			ORDER_STATE_PARTDELETED			= '6';
//��ȫ����
const TOrderStateType			ORDER_STATE_DELETED				= '7';
//���ֳɽ�
const TOrderStateType			ORDER_STATE_PARTFINISHED		= '8';
//��ȫ�ɽ�
const TOrderStateType			ORDER_STATE_FINISHED			= '9';

///////////////////////////////////////////////////////////////////////////
//ί�гɽ�ɾ�����
typedef char					TDeletedType;
//��
const TDeletedType				DEL_YES							= 'Y';
//��
const TDeletedType				DEL_NO							= 'N';
//����
const TDeletedType				DEL_DISAPPEAR					= 'D';

///////////////////////////////////////////////////////////////////////////
//�ɽ���ʽ
typedef char					TMatchWayType;
//����
const char						MATCH_WAY_ALL					= 'A';
//�������ӵ�
const char						MATCH_WAY_SELF_ETRADER			= 'E';
//������ӵ�
const char						MATCH_WAY_PROXY_ETRADER			= 'P';
//�ⲿ���ӵ�(�ⲿ����ϵͳ�µ�����ϵͳ¼��)
const char						MATCH_WAY_JTRADER				= 'J';
//�˹�¼�뵥(�ⲿ������ʽ�µ�����ϵͳ¼��)
const char						MATCH_WAY_MANUAL				= 'M';
//carry��
const char						MATCH_WAY_CARRY					= 'C';
//���
const char						MATCH_WAY_DELIVERY				= 'D';
//��ʽ����
const char						MATCH_WAY_PROGRAM				= 'S';

///////////////////////////////////////////////////////////////////////////
//�ɽ���ʽ����
typedef char					TMatchModeType;
//����
const TMatchModeType			MATCH_MODE_NORMAL				= 'N';
//����ί��
const TMatchModeType			MATCH_MODE_UPDATE				= 'U';
//����
const TMatchModeType			MATCH_MODE_OTHER				= 'O';

///////////////////////////////////////////////////////////////////////////
//T+1�ɽ�
typedef char					TAddOneType;
//T+1�ɽ�
const TAddOneType				ADD_ONE_YES						= 'Y';
//��T+1�ɽ�
const TAddOneType				ADD_ONE_NO						= 'N';



//////////////////////////�ʽ�//////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
//���ұ������
typedef char					TCurrencyNoType[11];
//������������
typedef char					TCurrencyNameType[21];

/////////////////////////////////////////////////////////////////////////////////
//�Ƿ��������
typedef char					TIsPrimaryCurrencyType;
//�ǻ���
const TIsPrimaryCurrencyType	CURRENCY_PRIMARY_YES			= 'Y';
//���ǻ���
const TIsPrimaryCurrencyType	CURRENCY_PRIMARY_NO			= 'N';

/////////////////////////////////////////////////////////////////////////////////
//�Ƿ����������ֹ������(�����ʾ�ǵ�ǰ���ֽ���Ʒ��Ҳ����ռ�õ�ǰ�����ʽ���н���)
typedef char					TIsShareCurrencyType;
//����������
const TIsShareCurrencyType		CURRENCY_SHARE_YES				= 'Y';
//�ǹ���������
const TIsShareCurrencyType		CURRENCY_SHARE_NO				= 'N';

/////////////////////////////////////////////////////////////////////////////////
//����(1��ǰ���һ�����ٻ���)
typedef double					TExchangeRateType;

/////////////////////////////////////////////////////////////////////////////////
//�Ƿ�����ϼ�ֵ
typedef char					TContainTotleType;
//����
const TContainTotleType			ContainTotle_Yes			= 'Y';
//������
const TContainTotleType			ContainTotle_No				= 'N';

///////////////////////////////////////////////////////////////////////////
//���б�ʶ
typedef char					TBankType[3];
//��������
typedef char					TBankNameType[21];
//�����˺�
typedef char					TAccountType[51];

///////////////////////////////////////////////////////////////////////////
//����ұ�ʶ
typedef char					TLWFlagType;
//����������˻�
const TLWFlagType				LWFlag_L						= 'L';
//�ͻ���������˻�
const TLWFlagType				LWFlag_W						= 'W';
//��˾��������˻�
const TLWFlagType				LJFFlag_J						= 'J';
//��˾��������˻�
const TLWFlagType				LJFFlag_F						= 'F';

///////////////////////////////////////////////////////////////////////////
//��֤����㷽ʽ
typedef char					TDepositModeType;
//����
const TDepositModeType			DEPOSIT_MODE_B					= '1';
//����
const TDepositModeType			DEPOSIT_MODE_D					= '2';
//��ֵ����
const TDepositModeType			DEPOSIT_MODE_CB					= '3';
//��ֵ����
const TDepositModeType			DEPOSIT_MODE_CD					= '4';
//�ۿ�
const TDepositModeType			DEPOSIT_MODE_Z					= '5';

///////////////////////////////////////////////////////////////////////////
//�������ˮ������
typedef int						TCashSerialIdType;
//�ʽ������ˮ������
typedef int						TAdjustSerialIdType;

///////////////////////////////////////////////////////////////////////////
//���������
typedef char					TCashTypeType;
//����
const TCashTypeType				CASH_TYPE_OUT					= 'O';
//���
const TCashTypeType				CASH_TYPE_IN					= 'I';

//�����״̬
typedef char					TCashStateType;
//δ���
const TCashStateType			CASH_STATE_NOT_CHECK			= 'N';
//�����
const TCashStateType			CASH_STATE_CHECK				= 'Y';
//���δͨ��
const TCashStateType			CASH_STATE_FAIL					= 'F';

///////////////////////////////////////////////////////////////////////////
//�����ʽ
typedef char					TCashModeType;
//ת��
const TCashModeType				CASH_MODE_A						= 'A';
//֧Ʊ
const TCashModeType				CASH_MODE_B						= 'B';
//�ֽ�
const TCashModeType				CASH_MODE_C						= 'C';
//����
const TCashModeType				CASH_MODE_E						= 'E';

///////////////////////////////////////////////////////////////////////////
//�����ע
typedef char					TCashRemarkType[101];

//�ʽ����״̬
typedef char					TAdjustStateType;
//δ���
const TAdjustStateType			ADJUST_STATE_NOT_CHECK			= 'N';
//�����
const TAdjustStateType			ADJUST_STATE_CHECK				= 'Y';
//���δͨ��
const TAdjustStateType			ADJUST_STATE_FAIL				= 'F';

///////////////////////////////////////////////////////////////////////////
//�ʽ������������
typedef char					TAdjustTypeType;

///////////////////////////////////////////////////////////////////////////
//�ʽ�仯�ֶ�����(�ӵ�λ����λ,ÿλ��Ӧһ���仯�ֶ�)
typedef unsigned int			TMoneyChgType;
//�ʽ����                                                                 
const TMoneyChgType				MONEY_CHG_ADJUST				= 0x00000001;
//���                                                                     
const TMoneyChgType				MONEY_CHG_CASHIN				= 0x00000002;
//����                                                                     
const TMoneyChgType				MONEY_CHG_CASHOUT   			= 0x00000004;
//������                                                                   
const TMoneyChgType				MONEY_CHG_FEE					= 0x00000008;
//�����ʽ�                                                                 
const TMoneyChgType				MONEY_CHG_FROZEN				= 0x00000010;
//���ƽӯ                                                                 
const TMoneyChgType				MONEY_CHG_COVERPROFIT			= 0x00000020;
//����ƽӯ                                                                 
const TMoneyChgType				MONEY_CHG_DAYCVERPROFIT		= 0x00000040;
//��ʸ�ӯ                                                                 
const TMoneyChgType				MONEY_CHG_FLOATPROFIT			= 0x00000080;
//���и�ӯ                                                                 
const TMoneyChgType				MONEY_CHG_DAYFLOATPROFIT		= 0x00000100;
//δ��ƽӯ                                                                 
const TMoneyChgType				MONEY_CHG_UNEXPIREDPROFIT		= 0x00000200;
//Ȩ����                                                                   
const TMoneyChgType				MONEY_CHG_PREMIUM				= 0x00000400;
//��֤��                                                                   
const TMoneyChgType				MONEY_CHG_DEPOSIT				= 0x00000800;
//ά�ֱ�֤��                                                               
const TMoneyChgType				MONEY_CHG_KEEPDEPOSIT			= 0x00001000;
//��Ѻ�ʽ�                                                                 
const TMoneyChgType				MONEY_CHG_PLEDGE				= 0x00002000;
//�����ʽ�                                                                 
const TMoneyChgType				MONEY_CHG_TAVAILABLE			= 0x00004000;

#endif
