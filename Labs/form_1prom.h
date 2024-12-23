#pragma once
#include <cmath>

namespace Labs {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для form_1prom
	/// </summary>
	public ref class form_1prom : public System::Windows::Forms::Form
	{
	public:
		form_1prom(void)
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
		~form_1prom()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ btn_back;

	private: System::Windows::Forms::Label^ lbl_x;
	private: System::Windows::Forms::Label^ lbl_y;
	private: System::Windows::Forms::TextBox^ tb_x;
	private: System::Windows::Forms::TextBox^ tb_y;
	private: System::Windows::Forms::Button^ btn_solve;
	private: System::Windows::Forms::Label^ lbl_info;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::ComponentModel::IContainer^ components;






	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(form_1prom::typeid));
			this->btn_back = (gcnew System::Windows::Forms::Button());
			this->lbl_x = (gcnew System::Windows::Forms::Label());
			this->lbl_y = (gcnew System::Windows::Forms::Label());
			this->tb_x = (gcnew System::Windows::Forms::TextBox());
			this->tb_y = (gcnew System::Windows::Forms::TextBox());
			this->btn_solve = (gcnew System::Windows::Forms::Button());
			this->lbl_info = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// btn_back
			// 
			this->btn_back->Location = System::Drawing::Point(12, 172);
			this->btn_back->Name = L"btn_back";
			this->btn_back->Size = System::Drawing::Size(75, 23);
			this->btn_back->TabIndex = 1;
			this->btn_back->Text = L"Назад";
			this->btn_back->UseVisualStyleBackColor = true;
			this->btn_back->Click += gcnew System::EventHandler(this, &form_1prom::btn_back_Click);
			// 
			// lbl_x
			// 
			this->lbl_x->AutoSize = true;
			this->lbl_x->Location = System::Drawing::Point(12, 139);
			this->lbl_x->Name = L"lbl_x";
			this->lbl_x->Size = System::Drawing::Size(21, 13);
			this->lbl_x->TabIndex = 15;
			this->lbl_x->Text = L"x =";
			// 
			// lbl_y
			// 
			this->lbl_y->AutoSize = true;
			this->lbl_y->Location = System::Drawing::Point(245, 139);
			this->lbl_y->Name = L"lbl_y";
			this->lbl_y->Size = System::Drawing::Size(21, 13);
			this->lbl_y->TabIndex = 16;
			this->lbl_y->Text = L"y =";
			// 
			// tb_x
			// 
			this->tb_x->Location = System::Drawing::Point(39, 136);
			this->tb_x->Name = L"tb_x";
			this->tb_x->Size = System::Drawing::Size(100, 20);
			this->tb_x->TabIndex = 17;
			this->tb_x->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &form_1prom::tb_x_KeyPress);
			// 
			// tb_y
			// 
			this->tb_y->Enabled = false;
			this->tb_y->Location = System::Drawing::Point(272, 136);
			this->tb_y->Name = L"tb_y";
			this->tb_y->Size = System::Drawing::Size(100, 20);
			this->tb_y->TabIndex = 18;
			// 
			// btn_solve
			// 
			this->btn_solve->Location = System::Drawing::Point(155, 134);
			this->btn_solve->Name = L"btn_solve";
			this->btn_solve->Size = System::Drawing::Size(75, 23);
			this->btn_solve->TabIndex = 19;
			this->btn_solve->Text = L"Посчитать";
			this->btn_solve->UseVisualStyleBackColor = true;
			this->btn_solve->Click += gcnew System::EventHandler(this, &form_1prom::btn_solve_Click);
			// 
			// lbl_info
			// 
			this->lbl_info->AutoSize = true;
			this->lbl_info->Location = System::Drawing::Point(12, 107);
			this->lbl_info->Name = L"lbl_info";
			this->lbl_info->Size = System::Drawing::Size(387, 13);
			this->lbl_info->TabIndex = 20;
			this->lbl_info->Text = L"Подставьте значение x и нажмите \"Посчитать\" чтобы получить значение y";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(387, 81);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 21;
			this->pictureBox1->TabStop = false;
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// form_1prom
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(413, 203);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->lbl_info);
			this->Controls->Add(this->btn_solve);
			this->Controls->Add(this->tb_y);
			this->Controls->Add(this->tb_x);
			this->Controls->Add(this->lbl_y);
			this->Controls->Add(this->lbl_x);
			this->Controls->Add(this->btn_back);
			this->Name = L"form_1prom";
			this->Text = L"Пошаговая детализация (1 промзачет)";
			//this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &form_1prom::form_1prom_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btn_back_Click(System::Object^ sender, System::EventArgs^ e) {
		Owner->Show();
		this->Close();
	}
	private: System::Void btn_solve_Click(System::Object^ sender, System::EventArgs^ e) {
		double x, y;
		x = LabsDLL::FunctsForAll::Vvod(tb_x);
		y = LabsDLL::PoshDetFuncts::Solve(x);
		LabsDLL::FunctsForAll::Vivod(y, tb_y);
	}
	private: System::Void tb_x_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!((e->KeyChar >= '0') && (e->KeyChar <= '9') || (e->KeyChar == ',') || (e->KeyChar == '.') || (e->KeyChar == '-') || (e->KeyChar == 8))) e->KeyChar = Char(0);
	}
	};
}
