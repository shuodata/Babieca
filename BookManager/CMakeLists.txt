set(BOOK_SOURCE_FILES main.cpp)

# RPCLIB
ADD_LIBRARY(rpclib STATIC IMPORTED)
SET_TARGET_PROPERTIES(rpclib PROPERTIES IMPORTED_LOCATION /usr/local/lib/librpc.a)
find_package(rpclib REQUIRED)

include_directories(${RPCLIB_INCLUDE_DIR} /usr/local/include/)

#Threads
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
set(CMAKE_MODULE_PATH "/usr/local/lib/cmake/rpclib")

# KDB+/Q
link_directories(../Kdb/l64)
include_directories(../Kdb)
ADD_LIBRARY(kdb STATIC IMPORTED)
if(UNIX)
    SET_TARGET_PROPERTIES(kdb PROPERTIES IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/Kdb/l64/c.o)
endif()
if(APPLE)
    SET_TARGET_PROPERTIES(kdb PROPERTIES IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/Kdb/m64/c.o)
endif()

# BookManager executable
add_executable(BookManager ${BOOK_SOURCE_FILES})
link_directories(usr/local/lib)
target_link_libraries(BookManager  ${RPCLIB_LIBS} Common Book kdb KDB rpclib Threads::Threads)

