cmake_minimum_required(VERSION 3.8)
project(testmodule)
set(CMAKE_CXX_STANDARD 14)
# release build type
set(CMAKE_BUILD_TYPE Release)
# set directories
set(INC_DIR "/usr/local/include")
set(OPT_DIR "/usr/local/opt")
set(LIB_DIR "/usr/local/lib")
# xtbclient library
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I${INC_DIR}/xtbclient")

set(SOURCE_FILES TestModul.h TestModul.cpp)
add_library(testmodule MODULE ${SOURCE_FILES})
target_link_libraries(testmodule ${LIB_DIR}/xtbclient/libxtbclient.dylib)

