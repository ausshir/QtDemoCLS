#include <QtWidgets>

#include "sampleEditor.h"

Editor::Editor(){
	QLabel *sampleNameLabel = new QLabel("Sample Name");
	QLineEdit *sampleNameEdit = new QLineEdit();
	
	QLabel *sampleChemLabel = new QLabel("Sample Chemical");
	QLineEdit *sampleChemEdit = new QLineEdit();
	
	QLabel *sampleNoteLabel = new QLabel("Sample Notes");
	QPlainTextEdit *sampleNoteEdit = new QPlainTextEdit();
	
	this->addRow(sampleNameLabel, sampleNameEdit);
	this->addRow(sampleChemLabel, sampleChemEdit);
	this->addRow(sampleNoteLabel, sampleNoteEdit);
}

Dialog::Dialog(QWidget* parent){
	
	
	// Right Edit Pane
	editPaneLayout = new Editor();
	
	QDialogButtonBox *buttonBox = new QDialogButtonBox(
		QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
	//connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    //connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
	
	mainLayout = new QVBoxLayout;
	mainLayout->addLayout(editPaneLayout);
	mainLayout->addWidget(buttonBox);
	
	setLayout(mainLayout);
}