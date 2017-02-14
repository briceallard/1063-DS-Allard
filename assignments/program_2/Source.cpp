/**
* @ProgramName: Program-1
* @Author: Brice Allard
* @Description:
*     This program reads in images stored as rgb values in a
space delimited file format.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 30 01 2017
*/

#include <iostream>
#include <fstream>
#include <math.h>
#include <string.h>

using namespace std;

struct rgb {
	int r;
	int g;
	int b;
};

class ImageManip {
private:
	int width;
	int height;
	ifstream ifile;
	ofstream ofile;
	string ifile_name;
	string ofile_name;
	rgb **image;

public:
	ImageManip() {
		
	}

	void readFile(string input_file) {
		ifile.open(input_file);

		ifile >> width >> height;	//Read in width and height from top of input file
															// We need this so we can make the Array the right
															// size.

		image = new rgb*[height];	// This array points to every row.

		for (int i = 0; i < height; i++) {
			image[i] = new rgb[width];	// Now allocate each row of rgb's
		}

		//Read the color data in from our txt file
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				ifile >> image[i][j].r >> image[i][j].g >> image[i][j].b;
			}
		}
	}

	void writeFile(string ofile_name) {
		ofile.open(ofile_name);

		ofile << width << " " << height << endl;

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				ofile << image[i][j].r << " " << image[i][j].g << " "
					<< image[i][j].b << " ";
			}
			ofile << endl;
		}
	}
	/**
	* @FunctionName: flipVert
	* @Description:
	*     Loops through a 2D array and flips the rows of array in order to manipulate
	*			the output to obtain a vertical flip of the original input.
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
	*			the output to obtain a horizontal flip of the original input.
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
	*			grayscale equivalent.
	* @Params:
	*    rgb** image - 2D array holding rgb values
	*    int width - width of image
	*    int height - height of image
	* @Returns:
	*    void
	*/
	void grayScale() {
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
	* @FunctionName: printImage
	* @Description:
	*     Loops through a 2D array and prints new integers to output.txt
	*			which are the new variables for the changes made to image by
	*			the user.
	* @Params:
	*     rgb** image - 2D array holding rgb values
	*     int width - width of image
	*     int height - height of image
	*			ofstream outfile - output of new RGB's
	* @Returns:
	*    void
	*/
	void printImage(rgb **image, int &width, int &height, ofstream &outfile) {
		cout << height << " " << width << endl;

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				cout << image[i][j].r << " " << image[i][j].g << " "
					<< image[i][j].b << " ";
			}
			cout << endl;
		}
	}

	~ImageManip() {

	}
};

/**
* @FunctionName: main
* @Description:
*		 Initialized the read in from input.txt and offers the user a menu to
*		 choose which way they would like the manipulate the input.txt
*		 then saves results to output.txt.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/
int main() {
	ImageManip Start;
	
	Start.readFile("input.txt");
	Start.grayScale();
	Start.writeFile("grayscale.txt");
}