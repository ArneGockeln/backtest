# backtest
cli tool to backtest trading strategies. 

## Dependencies
- a shared object lib with the strategy
- a file with historical data
- the [xtbclient](https://github.com/ArneGockeln/xtbclient) lib
- cmake

## Usage
You need a file with historical data in this format:

```
SYMBOL;ctm;ctmString;open;high;low;close;volume;quoteid
```

Then you need a modul that will be executed on every entry. A base modul is in src/example/.
Compile the modul as a shared object.

Then run the backtest like this:
```bash
$ backtest -f history.log -s libstrategy.so
```

## How to fetch historical data
TBA.

## How to write a strategy module
TBA.

