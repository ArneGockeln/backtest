/*!
 *  Copyright(c)2017, Arne Gockeln
 *  http://www.arnegockeln.com
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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