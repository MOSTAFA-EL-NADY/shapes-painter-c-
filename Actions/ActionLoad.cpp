#include "ActionLoad.h"
#include <iostream>
#include <fstream>
#include <string>
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\\Output.h"
#include "../Actions/ActionSave.h"
#include "../Figures//CSquare.h"
#include "..\Figures\CHex.h"
#include "../Figures/CEllipse.h"
#include <iostream>

ActionLoad::ActionLoad(ApplicationManager* pMan) :Action(pMan) //chain 
{
	FileName = "";
}

void ActionLoad::ReadFileName()
{
	GUI* pGui = pManager->GetGUI();
		pGui->PrintMessage("Please write the file you want to load:");
		FileName = pGui->GetSrting(); //get the written string from the user
}

void ActionLoad::Execute()
{
	
	GUI* pGui = pManager->GetGUI();
	

	// check if there is figure to save or the board is clean
	if (pManager->getFigCount() != 0)
	{
		pManager->Save_load();
	}
	

	
	

	CFigure* fig;
	int figCount = 0;
	ifstream loadedfile;
	string Drwcolor, bgroundcolor, fillcolor, shapename;
	CFigure* figure;


	ReadFileName();
	if (FileName == "")
		pGui->PrintMessage("not valid name");
	else
	{
		
		loadedfile.open("SavedFigures\\" + FileName+".txt");

		if (loadedfile.fail())
		{
			pGui->PrintMessage("invalid file name");
			
		}
		else
		{
			// loading the file content if filename is valid 
			loadedfile >> Drwcolor >> fillcolor>> bgroundcolor  ;
			UI.DrawColor =StringToColor( Drwcolor);
			UI.FillColor = StringToColor(fillcolor);
			UI.BkGrndColor= StringToColor(bgroundcolor);

			// delete figcolors from apmanager
			pManager->ClearFigList();
			loadedfile >> figCount;
			while (figCount)
			{
				
				loadedfile >> shapename;
					if (shapename == "SQUARE") {
						figure = new CSquare;
					}
					else if (shapename == "HEX") {
						//figure = new CHex();
					}
					else if (shapename == "ELLIPSE") {
						//figure = new CEllipse();
					}

					figure->Load(loadedfile);
					pManager->AddFigure(figure);
					figCount--;
				
			}
			pManager->UpdateInterface();
			pGui->ClearStatusBar();
			pGui->PrintMessage("shapes loaded sucsusful");


		}



	}
	


}

color ActionLoad::StringToColor(string s)const {
	if (s == "BLACK")
		return BLACK;
	if (s == "BLUE")
		return BLUE;
	if (s == "WHITE")
		return WHITE;
	if (s == "RED")
		return RED;
	if (s == "YELLOW")
		return YELLOW;
	if (s == "GREEN")
		return GREEN;
	if (s == "LIGHTGOLDENRODYELLOW")
		return LIGHTGOLDENRODYELLOW;
	if (s == "MAGENTA")
		return MAGENTA;
	if (s == "TURQUOISE")
		return TURQUOISE;
	if (s == "SKYBLUE")
		return SKYBLUE;
	if (s == "LIGHTSTEELBLUE")
		return LIGHTSTEELBLUE;
	if (s == "IVORY")
		return IVORY;
	if (s == "HONEYDEW")
		return HONEYDEW;
	return BLACK;
}
