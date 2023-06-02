#include <iostream>
#include <cstdlib>
#include <stack>
#include <chrono>

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
public:
    LinkedList l;
    int sz;

    Stack() : sz(0), l(LinkedList()) {}

    // Method to push a character to the stack
    void push(char c) {
        l.append(c);
        ++ sz;
    }

    // Method the pop a character out of the stack
    void pop() {
        l.removeEnd();
        -- sz;
    }

    // Do nothing
    void noop() {
        return;
    }

    char top() {
        return l.getEnd();
    }

    // Get the size of the stack
    int size() {
        return sz;
    }

};

// Function to check whether a string is valid (have equal number of opening and closing parentheses) or not using my own stack
bool isValidString(std::string s) {
    Stack st = Stack();
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') st.push(c);
        else if (c == ')' || c == ']' || c == '}') {
            if (st.size() == 0) return false;
            char topChar = st.top();
            switch(topChar) {
            case '(':
                if (c == '}' || c == ']') return false;
                break;
            case '[':
                if (c == '}' || c == ')') return false;
                break;
            case '{':
                if (c == ')' || c == ']') return false;
                break;
            }
            st.pop();
        }
    }
    int tmp = st.size();
    return (tmp == 0);
}

// Function to check whether a string is valid (have equal number of opening and closing parentheses) or not using the standard library stack
bool isValidStringStl(std::string s) {
    std::stack<int> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') st.push(c);
        else if (c == ')' || c == ']' || c == '}') {
            if (st.size() == 0) return false;
            char topChar = st.top();
            switch(topChar) {
            case '(':
                if (c == '}' || c == ']') return false;
                break;
            case '[':
                if (c == '}' || c == ')') return false;
                break;
            case '{':
                if (c == ')' || c == ']') return false;
                break;
            }
            st.pop();
        }
    }
    int tmp = st.size();
    return (tmp == 0);
}

// Number of function calls to compare_runtime
int no = 1;

// Function to compare runtime
void compare_runtime(std::string s) {

    std::cout << "Test case: " << s << "\n";
    auto start = std::chrono::steady_clock ::now();
    isValidString(s);
    auto stop = std::chrono::steady_clock ::now();
    std::cout << "\tUsing my own stack: " << std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count() << " ms\n";
    start = std::chrono::steady_clock ::now();
    isValidStringStl(s);
    stop = std::chrono::steady_clock ::now();
    std::cout << "\tUsing standard library's stack: " << std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count() << " ms\n";

}

int main() {

    // Compare runtime
    compare_runtime("{{{{}}}[][]((())");
    compare_runtime("(%TT{>><]]]%%%%%%)");
    compare_runtime("(((((()))))){}{}{}[][][][[[]]]");
    compare_runtime("{{{@23+6767}}}*<45>(a+b)[]");
    compare_runtime("(((((a+b %%%%%####3422222222222)))))[]{}[]");
    compare_runtime("[[[{{()}}]]]");
    compare_runtime("((((((}}}}}}");
    compare_runtime("Aaaaaaaa+bbbb({}{}{}[][][]tttttt + %^$)");
    compare_runtime("@@@@@@@@@@@@@@@@@@@@@@@$$%%T$%$%$$%{}()%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
    compare_runtime("@@@@@@@@@@@@@@@@@@@@@@@$$%%%%%%%####3422222222222))))");
    compare_runtime("{{{{}}}[][sdfsdg3345{[[[[]}]((())");
    compare_runtime("34235]]]}})_{{sa{{}}}[][]((())");
    compare_runtime("{{dsafaswwwwwwwwwwwwwwwwwwwwwwwwwwwwww{{}}}[][]((***)())");
    compare_runtime("(((((()))))){[[]]{}}{}{}[][][][[[]]]");
    compare_runtime("{{{{}}}[355----++++][]((())");


    // Uncomment the below code the try some test cases
//    std::cout << std::boolalpha;
//    std::cout << isValidString("(%TT{>><]]]%%%%%%)") << "\n";
//    std::cout << isValidString("(((((()))))){}{}{}[][][][[[]]]") << "\n";
//    std::cout << isValidString("{{{@23+6767}}}*<45>(a+b)[]") << "\n";
//    std::cout << isValidString("(a+b)") << "\n";
//    std::cout << isValidString("(((((a+b %%%%%####3422222222222)))))[]{}[]") << "\n";
//    std::cout << isValidString("[[[{{()}}]]]") << "\n";
//    std::cout << isValidString("((((((}}}}}}") << "\n";
//    std::cout << isValidString("Aaaaaaaa+bbbb({}{}{}[][][]tttttt + %^$)") << "\n";
//    std::cout << isValidString("@@@@@@@@@@@@@@@@@@@@@@@$$%%T$%$%$$%{}()%%%%%%%%%%%%%%%%%%%%%%%%%%%%") << "\n";
//
//    std::cout << isValidStringStl("{{{{}}}[][]((())") << "\n";
//    std::cout << isValidStringStl("(%TT{>><]]]%%%%%%)") << "\n";
//    std::cout << isValidStringStl("(((((()))))){}{}{}[][][][[[]]]") << "\n";
//    std::cout << isValidStringStl("{{{@23+6767}}}*<45>(a+b)[]") << "\n";
//    std::cout << isValidStringStl("(a+b)") << "\n";
//    std::cout << isValidStringStl("(((((a+b %%%%%####3422222222222)))))[]{}[]") << "\n";
//    std::cout << isValidStringStl("[[[{{()}}]]]") << "\n";
//    std::cout << isValidStringStl("((((((}}}}}}") << "\n";
//    std::cout << isValidStringStl("Aaaaaaaa+bbbb({}{}{}[][][]tttttt + %^$)") << "\n";
//    std::cout << isValidStringStl("@@@@@@@@@@@@@@@@@@@@@@@$$%%T$%$%$$%{}()%%%%%%%%%%%%%%%%%%%%%%%%%%%%") << "\n";


    return 0;

}
