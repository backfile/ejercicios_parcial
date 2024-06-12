#include <iostream>
#include <vector>
using namespace std;

struct perro{
	string nombre, raza;
	int edad;
	float peso;
};


vector<perro> buscar_perro_x_raza(vector<perro>v, string razaa){
	vector<perro>nuevo;
	for(int i=0;i<v.size();i++) { 
		if(v[i].raza == razaa){
			nuevo.push_back(v[i]);
		}
	}
	return nuevo;
}

vector<perro> buscar_perro_x_peso(vector<perro>v, int peso_min, int peso_max){
	vector<perro>nuevo;
	for(int i=0;i<v.size();i++) { 
		if(v[i].peso > peso_min && v[i].peso < peso_max){
			nuevo.push_back(v[i]);
		}
	}
	return nuevo;
}
	

int main(int argc, char *argv[]) {
	int N;
	string raza;
	int peso_min, peso_max;
	vector<perro>v;
	cout << "Cuantos perros quiere ingresar?: "<<endl;
	cin >>N;
	for(int i=0;i<N;i++) { 
		perro nuevo_perro;
		cout << "Ingrese el nombre del nuevo perro: "<<endl;
		cin >> nuevo_perro.nombre;
		cout << "Ingrese la raza del nuevo perro: "<<endl;
		cin >> nuevo_perro.raza;
		cout << "Ingrese la edad del nuevo perro: "<<endl;
		cin >> nuevo_perro.edad;
		cout << "Ingrese el peso del nuevo perro: "<<endl;
		cin >> nuevo_perro.peso;
		
		v.push_back(nuevo_perro);
	}
	cout << "Ingrese la raza que quiere filtrar: ";
		cin >> raza;
	
	cout << "Ingrese el peso minimo que quiere filtrar: ";
		cin >> peso_min;
	
	cout << "Ingrese el peso maximo que quiere filtrar: ";
		cin >> peso_max;
	
	vector<perro> raza_resultado = buscar_perro_x_raza(v, raza);
	vector<perro> resultado_final = buscar_perro_x_peso(raza_resultado, peso_min, peso_max);
	
	for(int i=0;i<resultado_final.size();i++) { 
		cout << "Nombre: " << resultado_final[i].nombre << "   Edad: " << resultado_final[i].edad << "     Peso: " << resultado_final[i].peso << endl;
	}
	
	
	return 0;
}

