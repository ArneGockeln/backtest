cmake_minimum_required(VERSION 3.8)
project(backtest)

# Version
set(xtbclient_VERSION_MAJOR 1)
set(xtbclient_VERSION_MINOR 0)
set(CMAKE_CXX_STANDARD 14)
# release build type
set(CMAKE_BUILD_TYPE Release)
# set directories
set(INC_DIR "/usr/local/include")
set(OPT_DIR "/usr/local/opt")
set(LIB_DIR "/usr/local/lib")
# xtbclient library
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I${INC_DIR}/xtbclient")
# date dependency
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I${INC_DIR}/date/include")

set(SOURCE_FILES src/main.cpp src/util/HeikinAshi.h src/util/Indicator.h src/util/TradeMath.h src/interface/ModuleBase.h)
add_executable(backtest ${SOURCE_FILES})
target_link_libraries(backtest ${LIB_DIR}/xtbclient/libxtbclient.dylib dl)

# include example
add_subdirectory(src/example)