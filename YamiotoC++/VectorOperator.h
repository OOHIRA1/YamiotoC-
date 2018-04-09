#pragma once

#include <DxLib.h>

//==ベクトルのオペレーターに関するヘッダー

VECTOR operator-( VECTOR& vecA, VECTOR& vecB );		//ベクトルの差
bool operator==( VECTOR& vecA, VECTOR& vecB );		//ベクトルの相等


VECTOR operator-( VECTOR& vecA, VECTOR& vecB ) {
	VECTOR vec;
	vec.x = vecA.x - vecB.x;
	vec.y = vecA.y - vecB.y;
	vec.z = vecA.z - vecB.z;
	return vec;
}


bool operator==( VECTOR& vecA, VECTOR& vecB ) {
	return ( vecA.x == vecB.x && vecA.y == vecB.y && vecA.z == vecB.z );
}