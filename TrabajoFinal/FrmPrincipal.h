#pragma once
#include "Controller.h"

namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	public ref class FrmPrincipal : public System::Windows::Forms::Form
	{
	public:
		FrmPrincipal(void)
		{
			InitializeComponent();
			//Buffer
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);

			//Bitmaps
			bmpMap = gcnew Bitmap("worldOne.jpg");
			bmpLeader = gcnew Bitmap("leaderMale.png");
			bmpAgent = gcnew Bitmap("agent.png");

			//Controller
			controller = new Controller(bmpLeader, bmpAgent);
		}

	private:
		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		//Bitmaps
		Bitmap^ bmpMap;
		Bitmap^ bmpLeader;
		Bitmap^ bmpAgent;
	private: System::Windows::Forms::Panel^ panel1;

		//Controller
		Controller* controller;

	protected:
		~FrmPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;
#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmPrincipal::timer1_Tick);
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(1, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(765, 598);
			this->panel1->TabIndex = 0;
			// 
			// FrmPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(767, 603);
			this->Controls->Add(this->panel1);
			this->Name = L"FrmPrincipal";
			this->Text = L"FrmPrincipal";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmPrincipal::FrmPrincipal_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		//Clear
		buffer->Graphics->Clear(Color::WhiteSmoke);
		//Move
		controller->moveEverything(buffer->Graphics);
		//Draw
		buffer->Graphics->DrawImage(bmpMap, 0, 0, panel1->Width, panel1->Height);
		controller->drawEverything(buffer->Graphics, bmpLeader, bmpAgent);
		//Render
		buffer->Render(g);
	}
	private: System::Void FrmPrincipal_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	{
		switch (e->KeyCode)
		{
		case Keys::A: case Keys::Left:
			controller->getLeader()->move(buffer->Graphics, 'A'); break;
		case Keys::D: case Keys::Right:
			controller->getLeader()->move(buffer->Graphics, 'D'); break;
		case Keys::W: case Keys::Up:
			controller->getLeader()->move(buffer->Graphics, 'W'); break;
		case Keys::S: case Keys::Down:
			controller->getLeader()->move(buffer->Graphics, 'S'); break;
		}
	}
	};
}
