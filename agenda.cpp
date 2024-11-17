#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;
struct contacto {
	string nombre;
	string telefono;
};
bool compara(const contacto& a, const contacto& b) {
	return a.nombre < b.nombre;
}
int main() {
	const int limite = 5;
	contacto lista[limite];
	int cuenta = 0;
	int opcion;
	while (true) {
		cout << "AGENDA DE CONTACTOS\n";
		cout << "1. Agregar Contacto\n";
		cout << "2. Ver Contactos\n";
		cout << "3. Eliminar Contactos\n";
		cout << "0. Salir\n";
		cout << "Opci�n: ";
		cin >> opcion;
		if (opcion == 0) {

			cout << "�Adi�s!\n";
			break;
		}
		switch (opcion) {
		case 1:
			if (cuenta < limite) {
				contacto nuevo;
				cout << "\nNombre: ";
				cin >> nuevo.nombre;
				for (char ch : nuevo.nombre) {
					while (!isalpha(ch)) {
						cout << "El nombre solo puede contener letras: ";
						cin >> nuevo.nombre;
						ch = nuevo.nombre[0];
					}
				}
				cout << "N�mero: ";
				cin >> nuevo.telefono;
				while (nuevo.telefono.length() != 10) {
					cout << "El n�mero debe tener 10 d�gitos: ";
					cin >> nuevo.telefono;
				}
				for (char ch : nuevo.telefono) {
					while (!isdigit(ch)) {
						cout << "El n�mero solo puede contener d�gitos: ";
						cin >> nuevo.telefono;

						if (nuevo.telefono.length() == 10) {
							break;
						}
					}
				}
				lista[cuenta] = nuevo;
				cuenta++;
				cout << "\n�Contacto agregado!\n" << "\n";
			}
			else {
				cout << "\nLa lista de contactos est� llena.\n" << "\n";
			}
			break;
		case 2:
			if (cuenta == 0) {
				cout << "\nNo hay contactos para mostrar.\n" << "\n";
			}
			else {
				sort(lista, lista + cuenta, compara);
				cout << "\nLista de Contactos:\n";
				for (int i = 0; i < cuenta; i++) {
					cout << i + 1 << ". " << lista[i].nombre << " -" << lista[i].telefono << "\n" << "\n";
				}
			}
			break;
		case 3:

			if (cuenta == 0) {
				cout << "\nNo hay contactos para eliminar.\n" << "\n";
			}
			else {
				sort(lista, lista + cuenta, compara);
				cout << "\nLista de Contactos:\n";
				for (int i = 0; i < cuenta; i++) {
					cout << i + 1 << ". " << lista[i].nombre << " -" << lista[i].telefono << "\n" << "\n";
				}
				int borrar;
				while (true) {
					cout << "\nIngrese el n�mero del contacto a eliminar: ";
					cin >> borrar;
					if (borrar >= 1 or borrar <= cuenta) {
						break;
					}
					else {
						cout << "\nN�mero inv�lido. Por favor, ingrese un n�mero v�lido.\n";
					}
				}
				for (int i = borrar - 1; i < cuenta - 1; i++) {
					lista[i] = lista[i + 1];
				}
				cuenta--;
				cout << "\n�Contacto eliminado!\n" << "\n";
			}

			break;
		default:
			cout << "\nOpci�n inv�lida, por favor intente nuevamente.\n" << "\n";
		}
	}
	return 0;
}