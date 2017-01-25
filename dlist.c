#include <stdlib.h>
#include <stdio.h>

#include "dlist.h"


//create dlist
dlist* create_dlist(void){
    dlist *list;
    
    if((list = malloc(sizeof(*list))) != NULL){
	list->head = NULL;
	list->tail = NULL;
	list->count = 0;
	return list;
    }else{
	printf("Error: Could not create dlist!\n");
	return NULL;
    }
}

//initialize list
int initialize_dlist(dlist *list, void *data){
    node *new_node;
    if((new_node = malloc(sizeof(*new_node))) != NULL){
	new_node->data = data;
	new_node->prev = NULL;
	new_node->next = NULL;
	list->head = new_node;
	list->tail = new_node;
	list->count++;
	return 1; //SUCCESS
    }
    return -1; //FAILURE
}

//is Empty
int is_empty(dlist *list){
    return (list->head == NULL);
}

//returns number of stored nodes in list
int node_count(dlist *list){
    return list->count;
}

//get node at index
node* get_node(dlist *list, int index){
    node *temp = list->head;
    while(index > 1){
	if(temp == NULL)
	    return temp;
	index--;
	temp = temp->next;
    }
    return temp;
}

//print dlist
void print_dlist(dlist *list){
    node *head = list->head;
    int *a;
    while(head != NULL){
	a = head->data;
	printf("{%p, [%d, %d, %d]}\n",head->data,a[0], a[1], a[2]);
	head = head->next;
    }
}

//prepend element
int prepend(dlist *list, void *data){
    node *new_node;
    if((new_node = malloc(sizeof(*new_node))) != NULL){
	new_node->data = data;
	new_node->prev = NULL;
	new_node->next = list->head;
	list->head->prev = new_node;
	list->head = new_node;
	list->count++;
	return 1; //SUCCESS
    }
    return -1; //ERROR
}

//append element
int append(dlist *list, void *data){
    node *new_node;
    if((new_node = malloc(sizeof(*new_node))) != NULL){
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = list->tail;
	list->tail->next = new_node;
	list->tail = new_node;
	list->count++;
	return 1; //SUCCESS
    }
    return -1; //ERROR
}

//

//insert element at index
int insert(dlist *list, void *data, int index){
    node *new_node;
    if((new_node = malloc(sizeof(*new_node))) != NULL){
	if(index == 0){
	    prepend(list, data);
	    return 1;
	}
	if(index == node_count(list)){
	    append(list, data);
	    return 1;
	}

	if(index <= node_count(list)){
	    node *left = get_node(list, index);
	    node *right = left->next;

	    new_node->data = data;
	    new_node->prev = left;
	    new_node->next = right;

	    left->next = new_node;
	    right->prev = new_node;
	    list->count++;
	    return 1;
	}
	free(new_node);
	printf("ERROR: index out of bounds!\tIndex: %d\tnode_count: %d\n",index, node_count(list));
	return -1; //ERROR
    }
    return -1; //ERROR
}

//delete element at index
int delete_node(dlist *list, int index){
    if(index < node_count(list)-1){
	node *delete = get_node(list, index);
	if(index == 0){
            list->head = list->head->next;
	    list->head->prev = NULL;
	   
	}else if(index == node_count(list)-1){
            list->tail = list->tail->prev;
	    list->tail->next = NULL;
	   
	}else{
	    node *left = delete->prev;
 	    node *right = delete->next;
	    left->next = right;
	    right->prev = left;
        }
	list->count--;
	free(delete);
	return 1;
    }
    printf("Error: Index out of bounds!\n");
    return -1;
}

