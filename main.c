#include <stdio.h>
#include "lib/env.h"
#include "lib/Stack.h"
#include "chessboard.h"
#include "testChessboard.h"

int main (int argc, const char * argv[]) {
    //Test unitaire
	
	testChessboard();
	
	//Programme

	pChessboard tmp = Chessboard_constructor(5);
	/*,			tmp2 = Chessboard_constructor(5);*/
	//Chessboard_empty(tmp);
	
	//Stack qui contient la suite des états de la matrice tmp
	//pStack states = Stack_create();
	
	Chessboard_draw(tmp);
	
	for(int col = 0; col < tmp->size; col++){
		printf("Col[%i] Ligne: %i\n", col, Chessboard_getKeenPos(tmp, col));
	}
	
	
	//printf("Matrice pareil ? %s\n", Chessboard_equals(tmp, tmp2) == true ? "Oui" : "Non");
	
	//Il faut maintenant, pour chaque reine, la déplacer sur toute la colonne et trouver son plus bas H
	
	//Puis, une fois toutes les reines déplacées et le plus bas H trouvé, changer la matrice initiale
	
	pChessboard tt = Chessboard_getNextState(tmp);
	
	Chessboard_draw(tt);
	
	
	Chessboard_free(tmp);
	
	_printMalloc();
    return 0;
}
