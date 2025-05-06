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

    //TODO Segfault error beheben

    /// @brief Creates a binary tree structure with elements out of a given vector
    /// @param v vector of elements to be placed inside a binary tree
    template <typename K, typename V> Element<K, V>* create_binary_tree(std::vector<Element<K, V>>* v){

        if (v->size() == 0){
            return nullptr;
        }

        //Muss bei eins starten, darf das erste Element nicht zu sich selbst hinzufügen
        for(auto i = 1; i < v->size(); i++){

            (*v)[0].add_element(&(v->at(i)));
        }

        return &(v->at(0));
    }