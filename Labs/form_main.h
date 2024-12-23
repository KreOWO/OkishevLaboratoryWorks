#pragma once

#include "form_lab_1.h"
#include "form_lab_2.h"
#include "form_lab_3.h"
#include "form_dopform.h"
#include "form_1prom.h"

namespace Labs {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для form_main
	/// </summary>
	public ref class form_main : public System::Windows::Forms::Form
	{
	public:
		form_main(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~form_main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_lab_1;
	private: System::Windows::Forms::Button^ btn_lab_2;
	private: System::Windows::Forms::Button^ btn_lab_3;


	private: System::Windows::Forms::Label^ lbl_MTUCI;
	private: System::Windows::Forms::Label^ lbl_kafedra;
	private: System::Windows::Forms::Label^ lbl_disciplina;
	private: System::Windows::Forms::Label^ lbl_podgjtovil;
	private: System::Windows::Forms::Label^ lbl_whocheck;
	private: System::Windows::Forms::Label^ lbl_variant13;
	private: System::Windows::Forms::Label^ lbl_Moscow;
	private: System::Windows::Forms::Label^ lbl_labs;
	private: System::Windows::Forms::Button^ btn_dop;




	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btn_lab_1 = (gcnew System::Windows::Forms::Button());
			this->btn_lab_2 = (gcnew System::Windows::Forms::Button());
			this->btn_lab_3 = (gcnew System::Windows::Forms::Button());
			this->lbl_MTUCI = (gcnew System::Windows::Forms::Label());
			this->lbl_kafedra = (gcnew System::Windows::Forms::Label());
			this->lbl_disciplina = (gcnew System::Windows::Forms::Label());
			this->lbl_podgjtovil = (gcnew System::Windows::Forms::Label());
			this->lbl_whocheck = (gcnew System::Windows::Forms::Label());
			this->lbl_variant13 = (gcnew System::Windows::Forms::Label());
			this->lbl_Moscow = (gcnew System::Windows::Forms::Label());
			this->lbl_labs = (gcnew System::Windows::Forms::Label());
			this->btn_dop = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btn_lab_1
			// 
			this->btn_lab_1->Location = System::Drawing::Point(12, 455);
			this->btn_lab_1->Name = L"btn_lab_1";
			this->btn_lab_1->Size = System::Drawing::Size(154, 23);
			this->btn_lab_1->TabIndex = 0;
			this->btn_lab_1->Text = L"Лабораторная работа 1";
			this->btn_lab_1->UseVisualStyleBackColor = true;
			this->btn_lab_1->Click += gcnew System::EventHandler(this, &form_main::btn_lab_1_Click);
			// 
			// btn_lab_2
			// 
			this->btn_lab_2->Location = System::Drawing::Point(12, 484);
			this->btn_lab_2->Name = L"btn_lab_2";
			this->btn_lab_2->Size = System::Drawing::Size(154, 23);
			this->btn_lab_2->TabIndex = 1;
			this->btn_lab_2->Text = L"Лабораторная работа 2";
			this->btn_lab_2->UseVisualStyleBackColor = true;
			this->btn_lab_2->Click += gcnew System::EventHandler(this, &form_main::btn_lab_2_Click);
			// 
			// btn_lab_3
			// 
			this->btn_lab_3->Location = System::Drawing::Point(12, 513);
			this->btn_lab_3->Name = L"btn_lab_3";
			this->btn_lab_3->Size = System::Drawing::Size(154, 23);
			this->btn_lab_3->TabIndex = 2;
			this->btn_lab_3->Text = L"Лабораторная работа 3";
			this->btn_lab_3->UseVisualStyleBackColor = true;
			this->btn_lab_3->Click += gcnew System::EventHandler(this, &form_main::btn_lab_3_Click);
			// 
			// lbl_MTUCI
			// 
			this->lbl_MTUCI->AutoSize = true;
			this->lbl_MTUCI->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13));
			this->lbl_MTUCI->Location = System::Drawing::Point(95, 45);
			this->lbl_MTUCI->Name = L"lbl_MTUCI";
			this->lbl_MTUCI->Size = System::Drawing::Size(668, 22);
			this->lbl_MTUCI->TabIndex = 5;
			this->lbl_MTUCI->Text = L"\"МОСКОВСКИЙ ТЕХНИЧЕСКИЙ УНИВЕРСИТЕТ СВЯЗИ И ИНФОРМАТИКИ\"";
			// 
			// lbl_kafedra
			// 
			this->lbl_kafedra->AutoSize = true;
			this->lbl_kafedra->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->lbl_kafedra->Location = System::Drawing::Point(316, 85);
			this->lbl_kafedra->Name = L"lbl_kafedra";
			this->lbl_kafedra->Size = System::Drawing::Size(185, 18);
			this->lbl_kafedra->TabIndex = 6;
			this->lbl_kafedra->Text = L"Кафедра \"Информатика\"";
			// 
			// lbl_disciplina
			// 
			this->lbl_disciplina->AutoSize = true;
			this->lbl_disciplina->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->lbl_disciplina->Location = System::Drawing::Point(170, 152);
			this->lbl_disciplina->Name = L"lbl_disciplina";
			this->lbl_disciplina->Size = System::Drawing::Size(462, 18);
			this->lbl_disciplina->TabIndex = 7;
			this->lbl_disciplina->Text = L"Дисциплина: Информационные технологии и программирование";
			// 
			// lbl_podgjtovil
			// 
			this->lbl_podgjtovil->AutoSize = true;
			this->lbl_podgjtovil->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->lbl_podgjtovil->Location = System::Drawing::Point(423, 304);
			this->lbl_podgjtovil->Name = L"lbl_podgjtovil";
			this->lbl_podgjtovil->Size = System::Drawing::Size(261, 18);
			this->lbl_podgjtovil->TabIndex = 8;
			this->lbl_podgjtovil->Text = L"Подготовил: Окишев К. А. БМИ2301";
			// 
			// lbl_whocheck
			// 
			this->lbl_whocheck->AutoSize = true;
			this->lbl_whocheck->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->lbl_whocheck->Location = System::Drawing::Point(423, 331);
			this->lbl_whocheck->Name = L"lbl_whocheck";
			this->lbl_whocheck->Size = System::Drawing::Size(410, 18);
			this->lbl_whocheck->TabIndex = 9;
			this->lbl_whocheck->Text = L"Проверил: доцент кафедры \"Информатика\" Гуриков С.Р.";
			// 
			// lbl_variant13
			// 
			this->lbl_variant13->AutoSize = true;
			this->lbl_variant13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->lbl_variant13->Location = System::Drawing::Point(365, 454);
			this->lbl_variant13->Name = L"lbl_variant13";
			this->lbl_variant13->Size = System::Drawing::Size(85, 18);
			this->lbl_variant13->TabIndex = 10;
			this->lbl_variant13->Text = L"Вариант 13";
			// 
			// lbl_Moscow
			// 
			this->lbl_Moscow->AutoSize = true;
			this->lbl_Moscow->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->lbl_Moscow->Location = System::Drawing::Point(359, 484);
			this->lbl_Moscow->Name = L"lbl_Moscow";
			this->lbl_Moscow->Size = System::Drawing::Size(108, 18);
			this->lbl_Moscow->TabIndex = 11;
			this->lbl_Moscow->Text = L"Москва 2024г.";
			// 
			// lbl_labs
			// 
			this->lbl_labs->AutoSize = true;
			this->lbl_labs->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->lbl_labs->Location = System::Drawing::Point(321, 118);
			this->lbl_labs->Name = L"lbl_labs";
			this->lbl_labs->Size = System::Drawing::Size(168, 18);
			this->lbl_labs->TabIndex = 12;
			this->lbl_labs->Text = L"Лабораторные работы";
			// 
			// btn_dop
			// 
			this->btn_dop->Location = System::Drawing::Point(12, 542);
			this->btn_dop->Name = L"btn_dop";
			this->btn_dop->Size = System::Drawing::Size(154, 23);
			this->btn_dop->TabIndex = 13;
			this->btn_dop->Text = L"Дополнительно";
			this->btn_dop->UseVisualStyleBackColor = true;
			this->btn_dop->Click += gcnew System::EventHandler(this, &form_main::btn_dop_Click);
			// 
			// form_main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(850, 580);
			this->Controls->Add(this->btn_dop);
			this->Controls->Add(this->lbl_labs);
			this->Controls->Add(this->lbl_Moscow);
			this->Controls->Add(this->lbl_variant13);
			this->Controls->Add(this->lbl_whocheck);
			this->Controls->Add(this->lbl_podgjtovil);
			this->Controls->Add(this->lbl_disciplina);
			this->Controls->Add(this->lbl_kafedra);
			this->Controls->Add(this->lbl_MTUCI);
			this->Controls->Add(this->btn_lab_3);
			this->Controls->Add(this->btn_lab_2);
			this->Controls->Add(this->btn_lab_1);
			this->Name = L"form_main";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Титульный лист";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &form_main::form_main_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btn_lab_1_Click(System::Object^ sender, System::EventArgs^ e) {
		form_lab_1^ f = gcnew form_lab_1();
		f->Owner = this;
		f->Show();
		this->Hide();
	}
	private: System::Void btn_lab_2_Click(System::Object^ sender, System::EventArgs^ e) {
		form_lab_2^ f = gcnew form_lab_2();
		f->Owner = this;
		f->Show();
		this->Hide();
	}
	private: System::Void btn_lab_3_Click(System::Object^ sender, System::EventArgs^ e) {
		form_lab_3^ f = gcnew form_lab_3();
		f->Owner = this;
		f->Show();
		this->Hide();
	}
	private: System::Void btn_dop_Click(System::Object^ sender, System::EventArgs^ e) {
		dopform^ f = gcnew dopform();
		f->Owner = this;
		f->Show();
		this->Hide();
	}
	private: System::Void form_main_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		Application::Exit();
	}
};
}