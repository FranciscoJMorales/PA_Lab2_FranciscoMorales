#pragma once
#include "Vector.h"

namespace PA_Lab2_FranciscoMorales_1223319 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  iniciarBtn;
	protected:
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  recorrido;
	private: System::Windows::Forms::Label^  label1;
	private: System::ComponentModel::IContainer^  components;

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->iniciarBtn = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->recorrido = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// iniciarBtn
			// 
			this->iniciarBtn->Location = System::Drawing::Point(232, 182);
			this->iniciarBtn->Name = L"iniciarBtn";
			this->iniciarBtn->Size = System::Drawing::Size(75, 23);
			this->iniciarBtn->TabIndex = 0;
			this->iniciarBtn->Text = L"Iniciar Carrera";
			this->iniciarBtn->UseVisualStyleBackColor = true;
			this->iniciarBtn->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// recorrido
			// 
			this->recorrido->AutoSize = true;
			this->recorrido->Location = System::Drawing::Point(12, 101);
			this->recorrido->Name = L"recorrido";
			this->recorrido->Size = System::Drawing::Size(65, 13);
			this->recorrido->TabIndex = 1;
			this->recorrido->Text = L"<Recorrido>";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(191, 43);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(150, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Carrera de la liebre y la tortuga";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(520, 261);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->recorrido);
			this->Controls->Add(this->iniciarBtn);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		Vector *carrera;

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		carrera = new Vector();
		recorrido->Text = carrera->Recorrido();
		iniciarBtn->Enabled = false;
		timer1->Start();
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		if (carrera->finalCarrera) {
			iniciarBtn->Enabled = true;
			timer1->Stop();
		}
		else {
			carrera->MoverLiebre();
			carrera->MoverTortuga();
			recorrido->Text = carrera->Recorrido();
		}
	}
	};
}
