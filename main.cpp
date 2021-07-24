#include <iostream>
#include <cassert>
#include <map>

#include "BinaryTree.h"
using namespace std;

/*
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
	tree->print_inorder() ;
	tree->print_inorder_iterative() ; //  2 1 3
	cout << "\n" ;
	tree->print_postorder() ; // 2 3 1
	cout << "\n" ;
	(*tree).print_preorder() ; // 1 2 3
	cout << "\n" ;

	cout << "\nDestructor\n" ;
	delete tree ;
	cout << "\n" ;

	tree = new BinaryTree(4) ;
	cout << tree->get_total_nodes() << "\n" ; // 1

	cout << "\nDestructor\n" ;
	delete tree ;
	cout << endl ;

}


void test4_diameter() {
	BinaryTree tree(1);

	assert( tree.Diameter().first == 0) ;

	tree.add_node( { 2 }, { 'L' });
	tree.add_node( { 3 }, { 'R' });

	assert(tree.Diameter().first == 2);

	tree.add_node( { 2, 4, 7 }, { 'L', 'L', 'L' });
	tree.add_node( { 2, 4, 8 }, { 'L', 'L', 'R' });
	tree.add_node( { 2, 5, 9 }, { 'L', 'R', 'R' });
	tree.add_node( { 3, 6, 15 }, { 'R', 'R', 'L' });

	tree.add_node( { 2, 5, 13 }, { 'L', 'R', 'L' });
	tree.add_node( { 3, 6, 12 }, { 'R', 'R', 'R' });
	tree.add_node( { 3, 14, 15 }, { 'R', 'L', 'L' });
	tree.add_node( { 3, 14, 16 }, { 'R', 'L', 'R' });

	assert(tree.Diameter().first == 6);
}
*/

void test6() {
	BinaryTree root("534*2^+");

	// To work well, You must convert the data type of data from integer to char
	cout << "infix expression: ";
	root.print_inorder_parntheses();
	cout << "\n";
	// infix expression: 5+((3*4)^2)
}


int main() {/*
	cout << "test1 \n" ;
	test1_numbers();
	cout << "\n test2 \n " ;
	test2_is_perfect();
	cout << " \n test3 \n" ;
	test3_print() ;
	cout << "\n test4 \n" ;
	test4_diameter() ;
	cout<< "\ntest6\n" ;*/
	test6() ;

	cout << "\nFine\n";


	return 0;
}

