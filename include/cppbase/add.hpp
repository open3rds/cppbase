#include <utility>

namespace open3rds
{

    /// @brief Addable instnce can be performed binary operator `+`.
    ///        Say we have `Addable a, b;`, then `a + b` should compiles.
    template <typename T>
    concept Addable = requires(const T &a, const T &b) {
                          a + b;
                      };

    constexpr auto _addBase(Addable auto &&a, Addable auto &&b) noexcept -> decltype(a + b)
    {
        return a + b;
    }

    constexpr auto _addBase(Addable auto &&first, Addable auto &&...args) noexcept
    {
        return _addBase(first, _addBase(args...));
    }

    /// @brief Add multiple Addable instance using operator `+`.
    /// @param ...args A sequence of Addable instances, could be cross different type.
    /// @return Return type would be the same as the result of operator `+` performed sequentially on args.
    constexpr auto add(Addable auto &&...args) noexcept
    {
        return _addBase(std::forward<decltype(args)>(args)...);
    }
}