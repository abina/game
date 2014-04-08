#include <iostream>

using namespace std;

char gBoard[9] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};

void PrintBoard() {
	cout << endl;
   	cout << gBoard[0] << " | " << gBoard[1] << " | " << gBoard[2] << endl;
   	cout << gBoard[3] << " | " << gBoard[4] << " | " << gBoard[5] << endl;
   	cout << gBoard[6] << " | " << gBoard[7] << " | " << gBoard[8] << endl;
}

void FillBoard(int nPos, char c) {
	gBoard[nPos] = c;
}

void UnFillBoard(int nPos) {
	gBoard[nPos] = '-';
}

bool IsWin(char c) {
	if ((gBoard[0] == c && gBoard[1] == c && gBoard[2] == c) ||
		(gBoard[3] == c && gBoard[4] == c && gBoard[5] == c) ||
		(gBoard[6] == c && gBoard[7] == c && gBoard[8] == c) ||
		(gBoard[0] == c && gBoard[3] == c && gBoard[6] == c) ||
		(gBoard[1] == c && gBoard[4] == c && gBoard[7] == c) ||
		(gBoard[2] == c && gBoard[5] == c && gBoard[8] == c) ||
		(gBoard[0] == c && gBoard[4] == c && gBoard[8] == c) ||
		(gBoard[2] == c && gBoard[4] == c && gBoard[6] == c)) {
		return true;
	}
	return false;
}

bool IsLose() {
	for (int i = 0; i < 9; i++) {
		if (gBoard[i] == '-') {
			return false;
		}
	}
	return true;
}

int GetAIPos() {
	int num;
	
	for (int i = 0; i < 9; i++) {
		if (gBoard[i] == '-') {
			num = i;
			FillBoard(i, 'X');
			if (IsWin('X')) {
				UnFillBoard(i);
				return i;
			}
			FillBoard(i, 'O');
			if (IsWin('O')) {
				UnFillBoard(i);
				return i;
			}
			UnFillBoard(i);
		}
	}
	return num;
}

int main() {
	PrintBoard();
	cout << "Welcome to my tic-tac-toe" << endl;

	int nPos;
	
	while (true) {
		bool bErr = true;
		
		while (bErr) {
			cout << "please input your position(from 0-8):" << endl;
			cin >> nPos;
			if (nPos > 8 || nPos < 0 || gBoard[nPos] != '-') {
				cout << "error input..." << endl;
			}
			else {
				bErr = false;
			}
		}
		FillBoard(nPos, 'O');
		PrintBoard();

		if (IsWin('O')) {
			cout << "Congratulations, U win..." << endl;
			return 0;
		}
		if (IsLose()) {
			cout << "A-O, U lose..." << endl;
			return 0;
		}

		nPos = GetAIPos();
		FillBoard(nPos, 'X');
		PrintBoard();
		if (IsWin('X')) {
			cout << "A-O, U lose..." << endl;
			return 0;
		}
	}
	return 0;
}
