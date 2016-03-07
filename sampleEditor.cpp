#include <QtWidgets>
#include <iostream>

#include "sampleEditor.h"
#include "dataStructure.h"

Editor::Editor(SampleData *sample, QWidget *){
	sampleNameLabel = new QLabel("Sample Name");
	sampleNameEdit = new QLineEdit("Water");
	
	sampleChemLabel = new QLabel("Sample Chemical");
	sampleChemEdit = new QLineEdit("H2O");
	
	sampleNoteLabel = new QLabel("Sample Notes");
	sampleNoteEdit = new QPlainTextEdit("<None>");
	
	activeSample = sample;
	activeSample->name = sampleNameEdit->text();
	activeSample->chemical = sampleChemEdit->text();
	activeSample->notes = sampleNoteEdit->toPlainText();
	
	this->addRow(sampleNameLabel, sampleNameEdit);
	this->addRow(sampleChemLabel, sampleChemEdit);
	this->addRow(sampleNoteLabel, sampleNoteEdit);
	
	// Update the struct when editing the fields
	connect(sampleNameEdit, SIGNAL(textChanged(QString)), this, SLOT(updateName()));
	connect(sampleChemEdit, SIGNAL(textChanged(QString)), this, SLOT(updateChem()));
	connect(sampleNoteEdit, SIGNAL(textChanged()), this, SLOT(updateNote()));
}

Editor::~Editor() {
	// Widgets should be cleaned up automatically by parent
	// Active sample is stored in the collection and deleted there
}	

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

void Editor::connectSample(SampleData *sample) {
	activeSample = sample;
	sampleNameEdit->setText(activeSample->name);
	sampleChemEdit->setText(activeSample->chemical);
	sampleNoteEdit->setPlainText(activeSample->notes);
	
}


Dialog::Dialog(SampleData *sample, QWidget *){
	
	// Right Edit Pane
	editPaneLayout = new Editor(sample, this);
	
	// OS standard accept/cancel buttons bound to slots
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
	// Widgets should be deleted automatically by parent
}
