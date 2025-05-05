#include <catch2/catch_test_macros.hpp>

#include "element.h"

TEST_CASE("Constructor", "[binary tree]"){

    Element<int, bool> example_elem(42, true);

    REQUIRE(example_elem.key == 42);
    REQUIRE(example_elem.value == true);
    REQUIRE(example_elem.left_child_ptr == nullptr);
    REQUIRE(example_elem.right_child_ptr == nullptr);
}

TEST_CASE("Add element", "[binay tree]"){

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