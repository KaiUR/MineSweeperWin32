cmake_minimum_required(VERSION 3.16)

project(MineSweeperWin32 LANGUAGES C RC)

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
)

target_include_directories(MineSweeperWin32 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

include(GNUInstallDirs)
install(TARGETS MineSweeperWin32
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
