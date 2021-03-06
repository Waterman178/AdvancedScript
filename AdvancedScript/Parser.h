#pragma once
#include "HelperFunctions.h"

int GetRegisterIndex(String^ input_);
String^ readVarName(String^ input, int arrayIndex, String^% VarString2Replace);
String^ tokens(String^ input, String^% VarString);
String^ BackWard(String^ input, int tokenindex, String^% VarString);
String^ ForWard(String^ input, int tokenindex, String^% VarString);
String^ findScriptSystemVarValue(String^ input);
String^ findVarValue(String^ input, VarType retAsVartype, String^% VarString);
bool CheckexcutedCmd(String^ cmd_);
String^ findHexValue(String^ input, String^% oldvalue_);
String^ resolveString(String^ input, int% commaCount);
String^ argumentValue(String^ argument, String^% OldValue_);
String^ GetArgValueByType(String^ argument, VarType type_, bool Add0x=false);

String^ replace_ads(String^ input_);
//String^ Get_adsValue(String^ input, int% EndB);
String^ StrAnalyze(String^ input, VarType type_,bool Add0x=false);
String^ returnSpaces(int SpaceNum);
String^ replaceValueBetweenBrackets(String^ input_);

//enum ads_Enum
//{
//	exebase,
//	modulebase,
//	SectionSize,
//	exefolderpath,
//	exename,
//	SectionBegin,
//	SectionEnd,
//};

//script test 

//Logx memdump(76FA0000, 50)

//varx int, x, 0x45fa
//varx str, z, 0xaa
//setx x, $z + 0x33 - 25
//varx array, y, 0x10
//setx x, $x + $y[0]


//varx str, search, "4533C94533C033"
//varx str, base, { rdx }
//findallmemx $base, $search
//mov rdi, ref.addr(0)
//
//findallmem 0x10000, "4533C94533C033"
//mov rdi, ref.addr(0)


//varx int, x, 90
//varx int, x1, 5
//getvarx x
//getvarx x1
//varx array, y, 1
//setvarx y, 110, 100
//getvarx y, 10 + $x + $x1 + 5




//varx int, x, 3
//varx int, x1, 5
//getvarx x
//getvarx x1
//varx array, y, 1
//setvarx y, 3, 9
//setvarx y, 10, 100
//getvarx y, $x * 1
//getvarx y, 1 + $x + $x1 + 1





//varx int, x, 3
//getvarx x
//varx array, y, 1
//setvarx y, 3, 5
//getvarx y, $x * 1