
#ifndef __DC_API_ERRCODE_H__
#define __DC_API_ERRCODE_H__

///////////////////////////////////////////////////////////////////////////
//�ɹ�
const int Err_Success									= 0;
//��ʾ��������������ʧ��
const int Err_DisConnect							=-1;
//��ʾ������δ�������󳬹������
const int Err_Untreated_Request				=-2;									
//��ʾ������ÿ�뷢�����������������
const int Err_PreSecond_Request			=-3;
//��ʾ������������δ��¼�ɹ�
const int Err_Exchange_Not_Login			=3;
//�û�δ��¼
const int Err_User_Not_Login					=4;
//�Ǳ�������API��¼
const int Err_Version =5;
//API�汾��Ϣ����
const int Err_ApiVersion =6;
//ϵͳ���ڳ�ʼ��
const int Err_System_Init =7;
//�ظ��ĵ�¼
const int Err_RepeatLogin =8;
//�����
const int Err_PassWord =9;
//�û�δ�ҵ�
const int Err_UserNotExist=10;
//��������ʧ��
const int Err_Update_Pwd_Failed = 12;
//��������ʧ��
const int Err_Create_Pwd_Failed		= 13;
//��ѯ��Ϣʧ��
const int Err_Query_Failed		= 14;
//����ʱδ�ҵ�ԭʼ����
const int Err_DelOrder_Err1		= 16;
//�����ڷ���������֮ǰ������
const int Err_DelOrder_Err2		= 17;
//����״̬Ϊ�ѳ���״̬���ɳ���
const int Err_DelOrder_Err3		= 18;
//����״̬Ϊȫ���ɽ�״̬���ɳ���
const int Err_DelOrder_Err4		= 19;
//����Ϊ�����ɳ���
const int Err_DelOrder_Err5		= 20;
//����ʱԭʼ����Ϊ���ɳ���״̬
const int Err_DelOrder_Err6		= 21;
//�ظ��ı���
const int Err_Order_Err1		= 22;
//����ʱδ�ҵ���Ӧ�ĺ�Լ��Ϣ
const int Err_Order_Err2		= 23;
//����ʱ���������ֶδ���
const int Err_Order_Err3		= 24;
//����ʱ��Ч�������ֶδ���
const int Err_Order_Err4		= 25;
//����ʱ�۸��ֶδ���
const int Err_Order_Err5		= 26;
//����ʱ�����ֶδ���
const int Err_Order_Err6		= 27;
//�����۸���������
const int Err_Order_Err7		= 28;
//����ʱδ��ȡ���ͻ���Ӧ���ʽ���Ϣ
const int Err_Order_Err8		= 29;
//����ʱ�ʽ���
const int Err_Order_Err9		= 30;
//���ܳ��������ͻ�����
const int Err_Order_Err11	= 32;
//����ʱ�۸���Ϣ��������С��λ�䶯Ҫ��
const int Err_Order_Err12	= 33;
//����ʱ������Ϣ��������С�����䶯Ҫ��
const int Err_Order_Err13	= 34;
//�м۵�������ϵͳҪ��
const int Err_Order_Err14	= 35;
//�û���Ϣ��֤ʧ��
const int Err_UserInfo_Failed = 36;
//����������Ự��Ϣʧ��
const int Err_Create_Session			=37;
//���ڹ��Ƚ�����Ϊ
const int Err_Excessive_Trading			=38;
//��������Ϊ
const int Err_Large_Del			=39;
//Ƶ��������Ϊ
const int Err_Frequent_Del			=40;
//��󽻸��յĺ�Լ��������
const int Err_EndDelivDate			=41;
//Ͷ���ױ���Ǵ���
const int Err_Order_Err15	= 42;
//��ƽ��־����
const int Err_Order_Err16	= 43;
//�����������
const int Err_Order_Err17	= 44;
//�����۸���������
const int Err_Order_Err18	= 45;
//��Ч�����ʹ���
const int Err_Order_Err19	= 46;
//�ɽ������ʹ���
const int Err_Order_Err20	= 47;
//������������
const int Err_Order_Err21	= 48;
//��ǰ״̬��ֹ�������
const int Err_Order_Err22	= 49;
//ƽ��ʱ�ͻ��ֲֲ���
const int Err_Order_Err23	= 50;
//�۸񳬳���ͣ��
const int Err_Order_Err24	= 51;
//�۸���Ƶ�ͣ��
const int Err_Order_Err25	= 52;
//������־����
const int Err_Order_Err26	= 53;
//��֧�ָý����������������ֶβ���ȷ
const int Err_Order_Err27	= 54;
//��ȡ�ͻ������ӵ�ַ��Ϣʱ����
const int Err_Order_Err55 = 55;
//��Լ���Ͳ���
const int Err_Order_Err56 = 56;
//����ֻ������������ƽ
const int Err_Order_Err57 = 57;
//���ҿ���ʱ��ĺ�Լ�ֲֲ���
const int Err_Order_Err58 = 58;
//���뽻����ʱ��̫�̲����������
const int Err_Order_Err59 = 59;
//��ϻ��ֱ�־��
const int Err_Order_Err60 = 60;
//��֧�ָ���ϲ���
const int Err_Order_Err61 = 61;
//��֧����Ȩ����
const int Err_Order_Err63 = 63;

#endif
