#include <iostream>
#include <stdexcept>
using namespace std;
// ──── Lista Encadeada Simples ─────────────────────────────
struct Node {
	int data;
	Node* next;
	Node(int d) : data(d), next(nullptr) {}
	};
struct LinkedList {
	Node* head = nullptr;
	int size = 0;
	};
// ──── Lista Duplamente Encadeada ──────────────────────────
struct DNode {
	int data;
	int priority; // 0 = normal, 1 = alta
		      //
	DNode* prev;
	DNode* next;
	DNode(int d, int p) : data(d), priority(p),
		prev(nullptr), next(nullptr) {}
	};
struct DLinkedList {
	DNode* head = nullptr;
	DNode* tail = nullptr;
	DNode* priority_tail = nullptr;
	int size = 0;
	};
// ──── Lista Circular (reusa Node) ────────────────────────
struct CircList {
	Node* tail = nullptr; // tail->next == head
	int size = 0;
	};

void invert(LinkedList& l) {
	Node* prev = nullptr;
	Node* curr = l.head;
	Node* next = nullptr;
	
	while (curr != nullptr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	l.head = prev;
}

void rotaciona(CircList& c, int k) {
	if (c.tail == nullptr || k <= 0 || c.size <= 1) {
		return;
	}
	int k_real = k % c.size;

	if (k_real == 0) {
		return;
	}
	int passos= c.size - k_real;

	for (int i = 0; i < passos; i++) {
		c.tail = c.tail->next;
	}
}
void enqueue_priority(DLinkedList& l, int data, int priority) {
    DNode* novo = new DNode(data, priority);
    l.size++;

    if (l.head == nullptr) {
        l.head = novo;
        l.tail = novo;
        if (priority == 1) l.priority_tail = novo;
        return;
    }

    if (priority == 1) {
        if (l.priority_tail == nullptr) {
            novo->next = l.head;
            l.head->prev = novo;
            l.head = novo;
            l.priority_tail = novo;
        } else {
            novo->next = l.priority_tail->next;
            novo->prev = l.priority_tail;
            
            if (l.priority_tail->next != nullptr) {
                l.priority_tail->next->prev = novo; 
            } else {
                l.tail = novo; 
            }
            
            l.priority_tail->next = novo;
            l.priority_tail = novo; 
        }
    } 
    else {
        novo->prev = l.tail;
        l.tail->next = novo;
        l.tail = novo;
    }
}
LinkedList merge(LinkedList& a, LinkedList& b) {
    LinkedList resultado;
    resultado.size = a.size + b.size;

    Node dummy(0); 
    Node* atual = &dummy;

    Node* ponteiroA = a.head;
    Node* ponteiroB = b.head;

    while (ponteiroA != nullptr && ponteiroB != nullptr) {
        if (ponteiroA->data <= ponteiroB->data) {
            atual->next = ponteiroA;          
            ponteiroA = ponteiroA->next;      
        } else {
            atual->next = ponteiroB;         
            ponteiroB = ponteiroB->next;      
        }
        atual = atual->next; 
    }

    if (ponteiroA != nullptr) {
        atual->next = ponteiroA;
    }
    if (ponteiroB != nullptr) {
        atual->next = ponteiroB;
    }

    resultado.head = dummy.next;
    
    a.head = nullptr; a.size = 0;
    b.head = nullptr; b.size = 0;

    return resultado;
}
bool tem_ciclo(const LinkedList& l) {
    if (l.head == nullptr) {
        return false; 
    }

    Node* tartaruga = l.head;
    Node* lebre = l.head;    

    while (lebre != nullptr && lebre->next != nullptr) {
        tartaruga = tartaruga->next;           
        lebre = lebre->next->next;             

        if (tartaruga == lebre) {
            return true;
        }
    }

    return false;
}

