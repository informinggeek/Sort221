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
////////////////////////////////////////////////////////////////////////////////

#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#include <iostream>
#include <limits>
#include <vector>

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
    for(int i = 0;i < s;++i)			// for every element in the sequence
    {
	RandomAccessIterator prec = first;	// set the predecessor iterator to the first element in the sequence 
	for(int j = 1;j < s-i;++j)		// for every element not already checked in the sequence (size - elements already checked)
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
template<class RandomAccessIterator, class Compare>
  void merge_sort(RandomAccessIterator first, RandomAccessIterator last,
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
/// Quick Sort.
template<class RandomAccessIterator, class Compare>
  void quick_sort(RandomAccessIterator first, RandomAccessIterator last,
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
/// Sort sorts in an optimal fashion. Select and implement one of:
///   -(a) heap sort  (in place)
///   -(b) merge sort
///   -(c) quick sort (in place)
template<class RandomAccessIterator, class Compare>
  void sort(RandomAccessIterator first, RandomAccessIterator last,
      Compare comp) {
    /// @todo Call your fast sort of choice
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
