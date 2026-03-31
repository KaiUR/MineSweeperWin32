cmake_minimum_required(VERSION 3.16)

project(MineSweeperWin32 VERSION 1.0.0 LANGUAGES C RC)

if(EXISTS "${CMAKE_SOURCE_DIR}/build_number.txt")
    file(READ "${CMAKE_SOURCE_DIR}/build_number.txt" BUILD_NUMBER)
    math(EXPR BUILD_NUMBER "${BUILD_NUMBER} + 1")
else()
    set(BUILD_NUMBER "1")
endif()
file(WRITE "${CMAKE_SOURCE_DIR}/build_number.txt" "${BUILD_NUMBER}")

string(TIMESTAMP CURRENT_DATE "%Y-%m-%d")

string(TIMESTAMP CURRENT_YEAR "%Y")
string(TIMESTAMP CURRENT_MONTH "%m")
string(TIMESTAMP CURRENT_DAY "%d")

configure_file(version.h.in "${CMAKE_CURRENT_BINARY_DIR}/version.h" @ONLY)

include_directories("${CMAKE_CURRENT_BINARY_DIR}")

set(CMAKE_RC_FLAGS "${CMAKE_RC_FLAGS} --use-temp-file")

add_executable(MineSweeperWin32 WIN32
    main.c
    main.h
    resource.h
    resource.rc
    Data/blank_space.bmp
    Data/blank_space_empty.bmp
    Data/menu_one.ico
    Data/mine_black.bmp
    Data/mine_red.bmp
    Data/space_1.bmp
    Data/space_2.bmp
    Data/space_3.bmp
    Data/space_4.bmp
    Data/space_5.bmp
    Data/space_6.bmp
    Data/space_7.bmp
    Data/space_8.bmp
    Data/space_flag.bmp
    version.h
)

target_include_directories(MineSweeperWin32 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

include(GNUInstallDirs)
install(TARGETS MineSweeperWin32
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
