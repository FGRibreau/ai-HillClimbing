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
	
	//init des cellules (lignes)
	
	pBoard->keens = _malloc(size * sizeof(int*));
	
	//colonnes
	for(int x = 0;x < size; x++){ 
		pBoard->keens[x] = _malloc(size * sizeof(*pBoard->keens[0]));
		
		//Init de l'échéquier de façon aléatoire
		for(int xx = 0; xx < size; xx++){
			pBoard->keens[x][xx] = ((int)(rand() % size) == (size-1)) ? 1 : 0;
		}
	}
	
	return pBoard;
}

//Vide l'echequier
void Chessboard_empty(pChessboard pBoard){
	for(int y = 0; y < pBoard->size; y++){
		for(int x = 0; x < pBoard->size; x++){
			pBoard->keens[y][x] = 0;
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
			if(pBoard->keens[i][x] == 1){
				nbKeen++;
			}
		}
		
		h += nbKeen > 0 ? (nbKeen*(nbKeen-1))/2 : 0;
	}
	
	
	//Pour chaque colonne trouver le nombre de saut
	for(col = 0; col < pBoard->size; col++){
		nbKeen = 0;
		
		for(x = 0; x < pBoard->size; x++){
			if(pBoard->keens[x][col] == 1){
				nbKeen++;
			}
		}
		
		h += nbKeen > 0 ? (nbKeen*(nbKeen-1))/2 : 0;
	}
	
	//Parcourir les reines de haut en bas, de gauche à droite
	//En diagonale vers le haut, en diag vers le bas
	
	for(col = 0; col < pBoard->size; col++){
	for(line = 0; line < pBoard->size; line++){
		
		if(pBoard->keens[line][col] == 1){
			nbKeen = 0;
			x = 0;
			y = 0;
			
			upCol = dwCol = col;
			upLine = dwLine = line;
			
			
			//Vers la diagonale haute
			while(upCol < pBoard->size && upLine >= 0){
				
				if(pBoard->keens[upLine][upCol] == 1){
					nbKeen++;
				}
				
				upCol++;
				upLine--;
			}
			
			h += nbKeen > 0 ? (nbKeen*(nbKeen-1))/2 : 0;
			nbKeen = 0;
			
			//Vers la dialognale basse
			while(dwCol >= 0 && dwLine < pBoard->size){
				if(pBoard->keens[dwLine][dwCol] == 1){
					nbKeen++;
				}
				
				dwCol--;
				dwLine++;
			}
			
			h += nbKeen > 0 ? (nbKeen*(nbKeen-1))/2 : 0;
		}
	
	}}
	
	return h;
}


void Chessboard_draw(pChessboard pBoard){
	for(int y = 0; y < pBoard->size; y++){
		for(int x = 0; x < pBoard->size; x++){
			printf("%d ", pBoard->keens[y][x]);
		}
		
		printf("\n");
	}
}