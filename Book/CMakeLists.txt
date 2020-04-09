set(BOOK_SOURCE_FILES main.cpp)
add_executable(Book ${BOOK_SOURCE_FILES})

target_link_libraries(Book PRIVATE Common)