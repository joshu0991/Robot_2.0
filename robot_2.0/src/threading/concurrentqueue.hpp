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

        node(const& T data) :
            data(data),
            next(nullptr),
            previous(nullptr)
        {
        }
    };
    
    std::atomic<boost::shared_ptr<node> > head;
    std::atomic<boost::shared_ptr<node> > tail;

public:

    ConcurrentQueue();

    void enqueue(const& T data)
    {
        boost::shared_ptr<node> new_node(new node(data));
        // Empty list scenerio
        if (head == NULL && tail == NULL)
        {
            // New node previous gets head
            new_node->previous = head.load();
            while(!head.compare_exchange_weak(new_node->next, new_node));
            tail->next = tail.load();
            while(!tail.compare_exchange_weak(new_node->next, new_node));
            return;
        }
        // If the list isn't empty we can just put the node inline FIFO ordering will be followed.
        std::atomic<boost::shared_ptr<node> > tempNode(nullptr);
        tempNode = tail->previous.load();
        tail->previous = new_node;
        new_node->next = tail;
        new_node->previous = tempNode;
        tempNode->next = new_node;
    }
};
