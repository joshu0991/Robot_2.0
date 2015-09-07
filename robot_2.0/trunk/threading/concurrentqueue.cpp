#include "concurrentqueue.hpp"

template <typename T>
ConcurrentQueue<T>::ConcurrentQueue()
{
    head = NULL;
    tail = NULL;
}
