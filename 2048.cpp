#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int szNum[4][4];
int nPosX;
int nPosY;
int nNewNum;

void PrintNum() {
	for (int i = 0; i < 4; i++) {
		cout << " | ";
		for (int j = 0; j < 4; j++) {
			if (szNum[i][j] == 0) {
				cout << "-";
			}
			else {
				cout << szNum[i][j];
			}
			cout << " | ";
		}
		cout << endl;
	}
}

void NewNum() {
	srand(time(NULL));
	do {
		nPosX = rand() % 4;
		nPosY = rand() % 4;
	}while (szNum[nPosX][nPosY] != 0);

	nNewNum = (rand() % 2 + 1) * 2;
	szNum[nPosX][nPosY] = nNewNum;
}

bool IsAll() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (szNum[i][j] == 0) {
				return false;
			}
		}
	}
	return true;
}

bool IsLose() {
	if (!IsAll()) {
		return false;
	}
	for (int i = 0; i < 4; i++) {
		if ((szNum[i][0] == szNum[i][1]) || (szNum[i][1] == szNum[i][2]) ||
			(szNum[i][2] == szNum[i][3])) {
			return false;
		}
		if ((szNum[0][i] == szNum[1][i]) || (szNum[1][i] == szNum[2][i]) ||
			(szNum[2][i] == szNum[3][i])) {
			return false;
		}
	}
	return true;
}

bool IsWin() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (szNum[i][j] == 2048) {
				return true;
			}
		}
	}
	return false;
}

void Merge(int sz[]) {
	for (int i = 0; i < 3; i++) {
		if (sz[i] == 0) {
			return;
		}
		if (sz[i] == sz[i+1]) {
			sz[i] += sz[i+1];
			for (int j = i + 1; j < 3; j++) {
				sz[j] = sz[j+1];
			}
			sz[3] = 0;
		}
	}
}

int main() {
	NewNum();
	NewNum();
	PrintNum();

	char c = 'z';

	while (true) {
		while (c != 'w' && c != 'a' && c != 's' && c != 'd' && c != 'q') {
			cout << "Please input(w4up, a4left, s4down, d4right, q4quit):" << endl;
			cin >> c;
		}
		if (c == 'q') {
			cout << "Have fun, bye..." << endl;
			return 0;
		}
		if (IsLose()) {
			cout << "A-O, U lose..." << endl;
			return 0;
		}
		
		switch (c) {
			case 'w':
				for (int col = 0; col < 4; col++) {
					int sz[4] = {0, 0, 0, 0};
					int nIndex = 0;

					for (int row = 0; row < 4; row++) {
						if (szNum[row][col] != 0) {
							sz[nIndex++] = szNum[row][col];
						}
					}
					Merge(sz);
					for (int row = 0; row < 4; row++) {
						szNum[row][col] = sz[row];
					}
				}
				break;
			case 'a':
				for (int row = 0; row < 4; row++) {
					int sz[4] = {0, 0, 0, 0};
					int nIndex = 0;

					for (int col = 0; col < 4; col++) {
						if (szNum[row][col] != 0) {
							sz[nIndex++] = szNum[row][col];
						}
					}
					Merge(sz);
					for (int col = 0; col < 4; col++) {
						szNum[row][col] = sz[col];
					}
				}
				break;
			case 's':
				for (int col = 0; col < 4; col++) {
					int sz[4] = {0, 0, 0, 0};
					int nIndex = 0;

					for (int row = 3; row >= 0; row--) {
						if (szNum[row][col] != 0) {
							sz[nIndex++] = szNum[row][col];
						}
					}
					Merge(sz);
					for (int row = 3; row >= 0; row--) {
						szNum[row][col] = sz[3-row];
					}
				}
				break;
			case 'd':
				for (int row = 0; row < 4; row++) {
					int sz[4] = {0, 0, 0, 0};
					int nIndex = 0;     

					for (int col = 3; col >= 0; col--) {
						if (szNum[row][col] != 0) {
							sz[nIndex++] = szNum[row][col];
						}
					}
					Merge(sz);
					for (int col = 3; col >= 0; col--) {
						szNum[row][col] = sz[3-col];
					}
				}
				break;
			default:
				break;
		}
		if (!IsAll()) {
			NewNum();
		}
		PrintNum();
		if (IsWin()) {
			cout << "Congratulations, U win..." << endl;
			return 0;
		}
		c = 'z';
	}
}
