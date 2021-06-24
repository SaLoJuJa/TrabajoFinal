#pragma once
#include "FrmPrincipal.h"

namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	public ref class FrmMenu : public System::Windows::Forms::Form
	{
	public:
		FrmMenu(void)
		{
			InitializeComponent();
			//Buffer
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);

			//Bitmaps
			bmpBackground = gcnew Bitmap("nebula.jpg");

			//Sound
			spmusic = gcnew SoundPlayer("sound.wav");
			
		}

	private:
		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		//Bitmaps
		Bitmap^ bmpBackground;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::NumericUpDown^ numHabitants;

	private: System::Windows::Forms::NumericUpDown^ numAgent;

	private: System::Windows::Forms::NumericUpDown^ numAlly;

	private: System::Windows::Forms::NumericUpDown^ numTime;

	private: System::Windows::Forms::PictureBox^ pictureBox1;

		//Sound
		SoundPlayer^ spmusic;


	protected:
		~FrmMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ btnInstructions;
	private: System::Windows::Forms::Button^ btnPlay;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmMenu::typeid));
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			   this->numHabitants = (gcnew System::Windows::Forms::NumericUpDown());
			   this->numAgent = (gcnew System::Windows::Forms::NumericUpDown());
			   this->numAlly = (gcnew System::Windows::Forms::NumericUpDown());
			   this->numTime = (gcnew System::Windows::Forms::NumericUpDown());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->btnInstructions = (gcnew System::Windows::Forms::Button());
			   this->btnPlay = (gcnew System::Windows::Forms::Button());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->panel1->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numHabitants))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numAgent))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numAlly))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numTime))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // panel1
			   // 
			   this->panel1->Controls->Add(this->pictureBox1);
			   this->panel1->Controls->Add(this->numHabitants);
			   this->panel1->Controls->Add(this->numAgent);
			   this->panel1->Controls->Add(this->numAlly);
			   this->panel1->Controls->Add(this->numTime);
			   this->panel1->Controls->Add(this->label4);
			   this->panel1->Controls->Add(this->label3);
			   this->panel1->Controls->Add(this->label2);
			   this->panel1->Controls->Add(this->label1);
			   this->panel1->Controls->Add(this->btnInstructions);
			   this->panel1->Controls->Add(this->btnPlay);
			   this->panel1->Location = System::Drawing::Point(6, 5);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(820, 656);
			   this->panel1->TabIndex = 0;
			   // 
			   // pictureBox1
			   // 
			   this->pictureBox1->BackColor = System::Drawing::Color::Black;
			   this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			   this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->pictureBox1->Location = System::Drawing::Point(290, 7);
			   this->pictureBox1->Name = L"pictureBox1";
			   this->pictureBox1->Size = System::Drawing::Size(239, 222);
			   this->pictureBox1->TabIndex = 9;
			   this->pictureBox1->TabStop = false;
			   // 
			   // numHabitants
			   // 
			   this->numHabitants->Location = System::Drawing::Point(540, 427);
			   this->numHabitants->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			   this->numHabitants->Name = L"numHabitants";
			   this->numHabitants->Size = System::Drawing::Size(150, 22);
			   this->numHabitants->TabIndex = 8;
			   // 
			   // numAgent
			   // 
			   this->numAgent->Location = System::Drawing::Point(540, 321);
			   this->numAgent->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			   this->numAgent->Name = L"numAgent";
			   this->numAgent->Size = System::Drawing::Size(119, 22);
			   this->numAgent->TabIndex = 7;
			   // 
			   // numAlly
			   // 
			   this->numAlly->Location = System::Drawing::Point(158, 427);
			   this->numAlly->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			   this->numAlly->Name = L"numAlly";
			   this->numAlly->Size = System::Drawing::Size(109, 22);
			   this->numAlly->TabIndex = 6;
			   // 
			   // numTime
			   // 
			   this->numTime->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			   this->numTime->Location = System::Drawing::Point(160, 321);
			   this->numTime->Name = L"numTime";
			   this->numTime->Size = System::Drawing::Size(109, 22);
			   this->numTime->TabIndex = 5;
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->BackColor = System::Drawing::Color::Black;
			   this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label4->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			   this->label4->Location = System::Drawing::Point(534, 379);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(156, 36);
			   this->label4->TabIndex = 4;
			   this->label4->Text = L"Habitantes";
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(3)), static_cast<System::Int32>(static_cast<System::Byte>(1)),
				   static_cast<System::Int32>(static_cast<System::Byte>(26)));
			   this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label3->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			   this->label3->Location = System::Drawing::Point(534, 268);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(125, 36);
			   this->label3->TabIndex = 3;
			   this->label3->Text = L"Agentes";
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(2)), static_cast<System::Int32>(static_cast<System::Byte>(1)),
				   static_cast<System::Int32>(static_cast<System::Byte>(44)));
			   this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			   this->label2->Location = System::Drawing::Point(154, 379);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(115, 36);
			   this->label2->TabIndex = 2;
			   this->label2->Text = L"Aliados";
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->BackColor = System::Drawing::Color::Black;
			   this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label1->ForeColor = System::Drawing::Color::White;
			   this->label1->Location = System::Drawing::Point(154, 268);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(113, 36);
			   this->label1->TabIndex = 1;
			   this->label1->Text = L"Tiempo";
			   // 
			   // btnInstructions
			   // 
			   this->btnInstructions->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnInstructions.BackgroundImage")));
			   this->btnInstructions->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->btnInstructions->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btnInstructions->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			   this->btnInstructions->Location = System::Drawing::Point(451, 530);
			   this->btnInstructions->Name = L"btnInstructions";
			   this->btnInstructions->Size = System::Drawing::Size(236, 77);
			   this->btnInstructions->TabIndex = 1;
			   this->btnInstructions->Text = L"INSTRUCCIONES";
			   this->btnInstructions->UseVisualStyleBackColor = true;
			   // 
			   // btnPlay
			   // 
			   this->btnPlay->BackColor = System::Drawing::SystemColors::AppWorkspace;
			   this->btnPlay->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnPlay.BackgroundImage")));
			   this->btnPlay->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->btnPlay->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btnPlay->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			   this->btnPlay->Location = System::Drawing::Point(129, 530);
			   this->btnPlay->Name = L"btnPlay";
			   this->btnPlay->Size = System::Drawing::Size(236, 77);
			   this->btnPlay->TabIndex = 0;
			   this->btnPlay->Text = L"PLAY";
			   this->btnPlay->UseVisualStyleBackColor = false;
			   this->btnPlay->Click += gcnew System::EventHandler(this, &FrmMenu::btnPlay_Click);
			   // 
			   // timer1
			   // 
			   this->timer1->Enabled = true;
			   this->timer1->Tick += gcnew System::EventHandler(this, &FrmMenu::timer1_Tick);
			   // 
			   // FrmMenu
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(828, 663);
			   this->Controls->Add(this->panel1);
			   this->Name = L"FrmMenu";
			   this->Text = L"FrmMenu";
			   this->Load += gcnew System::EventHandler(this, &FrmMenu::FrmMenu_Load);
			   this->panel1->ResumeLayout(false);
			   this->panel1->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numHabitants))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numAgent))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numAlly))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numTime))->EndInit();
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		//Clear
		buffer->Graphics->Clear(Color::WhiteSmoke);
		//Draw
		buffer->Graphics->DrawImage(bmpBackground, 0, 0, panel1->Width, panel1->Height);
		//Render
		buffer->Render(g);
	}
	private: System::Void FrmMenu_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		spmusic->PlayLooping();
	}
private: System::Void btnPlay_Click(System::Object^ sender, System::EventArgs^ e) 
{
	spmusic->Stop();
	FrmPrincipal^ frm = gcnew FrmPrincipal(Convert::ToInt32(numTime->Value), Convert::ToInt32(numAgent->Value)
	, Convert::ToInt32(numAlly->Value), Convert::ToInt32(numHabitants->Value));
	this->Hide();
	frm->ShowDialog();
	this->Close();			
}
};
}
