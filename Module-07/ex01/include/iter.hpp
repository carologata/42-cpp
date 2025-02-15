#ifndef ITER_HPP
#define ITER_HPP

/* template <typename T> 
void iter(T *array, int length, void (*func)(T &element))
{
    for (int i = 0; i < length; i++)
    {
        func(array[i]);
    }
} */
template <typename T>
void iter(T* arr, size_t len, void (*func)(T &element)) {
    for (size_t i = 0; i < len; ++i) {
        func(arr[i]);  
    }
}

#endif