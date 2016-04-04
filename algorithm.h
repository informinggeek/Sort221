////////////////////////////////////////////////////////////////////////////////
/// @brief Algorithms, e.g., sorting
/// @ingroup MySTL
/// @todo Implement swap
/// @todo Implement bubble sort
/// @todo Implement one of:
///       - Insertion Sort (in place)
///       - Selection Sort (in place)
/// @todo Implement one of:
///       - Heap Sort (in place)
///       - Merge Sort
///       - Quick Sort (in place)
/// @bonus Each extra sort you implement will be worth bonus points
///
/// By Thomas Step and Nathan Powell
////////////////////////////////////////////////////////////////////////////////

#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#include <iostream>
#include <limits>
#include <vector>
#include <list>

#include <math.h> // floor
#include <ctime> // time
#include <functional> // mod

namespace mystl {

////////////////////////////////////////////////////////////////////////////////
/// @brief Swap values of two elements
/// @tparam T Value type
/// @param a First value
/// @param b Second value
template<typename T>
  void swap(T& a, T& b) {
    /// @todo Implement swapping values
    T c = a; // Create a dummy variable
    a = b; // Swap A and B
    b = c; // Use the dummy C to finish swapping
  }

////////////////////////////////////////////////////////////////////////////////
/// @brief Sort the range [first, last) into nondecreasing order
/// @tparam RandomAccessIterator Random Access Iterator
/// @tparam Compare Comparator function
/// @param first Initial position of sequence to be sorted
/// @param last Final position of sequence to be sorted
/// @param comp Binary function that accepts two elements in the range as
///             arguments and returns a value convertable to bool. The value
///             returned indicates whether the element passed as first argument
///             is considered to go before the second in the ordering it
///             defines.
///
/// Bubble Sort
template<class RandomAccessIterator, class Compare>
  void bubble_sort(RandomAccessIterator first, RandomAccessIterator last,
      Compare comp) {
    /// @todo Implement Bubble sort
    size_t s = std::distance(first,last);	// finds the size of the sequence by taking the difference between the first and last iterators
    for(size_t i = 0;i < s;++i)			// for every element in the sequence
    {
	RandomAccessIterator prec = first;	// set the predecessor iterator to the first element in the sequence 
	for(size_t j = 1;j < s-i;++j)		// for every element not already checked in the sequence (size - elements already checked)
	{
		RandomAccessIterator succ = prec;	// sets the successor iterator
 		++succ;					// to be one element after the predecessor iterator
		if(comp(*succ,*prec))			// if the successor element is less than the predecessor element
		{
			swap(*prec,*succ);		// swap the elements
		}
		++prec;					// increment the predecessor element, and begin again
	}
  }
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Sort the range [first, last) into nondecreasing order
/// @tparam RandomAccessIterator Random Access Iterator
/// @tparam Compare Comparator function
/// @param first Initial position of sequence to be sorted
/// @param last Final position of sequence to be sorted
/// @param comp Binary function that accepts two elements in the range as
///             arguments and returns a value convertable to bool. The value
///             returned indicates whether the element passed as first argument
///             is considered to go before the second in the ordering it
///             defines.
///
/// Selection Sort.
template<class RandomAccessIterator, class Compare>
  void selection_sort(RandomAccessIterator first, RandomAccessIterator last,
      Compare comp) {
      
    RandomAccessIterator unsortedFirst; // This is the iterator we will change to find the min
    RandomAccessIterator min;
    
    while(first != last) { // Going through the whole list
      min = first; // Start out assuming that the first element is the min
      unsortedFirst = first; 
      unsortedFirst++; // We don't need to compare the first element to itself
      
      while(unsortedFirst != last) { // Going through the unsorted list finding the new min as we go
        if(comp(*unsortedFirst,*min)) // Comparing previous min element to the current element
          min = unsortedFirst; // If the current element is smaller than the current min, change the pointers
        unsortedFirst++; // Continue going through the unsorted list
      }
      
      if(min != first) // Compare the possibly new min to the assumed min from before (the first element)
        swap(*min,*first); // If the first element is not the correct min, then switch the elements
      first++; // Increase the unsorted front
    }
    
  }

////////////////////////////////////////////////////////////////////////////////
/// @brief Sort the range [first, last) into nondecreasing order
/// @tparam RandomAccessIterator Random Access Iterator
/// @tparam Compare Comparator function
/// @param first Initial position of sequence to be sorted
/// @param last Final position of sequence to be sorted
/// @param comp Binary function that accepts two elements in the range as
///             arguments and returns a value convertable to bool. The value
///             returned indicates whether the element passed as first argument
///             is considered to go before the second in the ordering it
///             defines.
///
/// Insertion Sort
template<class RandomAccessIterator, class Compare>
  void insertion_sort(RandomAccessIterator first, RandomAccessIterator last,
      Compare comp) {
     
      RandomAccessIterator tempfirst = first;
      RandomAccessIterator sorting;
      RandomAccessIterator sortingprev;
      RandomAccessIterator counting;
      
      while(tempfirst != last) { // Going up the list checking order

        sorting = tempfirst;
        sorting++;
        
        if(sorting != last) {
          if(comp(*sorting,*tempfirst)) { // Compare and possibly switch the tempfirst element with its next element
            if(sorting != last)
              swap(*sorting,*tempfirst);
            sorting = tempfirst;
            sortingprev = sorting;
            sortingprev--;

            while(sorting != first) { // Checking fit with all previous elements
              if(comp(*sorting,*sortingprev))
                swap(*sorting,*sortingprev); 	// Putting the newly sorted element where it needs
              sorting--;						// to be in comparison with the previously sorted elements
              if(sorting != first) // Case where we reach the beginning of the list
                sortingprev--;
            }
          }
        }

        tempfirst++;
        
      }
      
  }

////////////////////////////////////////////////////////////////////////////////
/// @brief Sort the range [first, last) into nondecreasing order
/// @tparam RandomAccessIterator Random Access Iterator
/// @tparam Compare Comparator function
/// @param first Initial position of sequence to be sorted
/// @param last Final position of sequence to be sorted
/// @param comp Binary function that accepts two elements in the range as
///             arguments and returns a value convertable to bool. The value
///             returned indicates whether the element passed as first argument
///             is considered to go before the second in the ordering it
///             defines.
///
/// Slow sort sorts in a non-optimal fashion. Select and implement one of:
///   -(a) insertion sort
///   -(b) selection sort
/// Your sort should be inplace (uses no extra memory).
template<class RandomAccessIterator, class Compare>
  void slow_sort(RandomAccessIterator first, RandomAccessIterator last,
      Compare comp) {
    /// @todo Call your slow sort of choice
    selection_sort(first, last, comp);   
  }

////////////////////////////////////////////////////////////////////////////////
/// @brief Sort the range [first, last) into nondecreasing order
/// @tparam RandomAccessIterator Random Access Iterator
/// @tparam Compare Comparator function
/// @param first Initial position of sequence to be sorted
/// @param last Final position of sequence to be sorted
/// @param comp Binary function that accepts two elements in the range as
///             arguments and returns a value convertable to bool. The value
///             returned indicates whether the element passed as first argument
///             is considered to go before the second in the ordering it
///             defines.
///
/// Heap Sort.
template<class RandomAccessIterator, class Compare>
  void heap_sort(RandomAccessIterator first, RandomAccessIterator last,
      Compare comp) {
 
  }

////////////////////////////////////////////////////////////////////////////////
/// @brief Sort the range [first, last) into nondecreasing order
/// @tparam RandomAccessIterator Random Access Iterator
/// @tparam Compare Comparator function
/// @param first Initial position of sequence to be sorted
/// @param last Final position of sequence to be sorted
/// @param comp Binary function that accepts two elements in the range as
///             arguments and returns a value convertable to bool. The value
///             returned indicates whether the element passed as first argument
///             is considered to go before the second in the ordering it
///             defines.
///
/// Merge Sort.

template<class RandomAccessIterator, class Compare, typename T>
std::vector<T> merge(RandomAccessIterator leftfirst, RandomAccessIterator leftlast,
RandomAccessIterator rightfirst, RandomAccessIterator rightlast, Compare comp) {
	std::vector<T> v;
	while(leftfirst!=leftlast && rightfirst!=rightlast)
	{
		if(comp(*rightfirst,*leftfirst))
		{
			v.push_back(*rightfirst);
			rightfirst++;
		}
		else
		{
			v.push_back(*leftfirst);
			leftfirst++;
		}
	}
	while(leftfirst!=leftlast)
	{
		v.push_back(*leftfirst);
		leftfirst++;
	}
	while(rightfirst!=rightlast)
	{
		v.push_back(*rightfirst);
		rightfirst++;
	}
	return v;
}
template<class RandomAccessIterator, class Compare>
  void merge_sort(RandomAccessIterator first, RandomAccessIterator last,
      Compare comp) {
	size_t s = std::distance(first,last);	// finds the size of the sequence by taking the difference between the first and last iterators
	RandomAccessIterator middle = first+s/2;
	if(first == middle)
	{
		return;
     	}
	merge_sort(first,middle,comp);
	merge_sort(middle,last,comp);
	typedef typename RandomAccessIterator::value_type T;
	std::vector<T> v = merge<RandomAccessIterator,Compare,T>(first,middle,middle,last,comp);
	size_t i = 0;
	for(auto k = first; k != last; ++k)
	{
		*k = v[i];
		++i;
	}
  }

////////////////////////////////////////////////////////////////////////////////
/// @brief Sort the range [first, last) into nondecreasing order
/// @tparam RandomAccessIterator Random Access Iterator
/// @tparam Compare Comparator function
/// @param first Initial position of sequence to be sorted
/// @param last Final position of sequence to be sorted
/// @param comp Binary function that accepts two elements in the range as
///             arguments and returns a value convertable to bool. The value
///             returned indicates whether the element passed as first argument
///             is considered to go before the second in the ordering it
///             defines.
///
/// Quick Sort.
template<class RandomAccessIterator, class Compare>
  void quick_sort(RandomAccessIterator first, RandomAccessIterator last,
      Compare comp) {
	
	if(first==last) { // Stopping case for recursion; if first and last are the same
      return;
    }
    
    RandomAccessIterator i = first;
    RandomAccessIterator j = last-2; // The pointer to the last element; the pivot
    RandomAccessIterator pivot = last-1; // The last element
          
    while(i<=j) { // While the pointers haven't overlapped
      while(comp(*i,*pivot) && i<=j) { // i goes right until it finds an element bigger than pivot
        i++;
        if(i==pivot)
          break;
      }
      
      while(comp(*pivot,*j) && i<=j) { // j goes left until it finds an element less than pivot
        j--;
        if(j==i)
            break;
      }
      
      if(comp(*j,*i) && i<=j) { // This should be the case anyway
        swap(*i,*j);
      }
      
      else { // If that's not the case, keep going (repeat elements)
        if(j != first)
          j--;
      }
    }
    
    // Put pivot into place
    swap(*i,*pivot); // Put pivot at i
    RandomAccessIterator qs2 = i+1;
	
    // Recursive calls
	quick_sort(first, i, comp);
    quick_sort(qs2, last, comp);
      
  }

////////////////////////////////////////////////////////////////////////////////
/// @brief Sort the range [first, last) into nondecreasing order
/// @tparam RandomAccessIterator Random Access Iterator
/// @tparam Compare Comparator function
/// @param first Initial position of sequence to be sorted
/// @param last Final position of sequence to be sorted
/// @param comp Binary function that accepts two elements in the range as
///             arguments and returns a value convertable to bool. The value
///             returned indicates whether the element passed as first argument
///             is considered to go before the second in the ordering it
///             defines.
///
/// Sort sorts in an optimal fashion. Select and implement one of:
///   -(a) heap sort  (in place)
///   -(b) merge sort
///   -(c) quick sort (in place)
template<class RandomAccessIterator, class Compare>
  void sort(RandomAccessIterator first, RandomAccessIterator last,
      Compare comp) {
    /// @todo Call your fast sort of choice
   merge_sort(first,last,comp);
  }

////////////////////////////////////////////////////////////////////////////////
/// @brief Sort the range [first, last) of integral types into nondecreading
///        order
/// @tparam RandomAccessIterator Random Access Iterator
/// @param first Initial position of sequence to be sorted
/// @param last Final position of sequence to be sorted
///
/// Sorts with Radix sort. Should do radix on decimal representation of integer
/// type, i.e., number of buckets is always 10.
/// typename RandomAccessIterator::value_type is required to be some integral
/// type, i.e., char, short, int, long, etc.
template<class RandomAccessIterator>
  void radix_sort(RandomAccessIterator first, RandomAccessIterator last) {
    /// @bonus Implement radix_sort
  }

}

#endif
