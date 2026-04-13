#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct node {
  int data;
  struct node* next;
  struct node* prev;
};
typedef struct node Node;

Node* createNode(int initVal){
  Node* n = malloc(sizeof(Node));
  if (!n) return NULL;

  n->data = initVal;
  n->next = NULL;
  n->prev = NULL;
  return n;
}

int pushAtHead(Node** binRef, int initVal){
  Node* new_node = createNode(initVal);
  if (!new_node) return -1;

  /* Check empty list. */
  Node* fake_node = *binRef;
  if (fake_node->next == fake_node){
    new_node->next = fake_node->prev;
    new_node->prev = fake_node->next;
    fake_node->next = new_node;
    fake_node->prev = new_node;
    return 0;
  }

  /* List with one or more nodes. */

  // Step1: Modify the links of the new node.
  new_node->next = fake_node->next;
  new_node->prev = fake_node;

  // Step2: Modify the links of the existing head node.
  (fake_node->next)->prev = new_node;

  // Step3: Modify the links of the fake node.
  fake_node->next = new_node;

  return 0;
}

int pushAtTail(Node** binRef, int initVal){
  Node *new_node = createNode(initVal);
  if (!new_node){ return -1;}

  /* Check empty list. */
  Node* fake_node = *binRef;
  if (fake_node->next == fake_node){
    fake_node->next = new_node;
    fake_node->prev = new_node;
    new_node->next = fake_node;
    new_node->prev = fake_node;
    return 0;
  }

  /* List with one or more nodes. */

  // Step1: Modify the new node's links
  new_node->prev = fake_node->prev;
  new_node->next = fake_node;

  // Step2: Modify the existing tail node's next link.
  (fake_node->prev)->next = new_node;

  // Step3: Modify the fake node's prev link.
  fake_node->prev = new_node;

  return 0;
}

void displayFromHead(Node** binRef){
  Node* fake_node = *binRef;
  if (fake_node->next == fake_node) return;

  int i = 0;
  Node* tmp = fake_node->next;
  do {
    printf("Node%d: %d\n", i, tmp->data);
    i++;
    tmp = tmp->next;
  } while(tmp != fake_node);
}

void displayFromTail(Node** binRef){
  Node* fake_node = *binRef;
  if (fake_node->next == fake_node)  return;

  Node* tmp = fake_node->next;
  do {
    printf("NodeValue: %d\n", tmp->data);
    tmp = tmp->next;
  } while (tmp != fake_node);
}

int deleteFromHead(Node** binRef){
  /* Empty list check. */
  Node* fake_node = *binRef;
  if (fake_node->next == fake_node)  return -1;

  /* Single node list. */
  Node* cur_head = fake_node->next;
  if (cur_head->next == fake_node){
    fake_node->next = fake_node;
    fake_node->prev = fake_node;
    free(cur_head);
    return 0;
  }

  /* List with more than one node. */

  // Step1: Modify the prev link of the node next to the current head node
  (cur_head->next)->prev = fake_node;

  // Step2: Modify the fake node's next link.
  fake_node->next = cur_head->next;

  // Step3: Release the current head node.
  free(cur_head);
}

int deleteFromTail(Node** binRef){
  /* Empty list check. */
  Node* fake_node = *binRef;
  if (fake_node->next == fake_node)  return -1;

  /* Single node list. */
  Node* cur_tail = fake_node->prev;
  if (cur_tail->prev == fake_node){
    fake_node->prev = fake_node;
    fake_node->next = fake_node;
    free(cur_tail);
    return 0;
  }

  /* List with more than one node. */

  // Step1: Modify the fake node's prev link.
  fake_node->prev = cur_tail->prev;

  // Step2: Modify the next link of the node previous to the last node.
  (cur_tail->prev)->next = fake_node;

  // Step3: free(cur_tail)
  free(cur_tail);
}

int initListHeaders(Node** listHdrs, int listCount){
  if (!listHdrs)  return -1;
  for (int i=0; i<listCount; i++){
    Node* fake_node = (Node*)((char*)(&listHdrs[i*2])-8);
    fake_node->next = fake_node;
    fake_node->prev = fake_node;
  }
  return 0;
}

int main(void){
  long long int listCount = 10;
  Node* listHeaders[listCount*2];
  initListHeaders(listHeaders, listCount);

  Node* binRef = (Node*)((char*)(&listHeaders[0])-8);
  pushAtHead(&binRef, 5);
  pushAtHead(&binRef, 6);
  pushAtHead(&binRef, 7);
  pushAtHead(&binRef, 8);
  pushAtHead(&binRef, 9);
  pushAtTail(&binRef, 10);
  pushAtTail(&binRef, 11);
  pushAtTail(&binRef, 12);
  pushAtTail(&binRef, 13);
  pushAtTail(&binRef, 14);
  deleteFromHead(&binRef);
  deleteFromTail(&binRef);
  displayFromTail(&binRef);
}
