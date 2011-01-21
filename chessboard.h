/*
 *  chessboard.h
 *  HillClimbing
 *
 *  Created by Francois-Guillaume Ribreau on 21/01/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */
#include "env.h"
#include "keen.h"

typedef struct Chessboard* pChessboard;

/* Echequier */
struct Chessboard{
	int**	keens;
	int		size;
} Chessboard;




pChessboard Chessboard_constructor(int size);

//Vide l'echequier
void Chessboard_empty(pChessboard board);


void Chessboard_draw(pChessboard board);

int Chessboard_getH(pChessboard pBoard);
