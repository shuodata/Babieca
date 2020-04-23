

set(KDB_SOURCE_FILES kdb.h kdb_vector.h kdb_type.h kdb_table.h kdb_result.h kdb_connector.h kdb_table.cpp kdb_result.cpp kdb_connector.cpp)
add_library(KDB SHARED ${KDB_SOURCE_FILES})
target_include_directories(KDB PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})