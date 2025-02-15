#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <algorithm>
#include <vector>
#include <deque>

template <typename T>
int easyfind(T& container, int target) throw(std::exception)
{
    typename T::iterator it = std::find(container.begin(), container.end(), target);
    if (it == container.end())
        throw std::exception();
    return std::distance(container.begin(), it);
}

#endif

/* In C++, vector is a dynamic array with the ability to resize itself automatically when an element 
is inserted or deleted. It is the part Standard Template Library (STL) */

/* Double-ended queues are sequence containers with the feature of expansion and contraction on both ends. 
They are similar to vectors, but are more efficient in case of insertion and deletion of elements. 
Unlike vectors, contiguous storage allocation may not be guaranteed. 
Double Ended Queues are basically an implementation of the data structure double-ended queue. 
A queue data structure allows insertion only at the end and deletion from the front. 
This is like a queue in real life, wherein people are removed from the front and added at the back. 
Double-ended queues are a special case of queues where insertion and deletion operations are possible at both the ends.
The functions for deque are same as vector, with an addition of push and pop operations for both front and back.   */