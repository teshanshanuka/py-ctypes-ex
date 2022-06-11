/**
 * @file sample_lib_pyi.cc
 * @author Teshan Liyanage (teshanuka@gmail.com)
 * @brief Python interfacing support for the `sample_lib`
 * @version 0.1
 * @date 2022-06-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "sample_lib.hh"

template <typename T>
inline std::vector<T> arr2vec(T* arr, int len){
    std::vector<T> ret(len);
    for (int i=0; i<len; i++)
        ret[i] = arr[i];
    return ret;
}

extern "C" {
    Polygon* getPolygonObj(int n_edges){
        return new Polygon(n_edges);
    }

    void delPolygonObj(Polygon* ptr){
        delete ptr;
    }

    bool setEdgeLengths(Polygon* ptr, float* edge_lengths){
        auto els = arr2vec<float>(edge_lengths, ptr->getData().n_sides);
        return ptr->setEdgeLengths(els);
    }

    void getEdgesBy2(Polygon* ptr, float* arr){
        auto v = ptr->getEdgesBy2();
        for (int i=0; i<v.size(); i++)
            arr[i] = v[i];
    }

    PolygonData getData(Polygon* ptr){
        return ptr->getData();
    }

    float sumEdgeLengths(Polygon* ptr){
        return ptr->sumEdgeLengths();
    } 
} // extern "C"