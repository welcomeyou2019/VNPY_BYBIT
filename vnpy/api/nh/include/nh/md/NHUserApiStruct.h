/*************************
*ժҪ���ϻ��ڻ�����ϵͳ
*�ļ���NhUserApiStruct.h
*      �����˿ͻ��˽ӿ����ݽṹ
*���ߣ��ϻ��ڻ������
*ʱ�䣺20100220
**************************/

#ifndef __NH_USERAPI_STRUCT_H__
#define __NH_USERAPI_STRUCT_H__

#include "NHUserApiDataType.h"

#include <iostream>

using namespace std;


struct STKMarketData_t //��ʱ���ݽṹ
{
	TDateType trading_day;							//�����գ����������ݡ�������
	TTimeType update_time;							//������ʱ��
	TMillisecType	update_millisec;					//����޸ĺ���
	TSequenceIDType	update_sequence;					//���ո������

	TContractNoType instrument_id;					//��Լ����
	TExchangeNoType exchange_id;						//����������
	TContractNoType exchange_inst_id;					//��Լ�ڽ������Ĵ���
	TContractTradeStateType instrument_status;			//��Լ����״̬

	TPriceType last_price;							//���¼�
	TVolumeType volume;								//�ɽ������ڻ�ȫ����������Ʊ��С��
	TVolumeType last_volume;							//���³ɽ���
	TMoneyType turnover;								//�ɽ����
	TVolumeType open_interest;						//�ֲ���
	TPriceType open_price;							//���տ��̼�
	TPriceType highest_price;						//������߼�
	TPriceType lowest_price;							//������ͼ�
	TPriceType close_price;							//�������̼�
	TPriceType settlement_price;						//���ս����
	TPriceType average_price;						//���վ���

	TPriceType change_price;							//�ǵ�
	TRangeType change_markup;						//�ǵ���
	TRangeType change_swing;							//���

	TPriceType upper_limit_price;						//��ͣ���
	TPriceType lower_limit_price;						//��ͣ���

	TPriceType pre_settlement_price;					//���ս����
	TPriceType pre_close_price;						//�������̼�
	TVolumeType pre_open_interest;					//���ճֲ���

	TDeltaType pre_delta;							//����ʵ��
	TDeltaType curr_delta;							//����ʵ��

	TPriceType	best_ask_price;							//��������
	TVolumeType	best_ask_volume;					//��������
	TPriceType	best_bid_price;							//�������
	TVolumeType	best_bid_volume;				//��������

	TPriceType	ask_price1;								//������1
	TVolumeType	ask_volume1;						//������1
	TPriceType	bid_price1;								//�����1
	TVolumeType	bid_volume1;						//������1
	TPriceType	ask_price2;								//������2
	TVolumeType	ask_volume2;						//������2
	TPriceType	bid_price2;								//�����2
	TVolumeType	bid_volume2;						//������2
	TPriceType	ask_price3;								//������3
	TVolumeType	ask_volume3;						//������3
	TPriceType	bid_price3;								//�����3
	TVolumeType	bid_volume3;						//������3
	TPriceType	ask_price4;								//������4
	TVolumeType	ask_volume4;						//������4
	TPriceType	bid_price4;								//�����4
	TVolumeType	bid_volume4;						//������4
	TPriceType	ask_price5;								//������5
	TVolumeType	ask_volume5;						//������5
	TPriceType	bid_price5;								//�����5
	TVolumeType	bid_volume5;						//������5
	TPriceType	ask_price6;								//������6
	TVolumeType	ask_volume6;						//������6
	TPriceType	bid_price6;								//�����6
	TVolumeType	bid_volume6;						//������6
	TPriceType	ask_price7;								//������7
	TVolumeType	ask_volume7;						//������7
	TPriceType	bid_price7;								//�����7
	TVolumeType	bid_volume7;						//������7
	TPriceType	ask_price8;								//������8
	TVolumeType	ask_volume8;						//������8
	TPriceType	bid_price8;								//�����8
	TVolumeType	bid_volume8;						//������8
	TPriceType	ask_price9;								//������9
	TVolumeType	ask_volume9;						//������9
	TPriceType	bid_price9;								//�����9
	TVolumeType	bid_volume9;						//������9
	TPriceType	ask_price10;								//������10
	TVolumeType	ask_volume10;						//������10
	TPriceType	bid_price10;								//�����10
	TVolumeType	bid_volume10;						//������10
	TMdSourceType	md_source;						//������Դ
};


//������Ϣ�ṹ
typedef struct ERRORMSGINFO
{
	TErrorCodeType error_code;			//�������
	TErrorMessageType error_message;		//������Ϣ
	/*����ô������ɷ�������Ϣ����ģ��������ֶζ�Ӧ������������Ϣ*/
	TRspCodeType response_code;			//��Ӧ����, 0Ϊ�ɹ�������Ϊ�������1Ϊ���һ��
	TRspStringType response_string;		//��Ӧ�ı���Ϣ
	TServerIDType utp_server_id;			    //���������UTP��������Ϣ
	TServerIDType oms_server_id;			//���������OMS��������Ϣ
}ERRORMSGINFO_t;

//��¼�ϻ�ͳһ����ƽ̨UTP����ṹ
typedef struct ReqUtpLoginField
{
	TDevelopCodeType developer_code;				//�����߱���(����)
	TDevelopLicenseType developer_license;			//��������Ȩ(����)
	TUserIDType user_id;							//��¼�û�(����)
	TPassWordType user_password;					//��¼��̬���룬ʹ�þ�̬publickey����
	TOneTimePassWordType user_one_time_password;	//��̬����
	TCAInfoType	user_ca_info;						//ca��֤��Ϣ
}ReqUtpLoginField_t;

//��¼�ϻ�ͳһ����ƽ̨UTPӦ��ṹ
typedef struct RspUtpLoginField 
{
	TRspCodeType response_code;				//��Ӧ����, 0Ϊ�ɹ���-1��̬�������-2��̬�������-3ca��֤����-4������OTP��¼��-5������CA��¼��-6�ص���ϢQ�����ڣ�-7���������ϣ�-8��ʧ��
	TRspStringType response_string;			//��Ӧ��Ϣ
	TPublicKeyType session_public_key;		//����������ĻỰ���ܹ�Կ������������Ϣ��Ҫ���ܺ���
	TServerCDKeyType utp_checking_server_id;	//��֤������ʶ����
	TLongTimeType	utp_checking_server_time;	//��֤������ʱ�䣬long��ʽ
	TIpType last_login_ip_address;		//�ϴε�¼��ԴIP
	TLongTimeType last_login_time;			//�ϴε�¼ʱ��
	TIsEncryptType session_encrypted;			//�Ƿ���ܴ���ͨ��
}RspUtpLoginField_t;


//�ǳ��ϻ�ͳһ����ƽ̨UTPӦ��ṹ
typedef struct RspUtpLogoutField
{
	TRspCodeType response_code;		//��Ӧ����, 0Ϊ�ɹ�������Ϊ�������1Ϊ���һ��
	TRspStringType response_string;	//��Ӧ�ı���Ϣ
	TServerIDType utp_server_id;		//���������UTP��������Ϣ
}RspUtpLogoutField_t;


/* ����������������ṹ
	*	routing_key:���Ĺ���,����������£�
	*			 ������.Ʒ�ִ���.��Լ����
	*			 ����������Ϊ��B:������;G:�н���;D:������;C:֣����
	*						 �磺G.IF.1203:Ϊ�н���12��3�¹�ָ�ڻ���������
	*			 ��Ʒ����Ϊ���ڻ���Ӧ���ڻ���Լ���룬��Сд���У����У�
	*						�������ʹ�����Ʒ�ִ�����Сд;
	*						�н�����֣����Ʒ�ִ������д
	*			����û�ʡ��ĳһ���֣���ϵͳĬ�϶���ȫ����
	*						 �磺G.IF.�����н���Ʒ�ִ���ΪIF�����й�ָ�ڻ���������
	*						 �磺B.����������������������
	*			����û�ͨ��ʡ�Եķ�ʽ������ĳһ������ȫ����Լ���������"."�������ҽ���������ʡ�ԡ�
	*			�����û�����ͨ��"."���������н������ĺ�Լ���ݡ�
	*/
typedef struct ReqSubscribeField
{
	TRouteKeyType  routing_key;		//���Ĺ���ÿ����ඩ��100��
}ReqSubscribeField_t;

//������������Ӧ��ṹ
typedef struct RspSubscribeField 
{
	TRspCodeType	response_code;	//��Ӧ����, 0Ϊ�ɹ�������Ϊ�������
	TRspStringType	response_string;	//�ɹ����ĵ���Ϣ
	TServerIDType	utp_server_id;
	TRouteKeyType	routing_key;		//���ĳɹ�����Ϣ
}RspSubscribeField_t;

//ȡ������������������ṹ
typedef struct ReqUnSubscribeField
{
	TRouteKeyType  routing_key;			//���Ĺ���ÿ�����ȡ��100��
}ReqUnSubscribeField_t;

//ȡ��������������Ӧ��ṹ
typedef struct RspUnSubscribeField 
{
	TRspCodeType	response_code;		//��Ӧ����, 0Ϊ�ɹ�������Ϊ�������
	TRspStringType	response_string;		//��Ӧ�ı���Ϣ
	TServerIDType	utp_server_id;
	TRouteKeyType	routing_key;			//ȡ���ɹ��Ķ�����Ϣ
}RspUnSubscribeField_t;

//�û���֤��������ṹ
typedef struct ReqAuthUserPassworField
{
	TUserIDType user_id;							//�û���
	TPassWordType password;				//����
	TSaveIntType save_int;						//�����ֶ�
	TSaveDoubleType save_double;		//�����ֶ�
	TSaveStringType save_string;			//�����ֶ�
}ReqAuthUserPassworField_t;

//�û���֤����Ӧ��ṹ
typedef struct RspAuthUserPassworField 
{
	TRspCodeType response_code;		//��Ӧ����, 0Ϊ�ɹ�������Ϊ�������
	TRspStringType response_string;	//��Ӧ�ı���Ϣ
}RspAuthUserPassworField_t;

//��������
typedef struct ReqOrderInsertData 
{
	TClientNoType client_id;							//�ͻ���
	TCommodityNoType commodity_id;		//��Ʒ����
	TContractNoType instrument_id;				//��Լ����
	TOrderTypeType order_type;					//ί������
	TOrderModeType order_mode;				//ί��ģʽ
	TOrderWayType order_way;					//ί�з�ʽ
	TDateType valid_datetime;						//��Ч����(GTD�����ʹ��)
	TIsRiskOrderType is_riskorder;				//���ձ���
	TDirectType direct;									//��������
	TOffsetType offset;									//����ƽ��:N:��,O:����,C:ƽ��,T:ƽ��,
	THedgeType hedge;									//Ͷ����ֵ:N:��,T:Ͷ��,B:��ֵ
	TPriceType order_price;							//ί�м۸�
	TPriceType trigger_price;							//�����۸�
	TVolumeType order_vol;						//ί������
	TVolumeType min_matchvol;				//��С�ɽ���
	TSaveIntType save_int;								//�ͻ������ֶ�1
	TSaveDoubleType save_double;				//�ͻ������ֶ�2
	TSaveStringType save_string;					//�ͻ������ֶ�3
}ReqOrderInsertData_t;

//��������
typedef struct ReqOrderInsertField 
{
	TServerIDType oms_server_id;			//OMS����
	TExchangeNoType exchange_id;			//����������
	ReqOrderInsertData req_data;				    //��������
}ReqOrderInsertField_t;

//����Ӧ��
typedef struct RspOrderInsertField 
{
	TRspCodeType response_code;			//��Ӧ����, 0Ϊ�ɹ���1Ϊ���һ��
	TRspStringType response_string;		//��Ӧ�ı���Ϣ
	TServerIDType utp_server_id;				//���������UTP��������Ϣ
	TServerIDType oms_server_id;			//���������OMS��������Ϣ
	TStreamIdType order_stream_id;		//ί������
	TOrderIdType order_id;						//ί�к�
	TLocalNoType local_id;							//���غ�
	TClientNoType trade_id;							//�����˺�
	TClientNoType insert_id;						//�µ���
	TDateTimeType insert_datetime;		//�µ�ʱ��
	TOrderStateType order_state;				//ί��״̬
	ReqOrderInsertData req_data;					//��������
}RspOrderInsertField_t;

//��ѯ����������ṹ
typedef struct ReqQryExchangeField
{
	TServerIDType oms_server_id;		//OMS����
}ReqQryExchangeField_t;

//��ѯ������Ӧ��ṹ
typedef struct RspQryExchangeField 
{
	TRspCodeType response_code;			//��Ӧ����, 0Ϊ�ɹ�������Ϊ�������
	TRspStringType response_string;		//��Ӧ�ı���Ϣ
	TServerIDType utp_server_id;			//���������UTP��������Ϣ
	TServerIDType oms_server_id;			//���������OMS��������Ϣ
	TExchangeNoType exchange_id;			//����������
	TExchangeNameType exchange_name;		//����������
	TExchangeStateType exchange_status;	//������״̬
}RspQryExchangeField_t;

//��ѯ��Լ����ṹ
typedef struct ReqQryInstrumentField 
{
	TServerIDType oms_server_id;		//OMS����
	TExchangeNoType exchange_id;		//����������
	TCommodityNoType product_id;		//��Ʒ����
	TContractNoType instrument_id;	//��Լ����
	TCommodityTypeType product_class;	//��Ʒ����:(Ĭ��ΪF:COMMODITY_TYPE_FUTURE)
}ReqQryInstrumentField_t;

//��ѯ��ԼӦ��ṹ
typedef struct RspQryInstrumentField 
{
	TRspCodeType response_code;		//��Ӧ����, 0Ϊ�ɹ�������Ϊ�������
	TRspStringType response_string;	//��Ӧ�ı���Ϣ
	TServerIDType utp_server_id;			//���������UTP��������Ϣ
	TServerIDType oms_server_id;			//���������OMS��������Ϣ
	TCommodityNoType product_id;			//��Ʒ����
	TCommodityNameType product_name;			//��Ʒ����
	TExchangeNoType exchange_id;			//����������
	TCommodityTypeType product_class;			//��Ʒ����
	TContractNoType instrument_id;			//��Լ����
	TContractNameType instrument_name;		//��Լ����
	TContractTypeType instrument_class;		//��Լ���
	TContractStateType instrument_status;		//��Լ״̬
	TYearType	delivery_year;			//�������
	TMonthType	delivery_month;			//�����·�
	TProductDotType volume_multiple;		//��Լ����
	TUpperTickType price_tick;			//��С�䶯��λ
	TLowerTickType price_tick_dividend;	//��С�䶯��λ��ĸ��һ��Ϊ1����������ʱ��Ϊ1
	TVolumeType max_marketorder_volume;	//�м۵�����µ���
	TVolumeType min_marketorder_volume;	//�м۵���С�µ���
	TVolumeType max_limitorder_volume;	//�޼۵�����µ���
	TVolumeType min_limitorder_volume;	//�޼۵���С�µ���
	TDateType create_date;			//������
	TDateType open_date;				//������
	TDateType expire_date;			//������
	TDateType last_trading_date;		//�������
	TDateType start_delivery_date;	//��ʼ������
	TDateType end_delivery_date;		//����������
	TDateType first_notice_date;		//�״�֪ͨ��
}RspQryInstrumentField_t;

#endif
