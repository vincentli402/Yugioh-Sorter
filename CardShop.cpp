/*
Vincent Li
CSCI235
Project 5
*/

#include "CardShop.hpp"
#include "Node.hpp"
#include <iostream>
#include <fstream>
#include <sstream>


/**
  @pre  : the input file is in csv format: "name,type,level_rank,race,attribute,atk,def"
  @param: the name of the input file
  @post:  Reads the input file and adds pointers to YGOCard objects 
          instantiated with the information read from the file. 
    */
CardShop::CardShop(std::string input_file_name) 
{
  std::ifstream fin(input_file_name);
  if (fin.fail())
  {
    std::cerr << "File cannot be opened for reading. \n";
    exit(1); // exit if failed to open the file
  }
  //we don't use the first line
  std::string ignore;
  getline(fin, ignore);

  //the columns of the csv associated with the data members
  std::string name, type, race, attribute;
  int level_rank, atk, def;

  std::string temp_string;
  int temp_int;
  int item_counter = 0;
  while (getline(fin, temp_string, ','))
  {
    name = temp_string;

    getline(fin, type, ',');
  
    getline(fin, temp_string, ',');
    std::istringstream(temp_string) >> temp_int;
    level_rank = temp_int;

    getline(fin, race, ',');

    getline(fin, attribute, ',');

    getline(fin, temp_string, ',');
    std::istringstream(temp_string) >> temp_int;
    atk = temp_int;

    getline(fin, temp_string);
    std::istringstream(temp_string) >> temp_int;
    def = temp_int;

    //create new card
    YGOCard *card_ptr = new YGOCard(name, type, level_rank, race, attribute, atk, def);

    //add to linked list and increment counter
    insert(item_counter++, card_ptr);
  }
}

//@post: removes all cards from the shop
//Deallocate and delete items
void CardShop::clear()
{
  for (int i = 0; i < item_count_; i++)
  {
    YGOCard *ptr = getItem(i);
    delete ptr;
    ptr = nullptr;
  }
  DoublyLinkedList::clear();
}

//destructor
CardShop::~CardShop()
{
  clear();
}

//@post: displays information of all cards in the shop, one per line
void CardShop::display()
{
  for (int i = 0; i < item_count_; i++)
  {
    getItem(i)->display();
  }
}

  //@param: the index of the first card to be displayed
  //@param: the index of the last card to be displayed
  //@post: displays the names of all cards in the shop with startRange and endRange, 
  //       inclusive, one per line
void CardShop::displayName(int startRange, int endRange)
{
  for (int i = startRange; i <= endRange; i++)
  {
    getItem(i)->displayName();
    if (i != endRange)
    {
      std::cout << ", ";
    }
    else
    {
      std::cout << std::endl;
    }
  }
}


//@return:  true if all the cards in rhs are equal to the cards in the shop, false otherwise
bool CardShop::operator==(const CardShop &rhs) const
{
  if (getLength() != rhs.getLength())
  {
    return false;
  }
  for (int i = 0; i < getLength(); i++)
  {
    if (*(getPointerTo(i)->getItem()) == *(rhs.getPointerTo(i)->getItem()))
    {
    }
    else
    {
      return false;
    }
  }
  return true;
}

  /**bubbleSort
    @param   :   The Comparator to sort with
    @param   :   A STRING key ("atk" or "def")
    @returns :   number of swaps to sort the cards in ascending or descending order based on "atk" or "def"
  */
  template<typename Comparator>
  int CardShop::bubbleSort(Comparator comp, std::string key)
  { 
    bool swapped = true; // Assume unsorted
    int pass = 1;
    int counter = 0;

    while (swapped && (pass < getLength()))
    {
      swapped = false;
      for (int i = 0; i < getLength() - pass; i++)
      {
        Node<YGOCard*> *ptr = getPointerTo(i);
        Node<YGOCard*> *ptr2 = getPointerTo(i + 1);
        if(key == "atk")
        {
          if (comp(ptr2->getItem()->getAtk(), ptr->getItem()->getAtk()))
          {
            swap(i, i + 1); 
            swapped = true; 
            counter++; // increment counter
          }
        }
        else if(key == "def")
        {
          if (comp(ptr2->getItem()->getDef(), ptr->getItem()->getDef()))
          {
            swap(i, i + 1);
            swapped = true;
            counter ++; // increment counter
          }
        }
      }  // end for
      pass++; // increment pass
    }  // end while
    return counter;
  }  // end bubbleSort

  /**insertionSort
    @param   :   The Comparator to sort with
    @param   :   A STRING key ("atk" or "def")
    @returns :   number of swaps to sort the cards in ascending or descending order based on "atk" or "def"
  */
  template<typename Comparator>
  int CardShop::insertionSort(Comparator comp, std::string key)
  {
    int counter = 0;
    for (int i = 1; i < getLength(); i++)
    {
      int current = i; //the index of the item currently being inserted
      Node<YGOCard*> *ptr = getPointerTo(current);
      Node<YGOCard*> *ptr2 = getPointerTo(current - 1);
      
      if(key == "atk")
      {
        while ((current > 0) && (comp(ptr->getItem()->getAtk(), ptr2->getItem()->getAtk())))
        {
          swap(current, current - 1);
          current--; //decrements current
          ptr = getPointerTo(current); // updates ptr to new value of current
          ptr2 = getPointerTo(current - 1); // updates ptr2 to new value of current
          counter++; // increments counter
        }
      }
      else if(key == "def")
      {
        while ((current > 0) && (comp(ptr->getItem()->getDef(), ptr2->getItem()->getDef())))
        {
          swap(current, current - 1);
          current--; // decrements current
          ptr = getPointerTo(current); // updates ptr to new value of current
          ptr2 = getPointerTo(current - 1); // updates ptr2 to new value of current
          counter++; // increments counter
        }        
      }
    }  // end for
    return counter; 
  }  // end insertionSort
  
  /**quickSort
    @param   :   The Comparator to sort with
    @param   :   A STRING key ("atk" or "def")
    @returns :   number of swaps to sort the cards in ascending or descending order based on "atk" or "def"
  */
  template<typename Comparator>
  int CardShop::quickSort(Comparator comp, std::string key)
  {
    return quickSortFunc(comp, key, 0, getLength() - 1); 
  }

  //helper functions for quickSort
  // Partition the array using the last element as the pivot
  template<typename Comparator>
  int CardShop::partition(Comparator comp, std::string key, int low, int high, int& counter)
  {
  YGOCard *pivot = getItem(high);
  int i = (low - 1); // Index of smaller element and indicates the 

  for (int j = low; j <= high; j++)
    {
      if (key == "atk" && (comp(getPointerTo(j)->getItem()->getAtk(), pivot->getAtk())) || key == "def" && (comp(getPointerTo(j)->getItem()->getDef(), pivot->getDef())))
      {
        i++;        // increment index of smaller element
        swap(i, j); // swaps index i and j
        counter++;  // increments counter
      }
    }
    swap(i+1, high);// swaps with pivot
    counter++;      // increments counter
    return (i + 1); // returns pivot index
  }

  //helper functions for quickSort
  template<typename Comparator>
  int CardShop::quickSortFunc(Comparator comp, std::string key, int low, int high)
  {
    int counter = 0;
    if (low < high)
    {
      int pivot_index = partition(comp, key, low, high, counter); //calls for pivot index
      counter += quickSortFunc(comp, key, low, pivot_index - 1) + quickSortFunc(comp, key, pivot_index + 1, high); // adds all the counters for both sides of the pivot
    }
    return counter; //returns number of swaps to sort
  }

  template<typename Comparator>
  int CardShop::mergeSort(Comparator comp, std::string key)
  {
    return 0;
  }