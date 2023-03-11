  #include <bits/stdc++.h>
  using namespace std;
  
  void heapify(float arr[], int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(arr[i], arr[largest]);
      heapify(arr, n, largest);
    }
  }
  
  // main function to do heap sort
  void heapSort(float arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
      swap(arr[0], arr[i]);
  
      // Heapify root element to get highest element at root again
      heapify(arr, i, 0);
    }
}
char file_name[200];
int main () {
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
                heapSort(a, 1000000);
                auto end = std::chrono::high_resolution_clock::now();
                auto duration =  std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
                cout << "Time to heap sort for " << file_name << " is " << duration.count() << " microseconds\n";
        }
        return 0;

}
