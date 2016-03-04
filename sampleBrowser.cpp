#include <QtWidgets>

#include "sampleBrowser.h"

Window::Window()
{
    
	// Right Edit Pane
	QLabel *sampleNameLabel = new QLabel("Sample Name");
	QLineEdit *sampleNameEdit = new QLineEdit();
	
	QLabel *sampleChemLabel = new QLabel("Sample Chemical");
	QLineEdit *sampleChemEdit = new QLineEdit();
	
	QLabel *sampleNoteLabel = new QLabel("Sample Notes");
	QPlainTextEdit *sampleNoteEdit = new QPlainTextEdit();
	
	
	QFormLayout *editPaneLayout = new QFormLayout();
	editPaneLayout->addRow(sampleNameLabel, sampleNameEdit);
	editPaneLayout->addRow(sampleChemLabel, sampleChemEdit);
	editPaneLayout->addRow(sampleNoteLabel, sampleNoteEdit);
	
	// Left Selection Pane
	QListWidget *sampleSelectList = new QListWidget();
	QPushButton *sampleCreateButton = new QPushButton("New Sample");
	QVBoxLayout *selectPaneLayout = new QVBoxLayout();
	selectPaneLayout->addWidget(sampleSelectList);
	selectPaneLayout->addWidget(sampleCreateButton);
	
	// Assemble the main layout
	QHBoxLayout *mainLayout = new QHBoxLayout();
	mainLayout->addLayout(selectPaneLayout);
	mainLayout->addLayout(editPaneLayout);
	
	setLayout(mainLayout);

}
