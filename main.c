#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <windows.h>
// hlavickovy subor "sachoveho" modulu
#include "chess.h"
#include "chess.c"

int main()
{
	int testk;
	init_chessboard();
	print_chessboard();
	while(0==0)
	{
		tah(0);
		testk=koniec_hry();
		if (testk==0){
			return 0;
		}
		printf("\nPRESS BUTTON TO CONTINUE");
		getchar();
		CLEAR_SCREEN();
		print_chessboard();
		printf("\nPRESS BUTTON TO CONTINUE");
		getchar();
		CLEAR_SCREEN();
		print_chessboard();
		tah(1);
		testk=koniec_hry();
		if (testk==0){
			return 0;
		}
		printf("\nPRESS BUTTON TO CONTINUE");
		getchar();
		CLEAR_SCREEN();
		print_chessboard();
		printf("\nPRESS BUTTON TO CONTINUE");
		getchar();
		CLEAR_SCREEN();
		print_chessboard();
	}
    return 0;
}
