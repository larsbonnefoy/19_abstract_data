#pragma once

namespace ft {

template <bool B, typename T, typename F>
struct conditional {
        typedef T type;
};

template <typename T, typename F>
struct conditional <false, T, F> {
        typedef F type;
};

}
