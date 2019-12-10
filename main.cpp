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
bool deseo_salir = false;

//Declarar variables de Comparador
int carrito_lista[100];
int indice_carrito = 0;

#define GetSize(array_enteros) (sizeof(array_enteros)/sizeof(*(array_enteros)))

//////////////////////////////////////

void titulo(){
	system("cls"); // Borrar la pantalla
	cout << "========================== PAPELERIA SAMATO =========================" << endl;
	cout << "============================= Nit. 15441 ============================" << endl;
	cout << "=============================== 7000000 =============================" << endl;
	cout << endl;
}

void registrarCompardor(){
	titulo();
	
	cout << "Ingrese los datos del comprador" << endl;
	cout << endl;
		
	cout <<"Nombre: ";
	cin>>nombre_comprador;
	
	cout <<"Apellido: ";
	cin>>apellido_comprador;
	
	/*cout <<"Direccion: ";
	cin>>direccion_comprador;*/
	
	cout <<"Telefono: ";
	cin>>telefono_comprador;
	
	cout <<"Numero de Idendificacion: ";
	cin>>identificacion_comprador;
	
	cout <<"clave (numeros): ";
	cin>>clave_comprador;
	
	cout << endl;
	cout <<"Hemos registrado con exito el comprador " << endl;
	system("pause");
}

void registrarProducto(string nombre, string descripcion, int codigo, double precio){	
	nombre_producto[indice_producto] = nombre;
	descipcion_producto[indice_producto] = descripcion;
	codigo_producto[indice_producto] = codigo;
	precio_producto[indice_producto] = precio;
	indice_producto++;
}

/*No registrar mas de 10 productos*/
void registrarProductos(){	
	registrarProducto("lapiz","Elemento de grafito...", 1, 700);
	registrarProducto("Esfero","Elemento de grafito...", 2, 1000);
	registrarProducto("Borrador","Elemento de grafito...", 3, 200);
	registrarProducto("Tajalapiz","Elemento de grafito...", 4, 400);
	registrarProducto("Cartuchera","Elemento de grafito...", 5, 3400);
	registrarProducto("Cartulina","Elemento de grafito...", 6, 2500);
	registrarProducto("Micropunta","Elemento de grafito...", 7, 2000);
	registrarProducto("Plumon","Elemento de grafito...", 8, 1500);
	registrarProducto("Papel Iris","Elemento de grafito...", 9, 100);
	registrarProducto("Carton Paja","Elemento de grafito...", 10, 500);
}

void listadoProductos() {
	titulo();
	for (int i = 0; i < 10; i++){
		cout << " | Codigo: " <<  codigo_producto[i] << " | Nombre: " << nombre_producto[i] <<  " | Precio: " << precio_producto[i] << " | Descripcion: " << descipcion_producto[i] <<endl;
	}
}

/*Se calcula costo solo de 100 datos*/
int calcularCosto(){
	int costoCantidad = 0;
	for (int i = 0; i < 100; i++){
		/*Si dentro del carrito de listas existe el dato*/
		int posicion = carrito_lista[i]-1;
		if(carrito_lista[i] != 0){
			costoCantidad = costoCantidad + precio_producto[posicion];
		}
	}
	return costoCantidad;
}

/*No se pueden agregar mas de 100 productos*/
bool agregarProductoAlCarrito() {
	int cod_temp;
	titulo();
	listadoProductos();
	cout << " " << endl;
	cout << "Ingrese el codigo del producto a agregar " << endl;
	cin >> cod_temp;
	
	/*Revisar si el producto existe, de ser asi agregarlo*/
	if( cod_temp != 0 ){
		for(int i = 0; i < 100; i++) {
			if (codigo_producto[i] == cod_temp){	
					carrito_lista[indice_carrito] = cod_temp;
					indice_carrito++;
					return true;
			}
		}	
	}
	return false;
}

void eliminarDatosArreglos(){
	indice_producto = 0;
	indice_carrito = 0;
		
	for(int i = 0; i < GetSize(carrito_lista); i++){
		carrito_lista[i] = 0;
	}
	
}

/*No se pueden mostrar mas de 100 productos*/
void mostrarCarrito() {
	for (int i = 0; i < 100; i++){
		if(carrito_lista[i] != 0){
			int posicion = carrito_lista[i]-1;
			cout << " | Codigo: " <<  codigo_producto[posicion] << " | Nombre: " << nombre_producto[posicion] <<  " | Precio: " << precio_producto[posicion] << " | Descripcion: " << descipcion_producto[posicion] <<endl;
		}

	}
	cout <<  endl;
}

void imprimirRecibo(){
	/*Variables Locales*/
	int costoTemp, ivaTemp;
	
	titulo();
	cout << "                     *** Vendedor ***                    " << endl;
	cout << "Juan Ortiz" << endl;
	cout << "C.C " <<  101249195 << endl;
	cout << endl;
	cout << "                     *** Cliente ***                    " << endl;
	cout << nombre_comprador << " "<<  apellido_comprador << endl;
	cout << "C.C " <<  identificacion_comprador << endl;
	cout << telefono_comprador << "-"<<  direccion_comprador << endl;
	cout << endl;
	mostrarCarrito();
	cout << endl;

	costoTemp = calcularCosto();
	ivaTemp = costoTemp * 16 / 100;
	
	cout << "Subtotal: " << costoTemp << endl;
	cout << "IVA: " << ivaTemp << endl;	
	cout << "Total: " << ivaTemp + costoTemp << endl;
	cout << endl;
	system("pause");
}

void carrito() {
	
	bool listoCarrito = false;
	char op ;
		
	while( listoCarrito != true) {
		system("cls"); 
		titulo();
		
		cout << "> (C) Agregar porduto al carrito de compras" << endl;
		cout << "> (M) Mostar Carrito" << endl;
		cout << "> (G) Generar Recibo" << endl;
		cout << "> (N) Nuevo Comprador" << endl;
		cin >> op;
		switch(op){
			case 'C':
			case 'c':
			{
				bool fueAgregado = agregarProductoAlCarrito(); 
				if(fueAgregado == true)
					cout << "Agregado al Carrito" << endl;
				else
					cout << "No fue agregado al Carrito" << endl;
				system("pause");
				break;
			}
			case 'G':
			case 'g': 
			{
				imprimirRecibo();
				break;	
			}
			case 'M':
			case 'm': 
			{
				mostrarCarrito();
				system("pause");
				break;	
			}
			case 'N':
			case 'n': 
			{
				listoCarrito = true;
				eliminarDatosArreglos();
			}
			
		} 
	}
}



void menu(){
	/*Variable local*/
	char menu_desicion;
	
	titulo();
	cout << "===== Bienvenido, ingrese la letra que aparece en el parentesis =====" << endl;
	cout << "" << endl;
	
	cout << "> (P) Mostrar listado de productos" << endl;
	cout << "> (C) Registrar compra" << endl;
	cout << "> (S) Salir" << endl;
	cout << "" << endl;
	
	cin >> menu_desicion;
	switch(menu_desicion){
		case 'P':
		case 'p': 
			listadoProductos();
			system("pause");
			break;
		case 'C':
		case 'c': 
			registrarCompardor();
			carrito();
			break;
		case 'S':
		case 's': 
			exit(0);
			break;
		default:
			menu();			
	} 
}

int main(int argc, char** argv) {
	
	/*Inicializar productos*/
	registrarProductos();
	
	/*Loop de mensajes*/
	while(deseo_salir == false){
		system("cls"); 	
		menu();
	}
	
	return 0;
}
