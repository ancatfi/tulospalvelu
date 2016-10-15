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

#ifndef UnitMerkKoodejaH
#define UnitMerkKoodejaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormMerkKoodeja : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *SG1;
	TLabel *Label1;
	TRadioGroup *RGTark;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TCheckBox *CBJoukkEil;
	TCheckBox *CBLoppuEil;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall SG1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormMerkKoodeja(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMerkKoodeja *FormMerkKoodeja;
//---------------------------------------------------------------------------
#endif
