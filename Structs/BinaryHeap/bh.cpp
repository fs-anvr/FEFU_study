//я просто захотел написать минимальных класс бинарной кучи :D
//работает для численных типов данных, можно указать доп. параметром тип (min / max)

#include <iostream>

template<class T>
class BinaryHeap
{
protected:
    T *body;
    size_t max_size;
    size_t size;
    std::string type;

    void swap(int a, int b)
    {
        T temp = body[a];
        body[a] = body[b];
        body[b] = temp;
    }

public:
    explicit BinaryHeap(size_t max_size, std::string type = "min"): max_size(max_size), size(0), type(std::move(type))
    {
        body = new T[max_size+1];
        body[0] = INT_MIN;
    }

    T priorityElement()
    {
        return empty() ? body[0] : body[1];
    }

    bool empty()
    {
        return size == 0;
    }

    void insert(T node)
    {
        if (size > max_size)
            return;

        body[++size] = node;
        if (type == "min")
            for (int i = size; i > 1 && body[i] < body[i/2]; i /= 2)
            {
                swap(i, i / 2);
            }
        else
            for (int i = size; i > 1 && body[i] > body[i/2]; i /= 2)
            {
                swap(i, i / 2);
            }

    }

    T erase(int index = 1)
    {
        T element = body[index];
        body[index] = body[size--];
        for (;;)
        {
            int left = index * 2;
            int right = left + 1;
            int largest = index;

            if (type == "min")
            {
                if (left <= size && body[left] < body[index])
                    largest = left;
                if (right <= size && body[right] < body[largest])
                    largest = right;
            }
            else
            {
                if (left <= size && body[left] > body[index])
                    largest = left;
                if (right <= size && body[right] > body[largest])
                    largest = right;
            }

            if (largest == index)
                break;
            swap(index, largest);
            index = largest;
        }

        return element;
    }
};



int main()
{
    BinaryHeap<int> bh(10);
    bh.insert(71);
    bh.insert(10);
    bh.insert(100);
    bh.insert(45);

    std::cout << bh.erase() << std::endl;
    std::cout << bh.erase() << std::endl;
    std::cout << bh.erase() << std::endl;
    std::cout << bh.priorityElement() << std::endl;
    return 0;
}
