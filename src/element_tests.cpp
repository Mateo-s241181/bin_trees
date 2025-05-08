#include <catch2/catch_test_macros.hpp>

#include "element.h"
#include "element.cpp"

TEST_CASE("Constructor", "[binary tree]"){

    Element<int, bool> example_elem(42, true);

    REQUIRE(example_elem.key == 42);
    REQUIRE(example_elem.value == true);
    REQUIRE(example_elem.left_child_ptr == nullptr);
    REQUIRE(example_elem.right_child_ptr == nullptr);
}

TEST_CASE("Add element", "[binary tree]"){

    Element<int, bool> root(1, false);

    REQUIRE(root.key == 1);
    REQUIRE(root.value == false);
    REQUIRE(root.left_child_ptr == nullptr);
    REQUIRE(root.right_child_ptr == nullptr);

    Element<int, bool> new_elem(2, true);

    REQUIRE(new_elem.key == 2);
    REQUIRE(new_elem.value == true);
    REQUIRE(new_elem.left_child_ptr == nullptr);
    REQUIRE(new_elem.right_child_ptr == nullptr);

    root.add_element(&new_elem);

    REQUIRE(root.key == 1);
    REQUIRE(root.value == false);
    REQUIRE(root.left_child_ptr == nullptr);
    REQUIRE(root.right_child_ptr == &new_elem);
    REQUIRE(root.right_child_ptr->key == 2);
    REQUIRE(root.right_child_ptr->value== true);
    REQUIRE(root.right_child_ptr->right_child_ptr == nullptr);
    REQUIRE(root.right_child_ptr->left_child_ptr == nullptr);

    Element<int, bool> another_elem(3, false);

    root.add_element(&another_elem);

    REQUIRE(root.key == 1);
    REQUIRE(root.value == false);
    REQUIRE(root.left_child_ptr == nullptr);
    REQUIRE(root.right_child_ptr == &new_elem);
    REQUIRE(root.right_child_ptr->key == 2);
    REQUIRE(root.right_child_ptr->value== true);
    REQUIRE(root.right_child_ptr->right_child_ptr == &another_elem);
    REQUIRE(root.right_child_ptr->left_child_ptr == nullptr);
    REQUIRE(root.right_child_ptr->right_child_ptr->key == 3);
    REQUIRE(root.right_child_ptr->right_child_ptr->value == false);
    REQUIRE(root.right_child_ptr->right_child_ptr->right_child_ptr == nullptr);
    REQUIRE(root.right_child_ptr->right_child_ptr->left_child_ptr == nullptr);

}

TEST_CASE("Create Elements", "[binary tree]"){

    std::vector<int> keys = {0, 1, 2, 3, 4, 5};
    std::vector<std::string> values = {"a", "b", "c", "d", "e", "f"};

    std::vector<Element<int, std::string>> elem_vec = create_elements(keys, values);

    REQUIRE(elem_vec[0].key == 0);
    REQUIRE(elem_vec[1].key == 1);
    REQUIRE(elem_vec[2].key == 2);
    REQUIRE(elem_vec[3].key == 3);
    REQUIRE(elem_vec[4].key == 4);
    REQUIRE(elem_vec[5].key == 5);

    REQUIRE(elem_vec[0].value == "a");
    REQUIRE(elem_vec[1].value == "b");
    REQUIRE(elem_vec[2].value == "c");
    REQUIRE(elem_vec[3].value == "d");
    REQUIRE(elem_vec[4].value == "e");
    REQUIRE(elem_vec[5].value == "f");

    for(auto el : elem_vec){

        REQUIRE(el.left_child_ptr == nullptr);
        REQUIRE(el.right_child_ptr == nullptr);
    }

    std::vector<int> keys_empty = {};
    std::vector<bool> values_empty = {};

    std::vector<Element<int, bool>> elem_vec_empty = create_elements(keys_empty, values_empty);

    REQUIRE(elem_vec_empty.empty());

    std::vector<int> keys_len = {1, 2, 3};
    std::vector<bool> values_len = {true, false};

    std::vector<Element<int, bool>> elem_vec_len = create_elements(keys_len, values_len);

    REQUIRE(elem_vec_len.empty());
}


TEST_CASE("Create binary tree", "[binary tree]"){

    std::vector<int> keys = {3, 1, 2, 0, 4, 5};
    std::vector<std::string> values = {"a", "b", "c", "d", "e", "f"};

    std::vector<Element<int, std::string>> elem_vec = create_elements(keys, values);

    Element<int, std::string>* root_adress = create_binary_tree(&elem_vec);

    REQUIRE(root_adress == &elem_vec[0]);
    REQUIRE(root_adress->key == 3);
    REQUIRE(root_adress->value == "a");
    REQUIRE(root_adress->left_child_ptr->key == 1);
    REQUIRE(root_adress->left_child_ptr->value == "b");
    REQUIRE(root_adress->right_child_ptr->key == 4);
    REQUIRE(root_adress->right_child_ptr->value == "e");
    REQUIRE(root_adress->left_child_ptr == &elem_vec[1]);
    REQUIRE(root_adress->right_child_ptr == &elem_vec[4]);
}

TEST_CASE("Binary search", "[binary tree]"){

    std::vector<int> keys = {3, 1, 2, 0, 4, 5};
    std::vector<std::string> values = {"a", "b", "c", "d", "e", "f"};

    std::vector<Element<int, std::string>> elem_vec = create_elements(keys, values);

    Element<int, std::string>* root_adress = create_binary_tree(&elem_vec);

    REQUIRE(binary_search(root_adress, 3) == &elem_vec[0]);
    REQUIRE(binary_search(root_adress, 1) == &elem_vec[1]);
    REQUIRE(binary_search(root_adress, 2) == &elem_vec[2]);
    REQUIRE(binary_search(root_adress, 0) == &elem_vec[3]);
    REQUIRE(binary_search(root_adress, 4) == &elem_vec[4]);
    REQUIRE(binary_search(root_adress, 5) == &elem_vec[5]);

    REQUIRE(binary_search(root_adress, 22) == nullptr);

}