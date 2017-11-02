//
// Created by Arne Gockeln on 31.10.17.
//

#include "TestModul.h"

void TestModul::onBalance(xtbclient::StreamBalanceRecord balanceRecord) {
  ModuleBase::onBalance(balanceRecord);
}

void TestModul::onCandle(xtbclient::StreamCandleRecord candleRecord) {
  printf("s: %s, ctm: %lld, ctmStr: %s, o: %.5f, h: %.5f, l: %.5f, c: %.5f, vol: %f\n",
  candleRecord.m_symbol.c_str(), candleRecord.m_ctm, candleRecord.m_ctmString.c_str(), candleRecord.m_open,
  candleRecord.m_high, candleRecord.m_low, candleRecord.m_close, candleRecord.m_vol);
}

void TestModul::onKeepAlive(long long timestamp) {
  ModuleBase::onKeepAlive(timestamp);
}

void TestModul::onNews(xtbclient::StreamNewsRecord newsRecord) {
  ModuleBase::onNews(newsRecord);
}

void TestModul::onProfits(xtbclient::StreamProfitRecord profitRecord) {
  ModuleBase::onProfits(profitRecord);
}

void TestModul::onTickPrices(xtbclient::StreamTickRecord tickRecord) {
  ModuleBase::onTickPrices(tickRecord);
}

void TestModul::onTrades(xtbclient::StreamTradeRecord tradeRecord) {
  ModuleBase::onTrades(tradeRecord);
}

void TestModul::onTradeStatus(xtbclient::StreamTradeStatusRecord statusRecord) {
  ModuleBase::onTradeStatus(statusRecord);
}

void TestModul::onDebugMsg(std::string msg) {
  ModuleBase::onDebugMsg(msg);
}

// the class factories
extern "C" TestModul* create(){
  return new TestModul;
}

extern "C" void destroy(TestModul* p){
  delete p;
}