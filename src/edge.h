#ifndef EDGE_H
#define EDGE_H


class Edge
{
private:
    int V1, V2;
public:
    Edge(int v1, int v2) : V1(v1), V2(v2) { }

    int v1() const { return V1; }
    int v2() const { return V2; }
};

#endif // EDGE_H
