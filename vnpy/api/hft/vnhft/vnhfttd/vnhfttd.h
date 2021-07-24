//ϵͳ
#ifdef WIN32
#include "pch.h"
#endif

#include "vnhft.h"
#include "pybind11/pybind11.h"
#include "hft/hft_trader_api.h"


using namespace pybind11;
using namespace HFT;



///-------------------------------------------------------------------------------------
///C++ SPI�Ļص���������ʵ��
///-------------------------------------------------------------------------------------

//API�ļ̳�ʵ��
class TdApi : public TraderSpi
{
private:
	TraderApi* api;            //API����
    bool active = false;       //����״̬

public:
    TdApi()
    {
    };

    ~TdApi()
    {
        if (this->active)
        {
            this->exit();
        }
    };

    //-------------------------------------------------------------------------------------
    //API�ص�����
    //-------------------------------------------------------------------------------------

	/**
	 * ���ӶϿ�ʱ�ص�
	 */
	virtual void OnDisconnect();

	/**
	 * ������Ϣ�ص���ϵͳ����ʱ�Ż�ص�
	 *
	 * @param error_info    ������Ϣ
	 * @param request_id    ��Ӧ����ʱ��������кţ�����������󴥷��Ĵ��󣬴��ֶ�ֵΪ0
	 */
	virtual void OnError(ErrorInfo* error_info, int request_id = 0);

	/**
	 * ��ظ澯��Ϣ֪ͨ�ص�
	 *
	 * @param risk_notify   ��ظ澯��Ϣ
	 */
	virtual void OnRiskNotify(RiskNotify* risk_notify);

	/**
	 * ��¼�ɹ���ʧ��ʱ�ص�
	 *
	 * @param rsp           ��¼Ӧ�����ݣ������ͻ��š��ͻ��������ɶ��������Ϣ
	 * @param error_info    ������Ϣ
	 */
	virtual void OnLogin(LoginRsp* rsp, ErrorInfo* error_info);

	/**
	 * �ɽ��ر��ص�
	 *
	 * @param trade_detail  �ص��ĳɽ��������
	 */
	virtual void OnTradeReport(TradeDetail* trade_detail);

	/**
	 * ����״̬�仯�ص�
	 *
	 * @param order_detail  �ص��Ķ�������
	 */
	virtual void OnOrderStatus(OrderDetail* order_detail);

	/**
	 * ����ί�е���Ӧ
	 *
	 * @param order_rsp     ����ί��Ӧ��
	 * @param error_info    Ӧ��Ĵ�����Ϣ
	 * @param request_id    ��Ӧ����ʱ��������к�
	 * @param is_last       �Ƿ��Ǳ�����������һ����Ӧ
	 */
	virtual void OnOrderRsp(OrderRsp* order_rsp, ErrorInfo* error_info,
		int request_id, bool is_last);

	/**
	 * ��������Ӧ
	 *
	 * @param cancel_rsp    ����Ӧ��
	 * @param error_info    Ӧ��Ĵ�����Ϣ
	 * @param request_id    ��Ӧ����ʱ��������к�
	 * @param is_last       �Ƿ��Ǳ�����������һ����Ӧ
	 */
	virtual void OnCancelRsp(CancelRsp* cancel_rsp, ErrorInfo* error_info,
		int request_id, bool is_last);

	/**
	 * ��ѯ���ն����������Ӧ��һ�η���һ����������
	 * QueryOrder��QueryOrderByCode��QueryOrders���ɴ˽ӿ���Ӧ
	 *
	 * @param order_detail  ��������
	 * @param error_info    Ӧ��Ĵ�����Ϣ
	 * @param request_id    ��Ӧ����ʱ��������к�
	 * @param is_last       �Ƿ��Ǳ�����������һ����Ӧ
	 * @param pos_str       ���β�ѯ���һ����¼�Ķ�λ����������һ�β�ѯ
	 */
	virtual void OnQueryOrderRsp(OrderDetail* order_detail,
		ErrorInfo* error_info, int request_id,
		bool is_last, const char* pos_str);

	/**
	 * ��ѯ���ճɽ��������Ӧ��һ�η���һ���ɽ�����
	 * QueryTradeByCode��QueryTradeByOrderId��QueryTrades��QueryETFTrades���ɴ˽ӿ���Ӧ
	 *
	 * @param trade_detail  �ɽ�����
	 * @param error_info    Ӧ��Ĵ�����Ϣ
	 * @param request_id    ��Ӧ����ʱ��������к�
	 * @param is_last       �Ƿ��Ǳ�����������һ����Ӧ
	 * @param pos_str       ���β�ѯ���һ����¼�Ķ�λ����������һ�β�ѯ
	 */
	virtual void OnQueryTradeRsp(TradeDetail* trade_detail,
		ErrorInfo* error_info, int request_id,
		bool is_last, const char* pos_str);

	/**
	 * ��ѯ���ճֲ��������Ӧ��һ�η���һ���ֲ�����
	 * QueryPosition��QueryPositions�ɴ˽ӿ���Ӧ
	 *
	 * @param position_detail   �ֲ�����
	 * @param error_info        Ӧ��Ĵ�����Ϣ
	 * @param request_id        ��Ӧ����ʱ��������к�
	 * @param is_last           �Ƿ������һ����Ӧ
	 * @param pos_str           ���β�ѯ���һ����¼�Ķ�λ����������һ�β�ѯ
	 */
	virtual void OnQueryPositionRsp(PositionDetail* position_detail,
		ErrorInfo* error_info, int request_id,
		bool is_last, const char* pos_str);

	/**
	 * ��ѯ�����ʽ����Ӧ
	 *
	 * @param cash_detail   �ʽ�����
	 * @param error_info    Ӧ��Ĵ�����Ϣ
	 * @param request_id    ��Ӧ����ʱ��������к�
	 */
	virtual void OnQueryCashRsp(CashDetail* cash_detail, ErrorInfo* error_info,
		int request_id);

	/**
	 * �鼯�н���ϵͳ�����ʽ�
	 *
	 * @param avail_balance �����ʽ𣬵�λ�������
	 * @param error_info    Ӧ��Ĵ�����Ϣ
	 * @param request_id    �������кţ�����ƥ����Ӧ�����û��Զ��壬��0
	 */
	virtual void OnQueryJZJYAvailFundRsp(int64_t avail_balance,
		ErrorInfo* error_info,
		int request_id);

	/**
	 * ���н��׹�̨����ٹ�̨֮���ʽ�ת��ת��
	 *
	 * @param transfer_value    ��ת���
	 * @param error_info        Ӧ��Ĵ�����Ϣ
	 * @param request_id        �������кţ�����ƥ����Ӧ�����û��Զ���
	 */
	virtual void OnTransferFundInAndOutRsp(int64_t transfer_value,
		ErrorInfo* error_info,
		int request_id);

	/**
	 * ���ͬһ���ʽ��˺ţ�һ������֮���ʽ�ת
	 *
	 * @param transfer_value    ��ת���
	 * @param error_info        Ӧ��Ĵ�����Ϣ
	 * @param request_id        �������кţ�����ƥ����Ӧ�����û��Զ���
	 */
	virtual void OnTransferFundBetweenSecuidRsp(int64_t transfer_value,
		ErrorInfo* error_info,
		int request_id);

	/**
	 * ��ѯETF������Ϣ����Ӧ��ÿ�η���һ��ETF��Ϣ
	 *
	 * @param etf_detail    ETF������Ϣ����
	 * @param error_info    Ӧ��Ĵ�����Ϣ
	 * @param request_id    ��Ӧ����ʱ��������к�
	 * @param is_last       �Ƿ��Ǳ�����������һ����Ӧ
	 */
	virtual void OnQueryETFRsp(ETFDetail* etf_detail, ErrorInfo* error_info,
		int request_id, bool is_last);

	/**
	 * ��ѯһ��ETF��Ʊ���ӵ���Ӧ��ÿ�η���ETF��һ����Ʊ��Ϣ
	 *
	 * @param etf_stock_detail      ETF��һ����Ʊ��Ϣ
	 * @param error_info            Ӧ��Ĵ�����Ϣ
	 * @param request_id            ��Ӧ����ʱ��������к�
	 * @param is_last               �Ƿ��Ǳ�����������һ����Ӧ
	 */
	virtual void OnQueryETFStockRsp(ETFStockDetail* etf_stock_detail,
		ErrorInfo* error_info, int request_id,
		bool is_last);

	/**
	 * ��ѯ����ί�������ص�
	 *
	 * @param detail        ����ί����������
	 * @param error_info    Ӧ��Ĵ�����Ϣ
	 * @param request_id    �������кţ�����ƥ����Ӧ�����û��Զ��壬��0
	 */
	virtual void OnQueryMaxOrderQtyRsp(MaxOrderQtyDetail* detail,
		ErrorInfo* error_info, int request_id);

	/**
	 * ��ѯ�¹ɿ��깺��ȵ���Ӧ
	 *
	 * @param detail        �¹ɿ��깺�������
	 * @param error_info    Ӧ��Ĵ�����Ϣ
	 * @param request_id    ��Ӧ����ʱ��������к�
	 */
	virtual void OnQueryIPOMaxPurchaseRsp(IPOMaxPurchaseDetail* detail,
		ErrorInfo* error_info, int request_id,
		bool is_last);

	/**
	 * ��ѯ�¹ɵ���Ӧ
	 *
	 * @param detail        �¹�����
	 * @param error_info    Ӧ��Ĵ�����Ϣ
	 * @param request_id    ��Ӧ����ʱ��������к�
	 */
	virtual void OnQueryIPOStockRsp(IPOStockDetail* detail,
		ErrorInfo* error_info, int request_id,
		bool is_last);

	/**
	 * ��ѯ�¹���ŵ���Ӧ
	 *
	 * @param detail        �¹��������
	 * @param error_info    Ӧ��Ĵ�����Ϣ
	 * @param request_id    ��Ӧ����ʱ��������к�
	 * @param is_last       �Ƿ��Ǳ�����������һ����Ӧ
	 * @param pos_str       ���β�ѯ���һ����¼�Ķ�λ����������һ�β�ѯ
	 */
	virtual void OnQueryIPODistributionRsp(IPODistributionDetail* detail,
		ErrorInfo* error_info,
		int request_id, bool is_last,
		const char* pos_str);

	/**
	 * ��ѯ�¹���ǩ����Ӧ
	 *
	 * @param detail        �¹���ǩ����
	 * @param error_info    Ӧ��Ĵ�����Ϣ
	 * @param request_id    ��Ӧ����ʱ��������к�
	 * @param is_last       �Ƿ��Ǳ�����������һ����Ӧ
	 * @param pos_str       ���β�ѯ���һ����¼�Ķ�λ����������һ�β�ѯ
	 */
	virtual void OnQueryIPOLotteryRsp(IPOLotteryDetail* detail,
		ErrorInfo* error_info, int request_id,
		bool is_last, const char* pos_str);

	/**
	* ��ѯ֤ȯ��Ϣ����Ӧ
	*
	* @param detail            ֤ȯ��Ϣ
	* @param error_info        Ӧ��Ĵ�����Ϣ
	* @param request_id        ��Ӧ����ʱ��������к�
	* @param is_last           �Ƿ������һ����Ӧ
	*/
	virtual void OnQuerySecurityBaseInfoRsp(SecurityBaseInfo* detail, ErrorInfo* error_info,
		int request_id, bool is_last);

	/**
	 * ����Ʒת��ת��Ӧ��ص�
	 *
	 * @param rsp           ����Ʒת��ת��Ӧ��
	 * @param error_info    Ӧ��Ĵ�����Ϣ
	 * @param request_id    ��Ӧ����ʱ��������к�
	 */
	virtual void OnCreditMortgageInOutRsp(CreditMortgageInOutRsp* rsp,
		ErrorInfo* error_info,
		int request_id);

	/**
	 * ��ȯ��ȯӦ��ص�
	 *
	 * @param rsp           ��ȯ��ȯӦ��
	 * @param error_info    Ӧ��Ĵ�����Ϣ
	 * @param request_id    ��Ӧ����ʱ��������к�
	 */
	virtual void OnCreditStockBackRsp(CreditStockBackRsp* rsp,
		ErrorInfo* error_info, int request_id);

	/**
	 * ֱ�ӻ���Ӧ��ص�
	 *
	 * @param rsp           ֱ�ӻ���Ӧ��
	 * @param error_info    Ӧ��Ĵ�����Ϣ
	 * @param request_id    ��Ӧ����ʱ��������к�
	 */
	virtual void OnCreditPayBackRsp(CreditPayBackRsp* rsp,
		ErrorInfo* error_info, int request_id);

	/**
	 * ָ����Լֱ�ӻ���
	 *
	 * @param rsp           ������Ϣ
	 * @param error_info    Ӧ��Ĵ�����Ϣ
	 * @param request_id    �������кţ�����ƥ����Ӧ�����û��Զ���
	 */
	virtual void OnCreditPayBackByOrderRsp(CreditPayBackRsp* rsp,
		ErrorInfo* error_info,
		int request_id);

	/**
	 * ���ñ��ȯӦ��ص�
	 *
	 * @param detail        ���ñ��ȯ����
	 * @param error_info    Ӧ��Ĵ�����Ϣ
	 * @param request_id    ��Ӧ����ʱ��������к�
	 * @param is_last       �Ƿ��Ǳ�����������һ����Ӧ
	 * @param pos_str       ���β�ѯ���һ����¼�Ķ�λ����������һ�β�ѯ
	 */
	virtual void OnQueryCreditStockRsp(CreditStockDetail* detail,
		ErrorInfo* error_info, int request_id,
		bool is_last, const char* pos_str);

	/**
	 * ��ѯ����Ʒȯ�ص�
	 *
	 * @param detail        ����Ʒȯ��Ϣ
	 * @param error_info    Ӧ��Ĵ�����Ϣ
	 * @param request_id    �������кţ�����ƥ����Ӧ�����û��Զ��壬��0
	 * @param is_last       �Ƿ��Ǳ�����������һ����Ӧ
	 * @param pos_str       ���β�ѯ���һ����¼�Ķ�λ����������һ�β�ѯ
	 */
	virtual void OnQueryCreditMortgageHoldRsp(CreditMortgageHoldDetail* detail,
		ErrorInfo* error_info,
		int request_id, bool is_last,
		const char* pos_str);

	/**
	 * �����ʲ���ѯӦ��ص�
	 *
	 * @param detail        �����ʲ�����
	 * @param error_info    Ӧ��Ĵ�����Ϣ
	 * @param request_id    ��Ӧ����ʱ��������к�
	 */
	virtual void OnQueryCreditAssetsRsp(CreditAssetsDetail* detail,
		ErrorInfo* error_info, int request_id);

	/**
	 * ��ѯ���ʺ�ԼӦ��ص�
	 *
	 * @param detail        ���ʺ�Լ����
	 * @param error_info    Ӧ��Ĵ�����Ϣ
	 * @param request_id    ��Ӧ����ʱ��������к�
	 * @param is_last       �Ƿ��Ǳ�����������һ����Ӧ
	 * @param pos_str       ���β�ѯ���һ����¼�Ķ�λ����������һ�β�ѯ
	 */
	virtual void OnQueryCreditFinanceRsp(CreditFinanceDetail* detail,
		ErrorInfo* error_info, int request_id,
		bool is_last, const char* pos_str);

	/**
	 * ��ѯ��ȯ��ԼӦ��ص�
	 *
	 * @param detail        ��ȯ��Լ����
	 * @param error_info    Ӧ��Ĵ�����Ϣ
	 * @param request_id    ��Ӧ����ʱ��������к�
	 * @param is_last       �Ƿ��Ǳ�����������һ����Ӧ
	 * @param pos_str       ���β�ѯ���һ����¼�Ķ�λ����������һ�β�ѯ
	 */
	virtual void OnQueryCreditShortsellRsp(CreditShortsellDetail* detail,
		ErrorInfo* error_info,
		int request_id, bool is_last,
		const char* pos_str);

	/**
	 * ��ѯ�ɻ����ʸ�ծ���Ӧ��ص�
	 *
	 * @param detail        �ɻ��������
	 * @param error_info    Ӧ��Ĵ�����Ϣ
	 * @param request_id    ��Ӧ����ʱ��������к�
	 */
	virtual void OnQueryCreditRepayAmountRsp(CreditRepayAmountDetail* detail,
		ErrorInfo* error_info,
		int request_id);

	/**
	 * ��ѯ������ȯ��ծ����Ӧ��ص�
	 *
	 * @param detail        �ɻ�����
	 * @param error_info    Ӧ��Ĵ�����Ϣ
	 * @param request_id    ��Ӧ����ʱ��������к�
	 * @param is_last       �Ƿ��Ǳ�����������һ����Ӧ
	 * @param pos_str       ���β�ѯ���һ����¼�Ķ�λ����������һ�β�ѯ
	 */
	virtual void OnQueryCreditRepayStockRsp(CreditRepayStockDetail* detail,
		ErrorInfo* error_info,
		int request_id, bool is_last,
		const char* pos_str);

	/**
	 * ��ѯ����ȯ������������������ָ��ȯ�Ŀ�����
	 *
	 * @param rsp               ��ѯ������Ϣ
	 * @param error_info        Ӧ��Ĵ�����Ϣ
	 * @param request_id        �������кţ�����ƥ����Ӧ�����û��Զ���
	 * @param is_last           �Ƿ��Ǳ�����������һ����Ӧ
	 */
	virtual void OnQueryCreditSecuritySellQtyRsp(CreditSecuritySellQtyRsp* rsp,
		ErrorInfo* error_info,
		int request_id, bool is_last);

	/**
	 * ��ѯ�˻�����Ȩ�޻ص�
	 *
	 * @param market        �г�,��"SZ SH",ԭ�����ص��������
	 * @param secuid_right  Ȩ������,�紴ҵ��,ԭ�����ص��������
	 * @param error_info    Ӧ��Ĵ�����Ϣ
	 * @param sign_flag     ǩ��Ȩ�ޱ�־,true����Ȩ��
	 * @param request_id    �������кţ�����ƥ����Ӧ�����û��Զ��壬��0
	 */
	virtual void OnQuerySecuidRightRsp(const char* market, int16_t secuid_right,
		ErrorInfo* error_info, bool sign_flag,
		int request_id);

	// ����ͨ�����ͨ���нӿ�
	/**
	 * ��ѯ����ͨ�ο����ʵ���Ӧ
	 *
	 * @param detail        ����ͨ�ο���������
	 * @param error_info    Ӧ��Ĵ�����Ϣ
	 * @param request_id    ��Ӧ����ʱ��������к�
	 * @param is_last       �Ƿ��Ǳ�����������һ����Ӧ
	 */
	virtual void OnQueryHKRateRsp(HKRateDetail* detail, ErrorInfo* error_info,
		int request_id, bool is_last);

	/**
	 * ��ѯ����ͨ���ȯ����Ӧ
	 *
	 * @param detail        ����ͨ���ȯ����
	 * @param error_info    Ӧ��Ĵ�����Ϣ
	 * @param request_id    ��Ӧ����ʱ��������к�
	 * @param is_last       �Ƿ��Ǳ�����������һ����Ӧ
	 */
	virtual void OnQueryHKStockRsp(HKStockDetail* detail, ErrorInfo* error_info,
		int request_id, bool is_last);

	/**
	 * ��ѯ����ͨ���ʽ���ʲ�����Ӧ
	 *
	 * @param detail        ����ͨ���ʽ���ʲ�����
	 * @param error_info    Ӧ��Ĵ�����Ϣ
	 * @param request_id    ��Ӧ����ʱ��������к�
	 */
	virtual void OnQueryHKFundRsp(HKFundDetail* detail, ErrorInfo* error_info,
		int request_id);

	/**
	 * ��ѯ����ͨ��С�۲����Ӧ
	 *
	 * @param detail        ����ͨ��С�۲�����
	 * @param error_info    Ӧ��Ĵ�����Ϣ
	 * @param request_id    ��Ӧ����ʱ��������к�
	 * @param is_last       �Ƿ��Ǳ�����������һ����Ӧ
	 */
	virtual void OnQueryHKMinPriceUnitRsp(HKMinPriceUnitDetail* detail,
		ErrorInfo* error_info, int request_id,
		bool is_last);

	/**
	 * ��ѯ����ͨ������������Ӧ
	 *
	 * @param detail        ����ͨ������������
	 * @param error_info    Ӧ��Ĵ�����Ϣ
	 * @param request_id    ��Ӧ����ʱ��������к�
	 * @param is_last       �Ƿ��Ǳ�����������һ����Ӧ
	 */
	virtual void OnQueryHKTradeCalendarRsp(HKTradeCalendarDetail* detail,
		ErrorInfo* error_info,
		int request_id, bool is_last);

	/**
	 * ��ѯ��ȯ��ϸӦ��
	 *
	 * @param detail        ��ȯ��ϸ����
	 * @param error_info    Ӧ��Ĵ�����Ϣ
	 * @param request_id    ��Ӧ����ʱ��������к�
	 * @param is_last       �Ƿ��Ǳ�����������һ����Ӧ
	 */
	virtual void OnQueryLockSecurityDetailRsp(LockSecurityDetail* detail,
		ErrorInfo* error_info,
		int request_id, bool is_last);

	/**
	 * չ��Ӧ��
	 *
	 * @param apply_sno     ������
	 * @param apply_date    ��������
	 * @param error_info    Ӧ��Ĵ�����Ϣ
	 * @param request_id    �������кţ�����ƥ����Ӧ�����û��Զ��壬��0
	 */
	virtual void OnExtendLockSecurityRsp(int32_t apply_sno, int32_t apply_date,
		ErrorInfo* error_info,
		int request_id);

	/**
	 * ��ѯչ������Ӧ��
	 *
	 * @param detail        չ����ϸ����
	 * @param error_info    Ӧ��Ĵ�����Ϣ
	 * @param request_id    ��Ӧ����ʱ��������к�
	 * @param is_last       �Ƿ��Ǳ�����������һ����Ӧ
	 */
	virtual void OnQueryLockSecurityExtensionRsp(
		LockSecurityExtensionDetail* detail, ErrorInfo* error_info,
		int request_id, bool is_last);

	/**
	 * ������ȯչ������Ӧ��
	 *
	 * @param apply_date    �������ڣ���20190415
	 * @param apply_sno     �������
	 * @param cancel_sno    �������
	 * @param error_info    Ӧ��Ĵ�����Ϣ
	 * @param request_id    ��Ӧ����ʱ��������к�
	 */
	virtual void OnCancelExtendLockSecurityRsp(int apply_date,
		const char* apply_sno,
		const char* cancel_sno,
		ErrorInfo* error_info,
		int request_id);

	/**
	 * ��ѯ�ʽ�ת��ˮ����Ӧ
	 *
	 * @param detail        �ʽ�ת��ϸ����
	 * @param error_info    Ӧ��Ĵ�����Ϣ
	 * @param request_id    ��Ӧ����ʱ��������к�
		 * @param is_last       �Ƿ��Ǳ�����������һ����Ӧ
		 */
	virtual void OnQueryTransferFundHistoryRsp(TransferFundDetail* detail,
		ErrorInfo* error_info,
		int request_id, bool is_last);



    //-------------------------------------------------------------------------------------
    //data���ص������������ֵ�
    //error���ص������Ĵ����ֵ�
    //id������id
    //last���Ƿ�Ϊ��󷵻�
    //i������
    //-------------------------------------------------------------------------------------
	virtual void onDisconnect() {};

	virtual void onError(const dict &error, int request_id) {};

	virtual void onRiskNotify(const dict &data) {};

	virtual void onLogin(const dict &data, const dict &error) {};

	virtual void onTradeReport(const dict &data) {};

	virtual void onOrderStatus(const dict &data) {};

	virtual void onOrderRsp(const dict &data, const dict &error, int request_id, bool last) {};

	virtual void onCancelRsp(const dict &data, const dict &error, int request_id, bool last) {};

	virtual void onQueryOrderRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

	virtual void onQueryTradeRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

	virtual void onQueryPositionRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

	virtual void onQueryCashRsp(const dict &data, const dict &error, int request_id) {};

	virtual void onQueryJZJYAvailFundRsp(int64_t avail_balance, const dict &error, int request_id) {};

	virtual void onTransferFundInAndOutRsp(int64_t transfer_value, const dict &error, int request_id) {};

	virtual void onTransferFundBetweenSecuidRsp(int64_t transfer_value, const dict &error, int request_id) {};

	virtual void onQueryETFRsp(const dict &data, const dict &error, int request_id, bool last) {};

	virtual void onQueryETFStockRsp(const dict &data, const dict &error, int request_id, bool last) {};

	virtual void onQueryMaxOrderQtyRsp(const dict &data, const dict &error, int request_id) {};

	virtual void onQueryIPOMaxPurchaseRsp(const dict &data, const dict &error, int request_id, bool last) {};

	virtual void onQueryIPOStockRsp(const dict &data, const dict &error, int request_id, bool last) {};

	virtual void onQueryIPODistributionRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

	virtual void onQueryIPOLotteryRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

	virtual void onQuerySecurityBaseInfoRsp(const dict &data, const dict &error, int request_id, bool last) {};

	virtual void onCreditMortgageInOutRsp(const dict &data, const dict &error, int request_id) {};

	virtual void onCreditStockBackRsp(const dict &data, const dict &error, int request_id) {};

	virtual void onCreditPayBackRsp(const dict &data, const dict &error, int request_id) {};

	virtual void onCreditPayBackByOrderRsp(const dict &data, const dict &error, int request_id) {};

	virtual void onQueryCreditStockRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

	virtual void onQueryCreditMortgageHoldRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

	virtual void onQueryCreditAssetsRsp(const dict &data, const dict &error, int request_id) {};

	virtual void onQueryCreditFinanceRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

	virtual void onQueryCreditShortsellRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

	virtual void onQueryCreditRepayAmountRsp(const dict &data, const dict &error, int request_id) {};

	virtual void onQueryCreditRepayStockRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

	virtual void onQueryCreditSecuritySellQtyRsp(const dict &data, const dict &error, int request_id, bool last) {};

	virtual void onQuerySecuidRightRsp(string market, int secuid_right, const dict &error, bool last, int request_id) {};

	virtual void onQueryHKRateRsp(const dict &data, const dict &error, int request_id, bool last) {};

	virtual void onQueryHKStockRsp(const dict &data, const dict &error, int request_id, bool last) {};

	virtual void onQueryHKFundRsp(const dict &data, const dict &error, int request_id) {};

	virtual void onQueryHKMinPriceUnitRsp(const dict &data, const dict &error, int request_id, bool last) {};

	virtual void onQueryHKTradeCalendarRsp(const dict &data, const dict &error, int request_id, bool last) {};

	virtual void onQueryLockSecurityDetailRsp(const dict &data, const dict &error, int request_id, bool last) {};

	virtual void onExtendLockSecurityRsp(int apply_sno, int apply_date, const dict &error, int request_id) {};

	virtual void onQueryLockSecurityExtensionRsp(const dict &data, const dict &error, int request_id, bool last) {};

	virtual void onCancelExtendLockSecurityRsp(int apply_date, string apply_sno, string cancel_sno, const dict &error, int request_id) {};

	virtual void onQueryTransferFundHistoryRsp(const dict &data, const dict &error, int request_id, bool last) {};

    //-------------------------------------------------------------------------------------
    //req:���������������ֵ�
    //-------------------------------------------------------------------------------------
	void setLogConfig(string log_path);

    void createTraderApi();

    void release();

    int exit();

    string getApiVersion();

	int login(string svr_ip, int svr_port, const dict &req, string terminal_info);

	int getCounterType();

	pybind11::list getSecuidInfo();

	dict getApiLocalAddr();

	int order(const dict &req, int request_id);

	int batchOrder(const dict &req, int count, int request_id);

	int cancelOrder(const dict &req, int request_id);

	int batchCancelOrder(const dict &req, int count, int request_id);

	int queryOrder(string order_id, int request_id, string market);

	int queryOrderByCode(string symbol, int request_id);

	int queryOrders(string pos_str, int query_num, int request_id, int query_flag);

	int queryTradeByOrderId(string order_id, int request_id, string market);

	int queryTradeByCode(string symbol, int request_id);

	int queryTrades(string pos_str, int query_num, int request_id);

	int queryETFTrades(string pos_str, int query_num, int request_id, string market);

	int queryPosition(string symbol, int request_id);

	int queryPositions(string pos_str, int query_num, int request_id);

	int queryCash(int request_id);

	int queryJZJYAvailFund(int request_id);

	int transferFundInAndOut(int transfer_side, int transfer_value, int request_id, string market);

	int transferFundBetweenSecuid(string fund_out_market, string fund_in_market, int transfer_value, int request_id);

	int queryETFs(int request_id);

	int queryETFStocks(string first_symbol, int request_id);

	int queryMaxOrderQty(string symbol, int order_type, int side, int price, int request_id);

	int queryIPOMaxPurchase(int request_id);

	int queryIPOStock(int request_id, int query_flag);

	int queryIPODistribution(int start_date, int end_date, string pos_str, int query_num, int request_id);

	int queryIPOLottery(int start_date, int end_date, string pos_str, int query_num, int request_id);

	int querySecurityBaseInfo(int request_id, string symbol);

	int creditMortgageInOut(const dict &req, int request_id);

	int creditStockBack(const dict &req, int request_id);

	int creditPayBack(int back_amt, int request_id);

	int creditPayBackByOrder(string order_id, int order_date, int back_amt, int request_id);

	int queryCreditStock(string pos_str, int query_num, int request_id);

	int queryCreditMortgageHold(string pos_str, int query_num, int request_id);

	int queryCreditAssets(int request_id);

	int queryCreditFinance(string pos_str, int query_num, int request_id);

	int queryCreditShortsell(string pos_str, int query_num, int request_id);

	int queryCreditRepayAmount(int request_id);

	int queryCreditRepayStock(string market, string code, int request_id);

	int queryCreditSecuritySellQty(string market, string code, int request_id);

	int querySecuidRight(string market, int secuid_right, int request_id);

	int queryHKRate(string market, int request_id);

	int queryHKStock(string market, int request_id);

	int queryHKFund(int request_id);

	int queryHKMinPriceUnit(string market, int request_id);

	int queryHKTradeCalendar(int start_date, int end_date, int request_id);

	int queryLockSecurityDetail(int begin_date, int end_date, int request_id, string market, string code);

	int extendLockSecurity(const dict &req, int request_id);

	int queryLockSecurityExtension(int begin_date, int end_date, int request_id);

	int cancelExtendLockSecurity(int apply_date, string apply_sno, int request_id);

	int queryTransferFundHistory(int request_id);



};
