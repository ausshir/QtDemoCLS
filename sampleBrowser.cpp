#include <QtWidgets>

#include "sampleBrowser.h"
#include "sampleEditor.h"
#include "dataStructure.h"

Window::Window() {	
	// Right Editor Pane
	editPaneLayout = new Editor();
	
	// Left Selection Pane
	sampleSelectList = new QListWidget();
	sampleCreateButton = new QPushButton("New Sample");
	selectPaneLayout = new QVBoxLayout();
	selectPaneLayout->addWidget(sampleSelectList);
	selectPaneLayout->addWidget(sampleCreateButton);
	connect(sampleCreateButton, SIGNAL(clicked()), this, SLOT(newSample()));
	connect(sampleSelectList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(editSample()));
	
	// Assemble the main layout
	mainLayout = new QHBoxLayout();
	mainLayout->addLayout(selectPaneLayout);
	mainLayout->addLayout(editPaneLayout);
	
	setLayout(mainLayout);
	
	// Create the data collection
	collection = new SampleDataCollection();
}

void Window::newSample() {
	// Show the Dialog and get return state (accept/cancel)
	dialog = new Dialog(this);
	
	if(dialog->exec() == QDialog::Accepted) {
		SampleData *data = dialog->getData();
		collection->list.insert(0, *data);
		updateSelectionPane();
	}
	
}

void Window::updateSelectionPane() {
	sampleSelectList->addItem(collection->list[0].name + " " + collection->list[0].chemical);
}

void Window::editSample() {
	int index = sampleSelectList->count() - sampleSelectList->currentRow() - 1;
	editPaneLayout->sample = &(collection->list[index]);
	editPaneLayout->refresh();
	
	connect(editPaneLayout->sampleNameEdit, SIGNAL(textChanged(QString)), this, SLOT(showUpdate()));
	connect(editPaneLayout->sampleChemEdit, SIGNAL(textChanged(QString)), this, SLOT(showUpdate()));
	connect(editPaneLayout->sampleNoteEdit, SIGNAL(textChanged(QString)), this, SLOT(showUpdate()));
}

void Window::showUpdate() {
	//QMessageBox msgBox;
	//msgBox.setText(sampleNameEdit->text());
	//msgBox.show();
	
	int row = sampleSelectList->currentRow();
	int index = sampleSelectList->count() - row - 1;
	replaceRow(row, index);

}

// Note, this doesn't seem quite right but I didn't see anything in docs to do what I wanted...
void Window::replaceRow(int row, int index) {
	sampleSelectList->takeItem(row);
	sampleSelectList->insertItem(row, collection->list[index].name + " " + collection->list[index].chemical);
	sampleSelectList->setCurrentRow(row);
}
