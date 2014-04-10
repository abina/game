#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

#define N 10
bool szMaze[N][N];
bool sz[N][N];

void PrintMaze() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (szMaze[i][j]) {
				cout << 1;
			}
			else {
				cout << ".";
			}
		}
		cout << endl;
	}
}



void CreateMaze(int row, int col) {
	srand(time(NULL));

	int szLR[4] = {-1, 0, 1, 0};
	int szUD[4] = {0, -1, 0, 1};
	int d = rand() % 4;
	int dd = rand() % 2 ? 1 : 3;

	for (int i = 0; i < 4; i++) {
		int r = row + szLR[d];
		int c = col + szUD[d];

		if (r > 0 && r < (N - 1) && c > 0 && c < (N - 1) && !szMaze[r][c]) {
			if (((int)szMaze[r][c-1] + (int)szMaze[r][c+1] + (int)szMaze[r+1][c] + (int)szMaze[r-1][c]) == 1) {
				szMaze[r][c] = true;
				CreateMaze(r, c);
			}
		}
		d = (d + dd) % 4;
	}
}
int main() {
	szMaze[1][1] = true;
	CreateMaze(1, 1);
	PrintMaze();
}
