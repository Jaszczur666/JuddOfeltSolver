#pragma once
#include "Solver.h"
#include <vector>
#define EIGEN_NO_CPUID
 #include <intrin.h>
using namespace std;
struct Experiment{
std::vector <double> u2;
std::vector <double> u4;
std::vector <double> u6;
std::vector <double> lambda;
double n;
double o2;
double o4;
double o6;
std::vector <double> fexp;
};
	Experiment experimental;
	Experiment SmEmmision;
namespace JuddOfeltSolver {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  button2;

	private: System::Windows::Forms::Button^  button4;

	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  u2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  u4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  u6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  lambda;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Pexp;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadFromFileToolStripMenuItem;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->u2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->u4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->u6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->lambda = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Pexp = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadFromFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(35, 41);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(73, 29);
			this->button2->TabIndex = 1;
			this->button2->Text = L"wype³nij";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(52, 76);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(116, 61);
			this->button4->TabIndex = 3;
			this->button4->Text = L"LM";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {this->u2, this->u4, 
				this->u6, this->lambda, this->Pexp});
			this->dataGridView1->Location = System::Drawing::Point(174, 27);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(581, 304);
			this->dataGridView1->TabIndex = 5;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::dataGridView1_CellContentClick);
			// 
			// u2
			// 
			this->u2->HeaderText = L"u2";
			this->u2->Name = L"u2";
			// 
			// u4
			// 
			this->u4->HeaderText = L"u4";
			this->u4->Name = L"u4";
			// 
			// u6
			// 
			this->u6->HeaderText = L"u6";
			this->u6->Name = L"u6";
			// 
			// lambda
			// 
			this->lambda->HeaderText = L"lambda";
			this->lambda->Name = L"lambda";
			// 
			// Pexp
			// 
			this->Pexp->HeaderText = L"Pexp";
			this->Pexp->Name = L"Pexp";
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(12, 172);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(144, 46);
			this->button6->TabIndex = 6;
			this->button6->Text = L"button6";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->fileToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(767, 24);
			this->menuStrip1->TabIndex = 7;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->loadFromFileToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(35, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// loadFromFileToolStripMenuItem
			// 
			this->loadFromFileToolStripMenuItem->Name = L"loadFromFileToolStripMenuItem";
			this->loadFromFileToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->loadFromFileToolStripMenuItem->Text = L"Load from file";
			this->loadFromFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::loadFromFileToolStripMenuItem_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(767, 343);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 double fpom;
				 fpom=chi2(experimental.u2,experimental.u4,experimental.u6,experimental.lambda,2.07,1.4322e-020,2.0218e-020,4.69421e-021,experimental.fexp);
				 cout <<fpom<<endl;
				 fpom=chi2(experimental.u2,experimental.u4,experimental.u6,experimental.lambda,2.07,0.14727E-19,0.19006E-19,0.86311E-20,experimental.fexp);
				 cout <<fpom<<endl;
				 //button1->Text=fpom.ToString();
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 double tempf;
				 				 
				
				 dataGridView1->RowCount=9;
				 for (int i=0;i<9;i++){
				 dataGridView1->Rows[i]->Cells[0]->Value= experimental.u2[i].ToString();
				 dataGridView1->Rows[i]->Cells[1]->Value= experimental.u4[i].ToString();
				 dataGridView1->Rows[i]->Cells[2]->Value= experimental.u6[i].ToString();
				 dataGridView1->Rows[i]->Cells[3]->Value= experimental.lambda[i].ToString();
				 dataGridView1->Rows[i]->Cells[4]->Value= experimental.fexp[i].ToString();
				 }
			 }
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				 MatrixXd Hess,Res;
				 CalculateHessian(experimental.u2,experimental.u4,experimental.u6,experimental.lambda,1.9,1e-24, 1e-24, 1e-24, experimental.fexp, Hess,Res);
};
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			FitLM(experimental.u2, experimental.u4, experimental.u6, experimental.lambda,experimental.n,experimental.o2,experimental.o4, experimental.o6, experimental.fexp);
		 };
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 	 
		 }
private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		 }
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 vector <double> a;
			
			 CalculateRates(SmEmmision.u2,SmEmmision.u4,SmEmmision.u6,6,SmEmmision.lambda,experimental.n,experimental.o2,experimental.o4,experimental.o6,a);
			 cout <<"FFFFFFFF"<<endl;
			 CalculateRates(SmEmmision.u2,SmEmmision.u4,SmEmmision.u6,6,SmEmmision.lambda,2.12,1.4e-20,2.23e-20,0.9e-20,a);
			 cout <<"FFFFFFFF"<<endl;
			 CalculateRates(SmEmmision.u2,SmEmmision.u4,SmEmmision.u6,6,SmEmmision.lambda,1.85,1.12e-20,5.57e-20,2.78e-20,a);
		 }
private: System::Void loadFromFileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

		 }
};
}

