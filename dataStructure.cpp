#include "dataStructure.h"

SampleDataCollection::SampleDataCollection() {
	// Nothing to do here but exist!
}

SampleDataCollection::~SampleDataCollection() {
	// Cleans up all of the samples in the list
	// List itself is deleted automatically with the class
	for(int i = 0; i < list.size(); i++) {
		delete &list[i];
	}
}