#include <iostream>
#include <matrix>
using namespace std;


void agregar(matrix<int>&f, int fil, int col, int valor){
	f[fil][col]=valor;
}

matrix<int> ordenar(matrix<int>M){
	matrix<int>f(M.size(0), M.size(1), 0);
	
	int cont_filas = 0;
	int cont_col = 0;
		
	for(size_t i=0;i<M.size(0);i++) { 
		for(size_t j=0;j<M.size(1);j++) { 
			if(M[i][j] % 2 == 0){
				if(cont_col == M.size(1)-1){
					agregar(f, cont_filas, cont_col, M[i][j]);
					cont_col = 0;
					cont_filas ++;
				}else{
					agregar(f, cont_filas, cont_col, M[i][j]);
					cont_col++;
				}
			}
		}
	}
	
	
	for(size_t i=0;i<M.size(0);i++) { 
		for(size_t j=0;j<M.size(1);j++) { 
			if(M[i][j] % 2 != 0){
				if(cont_col == M.size(1)-1){
					agregar(f, cont_filas, cont_col, M[i][j]);
					cont_col = 0;
					cont_filas ++;
				}else{
					agregar(f, cont_filas, cont_col, M[i][j]);
					cont_col++;
				}
			}
		}
	}
	
	return f;
}

int main() {
	matrix<int>p(3, 3);
	for(size_t i=0;i<p.size(0);i++) { 
		for(size_t j=0;j<p.size(1);j++) { 
			cin >> p[i][j];
		}
	}
	
	matrix<int>k = ordenar(p);
	
	for(size_t i=0;i<k.size(0);i++) { 
		for(size_t j=0;j<k.size(1);j++) { 
			cout << k[i][j]<< "  ";
		}
		cout << endl;
	}
	
	return 0;
}

