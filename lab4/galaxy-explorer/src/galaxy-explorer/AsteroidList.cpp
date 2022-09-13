#include <galaxy-explorer/AsteroidList.hpp>

// Constructor for list node
AsteroidListItem::AsteroidListItem() {
	this->next = nullptr;
	this->data = nullptr;
}

// Second constructor for list node
AsteroidListItem::AsteroidListItem(Asteroid a) {
	this->next = nullptr;
	this->data = new Asteroid(a); //dynamically allocated asteroid
}

// Destructor for list node
AsteroidListItem::~AsteroidListItem() {
    if (data != NULL) {
        delete data;
    }
}

// Constructor for linked list
AsteroidList::AsteroidList() {
}

// Copy constructor for linked list
AsteroidList::AsteroidList(const AsteroidList& src) {
    const AsteroidListItem* ptr = (src.head).getNext(); // to traverse list src
    AsteroidListItem* last = NULL; // to follow ptr in traversing src
    AsteroidListItem* nptr = NULL; // for access nodes in new list
    head.setNext(NULL); 
    while (ptr != NULL) {
        nptr = new AsteroidListItem(ptr->getData());
        if (last == NULL) { // for case when head of new list needs to be assigned
            head.setNext(nptr);
        } else {
            last->setNext(nptr);
        }
        ptr = ptr->getNext();
        last = nptr;
    }
}

// Destructor for linked list
AsteroidList::~AsteroidList() {
    AsteroidListItem* ptr; 
    while (head.getNext() != NULL) {
        ptr = head.getNext();
        head.setNext(ptr->getNext()); // head points to rest of list
        ptr->setNext(NULL);
        delete ptr;
    }
}

// Insert as first item in linked list
void AsteroidList::pushFront(Asteroid e) {
    AsteroidListItem* firstItem = new AsteroidListItem(e);
    firstItem->setNext(head.getNext());
    head.setNext(firstItem);
}

// For reference to first asteroid
Asteroid& AsteroidList::front() {
    if (head.getNext() == NULL) {
        return *(Asteroid*) NULL; // typecast for return
    }
    if (head.getNext() != NULL) {
        return ((head.getNext())->getData());
    }
    return *(Asteroid*) NULL;
}

const Asteroid& AsteroidList::front() const {
    if (head.getNext() == NULL) {
        return *(Asteroid*) NULL;
    }
    if (head.getNext() != NULL) {
        return ((head.getNext())->getData());
    }
    return *(Asteroid*) NULL;
}

// To check if list is has anything except for head
bool AsteroidList::isEmpty() const {
    if (head.getNext() == NULL) {    
        return true;
    }
    return false;
}

// For number of items in the list
int AsteroidList::size() const {
    int numItems = 0;
    const AsteroidListItem* ptr = head.getNext(); //pointer to traverse list
    while (ptr != NULL) {
        numItems = numItems + 1;
        ptr = ptr->getNext();
    }
    return numItems;
}

// To return position before first asteroid
AsteroidListItem* AsteroidList::beforeBegin() {
    return &head;
}

const AsteroidListItem* AsteroidList::beforeBegin() const {
    return &head;
}

// To return item corresponding to first asteroid
AsteroidListItem* AsteroidList::begin() {
    if (head.getNext() == NULL) {
        return end();
    }
    return head.getNext();
}

const AsteroidListItem* AsteroidList::begin() const {
        if (head.getNext() == NULL) {
        return end();
    }
    return head.getNext();
}

// To return an item corresponding to the position of the last asteroid
AsteroidListItem* AsteroidList::beforeEnd() {
    if (head.getNext() == NULL) {
        return beforeBegin();
    }
    AsteroidListItem* ptr = head.getNext(); //pointer to traverse
    while (ptr->getNext() != NULL) {
        ptr = ptr->getNext();
    }
    return ptr;
}

const AsteroidListItem* AsteroidList::beforeEnd() const {
    if (head.getNext() == NULL) {
        return beforeBegin();
    }
    const AsteroidListItem* ptr = head.getNext();
    while (ptr->getNext() != NULL) {
        ptr = ptr->getNext();
    }
    return ptr;
}

// To return the corresponding position immediately after the last asteroid
AsteroidListItem* AsteroidList::end() {
    return NULL;
}

const AsteroidListItem* AsteroidList::end() const {
    return NULL;
}

// To insert asteroid immediately after position prev
AsteroidListItem* AsteroidList::insertAfter(AsteroidListItem* prev, Asteroid e) {
    if (head.getNext() == NULL) { // if list is empty
        return NULL;
    }
    AsteroidListItem* ptr = head.getNext(); // pointer to traverse
    while (ptr != NULL ) {
        if (ptr == prev) {
            ptr = new AsteroidListItem(e);
            ptr->setNext(prev->getNext());
            prev->setNext(ptr);
            return ptr;
        }
        ptr = ptr->getNext();
    }
    return ptr;
}

AsteroidListItem* AsteroidList::insertAfter(AsteroidListItem* prev, const AsteroidList& others) {
    if (head.getNext() == NULL) { // if destination list is empty
        return NULL;
    }
    AsteroidListItem* ptr = head.getNext(); // pointer to traverse original list
    while (ptr != NULL){
        if (ptr == prev) {
            const AsteroidListItem* nptr = (others.head).getNext();
            while (nptr != NULL) { // pointer to traverse list to be added
                ptr = new AsteroidListItem(nptr->getData()); 
                ptr->setNext(prev->getNext());
                prev->setNext(ptr);
                prev = ptr;
                nptr = nptr->getNext();
            }
            return ptr;
        }
        ptr = ptr->getNext();
    }
    return ptr;
}

// Delete asteroid after prev
AsteroidListItem* AsteroidList::eraseAfter(AsteroidListItem* prev) {
    if (head.getNext() == NULL) { // if list is empty
        return NULL;
    }
    AsteroidListItem* ptr = head.getNext(); // pointer to traverse list
    while (ptr != NULL){
        if (ptr == prev) {
            ptr = prev->getNext();
            prev->setNext(ptr->getNext());
            delete ptr;
            if (prev->getNext() == NULL){
                return end();
            }
            return prev->getNext();
        }
        ptr = ptr->getNext();
    }
    return ptr;
}

// Delete list
void AsteroidList::clear() {
    AsteroidListItem* ptr; // pointer to traverse list
    while (head.getNext() != NULL) {
        ptr = head.getNext();
        head.setNext(ptr->getNext());
        ptr->setNext(NULL);
        delete ptr;
    }
}

// Make list independent copy of src
AsteroidList& AsteroidList::operator=(const AsteroidList& src) {
    if (this == &src){
        return *this; // same list
    }
    clear(); //destination destination list
    const AsteroidListItem* ptr = (src.head).getNext(); // pointer to traverse
    AsteroidListItem* last = NULL; // to follow ptr in traversing src
    AsteroidListItem* nptr = NULL; // for access nodes in new list
    head.setNext(NULL); 
    while (ptr != NULL) {
        nptr = new AsteroidListItem(ptr->getData());
        if (last == NULL) { // for case when head of new list needs to be assigned
            head.setNext(nptr);
        } else {
            last->setNext(nptr);
        }
        ptr = ptr->getNext();
        last = nptr;
    }
    return *this;
}