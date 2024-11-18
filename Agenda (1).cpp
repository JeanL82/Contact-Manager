#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>


using namespace std;



struct Contacto {   //Jean Luis Padilla Rivera   
	string nombre;
	string telefono;
};
int main() {
	const int limite = 5;
	Contacto lista[limite];
	int cuenta = 0;
	int opcion;//jean L Padilla Rivera
	while (true) {
		cout << "AGENDA DE CONTACTOS\n";
		cout << "1. Agregar Contacto\n";
		cout << "2. Ver Contactos\n";
		cout << "3. Eliminar Contactos\n";
		cout << "0. Salir\n";
		cout << "Opción: ";
		cin >> opcion;
		cin.ignore();
		if (opcion == 0) {
			cout << "¡Adiós!\n";
			break;
		}


		switch (opcion) {//Jean Luis Padilla Rivera
		case 1:
			if (cuenta < limite) {
				cout << "\nNombre: ";
				getline(cin, lista[cuenta].nombre);
				cout << "Número: ";
				getline(cin, lista[cuenta].telefono);
				cuenta++;
				cout << "¡Contacto agregado!\n\n";

			}
			else {
				cout << "\nLa lista de contactos está llena.\n\n";
			}
			break;//jean L Padilla Rivera
		case 2://Kristian A. Rivera Rios
			if (cuenta == 0) {
				cout << "\nNo hay contactos para mostrar.\n\n";
			}
			else {
				// Ordenar los contactos alfabéticamente por nombre /Kristian A. Rivera Rios
				sort(lista, lista + cuenta, [](const Contacto a, const Contacto b) {    //[jvilella] ([2020]) [C++ Ordenación con sort.] Recuperado desde: [https://aprende.olimpiada-informatica.org/cpp-sort.]
					return a.nombre < b.nombre;


					});
				cout << "\nLista de Contactos:\n";
				// Utiliza iomanip (setw) para estructurar el nombre y telefono /Kristian A. Rivera Rios
				cout << left << setw(20) << "Nombre" << "Teléfono" << endl;
				for (int i = 0; i < cuenta; i++) {
					cout << left << setw(20) << lista[i].nombre << lista[i].telefono << "\n";
				}
				cout << "\n";
			}
			break;
		case 3: // Dariel E Vilches, Y00658644
			if (cuenta == 0) {
				cout << "\nNo hay contactos para eliminar.\n\n";
			}
			else {
				cout << "\nLista de Contactos:\n";
				for (int i = 0; i < cuenta; i++) { // loop para mostrar lista en orden de entrada.
					cout << i + 1 << ". " << lista[i].nombre << " -" << lista[i].telefono << "\n";
				}
				int borrar;
				cout << "\nIngrese el número del contacto a eliminar: ";
				cin >> borrar;
				if (borrar >= 1 or borrar <= cuenta) { //Verifica que sea un numero valido.
					for (int i = borrar - 1; i < cuenta - 1; i++) {// ajusta la lista
						lista[i] = lista[i + 1];
					}
					cuenta--;// ajusta el conteo de la cantidad de contactos
					cout << "\n¡Contacto eliminado!\n\n";
				}
				else {
					cout << "\nNúmero inválido.\n\n";
				}
			}
			break;
		default:
			cout << "\nOpción inválida.\n\n";
		}
	}
	return 0;
}
