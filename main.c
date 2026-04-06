#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

// Node structure
struct Node
{
    char name[50];
    struct Node *children[MAX];
    int childCount;
};

// Create Node
struct Node *createNode(char name[])
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->childCount = 0;
    for (int i = 0; i < MAX; i++)
        newNode->children[i] = NULL;
    return newNode;
}

// Add Child (CREATE)
void addChild(struct Node *parent, char name[])
{
    if (parent->childCount < MAX)
    {
        parent->children[parent->childCount++] = createNode(name);
    }
    else
    {
        printf("Max children limit reached!\n");
    }
}

// Display Tree (READ)
void display(struct Node *root, int level)
{
    if (root == NULL)
        return;

    for (int i = 0; i < level; i++)
        printf("  ");

    printf("- %s\n", root->name);

    for (int i = 0; i < root->childCount; i++)
    {
        display(root->children[i], level + 1);
    }
}

// Search Node
struct Node *search(struct Node *root, char name[])
{
    if (root == NULL)
        return NULL;

    if (strcmp(root->name, name) == 0)
        return root;

    for (int i = 0; i < root->childCount; i++)
    {
        struct Node *found = search(root->children[i], name);
        if (found != NULL)
            return found;
    }
    return NULL;
}

// Update Node (UPDATE)
void updateNode(struct Node *root, char oldName[], char newName[])
{
    struct Node *node = search(root, oldName);
    if (node != NULL)
    {
        strcpy(node->name, newName);
        printf("Updated successfully!\n");
    }
    else
    {
        printf("Node not found!\n");
    }
}

// Delete Node (DELETE - simple version)
void deleteNode(struct Node *parent, char name[])
{
    for (int i = 0; i < parent->childCount; i++)
    {
        if (strcmp(parent->children[i]->name, name) == 0)
        {
            free(parent->children[i]);

            for (int j = i; j < parent->childCount - 1; j++)
            {
                parent->children[j] = parent->children[j + 1];
            }
            parent->childCount--;
            printf("Deleted successfully!\n");
            return;
        }
    }
    printf("Node not found!\n");
}

// Main Menu
int main()
{
    struct Node *root = createNode("Marketing Funnel");

    int choice;
    char parentName[50], name[50], newName[50];

    while (1)
    {
        printf("\n--- Marketing Funnel Menu ---\n");
        printf("1. Add Stage\n");
        printf("2. Display Funnel\n");
        printf("3. Update Stage\n");
        printf("4. Delete Stage\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            printf("Enter parent stage: ");
            scanf("%s", parentName);

            struct Node *parent = search(root, parentName);

            if (parent != NULL)
            {
                printf("Enter new stage name: ");
                scanf("%s", name);
                addChild(parent, name);
            }
            else
            {
                printf("Parent not found!\n");
            }
            break;

        case 2:
            printf("\nMarketing Funnel Structure:\n");
            display(root, 0);
            break;

        case 3:
            printf("Enter old name: ");
            scanf("%s", oldName);
            printf("Enter new name: ");
            scanf("%s", newName);
            updateNode(root, oldName, newName);
            break;

        case 4:
            printf("Enter parent name: ");
            scanf("%s", parentName);

            parent = search(root, parentName);

            if (parent != NULL)
            {
                printf("Enter node to delete: ");
                scanf("%s", name);
                deleteNode(parent, name);
            }
            else
            {
                printf("Parent not found!\n");
            }
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}