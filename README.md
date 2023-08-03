# Yugioh Sorting

## Implementation:

You will modify the DoublyLinkedList class to implement the swap function that swaps 2 elements in a doubly-linked list.
You will modify the CardShop class to implement the following sorting algorithms and their helper functions: bubbleSort, insertionSort, quickSort, mergeSort.
Remember, you must thoroughly document your code and explain your thought process!!! 

## Task 1: Implementing the swap method for the DoublyLinkedList class

Implement the following method for the DoublyLinkedList class:

/**
  
  @param: i is the index (integer) of the first item we are swapping in the list
  @param: j is the index (integer) of the second item we are swapping in the list
  @pre: i < j
  @post:  swaps the element at position i with the element at position j
  @example we have 1, 2, 3, 4, 5 in our list so calling swap(1,2) will make it:
  1, 3, 2, 4, 5 (note we start from index 0)
*/
swap
Be sure to test for edge cases!
 
## Task 2: Implement sorting algorithms for the CardShop class

Now that you can swap things around, implementing the sorting algorithms should be easy.

In your CardShop class you will have 4 sorting functions:

- bubbleSort
- insertionSort
- quickSort
- mergeSort
You are only required to implement *3 of the 4* sorting algorithms for full points. You can implement all 4 for extra credit.

Let's look at an example sorting function and consider the parameters and returns all these functions need:
template<typename Comparator>
int bubbleSort(Comparator comp, std::string key);

- All sorting functions will take the two parameters described above. NOTE that quickSort and mergeSort too will have only these two parameters, if you need to pass extra arguments you need to write helper functions. 
- We want you to be able to sort in both ascending and descending order, so just writing something like if(a > b) and then  swap won't work if we want to sort in the reverse order. We want to write a single function and parameterize whether we use the greater-than or less-than operators. We can use a template to parameterize a function (we pass a function into another function). That is why all the sorting functions will be templated, and will have a template Comparator parameter. 
    - comp can then be replaced by one of two functions:
        - std::less<int>{} which compares if the first item is less than the 2nd
         This is used for sorting in ascending order.
        - std::greater<int>{} for if the first item is greater than the 2nd
         This is used for sorting in descending order.
    - Instead of using if a<b or b>a, within the sorting functions you will have if(comp(a,b)). This will then be replaced with either if(a<b or if(a>b) depending on the argument being passed into the function when it is called. 
- Next we have what "key" we are sorting by. In our project the possible keys your sorting functions should account for are atk and def. This means the 4 possible ways of sorting the list are as follows:
    - ascending atk value with function call: bubbleSort(std::less<int>{}, "atk")
    - descending atk value with function call: bubbleSort(std::greater<int>{}, "atk")
    - ascending def value with function call: bubbleSort(std::less<int>{}, "def")
    - descending def value with function call: bubbleSort(std::greater<int>{}, "def")
- For grading purposes, all sorting functions MUST RETURN THE NUMBER OF SWAPS performed by the sorting algorithm. In the case of MergeSort, it will return the number of merge operations. 
- REMEMBER Parameters and returns will be the same for all sorting functions.
- IMPORTANT: Since CardShop has some template functions, it cannot be compiled. You must therefore follow  your usual include rules, except that main.cpp will now include CardShop.cpp instead of CardShop.hpp, so that it can be compiled with the appropriate comparison operator along with main.cpp. 
- Make sure to familiarize yourself with every class provided with the starter files before you start coding. You will use these classes to guide you in the implementation and testing of the sorting functions you write. You may write additional helper functions as you see fit.

