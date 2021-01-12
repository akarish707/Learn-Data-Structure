#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
cheryl 100 -> ann 95 -> Chika 92
*/
struct Node{
    char name[255];
    int score;//menunjuk ke node selanjutnya
    Node *next;//global variabelnya,head and tail
} *head,*tail;
//head menunjuk ke node pertama dalam linked list
//tail menunjuk ke node terakhir dalam linke list
Node *createNode(const char *name,int score){
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name,name);
    newNode->score = score;
    newNode->next = NULL;
    return newNode;
}

//push head,push tail
void pushHead(const char *name, int score){
    //1. buat dulu nodenya
    //2. cek kondisi
    // jika tidak ada head,maka nodenya akan menjadi head dan tail
    // jika ada head, node akan menjadi head baru dan node->next = head lama
    Node *temp = createNode(name,score);
    if(!head){// jika tidak aada head, maka nodenya akan menjadi head dan tail
        head = temp;
        tail = temp;
    } else{
        temp->next = head;//node menunjuk ke head yang lama
        head = temp; //node akan menjadi head yang baru
    }
}

void pushTail(const char *name, int score){
        Node *temp = createNode(name,score);
    if(!head){// jika tidak aada head, maka nodenya akan menjadi head dan tail
        head = tail = temp;
    } else{
        tail->next = temp;//node menunjuk ke head yang lama
        tail = temp; //node akan menjadi head yang baru
    }
}

void popHead(){
    if(!head){//jika tidak ada head
      return; // langsung return aja
    }else if(head == tail){//kalau node cuman 1
        free(head);
        head = tail = NULL;
    }else{// 53(head) -> 70 -> 40 -> 25
        Node *temp = head->next;// 53(head) -> 70 (temp)-> 40 -> 25
        head->next = NULL;// 53(head) -> NULL|| 70(temp) -> 40 -> 25
        free(head);
        head = NULL;
    } 
    //karena temp local;
    // // 70 (head) -> 40 -> 25

    // cheryl (head,tail)-> NULL
    //Node *temp = head -> next; //cheryl (head,tail) -> NULL (temp)
    //head

}

void popTail(){
    if(!head){//jika tidak ada head
      return; // langsung return aja
    }else if(head == tail){//kalau node cuman 1
        free(head);
        head = tail = NULL;
    }else{// 53(head) -> 70 -> 40 -> 25
        Node *temp = head;// 53(head) -> 70 (temp)-> 40 -> 25
        //head->next = NULL;// 53(head) -> NULL|| 70(temp) -> 40 -> 25
        while(temp->next != tail){
            temp = temp->next;//jalan terus
        }
        temp -> next = NULL;
        free(tail);
        tail = temp;
    } 
    //karena temp local;
    // // 70 (head) -> 40 -> 25

    // cheryl (head,tail)-> NULL
    //Node *temp = head -> next; //cheryl (head,tail) -> NULL (temp)
    //head

}

void printLinkedList() {
  Node *curr = head; // set current node to head
                                          
  while(curr) { // while there is still curr
    if(curr==head){
        printf("(tail)");
    }
    printf("%s %d-> ", curr->name, curr->score);
    curr = curr->next; // move to the next node
  }
  puts("NULL");
}

int main(){
    pushHead("Cheryl",100);
    pushTail("Ann",97);
    pushTail("Chika",95);
    printLinkedList();   
    return 0;
}