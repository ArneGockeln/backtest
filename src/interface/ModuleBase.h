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

//
// This is the module interface for modules that are gonna be loaded dynamically
//

#ifndef MODULEBASE_H
#define MODULEBASE_H

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

#endif // MODULEBASE_H
