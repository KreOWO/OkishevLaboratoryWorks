#pragma once
#include "form_1prom.h"

namespace Labs {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для dopform
	/// </summary>
	public ref class dopform : public System::Windows::Forms::Form
	{
	public:
		dopform(void)
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
		~dopform()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbl_info;
	protected:

	private: System::Windows::Forms::Button^ btn_back;
	private: System::Windows::Forms::Button^ btn_1prom;



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
			this->lbl_info = (gcnew System::Windows::Forms::Label());
			this->btn_back = (gcnew System::Windows::Forms::Button());
			this->btn_1prom = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lbl_info
			// 
			this->lbl_info->AutoSize = true;
			this->lbl_info->Location = System::Drawing::Point(24, 21);
			this->lbl_info->Name = L"lbl_info";
			this->lbl_info->Size = System::Drawing::Size(424, 13);
			this->lbl_info->TabIndex = 0;
			this->lbl_info->Text = L"Дополнительные подпрограммы которые не относятся к лабораторным работам";
			// 
			// btn_back
			// 
			this->btn_back->Location = System::Drawing::Point(13, 226);
			this->btn_back->Name = L"btn_back";
			this->btn_back->Size = System::Drawing::Size(75, 23);
			this->btn_back->TabIndex = 1;
			this->btn_back->Text = L"Назад";
			this->btn_back->UseVisualStyleBackColor = true;
			this->btn_back->Click += gcnew System::EventHandler(this, &dopform::btn_back_Click);
			// 
			// btn_1prom
			// 
			this->btn_1prom->Location = System::Drawing::Point(122, 58);
			this->btn_1prom->Name = L"btn_1prom";
			this->btn_1prom->Size = System::Drawing::Size(221, 23);
			this->btn_1prom->TabIndex = 2;
			this->btn_1prom->Text = L"Пошаговая детализация (1 промзачет)";
			this->btn_1prom->UseVisualStyleBackColor = true;
			this->btn_1prom->Click += gcnew System::EventHandler(this, &dopform::btn_1prom_Click);
			// 
			// dopform
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(477, 261);
			this->Controls->Add(this->btn_1prom);
			this->Controls->Add(this->btn_back);
			this->Controls->Add(this->lbl_info);
			this->Name = L"dopform";
			this->Text = L"Дополнительно";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btn_back_Click(System::Object^ sender, System::EventArgs^ e) {
		Owner->Show();
		this->Close();
	}
	private: System::Void btn_1prom_Click(System::Object^ sender, System::EventArgs^ e) {
		form_1prom^ f = gcnew form_1prom();
		f->Owner = this;
		f->Show();
		this->Hide();
	}/*
	private: System::Void dopform_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		Application::Exit();
	}*/
};
}
