#include <iostream>
#include "hdf4object.h"
using namespace std;

int main(int argc, char** argv)
{
	if (*(++argv) == NULL)
	{
		cerr << "ERROR!" << std::endl;
		return 1;
	}
	hdf4object* test = new hdf4object(new string(*argv));
	cerr << "FILE CREATED" << endl;
	cerr << sizeof(float ) << endl;
	float* array = (float*) test->setToArray(new string("Total_Attenuated_Backscatter_532"), sizeof(float));
	cerr << "ARRAY CREATED" << endl;

	int* dims = test->getSetDimensions(new string("Total_Attenuated_Backscatter_532"));
	cerr << "DIMS CREATED" << endl;
	cerr << array << endl;	
	for (int i = 0; i < dims[0]; i++) {
		for (int j = 0; j < dims[1]; j++) {
			cout << array[i * dims[1] + j] << '\t';
		}
		cout << endl;
	}
	//test->freeArray(array, sizeof(float));	
	delete test;

	return 0;
}

