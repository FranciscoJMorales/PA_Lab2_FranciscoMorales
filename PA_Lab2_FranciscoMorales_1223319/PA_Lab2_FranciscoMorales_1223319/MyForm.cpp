#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	PA_Lab2_FranciscoMorales_1223319::MyForm form;
	Application::Run(%form);
	return 0;
}