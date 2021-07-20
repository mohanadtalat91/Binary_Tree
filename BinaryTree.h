#include <iostream>
#include <vector>
#include <cassert>

using namespace std ;

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

class BinaryTree {
private:
	int data ;
	BinaryTree* left ;
	BinaryTree* right ;

public:
	BinaryTree( int data ) ;

	// printing (in,post,pre) orders
	void print_inorder() ;
	void print_postorder() ;
	void print_preorder() ;
	// adding node with given value&position
	void add_node( vector<int>values , vector<int> positions) ;

	//
	int max_tree() ;
	int get_height() ;
	int get_total_nodes() ;
	int get_leaf_nodes() ;
	int search_node( int ) ;
	int is_perfect_formula() ;
	bool is_perfect( int h =-1 ) ; // Default parameters only in declaration file not definition fine
};

#endif /* BINARYTREE_H_ */



















