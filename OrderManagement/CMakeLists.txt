set(ORDERMANAGEMENT_SOURCE_FILES main.cpp)
ADD_LIBRARY(rpclib STATIC IMPORTED)
SET_TARGET_PROPERTIES(rpclib PROPERTIES IMPORTED_LOCATION /usr/local/lib/librpc.a)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)



set(CMAKE_MODULE_PATH "/usr/local/lib/cmake/rpclib")
find_package(rpclib REQUIRED)
FIND_PACKAGE(Threads REQUIRED)
include_directories(${RPCLIB_INCLUDE_DIR} /usr/local/include/)

add_executable(ORDERMANAGEMENT ${ORDERMANAGEMENT_SOURCE_FILES})
link_directories(usr/local/lib)

target_link_libraries(ORDERMANAGEMENT  ${RPCLIB_LIBS} Common Book rpclib Threads::Threads)


