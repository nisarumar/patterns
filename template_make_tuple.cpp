#include <iostream>
#include <array>
#include <tuple>
#include <type_traits>

// convert array into a tuple
template<typename Array, std::size_t... I>
auto a2t_impl(const Array& a, std::index_sequence<I...>)
{
    return std::make_tuple(a[I]...);
}
 
template<typename T, std::size_t N, typename Indices = std::make_index_sequence<N>>
auto a2t(const std::array<T, N>& a)
{
    return a2t_impl(a, Indices{});
}


int main()
{
    std::array<int, 4> array = {1, 2, 3, 4};
    auto tuple = a2t(array);
    return 0;
}
