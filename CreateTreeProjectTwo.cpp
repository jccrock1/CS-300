//============================================================================
// Name        : CreateTreeProjectTwo.cpp
// Author      : Jonathan Carmichael
// Version     : v1.4
// Copyright   : October 2022
// Description : Hello World in C++, Ansi-style
//============================================================================


//Including .hpp file
#include "BSTProjectTwo.hpp"

//Creating binary search tree
bst::bst(){
	root = nullptr;
}
bst::~bst(){
}
void bst::InOrder(){
	this -> inOrder(root);
}
void bst::Insert(Course course){
	if(root == nullptr){
		root = new Node(course);
	}
	else{
		addNode(root, course);
	}
}

/*
 * Set current node to root and search (loop) until end of the list is reached
 * or a matching bidId is found.
 */
Course bst::Search(string courseNum){
	Node* current = root;

	while(current != nullptr){
		//If a match is found, return the current bid.
		if(current -> course.courseNum.compare(courseNum) == 0){
			return current -> course;
		}
		//If a bid is smaller than the current node, traverse left.
		if(courseNum.compare(current -> course.courseNum) < 0){
			current = current -> left;
		}
		//Else larger, to the right.
		else{
			current = current -> right;
		}
	}
	//Creating a Course named "course" and returning it.
	Course course;
	return course;
}

//Inserting a bid into the tree
void bst::addNode(Node* node, Course course){
	//If node is larger than 0, add to the left.
	if(node -> course.courseNum.compare(course.courseNum) > 0){
		//If there is no left node...
		if(node -> left == nullptr){
			//...this becomes the left node.
			node -> left = new Node(course);
		}
		else{
			addNode(node -> left, course);
		}
	}
	//Else, the node bid is larger and becomes right.
	else{
		if(node -> right == nullptr){
			node -> right = new Node(course);
		}
		//Else again, recurse down the left node.
		else {
			addNode(node -> right, course);
		}
	}
}

void bst::inOrder(Node* node){
	//Begin traversing the tree based on position.
	if(root != nullptr){
		if(node -> left != nullptr){
			/*
			 * Calls inOrder. This will recur until the left node
			 * is empty, arriving at the tree's lowest value.
			 */
			inOrder(node -> left);
		}
		//Arriving at tree's lowest value.
		cout << node -> course.courseNum << ", " << node -> course.courseName << endl;

		//Same thing on the right.
		if(node -> right != nullptr){
			inOrder*node -> right);
		}
	}
}
