#include <stdio.h>
#include <time.h>

//Libraries
#include "lib/env.h"
#include "lib/Stack.h"

//Objets métiers + Tests unitaires
#include "chessboard.h"
#include "testChessboard.h"

int main (int argc, const char * argv[]) {
	srand ( time(NULL) );
	
	int plateau = 0
	,	plateauMax = 200
	,	hL = 0
	,	hR = -1;
	
	//Test unitaire
	testChessboard();
	
	//Echiquier
	pChessboard lastMat = Chessboard_constructor(16),
				newMat = NULL;
	
	
	do{
		
		//Si entre 2 états le H est identique
		if(hL == hR){
			plateau++;
		} else {
			
			if(newMat != NULL){//Première itération
				Chessboard_free(lastMat);
			
				//Afficher l'état actuel
				printf("_____________________________________________\n\n");
				Chessboard_show(newMat);
				printf("H: %i\n", Chessboard_getH(newMat));
				lastMat = newMat;
			}
			
			//Trouver l'état suivant
			newMat = Chessboard_getNextState(lastMat);
			
		}
	
	//Continuer tant que le H baisse et que notre limite de plateau n'est pas atteinte
	} while (((hL = Chessboard_getH(newMat)) <= (hR = Chessboard_getH(lastMat)) && plateau < plateauMax));
	
	
	Chessboard_free(newMat);
	
	
    return 0;
}
