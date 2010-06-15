#ifndef HDF4OBJECT_H
#define HDF4OBJECT_H
/* hdf4object.h
 * HDF4Object Class
 * A more objective way to read data from HDF files.
 *
 * author: T. Nelson Hillyer
 * date: June 14, 2009
 * version: 1.0
 */
#include "mfhdf.h"
#include <string>
#include <iostream>
#include <fstream>

class hdf4object
{
	public:
		hdf4object(std::string* filename);
		~hdf4object();

		std::string* getDataSets();
		int getNumberOfSets();
		int getSetRank(std::string* setName);
		int* getSetDimensions(std::string* setName);
		void* setToArray(std::string* setName, int n_bytes);
		void freeArray(void* array, int n_bytes);
	
	private:
		int32 sd_id, sds_id;
		intn status;
		int32 n_datasets, n_file_attrs, index;
		int32 dim_sizes[H4_MAX_VAR_DIMS];
		int32 rank, data_type, n_attrs;

		char name[H4_MAX_NC_NAME];
		std::string* setNames;
		int* setRank;
		int** setDimensions;
};

#endif
