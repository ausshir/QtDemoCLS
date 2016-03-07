#include <QtWidgets>

#include "sampleBrowser.h"
#include "sampleEditor.h"
#include "dataStructure.h"

Window::Window() {	
	// Right Editor Pane
	
	SampleData sample;
	editPaneLayout = new Editor(&sample, this);
	
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

Window::~Window() {
	delete collection;
	// Remaining widgets should be deleted automatically
	
}

void Window::newSample() {
	// Show the Dialog and get return state (accept/cancel)
	SampleData *sample = new SampleData;
	dialog = new Dialog(sample, this);
	dialog->setAttribute(Qt::WA_DeleteOnClose);
	
	if(dialog->exec() == QDialog::Accepted) {
		collection->list.insert(0, *sample);
		updateSelectionPane();
	}
	else delete sample;
	
}

void Window::updateSelectionPane() {
	sampleSelectList->addItem(collection->list[0].name + " " + collection->list[0].chemical);
}

void Window::editSample() {
	int index = sampleSelectList->count() - sampleSelectList->currentRow() - 1;
	editPaneLayout->connectSample(&(collection->list[index])); 
	
	connect(editPaneLayout, SIGNAL(editorUpdated()), this, SLOT(showUpdate()));
}

void Window::showUpdate() {

	int row = sampleSelectList->currentRow();
	int index = sampleSelectList->count() - row - 1;
	
	// I feel like there should be a built-in method for this.. couldn't find it in the docs
	sampleSelectList->takeItem(row);
	sampleSelectList->insertItem(row, collection->list[index].name + " " + collection->list[index].chemical);
	sampleSelectList->setCurrentRow(row);

}

