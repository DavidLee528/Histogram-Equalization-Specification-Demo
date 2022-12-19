#include <iostream>
#include <numeric>
#include <vector>
#include <cassert>
#include <algorithm>
#include <limits>

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

std::vector<size_t> cal_mapping(const std::vector<double> freq, const std::vector<double> spec) {
    std::vector<size_t> ret { }; 

    for (const auto & elem : freq) {
        auto comp = [elem](double a, double b) { return std::abs(a - elem) < std::abs(b - elem); }; 
        auto it = std::min_element(spec.begin(), spec.end(), comp); 
        size_t index = std::distance(spec.begin(), it);
        ret.push_back(index); 
    }

    return ret; 
}

std::vector<double> cal_new_freq(const std::vector<double> freq, const std::vector<size_t> mapping) {
    std::vector<double> ret(mapping.size(), static_cast<double>(0)); 

    for (size_t i = 0; i < mapping.size(); ++i) {
        ret.at(mapping.at(i)) += freq.at(i); 
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
    double acc_freq { std::accumulate(freq.begin(), freq.end(), static_cast<double>(0)) }; 
    assert(abs(acc_freq - one) < eps); 

    std::vector<double> spec_freq { }; 
    std::cout << "Specificate Freq. of each depth level: "; 
    for (size_t i = 0; i < l; ++i) {
        double tmp { }; 
        std::cin >> tmp; 
        spec_freq.push_back(tmp); 
    }
    double acc_new_freq { std::accumulate(spec_freq.begin(), spec_freq.end(), static_cast<double>(0)) }; 
    assert(abs(acc_new_freq - one) < eps); 

    // calculate
    std::vector<double> acc_hist_freq { cal_acc_hist(freq) }; 
    std::vector<double> acc_hist_spec_freq { cal_acc_hist(spec_freq) }; 
    std::vector<size_t> mapping { cal_mapping(acc_hist_freq, acc_hist_spec_freq) }; 
    std::vector<double> new_freq { cal_new_freq(freq, mapping) }; 

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
    for (const auto & elem : acc_hist_freq) std::cout << elem << "\t"; 
    std::cout << std::endl; 

    std::cout << "hist_spec\t\t"; 
    for (const auto & elem : spec_freq) std::cout << elem << "\t"; 
    std::cout << std::endl; 

    std::cout << "acc_hist_spec\t\t"; 
    for (const auto & elem : acc_hist_spec_freq) std::cout << elem << "\t"; 
    std::cout << std::endl; 

    std::cout << "mapping\t\t\t"; 
    for (const auto & elem : mapping) std::cout << elem << "\t"; 
    std::cout << std::endl; 

    std::cout << "new_freq\t\t"; 
    for (const auto & elem : new_freq) std::cout << elem << "\t"; 
    std::cout << std::endl; 

    return 0; 
}