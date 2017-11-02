//
// Created by Arne Gockeln on 31.10.17.
// This is the module interface for modules that are gonna be loaded dynamically
//

#ifndef FERENGI_H
#define FERENGI_H

#include <xtbclient/StreamListener.h>

using namespace xtbclient;

class ModuleBase: public StreamListener {
public:
  ModuleBase(){}
  virtual ~ModuleBase() {}

  void onBalance(xtbclient::StreamBalanceRecord balanceRecord) override {
    StreamListener::onBalance(balanceRecord);
  }

  void onCandle(xtbclient::StreamCandleRecord candleRecord) override {
    StreamListener::onCandle(candleRecord);
  }

  void onKeepAlive(long long timestamp) override {
    StreamListener::onKeepAlive(timestamp);
  }

  void onNews(xtbclient::StreamNewsRecord newsRecord) override {
    StreamListener::onNews(newsRecord);
  }

  void onProfits(xtbclient::StreamProfitRecord profitRecord) override {
    StreamListener::onProfits(profitRecord);
  }

  void onTickPrices(xtbclient::StreamTickRecord tickRecord) override {
    StreamListener::onTickPrices(tickRecord);
  }

  void onTrades(xtbclient::StreamTradeRecord tradeRecord) override {
    StreamListener::onTrades(tradeRecord);
  }

  void onTradeStatus(xtbclient::StreamTradeStatusRecord statusRecord) override {
    StreamListener::onTradeStatus(statusRecord);
  }

  void onDebugMsg(std::string msg) override {
    StreamListener::onDebugMsg(msg);
  }
};

// the types of the class factories
typedef ModuleBase* create_t();
typedef void destroy_t(ModuleBase*);

#endif //FERENGI_H
