cmake_minimum_required(VERSION 3.16)

project(MineSweeperWin32 LANGUAGES C)

add_executable(MineSweeperWin32 main.c
    resource.h
    Data/blank_space.bmp Data/blank_space_empty.bmp Data/menu_one.ico Data/mine_black.bmp Data/mine_red.bmp Data/space_1.bmp Data/space_2.bmp Data/space_3.bmp Data/space_4.bmp Data/space_5.bmp Data/space_6.bmp Data/space_7.bmp Data/space_8.bmp Data/space_flag.bmp
    resource.rc
)

include(GNUInstallDirs)
install(TARGETS MineSweeperWin32
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
