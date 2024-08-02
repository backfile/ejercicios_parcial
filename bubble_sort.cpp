#include <iostream>
#include <vector>
using namespace std;

struct ficha{
	int DNI;
	float altura;
	
};

void ordenar(vector<ficha>&v){
	ficha siguiente;
	ficha actual;
	for(int i = 0;i < v.size()-1;i++){
		for(int j = 0;j<v.size()-1-i;j++){
			actual = v[j];
			siguiente = v[j+1];
			if ((actual.DNI < siguiente.DNI) && (actual.altura == siguiente.altura)){
				v[j] = siguiente;
				v[j+1] = actual;
			}
		}
	}
}



int main() {
	vector<ficha>f(8);
	for(size_t i=0;i<f.size();i++) { 
		cin>>f[i].altura;
		cin>>f[i].DNI;
		
	}
	ordenar(f);
	for(size_t i=0;i<f.size();i++) { 
		cout<<f[i].altura<<", "<<f[i].DNI<<endl;
	}
	return 0;
}

