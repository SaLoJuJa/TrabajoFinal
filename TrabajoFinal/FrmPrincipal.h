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
		FrmPrincipal(int time, int nAgents, int nAllys, int nHabitants)
		{
			InitializeComponent();
			//Buffer
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);

			//Bitmaps
			bmpMap = gcnew Bitmap("worldOne.png");
			bmpLeader = gcnew Bitmap("leaderMale.png");
			bmpAlly = gcnew Bitmap("allyOne.png");
			bmpAgent = gcnew Bitmap("agent.png");

			//Controller
			controller = new Controller(bmpLeader, bmpAlly, bmpAgent, time,
				nAgents, nAllys, nHabitants);

			//Sound
			spSound = gcnew SoundPlayer("prophecy.wav");
		}

	private:
		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		//Bitmaps
		Bitmap^ bmpMap;
		Bitmap^ bmpLeader;
		Bitmap^ bmpAlly;
		Bitmap^ bmpAgent;
	
		//Controller
		Controller* controller;	  
	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lblTime;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ lblHp;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ lblPoints;

		//Music
		SoundPlayer^ spSound;

	protected:
		~FrmPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::ComponentModel::IContainer^ components;

	protected:

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmPrincipal::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblTime = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->lblHp = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lblPoints = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmPrincipal::timer1_Tick);
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(1, 33);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1446, 731);
			this->panel1->TabIndex = 0;
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 1000;
			this->timer2->Tick += gcnew System::EventHandler(this, &FrmPrincipal::timer2_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(74, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Time:";
			// 
			// lblTime
			// 
			this->lblTime->AutoSize = true;
			this->lblTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTime->Location = System::Drawing::Point(131, 9);
			this->lblTime->Name = L"lblTime";
			this->lblTime->Size = System::Drawing::Size(0, 20);
			this->lblTime->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(241, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(51, 20);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Vidas";
			// 
			// lblHp
			// 
			this->lblHp->AutoSize = true;
			this->lblHp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblHp->Location = System::Drawing::Point(298, 10);
			this->lblHp->Name = L"lblHp";
			this->lblHp->Size = System::Drawing::Size(0, 20);
			this->lblHp->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(417, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(66, 20);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Puntos:";
			// 
			// lblPoints
			// 
			this->lblPoints->AutoSize = true;
			this->lblPoints->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPoints->Location = System::Drawing::Point(489, 9);
			this->lblPoints->Name = L"lblPoints";
			this->lblPoints->Size = System::Drawing::Size(0, 20);
			this->lblPoints->TabIndex = 6;
			// 
			// FrmPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1453, 765);
			this->Controls->Add(this->lblPoints);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lblHp);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->lblTime);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"FrmPrincipal";
			this->Text = L"Buggisoft";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &FrmPrincipal::FrmPrincipal_FormClosing);
			this->Load += gcnew System::EventHandler(this, &FrmPrincipal::FrmPrincipal_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmPrincipal::FrmPrincipal_KeyDown);
			this->Resize += gcnew System::EventHandler(this, &FrmPrincipal::FrmPrincipal_Resize);
			this->ResumeLayout(false);
			this->PerformLayout();

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
		controller->drawEverything(buffer->Graphics, bmpLeader, bmpAlly,bmpAgent);
		lblTime->Text = "" + controller->getTime();
		//Render
		buffer->Render(g);
	}

	private: System::Void FrmPrincipal_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	{
		switch (e->KeyCode)
		{
		case Keys::A: case Keys::Left:
			controller->getLeader()->move(buffer->Graphics, 'A',controller->getObstacles()); break;
		case Keys::D: case Keys::Right:
			controller->getLeader()->move(buffer->Graphics, 'D',controller->getObstacles()); break;
		case Keys::W: case Keys::Up:						   
			controller->getLeader()->move(buffer->Graphics, 'W',controller->getObstacles()); break;
		case Keys::S: case Keys::Down:						   
			controller->getLeader()->move(buffer->Graphics, 'S',controller->getObstacles()); break;
		case Keys::Space:
			break;
		default:
			break;
		}
	}
	private: System::Void FrmPrincipal_Resize(System::Object^ sender, System::EventArgs^ e)
	{
	}
	private: System::Void FrmPrincipal_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
	{
	}
	private: System::Void FrmPrincipal_Load(System::Object^ sender, System::EventArgs^ e)	
	{
		spSound->PlayLooping();
	}
private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) 
{
	controller->decreaseTime();
}
};
}
