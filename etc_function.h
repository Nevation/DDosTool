#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#pragma warning(disable:4996)
using namespace std;


typedef unsigned char uchar;

vector<string> str_split(string str, const char point);

vector<uchar> MakeDummy(vector<uchar> packet);
