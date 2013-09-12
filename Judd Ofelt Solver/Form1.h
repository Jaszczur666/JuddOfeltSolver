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
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  u2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  u4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  u6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  lambda;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Pexp;
	private: System::Windows::Forms::Button^  button6;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->u2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->u4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->u6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->lambda = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Pexp = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button6 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(50, 29);
			this->button1->TabIndex = 0;
			this->button1->Text = L"chi2";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(68, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(73, 29);
			this->button2->TabIndex = 1;
			this->button2->Text = L"wype³nij";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(93, 47);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"hessian";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
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
			// button5
			// 
			this->button5->Location = System::Drawing::Point(12, 47);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 4;
			this->button5->Text = L"button5";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {this->u2, this->u4, 
				this->u6, this->lambda, this->Pexp});
			this->dataGridView1->Location = System::Drawing::Point(174, 5);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(581, 326);
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
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(767, 343);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

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
				 				 
				 experimental.u2.push_back(0.371);//1
				 experimental.u2.push_back(0.002);//2
				 experimental.u2.push_back(0.0);//3
				 experimental.u2.push_back(0.0);//4
				 experimental.u2.push_back(0.0);//5
				 experimental.u2.push_back(0.0);//6
				 experimental.u2.push_back(0.0);//7
				 experimental.u2.push_back(0.0002);//8
				 experimental.u2.push_back(0.0);//9

				 experimental.u4.push_back(0.4218);//1
				 experimental.u4.push_back(0.1435);//2
				 experimental.u4.push_back(0.207);//3
				 experimental.u4.push_back(0.0006);//4
				 experimental.u4.push_back(0.0034);//5
				 experimental.u4.push_back(0.1663);//6
				 experimental.u4.push_back(0.0014);//7
				 experimental.u4.push_back(0.053);//8
				 experimental.u4.push_back(0.0006);//9

				 experimental.u6.push_back(0);//1
				 experimental.u6.push_back(0.4294);//2
				 experimental.u6.push_back(0.3408);//3
				 experimental.u6.push_back(0.0518);//4
				 experimental.u6.push_back(0.0370);//5
				 experimental.u6.push_back(0.0106);//6
				 experimental.u6.push_back(0.0634);//7
				 experimental.u6.push_back(0.0);//8
				 experimental.u6.push_back(0.0486);//9

				 experimental.lambda.push_back(1429.4e-7);//1
				 experimental.lambda.push_back(1230.0e-7);//2
				 experimental.lambda.push_back(1078.1e-7);//3
				 experimental.lambda.push_back(944.49e-7);//4
				 experimental.lambda.push_back(475.81e-7);//5
				 experimental.lambda.push_back(403.65e-7);//6
				 experimental.lambda.push_back(375.30e-7);//7
				 experimental.lambda.push_back(362.11e-7);//8
				 experimental.lambda.push_back(344.55e-7);//9



				 experimental.fexp.push_back(4.75844E-6);
				 experimental.fexp.push_back(2.36743E-6);
				 experimental.fexp.push_back(1.45904E-6);
				 experimental.fexp.push_back(1.94211E-7);
				 experimental.fexp.push_back(1.10471E-6);
				 experimental.fexp.push_back(4.5504E-6);
				 experimental.fexp.push_back(9.52891E-7);
				 experimental.fexp.push_back(1.3431E-6);
				 experimental.fexp.push_back(5.50825E-7);
				 experimental.n=1.9;
				 experimental.o2=1e-20;
				 experimental.o4=1e-20;
				 experimental.o6=1e-20;
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
			 	 experimental.u2.push_back(0.371);//1
				 experimental.u2.push_back(0.002);//2
				 experimental.u2.push_back(0.0);//3
				 experimental.u2.push_back(0.0);//4
				 experimental.u2.push_back(0.0034);//5
				 experimental.u2.push_back(0.0003);//6
				 experimental.u2.push_back(0.0002);//7
				 experimental.u2.push_back(0.0002);//8


				 experimental.u4.push_back(0.4224);//1
				 experimental.u4.push_back(0.1435);//2
				 experimental.u4.push_back(0.0207);//3
				 experimental.u4.push_back(0.0006);//4
				 experimental.u4.push_back(0.0058);//5
				 experimental.u4.push_back(0.1680);//6
				 experimental.u4.push_back(0.0544);//7
				 experimental.u4.push_back(0.0530);//8

				 experimental.u6.push_back(0.0712);//1
				 experimental.u6.push_back(0.4294);//2
				 experimental.u6.push_back(0.3408);//3
				 experimental.u6.push_back(0.0518);//4
				 experimental.u6.push_back(0.0753);//5
				 experimental.u6.push_back(0.0136);//6
				 experimental.u6.push_back(0.0642);//7
				 experimental.u6.push_back(0.0);//8

				 experimental.lambda.push_back(1./7168);
				 experimental.lambda.push_back(1./8006);
				 experimental.lambda.push_back(1./9208);
				 experimental.lambda.push_back(1./10537);
				 experimental.lambda.push_back(1./21514);
				 experimental.lambda.push_back(1./24630);
				 experimental.lambda.push_back(1./26469);
				 experimental.lambda.push_back(1./27487);

experimental.fexp.push_back(7.75E-6);
experimental.fexp.push_back(3.65E-6);
experimental.fexp.push_back(2.73E-6);
experimental.fexp.push_back(5.43E-7);
experimental.fexp.push_back(2.39E-6);
experimental.fexp.push_back(7.2E-6);
experimental.fexp.push_back(2.42E-6);
experimental.fexp.push_back(2.07E-6);

				 experimental.n=1.9;
				 experimental.o2=1e-20;
				 experimental.o4=1e-20;
				 experimental.o6=1e-20;
		 }
private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		 }
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 vector <double> a;
			 SmEmmision.u2.clear();
			 SmEmmision.u4.clear();
			 SmEmmision.u6.clear();
			 SmEmmision.u2.push_back(0);
			 SmEmmision.u4.push_back(0.0001);
			 SmEmmision.u6.push_back(0.0005);
			 SmEmmision.lambda.push_back(1./6851);
			 SmEmmision.u2.push_back(0.0018);
			 SmEmmision.u4.push_back(0.0003);
			 SmEmmision.u6.push_back(0.0002);
			 SmEmmision.lambda.push_back(1./8350);
			 SmEmmision.u2.push_back(0);
			 SmEmmision.u4.push_back(0.0017);
			 SmEmmision.u6.push_back(0.0002);
			 SmEmmision.lambda.push_back(1./9637);
			 SmEmmision.u2.push_back(0.0072);
			 SmEmmision.u4.push_back(0.0017);
			 SmEmmision.u6.push_back(0.0);
			 SmEmmision.lambda.push_back(1./10493);
			 SmEmmision.u2.push_back(0.0011);
			 SmEmmision.u4.push_back(0.0001);
			 SmEmmision.u6.push_back(0.0);
			 SmEmmision.lambda.push_back(1./11016);
			 SmEmmision.lambda.push_back(1./11091);
			 SmEmmision.u2.push_back(0.0);
			 SmEmmision.u4.push_back(0.0);
			 SmEmmision.u6.push_back(0.0002);
			 SmEmmision.lambda.push_back(1./11203);
			 SmEmmision.u2.push_back(0.001);
			 SmEmmision.u4.push_back(0.0);
			 SmEmmision.u6.push_back(0.0);
			 SmEmmision.lambda.push_back(1./12578);
			 SmEmmision.u2.push_back(0.00);
			 SmEmmision.u4.push_back(0.0002);
			 SmEmmision.u6.push_back(0.0018);
			 SmEmmision.lambda.push_back(1./14025);
			 SmEmmision.u2.push_back(0.00);
			 SmEmmision.u4.push_back(0.0053);
			 SmEmmision.u6.push_back(0.0021);
			 SmEmmision.lambda.push_back(1./15396);
			 SmEmmision.u2.push_back(0.0112);
			 SmEmmision.u4.push_back(0.0067);
			 SmEmmision.u6.push_back(0.0020);
			 SmEmmision.lambda.push_back(1./16647);
			 SmEmmision.u2.push_back(0.0001);
			 SmEmmision.u4.push_back(0.0086);
			 SmEmmision.u6.push_back(0.0089);


			 CalculateRates(SmEmmision.u2,SmEmmision.u4,SmEmmision.u6,6,SmEmmision.lambda,experimental.n,experimental.o2,experimental.o4,experimental.o6,a);
			 cout <<"FFFFFFFF"<<endl;
			 CalculateRates(SmEmmision.u2,SmEmmision.u4,SmEmmision.u6,6,SmEmmision.lambda,2.12,1.4e-20,2.23e-20,0.9e-20,a);
			 cout <<"FFFFFFFF"<<endl;
			 CalculateRates(SmEmmision.u2,SmEmmision.u4,SmEmmision.u6,6,SmEmmision.lambda,1.85,1.12e-20,5.57e-20,2.78e-20,a);
		 }
};
}

