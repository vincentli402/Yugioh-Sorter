#include "DoublyLinkedList.hpp"
#include "CardShop.cpp"
#include "YGOCard.hpp"

#include <iostream>

int main() {
    //DoublyLinkedList<int> new_list;
    //new_list.insert(0,1);
    //new_list.insert(1,2);
    //new_list.insert(2,3);
    //new_list.insert(3,4);
    //new_list.insert(4,5);
    //new_list.swap(1,2);
    //new_list.display();
    CardShop new_card("cards.csv");  
    //std::cout << new_card.bubbleSort(std::greater<int>{}, "atk") << std::endl;
    //std::cout << new_card.bubbleSort(std::less<int>{}, "atk") << std::endl;
    //std::cout << new_card.bubbleSort(std::greater<int>{}, "def") << std::endl;
    //std::cout << new_card.bubbleSort(std::less<int>{}, "def") << std::endl;
    //std::cout << new_card.insertionSort(std::greater<int>{}, "atk") << std::endl;
    //std::cout << new_card.insertionSort(std::less<int>{}, "atk") << std::endl;
    //std::cout << new_card.insertionSort(std::greater<int>{}, "def") << std::endl;
    //std::cout << new_card.insertionSort(std::less<int>{}, "def") << std::endl;
    std::cout << new_card.quickSort(std::greater<int>{}, "atk") << std::endl;
    std::cout << new_card.quickSort(std::less<int>{}, "atk") << std::endl;
    std::cout << new_card.quickSort(std::greater<int>{}, "def") << std::endl;
    std::cout << new_card.quickSort(std::less<int>{}, "def") << std::endl;

    //new_card.display();
    
}