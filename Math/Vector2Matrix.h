#pragma once
#include "Vector2My.h"

/// <summary>
/// 2x2Matrixベクトル
/// </summary>
struct Matrix2x2 final
{
	float m[2][2];
};

/// <summary>
/// 3x3Matrixベクトル
/// </summary>
struct Matrix3x3 final
{
	float m[3][3];
};

/// <summary>
/// 4x4Matrixベクトル
/// </summary>
struct Matrix4x4 final
{
	float m[4][4];
};

struct Quad final
{
	Vector2My lt;
	Vector2My rt;
	Vector2My lb;
	Vector2My rb;
};