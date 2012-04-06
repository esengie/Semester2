#ifndef PriorityList_H
#define PriorityList_H
/** Priority List Class

  Stores values starting with the largest integer priority
  */

template<class T>
class PriorityList
{
public:
    /// Exception Class
    class EmptyList {};
    PriorityList(): next(0), val(0), priority(0) {}
    ~PriorityList() { delete next; }
    void enqueue(const T&, int); ///< takes an element and a priority
    T dequeue() throw(EmptyList); ///< returns highest priority element
private:
    PriorityList* next;
    T val;
    int priority;

};

template<> inline
PriorityList<std::string>::PriorityList(): next(0), val(""), priority(0) {}

template<class T>
void PriorityList<T>::enqueue(const T & value, int prio)
{
    PriorityList* tmpx = new PriorityList();
    tmpx->val = value;
    tmpx->priority = prio;
    PriorityList* tmp = this;
    while (tmp->next && tmp->next->priority > tmpx->priority)
    {
        tmp = tmp->next;
    }
    tmpx->next = tmp->next;
    tmp->next = tmpx;
}

template<class T>
T PriorityList<T>::dequeue() throw(EmptyList)
{
    if (!next)
        throw EmptyList();
    T tmp = next->val;
    PriorityList* temp = next;
    next = next->next;
    temp->next = NULL;
    delete temp;
    return tmp;
}




#endif // PriorityList_H
