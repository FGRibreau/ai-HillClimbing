#include <stdio.h>
#include "env.h"

#include "chessboard.h"



int main (int argc, const char * argv[]) {
    
	pChessboard tmp = Chessboard_constructor(100);
	Chessboard_empty(tmp);
	
	
	Chessboard_draw(tmp);
	
	printf("H= %d\n", Chessboard_getH(tmp));
	
    return 0;
}
