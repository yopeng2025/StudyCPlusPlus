//iterator: imagine it as a "pointer" 
//called "iterator" because "iterating" = "looping"

template<typename T>
//⬇typename: avoid compiler warning, emphasizing it is a "type", not operator* or pointer*
typename T::iterator easyfind(T &container, int n)
{
    typename T::iterator it;
    
    it = std::find(container.begin(), container.end(), n);
    if (it == container.end())
        throw NotFound();
    return it;
}