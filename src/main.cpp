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

#include <iostream>
#include <xtbclient/Client.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fstream>
#include <dlfcn.h>
#include "interface/ModuleBase.h"

using namespace std;

/*!
 * Print line
 * @param const char* str
 */
void println(const char* str){
  printf("%s\n", str);
}

/*!
 * Check if files do exist
 *
 * @param const string& historyFilename
 * @param const string& strategyFilename
 */
void checkFiles(const string& historyFilename, const string& strategyFilename){
  struct stat buffer;

  if( historyFilename.empty() ){
    println("Error: No historyFilename found.");
    exit(EXIT_FAILURE);
  }

  if( stat(historyFilename.c_str(), &buffer) != 0 ){
    println("Error: history file not found.");
    exit(EXIT_FAILURE);
  }

  if( strategyFilename.empty() ){
    println("Error: No strategy filename found.");
    exit(EXIT_FAILURE);
  }

  if( stat(strategyFilename.c_str(), &buffer) != 0 ){
    println("Error: strategy file not found.");
    exit(EXIT_FAILURE);
  }
}

/*!
 * Main
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char* argv[]) {
  // load data from file

  if( argc < 2 ){
    println("Usage: backtest [options]");
    println("\t-f <history.log> *required, Format: \"SYMBOL;ctm;ctmString;open;high;low;close;volume;quoteid\"");
    println("\t-s <strategy.so> *reguired");
    exit(EXIT_FAILURE);
  }

  string historyFilename;
  string strategyFilename;

  int opt;
  while( (opt = getopt(argc, argv, "f:s:")) != -1 ) {
    switch (opt) {
      case 'f':
        historyFilename = optarg;
        break;
      case 's':
        strategyFilename = optarg;
        break;
      default:
        exit(EXIT_FAILURE);
    }
  }

  // check if files exists
  checkFiles(historyFilename, strategyFilename);

  // ---
  // load history data
  // ---

  // holds the candle history
  vector<xtbclient::StreamCandleRecord> m_candle_history;

  // load log file
  string line;
  ifstream logFile( historyFilename.c_str(), ifstream::in );

  if( logFile.is_open() ) {
    unsigned int col = 0;

    while (logFile) {
      string currentLine;
      if (!getline(logFile, currentLine)) break;

      istringstream stream(currentLine);
      xtbclient::StreamCandleRecord tmpCandle;

      col = 0;
      while (stream) {
        string value;
        if (!getline(stream, value, ';')) break;

        switch (col) {
          case 0: // symbol
            tmpCandle.m_symbol = value;
            break;
          case 1: // ctm
            tmpCandle.m_ctm = stoll(value);
            break;
          case 2: // ctmString
            tmpCandle.m_ctmString = value;
            break;
          case 3: // open
            tmpCandle.m_open = stod(value);
            break;
          case 4: // high
            tmpCandle.m_high = stod(value);
            break;
          case 5: // low
            tmpCandle.m_low = stod(value);
            break;
          case 6: // close
            tmpCandle.m_close = stod(value);
            break;
          case 7: // volume
            tmpCandle.m_vol = stod(value);
            break;
          case 8: // quote id

            break;
          default:
            break;
        }
        col++;
      }
      // add to list
      m_candle_history.push_back(tmpCandle);
    }
  }

  logFile.close();

  // ---
  // load dynamic strategy
  // ---
  void* strategyBase = dlopen(strategyFilename.c_str(), RTLD_LAZY);
  if(!strategyBase){
    printf("Error: Cannot load library %s\n", dlerror());
    exit(EXIT_FAILURE);
  }

  // reset errors
  dlerror();

  // load symbols
  auto create_strategy = (create_t*) dlsym(strategyBase, "create");
  const char* dlsym_error = dlerror();
  if(dlsym_error){
    printf("Error: Cannot load symbol create: %s\n.", dlsym_error);
    exit(EXIT_FAILURE);
  }

  auto destroy_strategy = (destroy_t*) dlsym(strategyBase, "destroy");
  dlsym_error = dlerror();
  if(dlsym_error){
    printf("Error: Cannot load symbol destroy: %s\n.", dlsym_error);
    exit(EXIT_FAILURE);
  }

  // create an instance of the class
  ModuleBase* strategy = create_strategy();

  // start trade analyzer
  for(auto& candle : m_candle_history) {
    // call module handler
    strategy->onCandle(candle);
  }

  // destroy the strategy class
  destroy_strategy(strategy);

  // unload the strategy lib
  dlclose(strategyBase);

  return 0;
}