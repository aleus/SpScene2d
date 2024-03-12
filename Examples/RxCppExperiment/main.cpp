#include "rxcpp/rx.hpp"

#include <iostream>
#include <memory>
#include <string>

namespace rx = rxcpp;
namespace rxsub = rxcpp::subjects;
namespace rxu = rxcpp::util;

int main()
{
    rxsub::subject<int> sub;
    auto o = sub.get_subscriber();
    auto source = sub.get_observable();

    auto l = [](int v) {
        printf("OnNext: %d\n", v);
    };

    auto sub0 = source.subscribe([](int v) { printf("OnNext: %d\n", v); },
                                 []() { printf("OnCompleted\n"); });
    auto sub1 = source.subscribe([](int v) { printf("OnNext 2: %d\n", v); },
                                 []() { printf("OnCompleted 2\n"); });
    auto sub2 = source.subscribe([](int v) { printf("OnNext 3: %d\n", v); },
                                 []() { printf("OnCompleted 3\n"); });

    for (int i = 0;; ++i) {
        switch (i) {
            case 1: i = 3; break;
        }
    }

    o.on_next(10);
    o.on_next(20);
    o.on_next(30);

    o.on_completed();

    return 0;
}
