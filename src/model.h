#ifndef MODEL_H
#define MODEL_H

#include <vector>

#include "scene_object.h"
#include "edge.h"

class Model : public SceneObject
{
protected:
    vector<Coords3D> vertices;
    vector<Edge> edges;

    vector<shared_ptr<SceneObject>>::iterator nullIterator;

public:
    Model();
    Model(const vector<Coords3D> &verts, const vector<Edge> &eds);

    const vector<Coords3D> &getVertices() const { return vertices; }
    const vector<Edge> &getEdges() const { return edges; }

    void addVertex (const Coords3D &v) { vertices.push_back(v); }
    void addEdge (const Edge &e) { edges.push_back(e); }

    virtual void setPosition(const Coords3D &pos) override;

    virtual void addChild(const shared_ptr<SceneObject> &) override { }
    virtual shared_ptr<SceneObject> getChild(int ) override { return nullptr; }
    virtual void removeChild(int ) override { }

    virtual vector<shared_ptr<GraphicsItems>> geometryPrimitives(const Matrix &pv, const Matrix &m = Matrix()) override;
    virtual void transform(const Matrix &m) override;

    virtual vector<shared_ptr<SceneObject>>::iterator begin() override;
    virtual vector<shared_ptr<SceneObject>>::iterator end() override;

};

#endif // MODEL_H
