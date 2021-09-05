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

     BassController bassController;
    Controller controller(bassController);
    controller.createDateBase();
    controller.readDB();
//    controller.sortList();



    controller.stations.sort(0);

    context->setContextProperty("bassController", &bassController);
    context->setContextProperty("stations", QVariant::fromValue(&controller.stations));
    context->setContextProperty("favorite", QVariant::fromValue(&controller.favorite));
    context->setContextProperty("my", QVariant::fromValue(&controller.my));
    context->setContextProperty("test", QVariant::fromValue(&controller.test));

    context->setContextProperty("controller", &controller);
    engine.rootContext()->setContextProperty("applicationDirPath", QGuiApplication::applicationDirPath());


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
