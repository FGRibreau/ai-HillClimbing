/*
 *  chessboard.h
 *  HillClimbing
 *
 *  Created by Francois-Guillaume Ribreau on 21/01/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _CHESSBOARD_H
#define _CHESSBOARD_H

#include "lib/env.h"
#include "queen.h"

typedef struct Chessboard* pChessboard;

/* Echequier */
struct Chessboard{
	int**	queens;
	int		size;
	int		h;
} Chessboard;

typedef struct KeenState* pKeenState;

/* Etat d'une reine */
struct KeenState{
	int			col;			//Numéro de colonne [0-N]
	int			lineOldPos;		//Ancienne position de la reine (ligne)
	int			lineBestPos;	//Meilleur position de la reine
	int			h;
} KeenState;


pChessboard Chessboard_constructor(int size);

//Vide l'echequier
void Chessboard_empty(pChessboard board);

//Dessine l'echequier
void Chessboard_draw(pChessboard board);

//Retourne la position d'une reine dans une colonne
int Chessboard_getKeenPos(pChessboard pBoard, int col);

//Valorise la matrice avec values
void Chessboard_setKeens(pChessboard pBoard, int* values);

//Return true si 
bool Chessboard_equals(pChessboard pBoardB, pChessboard pBoardA);

//Retourne le H d'une matrice
int Chessboard_getH(pChessboard pBoard);

//
void Chessboard_free(pChessboard pBoard);

#endif
