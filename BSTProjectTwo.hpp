#ifndef    BSTPROJECTTWO_HPP_
#define    BSTPROJECTTWO_HPP_

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Defining structure "Course".
struct Course{
	string courseNum;
	string courseName;
	string prerequisites;

	//Default constructor that sets each variable to "Void".
	Course(){
		courseNum = "Void";
		courseName = "Void";
		prerequisites = "Void";
	}
};

/*
 * Another structure to hold nodes. Each node has a pointer
 * (left, right)holding the course structure.
 */
struct Node{
	Course course;
	Node* left;
	Node* right;

	//Default Node constructor, setting pointers to null.
	Node(){
		left = nullptr;
		right = nullptr;
	}
};

/*
 * Create class bst ("Binary Search Tree") and define private and public
 * variables for Node and Course.
 */
class bst{
private:
	Node* root;

	void addNode(Node* node, Course course);
	void inOrder(Node* node);

public:
	bst();
	virtual ~bst();
	void InOrder();
	void Insert(Course course);
	Course Search(string courseNum);
};

#endif /* BSTPROJECTTWO_HPP_ */
