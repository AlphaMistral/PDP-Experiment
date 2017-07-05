//
//  Matrix.hpp
//  PDP-Experiment
//
//  Created by 于京平 on 2017/6/19.
//  Copyright © 2017年 于京平. All rights reserved.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <cstdio>
#include <cstdlib>

#include "LogManager.hpp"

class Matrix
{
public:
	int n, m;
	double **mat;
	Matrix(int, int);
	Matrix operator + (const Matrix &);
	Matrix operator * (const double);
	Matrix operator * (const Matrix &);
};

#endif /* Matrix_hpp */
