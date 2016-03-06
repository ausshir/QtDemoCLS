#include <QtWidgets>
#include <iostream>

#include "sampleEditor.h"
#include "dataStructure.h"

Editor::Editor(){
	sampleNameLabel = new QLabel("Sample Name");
	sampleNameEdit = new QLineEdit("Water");
	
	sampleChemLabel = new QLabel("Sample Chemical");
	sampleChemEdit = new QLineEdit("H2O");
	
	sampleNoteLabel = new QLabel("Sample Notes");
	sampleNoteEdit = new QPlainTextEdit("<None>");
	
	sample = new SampleData;
	sample->name = sampleNameEdit->text();
	sample->chemical = sampleChemEdit->text();
	sample->notes = sampleNoteEdit->toPlainText();
	
	this->addRow(sampleNameLabel, sampleNameEdit);
	this->addRow(sampleChemLabel, sampleChemEdit);
	this->addRow(sampleNoteLabel, sampleNoteEdit);
	
	// Update the struct when editing the fields
	connect(sampleNameEdit, SIGNAL(textChanged(QString)), this, SLOT(updateName()));
	connect(sampleChemEdit, SIGNAL(textChanged(QString)), this, SLOT(updateChem()));
	connect(sampleNoteEdit, SIGNAL(textChanged(QString)), this, SLOT(updateNote()));
}

void Editor::updateName() {
	sample->name = sampleNameEdit->text();
	
}

void Editor::updateChem() {
	sample->chemical = sampleChemEdit->text();
}

void Editor::updateNote() {
	sample->notes = sampleNoteEdit->toPlainText();

}

void Editor::refresh() {
	sampleNameEdit->setText(sample->name);
	sampleChemEdit->setText(sample->chemical);
	sampleNoteEdit->setPlainText(sample->notes);
	
}


Dialog::Dialog(QWidget* parent){
	
	
	// Right Edit Pane
	editPaneLayout = new Editor();
	
	// OS standard accept/cancel buttons bound to slots
	QDialogButtonBox *buttonBox = new QDialogButtonBox(
		QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
	connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
	connect(buttonBox, SIGNAL(accepted()), parent, SLOT(setData()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
	
	// Assemble everything and display the entire widget
	mainLayout = new QVBoxLayout;
	mainLayout->addLayout(editPaneLayout);
	mainLayout->addWidget(buttonBox);
	
	setLayout(mainLayout);
}

SampleData* Dialog::getData(){
	return editPaneLayout->sample;
}