
/*
	* Filename:		main.cc
	* Date:			11/25/2020
	* Author:		Maha Siddique
	* Email:		mxs151731@utdallas.edu
	* Description: This is the source code for assignment 6 using the example from Dr.Perkins 
	*/
	

	

	 
	#include "Assignment6.h"
	

	int main()
	{
	  string matrix[MATRIX_HEIGHT + 1][MATRIX_WIDTH + 1];			
	  ifstream file("/scratch/perkins/cs3377.bin", ios::in | ios::binary);
	  
	  if(!file.is_open())
	  {
	    cerr << "File did not open!" << endl;
	    exit(EXIT_FAILURE);
	  }
	  
	  
	  BinaryFileHeader *header = new BinaryFileHeader();
	  
	  if(!file.read((char *) header, sizeof(BinaryFileHeader)))
	  {
	    cerr << "Corrupted Read!" << endl;
	    cerr << "Debugging.." << endl;
	    cerr << "# of Bytes Read (Before Error): " << file.gcount() << endl;
	    exit(EXIT_FAILURE);
	  }
	

	  stringstream ssh;								
	  ssh << "NumRecords: " << header->numRecords;
	  matrix[1][3] = ssh.str();
	  ssh.str("");									
	  ssh.clear();
	  
	  // Place "Version Number" Into Matrix
	  ssh << "Version: " << header->versionNumber;
	  matrix[1][2] = ssh.str();
	  ssh.str("");
	  ssh.clear();
	  
	  //Magic number placement
	  ssh << "Magic: 0x" << hex << uppercase <<  header->magicNumber;		
	  matrix[1][1] = ssh.str();
	  ssh.str("");
	  ssh.clear();
	

	  stringstream ssd;								
	  BinaryFileRecord *record = new BinaryFileRecord();
	  uint64_t numRecords = header->numRecords < 4 ? header->numRecords : 4; //Maximim number of records read	
	

	  for(uint64_t i = 2; i < numRecords + 2; i++)
	  {
	    if(!file.read((char *) record, sizeof(BinaryFileRecord)))
	    {
	      cerr << "Corrupted Reading!" << endl;
	      cerr << "Debugging..." << endl;
	      cerr << "# of Bytes Read (Before Error): " << file.gcount() << endl;
	      exit(EXIT_FAILURE);
	    }
	    
	    ssd << "strlen: " << (int) record->strLength;				
	

	    matrix[i][1] = ssd.str();							
	    matrix[i][2] = record->stringBuffer;					
	

	    ssd.str(""); 							    	
	    ssd.clear();
	  }
	

	  file.close();
	  display(matrix);	
	}

