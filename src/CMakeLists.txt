
add_executable(main main.cpp)
add_executable(MyString MyString.cpp MyString.h)

add_subdirectory(tests)

add_executable(MyString_tests tests/MyString_tests.cpp MyString.cpp MyString.h)
target_link_libraries(MyString_tests Catch2::Catch2WithMain)
catch_discover_tests(MyString_tests)

