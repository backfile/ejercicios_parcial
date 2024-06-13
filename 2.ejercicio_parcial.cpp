#include <iostream>
#include <vector>
using namespace std;
//En una carrera de ciclismo por etapas, el ganador es el competidor que acumula menor
//cantidad de tiempo sumando sus tiempos de todas las etapas. Escriba un programa que permita ingresar la
//cantidad de competidores de una carrera de tres etapas y a continuación, por cada competidor, ingresar primero
//nombre y apellido, y luego los tres tiempos (uno por cada etapa). Cada tiempo se ingresa mediante dos enteros,
//que corresponden a minutos y segundos. El programa debe mostrar el nombre del ganador y su tiempo total en
//minutos y segundos. Advertencia: 40m 40s + 50m 50s no es 90m 90s, sino 91m 30s.

struct tiempo{
	int minutos, segundos;
};

struct participantes{
	string nombre, apellido;
	tiempo etapa1;
	tiempo etapa2;
	tiempo etapa3;
};

struct ganador{
	string nombre;
	int segundos;
};

ganador encontrar_ganador(vector<participantes>v){
	int mayor = 0;
	int indice = -1;
	int tiempo_participante;
	ganador participante_ganador;
	for(int i=0;i<v.size();i++) { 
		tiempo_participante = 0;
		tiempo_participante = v[i].etapa1.minutos*60 + v[i].etapa1.segundos + v[i].etapa2.minutos*60 + v[i].etapa2.segundos + v[i].etapa3.minutos*60 + v[i].etapa3.segundos;
		if(tiempo_participante > mayor){
			mayor = tiempo_participante;
			participante_ganador.nombre = v[i].nombre;
			participante_ganador.segundos = tiempo_participante;
		}
	}
	return participante_ganador;
}

int main(int argc, char *argv[]) {
	int N;
	cout << "Ingrese la cantidad de participantes: " << endl;
	cin >> N;
	vector<participantes>vparticipantes;
	for(int i=0;i<N;i++) { 
		participantes participante;
		cout << "Ingrese el nombre del participante: " << endl;
		cin >> participante.nombre;
		
		cout << "Ingrese el apellido del participante: " << endl;
		cin >> participante.apellido;
		
		cout << "Ingrese el tiempo (en el primer input minutos, en el segundo segundos) de la etapa1 del particiapnte " << endl;
		cin >> participante.etapa1.minutos;
		cin >> participante.etapa1.segundos;
			
		cout << "Ingrese el tiempo (en el primer input minutos, en el segundo segundos) de la etapa2 del particiapnte " << endl;
		cin >> participante.etapa2.minutos;
		cin >> participante.etapa2.segundos;
			
		cout << "Ingrese el tiempo (en el primer input minutos, en el segundo segundos) de la etapa3 del particiapnte " << endl;
		cin >> participante.etapa3.minutos;
		cin >> participante.etapa3.segundos;
		vparticipantes.push_back(participante);
	}
	
	ganador resultado = encontrar_ganador(vparticipantes);
	int minutos = resultado.segundos / 60;
	int segundos = resultado.segundos % 60;
	cout << resultado.nombre <<" "<< minutos << "  " << segundos;
	
	return 0;
	
	
	
}

