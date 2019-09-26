#pragma once
#include "Juego.h"


namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();

			objjuego = new Juego();
			bmpasteroide_01 = gcnew  System::Drawing::Bitmap("../Imagenes/asteroid_01.png");
			bmpasteroide_02 = gcnew  System::Drawing::Bitmap("../Imagenes/asteroid_02.png");
			bmpnave = gcnew System::Drawing::Bitmap("../Imagenes/nave.png");
			bmpmapa = gcnew System::Drawing::Bitmap("../Imagenes/fa.png");
			bmpportada = gcnew System::Drawing::Bitmap("../Imagenes/portada.png");
			//
			segundos;
		}
	protected:
		~MyForm()
		{	if (components)
			{
				delete components;
			}
			delete bmpasteroide_01;
			delete bmpnave;
			delete bmpportada;
			delete bmpmapa;
		}
	private:
		Juego *objjuego;
		System::Drawing::Bitmap ^bmpasteroide_01;
		System::Drawing::Bitmap ^bmpasteroide_02;
		System::Drawing::Bitmap ^bmpnave;
		System::Drawing::Bitmap ^bmpportada;
		System::Drawing::Bitmap ^bmpmapa;
		//creamos una variable del tipo time
		int segundos;
	


	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;




	private: System::ComponentModel::IContainer^  components;



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(436, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(52, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"PUNTOS";
			this->label1->Visible = false;
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(488, 22);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->Visible = false;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Enabled = false;
			this->textBox2->Location = System::Drawing::Point(488, 57);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 2;
			this->textBox2->Visible = false;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::TextBox2_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(439, 57);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(39, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"VIDAS";
			this->label2->UseWaitCursor = true;
			this->label2->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(600, 600);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L".";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::MyForm_KeyPress);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		//if (e->KeyChar == (char)Keys::X) ahora se crean automaticamente
			//objjuego->Insertar_Figura();
		if (e->KeyChar == (char)Keys::Space)
			objjuego->Disparar(nullptr); //NULLPTR
		if (e->KeyChar == (char)Keys::Enter)	
		{
			objjuego->set_y(1);
			segundos = -15;
		}
		if (e->KeyChar == (char)Keys::Escape)
		{
			exit(1);
		}
	}

			 
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

		Graphics ^g = CreateGraphics();
		BufferedGraphicsContext ^bfc = BufferedGraphicsManager::Current;
		BufferedGraphics ^bf = bfc->Allocate(g, this->ClientRectangle);
		bf->Graphics->FillRectangle(gcnew System::Drawing::SolidBrush(Color::Transparent), g->ClipBounds);
		objjuego->Mostrar_Portada(bf->Graphics, bmpportada);
		textBox1->Text = objjuego->get_puntuacion().ToString();
		textBox2->Text = objjuego->get_vidas().ToString();
		if (segundos < 20)
		{
			if (segundos % 3 == 0)
			{
				objjuego->set_x(1);
			}
			else
			{
				objjuego->set_x(0);
			}
		}
		else
		{
			bf->Graphics->FillRectangle(gcnew System::Drawing::SolidBrush(Color::Transparent), g->ClipBounds);			
			objjuego->Mover_Figuras(bf->Graphics);
			objjuego->Mostrar_Mapa(bf->Graphics, bmpmapa);
			objjuego->Mostrar_Figuras(bf->Graphics, bmpasteroide_01, bmpasteroide_02);
			objjuego->Mostrar_Nave(bf->Graphics, bmpnave);
			objjuego->Mover_Balas(bf->Graphics);
			objjuego->Colision_Bala_Figura();
			objjuego->eliminar_Asteroides();
			objjuego->set_puntuacion(objjuego->get_puntuacion() + 1);
			label1->Visible = true;
			label2->Visible = true;
			textBox1->Visible = true;
			textBox2->Visible = true;
			if (segundos % 20 == 0)
			{
				objjuego->Insertar_Figura(1);
				objjuego->Insertar_Figura(2);
			}
			if (objjuego->Colision_Nave_Figura())
			{
				objjuego->set_vidas(0);
				objjuego->Volver_Inicio();
			}
			if (objjuego->get_vidas() == 0)
			{

				

				//objjuego->Guardar_Partida();
				timer1->Enabled = false;
				MessageBox::Show("PERDISTE :C");
			
				
			
			}
				
		}
		segundos++;

		bf->Render(g);
		delete g;
		delete bf;
		delete bfc;

	}

	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Left)
			objjuego->Mover_Nave(CreateGraphics(), direccion::izquierda);
		if (e->KeyCode == Keys::Right)
			objjuego->Mover_Nave(CreateGraphics(), direccion::derecha);
		if (e->KeyCode == Keys::Up)
			objjuego->Mover_Nave(CreateGraphics(), direccion::arriba);
		if (e->KeyCode == Keys::Down)
			objjuego->Mover_Nave(CreateGraphics(), direccion::abajo);
		if (e->KeyCode == Keys::G)
			objjuego->Guardar_Partida();
		if (e->KeyCode == Keys::C)
			objjuego->Cargar_Partida();	

	}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		
	}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void TextBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
};
}
