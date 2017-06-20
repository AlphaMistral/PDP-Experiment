//
//  Matrix.cpp
//  PDP-Experiment
//
//  Created by 于京平 on 2017/6/19.
//  Copyright © 2017年 于京平. All rights reserved.
//

#include "Matrix.hpp"

Matrix :: Matrix(int nn, int mm)
{
	n = nn;
	m = mm;
	if(n == 0 || m == 0)
	{
		mat = NULL;
	}
	else
	{
		mat = new double*[n];
		for(int i = 0;i < n;i++)
			mat[i] = new double[m];
	}
}

Matrix Matrix :: operator * (const double x)
{
	Matrix res(n, m);
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < m;j++)
			res.mat[i][j] = mat[i][j] * x;
	}
	return res;
}

Matrix Matrix :: operator + (const Matrix &tar)
{
	if(n != tar.n || m != tar.m)
	{
		std::string msg = fromptf("FATAL ERROR! You are trying to add two matrices with different scales! Nothing is done but a Matrix of scale 0 * 0 is returned. \n");
		std::cout << msg;
		LogManager::AppendToLog(msg);
		return Matrix(0, 0);
	}
	Matrix res(n, m);
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < m;j++)
		{
			res.mat[i][j] = mat[i][j] + tar.mat[i][j];
		}
	}
	return res;
}

Matrix Matrix :: operator * (const Matrix &tar)
{
	if(m != tar.n)
	{
		std::string msg = fromptf("FATAL ERROR! You are trying to multiply two matrices with invalid scales! Nothing is done but a Matrix of scale 0 * 0 is returned. \n");
		std::cout << msg;
		LogManager::AppendToLog(msg);
		return Matrix(0, 0);
	}
	Matrix res(n, tar.m);
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < tar.m;j++)
		{
			res.mat[i][j] = 0.0;
			for(int k = 0;k < n;k++)
				res.mat[i][j] += mat[i][k] * tar.mat[k][j];
		}
	}
	return res;
}
