#include <optional>
template<typename T>

bool is_sorted(const std::vector<T>& vec)
{
    if (vec.size() < 2) {
        return true;
    }

    for (size_t i = 1; i < vec.size(); i++) {
        if (vec[i]<vec[i-1]) {
            return false; 
        }
    }
    return true;
}
