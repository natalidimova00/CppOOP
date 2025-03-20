#include "list.h"

template <typename T>
List<T>::List()
{
}
template <typename T>
bool List<T>::empty()
{
    return first == nullptr;
}

template <typename T>
unsigned List<T>::count()
{
    unsigned c = 0;
    box<T> *current = first;
    while (current != nullptr)
    {
        ++c;
        current = current->next;
    }
    return c;
}

template <typename T>
T& List<T>::operator[](unsigned i)
{
    box<T> *current = pointerTo(i);
    if (current == nullptr)
    {
        throw "Index out of bounds.";
    }
    return current->data;
}