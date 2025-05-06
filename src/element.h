#ifndef ELEMENT_H
#define ELEMENT_H

#include <vector>
#include <string>

/// Ein Element eines binären Suchbaumes.
template <typename K, typename V>
struct Element {
    
    //Key of the Element
    K key;
    //Value, that is held by the element of the binary tree
    V value;

    //pointers, that point to the children of the element
    Element<K, V>* left_child_ptr;
    Element<K, V>* right_child_ptr;

    Element(K k, V v){

        key = k;
        value = v;
        left_child_ptr = nullptr;
        right_child_ptr = nullptr;
    }

    
    /// @brief The function add_element adds a given element to the binary tree. By comparing the key of new_element to the key of first_element, it determines, whether it should be placed on the left or the right side of the tree and places it at the bottom.
    /// @param new_element Element, that needs to be added to the binary tree
    /// @param first_element pointer to some element of the binary tree. If you call the function, you should always enter a pointer to the root of your binary tree.
    void add_element(Element *new_element)
    {
        //Compare keys of both elements to each other and determine, whether new_element shound be placed on the right side of the binary tree
        bool place_on_right_side = new_element->key > key; 

        if (place_on_right_side){

            //check, if the element, the function was called from has an element linked to it on the right side
            if (right_child_ptr == nullptr){

                right_child_ptr = new_element;
                return;
            }

            //Move one layer down on the right side
            right_child_ptr->add_element(new_element);

        } else {

            if (left_child_ptr == nullptr){

                left_child_ptr = new_element;
                return;
            }

            left_child_ptr->add_element(new_element);
        }
    }
};

#endif
