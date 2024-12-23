#include "form_main.h"
#include "form_lab_1.h"
#include "form_lab_2.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main(array<String^>^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Labs::form_main form;
	Application::Run(%form);
}