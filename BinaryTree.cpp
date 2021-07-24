#include "BinaryTree.h"
#include <cassert>
#include <algorithm>
#include <cmath>
#include <stack>
#include <map>

BinaryTree::BinaryTree( int Data ) {
	data = Data ;
	right = left = nullptr ;
}

BinaryTree::BinaryTree( string postfix){

	stack< BinaryTree* > s ;

	for( int i = 0 ; i< (int)postfix.size() ; i++ ){

		BinaryTree* node = new BinaryTree( postfix[i] ) ;

		if( !isdigit( postfix[i] ) ){

			node->right = s.top() ;
			s.pop() ;

			node->left = s.top() ;
			s.pop() ;
		}
		s.push(node) ;
	}

	BinaryTree* root = s.top() ;

	this->data = root->data ;
	this->left = root->left ;
	this->right = root->right ;

}

void BinaryTree::print_inorder(){
		if( left )
			left->print_inorder() ;
		cout << data << " " ;
		if( right )
			right->print_inorder() ;
	}

void BinaryTree::print_postorder(){
		if(left)
			left->print_postorder() ;
		if( right )
			right->print_postorder() ;
		cout << data << " " ;
	}

void BinaryTree::print_preorder(){
		cout << data << " " ;
		if(left)
			left->print_preorder() ;
		if(right)
			right->print_preorder() ;
	}

void BinaryTree::add_node( vector<int> values , vector<int> positions ){
	assert( values.size() == positions.size() ) ;
	BinaryTree* current = this ;

	for( int i = 0 ; i < (int)values.size() ; i++ ){
		if( positions[i] == 'L'){
			if( current->left )
				assert( values[i] == current->left->data ) ;
			else if( !current->left )
				current->left = new BinaryTree( values[i] ) ;
			current = current->left ;
		}
		else if( positions[i] == 'R'){
			if( current->right )
				assert( values[i] == current->right->data ) ;
			else if( !current->right )
				current->right = new BinaryTree( values[i] ) ;
			current = current->right ;
		}
	}
}

int BinaryTree::max_tree(){
	int res = data ;
	if( left )
		res = max(res , left->max_tree() ) ;
	if(right )
		res = max( res , right->max_tree() ) ;
	return res ;
}

int BinaryTree::get_height(){
	int res = 0 ;
	if(left)
		res = 1 + left->get_height() ;
	if(right)
		res = max( res , 1 + right->get_height() ) ;
	return res ;
}

int BinaryTree::get_total_nodes(){
	int res = 1 ;
	if( left )
		res += left->get_total_nodes() ;
	if( right )
		res += right->get_total_nodes() ;
	return res ;
}

int BinaryTree::get_leaf_nodes(){
	int leaf = !left && !right ;
	if( left )
		leaf += left->get_leaf_nodes() ;
	if( right )
		leaf += right->get_leaf_nodes() ;
	return leaf ;
}

int BinaryTree::search_node( int value ){
	int res = data == value ;
	if( !res && left )
		res = left->search_node(value) ;
	if(!res && right )
		res = right->search_node(value) ;
	return res ;
}

int BinaryTree::is_perfect_formula(){
	int h = get_height() ;
	return pow(2,h+1) - 1 == get_total_nodes() ;
}

bool BinaryTree::is_perfect( int h ){
	if( h == -1 )
		h = get_height() ;
	if( !left && !right )
		return h == 0 ;
	if( (!left && right) || (left && !right) )
		return false ;
	return left->is_perfect( h-1 ) && right->is_perfect( h-1 ) ;
}

void BinaryTree::print_inorder_iterative(){
	stack< pair<BinaryTree* , bool> > s ;
	s.push( make_pair( this , false ) ) ;

	while( !s.empty() ){
		BinaryTree *current = s.top().first  ;
		bool has_children = s.top().second ;
		s.pop() ;

		if( has_children )
			cout << current->data << " " ;
		else{

			if( current->right )
				s.push( make_pair( current->right , false ) ) ;

			s.push( make_pair( current , true ) ) ;

			if( current->left )
				s.push( make_pair( current->left , false ) ) ;
		}
	}
}

void BinaryTree::travrse_left_boundary(){

	cout << this->data << " " ;

	if( left ){
		left->travrse_left_boundary() ;
	}
	else{
		right->travrse_left_boundary() ;
	}
}

void BinaryTree::travrse_right_boundary(){

	cout << this->data << " " ;

	if( right )
		right->travrse_right_boundary() ;
	else
		left->travrse_right_boundary() ;
}

pair<int,int> BinaryTree::Diameter(){
//  pair<diameter,height >  first pair for diameter & second pair for height
	pair<int,int> res = make_pair( 0 , 0 ) ;

	if( !left && !right )
		return res ;

	pair<int,int> sub_left = make_pair( 0,0 ) ;
	pair<int,int> sub_right = make_pair( 0,0 ) ;

	if( left ){
		sub_left = left->Diameter() ;
		res.first += 1 + sub_left.second ;
	}

	if( right ){
		sub_right = right->Diameter() ;
		res.first += 1 + sub_right.second ;
	}

	res.second = 1 + max( sub_right.second , sub_left.second ) ;

	return res ;
}

bool BinaryTree::has_children(){

	return !left && !right ;
}

void BinaryTree::print_inorder_parntheses(){

	if( left ){
		if( !left->has_children() )
			cout << "(" ;

		left->print_inorder_parntheses() ;

		if( ! left->has_children() )
			cout << ")" ;
	}
	cout << this->data  ;

	if( right ){

		if( !right->has_children() )
			cout << "(" ;

		right->print_inorder_parntheses() ;

		if( !right->has_children() )
			cout << ")" ;
	}
}

void BinaryTree::clear(){
}

/*

BinaryTree::~BinaryTree(){ // The order of destructor will be post-order

	if( left ){
		delete left ;
		left = nullptr ;
	}
	if( right ){
		delete right ;
		right = nullptr ;
	}
	cout << this->data << " " ;
}


*/











