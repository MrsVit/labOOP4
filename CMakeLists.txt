cmake_minimum_required(VERSION 3.14)  #
project(lab4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)  
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.15.0  
  GIT_SHALLOW    TRUE
  TLS_VERIFY     FALSE
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "Disable installation of googletest" FORCE)
FetchContent_MakeAvailable(googletest)

#

# Исполняемый файл основной программы сейчас просто маин
add_executable(lab4_exe body/main.cpp)
target_include_directories(lab4_exe PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/head)
target_compile_features(lab4_exe PRIVATE cxx_std_20)


add_executable(tests tests.cpp)
target_include_directories(tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/head)
target_link_libraries(tests PRIVATE gtest gtest_main)
target_compile_features(tests PRIVATE cxx_std_20)


enable_testing()
add_test(NAME AllTests COMMAND tests)