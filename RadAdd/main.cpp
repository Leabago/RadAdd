#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <radiomodel.h>
#include <controller.h>
#include <radio.h>
#include <filevalidator.h>
#include <basscontroller.h>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QQmlContext *context = engine.rootContext();
    qmlRegisterType<FileValidator>("App", 1, 0, "FileValidator");

    Controller controller;
//    controller.createDateBase();
    controller.readDB();
//    controller.sortList();
    BassController bassController;


    controller.stations.sort(0);

    context->setContextProperty("bassController", &bassController);
    context->setContextProperty("stations", QVariant::fromValue(&controller.stations));
    context->setContextProperty("favorite", QVariant::fromValue(&controller.favorite));
    context->setContextProperty("my", QVariant::fromValue(&controller.my));

    const QList<QString> genre = controller.genre;
    context->setContextProperty("genre", QVariant::fromValue(genre));

    context->setContextProperty("controller", &controller);
    engine.rootContext()->setContextProperty("applicationDirPath", QGuiApplication::applicationDirPath());

//     context->setContextProperty("test", &controller.test);
//      context->setContextProperty("listObjects", QVariant::fromValue(&controller.test.listMy) );

//     context->setContextProperty("listObjects",  QVariant::fromValue(controller.listMy));


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
