#pragma once
#include <random>

namespace Labs {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для form_lab_2
	/// </summary>
	public ref class form_lab_2 : public System::Windows::Forms::Form
	{
	public:
		form_lab_2(void)
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
		~form_lab_2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_back;
	private: System::Windows::Forms::PictureBox^ bp_task;
	private: System::Windows::Forms::Label^ lbl_arraylen;


	private: System::Windows::Forms::TextBox^ tb_arraylen;
	private: System::Windows::Forms::TextBox^ tb_minvalue;
	private: System::Windows::Forms::Label^ lbl_minvalue;







	private: System::Windows::Forms::Button^ btn_generate;
	private: System::Windows::Forms::Button^ btn_solve;










	private: System::Windows::Forms::Label^ lbl_startarray;
	private: System::Windows::Forms::Label^ lbl_answer;
	private: System::Windows::Forms::DataGridView^ dg_start;
	private: System::Windows::Forms::DataGridView^ dg_result;
	private: System::Windows::Forms::Label^ lbl_maxvalue;
	private: System::Windows::Forms::TextBox^ tb_maxvalue;
	private: System::Windows::Forms::TextBox^ tb_resind;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btn_wordwrite;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btn_excelwrite;
	private: System::Windows::Forms::Button^ btn_sqlitewrite;






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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(form_lab_2::typeid));
			this->btn_back = (gcnew System::Windows::Forms::Button());
			this->bp_task = (gcnew System::Windows::Forms::PictureBox());
			this->lbl_arraylen = (gcnew System::Windows::Forms::Label());
			this->tb_arraylen = (gcnew System::Windows::Forms::TextBox());
			this->tb_minvalue = (gcnew System::Windows::Forms::TextBox());
			this->lbl_minvalue = (gcnew System::Windows::Forms::Label());
			this->btn_generate = (gcnew System::Windows::Forms::Button());
			this->btn_solve = (gcnew System::Windows::Forms::Button());
			this->lbl_startarray = (gcnew System::Windows::Forms::Label());
			this->lbl_answer = (gcnew System::Windows::Forms::Label());
			this->dg_start = (gcnew System::Windows::Forms::DataGridView());
			this->dg_result = (gcnew System::Windows::Forms::DataGridView());
			this->lbl_maxvalue = (gcnew System::Windows::Forms::Label());
			this->tb_maxvalue = (gcnew System::Windows::Forms::TextBox());
			this->tb_resind = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btn_wordwrite = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btn_excelwrite = (gcnew System::Windows::Forms::Button());
			this->btn_sqlitewrite = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bp_task))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dg_start))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dg_result))->BeginInit();
			this->SuspendLayout();
			// 
			// btn_back
			// 
			this->btn_back->Location = System::Drawing::Point(12, 477);
			this->btn_back->Name = L"btn_back";
			this->btn_back->Size = System::Drawing::Size(142, 23);
			this->btn_back->TabIndex = 0;
			this->btn_back->Text = L"Вернуться на главную";
			this->btn_back->UseVisualStyleBackColor = true;
			this->btn_back->Click += gcnew System::EventHandler(this, &form_lab_2::btn_back_Click);
			// 
			// bp_task
			// 
			this->bp_task->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bp_task.Image")));
			this->bp_task->Location = System::Drawing::Point(12, 12);
			this->bp_task->Name = L"bp_task";
			this->bp_task->Size = System::Drawing::Size(512, 135);
			this->bp_task->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->bp_task->TabIndex = 1;
			this->bp_task->TabStop = false;
			// 
			// lbl_arraylen
			// 
			this->lbl_arraylen->AutoSize = true;
			this->lbl_arraylen->Location = System::Drawing::Point(14, 168);
			this->lbl_arraylen->Name = L"lbl_arraylen";
			this->lbl_arraylen->Size = System::Drawing::Size(124, 13);
			this->lbl_arraylen->TabIndex = 2;
			this->lbl_arraylen->Text = L"Количество элементов";
			// 
			// tb_arraylen
			// 
			this->tb_arraylen->Location = System::Drawing::Point(154, 165);
			this->tb_arraylen->Name = L"tb_arraylen";
			this->tb_arraylen->Size = System::Drawing::Size(56, 20);
			this->tb_arraylen->TabIndex = 3;
			this->tb_arraylen->Text = L"10";
			this->tb_arraylen->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &form_lab_2::tb_arraylen_KeyPress);
			// 
			// tb_minvalue
			// 
			this->tb_minvalue->Location = System::Drawing::Point(154, 196);
			this->tb_minvalue->Name = L"tb_minvalue";
			this->tb_minvalue->Size = System::Drawing::Size(56, 20);
			this->tb_minvalue->TabIndex = 5;
			this->tb_minvalue->Text = L"-100";
			this->tb_minvalue->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &form_lab_2::tb_minvalue_KeyPress);
			// 
			// lbl_minvalue
			// 
			this->lbl_minvalue->AutoSize = true;
			this->lbl_minvalue->Location = System::Drawing::Point(14, 199);
			this->lbl_minvalue->Name = L"lbl_minvalue";
			this->lbl_minvalue->Size = System::Drawing::Size(128, 13);
			this->lbl_minvalue->TabIndex = 4;
			this->lbl_minvalue->Text = L"Минимальное значение";
			// 
			// btn_generate
			// 
			this->btn_generate->BackColor = System::Drawing::SystemColors::Control;
			this->btn_generate->Location = System::Drawing::Point(324, 165);
			this->btn_generate->Name = L"btn_generate";
			this->btn_generate->Size = System::Drawing::Size(111, 23);
			this->btn_generate->TabIndex = 8;
			this->btn_generate->Text = L"Сгенерировать";
			this->btn_generate->UseVisualStyleBackColor = false;
			this->btn_generate->Click += gcnew System::EventHandler(this, &form_lab_2::btn_generate_Click);
			// 
			// btn_solve
			// 
			this->btn_solve->Enabled = false;
			this->btn_solve->Location = System::Drawing::Point(342, 220);
			this->btn_solve->Name = L"btn_solve";
			this->btn_solve->Size = System::Drawing::Size(75, 23);
			this->btn_solve->TabIndex = 10;
			this->btn_solve->Text = L"Обработать";
			this->btn_solve->UseVisualStyleBackColor = true;
			this->btn_solve->Click += gcnew System::EventHandler(this, &form_lab_2::btn_solve_Click);
			// 
			// lbl_startarray
			// 
			this->lbl_startarray->AutoSize = true;
			this->lbl_startarray->Location = System::Drawing::Point(14, 265);
			this->lbl_startarray->Name = L"lbl_startarray";
			this->lbl_startarray->Size = System::Drawing::Size(140, 13);
			this->lbl_startarray->TabIndex = 13;
			this->lbl_startarray->Text = L"Сгенерированный массив";
			// 
			// lbl_answer
			// 
			this->lbl_answer->AutoSize = true;
			this->lbl_answer->Location = System::Drawing::Point(12, 366);
			this->lbl_answer->Name = L"lbl_answer";
			this->lbl_answer->Size = System::Drawing::Size(161, 13);
			this->lbl_answer->TabIndex = 14;
			this->lbl_answer->Text = L"Результат работы программы";
			// 
			// dg_start
			// 
			this->dg_start->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dg_start->Location = System::Drawing::Point(12, 290);
			this->dg_start->Name = L"dg_start";
			this->dg_start->RowHeadersVisible = false;
			this->dg_start->Size = System::Drawing::Size(512, 62);
			this->dg_start->TabIndex = 15;
			// 
			// dg_result
			// 
			this->dg_result->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dg_result->Location = System::Drawing::Point(12, 409);
			this->dg_result->Name = L"dg_result";
			this->dg_result->RowHeadersVisible = false;
			this->dg_result->Size = System::Drawing::Size(512, 62);
			this->dg_result->TabIndex = 16;
			// 
			// lbl_maxvalue
			// 
			this->lbl_maxvalue->AutoSize = true;
			this->lbl_maxvalue->Location = System::Drawing::Point(14, 230);
			this->lbl_maxvalue->Name = L"lbl_maxvalue";
			this->lbl_maxvalue->Size = System::Drawing::Size(134, 13);
			this->lbl_maxvalue->TabIndex = 6;
			this->lbl_maxvalue->Text = L"Максимальное значение";
			// 
			// tb_maxvalue
			// 
			this->tb_maxvalue->Location = System::Drawing::Point(154, 227);
			this->tb_maxvalue->Name = L"tb_maxvalue";
			this->tb_maxvalue->Size = System::Drawing::Size(56, 20);
			this->tb_maxvalue->TabIndex = 7;
			this->tb_maxvalue->Text = L"100";
			this->tb_maxvalue->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &form_lab_2::tb_maxvalue_KeyPress);
			// 
			// tb_resind
			// 
			this->tb_resind->Enabled = false;
			this->tb_resind->Location = System::Drawing::Point(243, 383);
			this->tb_resind->Name = L"tb_resind";
			this->tb_resind->Size = System::Drawing::Size(56, 20);
			this->tb_resind->TabIndex = 18;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(14, 386);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(223, 13);
			this->label1->TabIndex = 17;
			this->label1->Text = L"Индекс максимального четного элемента";
			// 
			// btn_wordwrite
			// 
			this->btn_wordwrite->Enabled = false;
			this->btn_wordwrite->Location = System::Drawing::Point(285, 477);
			this->btn_wordwrite->Name = L"btn_wordwrite";
			this->btn_wordwrite->Size = System::Drawing::Size(76, 23);
			this->btn_wordwrite->TabIndex = 19;
			this->btn_wordwrite->Text = L"Word";
			this->btn_wordwrite->UseVisualStyleBackColor = true;
			this->btn_wordwrite->Click += gcnew System::EventHandler(this, &form_lab_2::btn_dbwrite_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(215, 482);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(64, 13);
			this->label2->TabIndex = 20;
			this->label2->Text = L"Записать в";
			// 
			// btn_excelwrite
			// 
			this->btn_excelwrite->Enabled = false;
			this->btn_excelwrite->Location = System::Drawing::Point(367, 477);
			this->btn_excelwrite->Name = L"btn_excelwrite";
			this->btn_excelwrite->Size = System::Drawing::Size(75, 23);
			this->btn_excelwrite->TabIndex = 21;
			this->btn_excelwrite->Text = L"Excel";
			this->btn_excelwrite->UseVisualStyleBackColor = true;
			this->btn_excelwrite->Click += gcnew System::EventHandler(this, &form_lab_2::btn_dbwrite_Click);
			// 
			// btn_sqlitewrite
			// 
			this->btn_sqlitewrite->Enabled = false;
			this->btn_sqlitewrite->Location = System::Drawing::Point(448, 477);
			this->btn_sqlitewrite->Name = L"btn_sqlitewrite";
			this->btn_sqlitewrite->Size = System::Drawing::Size(76, 23);
			this->btn_sqlitewrite->TabIndex = 22;
			this->btn_sqlitewrite->Text = L"SQLite";
			this->btn_sqlitewrite->UseVisualStyleBackColor = true;
			this->btn_sqlitewrite->Click += gcnew System::EventHandler(this, &form_lab_2::btn_dbwrite_Click);
			// 
			// form_lab_2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(539, 511);
			this->Controls->Add(this->btn_sqlitewrite);
			this->Controls->Add(this->btn_excelwrite);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btn_wordwrite);
			this->Controls->Add(this->tb_resind);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dg_result);
			this->Controls->Add(this->dg_start);
			this->Controls->Add(this->lbl_answer);
			this->Controls->Add(this->lbl_startarray);
			this->Controls->Add(this->btn_solve);
			this->Controls->Add(this->btn_generate);
			this->Controls->Add(this->tb_maxvalue);
			this->Controls->Add(this->lbl_maxvalue);
			this->Controls->Add(this->tb_minvalue);
			this->Controls->Add(this->lbl_minvalue);
			this->Controls->Add(this->tb_arraylen);
			this->Controls->Add(this->lbl_arraylen);
			this->Controls->Add(this->bp_task);
			this->Controls->Add(this->btn_back);
			this->Name = L"form_lab_2";
			this->Text = L"Лабораторная работа 2";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bp_task))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dg_start))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dg_result))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btn_back_Click(System::Object^ sender, System::EventArgs^ e) {
		Owner->Show();
		this->Close();
	}
	private: System::Void btn_generate_Click(System::Object^ sender, System::EventArgs^ e) {
		btn_solve->Enabled = true;
		int arraylen, minvalue, maxvalue;
		arraylen = LabsDLL::FunctsForAll::Vvod(tb_arraylen);
		minvalue = LabsDLL::FunctsForAll::Vvod(tb_minvalue);
		maxvalue = LabsDLL::FunctsForAll::Vvod(tb_maxvalue);
		int* array = new int[arraylen];
		LabsDLL::FunctsForAll::GenerateArray(array, arraylen, minvalue, maxvalue);
		LabsDLL::FunctsForAll::output_mas(array, arraylen, dg_start);

	}
	private: System::Void btn_solve_Click(System::Object^ sender, System::EventArgs^ e) {
		btn_wordwrite->Enabled = true;
		btn_excelwrite->Enabled = true;
		btn_sqlitewrite->Enabled = true;
		int arraylen = LabsDLL::FunctsForAll::Vvod(tb_arraylen);
		int* array = new int[arraylen]{};
		LabsDLL::FunctsForAll::input_mas(array, arraylen, dg_start);
		int maxchetind = LabsDLL::Lab2Functs::SearchMaxChetInd(array, arraylen);
		int resarraylen = LabsDLL::Lab2Functs::SearchNewArrayLen(array, arraylen, maxchetind);
		int* resarray = new int[resarraylen] {};
		LabsDLL::Lab2Functs::FillNewArray(array, arraylen, maxchetind, resarray);
		LabsDLL::FunctsForAll::Vivod(maxchetind, tb_resind);
		LabsDLL::FunctsForAll::output_mas(resarray, resarraylen, dg_result);
	}
	private: System::Void tb_arraylen_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!((e->KeyChar >= '0') && (e->KeyChar <= '9') || (e->KeyChar == 8))) e->KeyChar = Char(0);
	}
	private: System::Void tb_minvalue_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!((e->KeyChar >= '0') && (e->KeyChar <= '9') || (e->KeyChar == '-') || (e->KeyChar == 8))) e->KeyChar = Char(0);
	}
	private: System::Void tb_maxvalue_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!((e->KeyChar >= '0') && (e->KeyChar <= '9') || (e->KeyChar == '-') || (e->KeyChar == 8))) e->KeyChar = Char(0);
	}
	private: System::Void tb_startarray_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!((e->KeyChar >= '0') && (e->KeyChar <= '9') || (e->KeyChar == '-') || (e->KeyChar == ' ') || (e->KeyChar == 8))) e->KeyChar = Char(0);
	}
	private: System::Void btn_dbwrite_Click(System::Object^ sender, System::EventArgs^ e) {
		int arraylen = LabsDLL::FunctsForAll::Vvod(tb_arraylen);
		int* arr = new int[arraylen] {};
		LabsDLL::FunctsForAll::input_mas(arr, arraylen, dg_start);
		int maxchetind = LabsDLL::Lab2Functs::SearchMaxChetInd(arr, arraylen);
		int resarraylen = LabsDLL::Lab2Functs::SearchNewArrayLen(arr, arraylen, maxchetind);
		int* resarray = new int[resarraylen] {};
		LabsDLL::FunctsForAll::input_mas(resarray, resarraylen, dg_result);

		if (sender == btn_wordwrite) {
			auto Wrd = LabsDLL::FunctsForAll::CreateWordDoc();
			LabsDLL::FunctsForAll::ZapisWordOneArr("Исходный массив", arr, arraylen, Wrd);
			LabsDLL::FunctsForAll::ZapisWordOneArr("Результирующий массив", resarray, resarraylen, Wrd);
		}
		else if (sender == btn_excelwrite) {
			auto XL = LabsDLL::FunctsForAll::CreateExcelDoc();
			LabsDLL::FunctsForAll::ZapisExcelOneArr("Исходный массив", arr, arraylen, XL);
			LabsDLL::FunctsForAll::ZapisExcelOneArr("Результирующий массив", resarray, resarraylen, XL);
		}
		else if (sender == btn_sqlitewrite) {
			LabsDLL::FunctsForAll::add();
			array<String^>^ names = gcnew array<String^> {"Исходный массив", "Результирующий массив"};
			LabsDLL::FunctsForAll::add_struct(names, 2, "Massivs");
			MessageBox::Show("Структура базы данных записана");
			LabsDLL::FunctsForAll::add_zap(names[1], resarray, resarraylen, "Massivs");
			LabsDLL::FunctsForAll::add_zap(names[0], arr, arraylen, "Massivs");
			MessageBox::Show("Все записи добавлены");
		}
	}
};
}