#include <atomic>
#include <cstddef>

#include <boost/shared_ptr.hpp>

template<typename T>
class ConcurrentQueue
{
    struct node
    {
        T data;
        boost::shared_ptr<node> next;
        boost::shared_ptr<node> previous;

        node(T const& data) :
            data(data),
            next(new node(NULL)),
            previous(new node(NULL))
        {
        }
    };
    
    std::atomic<boost::shared_ptr<node> > head;
    std::atomic<boost::shared_ptr<node> > tail;

public:

    ConcurrentQueue();

    void enqueue(T const& data)
    {
        boost::shared_ptr<node> new_node(new node(data));
        // Empty list scenerio
        if (head == NULL && tail == NULL)
        {
            head->next = new_node;
            tail->previous = new_node;
            new_node->next = tail;
            new_node->previous = head;
        }
        // If the list isn't empty we can just put the node inline FIFO ordering will be followed.
        boost::shared_ptr<node> tempNode(new node(NULL));
        tempNode = tail->previous;
        tail->previous = new_node;
        new_node->next = tail;
        new_node->previous = tempNode;
        tempNode->next = new_node;
    }
};
