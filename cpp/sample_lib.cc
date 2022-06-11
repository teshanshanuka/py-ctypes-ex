# include "sample_lib.hh"

Polygon::Polygon(int n_sides) : n_sides_(n_sides) {};

bool Polygon::setEdgeLengths(std::vector<float> lens){
    if (lens.size() != n_sides_)
        return false;
    edge_lengths = lens;
    return true;
}

float Polygon::sumEdgeLengths(){
    float sum = 0;
    for (const auto& len: edge_lengths)
        sum += len;
    return sum;
}

std::vector<float> Polygon::getEdgesBy2(){
    std::vector<float> ret;
    for (const auto& len: edge_lengths)
        ret.push_back(len*2);
    return ret;
}

PolygonData Polygon::getData(){
    return PolygonData{n_sides_, n_sides_};
}

Polygon::~Polygon() {};
