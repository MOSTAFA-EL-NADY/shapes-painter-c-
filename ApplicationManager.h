#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include <fstream>
class Action;	//Forward Declaration


//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount, selectedFigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	//Pointers to Input and Output classes
	GUI* pGUI;
	CFigure* SelectedFig; //Pointer to the selected figure

public:	
	ApplicationManager(); 
	~ApplicationManager();

	void Run();		//to run the application
	
	// -- Action-Related Functions
	Action* CreateAction(ActionType);
	void ExecuteAction(Action*&) ; //Execute an action
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	CFigure* GetSelectedFigure() const;
	int* getSelectedFigCount();
		
	// -- Interface Management Functions	
	GUI *GetGUI() const; //Return pointer to the interface
	CFigure** getFigList();
	int getFigCount();
	int* getFigsCount();
	void UpdateInterface() const;	//Redraws all the drawing window	

	void fillSelectedFig(color c);
	void drwSelectedFig(color c);
	void SaveAll(ofstream& outputfile);
	void Save_load();
	void ClearFigList();
	void BringToFront(int selectedIndex);//bring to front function
	void SendToBack(int selectedIndex);//send to back function
	int getSelectedFigure(); //to get selected figure to resize
	CFigure* DrawnFigs(int i) const; // play mode
	
};

#endif