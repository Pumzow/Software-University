#include "List.h"
#include <stdexcept>

// Node class implementation
List::Node::Node(int value, Node* prev, Node* next) : value(value), prev(prev), next(next) {}

int List::Node::getValue() const {
    return value;
}

void List::Node::setValue(int value) {
    this->value = value;
}

List::Node* List::Node::getNext() const {
    return next;
}

void List::Node::setNext(Node* next) {
    this->next = next;
}

List::Node* List::Node::getPrev() const {
    return prev;
}

void List::Node::setPrev(Node* prev) {
    this->prev = prev;
}

// List class implementation
List::List() : head(nullptr), tail(nullptr), size(0) {}

List::List(const List& other) : head(nullptr), tail(nullptr), size(0) {
    Node* current = other.head;
    while (current != nullptr) {
        add(current->getValue());
        current = current->getNext();
    }
}

int List::first() const {
    if (isEmpty()) {
        throw std::out_of_range("List is empty");
    }
    return head->getValue();
}

void List::add(int value) {
    Node* newNode = new Node(value, tail, nullptr);
    if (tail != nullptr) {
        tail->setNext(newNode);
    }
    tail = newNode;
    if (head == nullptr) {
        head = newNode;
    }
    size++;
}

void List::addAll(const List& other) {
    Node* current = other.head;
    while (current != nullptr) {
        add(current->getValue());
        current = current->getNext();
    }
}

void List::removeFirst() {
    if (isEmpty()) {
        throw std::out_of_range("List is empty");
    }
    Node* temp = head;
    head = head->getNext();
    if (head != nullptr) {
        head->setPrev(nullptr);
    }
    else {
        tail = nullptr;
    }
    delete temp;
    size--;
}

void List::removeAll() {
    while (!isEmpty()) {
        removeFirst();
    }
}

size_t List::getSize() const {
    return size;
}

bool List::isEmpty() const {
    return size == 0;
}

List List::getReversed(List l) {
    List reversed;
    Node* current = l.tail;
    while (current != nullptr) {
        reversed.add(current->getValue());
        current = current->getPrev();
    }
    return reversed;
}

std::string List::toString() const {
    std::string result;
    Node* current = head;
    while (current != nullptr) {
        result += std::to_string(current->getValue()) + " ";
        current = current->getNext();
    }
    return result;
}

List& List::operator<<(const int& value) {
    add(value);
    return *this;
}

List& List::operator<<(const List& other) {
    addAll(other);
    return *this;
}

List& List::operator=(const List& other) {
    if (this != &other) {
        removeAll();
        addAll(other);
    }
    return *this;
}

List::~List() {
    removeAll();
}
