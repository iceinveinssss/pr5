#include <iostream>
#include <string>

template <typename T>
class BinaryTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(T value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void insert(Node*& node, T value) {
        if (!node) {
            node = new Node(value);
        }
        else if (value < node->data) {
            insert(node->left, value);
        }
        else {
            insert(node->right, value);
        }
    }

    void inorder(Node* node) const {
        if (node) {
            inorder(node->left);
            std::cout << node->data << " ";
            inorder(node->right);
        }
    }

    void clear(Node* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    ~BinaryTree() {
        clear(root);
    }

    void insert(T value) {
        insert(root, value);
    }

    void inorder() const {
        inorder(root);
        std::cout << std::endl;
    }
};

int main()
{
    setlocale(0, "rus");
    BinaryTree<int> intTree;
    BinaryTree<std::string> stringTree;

    int choice;
    do {
        std::cout << "1. �������� ����� �����\n";
        std::cout << "2. �������� ������\n";
        std::cout << "3. �������� ��������������� ����� �����\n";
        std::cout << "4. �������� ��������������� ������\n";
        std::cout << "5. �����\n";
        std::cout << "��� �����: ";
        std::cin >> choice;

        if (choice == 1) {
            int value;
            std::cout << "������� ����� �����: ";
            std::cin >> value;
            intTree.insert(value);
        }
        else if (choice == 2) {
            std::string value;
            std::cout << "������� ������: ";
            std::cin >> value;
            stringTree.insert(value);
        }
        else if (choice == 3) {
            std::cout << "��������������� ����� �����: ";
            intTree.inorder();
        }
        else if (choice == 4) {
            std::cout << "��������������� ������: ";
            stringTree.inorder();
        }
    } while (choice != 5);

    return 0;
}
