#include <iostream>
#include <stdlib.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//////////Variables Globales////////////

//Declarar variables de Comprador
string nombre_comprador, apellido_comprador, direccion_comprador, clave_comprador;
int telefono_comprador, identificacion_comprador;

//Declarar variables de producto
string nombre_producto[10], descipcion_producto[10];
double codigo_producto[10], precio_producto[10];
int indice_producto = 0;

//Declarar variables de Vendedor
bool deseaSalir;

//////////////////////////////////////



void registrarCompardor(){	
	cout <<"Nombre: ";
	cin>>nombre_comprador;
	
	cout <<"Apellido: ";
	cin>>apellido_comprador;
	
	cout <<"Direccion: ";
	cin>>direccion_comprador;
	
	cout <<"Telefono: ";
	cin>>telefono_comprador;
	
	cout <<"Numero de Idendificacion: ";
	cin>>identificacion_comprador;
	
	cout <<"clave: ";
	cin>>clave_comprador;
}

void registrarProducto(string nombre, string descripcion, int codigo, double precio){	
	nombre_producto[indice_producto] = nombre;
	descipcion_producto[indice_producto] = descripcion;
	codigo_producto[indice_producto] = codigo;
	precio_producto[indice_producto] = precio;
	indice_producto++;
}

void registrarProductos(){	
	registrarProducto("lapiz","Elemento de grafito...", 10243, 700);
	registrarProducto("Esfero","Elemento de grafito...", 14862, 1000);
	registrarProducto("Borrador","Elemento de grafito...", 76522, 200);
	registrarProducto("Tajalapiz","Elemento de grafito...", 86654, 400);
	registrarProducto("Cartuchera","Elemento de grafito...", 16644, 3400);
	registrarProducto("Cuadreno","Elemento de grafito...", 78965, 2500);
}

void imprimirRecibo(){
	system("cls"); // Borrar la pantalla
	cout << "=====================PAPELERIA SAMATO====================" << endl;
	cout << "========================Nit. 15441=======================" << endl;
	cout << "==========================7000000========================" << endl;
	cout << endl;
	cout << "                     *** Vendedor ***                    " << endl;
	cout << "Juan Ortiz" << endl;
	cout << endl;
	cout << "                     *** Cliente ***                    " << endl;
	cout << nombre_comprador << " "<<  apellido_comprador << endl;
	cout << "C.C " <<  identificacion_comprador << endl;
	cout << telefono_comprador << "-"<<  direccion_comprador << endl;
}

int main(int argc, char** argv) {
	/*Inicializar productos*/
	registrarProductos();
	while(deseaSalir == false){
		//system("cls"); // Borrar la pantalla
		cout << "========================================================" << endl;
		cout << "====================PAPELERIA SAMATO====================" << endl;
		cout << "========================================================" << endl;
		cout << "" << endl;
		cout << "===== Bienvenido, Ingrese los datos del comparador =====" << endl;
		registrarCompardor();
		imprimirRecibo();
		system("pause");
	}
	return 0;
}
