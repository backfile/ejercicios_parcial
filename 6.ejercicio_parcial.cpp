#include <iostream>
#include <matrix>
using namespace std;
//	Libres ((20 pts) Escriba una función C++ que reciba una matriz M de strings, y dos variables s1 y s2 de tipo string
//	Si en una fila de M se encuentra el string s1 pero no se encuentra s2, reemplazar s1 con s2. Si en una fila se 
//	encuentra el string s2 no se debe hacer modificaciones. La función debe retornar la matriz y el número de reemplazos de s1

bool busqueda(matrix<string>M, int i, string s2){
	for(size_t j=0;j<M.size(1);j++) { 
		if(M[i][j] == s2){
			return true;
		}
	}
	return false;
}

int funcion(matrix<string>&M, string s1, string s2){
	int contador = 0;
	for(size_t i=0;i<M.size(0);i++) { //Filas
		bool rta = busqueda(M, i, s2);
		if(rta == false){
			for(size_t j=0;j<M.size(1);j++) { 
				if(M[i][j] == s1){
					M[i][j] = s2;
					contador ++;
				}
			}	
		}
		
	}
	
	return contador;
}
int main() {
	matrix<string>M(2,2);
	for(size_t i=0;i<M.size(0);i++) {
		for(size_t j=0;j<M.size(1);j++) { 
			cin >> M[i][j];
		}
	}
	string s1 = "ff";
	string s2 = "ee";
	
	int p = funcion(M,s1,s2);
	for(size_t i=0;i<M.size(0);i++) { 
		for(size_t j=0;j<M.size(1);j++) { 
			cout << M[i][j]<<"  ";
		}
		cout << endl;
	}
	cout << p;
	return 0;
}

