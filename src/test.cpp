#include <iostream>
#include "hdf4object.h"
using namespace std;

int main(int argc, char** argv)
{
	if (*(++argv) == NULL)
		return 1;
	hdf4object* test = new hdf4object(new string(*argv));

	float** array = test->setToArray<float>(new string("Total_Attenuated_Backscatter_532"));

	int* dims = test->getSetDimensions(new string("Total_Attenuated_Backscatter_532"));
	
	for (int i = 0; i < dims[0]; i++) {
		for (int j = 0; j < dims[1]; j++) {
			cout << array[i][j] << '\t';
		}
		cout << endl;
	}
	test->freeArray<float>(array);	
	delete test;

	return 0;
}

