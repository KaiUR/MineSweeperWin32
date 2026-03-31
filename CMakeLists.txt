cmake_minimum_required(VERSION 3.16)

project(MineSweeperWin32 VERSION 1.0.0 LANGUAGES C RC)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# --- Build Number Logic ---
if(EXISTS "${CMAKE_SOURCE_DIR}/build_number.txt")
    file(READ "${CMAKE_SOURCE_DIR}/build_number.txt" BUILD_NUMBER)
    string(STRIP "${BUILD_NUMBER}" BUILD_NUMBER) # Clean whitespace
    math(EXPR BUILD_NUMBER "${BUILD_NUMBER} + 1")
else()
    set(BUILD_NUMBER "1")
endif()
file(WRITE "${CMAKE_SOURCE_DIR}/build_number.txt" "${BUILD_NUMBER}")

# --- Timestamp Logic ---
string(TIMESTAMP CURRENT_DATE "%Y-%m-%d")
string(TIMESTAMP CURRENT_YEAR "%Y")
string(TIMESTAMP CURRENT_MONTH "%m")
string(TIMESTAMP CURRENT_DAY "%d")

# --- Configuration ---
set(CMAKE_RC_FLAGS "${CMAKE_RC_FLAGS} --use-temp-file")
configure_file(res/version.h.in "${CMAKE_CURRENT_BINARY_DIR}/version.h" @ONLY)

# --- Data Assets (for IDE visibility) ---
set(GAME_DATA
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

source_group("Data" FILES ${GAME_DATA})

# --- Executable ---
add_executable(MineSweeperWin32 WIN32
    src/main.c
    src/main.h
    src/resource.h
    res/resource.rc
    Data/blank_space.bmp Data/blank_space_empty.bmp Data/menu_one.ico Data/mine_black.bmp Data/mine_red.bmp Data/space_1.bmp Data/space_2.bmp Data/space_3.bmp Data/space_4.bmp Data/space_5.bmp Data/space_6.bmp Data/space_7.bmp Data/space_8.bmp Data/space_flag.bmp
)

# --- Include Paths ---
target_include_directories(MineSweeperWin32 PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_BINARY_DIR}
)

# --- Install ---
include(GNUInstallDirs)
install(TARGETS MineSweeperWin32
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Optional: Install the Data folder along with the exe
install(DIRECTORY Data/ DESTINATION ${CMAKE_INSTALL_BINDIR}/Data)
