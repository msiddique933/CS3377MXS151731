/*
* Filename: Assignment6.h
* Date: 11/25/2020
* Author: Maha Siddiuqe
* Email: mxs151731@utdallas.edu
* Description: This is the header file
*/

#ifndef ASSIGNMENT6_H
	#define ASSIGNMENT6_H
	

	#include <iostream>     
	#include <fstream>      
	#include <string>       
	#include <sstream>      
	#include <stdio.h>      
	#include <stdlib.h>     
	#include <stdint.h>	
	#include "cdk.h"
	

	#define MATRIX_WIDTH 3
	#define MATRIX_HEIGHT 5
	#define BOX_WIDTH 20
	#define MATRIX_NAME_STRING "Binary File Contents"
	

	using namespace std;
	

	/* HEADER RECORD FROM BINARY FILE, (Given in the assignment) */
	class BinaryFileHeader
	{
	  public:
	    uint32_t magicNumber;               
	    uint32_t versionNumber;
	    uint64_t numRecords;
	};
	

	
	const int maxRecordStringLength = 25;
	

	class BinaryFileRecord
	{
	  public:
	    uint8_t strLength;
	    char stringBuffer[maxRecordStringLength];
	};
	

	
	void display(string [MATRIX_HEIGHT + 1][MATRIX_WIDTH + 1]);
	

	#endif /* ASSIGNMENT6_H */

