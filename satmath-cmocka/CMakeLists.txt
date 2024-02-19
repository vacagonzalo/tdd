cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(satmath VERSION 1.0 LANGUAGES C)

add_library(${PROJECT_NAME}
    src/satmath.c
    src/satmath_core.c
)
target_include_directories(${PROJECT_NAME} PUBLIC include)

# Unit tests
include(cmake/cmocka.cmake)

add_executable(test__satmath_core test/utest/test__satmath_core.c)
target_compile_features(test__satmath_core PRIVATE c_std_99)
target_link_libraries(test__satmath_core PRIVATE cmocka-static)
target_include_directories(test__satmath_core PUBLIC include)

add_executable(test__satmath
    test/utest/test__satmath.c
    test/mocks/mock__satmath_core.c)
target_link_options(test__satmath PRIVATE -Wl,--wrap=satmath_accumulation)
target_compile_features(test__satmath PRIVATE c_std_99)
target_link_libraries(test__satmath PRIVATE cmocka-static)
target_include_directories(test__satmath PUBLIC include)

enable_testing()
add_test(NAME test__satmath_core COMMAND test__satmath_core)
add_test(NAME test__satmath_ COMMAND test__satmath)

