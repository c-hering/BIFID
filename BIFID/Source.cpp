#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string input;
int ln;
int counter = 0;
int trans_coords[128];
char square[5][5] = {
	{ 'a','b','c','d','e' },	
	{ 'f','g','h','i','k' },
	{ 'l','m','n','o','p' },
	{ 'q','r','s','t','u' },
	{ 'v','w','x','y','z' }
};

void combine(int coords[64]);
void decrypt();

void decrypt() {
	int coords[128];
	int new_coords[64][2];
	int c1 = 0;
	int c2 = ln;
	int c = 0;
	for (int i = 0; i < ln; i++) {
		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 5; x++) {
				if (input[i] == square[y][x]) {
					coords[c] = y;
					coords[c + 1] = x;
				}
			}
		}
		c += 2;
	}
	cout << endl;
	for (int o = 0; o < ln; o++) {
		new_coords[o][0] = coords[c1];
		new_coords[o][1] = coords[c2];
		c1++;
		c2++;
	}
	cout << "Decrypted: ";
	for (int u = 0; u < ln; u++) {
		cout << square[new_coords[u][0]][new_coords[u][1]];
	}
	cout << endl;
}

void combine(int coords[64]) {
	for (int x = 0; x < ln; x++) {
		trans_coords[counter] = coords[x];
		counter++;
	}
}

int main() {
	char choice;
	int c1;
	int c2;
	int y_coords[64];
	int x_coords[64];
	int new_x;
	int new_y;
	int new_coords[64][2];
	char output[64];

	while (true) {
		counter = 0;
		fill(begin(y_coords), end(y_coords), 0);
		fill(begin(x_coords), end(x_coords), 0);
		c1 = 0;
		c2 = 1;
		cout << "please input a phrase that is from 0 - 64 chars long: ";
		getline(cin, input);
		transform(input.begin(), input.end(), input.begin(), ::tolower);
		ln = input.length();
			for (int i = 0; i < ln; i++) {
				for (int y = 0; y < 5; y++) {
					for (int x = 0; x < 5; x++) {
						if (input[i] == 'j') {
							input[i] == 'i';
						}
						if (input[i] == square[y][x]) {
							y_coords[i] = y;
							x_coords[i] = x;
						}
					}
				}
			}
			combine(y_coords);
			combine(x_coords);
			for (int o = 0; o < ln; o++) {
				new_coords[o][0] = trans_coords[c1];
				new_coords[o][1] = trans_coords[c2];
				c1 += 2;
				c2 += 2;
			}
			cout << "Encrypted: ";
			for (int u = 0; u < ln; u++) {
				cout << square[new_coords[u][0]][new_coords[u][1]];
			}
			cout << endl;
			decrypt();
	}
}