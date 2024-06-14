#include <iostream>
#include <vector>
using namespace std;
//Un struct definido como struct Evento { string tipo; int jugador; }; representa un evento
//ocurrido en un partido de tenis. tipo puede ser “ace”, “error no forzado”, “tiro ganador”, “doble falta”, y
//”quiebre”. jugador puede ser 1 o 2. a) Escriba una función llamada resumen_partido que reciba un
//arreglo/vector de structs de tipo Evento y un número de jugador, y retorne la cantidad de eventos de cada tipo
//para ese jugador. b) Escriba un programa cliente que permita ingresar todos los eventos de un partido durante el
//mismo (sin conocer previamente la cantidad de eventos), y luego muestre en pantalla el resumen de cada
//jugador

struct Evento{
	string tipo;
	int jugador;
};

struct Evento_Repeticiones{
	string tipo;
	int repeticiones;
};

int busqueda(vector<Evento_Repeticiones>v, string tipoo){
	for(int i=0;i<v.size();i++) { 
		if(v[i].tipo == tipoo){
			return i;
		}
	}
	return -1;
}

vector<Evento_Repeticiones>resumen_partido(vector<Evento>v, int nro_jugador){
	vector<Evento_Repeticiones>n;
	for(int i=0;i<v.size();i++) { 
			int resultado = busqueda(n, v[i].tipo);
			if (resultado == -1){
				Evento_Repeticiones a;
				a.tipo = v[i].tipo;
				a.repeticiones = 1;
				n.push_back(a);
			}else{
				n[resultado].repeticiones += 1;
			}
		}
	return n;
	}
	

int main() {
	Evento jugador;
	vector<Evento>n1;
	vector<Evento>n2;
	
	cout << "Ingrese el nro de jugador (-1 para finalizar la carga de datos)" << endl;
	cin >> jugador.jugador;
	while(jugador.jugador != -1){
		cout << "Ingrese el tipo: " << endl;
		cin >> jugador.tipo;
		
		if(jugador.jugador == 1){
			n1.push_back(jugador);
		}else{
			n2.push_back(jugador);
		}
		
		cout << "Ingrese el nro de jugador (-1 para finalizar la carga de datos)" << endl;
		cin >> jugador.jugador;
	}
	
	vector<Evento_Repeticiones> rta_jugador1 = resumen_partido(n1, 1);
	vector<Evento_Repeticiones> rta_jugador2 = resumen_partido(n2, 2);
	
	cout<<"Resumen del jugador 1: "<<endl;
	for(int i=0;i<rta_jugador1.size();i++) { 
		cout << "Tipo:  "<< rta_jugador1[i].tipo << "  Repeticiones:  " << rta_jugador1[i].repeticiones << endl;
	}
	
	cout<<"Resumen del jugador 2: "<<endl;
	for(int i=0;i<rta_jugador2.size();i++) { 
		cout << "Tipo:  "<< rta_jugador2[i].tipo << "  Repeticiones:  " << rta_jugador2[i].repeticiones << endl;
	}
	
	return 0;
}

