#include <iostream>
#include <vector>
#include <map>

using namespace std ;

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

class BinaryTree {
private:
	char data ;
	BinaryTree* left ;
	BinaryTree* right ;

public:
	BinaryTree( int data ) ;
	BinaryTree( string postfix ) ; // This constructor will convert string experssion

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

	//
	void clear() ;
	void print_inorder_iterative() ;
	void travrse_left_boundary() ;
	void travrse_right_boundary() ;
	pair< int , int > Diameter() ;
	bool has_children() ;
	void print_inorder_parntheses() ;



	//~BinaryTree() ;
};

#endif /* BINARYTREE_H_ */



















