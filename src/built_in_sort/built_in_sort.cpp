#include<bits/stdc++.h>
using namespace std;

char file_name[200];
int main(){
	auto *a = new float[1000001]; 
	for (unsigned int i = 0; i < 10; i++) {
		memset(file_name, 0, sizeof(file_name));
		sprintf(file_name, "testcase%u.txt", i + 1);
		ifstream File(file_name);
		for (unsigned int i = 0; i < 1000000 && (!File.eof()); i++){
			File >> a[i];
		}
		File.close();	
		auto begin = std::chrono::high_resolution_clock::now(); 
		std::sort(a, a + 1000000);
		auto end = std::chrono::high_resolution_clock::now();
		auto duration =  std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
		cout << "Time to C++ built-in sort for " << file_name << " is " << duration.count() << " microseconds\n"; 
	}
	return 0;
}
