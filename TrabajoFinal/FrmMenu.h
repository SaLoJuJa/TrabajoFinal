#pragma once

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
			this->btnInstructions = (gcnew System::Windows::Forms::Button());
			this->btnPlay = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->btnInstructions);
			this->panel1->Controls->Add(this->btnPlay);
			this->panel1->Location = System::Drawing::Point(6, 5);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(820, 656);
			this->panel1->TabIndex = 0;
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
};
}
