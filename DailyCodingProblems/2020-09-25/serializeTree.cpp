#include<iostream>
#include<string>
#include<queue>
#include<cassert>

using namespace std;

class Node {
public:
	string val;
	Node* left;
	Node* right;
	Node(string v){
		val = v; 
		left = nullptr; 
		right = nullptr;
	}
	Node(string v, Node* leftNode, Node* rightNode){
		val = v;
		left = leftNode;
		right = rightNode;
	}
};

class Solution{
private:
	char delimiter;
	int index;
	string nullPlaceholder;
public:
	Solution(){
		delimiter='|';
		index=0;
		nullPlaceholder="?";
	}
	string serialize(Node* root){
		string serialized="";		
		recurSerialize(root,&serialized);
		return serialized;
	}
	void recurSerialize(Node* root, string* str_ptr){
		if( root == nullptr){
			*str_ptr += nullPlaceholder + delimiter;
			return;
		}
		
		*str_ptr += root->val + delimiter;
		recurSerialize(root->left,str_ptr);
		recurSerialize(root->right,str_ptr);
	}
	Node* deserialize(string serialized){
		Node* root = nullptr;
		index=0;
		recurDeserialize(root, serialized);	
		return root;
	}
	void recurDeserialize(Node* root, string serialized){
		
		string word="";
		while(serialized[index]!=delimiter){
			word+=serialized[index++];
		}
		
		cout << word << " ";	
		if(index>=serialized.size() || word==nullPlaceholder){
			return;	
		}
		
		root = new Node(word);
		recurDeserialize(root->left, serialized);
		recurDeserialize(root->right, serialized);
	} 			
};

//Node* deserialize(string str){
//}
int main(){
	Node* node = new Node("root", new Node("left", new Node("left.left"), nullptr), new Node("right"));
	cout << node->left->val << endl;
	
	Solution solution;
	
	cout << solution.serialize(node) << endl;
	
	string serialized = solution.serialize(node);
	Node* out = solution.deserialize(serialized);
	
	cout << out->left->val << endl;
	//assert( solution.deserialize(solution.serialize(node))->left->left->val == "left.left");

	return 0;
}
