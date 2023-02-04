#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int *find_min(int *array, int size)
{
    int *min = array;
    for (int i = 0; i < size; i++)
    {
        if (*min > array[i])
            min = &array[i];
    }
    return min;
}
void S_sort(int array[],int size)
{
    for (int i=0;i<5;i++)
    {
        int a=*find_min(array,size);
        swap(a,array[i]);
        size--;
    }

}

int main()

{
    int array[5] = {0, 2, 3, 1, 5};
    int *array1 = array;
    int size = 5;
    S_sort(array,size);
    for (int i=0;i<size;i++){
        cout<<array[i];
    }

}