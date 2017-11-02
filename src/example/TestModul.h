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

#ifndef BACKTEST_MODULEBASE_H
#define BACKTEST_MODULEBASE_H

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


#endif //BACKTEST_MODULEBASE_H
