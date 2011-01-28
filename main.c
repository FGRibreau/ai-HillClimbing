#include <stdio.h>
#include <time.h>
#include "lib/env.h"
#include "lib/Stack.h"
#include "chessboard.h"
#include "testChessboard.h"

int main (int argc, const char * argv[]) {
	srand ( time(NULL) );
	
	int plateau = 0
	,	plateauMax = 200;
	
	//Test unitaire
	testChessboard();
	
	//Programme
	pChessboard lastMat = Chessboard_constructor(32),
				newMat = NULL;
	

	Chessboard_show(lastMat);
	printf("H: %i\n", Chessboard_getH(lastMat));
	
	newMat = Chessboard_getNextState(lastMat);
	
	int hL = 0, hR = 0;

	//Trouver les états suivants
	while((hL = Chessboard_getH(newMat)) <= (hR = Chessboard_getH(lastMat)) && plateau < plateauMax){
		
		if(hL == hR){
			plateau++;
		} else {
			
			Chessboard_free(lastMat);
			Chessboard_show(newMat);
			printf("H: %i\n", Chessboard_getH(newMat));
			
			lastMat = newMat;
			newMat = Chessboard_getNextState(lastMat);
		}
	}
	
	Chessboard_free(newMat);
	
	
    return 0;
}
