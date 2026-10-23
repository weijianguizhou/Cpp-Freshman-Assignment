Stack::Stack(const double* arr, int n) {
    topNode = nullptr;
    stackSize = 0;
    for (int i = 0; i < n; i++) {
        push(arr[i]);
    }
}

Stack::Stack(const Stack& s) {
    topNode = nullptr;
    stackSize = 0;
    Node* current = s.topNode;
    Node* newNode;
    Node* tail = nullptr;
    while (current != nullptr) {
        newNode = new Node;
        newNode->data = current->data;
        newNode->next = nullptr;
        if (tail == nullptr) {
            topNode = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        current = current->next;
        stackSize++;
    }
}

Stack::~Stack() {
    Node* current = topNode;
    Node* next;
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
    stackSize = 0;
}

void Stack::push(const double& n) {
    Node* newNode = new Node;
    newNode->data = n;
    newNode->next = topNode;
    topNode = newNode;
    stackSize++;
}

void Stack::pop() {
    if (!isEmpty()) {
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        stackSize--;
    }
}

const double& Stack::top() const {
    if (!isEmpty()) {
        return topNode->data;
    }
    static double dummy = 0;
    return dummy;
}

bool Stack::isEmpty() const {
    return stackSize == 0;
}

int Stack::size() const {
    return stackSize;
}

void Stack::print() const {
    Node* current = topNode;
    std::cout << "Stack (top to bottom): ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

