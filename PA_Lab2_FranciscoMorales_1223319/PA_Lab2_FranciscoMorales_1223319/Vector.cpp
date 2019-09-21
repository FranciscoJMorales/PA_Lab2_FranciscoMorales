#include "Vector.h"

int v[71];
int *liebre;
int *tortuga;
int *inicio;
int *fin;
bool finalCarrera;

Vector::Vector()
{
	v[0] = 3;
	v[70] = -1;
	for (int *i = &v[1]; *i != -1; i++) {
		(*i) = 0;
	}
	liebre = &v[0];
	tortuga = &v[0];
	inicio = &v[0];
	fin = &v[69];
	finalCarrera = false;
}


Vector::~Vector()
{
}

System::String^Vector::Recorrido() {
	System::String^ mapa = "";
	for (int *i = &v[0]; *i != -1; i++) {
		int posicion = *i;
		if (posicion == 0) {
			mapa += "- ";
		}
		else if (posicion == 1) {
			mapa += "H ";
		}
		else if (posicion == 2) {
			mapa += "T ";
		}
		else {
			mapa += "¡OUCH! ";
		}
	}
	return mapa;
}

void Vector::MoverLiebre() {
	System::Random^ rng = gcnew System::Random();
	int mov = rng->Next(0, 10);
	if (*liebre == 1) {
		*liebre = 0;
	}
	else {
		*liebre = 2;
	}
	if (mov < 2) {
		liebre += 9;
	}
	else if (mov < 3) {
		liebre -= 12;
	}
	else if (mov < 6) {
		liebre += 1;
	}
	else if (mov < 8) {
		liebre -= 2;
	}
	if (liebre < inicio) {
		liebre = inicio;
		if (*liebre == 0) {
			*liebre = 1;
		}
		else {
			*liebre = 3;
		}
	}
	else if (liebre >= fin) {
		liebre = fin;
		if (*liebre == 0) {
			*liebre = 1;
		}
		else {
			*liebre = 3;
		}
		Final();
	}
	else {
		switch (*liebre) {
		case 0:
			*liebre = 1;
			break;
		case 2:
			*liebre = 3;
			break;
		}
	}
}

void Vector::MoverTortuga() {
	System::Random^ rng = gcnew System::Random();
	int mov = rng->Next(0, 10);
	if (*tortuga == 2) {
		*tortuga = 0;
	}
	else {
		*tortuga = 1;
	}
	if (mov < 5) {
		tortuga += 3;
	}
	else if (mov < 7) {
		tortuga -= 6;
	}
	else {
		tortuga += 1;
	}
	if (tortuga < inicio) {
		tortuga = inicio;
		if (*tortuga == 0) {
			*tortuga = 2;
		}
		else {
			*tortuga = 3;
		}
	}
	else if (tortuga >= fin) {
		tortuga = fin;
		if (*tortuga == 0) {
			*tortuga = 2;
		}
		else {
			*tortuga = 3;
		}
		Final();
	}
	else {
		switch (*tortuga) {
		case 0:
			*tortuga = 2;
			break;
		case 1:
			*tortuga = 3;
			break;
		}
	}
}

void Vector::Final() {
	switch (*fin) {
	case 1:
		finalCarrera = true;
		System::Windows::Forms::MessageBox::Show("La liebre gana. Ni hablar", "Fin de la carrera");
		break;
	case 2:
		finalCarrera = true;
		System::Windows::Forms::MessageBox::Show("¡LA TORTUGA GANA! ¡BRAVO!", "Fin de la carrera");
		break;
	case 3:
		System::Windows::Forms::MessageBox::Show("Es un empate. La carrera se repetirá", "Fin de la carrera");
		tortuga = &v[0];
		liebre = &v[0];
		v[0] = 3;
		v[70] = 0;
		break;
	}
}
