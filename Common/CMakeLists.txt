set(COMMON_SOURCE_FILES Common.h Common.cpp)
add_library(Common SHARED ${COMMON_SOURCE_FILES})
target_include_directories(Common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set(BOOK_SOURCE_FILES Book.h Book.cpp)
add_library(Book SHARED ${BOOK_SOURCE_FILES})
target_include_directories(Book PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set(EXCHANGE_SOURCE_FILES Exchange.h Exchange.cpp)
add_library(Exchange SHARED ${EXCHANGE_SOURCE_FILES})
target_include_directories(Exchange PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set(MARKET_SOURCE_FILES Market.h Market.cpp)
add_library(Market SHARED ${MARKET_SOURCE_FILES})
target_include_directories(Market PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})