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
}

void equalsBool(bool a, const char* msg){
	equals((int)a, true, msg);
}

void testChessboard(){
	
	//Test1
	pChessboard t = Chessboard_constructor(5);
	
	int values[] = {0,0,0,0,1,
					0,0,0,0,0,
					1,0,0,0,0,
					0,0,1,1,0,
					0,1,0,0,0};
	
	Chessboard_setKeens(t, values);

	equals(Chessboard_getH(t), 2, "Test du H (taille 5)");
	
	Chessboard_free(t);
	
	//Test 2
	t = Chessboard_constructor(4);
	
	int values2[] = {	1,1,0,0,
						0,0,1,0,
						0,0,0,0,
						0,0,0,1};
	
	Chessboard_setKeens(t, values2);
	
	equals(Chessboard_getH(t), 3, "Test du H ");

	Chessboard_free(t);
	
	//Test 3
	t = Chessboard_constructor(4);
	
	int values3[] = {	1,1,0,0,
						0,0,1,0,
						0,0,0,1,
						0,0,0,0};
	
	Chessboard_setKeens(t, values3);
	
	//Chessboard_draw(t);
	
	equals(Chessboard_getH(t), 4, "Test du H");
	
	Chessboard_free(t);

	//Test 4
	t = Chessboard_constructor(3);
	
	int values4[] = {	1,0,0,
						0,1,0,
						0,0,1};
	
	Chessboard_setKeens(t, values4);
	
	//Chessboard_draw(t);
	
	equals(Chessboard_getH(t), 3, "Test du H");
	
	Chessboard_free(t);

	testEqualsClone();
}

void testEqualsClone(){
	pChessboard firstMatrix = Chessboard_constructor(5);
	
	int values[] = {0,0,0,0,1,
					0,0,0,0,0,
					1,0,0,0,0,
					0,0,1,1,0,
					0,1,0,0,0};
	
	Chessboard_setKeens(firstMatrix, values);
	
	pChessboard cloneMatrix = Chessboard_clone(firstMatrix);
	
	equalsBool(Chessboard_equals(cloneMatrix, firstMatrix), "Clonage");
	
	Chessboard_free(firstMatrix);
	Chessboard_free(cloneMatrix);

}