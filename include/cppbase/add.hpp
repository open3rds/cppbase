#include <utility>
namespace open3rds
{
    template <typename TypeA, typename TypeB>
    auto _addBase(TypeA &&a, TypeB &&b) noexcept -> decltype(a + b)
    {
        return a + b;
    }
    template <typename FirstType, typename... Args>
    auto _addBase(FirstType &&first, Args &&...args) noexcept
    {
        return _addBase(first, _addBase(args...));
    }
    template <typename... Args>
    auto add(Args &&...args) noexcept
    {
        return _addBase(std::forward<Args>(args)...);
    }
}