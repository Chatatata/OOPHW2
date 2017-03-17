
//  Buğra Ekuklu, 150120016

#ifndef ListDeclaration
#define ListDeclaration

template <typename T>
class List {
public:
    T operator [](unsigned int index) {
        //  Complementary operation
        index = _length - index - 1;
        
        Node *cursor = _head;
        
        for (unsigned int i = 0; i < index; ++i) {
            cursor = cursor->next;
        }
        
        return cursor->data;
    }
    
    void append(const T& object) {
        //  Append to first node
        Node *incoming = new Node(object);
        
        incoming->data = object;
        incoming->next = _head;
        
        _head = incoming;
        
        _length += 1;
    }
    
    unsigned int count() const {
        return _length;
    }
    
    ~List() {
        Node *cursor = _head;
        
        for (unsigned int i = 0; i < _length; ++i) {
            Node *next = cursor->next;
            
            delete cursor;
            
            cursor = next;
        }
    }
    
private:
    struct Node {
        Node(const T &data) : data(data) { }
        
        T data;
        Node *next;
    };
    
    Node *_head;
    unsigned int _length = 0;
};

#endif /* ListDeclaration */
