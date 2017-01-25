#ifndef DLIST_H
#define DLIST_H

typedef struct node node;

struct node{
    void* data;
    struct node *next;
    struct node *prev;
};

typedef struct dlist dlist;

struct dlist{
    struct node *head;
    struct node *tail;
    unsigned int count;
};

/**
 *    create
 */ 
dlist* create_dlist(void);

/**
 *    initialize list
 */ 
int initialize_dlist(dlist *list, void *data);

/*
 *    is Empty
 */ 
int is_empty(dlist *list);

/*
 *    returns number of nodes in dlist
 */ 
int node_count(dlist *list);

/**
 *    get node at index
 */ 
node* get_node(dlist *list, int index); 

/**
 *    print dlist
 */
void print_dlist(dlist *dlist);

/**
 *    prepend element to dlist
 */ 
int prepend(dlist *list, void *data);

/**
 *    append element to a existing dlist
 */ 
int append(dlist *list, void *data);

/**
 *    insert element at index
 */ 
int insert(dlist *list, void *data, int index);
/**
 *    delete
 */ 
int delete_node(dlist *list, int index);
#endif
