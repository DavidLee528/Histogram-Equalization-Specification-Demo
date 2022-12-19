#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>

static const double one { 1 }; 
static const double eps { 1e-8 }; 

std::vector<double> cal_acc_hist(const std::vector<double> freq) {
    std::vector<double> ret { }; 
    double acc { }; 
    
    for (const auto & f : freq) {
        acc += f; 
        ret.push_back(acc); 
    }

    assert(abs(acc - one) < eps); 
    return ret; 
}

std::vector<size_t> cal_round(size_t l, const std::vector<double> acc_hist) {
    std::vector<size_t> ret { }; 

    for (const auto & elem : acc_hist) {
        ret.push_back(static_cast<size_t>((l - 1) * elem + 0.5)); 
    }

    return ret; 
}

std::vector<double> cal_new_freq(const std::vector<double> freq, const std::vector<size_t> round) {
    std::vector<double> ret(round.size(), static_cast<double>(0)); 

    for (size_t i = 0; i < round.size(); ++i) {
        ret.at(round.at(i)) += freq.at(i); 
    }

    return ret; 
}

int main(int argc, const char **argv) {
    // input
    size_t l { 0 }; 
    std::cout << "Number of bit depth: "; 
    std::cin >> l; 

    std::vector<double> freq { }; 
    std::cout << "Freq. of each depth level: "; 
    for (size_t i = 0; i < l; ++i) {
        double tmp { }; 
        std::cin >> tmp; 
        freq.push_back(tmp); 
    }
    double acc { std::accumulate(freq.begin(), freq.end(), static_cast<double>(0)) }; 
    assert(abs(acc - one) < eps); 

    // calculate
    std::vector<double> acc_hist { cal_acc_hist(freq) }; 
    std::vector<size_t> round { cal_round(l, acc_hist) }; 
    std::vector<double> new_freq { cal_new_freq(freq, round) }; 
    
    // output
    std::cout << std::endl << "origin gray level\t"; 
    for (size_t i = 0; i < l; ++i) {
        std::cout << i << "\t"; 
    }
    std::cout << std::endl; 

    std::cout << "origin freq\t\t"; 
    for (const auto & elem : freq) std::cout << elem << "\t"; 
    std::cout << std::endl; 

    std::cout << "acc_hist\t\t"; 
    for (const auto & elem : acc_hist) std::cout << elem << "\t"; 
    std::cout << std::endl; 

    std::cout << "round\t\t\t"; 
    for (const auto & elem : round) std::cout << elem << "\t"; 
    std::cout << std::endl; 

    std::cout << "new_freq\t\t"; 
    for (const auto & elem : new_freq) std::cout << elem << "\t"; 
    std::cout << std::endl; 

    return 0; 
}