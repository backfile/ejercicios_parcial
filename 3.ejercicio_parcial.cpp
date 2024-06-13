#include <iostream>
#include <matrix>
using namespace std;
	// Una materia tiene 4 evaluaciones codificadas: 1 (parcial 1),2 (recup. parcial 1),3 (parcial 2),4 (recup.parcial 2). 
	// El Profesor responsable de la materia -en la que hay muchos docentes- quiere saber quién corrigió cada
	// parcial o recuperatorio de su materia. a) Escriba un programa que permita ingresar la cantidad de alumnos de la
	// materia (N), y luego ternas de datos: nro de alumno (1 a N), nro de evaluación (1 a 4), y nombre del docente que lo
	// corrigió. Los datos finalizan con el nro de alumno -1 (porque no todos los alumnos rindieron las 4 instancias).
	// Organice estos datos en una matriz de N filas x 4 columnas, donde cada casillero contenga el nombre del docente
	// que corrigió un parcial/recuperatorio, o la cadena "No rindió" si el alumno no se presentó a esa evaluación. b) El
	// programa debe luego informar cuántos alumnos rindieron cada evaluación; c) mostrar la lista de alumnos que no
	// rindieron ninguna de las (4) instancias; y d) permitir al usuario ingresar el nombre de un docente y mostrar cuántos
	// parciales/recuperatorios corrigió ese docente


int main(int argc, char *argv[]) {
	int alumnos;
	int nro_alumno, nro_evaluacion;
	string nombre_docente;
	cout << "Ingrese la cantidad de alumnos: " << endl;
	cin >> alumnos;
	matrix<string>grilla(alumnos, 4, "No rindió");
	
	cout << "Ingrese el numero del alumno: " << endl;
	cin >> nro_alumno;
	while(nro_alumno!= -1){
		cout << "Ingrese el numero de la evalucacion: " << endl;
		cin >> nro_evaluacion;
		cout << "Ingrese el nombre del profesor: " << endl;
		cin >> nombre_docente;
		grilla[nro_alumno-1][nro_evaluacion-1] = nombre_docente;
		
		cout << "Ingrese el numero del alumno: " << endl;
		cin >> nro_alumno;
	}
	
	for(int i=0;i<4;i++) {
		for(int j=0;j<grilla.size(0);j++) { 
			cout << grilla[j][i] << endl;
		}
		
	}
	
	int contador = 0;
	for(int i=0;i<4;i++) {
		contador = 0;
		for(int j=0;j<grilla.size(0);j++) { 
			if(grilla[j][i] != "No rindió"){
				contador++;
			}
		}
		cout << "El parcial " << i+1 << " lo rindieron: "<<contador << " alumnos"<<endl;
		
	}
	
	for(int j=0;j<grilla.size(0);j++){
		contador = 0;
		for(int i=0;i<4;i++){ 
			if(grilla[j][i] == "No rindió"){
				contador++;
			}
		}
		if(contador == 4){
			cout << "El alumno "<<j+1<< " no rindió ninguna evaluacion!"<<endl;
		}
	}
	
	
	cout << "Ingrese el nombre de un docente para ver cuantos examenes corrigió: "<<endl;
	cin>> nombre_docente;
	
	int nuevo_contador = 0;
	
	for(int i=0;i<4;i++) {
		for(int j=0;j<grilla.size(0);j++) { 
			if(grilla[j][i] == nombre_docente){
				nuevo_contador++;
			}
		}
	}
	
	cout << "El profesor " << nombre_docente << " corrigió: "<<nuevo_contador<< " evaluaciones";
	
	return 0;
}

