#include <stdio.h>
#include <string.h>
#include "lab04.h"
#include <stdbool.h>


void init_board(board_t b, char **argv){
    int i, j;
    int k = 0 ;
    for (i = 0; i < BOARD_SZ; i++) {
        for (j = 0; j < BOARD_SZ; j++) {
            b[i][j] = *argv[i+j+k] ;
        }
        k = k + 2 ;
    }
}

void print_board(board_t b){
    int i, j;
    for (int i = 0; i < BOARD_SZ; i++)
    {
        for (int j = 0; j < BOARD_SZ; j++)
        {
            printf(" %c", b[i][j]);
            if (j != 2) printf(" |");
        }
        if (i != 2)
            printf("\n---+---+---");
        printf("\n");
    }
}

bool is_player_win(board_t b, char player) {
    bool win = false ;
    for (int i = 0; i < BOARD_SZ; i++) {
        win = true ;
        for (int j = 0; j < BOARD_SZ; j++) {
            if ( b[i][j] !=  player)  {
                win = false ;
            }
        }
        if ( win == true ) return 1 ;
    }

    win = false ;
    for (int i = 0; i < BOARD_SZ; i++) {
        win = true ;
        for (int j = 0; j < BOARD_SZ; j++) {
            if ( b[j][i] !=  player)  {
                win = false ;
            }
        }
        if ( win == true ) return 1 ;
    }

    win = true ;
    for (int i = 0; i < BOARD_SZ; i++) {
        if ( b[i][i] !=  player)  {
            win = false ;
        }
    }
    if ( win == true ) return 1 ;
    
    win = true ;
    for (int i = 0; i < BOARD_SZ; i++) {
        if ( b[i][3-1-i] != player)  {
            win = false ;
        }
    }
    if ( win == true ) return 1 ;
    return 0 ;
}

int check_board(board_t board){
    if ( is_player_win(board, 'X') ) return 1 ;
    if ( is_player_win(board, 'O') ) return -1 ;
    return 0 ;
}



