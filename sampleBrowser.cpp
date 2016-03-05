#include <QtWidgets>

#include "sampleBrowser.h"
#include "sampleEditor.h"

Window::Window()
{	
	// Right Editor Pane
	editPaneLayout = new Editor();
	
	// Left Selection Pane
	sampleSelectList = new QListWidget();
	sampleCreateButton = new QPushButton("New Sample");
	selectPaneLayout = new QVBoxLayout();
	selectPaneLayout->addWidget(sampleSelectList);
	selectPaneLayout->addWidget(sampleCreateButton);
	
	// Assemble the main layout
	mainLayout = new QHBoxLayout();
	mainLayout->addLayout(selectPaneLayout);
	mainLayout->addLayout(editPaneLayout);
	
	// Show the Dialog
	dialog = new Dialog(this);
	dialog->show();
	
	setLayout(mainLayout);

}