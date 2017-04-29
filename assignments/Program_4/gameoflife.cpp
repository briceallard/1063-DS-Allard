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
		// hide cursor while printing
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

	bool OnBoard(int row, int col) {
		return (row >= 0 && row < Rows && col >= 0 && col < Cols);
	}

	bool IsCorner(int row, int col) {
		return ((row == 0 && col == 0)			// Top Left corner
			|| (row == 0) && col == (Cols - 1)) // Top Right Corner
			|| (row == (Rows - 1) && (col == 0)) // Bottom Left corner
			|| (row == (Rows - 1) && (col == Cols - 1)); // Bottom Right corner
	}

	void RandomPopulate(int num) {
		int r = 0;
		int c = 0;

		for (int i = 0; i<num; i++) {
			r = rand() % Rows;
			c = rand() % Cols;
			Board[r][c] = 1;
		}
	}

	void SetCell(int r, int c, int val) {
		Board[r][c] = val;
	}

	void AddGens() {
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				Board[i][j] += Board2[i][j];
			}
		}
		ResetBoardArray(Board2);
	}

	void clear_screen(int lines) {
		for (int i = 0; i<lines; i++) {
			cout << endl;
		}
	}

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

int main() {
	int UserInputMenu, UserInputTimer, timer, rows, cols = 0;

	cout << "///////////////////////////////////////////////" << endl
		<< "//       Project:    Game Of Life           ///" << endl
		<< "//       Name:       Brice Allard           ///" << endl
		<< "///////////////////////////////////////////////" << endl
		<< endl;

	cout << "1. Random (Borderless)" << endl
		<< "2. Random (Bordered)" << endl
		<< "3. Glider Gun (Borderless)" << endl
		<< "4. Glider Gun (Bordered)" << endl
		<< "5. Exit" << endl
		<< "Choose (1-5): ";
	cin >> UserInputMenu;
	
	system("CLS");

	cout << "///////////////////////////////////////////////" << endl
		<< "//       Project:    Game Of Life           ///" << endl
		<< "//       Name:       Brice Allard           ///" << endl
		<< "///////////////////////////////////////////////" << endl
		<< endl;
	cout << "Enter your grid (world) size:" << endl
		<< "Rows (Recommended Value = 26): ";
	cin >> rows;
	cout << "Cols (Recommended Value = 80): ";
	cin >> cols;

	system("CLS");

	cout << "///////////////////////////////////////////////" << endl
		<< "//       Project:    Game Of Life           ///" << endl
		<< "//       Name:       Brice Allard           ///" << endl
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

	return 0;
}