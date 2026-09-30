//tpp: Template implementation / Template Plus Plus
//included by .hpp, function as the implementation of class template
//without this, we can only put implementation in .hpp

template <typename T>
Array<T>::Array(): elements(NULL), n(0) {}

template <typename T>
Array<T>::Array(unsigned int n): n(n)
{
        elements = new T[n](); //():Value-initialization T[0]=0 T[1]=0 ...
}

template <typename T>
Array<T>::~Array() 
{
    delete[] elements;      
}
 //RAII(Resource Acquisition Is Initialization) 
 //new[] && delete[]
 //only exist in c++98 (pros: 1.no heavy garbage collection 2.control specific time to free memory)
 //c++11 std::vector std::unique_ptr can automatically delete in destructor

template <typename T>
Array<T>::Array(const Array& other): elements(NULL), n(0)
{
    *this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        delete[] elements;
        n = other.n;
        if (n > 0)
        {
            elements = new T[n];
            for (unsigned int i = 0; i < n; i++)
                elements[i] = other.elements[i];
        }
        else
            elements = NULL;
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
    if (i >= n || !elements)            //in case of n=0(!element), type in element[0] 
        throw Array<T>::OutOfBounds();
    return elements[i];
} 

template <typename T>
const T& Array<T>::operator[](unsigned int i) const
{
    if (i >= n || !elements)
        throw Array<T>::OutOfBounds();
    return elements[i];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return n;
}

