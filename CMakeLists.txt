cmake_minimum_required(VERSION 3.14)  # 4.1.1 — не существует; последняя на 2025 — 3.30+
project(lab4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)  # для Windows, если будут проблемы со ссылками

# Подключаем GoogleTest через FetchContent
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.15.0  # стабильная версия, совместима с C++20
  GIT_SHALLOW    TRUE
  TLS_VERIFY     FALSE
)
# Отключаем установку gtest/ gmock (нам не нужна инсталляция)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "Disable installation of googletest" FORCE)
FetchContent_MakeAvailable(googletest)

# === Исправление 1: вы не должны собирать main.cpp в библиотеку! ===
# Библиотека должна содержать ТОЛЬКО классы (point, figure, rhombus и т.д.)
# main.cpp — это точка входа, её нельзя линковать в библиотеку.

# → Удаляем add_library с main.cpp

# Исполняемый файл основной программы
add_executable(lab4_exe body/main.cpp)
target_include_directories(lab4_exe PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/head)
target_compile_features(lab4_exe PRIVATE cxx_std_20)

# === Исправление 2: тесты должны линковаться с gtest_main и иметь доступ к заголовкам ===
add_executable(tests tests.cpp)
target_include_directories(tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/head)
target_link_libraries(tests PRIVATE gtest gtest_main)
target_compile_features(tests PRIVATE cxx_std_20)

# === Исправление 3: enable_testing() должен быть до add_test ===
enable_testing()
add_test(NAME AllTests COMMAND tests)