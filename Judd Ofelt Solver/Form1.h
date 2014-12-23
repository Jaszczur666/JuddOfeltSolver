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
	private: System::Windows::Forms::Button^  LevMarButt;




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
	private: System::Windows::Forms::TabPage^  tabData;

	private: System::Windows::Forms::TabPage^  tabResult;

	private: System::Windows::Forms::TextBox^  OutTB;
	private: System::Windows::Forms::TabPage^  tabLaTeX;
	private: System::Windows::Forms::TextBox^  latexBox;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel2;



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
			this->LevMarButt = (gcnew System::Windows::Forms::Button());
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
			this->tabResult = (gcnew System::Windows::Forms::TabPage());
			this->OutTB = (gcnew System::Windows::Forms::TextBox());
			this->tabData = (gcnew System::Windows::Forms::TabPage());
			this->tabLaTeX = (gcnew System::Windows::Forms::TabPage());
			this->latexBox = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel2 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabResult->SuspendLayout();
			this->tabData->SuspendLayout();
			this->tabLaTeX->SuspendLayout();
			this->statusStrip1->SuspendLayout();
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
			// LevMarButt
			// 
			this->LevMarButt->Location = System::Drawing::Point(12, 27);
			this->LevMarButt->Name = L"LevMarButt";
			this->LevMarButt->Size = System::Drawing::Size(64, 25);
			this->LevMarButt->TabIndex = 3;
			this->LevMarButt->Text = L"Load data";
			this->LevMarButt->UseVisualStyleBackColor = true;
			this->LevMarButt->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
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
			this->menuStrip1->Size = System::Drawing::Size(823, 24);
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
			this->o2tb->Location = System::Drawing::Point(203, 292);
			this->o2tb->Name = L"o2tb";
			this->o2tb->Size = System::Drawing::Size(100, 20);
			this->o2tb->TabIndex = 9;
			// 
			// o4tb
			// 
			this->o4tb->Location = System::Drawing::Point(345, 292);
			this->o4tb->Name = L"o4tb";
			this->o4tb->Size = System::Drawing::Size(100, 20);
			this->o4tb->TabIndex = 10;
			// 
			// o6tb
			// 
			this->o6tb->Location = System::Drawing::Point(487, 292);
			this->o6tb->Name = L"o6tb";
			this->o6tb->Size = System::Drawing::Size(100, 20);
			this->o6tb->TabIndex = 11;
			// 
			// o2label
			// 
			this->o2label->AutoSize = true;
			this->o2label->Location = System::Drawing::Point(171, 296);
			this->o2label->Name = L"o2label";
			this->o2label->Size = System::Drawing::Size(22, 13);
			this->o2label->TabIndex = 12;
			this->o2label->Text = L"Ω2";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(313, 296);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(22, 13);
			this->label1->TabIndex = 13;
			this->label1->Text = L"Ω4";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(455, 296);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(22, 13);
			this->label2->TabIndex = 14;
			this->label2->Text = L"Ω6";
			this->label2->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabResult);
			this->tabControl1->Controls->Add(this->tabData);
			this->tabControl1->Controls->Add(this->tabLaTeX);
			this->tabControl1->Location = System::Drawing::Point(82, 27);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(729, 259);
			this->tabControl1->TabIndex = 15;
			// 
			// tabResult
			// 
			this->tabResult->Controls->Add(this->OutTB);
			this->tabResult->Location = System::Drawing::Point(4, 22);
			this->tabResult->Name = L"tabResult";
			this->tabResult->Padding = System::Windows::Forms::Padding(3);
			this->tabResult->Size = System::Drawing::Size(721, 233);
			this->tabResult->TabIndex = 1;
			this->tabResult->Text = L"Results";
			this->tabResult->UseVisualStyleBackColor = true;
			// 
			// OutTB
			// 
			this->OutTB->Dock = System::Windows::Forms::DockStyle::Fill;
			this->OutTB->Location = System::Drawing::Point(3, 3);
			this->OutTB->Multiline = true;
			this->OutTB->Name = L"OutTB";
			this->OutTB->Size = System::Drawing::Size(715, 227);
			this->OutTB->TabIndex = 0;
			// 
			// tabData
			// 
			this->tabData->Controls->Add(this->dataGridView1);
			this->tabData->Location = System::Drawing::Point(4, 22);
			this->tabData->Name = L"tabData";
			this->tabData->Padding = System::Windows::Forms::Padding(3);
			this->tabData->Size = System::Drawing::Size(721, 233);
			this->tabData->TabIndex = 0;
			this->tabData->Text = L"Data";
			this->tabData->UseVisualStyleBackColor = true;
			// 
			// tabLaTeX
			// 
			this->tabLaTeX->Controls->Add(this->latexBox);
			this->tabLaTeX->Location = System::Drawing::Point(4, 22);
			this->tabLaTeX->Name = L"tabLaTeX";
			this->tabLaTeX->Padding = System::Windows::Forms::Padding(3);
			this->tabLaTeX->Size = System::Drawing::Size(721, 233);
			this->tabLaTeX->TabIndex = 2;
			this->tabLaTeX->Text = L"LaTeX Report";
			this->tabLaTeX->UseVisualStyleBackColor = true;
			// 
			// latexBox
			// 
			this->latexBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->latexBox->Location = System::Drawing::Point(3, 3);
			this->latexBox->Multiline = true;
			this->latexBox->Name = L"latexBox";
			this->latexBox->Size = System::Drawing::Size(715, 227);
			this->latexBox->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(628, 290);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 16;
			this->button1->Text = L"Set Omegas";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click_2);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(12, 58);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(64, 25);
			this->button3->TabIndex = 17;
			this->button3->Text = L"LMSol";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click_1);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripStatusLabel1, 
				this->toolStripStatusLabel2});
			this->statusStrip1->Location = System::Drawing::Point(0, 321);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(823, 22);
			this->statusStrip1->TabIndex = 18;
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(100, 17);
			this->toolStripStatusLabel1->Text = L"No data file koaded";
			this->toolStripStatusLabel1->Click += gcnew System::EventHandler(this, &Form1::toolStripStatusLabel1_Click);
			// 
			// toolStripStatusLabel2
			// 
			this->toolStripStatusLabel2->Name = L"toolStripStatusLabel2";
			this->toolStripStatusLabel2->Size = System::Drawing::Size(71, 17);
			this->toolStripStatusLabel2->Text = L"No fit to data";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(823, 343);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->o2label);
			this->Controls->Add(this->o6tb);
			this->Controls->Add(this->o4tb);
			this->Controls->Add(this->o2tb);
			this->Controls->Add(this->LevMarButt);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabResult->ResumeLayout(false);
			this->tabResult->PerformLayout();
			this->tabData->ResumeLayout(false);
			this->tabLaTeX->ResumeLayout(false);
			this->tabLaTeX->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
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
			 String ^messages,^latex;
			 DateTime now;
			 now=DateTime::Now;
			 String ^date=now.ToString("yyyyMMddHHmmss");
			 //System::Console->WriteLine(date);
			 
			 if (experimental.filled==false){
				 loadFromFileToolStripMenuItem_Click(sender, e);
				 
				 if (experimental.filled==true){
					 toolStripStatusLabel1->Text=openFileDialog1->FileNames[0]+ " was loaded";
					 LevMarButt->Text="LM";
				 };
			 }
			 else
			 {
			//FitLM(experimental.u2, experimental.u4, experimental.u6, experimental.lambda,experimental.n,experimental.j,experimental.o2,experimental.o4, experimental.o6, experimental.fexp,messages,latex);
			experimental.FitLevMar(messages,latex);	 
			OutTB->Text+=messages;
			latexBox->Text+=latex;
			o2tb->Text=experimental.o2.ToString("g4");
			o4tb->Text=experimental.o4.ToString("g4");
			o6tb->Text=experimental.o6.ToString("g4");
			System::IO::StreamWriter^ sw=gcnew System::IO::StreamWriter(date+".log");
			sw->WriteLine(OutTB->Text);
			sw->Close();
			 }
		 };
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 	 
		 }
private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		 }
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {

		 }
private: System::Void loadFromFileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 int size;
			 String ^MSG;
if (openFileDialog1->ShowDialog() == ::System::Windows::Forms::DialogResult::OK )
				 {
					 experimental.LoadAbsoDataFromFile(openFileDialog1->FileNames[0],MSG);
					  OutTB->Text+=MSG;
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
			  String ^messages,^latex;
			 double Ajj;
			 Ajj=0;
			 if (openFileDialog1->ShowDialog() == ::System::Windows::Forms::DialogResult::OK )
			 {
				 SmEmmision.LoadEmDataFromFile(openFileDialog1->FileNames[0]);
				 SmEmmision.GetParameters(experimental);
				 //CalculateRates(SmEmmision.u2,SmEmmision.u4,SmEmmision.u6,SmEmmision.j,SmEmmision.lambda,SmEmmision.n,experimental.o2,experimental.o4,experimental.o6,a);
				 SmEmmision.CalculateRates();
				 SmEmmision.ReportRates(messages,latex);
				 			OutTB->Text+=messages;
			latexBox->Text+=latex;
				 
			 }
		 }
private: System::Void quitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 exit(0);
		 }
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button1_Click_2(System::Object^  sender, System::EventArgs^  e) {
			 experimental.o2=(Convert::ToDouble(o2tb->Text));
			  experimental.o4=(Convert::ToDouble(o4tb->Text));
			   experimental.o6=(Convert::ToDouble(o6tb->Text));
		 }
private: System::Void button3_Click_1(System::Object^  sender, System::EventArgs^  e) {
			 			 String ^messages,^latex;
			 if (experimental.filled==false){
				 loadFromFileToolStripMenuItem_Click(sender, e);
			 }
			 else
			 {
			//FitLM(experimental.u2, experimental.u4, experimental.u6, experimental.lambda,experimental.n,experimental.j,experimental.o2,experimental.o4, experimental.o6, experimental.fexp,messages,latex);
			experimental.FitLevMarSol(messages,latex);	 
			OutTB->Text+=messages;
			latexBox->Text+=latex;
			o2tb->Text=experimental.o2.ToString("g4");
			o4tb->Text=experimental.o4.ToString("g4");
			o6tb->Text=experimental.o6.ToString("g4");
			 }

		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void toolStripStatusLabel1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

