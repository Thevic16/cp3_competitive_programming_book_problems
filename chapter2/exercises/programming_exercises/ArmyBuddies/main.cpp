#include <bits/stdc++.h>

using namespace std;

// https://vjudge.net/problem/UVA-12356

/*
 creo que la solucion mas sencilla e eficinte simplemente es mantener dos indices R Y L del right most number
 y el left most number de los casos que te dan.

 y en casa peticion retornar r-1 valor y l+1 valor si existe claro
*/

// structure to define a node of the doubly linked list in C++
struct node{

// part which will store data
    int data;
    // pointer to the previous node
    struct node *prev;
    // pointer to the next node
    struct node *next;

};

// function to insert a new node with given data in the front of the doubly linked list
void insert_at_end(node** head, int data){

    // create a new node with given data
    node* new_node = new node();
    new_node->data = data;

    // assign next pointer to NULL
    new_node->next = NULL;

    // if linked list is empty
    if((*head) == NULL){
        // this is the only node in the list
        new_node->prev = NULL;

        *head = new_node;
        return;
    }

    node* end = (*head);

    // travel to the end of the list
    while(end->next != NULL){
        end = end->next;
    }

    // assign the new node after the end node
    end->next = new_node;

    // assign previous of new node to the current end node
    new_node->prev = end;

    return;
}


// function to delete given node
void delete_given_node(node** head, node* given_node){

    // if the given node is head node
    if(given_node == (*head)){
        // change head to next node
        (*head) = given_node->next;

        if(*head != NULL){
            (**head).prev = NULL;
        }

        return;
    }

    // set the node before given node to point to node after given node
    given_node->prev->next = given_node->next;

    // given node was last node
    if(given_node->next == NULL){
        return;
    }

    // set the node after the given node to point to node before given node
    given_node->next->prev = given_node->prev;

    return;
}


// function to search given target
pair<int, int> searchAndDeleteRange(node** head, int L, int R){

    // node to traverse the linked list
    node* temp = (*head);
    bool firstTime = false;
    int firstSurvivorL = -1;
    int firstSurvivorR = -1;

    // loop over the list
    while(temp != NULL && temp->data <= R){

        if(temp->data >= L && temp->data <= R){

            if(!firstTime){
                firstTime = true;

                if(temp->prev != NULL){
                    firstSurvivorL = temp->prev->data;
                }
            }

            if(temp->next != NULL){
                firstSurvivorR = temp->next->data;
            }
            else {
                firstSurvivorR = -1;
            }

            delete_given_node(head, temp);
        }

        // go to next node
        temp = temp->next;
    }

  pair<int, int> result;
  result.first = firstSurvivorL;
  result.second = firstSurvivorR;

  return result;
}

void printTestCase(pair<int, int> survivors){
    if(survivors.first != -1 && survivors.second != -1){
        cout << survivors.first << " " << survivors.second << endl;
    }
    else if(survivors.first != -1){
        cout << survivors.first << " " << "*" << endl;
    }
    else if(survivors.second != -1){
        cout << "*" << " " << survivors.second << endl;
    }
    else {
        cout << "*" << " " << "*" << endl;
    }

    return;
}


void generateSoldier(int S, node** soldiers){
    for (int i = 1; i < S + 1; ++i) {
        insert_at_end(soldiers, i);
    }

    return;
}


int main() {
    int S, B;

    while(cin >> S >> B){
        if(S == 0 && B == 0){
            return 0;
        }

        // create a pointer to the head node
        node *soldiers = NULL;
        generateSoldier(S, &soldiers);

        for (int i = 0; i < B; ++i) {
            int L, R;
            cin >> L >> R;

            pair<int, int> survivors = searchAndDeleteRange(&soldiers, L, R);
            printTestCase(survivors);
        }

        cout << "-" << endl;
    }


    return 0;
}
