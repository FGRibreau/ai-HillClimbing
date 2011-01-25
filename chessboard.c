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
	,	nbQueen = 0
	,	i =0
	,	col = 0
	,	line = 0
	,	x = 0
	,	upCol = 0
	,	upLine = 0
	,	dwCol = 0
	,	dwLine = 0;
	
	
	//Pour chaque ligne, calculer le nombre de saut
	for(i = 0; i < pBoard->size; i++){
		//Trouver nombre de reine pour cette ligne
		nbQueen = 0;
		
		for(x = 0; x < pBoard->size; x++){
			if(pBoard->queens[i][x] == 1){
				nbQueen++;
			}
		}
		
		if(nbQueen > 1){
			//printf("(line) h = (h = %i) + %i\n", h, (nbQueen*(nbQueen-1))/2);
		}
		
		h += nbQueen > 1 ? (nbQueen*(nbQueen-1))/2 : 0;
	}

	
	//Pour chaque colonne trouver le nombre de saut
	for(col = 0; col < pBoard->size; col++){
		nbQueen = 0;
		
		for(x = 0; x < pBoard->size; x++){
			if(pBoard->queens[x][col] == 1){
				nbQueen++;
			}
		}
		
		/*if(nbQueen > 1){
			printf("(col)  h = (h = %i) + %i\n", h, (nbQueen*(nbQueen-1))/2);
		}*/
		
		h += nbQueen > 1 ? (nbQueen*(nbQueen-1))/2 : 0;
	}

	//Parcourir les reines de haut en bas, de gauche à droite
	//En diagonale vers le haut, en diag vers le bas
	
	for(col = 0; col < pBoard->size; col++){
	for(line = 0; line < pBoard->size; line++){
		
		if(pBoard->queens[line][col] == 1){
			nbQueen = 0;
			
			upCol = dwCol = col;
			upLine = dwLine = line;
			
			
			//Vers la diagonale haute
			while(upCol < pBoard->size && upLine >= 0){
				
				if(pBoard->queens[upLine][upCol] == 1){
					nbQueen++;
				}
				
				upCol++;
				upLine--;
			}
			
			/*if(nbQueen > 1){
				printf("(up)  h = (h = %i) + %i\n", h, (nbQueen*(nbQueen-1))/2);
			}*/
			
			//h += nbQueen > 1 ? (nbQueen*(nbQueen-1))/2 : 0;
			h += nbQueen > 1 ? nbQueen-1 : 0;
			nbQueen = 0;
			
			//printf("\n");
			
			//Vers la dialognale basse
			while(dwCol < pBoard->size && dwLine < pBoard->size){
				
				if(pBoard->queens[dwLine][dwCol] == 1){
					//printf("(dw) [%i][%i]\n", dwLine, dwCol);
					nbQueen++;
				}
				
				dwCol++;
				dwLine++;
			}

			/*if(nbQueen > 1){
				printf("(dw)  h = (h = %i) + %i\n", h, (nbQueen*(nbQueen-1))/2);
			}*/
			
			//h += nbQueen > 1 ? ((nbQueen*(nbQueen-1))/2) : 0;
			h += nbQueen > 1 ? nbQueen-1 : 0;
		}
	
	}}
	
	return h;
}


void Chessboard_draw(pChessboard pBoard){
	/*for(int y = 0; y < pBoard->size; y++){
		for(int x = 0; x < pBoard->size; x++){
			printf("%i ", pBoard->queens[y][x]);
		}
		
		printf("\n");
	}*/
	
	__drawMatrix(pBoard->queens, pBoard->size);
}

void __drawMatrix(int** mat, int size){
	
	for(int y = 0; y < size; y++){
		for(int x = 0; x < size; x++){
			printf("%i ", mat[y][x]);
		}
		
		printf("\n");
	}
}

void Chessboard_setQueens(pChessboard pBoard, int* values){
	
	int i = 0;
	
	for(int line = 0; line < pBoard->size; line++){
		for(int col = 0; col < pBoard->size; col++){
			pBoard->queens[line][col] = values[i++];
		}
	}
}

//Prendre le dernier état du stack
pChessboard Chessboard_getNextState(pChessboard pBoardCurrentState){
	
	printf("---------------\n");
	
	pChessboard pBoard = Chessboard_clone(pBoardCurrentState);

	pMatrix hMat = Matrix_constructor(pBoard);
	
	
	
	printf("\nMatrice H:\n");
	__drawMatrix(hMat->values, pBoard->size);
	printf("\n");
	
	/*int** = _malloc(sizeof(int*) * pBoard->size);
	int i = pBoard->size;
	
	while(i--){
	
	}*/
	//[H,X,Y]
	
	//Filtrer la matrice ne récupérer que les éléments les plus petit
	for(int line = 0; line < pBoard->size; line++){
		for(int col = 0; col < pBoard->size; col++){
				
		}
	}
	
	Matrix_destructor(hMat);
	
	return pBoard;
}

//Retourne un QueenState pour une colonne donnée

pMatrix Matrix_constructor(pChessboard pBoard){
	pMatrix hMat = _malloc(sizeof(Matrix));
	
	
	hMat->size = pBoard->size;
	//La matrice de taille [][] qui contient les H
	hMat->values = _malloc(sizeof(int*) * hMat->size);
	
	int i = hMat->size;
	while(i--){
		hMat->values[i] = _malloc(sizeof(int) * hMat->size);
	}
	
	
	//1 - Pour chaque case de matH, remplacer par le H lorsque l'on déplace la reine de cette colonne à cette ligne
	int queenOldPos = 0;
	
	for(int col = 0; col < hMat->size; col++){
		
		queenOldPos = Chessboard_getQueenPos(pBoard, col);		
		
		//Enlever la position de la reine pour cette colonne
		pBoard->queens[queenOldPos][col] = 0;
		
		//Parcours des lignes de cette colonne
		for(int line = 0; line < hMat->size; line++){
			pBoard->queens[line][col] = 1;
			
			hMat->values[line][col] = Chessboard_getH(pBoard);
			
			pBoard->queens[line][col] = 0;
		}
		
		//Remettre la position de la reine pour cette colonne
		pBoard->queens[queenOldPos][col] = 1;
	}
	
	return hMat;
}

//Désallocation de la matrice
void Matrix_destructor(pMatrix mat){

	while(mat->size--){
		_free(mat->values[mat->size]);
	}
	_free(mat);
}

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

int Chessboard_getQueenPos(pChessboard pBoard, int col){
	
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
