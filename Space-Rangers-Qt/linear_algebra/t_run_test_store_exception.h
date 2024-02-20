#ifndef T_RUN_TEST_STORE_EXCEPTION_H
#define T_RUN_TEST_STORE_EXCEPTION_H

#include <vector>
#include <iostream>
#include <set>


template <typename ...t_arguments>
inline void run_test_store_exceptions(std::vector<std::runtime_error>& exceptions, void (*testable)(t_arguments ...), t_arguments ...arguments) {
    try {
        testable(std::forward<t_arguments>(arguments) ...);
    }
    catch (const std::runtime_error& exception) {
        exceptions.emplace_back(std::move(exception));
    }
}

struct t_mesure_cache {
    std::string_view name;
    size_t minimum {};
    size_t maximum {};
    size_t total   {};
};

struct t_mesure_cache_comparator {
    bool operator()(const t_mesure_cache& lhs, const t_mesure_cache& rhs) const {
        if (lhs.minimum == rhs.minimum && lhs.maximum == rhs.maximum) {
            return lhs.total < rhs.total;
        }

        if (lhs.minimum == rhs.minimum) {
            return lhs.maximum < rhs.maximum;
        }

        return lhs.minimum < rhs.minimum;
    }
};

using t_cache_array = std::multiset<t_mesure_cache, t_mesure_cache_comparator>;

void print(const t_cache_array cache_array) {
    for (const t_mesure_cache& mesure : cache_array) {
        std::cout << mesure.name
                  << " Times:"
                  << " minimum: " << mesure.minimum << " [ns]"
                  << " maximum: " << mesure.maximum << " [ns]"
                  << " total: "   << mesure.total   << " [ns]"
                  << std::endl;
    }
}

template <typename ...t_arguments>
void mesure(t_cache_array& cache_array, std::string_view name, size_t tries/*, bool (system)(const t_2d_vector_entity& lhs, const t_2d_vector_entity& rhs)*/) {

    size_t maximum { std::numeric_limits<size_t>::min() };
    size_t minimum { std::numeric_limits<size_t>::max() };
    size_t total {};

    // const t_2d_vector_entity& lhs { 1, 1 };
    // const t_2d_vector_entity& rhs { 2, 2 };

    for (size_t _ {}; _ < tries; ++ _) {

        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        // system(lhs, rhs);
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

        size_t elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();

        if (maximum < elapsed) { maximum = elapsed; }

        if (minimum > elapsed) { minimum = elapsed; }

        total += elapsed;
    }

    cache_array.emplace(t_mesure_cache { name, minimum, maximum, total });

    // std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
}

#endif // T_RUN_TEST_STORE_EXCEPTION_H
