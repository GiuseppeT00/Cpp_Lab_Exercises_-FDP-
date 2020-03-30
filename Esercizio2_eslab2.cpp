#include "Template.h"
#include "D:\Progetti_C++\Template_miei\Templates.h"

int main() {
	int array_i[N] = { 2,10,2,7,4,45,9,15,0,4 };
	double array_d[N] = { 19.4,6.7,3.3,16.2,3.3,76.2,0.2,43.7,0.2,43.7 };
	string array_s[6] = { "pippo", "topolino", "minni", "paperino", "pippo", "pippo" };

	print_array(array_i, N);
	print_array(array_d, N);
	print_array(array_s, 6);

	cout << "Max integer element: " << most_common(array_i, N) << endl;
	cout << "Max double element: " << most_common(array_d, N) << endl;
	cout << "Max string element: " << most_common(array_s, 6) << endl;
	
	return 0;
}