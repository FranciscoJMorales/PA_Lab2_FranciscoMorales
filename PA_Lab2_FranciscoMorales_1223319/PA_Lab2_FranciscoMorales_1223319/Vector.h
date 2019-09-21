#pragma once
class Vector
{
public:
	int v[71];
	int *liebre;
	int *tortuga;
	int *inicio;
	int *fin;
	bool finalCarrera;
	Vector();
	~Vector();
	System::String^Vector::Recorrido();
	void Vector::MoverLiebre();
	void Vector::MoverTortuga();
	void Vector::Final();
};

