set(COMMON_SOURCE_FILES Common.h Common.cpp)

add_library(Common SHARED ${COMMON_SOURCE_FILES})

target_include_directories(Common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})