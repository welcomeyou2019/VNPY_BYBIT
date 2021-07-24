# flake8: noqa
from vnpy.event import EventEngine

from vnpy.trader.engine import MainEngine
from vnpy.trader.ui import MainWindow, create_qapp
from vnpy.gateway.bybit import BybitGateway
from vnpy.app.rpc_service import RpcServiceApp
import time
from vnpy.trader.constant import Exchange
from vnpy.trader.object import SubscribeRequest

def main(Visualization):
    """"""
    if Visualization:
        qapp = create_qapp()

        event_engine = EventEngine()

        main_engine = MainEngine(event_engine)

        main_engine.add_gateway(BybitGateway)
        main_engine.add_app(RpcServiceApp)

        main_window = MainWindow(main_engine, event_engine)
        main_window.showMaximized()

        qapp.exec()

    else:
        event_engine = EventEngine()

        main_engine = MainEngine(event_engine)

        main_engine.add_gateway(BybitGateway)

        setting = {'ID': 'GQzGyWI0YneGTfWbhr', 'Secret': '7FBjt3fB0fRFUfMwEN9W5U3jh1yneiNtUAQ2', '服务器': "REAL",
                   '代理地址': 'None', '代理端口': '0', '合约模式': '正向'}
        gateway_name = 'BYBIT'
        main_engine.connect(setting, gateway_name)
        time.sleep(5)

        req = SubscribeRequest
        req.exchange = Exchange.BYBIT
        req.symbol = 'BTCUSD'

        main_engine.subscribe(req, gateway_name)

        while True:

            contract = main_engine.get_all_contracts()
            ticks = main_engine.get_tick('BTCUSDT.BYBIT')
            time.sleep(1)
            print(contract)
            print(ticks)


if __name__ == "__main__":
    main(True)  #True for visiualization, Fasle for console