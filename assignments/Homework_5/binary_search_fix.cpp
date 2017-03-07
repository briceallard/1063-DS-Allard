/**
* @FunctionName: BinarySearch
* @Description:
*     Implementation of a binary search on an array of values
* @Params:
*     int* data - data array
*     int  key  - key to search for
* @Returns:
*    int - positive value = index / negative value = not found
*/

int BinarySearch(int* data, int key, int size) {
	int left = 0;
	int right = size - 1;
	int middle = (left + right) / 2;

	bool found = false;


	while (!found) {
		if (data[middle] == key) {
			return middle;
		}
		else if (middle == left || middle == right) {
			cout << "Not Found!" << endl;
			found = false;
			return -1;    // This is the fix!!!!!!!!
		}
		else {
			if (key < data[middle]) {
				right = middle;
			}
			else {
				left = middle;
			}
			middle = (left + right) / 2;
		}

	}

	return -1;
}
