#include<bits/stdc++.h>

char file_name[200];
int main(){
	float *a = new float[1000001]; 
	for (unsigned int i = 0; i < 10; i++) {
		memset(file_name, 0, sizeof(file_name));
		sprintf(file_name, "testcase%u.txt", i + 1);
		std::ifstream File(file_name);
		for (unsigned int i = 0; i < 1000000 && (!File.eof()); i++){
			File >> a[i];
		}
		File.close();	
		auto begin = std::chrono::high_resolution_clock::now(); 
		std::sort(a, a + 1000000);
		auto end = std::chrono::high_resolution_clock::now();
		auto duration =  std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
		std::cout << "Time to C++ built-in sort for " << file_name << " is " << duration.count() << " microseconds\n"; 
	}
	free(a)
	return 0;
}
