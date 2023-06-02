#include <iostream>
#include <cstdlib>

class Node {
public:
    char val;
    Node* next;

    Node() = default;

    Node(char c) : val(c), next(nullptr) {}
};

class LinkedList {
public:
    Node* root;

    LinkedList() : root(nullptr) {}

    // Method to append a character to the end of the linked list
    void append(char c) {
        if (!root) root = new Node(c);
        else {
            Node* tmp = root;
            while (tmp->next) tmp = tmp->next;
            tmp->next = new Node(c);
        }
    }

    // Method to remove a character from the end of the linked list
    void removeEnd() {
        if (!root) return;
        Node* prev = nullptr, *curr = root;
        while (curr->next) {
            prev = curr;
            curr = curr->next;
        }
        if (!prev) {
            delete curr;
            root = nullptr;
        } else {
            prev->next = nullptr;
            delete curr;
        }
    }

    // Method to delete the whole list
    void clean() {
        Node* curr = root;
        while (curr) {
            Node* tmp = curr->next;
            delete curr;
            curr = tmp;
        }
        root = nullptr;
    }

    // Get the end character of list
    char getEnd() {
        if (!root) return '\0';
        Node* tmp = root;
        while (tmp->next) tmp = tmp->next;
        return tmp->val;
    }

};

class Stack {
private:
    // This is only a helper method
    bool cleanAndReturnFalseHelper() {
        clean();
        return false;
    }

public:
    LinkedList l;
    int size;

    Stack() : size(0), l(LinkedList()) {}

    // Method to push a character to the stack
    void push(char c) {
        l.append(c);
        ++ size;
    }

    // Method the pop a character out of the stack
    void pop() {
        l.removeEnd();
        -- size;
    }

    // Do nothing
    void noop() {
        return;
    }

    char top() {
        return l.getEnd();
    }

    // Method to remove every characters of the stack
    void clean() {
        l.clean();
        size = 0;
    }

    // Method to check whether a string is valid (have equal number of opening and closing parentheses) or not
    bool isValidString(std::string s) {
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') push(c);
            else if (c == ')' || c == ']' || c == '}') {
                if (size == 0) return cleanAndReturnFalseHelper();
                char topChar = top();
                switch(topChar) {
                case '(':
                    if (c == '}' || c == ']') return cleanAndReturnFalseHelper();
                    break;
                case '[':
                    if (c == '}' || c == ')') return cleanAndReturnFalseHelper();
                    break;
                case '{':
                    if (c == ')' || c == ']') return cleanAndReturnFalseHelper();
                    break;
                }
                pop();
            }
        }
        int tmp = size;
        clean();
        return (tmp == 0);
    }

};

int main() {

    Stack st = Stack();

    // Try some test cases
    std::cout << std::boolalpha;
    std::cout << st.isValidString("{{{{}}}[][]((())") << "\n";
    std::cout << st.isValidString("(%TT{>><]]]%%%%%%)") << "\n";
    std::cout << st.isValidString("(((((()))))){}{}{}[][][][[[]]]") << "\n";
    std::cout << st.isValidString("{{{@23+6767}}}*<45>(a+b)[]") << "\n";
    std::cout << st.isValidString("(a+b)") << "\n";
    std::cout << st.isValidString("(((((a+b %%%%%####3422222222222)))))[]{}[]") << "\n";
    std::cout << st.isValidString("[[[{{()}}]]]") << "\n";
    std::cout << st.isValidString("((((((}}}}}}") << "\n";
    std::cout << st.isValidString("Aaaaaaaa+bbbb({}{}{}[][][]tttttt + %^$)") << "\n";
    std::cout << st.isValidString("@@@@@@@@@@@@@@@@@@@@@@@$$%%T$%$%$$%{}()%%%%%%%%%%%%%%%%%%%%%%%%%%%%") << "\n";
    return 0;

}
