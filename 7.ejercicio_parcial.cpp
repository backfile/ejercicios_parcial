#include <iostream>
#include <matrix>
using namespace std;

bool funcion(matrix<int>&M, int pos, vector<int>v){
	if(M.size(1)!=v.size() || pos<0){
		return false;
	}
	if(M.size(0)>=pos){
		M.resize(M.size(0)+1, M.size(1));
		for(size_t i=M.size(0)-1;i>pos-1;i--) { 
			for(size_t j=0;j<M.size(1);j++) { 
				M[i][j]= M[i-1][j];
			}
		}
		for(size_t j=0;j<M.size(1);j++) { 
			M[pos-1][j]=v[j];
		}
	}else{
		while(M.size(0) < pos){
			M.resize(M.size(0)+1, M.size(1));
		}
		for(size_t i=M.size(0)-1;i>pos-1;i--) { 
			for(size_t j=0;j<M.size(1);j++) { 
				M[i][j]= M[i-1][j];
			}
		}
		for(size_t j=0;j<M.size(1);j++) { 
			M[pos-1][j]=v[j];
		}
	}

	return true;
}

int main() {
	
	vector<int>v = {2, 4};
	matrix<int>M(2,2,1);
	bool rta= funcion(M, 2, v);
		
	for(size_t i=0;i<M.size(0);i++) { 
		for(size_t j=0;j<M.size(1);j++) { 
			cout<<M[i][j]<<"   ";
			
		}
		cout<<endl;
	}
	
	return 0;
}

