#include <QtWidgets>
#include <iostream>

#include "sampleEditor.h"
#include "dataStructure.h"

Editor::Editor(SampleData *sample, QWidget *){
	// Widgets for editing as well as their decorating labels
	// Created with default parameters based on video
	sampleNameLabel = new QLabel("Sample Name");
	sampleNameEdit = new QLineEdit("Water");
	
	sampleChemLabel = new QLabel("Sample Chemical");
	sampleChemEdit = new QLineEdit("H2O");
	
	sampleNoteLabel = new QLabel("Sample Notes");
	sampleNoteEdit = new QPlainTextEdit("<None>");
	
	// activeSample is a pointer to the current sample edited by the widget
	//	passed by the parent widgets
	// When the widget is created with a new sample it passes its default values in
	activeSample = sample;
	activeSample->name = sampleNameEdit->text();
	activeSample->chemical = sampleChemEdit->text();
	activeSample->notes = sampleNoteEdit->toPlainText();
	
	// Creating the layout (form)
	this->addRow(sampleNameLabel, sampleNameEdit);
	this->addRow(sampleChemLabel, sampleChemEdit);
	this->addRow(sampleNoteLabel, sampleNoteEdit);
	
	// Signals to update the sample when editing the fields
	//	as there is no 'save' button here!
	connect(sampleNameEdit, SIGNAL(textChanged(QString)), this, SLOT(updateName()));
	connect(sampleChemEdit, SIGNAL(textChanged(QString)), this, SLOT(updateChem()));
	connect(sampleNoteEdit, SIGNAL(textChanged()), this, SLOT(updateNote()));
}

Editor::~Editor() {
	// Widgets should be cleaned up automatically by parent
	// Active sample is stored in the collection and deleted there
}	


// A number of slots to update the current sample when something is typed
void Editor::updateName() {
	activeSample->name = sampleNameEdit->text();
	emit editorUpdated();
}
void Editor::updateChem() {
	activeSample->chemical = sampleChemEdit->text();
	emit editorUpdated();
}
void Editor::updateNote() {
	activeSample->notes = sampleNoteEdit->toPlainText();
	emit editorUpdated();
}


// Connects the active sample to an existing sample or changes the current sample being edited
//	This is primarily when used in the main window when items in the existing list are edited
void Editor::connectSample(SampleData *sample) {
	activeSample = sample;
	sampleNameEdit->setText(activeSample->name);
	sampleChemEdit->setText(activeSample->chemical);
	sampleNoteEdit->setPlainText(activeSample->notes);	
}


///////////////////////////////////////////////////////////////////////////////


Dialog::Dialog(SampleData *sample, QWidget *){
	
	// Right Edit Pane made from an editor (above)
	// 	Passes on itself as the parent as well as the sample from the main window
	editPaneLayout = new Editor(sample, this);
	
	// OS standard accept/cancel buttons bound to slots
	//	These are used to let the window know if the user pressed Ok or Cancel
	QDialogButtonBox *buttonBox = new QDialogButtonBox(
			QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
	connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
	connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
	
	// Assemble everything and display the entire widget
	mainLayout = new QVBoxLayout;
	mainLayout->addLayout(editPaneLayout);
	mainLayout->addWidget(buttonBox);
	setLayout(mainLayout);
}

Dialog::~Dialog() {
	// Widgets should be deleted automatically by parent when dialog is closed
}
