#include "pch.h"
#include "LabsDLL.h"

#include <cmath>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data::OleDb;
using namespace Microsoft::Office::Interop;
using namespace Microsoft::VisualBasic;
using namespace System::IO;

#define SQLiteDBPath "D:\\Downloads\\New_BD_mass.mdb"


namespace LabsDLL {
    // Общие функции для всех лабораторных работ
    double FunctsForAll::Vvod(TextBox^ t)
    {
        if (t->Text == "") {
            t->Text = "0";
            return 0;
        }
        else if (t->Text == "Неизвестно") {
            return -1;
        }
        else {
            return Convert::ToDouble(t->Text->Replace('.', ','));
        }
    }

    void FunctsForAll::Vivod(double x, TextBox^ t)
    {
        t->Text = Convert::ToString(x);
    }

    void FunctsForAll::RegenerateDataGrid(int arraylen, System::Windows::Forms::DataGridView^ datagrid) {
        datagrid->Columns->Clear();
        for (int i = 0; i < arraylen; i++) {
            System::Windows::Forms::DataGridViewTextBoxColumn^ newcol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            newcol->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
            newcol->HeaderText = Convert::ToString(i);
            newcol->MinimumWidth = 20;
            newcol->Name = L"col" + Convert::ToString(i);
            newcol->Width = 20;
            datagrid->Columns->Add(newcol);
        }
    }

    void FunctsForAll::output_mas(int* array, int arraylen, System::Windows::Forms::DataGridView^ datagrid) {
        FunctsForAll::RegenerateDataGrid(arraylen, datagrid);
        for (int i = 0; i < arraylen; i++) {
            datagrid->Rows[0]->Cells[i]->Value = array[i];
        }
    }

    void FunctsForAll::GenerateArray(int* array, int arraylen, int minvalue, int maxvalue) {
        for (int i = 0; i < arraylen; i++) {
            array[i] = minvalue + (std::rand() % (maxvalue - minvalue + 1));
        }
    }

    void FunctsForAll::input_mas(int* array, int arraylen, System::Windows::Forms::DataGridView^ datagrid) {
        if (datagrid->ColumnCount > 0) {
            for (int i = 0; i < arraylen; i++) {
                array[i] = Convert::ToInt32(datagrid->Rows[0]->Cells[i]->Value);
            }
        }
    }

    void FunctsForAll::add()
    {
        ADOX::Catalog^ k = gcnew ADOX::CatalogClass();
        try {
            k->Create("Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + SQLiteDBPath);
            MessageBox::Show("База данных успешно создана");
        }
        catch (System::Runtime::InteropServices::COMException^ situation)
        {
            MessageBox::Show(situation->Message);
        }
        finally
        {
            k = nullptr;
        }
    }

    void FunctsForAll::add_struct(array<String^>^ names, int colvo, String^ tablename)
    {
        auto p = gcnew OleDbConnection("Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + SQLiteDBPath);
        p->Open();
        String^ rescom = "CREATE TABLE [" + tablename + "] ([Номер элемента] counter";
        for (int i = 0; i < colvo; i++) {
            rescom += ", [" + names[i] + "] char(200)";
        }
        rescom += ")";
        auto c = gcnew OleDbCommand(rescom, p);
        try
        {
            c->ExecuteNonQuery();
        }
        catch (Exception^ situation)
        {
            MessageBox::Show(situation->Message);
        }
        p->Close();
    }

    void FunctsForAll::add_zap(String^ name, String^ value, String^ tablename)
    {
        auto p = gcnew OleDbConnection("Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + SQLiteDBPath);
        p->Open();
        auto CMDRowsCount = gcnew OleDbCommand("SELECT COUNT(*) FROM [" + tablename + "]", p);
        int rowsCount = Convert::ToInt32(CMDRowsCount->ExecuteScalar());
        if (rowsCount == 0) {
            auto c = gcnew OleDbCommand("UPDATE [" + tablename + "] SET [" + name + "] = " + value + " WHERE [Номер элемента] = 1", p);
            c->Connection = p;
            c->ExecuteNonQuery();
        }
        else {
            auto c = gcnew OleDbCommand("INSERT INTO [" + tablename + "]([" + name + "]) VALUES('" + value + "')");
            c->Connection = p;
            c->ExecuteNonQuery();
        }
        p->Close();
    }

    void FunctsForAll::add_zap(String^ name, int* array, int array_len, String^ tablename)
    {
        auto p = gcnew OleDbConnection("Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + SQLiteDBPath);
        p->Open();
        auto CMDRowsCount = gcnew OleDbCommand("SELECT COUNT(*) FROM [" + tablename + "]", p);
        int rowsCount = Convert::ToInt32(CMDRowsCount->ExecuteScalar());
        for (int i = 0; i < array_len; i++)
        {
            if (i + 1 <= rowsCount) {
                auto c = gcnew OleDbCommand("UPDATE [" + tablename + "] SET [" + name + "] = " + array[i] + " WHERE [Номер элемента] = " + (i + 1), p);
                c->Connection = p;
                c->ExecuteNonQuery();
            }
            else {
                auto c = gcnew OleDbCommand("INSERT INTO [" + tablename + "]([" + name + "]) VALUES('" + array[i] + "')");
                c->Connection = p;
                c->ExecuteNonQuery();
            }
        }
        p->Close();
    }

    void FunctsForAll::ZapisWordValue(String^ nazv, String^ value, Microsoft::Office::Interop::Word::ApplicationClass^ Wrd) {
        Wrd->Selection->TypeText(nazv);
        Wrd->Selection->TypeParagraph();
        Wrd->Selection->TypeText(value);
        Wrd->Selection->TypeParagraph();
        Wrd->Selection->TypeParagraph();
    }

    void FunctsForAll::ZapisWordOneArr(String^ nazv, int* arr, int arr_len, Microsoft::Office::Interop::Word::ApplicationClass^ Wrd) {
        Wrd->Selection->TypeText(nazv);
        Wrd->Selection->TypeParagraph();
        Wrd->Selection->TypeParagraph();
        Wrd->Selection->TypeParagraph();
        Object^ t1 = Microsoft::Office::Interop::Word::WdDefaultTableBehavior::wdWord9TableBehavior;
        Object^ t2 = Microsoft::Office::Interop::Word::WdAutoFitBehavior::wdAutoFitContent;
        String^ str;
        Microsoft::Office::Interop::Word::Table^ tbl = Wrd->ActiveDocument->Tables->Add(Wrd->ActiveDocument->Paragraphs[Wrd->ActiveDocument->Paragraphs->Count - 2]->Range, 2, arr_len, t1, t2);
        for (int i = 0; i < arr_len; i++)
        {
            tbl->Cell(1, i + 1)->Range->InsertAfter("[" + Convert::ToString(i) + "]");
            str = String::Format("{0:f0}", arr[i]);
            tbl->Cell(2, i + 1)->Range->InsertAfter(str);
        }
    }

    Microsoft::Office::Interop::Word::ApplicationClass^ FunctsForAll::CreateWordDoc()
    {
        auto Wrd = gcnew Microsoft::Office::Interop::Word::ApplicationClass();
        Wrd->Visible = true;
        auto inf = Type::Missing;
        auto Doc = Wrd->Documents->Add(inf, inf, inf, inf);
        return Wrd;

    }

    void FunctsForAll::ZapisExcelValue(String^ nazv, String^ value, Microsoft::Office::Interop::Excel::ApplicationClass^ XL) {
        auto sheet = (Microsoft::Office::Interop::Excel::Worksheet^)XL->ActiveSheet;
        int LastRow = sheet->UsedRange->Rows->Count;
        int NewRow;
        if (LastRow == 1) {
            NewRow = 1;
        }
        else {
            NewRow = LastRow + 2;
        }
        XL->Cells[NewRow, 1] = nazv;
        XL->Cells[NewRow + 1, 1] = value;
    }

    void FunctsForAll::ZapisExcelOneArr(String^ nazv, int* arr, int arr_len, Microsoft::Office::Interop::Excel::ApplicationClass^ XL) {
        auto sheet = (Microsoft::Office::Interop::Excel::Worksheet^)XL->ActiveSheet;
        int LastRow = sheet->UsedRange->Rows->Count;
        int NewRow;
        if (LastRow == 1) {
            NewRow = 1;
        }
        else {
            NewRow = LastRow + 2;
        }
        String^ str;
        XL->Cells[NewRow, 1] = nazv;
        for (int i = 0; i < arr_len; i++)
        {
            XL->Cells[NewRow + 1, i + 1] = Convert::ToString(i);
            str = String::Format("{0:f0}", arr[i]);
            XL->Cells[NewRow + 2, i + 1] = str;
        }
    }

    Microsoft::Office::Interop::Excel::ApplicationClass^ FunctsForAll::CreateExcelDoc() {
        auto XL = gcnew Microsoft::Office::Interop::Excel::Application();
        XL->Visible = true;
        Object^ t = Type::Missing;
        auto Workbook = XL->Workbooks->Add(t);
        return XL;
    }


    // Функции для 1 лабораторной работы
    double Lab1Functs::Solve1(double a, double b, double x)
    {
        double z = sqrt(a * x * sin(2 * x) + exp(-2 * x) * (x + b));
        return z;
    }

    void Lab1Functs::Solve2(double* w, double a, double b, double x)
    {
        *w = pow(cos(pow(x, 3)), 2) - x / sqrt(pow(a, 2) + pow(b, 2));
    }

    void Lab1Functs::Solve12(double* z, double* w, double a, double b, double x)
    {
        *z = Lab1Functs::Solve1(a, b, x);
        Lab1Functs::Solve2(w, a, b, x);
    }


    // Функции для пошаговой детализации
    double PoshDetFuncts::Sh(double x) {
        return (exp(x) - exp(-x)) / 2;
    }

    double PoshDetFuncts::Solve(double x) {
        return PoshDetFuncts::Sh(x) + tan(x + 1) - pow(tan(2 + PoshDetFuncts::Sh(x - 1)), 2);
    }


    // Функции для 2 лабораторной работы
    int Lab2Functs::SearchMaxChetInd(int* array, int arraylen) {
        int maxchet = array[0] - 1;
        int maxchetind = -1;
        for (int i = 0; i < arraylen; i++) {
            if (array[i] % 2 == 0 && array[i] > maxchet) {
                maxchet = array[i];
                maxchetind = i;
            }
        }
        return maxchetind;
    }

    int Lab2Functs::SearchNewArrayLen(int* array, int arraylen, int maxchetind) {
        int newarrayulen = 0;
        for (int i = 0; i < arraylen; i++) {
            if (array[i] < maxchetind) {
                newarrayulen++;
            }
        }
        return newarrayulen;
    }

    void Lab2Functs::FillNewArray(int* array, int arraylen, int maxchetind, int* resarray) {
        int newi = 0;
        for (int i = 0; i < arraylen; i++) {
            if (array[i] < maxchetind) {
                resarray[newi] = i;
                newi++;
            }
        }
    }


    // Функции для 3 лабораторной работы
    void Lab3Functs::Solve3(int* array, int arraylen, int insertelement, int insertindex) {

        for (int i = arraylen; i > insertindex; i--) {
            array[i] = array[i - 1];
        }
        array[insertindex] = insertelement;
    }

    bool Lab3Functs::Solve4(int* array, int arraylen) {
        bool monot = true;
        for (int i = 1; i < arraylen; i++) {
            if (array[i] > array[i - 1]) {
                monot = false;
                break;
            }
        }
        return monot;
    }

    void Lab3Functs::Solve7(int* array, int arraylen, int* polind, int* polval) {
        for (int i = 0; i < arraylen; i++) {
            if (array[i] > 0) {
                *polind = i;
                *polval = array[i];
                break;
            }
        }
    }

    void Lab3Functs::Solve8(int* array, int arraylen, int* chetind, int* chetval) {
        for (int i = 0; i < arraylen; i++) {
            if (array[i] % 2 == 0) {
                *chetind = i;
                *chetval = array[i];
                break;
            }
        }
    }

    void Lab3Functs::Solve10(int* array, int arraylen) {
        for (int i = 1; i < arraylen; ++i) {
            int key = array[i];
            int left = 0;
            int right = i - 1;

            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (array[mid] > key) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }

            for (int j = i - 1; j >= left; --j) {
                array[j + 1] = array[j];
            }
            array[left] = key;
        }
    }

    void Lab3Functs::Solve11(int* array, int arraylen) {
        for (int i = 0; i < arraylen - 1; ++i) {
            int minIndex = i;

            for (int j = i + 1; j < arraylen; ++j) {
                if (array[j] < array[minIndex]) {
                    minIndex = j;
                }
            }

            if (minIndex != i) {
                int t = array[i];
                array[i] = array[minIndex];
                array[minIndex] = t;
            }
        }
    }

    void Lab3Functs::Solve12(int* array, int arraylen) {
        for (int i = 0; i < arraylen - 1; ++i) {
            for (int j = 0; j < arraylen - i - 1; ++j) {
                if (array[j] > array[j + 1]) {
                    int t = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = t;
                }
            }
        }
    }

    void Lab3Functs::Solve13(int* array, int arraylen) {
        bool flag = true;

        for (int i = 0; i < arraylen - 1 && flag; ++i) {
            flag = false;

            for (int j = 0; j < arraylen - i - 1; ++j) {
                if (array[j] > array[j + 1]) {
                    int t = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = t;
                    flag = true;
                }
            }

            if (!flag) break;
        }
    }
}