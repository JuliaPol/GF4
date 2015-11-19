#pragma once
#include "BT.cpp"

namespace GF4 {

	using namespace BT1;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::PaintEventArgs^ e;
	protected: 

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(927, 330);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Поиск";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(886, 295);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(173, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(883, 267);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(155, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Введите элемент для поиска";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->panel1->Location = System::Drawing::Point(13, 23);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(839, 436);
			this->panel1->TabIndex = 3;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(878, 107);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(181, 84);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Построить дерево";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1071, 480);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}



#pragma endregion

		inline void displayBT (binTree b, int theX, int theY,int n, int theX1, int theY1)
	{	// n - уровень узла
		/*ofstream out;
		out.open("output.txt");*/
		Graphics ^panelGraphics = panel1->CreateGraphics();
		if (b!=NULL) 
		{
			Label^ label = gcnew Label();
			label->Font = gcnew System::Drawing::Font("verdana",11);
			label->Width = 20;
			label->BackColor = Color::YellowGreen;
			label->Location = Point(theX1, theY1);
			label->Text = Convert::ToString((wchar_t)RootBT(b));
			panel1->Controls->Add(label);
			
			if(theX !=theX1 && theY !=theY1){
			 // Draw line to screen.
				panelGraphics->DrawLine( gcnew Pen(Color::Brown, 2), Point(theX+10,theY+10), Point(theX1+10,theY1+10));}
			n++;
			if(!isNull(Right1(b))) 
			{
				displayBT (Right1(b),theX1,theY1,n,theX1+150/n,theY1+50);
			}
			
 			if(!isNull(Left1(b))) 
			{
				displayBT (Left1(b),theX1,theY1,n,theX1-150/n,theY1+50);
			}
		}

	}

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
			
				//Graphics ^panelGraphics = panel1->CreateGraphics();
				
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				ifstream in("input.txt");
				binTree b;
				b=enterBT(in);
				bool f=false;
				if(textBox1->Text->Length != 0)
					{
						base x = Convert::ToChar(textBox1->Text);
						if (search(x,b,f)==true)
						MessageBox::Show("Элемент найден");
						else MessageBox::Show("Элемент не найден");
					}
					else
					MessageBox::Show("Введите элемент для поиска!");
	
			 }
	private: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				ifstream in("input.txt");
				binTree b;
				b=enterBT(in);
				displayBT(b,400,20,0,400,20);
				destroy(b);
			 }
};
}
