#-------------------------------------------------
#
# Project created by QtCreator 2017-05-25T20:13:11
#
#-------------------------------------------------

QT       += core gui
CONFIG += C++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lr3_v2.0
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    model.cpp \
    coords3d.cpp \
    matrix.cpp \
    scene.cpp \
    composite_object.cpp \
    scene_manager.cpp \
    simplescenefactory.cpp \
    add_camera_command.cpp \
    add_composite_command.cpp \
    add_model_command.cpp \
    camera_factory.cpp \
    composite_factory.cpp \
    file_reader.cpp \
    id_creator.cpp \
    model_factory.cpp \
    matrix_set.cpp \
    qt_canvas.cpp \
    scene_command.cpp \
    scene_factory.cpp \
    scene_object.cpp \
    simple_scene.cpp \
    transform_command.cpp \
    camera.cpp

HEADERS  += mainwindow.h \
    model.h \
    coords3d.h \
    edge.h \
    matrix.h \
    scene.h \
    camera.h \
    canvas.h \
    composite_object.h \
    scene_manager.h \
    simplescenefactory.h \
    exceptions.h \
    base_file_reader.h \
    file_reader.h \
    camera_factory.h \
    add_camera_command.h \
    add_composite_command.h \
    add_model_command.h \
    composite_factory.h \
    graphics_items.h \
    id_creator.h \
    matrix_set.h \
    model_factory.h \
    qt_canvas.h \
    scene_command.h \
    scene_factory.h \
    scene_object.h \
    scene_object_factory.h \
    simple_scene.h \
    transform_command.h

FORMS    += mainwindow.ui
