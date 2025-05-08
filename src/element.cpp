#include "element.h"

/// @brief Creates a vector of elements with given values and keys
    /// @param keys vector of keys
    /// @param values vector of values, that needs to be the sae size as keys
    /// @return Vector of elements
    template <typename K, typename V> std::vector<Element<K, V>> create_elements(std::vector<K> keys, std::vector<V> values){

        if (keys.size() != values.size()){
            return std::vector<Element<K, V>> {};
        }

        
        std::vector<Element<K, V>> elem_vec {};

        //range through one of the vectors backwards, grouping each key and value at position i together in an element
        for(size_t i = 0; i < keys.size(); i++){

            Element<K, V> elem(keys[i], values[i]);

            elem_vec.push_back(elem);
        }

        return elem_vec;
    }

    /// @brief Creates a binary tree structure with elements out of a given vector.
    /// @param v vector of elements to be placed inside a binary tree
    /// @return Pointer to the first element of the binary tree
    template <typename K, typename V> Element<K, V>* create_binary_tree(std::vector<Element<K, V>>* v){

        if (v->size() == 0){
            return nullptr;
        }

        //has to start at one, so that the first element doesnt get added twice
        for(auto i = 1; i < v->size(); i++){

            //adds the element at position i to the binary tree
            (*v)[0].add_element(&(v->at(i)));
        }

        //returns the memory adress of the first element of the binary tree
        return &(v->at(0));
    }

    //TODO: Add binary search algorithm
    
    /// @brief Searches for an element with a given key in a binary tree with a given root element, using the binary search algorithm
    /// @param root_elem_adress Pointer to the root element of a binary tree
    /// @param key_ Key of the element you are searching for
    /// @return Pointer to the first element of the binary tree with the key "key_"; nulltptr if element wasnt found
    template <typename K, typename V> Element<K,V>* binary_search(Element<K,V>* root_adress, K key_){

        //recursion anchors
        if (root_adress == nullptr){
            return nullptr;
        }

        if (root_adress->key == key_){
            return root_adress;
        }

        return root_adress->key > key_ ? binary_search(root_adress->left_child_ptr, key_) : binary_search(root_adress->right_child_ptr, key_);
    }