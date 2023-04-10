#include <stdio.h>

int complete_node = 15;
char tree[] = {'\0', 'D', 'A', 'F', 'E', 'B', 'R', 'T', 'G', 'Q', '\0',
               '\0', 'V', '\0', 'J', 'L'};

int get_parent(int index)
{
    if (tree[index] != '\0' && index > 1 && index <= complete_node)
        return index / 2;
    return -1;
}

int get_right_child(int index)
{
    if (tree[index] != '\0' && ((2 * index) + 1) <= complete_node)
        return (2 * index) + 1;
    return 0;
}

int get_left_child(int index)
{
    if (tree[index] != '\0' && (2 * index) <= complete_node)
        return 2 * index;
    return 0;
}

void preorder(int index)
{
    if (index > 0 && tree[index] != '\0')
    {
        printf(" %c ", tree[index]);      // visiting root
        preorder(get_left_child(index));  // visiting left subtree
        preorder(get_right_child(index)); // visiting right subtree
    }
}
void postorder(int index)
{
    if (index > 0 && tree[index] != '\0')
    {
        postorder(get_left_child(index));  // visiting left subtree
        postorder(get_right_child(index)); // visiting right subtree
        printf(" %c ", tree[index]);       // visiting root
    }
}

void inorder(int index)
{
    if (index > 0 && tree[index] != '\0')
    {
        inorder(get_left_child(index));  // visiting left subtree
        printf(" %c ", tree[index]);     // visiting root
        inorder(get_right_child(index)); // visiting right subtree
    }
}
int is_leaf(int index)
{
    if (!get_left_child(index) && !get_right_child(index))
        return 1;
    if (tree[get_left_child(index)] == '\0' &&
        tree[get_right_child(index)] == '\0')
        return 1;
    return 0;
}
int get_max(int a, int b)
{
    return (a > b) ? a : b;
}

int get_height(int index)
{
    if (tree[index] == '\0' || index <= 0 || is_leaf(index))
        return 0;
    return (get_max(get_height(get_left_child(index)), get_height(get_right_child(index))) + 1);
}

int main()
{
    printf("Preorder: ");
    preorder(1);
    printf("\nPostorder: ");
    postorder(1);
    printf("\nInorder: ");
    inorder(1);
    printf("\n");
    printf("Index of Parent of first Index: %d\n", get_parent(1));
    printf("Check if index 2 is leaf: %d\n", is_leaf(2));
    printf("Height: %d\n", get_height(1));
    return 0;
}
