#include <stdio.h>
#include "lib/env.h"
#include "lib/Stack.h"
#include "chessboard.h"
#include "testChessboard.h"

int main (int argc, const char * argv[]) {
	srand ( time(NULL) );
	
    //Test unitaire
	
	//testChessboard();
	
	//Programme
	pChessboard lastMat = Chessboard_constructor(8),
				newMat = NULL;


	
	//printf("Matrixrice pareil ? %s\n", Chessboard_equals(tmp, tmp2) == true ? "Oui" : "Non");
	
	//Il faut maintenant, pour chaque reine, la déplacer sur toute la colonne et trouver son plus bas H
	
	//Puis, une fois toutes les reines déplacées et le plus bas H trouvé, changer la matrice initiale
	
	Chessboard_show(lastMat);
	printf("Dernier H: %i\n", Chessboard_getH(lastMat));
	
	newMat = Chessboard_getNextState(lastMat);
	
	//Trouver les états suivants
	while(Chessboard_getH(newMat) < Chessboard_getH(lastMat)){
		
		Chessboard_free(lastMat);
		Chessboard_show(newMat);
		printf("Dernier H: %i\n", Chessboard_getH(newMat));
		
		lastMat = newMat;
		
		newMat = Chessboard_getNextState(lastMat);
	}
	
	/*Chessboard_show(newMat);
	printf("Dernier H: %i\n", Chessboard_getH(newMat));*/
	Chessboard_free(newMat);
	
	//_printMalloc();
    return 0;
}
