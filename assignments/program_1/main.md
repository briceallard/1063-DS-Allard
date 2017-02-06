'''
/**
* @ProgramName: Program-1
* @Author: Brice Allard
* @Description:
*     This program reads in images stored as rgb values in a
*     space delimited file format.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 30 01 2017
*/

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

struct rgb {
	int r;
	int g;
	int b;
};

/**
* @FunctionName: flipVert
* @Description:
*     Loops through a 2D array and flips the rows of array in order to manipulate
*	the output to obtain a vertical flip of the original input.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/
void flipVert(rgb** image, int width, int height) {
	rgb temp;

	for (int r = 0; r < height / 2; r++) {
		for (int c = 0; c < width; c++) {
			temp = image[r][c];
			image[r][c] = image[height - 1 - r][c];
			image[height - 1 - r][c] = temp;
		}
	}
}

/**
* @FunctionName: flipHorz
* @Description:
*     Loops through a 2D array and flips the columns of array in order to manipulate
*	the output to obtain a horizontal flip of the original input.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/
void flipHorz(rgb** image, int width, int height) {
	rgb temp;

	for (int r = 0; r < height; r++) {
		for (int c = 0; c < width / 2; c++) {
			temp = image[r][c];
			image[r][c] = image[r][width - 1 - c];
			image[r][width - 1 - c] = temp;
		}
	}
}

/**
* @FunctionName: grayScale
* @Description:
*     Loops through a 2D array and turns every RGB value into its 
*	grayscale equivalent.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/
void grayScale(rgb** image, int width, int height) {
	int gray;
	
	for (int r = 0; r < height; r++) {
		for (int c = 0; c < width; c++) {
			gray = (image[r][c].r + image[r][c].g + image[r][c].b) / 3;
			image[r][c].r = gray;
			image[r][c].g = gray;
			image[r][c].b = gray;
		}
	}
}

/**
* @FunctionName: main	
* @Description:
*	Initialized the read in from input.txt and offers the user a menu to
*	 choose which way they would like the manipulate the input.txt
*	 then saves results to output.txt.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/
int main() {
	ifstream ifile;		// input & output files
	ofstream ofile;

	ifile.open("input.txt");
	ofile.open("output.txt");

	int width;		// width of image
	int height;		// height of image
	int selection;

	rgb **imgArray;		// Point var for our 2D Array

	ifile >> width >> height;	//Read in width and height from top of input file
					// We need this so we can make the Array the right
					// size.

	imgArray = new rgb*[height];	// This array points to every row.

	for (int i = 0; i < height; i++) {
		imgArray[i] = new rgb[width];	// Now allocate each row of rgb's
	}
	
	//Read the color data in from our txt file
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			ifile >> imgArray[i][j].r >> imgArray[i][j].g >> imgArray[i][j].b;
		}
	}

	start:
	cout << "Image Size: " << width << 'x' << height << "\n\n";
	cout << "What would you like to do to the image?\n";
	cout << "1. Flip Vertically\n";
	cout << "2. Flip Horizontally\n";
	cout << "3. Gray Scale Image\n";
	cout << "0. Exit\n";
	cout << "(0-3): ";
	cin >> selection;

	if (selection == 0)
		exit(0);
	else if (selection == 1)
		flipVert(imgArray, width, height);
	else if (selection == 2)
		flipHorz(imgArray, width, height);
	else if (selection == 3)
		grayScale(imgArray, width, height);
	else{
		cout << "Invalid selection. Try Again!";
		goto start;
	}

	cout << "Action Successful!\nCheck output.txt for results....\n\n";

	ofile << width << " " << height << endl;

	// Read the color data from our txt file
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			ofile << imgArray[i][j].r << " " << imgArray[i][j].g << " " 
				<< imgArray[i][j].b << " ";
		}
		ofile << endl;
	}

	return 0;
}
'''
