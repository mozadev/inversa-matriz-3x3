#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int nfil = 3, ncol = 3;
	float determinante = 0;
	
	float matriz[nfil][ncol];
	float adjunta[nfil][ncol];
	float inversa[nfil][ncol];
	
	for (int i = 0; i < nfil; ++i) {
		
		for (int j = 0; j < ncol; ++j) {
			cout << "ingresa valor [" << i << "][" << j << "]: " ;
			cin >> matriz[i][j];
			
		}
		
	}
	
	determinante = matriz[0][0] * (matriz[1][1] * matriz[2][2] - matriz[2][1] * matriz[1][2]) +
		matriz[1][0] * (matriz[2][1] * matriz[0][2] - matriz[0][1] * matriz[2][2]) +
			matriz[2][0] * (matriz[0][1] * matriz[1][2] - matriz[1][1] * matriz[0][2]);
			
			if (determinante != 0) {
				for (int fil = 0; fil < nfil; ++fil) {
					for (int col = 0; col < ncol; ++col) {
						adjunta[fil][col]=matriz[(fil+1)%nfil][(col+1)%ncol]*matriz[(fil+2)%nfil][(col+2)%ncol]-
							matriz[(fil+1)%nfil][(col+2)%ncol]*matriz[(fil+2)%nfil][(col+1)%ncol];
						
						inversa[col][fil]=adjunta[fil][col]/determinante;
					}
				}
				
				for (int i = 0; i < nfil; ++i) {
					for (int j = 0; j < ncol; ++j) {
						cout<<inversa[i][j]<<"\t";
					}
					cout   <<endl;
				}
				
				
			} else {
				cout << "la matriz no tiene inversa, determinante=0";
			}
			
			return 0;
}