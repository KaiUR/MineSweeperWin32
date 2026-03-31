#ifndef MAIN_H
#define MAIN_H

/*
 ============================================================================
    INCLUDES
 ============================================================================
 */
#include <minwindef.h>
#include <windef.h>

/*
 ============================================================================
    Function prototypes
 ============================================================================
 */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK STD_DlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK New_Game_DlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Custom_Game_DlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
void new_game_board(int x, int y, int mines);
void clear_game_board(void);
void game_board_reveal(int x, int y);
void reveal_r(int x, int y);

/*
 ============================================================================
    Structure definition
 ============================================================================
 */
struct game_board_s
{
    int ** game_board;
    int ** flag_board;
    int x;
    int y;
    int mines;
    int remain_mines;
    int lost;
    int l_x;
    int l_y;
    int first_start;
};

#endif // MAIN_H
