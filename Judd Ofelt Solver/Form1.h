#pragma once
#include "Solver.h"
#include "Parser.h"
#include <vector>
#define EIGEN_NO_CPUID
 #include <intrin.h>
using namespace std;

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

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadFromFileToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;

	private: System::Windows::Forms::ToolStripMenuItem^  loadEmissionDataToolStripMenuItem;
	private: System::Windows::Forms::TextBox^  o2tb;
	private: System::Windows::Forms::TextBox^  o4tb;
	private: System::Windows::Forms::TextBox^  o6tb;
	private: System::Windows::Forms::Label^  o2label;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ToolStripMenuItem^  quitToolStripMenuItem;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::TextBox^  OutTB;
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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadFromFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadEmissionDataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->quitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->o2tb = (gcnew System::Windows::Forms::TextBox());
			this->o4tb = (gcnew System::Windows::Forms::TextBox());
			this->o6tb = (gcnew System::Windows::Forms::TextBox());
			this->o2label = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->OutTB = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 304);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(73, 29);
			this->button2->TabIndex = 1;
			this->button2->Text = L"wypełnij";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Visible = false;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(12, 27);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(64, 25);
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
			this->dataGridView1->Location = System::Drawing::Point(30, 6);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(581, 221);
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
			this->lambda->HeaderText = L"lambda [nm]";
			this->lambda->Name = L"lambda";
			// 
			// Pexp
			// 
			this->Pexp->HeaderText = L"Pexp";
			this->Pexp->Name = L"Pexp";
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
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->loadFromFileToolStripMenuItem, 
				this->loadEmissionDataToolStripMenuItem, this->quitToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(35, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// loadFromFileToolStripMenuItem
			// 
			this->loadFromFileToolStripMenuItem->Name = L"loadFromFileToolStripMenuItem";
			this->loadFromFileToolStripMenuItem->Size = System::Drawing::Size(176, 22);
			this->loadFromFileToolStripMenuItem->Text = L"Load from file";
			this->loadFromFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::loadFromFileToolStripMenuItem_Click);
			// 
			// loadEmissionDataToolStripMenuItem
			// 
			this->loadEmissionDataToolStripMenuItem->Name = L"loadEmissionDataToolStripMenuItem";
			this->loadEmissionDataToolStripMenuItem->Size = System::Drawing::Size(176, 22);
			this->loadEmissionDataToolStripMenuItem->Text = L"Load emission data";
			this->loadEmissionDataToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::loadEmissionDataToolStripMenuItem_Click);
			// 
			// quitToolStripMenuItem
			// 
			this->quitToolStripMenuItem->Name = L"quitToolStripMenuItem";
			this->quitToolStripMenuItem->Size = System::Drawing::Size(176, 22);
			this->quitToolStripMenuItem->Text = L"Quit";
			this->quitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::quitToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::openFileDialog1_FileOk);
			// 
			// o2tb
			// 
			this->o2tb->Location = System::Drawing::Point(203, 304);
			this->o2tb->Name = L"o2tb";
			this->o2tb->Size = System::Drawing::Size(100, 20);
			this->o2tb->TabIndex = 9;
			// 
			// o4tb
			// 
			this->o4tb->Location = System::Drawing::Point(345, 304);
			this->o4tb->Name = L"o4tb";
			this->o4tb->Size = System::Drawing::Size(100, 20);
			this->o4tb->TabIndex = 10;
			// 
			// o6tb
			// 
			this->o6tb->Location = System::Drawing::Point(487, 304);
			this->o6tb->Name = L"o6tb";
			this->o6tb->Size = System::Drawing::Size(100, 20);
			this->o6tb->TabIndex = 11;
			// 
			// o2label
			// 
			this->o2label->AutoSize = true;
			this->o2label->Location = System::Drawing::Point(171, 308);
			this->o2label->Name = L"o2label";
			this->o2label->Size = System::Drawing::Size(22, 13);
			this->o2label->TabIndex = 12;
			this->o2label->Text = L"Ω2";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(313, 308);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(22, 13);
			this->label1->TabIndex = 13;
			this->label1->Text = L"Ω4";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(455, 308);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(22, 13);
			this->label2->TabIndex = 14;
			this->label2->Text = L"Ω6";
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(82, 27);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(685, 259);
			this->tabControl1->TabIndex = 15;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->dataGridView1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(677, 233);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Data";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->OutTB);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(677, 233);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Results";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// OutTB
			// 
			this->OutTB->Dock = System::Windows::Forms::DockStyle::Fill;
			this->OutTB->Location = System::Drawing::Point(3, 3);
			this->OutTB->Multiline = true;
			this->OutTB->Name = L"OutTB";
			this->OutTB->Size = System::Drawing::Size(671, 227);
			this->OutTB->TabIndex = 0;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(767, 343);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->o2label);
			this->Controls->Add(this->o6tb);
			this->Controls->Add(this->o4tb);
			this->Controls->Add(this->o2tb);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 //double fpom;
				 //fpom=chi2(experimental.u2,experimental.u4,experimental.u6,experimental.lambda,2.07,1.4322e-020,2.0218e-020,4.69421e-021,experimental.fexp);
				 //cout <<fpom<<endl;
				 //fpom=chi2(experimental.u2,experimental.u4,experimental.u6,experimental.lambda,2.07,0.14727E-19,0.19006E-19,0.86311E-20,experimental.fexp);
				 //cout <<fpom<<endl;
				 ////button1->Text=fpom.ToString();
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		int size;
		size=experimental.u2.size();				
				 dataGridView1->RowCount=size;
				 for (int i=0;i<size;i++){
				 dataGridView1->Rows[i]->Cells[0]->Value= experimental.u2[i].ToString();
				 dataGridView1->Rows[i]->Cells[1]->Value= experimental.u4[i].ToString();
				 dataGridView1->Rows[i]->Cells[2]->Value= experimental.u6[i].ToString();
				 dataGridView1->Rows[i]->Cells[3]->Value= (1e7*experimental.lambda[i]).ToString();
				 dataGridView1->Rows[i]->Cells[4]->Value= experimental.fexp[i].ToString();
				 }
			 }
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				 MatrixXd Hess,Res;
//				 CalculateHessian(experimental.u2,experimental.u4,experimental.u6,experimental.lambda,1.9,1e-24, 1e-24, 1e-24, experimental.fexp, Hess,Res);
};
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 String ^messages;
			 if (experimental.filled==false){
				 loadFromFileToolStripMenuItem_Click(sender, e);
			 }
			 else
			 {
			FitLM(experimental.u2, experimental.u4, experimental.u6, experimental.lambda,experimental.n,experimental.j,experimental.o2,experimental.o4, experimental.o6, experimental.fexp,messages);
			OutTB->Text+=messages;
			o2tb->Text=experimental.o2.ToString("g4");
			o4tb->Text=experimental.o4.ToString("g4");
			o6tb->Text=experimental.o6.ToString("g4");
			 }
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
			 int size;
if (openFileDialog1->ShowDialog() == ::System::Windows::Forms::DialogResult::OK )
				 {
					 LoadAbsoDataFromFile(openFileDialog1->FileNames[0],experimental);
					 size=experimental.u2.size();				
				 dataGridView1->RowCount=size;
				 for (int i=0;i<size;i++){
				 dataGridView1->Rows[i]->Cells[0]->Value= experimental.u2[i].ToString("g5");
				 dataGridView1->Rows[i]->Cells[1]->Value= experimental.u4[i].ToString("g5");
				 dataGridView1->Rows[i]->Cells[2]->Value= experimental.u6[i].ToString("g5");
				 dataGridView1->Rows[i]->Cells[3]->Value= (1e7*experimental.lambda[i]).ToString("g4");
				 dataGridView1->Rows[i]->Cells[4]->Value= experimental.fexp[i].ToString("g4");
				 }
					 experimental.o2=1e-20;
					 experimental.o4=1e-20;
					 experimental.o6=1e-20;
					 experimental.filled=true;
}
		 }
private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
		 }
private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
			/*experimental.o2=0.14727E-19;
			experimental.o4=0.19006E-19;
			experimental.o6=0.86311E-20;
			cout <<chi2(experimental.u2,experimental.u4,experimental.u6,experimental.lambda,experimental.n,experimental.o2,experimental.o4,experimental.o6,experimental.fexp);*/
		 }
private: System::Void loadEmissionDataToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 vector <double> a;
			 int size;
			 double Ajj;
			 Ajj=0;
			 if (openFileDialog1->ShowDialog() == ::System::Windows::Forms::DialogResult::OK )
			 {
				 LoadEmDataFromFile(openFileDialog1->FileNames[0],SmEmmision);
				 CalculateRates(SmEmmision.u2,SmEmmision.u4,SmEmmision.u6,SmEmmision.j,SmEmmision.lambda,experimental.n,experimental.o2,experimental.o4,experimental.o6,a);
				 size=a.size();
				 for (int i=0;i<size;i++) Ajj+=a[i];
				 cout <<"Effective lifetime " <<1e3/Ajj <<" ms"<<endl;
			 }
		 }
private: System::Void quitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 exit(0);
		 }
};
}

