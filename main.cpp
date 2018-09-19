#include <cstdlib>
#include <iostream>

using namespace std;

void print(int numbers[], int size);
void countingSort(int numbers[], int size);

int main(int argc, char *argv[]) {
    int numbers[] = {1, 4, 1, 2, 7, 5, 2};
    int size = sizeof(numbers) / sizeof(*numbers);

    print(numbers, size);
    countingSort(numbers, size);
    print(numbers, size);
    
    //system("read");
    return EXIT_SUCCESS;
}

void print(int numbers[], int size) {
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << ' ';
    }
    cout << endl;
}

void countingSort(int numbers[], int size) {
    int max = 0;
    for(int i = 0; i < size;i++)
    {
        if (numbers[i] > max)
        {
            max = numbers[i];
        }
    }

    int counter[max+1] = {0};
    {
        for(int i = 0; i < size;i++)
        {
            counter[numbers[i]] += 1;
        }
        for(int i = 0; i < max;i++)
        {
            counter[i+1] += counter[i];
        }
    }

    int temp[size] = {};
    for(int i = 0; i < size; i++)
    {
        if(counter[numbers[i]] == 0)
            continue;

        temp[counter[numbers[i]]-1] = numbers[i];
        counter[numbers[i]] -= 1;
    }
    for(int i = 0; i < size; i++)
    {
        cout << temp[i] << " ";
    }
    cout << endl;
}