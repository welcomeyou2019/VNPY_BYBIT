/*************************
*ժҪ���ϻ��ڻ�����ϵͳ
*�ļ���NhUserApiErrCode.h
*      �����˿ͻ��˽ӿڴ�����
*���ߣ��ϻ��ڻ������
*ʱ�䣺20100220
**************************/

#ifndef __NH_USERAPI_ERRCODE_H__
#define __NH_USERAPI_ERRCODE_H__

#include "NHUserApiDataType.h"

///////////////////////////////////////////////////////////////////////////
//δ֪����
const TErrorCodeType Err_Unknown									= -1;
//�ɹ�
const TErrorCodeType Err_Succeed									= 0;
//��ʱ
const TErrorCodeType Err_TimeOut									= 10;
//���յ������ݸ�ʽ����
const TErrorCodeType Err_ReceiveMsg								= 11;
//�������ﵽ���ֵ
const TErrorCodeType Err_ConnectNum								= 12;
//�������ݳ���
const TErrorCodeType Err_SendData									= 13;
//����δ����
const TErrorCodeType Err_DisConnect								= 14;
//ԭʼ�����ѳ�ʱ
const TErrorCodeType Err_Request_TimeOUt					= 15;
//�û��ѵ�¼
const TErrorCodeType Err_User_Login								= 16;
//�û�δ��¼
const TErrorCodeType Err_User_Not_Login							= 17;
//����ȱ�ٱ����ֶ�
const TErrorCodeType Err_Param_Necess								= 18;
//��ѯ��Ϣʧ��
const TErrorCodeType Err_Query_Failed								= 19;

#endif
