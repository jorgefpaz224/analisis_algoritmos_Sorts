#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class Sorts {
private:
    void imprimirVector(const vector<int>& vec) {
        for (size_t i = 0; i < vec.size(); ++i)
            cout << vec[i] << " ";
        cout << endl;
    }

    void bubbleSort(vector<int>& vec) {
        clock_t inicio = clock();
        int n = vec.size();
        for (int i = 0; i < n - 1; ++i)
            for (int j = 0; j < n - i - 1; ++j)
                if (vec[j] > vec[j + 1])
                    swap(vec[j], vec[j + 1]);
        clock_t fin = clock();
        cout << "Resultado Bubble Sort:\n";
        //imprimirVector(vec);
        cout << "Tiempo de ejecucion: " << double(fin - inicio) / CLOCKS_PER_SEC << " segundos\n";
    }

    void insertSort(vector<int>& vec) {
        clock_t inicio = clock();
        int n = vec.size();
        for (int i = 1; i < n; ++i) {
            int key = vec[i];
            int j = i - 1;
            while (j >= 0 && vec[j] > key) {
                vec[j + 1] = vec[j];
                j--;
            }
            vec[j + 1] = key;
        }
        clock_t fin = clock();
        cout << "Resultado Insertion Sort:\n";
        //imprimirVector(vec);
        cout << "Tiempo de ejecucion: " << double(fin - inicio) / CLOCKS_PER_SEC << " segundos\n";
    }

    void selectionSort(vector<int>& vec) {
        clock_t inicio = clock();
        int n = vec.size();
        for (int i = 0; i < n - 1; ++i) {
            int minIndex = i;
            for (int j = i + 1; j < n; ++j)
                if (vec[j] < vec[minIndex])
                    minIndex = j;
            swap(vec[i], vec[minIndex]);
        }
        clock_t fin = clock();
        cout << "Resultado Selection Sort:\n";
        //imprimirVector(vec);
        cout << "Tiempo de ejecucion: " << double(fin - inicio) / CLOCKS_PER_SEC << " segundos\n";
    }

    void merge(vector<int>& vec, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        vector<int> L(n1), R(n2);

        for (int i = 0; i < n1; ++i)
            L[i] = vec[left + i];
        for (int j = 0; j < n2; ++j)
            R[j] = vec[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2)
            vec[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
        while (i < n1)
            vec[k++] = L[i++];
        while (j < n2)
            vec[k++] = R[j++];
    }

    void mergeSort(vector<int>& vec, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(vec, left, mid);
            mergeSort(vec, mid + 1, right);
            merge(vec, left, mid, right);
        }
    }

    int partition(vector<int>& vec, int low, int high) {
        int pivot = vec[high];
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            if (vec[j] < pivot) {
                i++;
                swap(vec[i], vec[j]);
            }
        }
        swap(vec[i + 1], vec[high]);
        return i + 1;
    }

    void quickSort(vector<int>& vec, int low, int high) {
        if (low < high) {
            int pi = partition(vec, low, high);
            quickSort(vec, low, pi - 1);
            quickSort(vec, pi + 1, high);
        }
    }

    void heapify(vector<int>& vec, int n, int i) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && vec[l] > vec[largest])
            largest = l;
        if (r < n && vec[r] > vec[largest])
            largest = r;
        if (largest != i) {
            swap(vec[i], vec[largest]);
            heapify(vec, n, largest);
        }
    }

    void heapSort(vector<int>& vec) {
        clock_t inicio = clock();
        int n = vec.size();
        for (int i = n / 2 - 1; i >= 0; --i)
            heapify(vec, n, i);
        for (int i = n - 1; i > 0; --i) {
            swap(vec[0], vec[i]);
            heapify(vec, i, 0);
        }
        clock_t fin = clock();
        cout << "Resultado Heap Sort:\n";
        //imprimirVector(vec);
        cout << "Tiempo de ejecucion: " << double(fin - inicio) / CLOCKS_PER_SEC << " segundos\n";
    }

public:
    void menu() {
        int opcion;
        //GENERA UN VECTOR CON N NUMERO DE POSICIONES
        int n = 10000; 
    	vector<int> vec;

    	srand(time(0));

    	for (int i = 0; i < n; ++i) {
        	vec.push_back(rand() % 1000 + 1);
    	}

        do {
            cout << "\n--- MENU DE ORDENAMIENTOS ---\n";
            cout << "1. Insertion Sort\n";
            cout << "2. Heap Sort\n";
            cout << "3. Quick Sort\n";
            cout << "4. Merge Sort\n";
            cout << "5. Selection Sort\n";
            cout << "6. Bubble Sort\n";
            cout << "0. Salir\n";
            cout << "Elige una opcion: ";
            cin >> opcion;

            vector<int> copia = vec;

            switch (opcion) {
                case 1:
                    insertSort(copia);
                    break;
                case 2:
                    heapSort(copia);
                    break;
                case 3: {
                    clock_t inicio = clock();
                    quickSort(copia, 0, copia.size() - 1);
                    clock_t fin = clock();
                    cout << "Resultado Quick Sort:\n";
                    //imprimirVector(copia);
                    cout << "Tiempo de ejecucion: " << double(fin - inicio) / CLOCKS_PER_SEC << " segundos\n";
                    break;
                }
                case 4: {
                    clock_t inicio = clock();
                    mergeSort(copia, 0, copia.size() - 1);
                    clock_t fin = clock();
                    cout << "Resultado Merge Sort:\n";
                    //imprimirVector(copia);
                    cout << "Tiempo de ejecucion: " << double(fin - inicio) / CLOCKS_PER_SEC << " segundos\n";
                    break;
                }
                case 5:
                    selectionSort(copia);
                    break;
                case 6:
                    bubbleSort(copia);
                    break;
                case 0:
                    cout << "Saliendo del programa...\n";
                    break;
                default:
                    cout << "Opcion invalida.\n";
            }
        } while (opcion != 0);
    }
};

int main() {
    Sorts s;
    s.menu();
    return 0;
}
