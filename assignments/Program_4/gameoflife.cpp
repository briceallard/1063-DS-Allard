/**
* @ProgramName: Program-4
* @Author: Brice Allard
* @Description:
*     Game of Life uses a 2d array of values to represent "life" in a given cell.
*		Certain rules are applied to determine whether life continues or death occurs.
*		These rules are as follows:
*
*		1. Any live cell with fewer than two live neighbours dies, as if caused by underpopulation.
*		2. Any live cell with two or three live neighbours lives on to the next generation.
*		3. Any live cell with more than three live neighbours dies, as if by overpopulation.
*		4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 28 04 2017
*/

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

class GameOfLife {
private:
	int **Board;
	int **Board2;
	int Rows;
	int Cols;
	bool StableCntr;

public:
	/**
	* @FunctionName: GameOfLife
	* @Description:
	*     Generates the Class GameOfLife
	* @Params:
	*    string filename - imports the .txt file for initial load
	* @Returns:
	*    void
	*/
	GameOfLife(string filename) {
		string line;
		char ch;

		ifstream fin;
		fin.open(filename);
		fin >> Rows >> Cols;

		InitBoardArray(Board);
		InitBoardArray(Board2);

		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				fin.get(ch);
				if (ch == 10) {
					continue;
				}
				Board[i][j] = int(ch) - 48;
			}
		}
	}

	/**
	* @FunctionName: GameOfLife
	* @Description:
	*     Generates the Class GameOfLife
	* @Params:
	*    int r - Total rows for 2d array to create
	*	 int c - Total columns for 2d array to create
	* @Returns:
	*    void
	*/
	GameOfLife(int r, int c) {
		Rows = r;
		Cols = c;

		InitBoardArray(Board);
		InitBoardArray(Board2);
		PrintBoard();
	}

	void InitBoardArray(int **&b) {
		b = new int*[Rows];

		for (int i = 0; i < Rows; i++) {
			b[i] = new int[Cols];
		}
		ResetBoardArray(b);
	}

	void ResetBoardArray(int **&b) {
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				b[i][j] = 0;
			}
		}
	}

	void PrintBoard() {
		// Hide Cursor while printing
		CONSOLE_CURSOR_INFO cursorInfo;
		GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
		cursorInfo.bVisible = false;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				if (Board[i][j] == 1)
					cout << char('X');
				else
					cout << " ";
			}
			cout << endl;
		}
	}

	void GliderGun(GameOfLife G) {
		// Left Block
		G.SetCell(5, 1, 1);
		G.SetCell(5, 2, 1);
		G.SetCell(6, 1, 1);
		G.SetCell(6, 2, 1);
		//Left Gun
		G.SetCell(5, 11, 1);
		G.SetCell(6, 11, 1);
		G.SetCell(7, 11, 1);
		G.SetCell(4, 12, 1);
		G.SetCell(8, 12, 1);
		G.SetCell(3, 13, 1);
		G.SetCell(9, 13, 1);
		G.SetCell(3, 14, 1);
		G.SetCell(9, 14, 1);
		G.SetCell(6, 15, 1);
		G.SetCell(4, 16, 1);
		G.SetCell(8, 16, 1);
		G.SetCell(5, 17, 1);
		G.SetCell(6, 17, 1);
		G.SetCell(7, 17, 1);
		G.SetCell(6, 18, 1);
		//Right Gun
		G.SetCell(3, 21, 1);
		G.SetCell(4, 21, 1);
		G.SetCell(5, 21, 1);
		G.SetCell(3, 22, 1);
		G.SetCell(4, 22, 1);
		G.SetCell(5, 22, 1);
		G.SetCell(2, 23, 1);
		G.SetCell(6, 23, 1);
		G.SetCell(1, 25, 1);
		G.SetCell(2, 25, 1);
		G.SetCell(6, 25, 1);
		G.SetCell(7, 25, 1);
		// Right Block
		G.SetCell(3, 35, 1);
		G.SetCell(4, 35, 1);
		G.SetCell(3, 36, 1);
		G.SetCell(4, 35, 1);
	}

	/**
	* @FunctionName: CountNeightborsEndless
	* @Description:
	*     Calculates the total neighbors for an ever existing plane
	* @Params:
	*    row & col - The current cell to examine neighbors for
	* @Returns:
	*    int neighbors
	*/
	int CountNeighborsEndless(int row, int col) {
		int neighbors = 0;
		if (Board[row][col] == 1) {
			neighbors--;
		}
		for (int i = row - 1; i <= row + 1; i++) {
			for (int j = col - 1; j <= col + 1; j++)
				neighbors += Board[(i + Rows) % Rows][(j + Cols) % Cols];
		}
		return neighbors;
	}

	/**
	* @FunctionName: CountNeightbors
	* @Description:
	*     Calculates the total neighbors for a plane that does not exceed its borders
	* @Params:
	*    row & col - The current cell to examine neighbors for
	* @Returns:
	*    int neighbors
	*/
	int CountNeighbors(int row, int col) {
		int neighbors = 0;

		if (Board[row][col] == 1) {
			neighbors--;
		}
		for (int i = row - 1; i <= row + 1; i++) {
			for (int j = col - 1; j <= col + 1; j++) {
				if (OnBoard(i, j)) {
					neighbors += Board[i][j];
				}
			}
		}
		return neighbors;
	}

	/**
	* @FunctionName: OnBoard
	* @Description:
	*     Determines whether or not the current cell is in the plane of excistence
	* @Params:
	*    row & col - The current cell to examine
	* @Returns:
	*    bool true or false (is or isn't on the board)
	*/
	bool OnBoard(int row, int col) {
		return (row >= 0 && row < Rows && col >= 0 && col < Cols);
	}

	/**
	* @FunctionName: IsCorner
	* @Description:
	*     Determines whether or not the current cell is the corner of the plane of existence
	* @Params:
	*    row & col - The current cell to examine
	* @Returns:
	*    bool true or false (is or isn't corner of the board)
	*/
	bool IsCorner(int row, int col) {
		return ((row == 0 && col == 0)			// Top Left corner
			|| (row == 0) && col == (Cols - 1)) // Top Right Corner
			|| (row == (Rows - 1) && (col == 0)) // Bottom Left corner
			|| (row == (Rows - 1) && (col == Cols - 1)); // Bottom Right corner
	}

	/**
	* @FunctionName: RandomPopulate
	* @Description:
	*     Randomly generates life in cells
	* @Params:
	*    num - the number of cells that should be generated with life
	* @Returns:
	*    void
	*/
	void RandomPopulate(int num) {
		int r = 0;
		int c = 0;

		for (int i = 0; i<num; i++) {
			r = rand() % Rows;
			c = rand() % Cols;
			Board[r][c] = 1;
		}
	}

	/**
	* @FunctionName: SetCell
	* @Description:
	*     Generates life in given cell
	* @Params:
	*    row & col - The current cell to add life too
	*	 val - 1 represents life, 0 dead, -1 kill next generation
	* @Returns:
	*    void
	*/
	void SetCell(int r, int c, int val) {
		Board[r][c] = val;
	}

	/**
	* @FunctionName: AddGens
	* @Description:
	*     Adds the values between board1 and board2 for next generation
	* @Params:
	*    none
	* @Returns:
	*    void
	*/
	void AddGens() {
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				Board[i][j] += Board2[i][j];
			}
		}
		ResetBoardArray(Board2);
	}

	/**
	* @FunctionName: clear_screen
	* @Description:
	*     Clears the screen before print of next generation (Currently an unused function - replaced with system("CLS") )
	* @Params:
	*    lines - number of lines to clear
	* @Returns:
	*    void
	*/
	void clear_screen(int lines) {
		for (int i = 0; i<lines; i++) {
			cout << endl;
		}
	}

	/**
	* @FunctionName: RunEndless
	* @Description:
	*     Determines neighbors and executes rules for life or death of given cell
	*	  This function makes the plane endless so cells running off the plane of
	*	  existence are returned to the opposite side of the plane to represent endless
	*	  life
	* @Params:
	*    generations - how many times will it cycle through before auto-exiting
	*	 timer - the delay for system pause before printing the next generation
	* @Returns:
	*    void
	*/
	void RunEndless(int generations, int timer) {
		int neighbors = 0;
		int g = 0;

		while (g < generations) {
			StableCntr = false;

			for (int i = 0; i < Rows; i++) {
				for (int j = 0; j < Cols; j++) {
					neighbors = CountNeighborsEndless(i, j);
					if (Board[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
						Board2[i][j] = -1;
						StableCntr = true;
					}
					if (Board[i][j] == 0 && neighbors == 3) {
						Board2[i][j] = 1;
						StableCntr = true;
					}
				}
			}
			AddGens();
			Sleep(timer);

			//Check to see if any cell has moved
			if (!StableCntr)
				break;
			StableCntr = false;

			system("CLS");
			PrintBoard();
			g++;
		}

	}

	/**
	* @FunctionName: Run
	* @Description:
	*     Determines neighbors and executes rules for life or death of given cell
	*	  This function allows the plane of existence to end allowing the cells to
	*	  simply dissapear from the grid
	* @Params:
	*    generations - how many times will it cycle through before auto-exiting
	*	 timer - the delay for system pause before printing the next generation
	* @Returns:
	*    void
	*/
	void Run(int generations, int timer) {
		int neighbors = 0;
		int g = 0;

		while (g < generations) {
			StableCntr = 0;

			for (int i = 0; i < Rows; i++) {
				for (int j = 0; j < Cols; j++) {
					if (!IsCorner(i, j)) {
						neighbors = CountNeighbors(i, j);
						if (Board[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
							Board2[i][j] = -1;
							StableCntr = true;
						}
						if (Board[i][j] == 0 && neighbors == 3) {
							Board2[i][j] = 1;
							StableCntr = true;
						}
					}
					else if (IsCorner(i, j)) {
						Board2[i][j] = -1;
					}
				}
			}
			AddGens();
			Sleep(timer);

			//Check to see if any cell has moved
			if (!StableCntr)
				break;
			StableCntr = false;

			system("CLS");
			PrintBoard();
			g++;
		}

	}
};

/**
* @FunctionName: main
* @Description:
*     Initialize menu for user and execute all functions
* @Params:
*    None
* @Returns:
*    int - return 0 to exit program
*/
int main() {
	int UserInputMenu, UserInputTimer, timer, rows, cols = 0;

	//User menu for operations to execute
	cout << "///////////////////////////////////////////////" << endl
		<< "//       Project:    Game Of Life           ///" << endl
		<< "//       Name:       Brice Allard           ///" << endl
		<< "//                                          ///" << endl
		<< "//       Note:       Corners die in         ///" << endl
		<< "//                   Bordered worlds ONLY   ///" << endl
		<< "///////////////////////////////////////////////" << endl
		<< endl;

	// Select style of GameOfLife
	cout << "1. Random (Borderless)" << endl
		<< "2. Random (Bordered)" << endl
		<< "3. Glider Gun (Borderless)" << endl
		<< "4. Glider Gun (Bordered)" << endl
		<< "5. Exit" << endl
		<< "Choose (1-5): ";
	cin >> UserInputMenu;
	
	while (UserInputMenu != 5) {
		system("CLS");

		//Select grid size
		cout << "///////////////////////////////////////////////" << endl
			<< "//       Project:    Game Of Life           ///" << endl
			<< "//       Name:       Brice Allard           ///" << endl
			<< "//                                          ///" << endl
			<< "//       Note:       Corners die in         ///" << endl
			<< "//                   Bordered worlds ONLY   ///" << endl
			<< "///////////////////////////////////////////////" << endl
			<< endl;
		cout << "Enter your grid (world) size:" << endl
			<< "Rows (Recommended Value = 26): ";
		cin >> rows;
		cout << "Cols (Recommended Value = 80): ";
		cin >> cols;

		system("CLS");

		// Select speed of animation
		cout << "///////////////////////////////////////////////" << endl
			<< "//       Project:    Game Of Life           ///" << endl
			<< "//       Name:       Brice Allard           ///" << endl
			<< "//                                          ///" << endl
			<< "//       Note:       Corners die in         ///" << endl
			<< "//                   Bordered worlds ONLY   ///" << endl
			<< "///////////////////////////////////////////////" << endl
			<< endl;
		cout << "Please choose a speed:" << endl
			<< "1. Slow" << endl
			<< "2. Medium" << endl
			<< "3. Fast" << endl
			<< "Choose (1-3): ";
		cin >> UserInputTimer;

		GameOfLife G(rows, cols);
		system("CLS");

		if (UserInputMenu == 1) {
			if (UserInputTimer == 1)
				timer = 500;
			else if (UserInputTimer == 2)
				timer = 100;
			else if (UserInputTimer == 3)
				timer = 30;
			else
				timer = 100;

			system("CLS");

			G.RandomPopulate(1000);
			G.RunEndless(10000, timer);
		}
		else if (UserInputMenu == 2) {
			if (UserInputTimer == 1)
				timer = 500;
			else if (UserInputTimer == 2)
				timer = 100;
			else if (UserInputTimer == 3)
				timer = 30;
			else
				timer = 100;

			system("CLS");

			G.RandomPopulate(1000);
			G.Run(10000, timer);
		}
		else if (UserInputMenu == 3) {
			if (UserInputTimer == 1)
				timer = 500;
			else if (UserInputTimer == 2)
				timer = 100;
			else if (UserInputTimer == 3)
				timer = 30;
			else
				timer = 100;

			system("CLS");

			G.GliderGun(G);
			G.RunEndless(10000, timer);
		}
		else if (UserInputMenu == 4) {
			if (UserInputTimer == 1)
				timer = 500;
			else if (UserInputTimer == 2)
				timer = 100;
			else if (UserInputTimer == 3)
				timer = 30;
			else
				timer = 100;

			system("CLS");

			G.GliderGun(G);
			G.Run(10000, timer);
		}
		else {
			system("CLS");
			cout << "You either selected Exit or can't read instructions. Goodbye!" << endl;
			system("pause");
		}
	}

	return 0;
}
