#include<bits/stdc++.h>

void merge(float arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    float L[n1], R[n2];
    for (i = 0; i < n1; i++){
    	L[i] = arr[l + i];
	}  
    for (j = 0; j < n2; j++){
    	R[j] = arr[m + 1+ j];
	}
    i = 0;
    j = 0; 
    k = l; 
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(float a[], int l, int r){
    if (l < r){
        int m = l+(r-l)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }
}
char file_name[200];
int main(){
	float *a = new float[1000001]; 
	for (unsigned int i = 0; i < 10; i++) {
		sprintf(file_name, "testcase%u.txt", i + 1);
		ifstream File(file_name);
		for (unsigned int i = 0; i < 1000000 && (!File.eof()); i++){
			File >> a[i];
		}
		File.close();	
		auto begin = std::chrono::high_resolution_clock::now(); 
		mergeSort(a, 0, 1000000 - 1);
		auto end = std::chrono::high_resolution_clock::now();
		auto duration =  std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
		cout << "Time to merge sort for " << file_name << " is " << duration.count() << " microseconds\n"; 
	}
	free(a)
	return 0;
}
