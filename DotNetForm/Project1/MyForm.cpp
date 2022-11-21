#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Project1;
//go to MyForm.h and look for [namespace ****] where **** is the name of your project..mines name is testing. :)


STAThreadAttribute;

[STAThread]
void main() {
    
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MyForm());


}

