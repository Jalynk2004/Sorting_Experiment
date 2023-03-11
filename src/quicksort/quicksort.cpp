#include <bits/stdc++.h>
using namespace std;

void quickSort(float a[], int l, int r){
	float p = a[(l+r)/2];
	int i = l, j = r;
	while (i < j){
		while (a[i] < p){
			i++;
		}
		while (a[j] > p){
			j--;
		}
		if (i <= j){
			float temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	if (i < r){
		quickSort(a, i, r);
	}
	if (l < j){
		quickSort(a, l, j);
	}
}
char file_name[200];
int main (){
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
                quickSort(a, 0, 1000000 - 1);
                auto end = std::chrono::high_resolution_clock::now();
                auto duration =  std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
                cout << "Time to quick sort for " << file_name << " is " << duration.count() << " microseconds\n";
        }
        return 0;

}
