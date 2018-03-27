#include "model.h"
#include "matrix_set.h"

#include "exceptions.h"

Model::Model()
{

}

Model::Model(const vector<Coords3D> &verts, const vector<Edge> &eds) :
    vertices(verts), edges(eds)
{

}

void Model::setPosition(const Coords3D &pos)
{
    position.transform(MatrixShift(pos).create());
}

vector<shared_ptr<GraphicsItems>> Model::geometryPrimitives(const Matrix &pv, const Matrix &m)
{
    vector<shared_ptr<GraphicsItems>> drawItems;

    MatrixShift ms(getPosition());
    Matrix pvm = pv * (ms.create() * m);

    for (const Edge &edge : edges)
    {
        Coords3D v1, v2;
        try
        {
            v1 = vertices.at(edge.v1());
            v2 = vertices.at(edge.v2());
        }
        catch (const std::out_of_range& )
        {
            throw DrawException("no vertex");
        }

        v1.transform(pvm);
        v2.transform(pvm);

        drawItems.push_back(make_shared<Line>(v1.x()/v1.w(), v1.y()/v1.w(), v2.x()/v2.w(),
                                 v2.y()/v2.w()));
    }

    return drawItems;
}

void Model::transform(const Matrix &m)
{
    for (Coords3D &vertex : vertices)
        vertex.transform(MatrixShift(-getPosition()).create() *
                         m * MatrixShift(getPosition()).create());
    position.transform(m);
}

vector<shared_ptr<SceneObject>>::iterator Model::begin()
{
    return nullIterator;
}

vector<shared_ptr<SceneObject>>::iterator Model::end()
{
    return nullIterator;
}
