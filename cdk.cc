/*
	 * Filename:    cdk.cc
	 * Date:        11/25/2020
	 * Author:      Maha Siddique
	 * Email:       mxs151731@utdallas.edu
	 * About file: This file has the CDK Matrix in data records and displays all the headers
	 */
	 
	 #include "Assignment6.h"
	

	void display(string matrix[MATRIX_HEIGHT + 1][MATRIX_WIDTH + 1])
	{
	  WINDOW        *window;
	  CDKSCREEN     *cdkscreen;
	  CDKMATRIX     *myMatrix;           	// CDK Screen Matrix
	

	  const char    *rowTitles[MATRIX_HEIGHT+1] =   {"x", "a", "b", "c", "d", "e"};
	  const char    *columnTitles[MATRIX_WIDTH+1] = {"x", "a", "b", "c"};
	  int           boxWidths[MATRIX_WIDTH+1] =     {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH};
	  int           boxTypes[MATRIX_WIDTH+1] =      {vMIXED, vMIXED, vMIXED, vMIXED};
	

	  //Begin the CDK 
	  window = initscr();
	  cdkscreen = initCDKScreen(window);
	

	

	  initCDKColor();
	

	  // Create the matrix.  Need to manually cast (const char**) to (char **)
	  myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH,
	                          MATRIX_NAME_STRING, (char **) rowTitles, (char **) columnTitles, boxWidths,
				  boxTypes, 1, 1, ' ', ROW, true, true, false);
	

	  if(myMatrix == NULL)
	  {
	    printf("Error in creating the  Matrix\n");
	    exit(1);
	  }
	

	  // Display the Matrix
	  drawCDKMatrix(myMatrix, true);
	

	  // Present a message
	  for(int r = 1; r < MATRIX_HEIGHT + 1; r++)
	  {
	    for(int c = 1; c < MATRIX_WIDTH + 1; c++)
	    {
	      setCDKMatrixCell(myMatrix, r, c, matrix[r][c].c_str());
	    }
	  }
	

	  drawCDKMatrix(myMatrix, true);        
	

	  // This allows the CDK to exit if it is selected
	  if(getchar())
	    endCDK();     			
	}

