// Pekka Pirila's sports timekeeping program (Finnish: tulospalveluohjelma)
// Copyright (C) 2015 Pekka Pirila 

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

//---------------------------------------------------------------------------

#ifndef UnitVaiheMaarH
#define UnitVaiheMaarH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TFormVaiheMaar : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *SG1;
	TButton *Button1;
	TButton *Button2;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall SG1SelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall SG1Exit(TObject *Sender);

private:	// User declarations
	int aktCol;
	int aktRow;
	void Paivita(void);
	void PaivitaCell(int row, int col);
public:		// User declarations
	__fastcall TFormVaiheMaar(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormVaiheMaar *FormVaiheMaar;
//---------------------------------------------------------------------------
#endif
