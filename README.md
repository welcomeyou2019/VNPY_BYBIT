本代码主要借鉴VNPY的框架改写而成，其主要功能：\
1、实现了可视化BYBIT的行情数据订阅与交易命令；\
2、实现了rpc广播数据机制.\
其中BYBIT.py文件主要实现了第一个功能，并作为rpc的server，client.py文件作为rpc的client端接受数据。