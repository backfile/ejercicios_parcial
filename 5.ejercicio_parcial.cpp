#include <iostream>
//	Una entidad bancaria desea procesar los movimientos de la cuenta corriente de un día de su cartera de clientes. 
//	Por cada cliente se tiene: Nro de cuenta, apellido y nombres, saldo y el máximo importe con el que puede operar en descubierto*. 
//	Escriba un programa C++ que incialmente haga la carga de los datos de los N clientes del banco. a) Luego, el programa debe permitir 
//	la carga de los movimientos del día. Los datos son: nro de cuenta, tipo de movimiento, importe. Los tipos de 
//	movimiento pueden ser 1-depósitos, 2-transferencias recibidas o 3-transferencias hechas. La carga de movimientos 
//	termina con nro de cuenta 0. b) Codifique una función que retorne la lista de movimientos de un cliente, y otra 
//	función que use esa sublista para actualizar el saldo de ese cliente. c)
//	Utilizando las funciones de (b) actualice los saldos de todos los clientes 
//	e informe por pantalla cuáles clientes terminan con un saldo negativo que supere su mayor importe permitido para descubierto.
//	Nota: ""Descubierto" es
//	cuando queda un saldo negativo. Ej: Si en la cuenta del banco se dispone de $10.000 y se 
//	efectúan pagos por $15.000; el banco lo admite y la cuenta tiene $5000 de descubierto. 
//		Muchos bancos tienen acuerdos con clientes para operar en descubierto.

#include <vector>
using namespace std;

struct movimientos{
	int nro_cuenta_mov;
	string movimiento;
	int importe;
};

struct cliente{
	int nro_cuenta;
	string apellido;
	string nombre;
	int saldo;
	int lim_descubierto;
	vector<movimientos>v;
};

vector<movimientos> lista_movimientos(int nro, vector<cliente>v){
	vector<movimientos>vacio;
	for(size_t i=0;i<v.size();i++) { 
		if(v[i].nro_cuenta == nro){
			return v[i].v;
		}
	}
	return vacio; // en caso de no encontrar nada
}
	
void actualizar_saldo(int nro, vector<cliente>&v){
	vector<movimientos>f = lista_movimientos(nro, v);
	for(size_t i=0;i<v.size();i++) { 
		if(v[i].nro_cuenta == nro){
			for(size_t j=0;j<f.size();j++) { 
				 v[i].saldo -= f[j].importe;
				}
		}
	}
}
	
int main() {
	int N;
	cliente p;
	vector<cliente>f;
	cout << "Ingrese la cantidad de clientes: " << endl;
	cin >> N;
	for(size_t i=0;i<N;i++) { 
		cout<< "nro cuenta: "<<endl;
		cin>>p.nro_cuenta;
		cout<< "apellido: "<<endl;
		cin>>p.apellido;
		cout<< "nombre: "<<endl;
		cin>>p.nombre;
		cout<<"saldo: "<<endl;
		cin>>p.saldo;
		cout<<"limite descubierto: "<<endl;
		cin>>p.lim_descubierto;
		f.push_back(p);
	}
	
	int nrocuenta;
	int importe;
	movimientos mov;
	string tipo_movimiento;
	cout << "Bienvenido mira tetas a la carga de datos!!"<<endl;
	cout << "Ingrese el numero de cuenta: ";
	cin>>nrocuenta;
	while(nrocuenta != 0){
		for(size_t i=0;i<f.size();i++) { 
			if(f[i].nro_cuenta == nrocuenta){
				cout << "Ingrese el tipo de movimiento: "<<endl;
				cin >> tipo_movimiento;
				cout << "Ingrese el importe: "<<endl;
				cin>> importe;
				mov.nro_cuenta_mov = nrocuenta;
				mov.movimiento = tipo_movimiento;
				mov.importe = importe;
				f[i].v.push_back(mov);
			}
		}
		cout << "Ingrese el numero de cuenta: ";
		cin>>nrocuenta;
	}
	
	// Actualizar todos los saldos
	
	for(size_t i=0;i<f.size();i++) { 
		actualizar_saldo(f[i].nro_cuenta, f);
	}
	
	// Mostrar los descubiertos superados
	
	for(size_t i=0;i<f.size();i++) { 
		if(f[i].saldo < -(f[i].lim_descubierto)){
			cout<< f[i].saldo<<endl;
			cout<<f[i].nombre<<" "<<f[i].apellido<<" superó el limite de descubierto"<<endl;
		}
	}
	
	return 0;
}

