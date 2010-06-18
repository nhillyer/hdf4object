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
	//float* array = (float*) test->setToArray1d(new string("Latitude"), sizeof(float));
	//int* dims = test->getSetDimensions(new string("Latitude"));
		
	float** array = (float**) test->setToArray2d(new string("Integrated_Attenuated_Backscatter_532"), sizeof(float));
	int* dims = test->getSetDimensions(new string("Integrated_Attenuated_Backscatter_532"));

	cout << "printing...." << endl;

	for (int i = 0; i < dims[0]; ++i)
	{
		for (int j = 0; j < dims[1]; ++j)
		{
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}
	
	delete test;

	return 0;
}

