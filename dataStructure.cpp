#include "dataStructure.h"

SampleDataCollection::SampleDataCollection() {
	
}

SampleDataCollection::~SampleDataCollection() {
	
	// Cleans up all of the samples
	// List itself is deleted automatically
	for(int i = 0; i < list.size(); i++) {
		delete &list[i];
	}
}