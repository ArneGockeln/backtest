//
// Created by Arne Gockeln on 31.10.17.
//

#ifndef BACKTEST_FERENGIHEIKINASHI_H
#define BACKTEST_FERENGIHEIKINASHI_H

#include "../interface/ModuleBase.h"

class TestModul: public ModuleBase {
public:
  void onBalance(xtbclient::StreamBalanceRecord balanceRecord) override;

  void onCandle(xtbclient::StreamCandleRecord candleRecord) override;

  void onKeepAlive(long long timestamp) override;

  void onNews(xtbclient::StreamNewsRecord newsRecord) override;

  void onProfits(xtbclient::StreamProfitRecord profitRecord) override;

  void onTickPrices(xtbclient::StreamTickRecord tickRecord) override;

  void onTrades(xtbclient::StreamTradeRecord tradeRecord) override;

  void onTradeStatus(xtbclient::StreamTradeStatusRecord statusRecord) override;

  void onDebugMsg(std::string msg) override;
};


#endif //BACKTEST_FERENGIHEIKINASHI_H
