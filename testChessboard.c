/*
 *  testChessboard.c
 *  HillClimbing
 *
 *  Created by Francois-Guillaume Ribreau on 24/01/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "testChessboard.h"

void equals(int a, int b, const char* msg){
	if(a == b){
		printf("[Ok] %s\n", msg);
	} else {
		printf("[Error] %s (attendu:%i retour:%i)\n", msg, b, a);
	}
	
	printf(" %s\n", msg);
}

void testChessboard(){
	
	pChessboard t = Chessboard_constructor(5);
	
	int values[] = {0,0,0,0,1,
		0,0,0,0,0,
		1,0,0,0,0,
		0,0,1,1,0,
		0,1,0,0,0};
	
	Chessboard_setKeens(t, values);

	equals(Chessboard_getH(t), 2, "Test du H");
	
	Chessboard_free(t);
}