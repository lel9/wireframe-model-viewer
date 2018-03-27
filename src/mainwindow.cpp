#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsScene>

#include "scene_manager.h"
#include "simplescenefactory.h"
#include "qt_canvas.h"
#include "add_model_command.h"
#include "transform_command.h"
#include "add_camera_command.h"
#include "add_composite_command.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene *newscene = new QGraphicsScene;
    ui->graphicsView->setScene(newscene);

    shared_ptr<Scene> scene = SimpleSceneFactory(make_shared<QtCanvas>(newscene)).create();
    SceneManager::getInstance().addScene(scene);

    /*AddModelCommand modelCommand("D:\\oop\\lr3_v2.0\\model.txt");
    modelCommand.setScene(scene);
    int tm = modelCommand.execute();
    */
    AddCameraCommand cameraCommand("D:\\oop\\lr3_v2.0\\camera.txt");
    cameraCommand.setScene(scene);
    cameraCommand.execute();

    const char *names[2] = {"D:\\oop\\lr3_v2.0\\camera.txt", "D:\\oop\\lr3_v2.0\\model.txt"};
    AddCompositeCommand cc(names, 2);
    cc.setScene(scene);
    int tm = cc.execute();

    RotateZCommand rotateCommand(Coords3D(0,0,0), 3.14 / 2);
    rotateCommand.setObject(scene->getChild(tm));
    rotateCommand.execute();

    SceneManager::getInstance().drawActiveScene();
}

MainWindow::~MainWindow()
{
    delete ui;
}
