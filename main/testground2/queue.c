#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int x;
    struct Node* next;
} Node;

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

void insert_after(Node* node, int pos, int value)
{
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        exit(1);
    }
    Node* curr = node;
    while (curr->x != pos)
    {
        curr = curr->next;
    }


    new_node->x = value;
    new_node->next = curr->next;
    curr->next = new_node;

}

int main(int argc, char* argv[])
{

    // root = malloc(sizeof(Node));
    // root->x = 4;
    // Node* afterroot = malloc(sizeof(Node));
    // root->next = afterroot;
    // root->next->x = 5;
    Node* root = NULL; // start node type pointer to NULL

    insert_beginning(&root, 5);
    insert_beginning(&root, 4);
    insert_beginning(&root, 3);
    insert_beginning(&root, 2);
    insert_beginning(&root, 1);
    remove_element(&root, 3);


    insert_after(root, 5, 6);



    for (Node* curr = root; curr != NULL; curr = curr->next)
    {
        printf("%d\n", curr->x);

    }
    deallocate(&root);
    return 0;




}

