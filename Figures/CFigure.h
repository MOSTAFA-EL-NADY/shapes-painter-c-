#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\GUI.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	static int Fid;
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	bool PlayHidden;

	
	/// Add more parameters if needed.
	color Drwcolor, Fillcolor;
	bool Isfill;
public:
	CFigure(GfxInfo FigureGfxInfo);
	CFigure();
	void SetSelected(bool );	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	virtual bool Get(int x, int y) const = 0;	//Check if the point inside The Figure
	virtual void DrawMe(GUI*) const  = 0 ;		//Draw the figure
	void Hide();
	void Show();
	bool HiddenStatus() const;
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	void ChngSelectClr(color Dclr);	//changes the figure's selection color
	color ChngSelectClr();	//changes the figure's selection color
	color virtual GetCurrentDrawClr();	//Get the current figure's fill color
	void setGFX();
	string ColorToString(color c)const;
	color StringToColor(string s);
	virtual string ShowFigureDetails() const = 0;	//show figure details

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	//virtual void Rotate() = 0;	//Rotate the figure
	//virtual void Resize() = 0;	//Resize the figure
	virtual void Resize(float) = 0;
	//virtual void Move() = 0;		//Move the figure

	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif