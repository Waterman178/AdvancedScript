#pragma once

#include "HelperFunctions.h"
#include "LogWindow.h"
#include "Parser.h"

ref class VarPara_temp
{
public:
	VarPara_temp(String^ vartype_, String^ varname_, String^ varvalue_, int i) {
		if (varvalue_ == nullptr) {
			varvalue_ = "NULL";
		}

		if (i !=-1){
		if (vartype_ == "array") {
			vartype = vartype_;
			varname = varname_;
			varvalue = varvalue_;
		}
		else {
			vartype = vartype_;
			varname = varname_;
			varvalue = varvalue_;
		}
		}
		else {
			vartype = "";
			varname = "";
			varvalue = "";
		}

		/*if ((vartype_ == "str") || (vartype_ == "int")) {
			vartype = vartype_;
			varname = varname_;
			varvalue = gcnew array<String^>(1);
			if (vartype_ == "str")
				varvalue[i] = varvalue_;
			if (vartype_ == "int" && varvalue_ == "") {
				varvalue[i] = "0";
			}
			else { varvalue[i] = varvalue_; }

		}
		if (vartype_ == "array") {
			vartype = vartype_;
			varname = varname_;
			varvalue = gcnew array<String^>(500);
			varvalue[0] = varvalue_;
		}
		if ((vartype_ != "str") && (vartype_ != "int") && (vartype_ != "array")) {
			vartype = "";
			varname = "";
			varvalue = gcnew array<String^>(1);
			varvalue[0] = varvalue_;
		}*/
	}

public:
	String^ vartype;
	String^ varname;
	String^ varvalue;
};


public ref class VarPara
{
public:
	VarPara(String^ vartype_, String^ varname_, String^ varvalue_, int arrayLength_) { 
		if ((vartype_ == "str") || (vartype_ == "int")) {
			vartype = vartype_;
			varname = varname_;
			varvalue = gcnew array<String^>(1);
			if (vartype_ == "str")
				varvalue[0] = varvalue_;
			if (vartype_ == "int" && varvalue_ == "") {
				varvalue[0] = "0";
			}
			else { varvalue[0] = varvalue_; }

		}
		if (vartype_ == "array") {
			vartype = vartype_;
			varname = varname_;
			//varvalue = gcnew array<String^>(0x500);
			arrayLength = arrayLength_;
			varvalue = gcnew array<String^>(arrayLength_);
			varvalue[0] = varvalue_;
		}
		if ((vartype_ != "str") && (vartype_ != "int") && (vartype_ != "array")) {
			vartype = "";
			varname = "";
			varvalue = gcnew array<String^>(1);
			varvalue[0] = varvalue_;
		}
	}
public :
	void ResizeArr(int i) {
		Array::Resize(varvalue, arrayLength + i);
		arrayLength = arrayLength + i;
	}

public:
	String^ vartype;
	String^ varname;
	array <String^>^ varvalue;
	int arrayLength;
};

public ref class ScriptFunList {
public:
	static Generic::List<VarPara^>^ VarList = gcnew Generic::List<VarPara^>;

};

public ref class LableLine
{
public:
	LableLine(int LableLineNumber_, String^ Lable_) {
		LableLineNumber = LableLineNumber_;
		Lable = Lable_;
	}

private:
public:
	int LableLineNumber;
	String^ Lable;

	
};

public ref class LableLineClass {
public:
	static Generic::List<LableLine^>^ LableLines = gcnew Generic::List<LableLine^>;
};


static LableLine^ GetLineByLable(String^ input) {
	for each (LableLine^ var in LableLineClass::LableLines)
	{
		if (var->Lable->Trim() == input->Trim()) {
			return var;
		}
	}
	return gcnew LableLine(0, "");
}


void VarListClear();
bool Varexist(String^ varname, String^% vartype_, int% index, int% arrayLength);
/////
bool Varx_(String^ vartype, String^ varname, String^ varvalue = "");
bool GetVarx_(String^ varname, int Arrayindex_=0);
bool SetVarx_(String^ varname, int index_, String^ value_);
String^ Movx_(String^ p1, String^ p2);
String^ addx_(String^ p1, String^ p2);
String^ subx_(String^ p1, String^ p2);
String^ mulx_(String^ p1, String^ p2);
String^ divx_(String^ p1, String^ p2);
String^ andx_(String^ p1, String^ p2);
String^ orx_(String^ p1, String^ p2);
String^ xorx_(String^ p1, String^ p2);
String^ shlx_(String^ p1, String^ p2);
String^ pushx_(String^ p1);
String^ popx_(String^ p1);
String^ cmpx_(String^ p1, String^ p2);

////
String^ findx_(String^ base_, String^ Searchvalue_, String^ Size_="");
String^ findallx_(String^ base_, String^ Searchvalue_, String^ Size_="");
String^ findallmemx_(String^ base_, String^ Searchvalue_, String^ Size_="");
bool dumpmem(String^ addr, String^ size, String^ para = "");
bool WriteStr_(duint address, String^ text, bool replace);
String^ condtion_(String^ input, String^ typo);
bool ResizeArray_(String^ varname, int AddSub);
bool GetArraySize_(String^ varArrName, String^ varname);
bool Write2File_(String^ filepath, bool append_, String^ data_);
bool ReadStr_(String^ varname, String^ value_);
bool InputBox_(String^ varname, int index_, String^ message_, String^ title);

bool ifCond(String^ input, String^% lineNumber,int currentLine);
bool gotox_(String^ input, String^% lineNumber);
bool GetdesCallJmp_(String^ varname, String^ command_, int Arrayindex_=0);
//String^ BPxx_(String^ addr, String^ BPname = "", String^ BPType = "");