#pragma once

#include <vector>

struct PolygonData
{
    int n_sides;
    int n_verts;  // todo: test string
};

class Polygon{
private:
    int n_sides_;

public:
    std::vector<float> edge_lengths;

    Polygon(int n_sides);

    bool setEdgeLengths(std::vector<float> lens);

    PolygonData getData();

    float sumEdgeLengths();

    std::vector<float> getEdgesBy2();

    ~Polygon();
};
