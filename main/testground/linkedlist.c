#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int x;
    struct Node* next;
} Node;


void insert_end(Node** root, int value)
{
    Node* new_node = malloc(sizeof(Node)); //Create the new node to add on the list
    if (new_node == NULL) // make sure the memory is properly allocated
    {
        exit(1);
    }
    //initialize node's values, new node's 'next' value is initialized to NULL.
    new_node->next = NULL; //this will identify it as last node in the list.
    new_node->x = value;

    if (*root == NULL) //check if there is already any nodes on the list.
    {
        *root = new_node; //set this new node as the head/root of the list.
        return; //end
    }

    Node* curr = *root; //start iterating from the root till finding the last node(it's 'next' variable has 'NULL' value)
    while (curr->next != NULL)
    {
        curr = curr->next; //set last iterated node as the current one.
    }
    curr->next = new_node; //once finding last node, set it's 'next' vaue to 'new_node' so this can become the new last node.

}

void insert_beginning(Node** root, int value)
{
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        exit(1);
    }
    new_node->x = value;
    new_node->next = *root;

    *root = new_node;

}

void insert_after(Node* node, int value)
{
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        exit(1);
    }

    new_node->x = value;
    new_node->next = node->next;
    node->next = new_node;

}

void insert_sorted(Node** root, int value)
{
    if (*root == NULL || (*root)->x >= value)
    {
        insert_beginning(root,value);
        return;
    }

    Node* curr = *root;
    while (curr->next != NULL)
    {
        if (curr->next->x >= value)
        {
            break;

        }
        curr = curr->next;

    }
    insert_after(curr, value);
}

void remove_element(Node** root, int value)
{
    if (*root == NULL)
    {
        return;
    }

    if ((*root)->x == value)
    {
        Node* to_remove = *root;
        *root = (*root)->next;
        free(to_remove);
        return;
    }

    for (Node* curr = *root; curr->next != NULL; curr = curr->next)
    {
        if (curr->next->x == value)
        {
            Node* to_remove = curr->next;
            curr->next = curr->next->next;
            free(to_remove);
            return;
        }
    }
}

void deallocate(Node** root)
{
    Node* curr = *root;
    while (curr != NULL)
    {
        Node * aux = curr;
        curr = curr->next;
        free(aux);
    }
    *root = NULL;
}

int main(int argc, char* argv[])
{
    Node* root = NULL; // start node type pointer to NULL


    // insert_end(&root, -2);
    // insert_end(&root, 11);

    // insert_beginning(&root, 13);

    // insert_after(root->next, 7);

    insert_sorted(&root, 5);
    insert_sorted(&root, 4);
    insert_sorted(&root, 1);
    insert_sorted(&root, 7);




     for (Node* curr = root; curr != NULL; curr = curr->next)
    {
        printf("%d\n", curr->x); //print until last element on the list(last item's next value is NULL).
    }
    deallocate(&root);

    return 0;



}

