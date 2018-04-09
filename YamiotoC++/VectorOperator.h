#pragma once

#include <DxLib.h>

//==�x�N�g���̃I�y���[�^�[�Ɋւ���w�b�_�[

VECTOR operator-( VECTOR& vecA, VECTOR& vecB );		//�x�N�g���̍�
bool operator==( VECTOR& vecA, VECTOR& vecB );		//�x�N�g���̑���


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