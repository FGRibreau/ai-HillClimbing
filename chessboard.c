/*
 *  chessboard.c
 *  HillClimbing
 *
 *  Created by Francois-Guillaume Ribreau on 21/01/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "chessboard.h"


pChessboard Chessboard_constructor(int size){
	pChessboard pBoard = _malloc(sizeof(Chessboard));
	
	pBoard->size = size;
	
	//Alloc des lignes
	pBoard->queens = _malloc(size * sizeof(int*));
	
	int queenPos[pBoard->size];
	
	//Choix des positions
	for(int col = 0; col < pBoard->size; col++){
		queenPos[col] = (int)(rand() % pBoard->size);
	}
	
	//Alloc des colonnes
	for(int line = 0;line < size; line++){ 
		pBoard->queens[line] = _malloc(size * sizeof(*pBoard->queens[0]));
		
		//Init de l'échéquier de façon aléatoire
		for(int col = 0; col < size; col++){
			pBoard->queens[line][col] = queenPos[col] == line ? 1 : 0;
		}
	}
	
	return pBoard;
}

//Vide l'echequier
void Chessboard_empty(pChessboard pBoard){
	for(int y = 0; y < pBoard->size; y++){
		for(int x = 0; x < pBoard->size; x++){
			pBoard->queens[y][x] = 0;
		}
	}
}

//Calcul le nombre de saut de l'intégralité du plateau
int Chessboard_getH(pChessboard pBoard){

	int h = 0
	,	nbKeen = 0
	,	i =0
	,	col = 0
	,	line = 0
	,	x = 0
	,	y = 0
	,	upCol = 0
	,	upLine = 0
	,	dwCol = 0
	,	dwLine = 0;
	
	
	//Pour chaque ligne, calculer le nombre de saut
	for(i = 0; i < pBoard->size; i++){
		//Trouver nombre de reine pour cette ligne
		nbKeen = 0;
		
		for(x = 0; x < pBoard->size; x++){
			if(pBoard->queens[i][x] == 1){
				nbKeen++;
			}
		}
		
		h += nbKeen > 0 ? (nbKeen*(nbKeen-1))/2 : 0;
	}

	
	//Pour chaque colonne trouver le nombre de saut
	for(col = 0; col < pBoard->size; col++){
		nbKeen = 0;
		
		for(x = 0; x < pBoard->size; x++){
			if(pBoard->queens[x][col] == 1){
				nbKeen++;
			}
		}
		
		h += nbKeen > 0 ? (nbKeen*(nbKeen-1))/2 : 0;
	}

	//Parcourir les reines de haut en bas, de gauche à droite
	//En diagonale vers le haut, en diag vers le bas
	
	for(col = 0; col < pBoard->size; col++){
	for(line = 0; line < pBoard->size; line++){
		
		if(pBoard->queens[line][col] == 1){
			nbKeen = 0;
			x = 0;
			y = 0;
			
			upCol = dwCol = col;
			upLine = dwLine = line;
			
			
			//Vers la diagonale haute
			while(upCol < pBoard->size && upLine >= 0){
				
				if(pBoard->queens[upLine][upCol] == 1){
					nbKeen++;
				}
				
				upCol++;
				upLine--;
			}
			
			
			h += nbKeen > 0 ? (nbKeen*(nbKeen-1))/2 : 0;
			nbKeen = 0;
			
			//Vers la dialognale basse
			while(dwCol < pBoard->size && dwLine < pBoard->size){
				if(pBoard->queens[dwLine][dwCol] == 1){
					nbKeen++;
				}
				
				dwCol++;
				dwLine++;
			}

			h += nbKeen > 1 ? ((nbKeen*(nbKeen-1))/2) : 0;
		}
	
	}}
	
	return h;
}


void Chessboard_draw(pChessboard pBoard){
	for(int y = 0; y < pBoard->size; y++){
		for(int x = 0; x < pBoard->size; x++){
			printf("%i ", pBoard->queens[y][x]);
		}
		
		printf("\n");
	}
}

void Chessboard_setKeens(pChessboard pBoard, int* values){
	
	int i = 0;
	
	for(int line = 0; line < pBoard->size; line++){
		for(int col = 0; col < pBoard->size; col++){
			pBoard->queens[line][col] = values[i++];
		}
	}
}

//Prendre le dernier état du stack

pChessboard Chessboard_getNextState(pChessboard pBoard){
	pChessboard newState = NULL;
	//Pour chaque colonne, avoir hValue[col] = [ positionReine , valeurDeH ];
	pKeenState ks[pBoard->size];
	
	//parcours des colonnes
	
	for(int col = 0; col < pBoard->size; col++){
		/*
		 int			lineOldPos;		//Ancienne position de la reine (ligne)
		 int			lineBestPos;	//Meilleur position de la reine
		 int			h;
		 */
		ks[col]->lineOldPos = Chessboard_getKeenPos(pBoard, col);
		
		//Recherche de la plus petite valeur de H
		for(int line = 0; line < pBoard->size; line++){
			
		}
	
	}
	
	
	//Appliquer la modification sur la matrice
	return newState;
}

//Retourne un KeenState pour une colonne donnée
//pKeenState

//Clone la matrice
pChessboard Chessboard_clone(pChessboard pBoardToClone){

	pChessboard pBoard = _malloc(sizeof(Chessboard));
	
	pBoard->size = pBoardToClone->size;
	
	//Alloc des lignes
	pBoard->queens = _malloc(pBoardToClone->size * sizeof(int*));
	
	//Alloc des colonnes
	for(int line = 0;line < pBoard->size; line++){ 
		pBoard->queens[line] = _malloc(pBoardToClone->size * sizeof(*pBoard->queens[0]));
		
		//Init de l'échéquier de façon aléatoire
		for(int col = 0; col < pBoard->size; col++){
			pBoard->queens[line][col] = pBoardToClone->queens[line][col];
		}
	}
	
	return pBoard;
}

int Chessboard_getKeenPos(pChessboard pBoard, int col){
	
	for(int line = 0;line < pBoard->size; line++){ 
		if(pBoard->queens[line][col] == 1){
			return line;
		}
	}
	
	return -1;
}


//Test si 2 échéqués son identique
bool Chessboard_equals(pChessboard pBoardB, pChessboard pBoardA){

	if(pBoardA == pBoardB){
		return true;
	}
	
	if(pBoardA->size != pBoardB->size){
		return false;
	}
	
	for(int line = 0;line < pBoardB->size; line++){ 
	for(int col = 0; col < pBoardB->size; col++){
		if(!pBoardA->queens[line][col] == pBoardB->queens[line][col]){return false;}
	}}
	
	return true;
}

void Chessboard_free(pChessboard pBoard){
	//Désalloc de la matrice
	for(int line = 0;line < pBoard->size; line++){
		_free(pBoard->queens[line]);
	}
	
	_free(pBoard->queens);
	
	_free(pBoard);
	
}
