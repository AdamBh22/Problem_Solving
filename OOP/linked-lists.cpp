#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
#define make_pair mp 
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define vi vector<int>
#define vl vector<long long int>
#define pi pair<int,int>
#define pl pair<long long int ,long long int>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ll long long
#define endl '\n'
const double eps=1e-12;
int gcd (int a, int b) { return b ? gcd (b, a % b) : a; }
int lcm (int a, int b) { return a / gcd(a, b) * b; }
const int mod=1e9+7;
class Node{
private:
	Node * prev ;
	int data;
	Node * next ;
public:
	Node(int data):data(data),next(nullptr),prev(nullptr){};
	Node* getNext(){
		return next ;
	}
	Node* getPrev(){
		return prev ;
	}
	int getData(){
		return data ;
	}
	void setNext(Node* nextNode){
		next = nextNode ;
	}
	void setPrev(Node* prevNode){
		prev = prevNode ;
	}
};

class LinkedList{
private:
	Node* head ;
	Node* front ;
	int size ;
public: 
	LinkedList():head(nullptr),front(nullptr),size(0){};

	void insertAtBeginning(int value){
		size++;
		Node* nodePointer = new Node(value); 
		if(head == nullptr){
			head = nodePointer ;
			front = nodePointer ;
			return ;
		}
		head->setPrev(nodePointer);
		nodePointer->setNext(head);
		head = nodePointer ;
	}
	void insertAtEnd(int value){
		size++;
		Node* nodePointer = new Node(value);
		if(head == nullptr){
			head = nodePointer ;
			front = nodePointer ;
			return ;
		}
		front->setNext(nodePointer);
		nodePointer->setPrev(front);
		front = nodePointer ;
	}

	void insertAtPosition(int ps,int val){
		if(ps<1 || ps > size){
			cout<<"Position out of range ! "<<endl;
			return ;
		}
		Node* tmp = head;
		for(int i=1;i< ps;i++){
			tmp = tmp->getNext();
		}	
		Node* previousNode = tmp->getPrev();
		Node* node = new Node(val);
		node->setPrev(previousNode);
		node->setNext(tmp);
		tmp->setPrev(node);
	}
	void deleteFromBeginnig(){
		size--;
		if(head!=nullptr){
			Node* temp = head->getNext();
			head = temp ; 
		}
	}

	void deleteFromEnd(){
		size--;
		if(front!=nullptr){
			Node* temp = front->getPrev();
			front = temp ;
		}
	}

	void deleteFromPosition(int ps){
		if(ps<1 || ps > size){
			cout<<"Position out of range ! "<<endl;
			return ;
		}
		Node* tmp = head;
		for(int i=1;i< ps - 1 ;i++){
			tmp = tmp->getNext();
		}
		Node* nextNode = tmp->getNext()->getNext();
		if(nextNode!=nullptr){
			nextNode->setPrev(tmp);
		}
		tmp->setNext(nextNode);
	}
	int getBeginning(){
		return head->getData();
	}
	int getEnd(){
		return front->getData();
	}
	int getSize(){
		return size;
	}
	bool isEmpty(){
		return front == nullptr|| head == nullptr;
	}

};
 
int main() {
    fast;
    int n;
    cin>>n;
    LinkedList list;
    for(int i=1;i<=n;i++){
    	int x;
    	cin>>x;
    	list.insertAtBeginning(x);
    	//cout<<list.getBeginning()<<endl;
    }
    while(!list.isEmpty()){
    	cout<<list.getBeginning()<<" ";
    	list.deleteFromBeginnig();
    }
}
