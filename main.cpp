#include <iostream>
#include <cassert>
#include "BinaryTree.h"
using namespace std;


void test1_numbers() {
	BinaryTree tree(1);
	tree.add_node( { 2, 4, 7 }, { 'L', 'L', 'L' });
	tree.add_node( { 2, 4, 8 }, { 'L', 'L', 'R' });
	tree.add_node( { 2, 5, 9 }, { 'L', 'R', 'R' });
	tree.add_node( { 3, 6, 15 }, { 'R', 'R', 'L' });

	assert(tree.max_tree() == 15);
	assert(tree.get_height() == 3);
	assert(tree.get_total_nodes() == 10);
	assert(tree.get_leaf_nodes() == 4);

	assert(tree.search_node(1));
	assert(tree.search_node(15));
	assert(tree.search_node(4));
	assert(!tree.search_node(61));
}

void test2_is_perfect() {
	BinaryTree tree(1);

	assert(tree.is_perfect() == 1);

	tree.add_node( { 2 }, { 'L' });
	tree.add_node( { 3 }, { 'R' });

	assert(tree.is_perfect() == 1);

	tree.add_node( { 2, 4, 7 }, { 'L', 'L', 'L' });
	tree.add_node( { 2, 4, 8 }, { 'L', 'L', 'R' });
	tree.add_node( { 2, 5, 9 }, { 'L', 'R', 'R' });
	tree.add_node( { 3, 6, 15 }, { 'R', 'R', 'L' });

	assert(tree.is_perfect() == 0);

	tree.add_node( { 2, 5, 13 }, { 'L', 'R', 'L' });
	tree.add_node( { 3, 6, 12 }, { 'R', 'R', 'R' });
	tree.add_node( { 3, 14, 15 }, { 'R', 'L', 'L' });
	tree.add_node( { 3, 14, 16 }, { 'R', 'L', 'R' });

	assert(tree.is_perfect() == 1);	// now 8 leaf nodes
}

void test3_print(){

	BinaryTree* tree ;
	tree = new BinaryTree(1) ;

	tree->add_node( {2} , {'L'} ) ;
	tree->add_node( {3} , {'R'} ) ;
	tree->print_inorder() ; //  2 1 3
	cout << "\n" ;
	tree->print_postorder() ; // 2 3 1
	cout << "\n" ;
	(*tree).print_preorder() ; // 1 2 3
	cout << "\n" ;
}

int main() {
	test1_numbers();
	test2_is_perfect();
	test3_print() ;

	cout << "\nFine\n";

	return 0;
}

