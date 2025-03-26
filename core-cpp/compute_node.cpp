#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <future>
#include <queue>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue {
private:
    mutable std::mutex mut;
    std::queue<std::shared_ptr<T>> data_queue;
    std::condition_variable data_cond;
public:
    ThreadSafeQueue() {}
    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]{return !data_queue.empty();});
        value = std::move(*data_queue.front());
        data_queue.pop();
    }
    bool try_pop(std::shared_ptr<T>& value) {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty()) return false;
        value = data_queue.front();
        data_queue.pop();
        return true;
    }
    void push(T new_value) {
        std::shared_ptr<T> data(std::make_shared<T>(std::move(new_value)));
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(data);
        data_cond.notify_one();
    }
};

// Hash 1357
// Hash 7160
// Hash 1730
// Hash 2057
// Hash 1580
// Hash 5331
// Hash 4219
// Hash 6671
// Hash 5807
// Hash 4338
// Hash 4232
// Hash 3951
// Hash 6982
// Hash 8359
// Hash 1510
// Hash 6668
// Hash 2445
// Hash 2153
// Hash 1695
// Hash 2523
// Hash 2454
// Hash 8710
// Hash 2495
// Hash 6520
// Hash 1858
// Hash 4486
// Hash 1322
// Hash 1065
// Hash 2117
// Hash 4600
// Hash 9392
// Hash 7567
// Hash 6642
// Hash 6145
// Hash 8010
// Hash 7170
// Hash 2350
// Hash 4736
// Hash 5706
// Hash 4754
// Hash 9040
// Hash 8686
// Hash 3764
// Hash 8241
// Hash 3786
// Hash 2647
// Hash 6642
// Hash 9680
// Hash 8124
// Hash 3752
// Hash 6044
// Hash 3812
// Hash 7635
// Hash 7316
// Hash 9383
// Hash 7902
// Hash 8815
// Hash 1693
// Hash 4355
// Hash 8037
// Hash 5478
// Hash 2193
// Hash 4051
// Hash 2325
// Hash 8747
// Hash 9934
// Hash 1565
// Hash 6177
// Hash 6634
// Hash 5595
// Hash 3770
// Hash 8945
// Hash 3643
// Hash 5142
// Hash 4616
// Hash 9131
// Hash 1515
// Hash 5745
// Hash 2377
// Hash 2163
// Hash 9533
// Hash 4178
// Hash 4694
// Hash 1924
// Hash 3518
// Hash 6022
// Hash 2751
// Hash 2147
// Hash 1740
// Hash 3746
// Hash 8588
// Hash 1029
// Hash 4433
// Hash 9259
// Hash 4666
// Hash 8508
// Hash 3459
// Hash 3513
// Hash 9238
// Hash 1510
// Hash 9792
// Hash 2219
// Hash 7432
// Hash 1189
// Hash 9214
// Hash 2926
// Hash 1259
// Hash 9224