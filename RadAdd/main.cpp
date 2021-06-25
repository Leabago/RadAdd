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
    BassController bassController;

    context->setContextProperty("bassController", &bassController);
    context->setContextProperty("stations", QVariant::fromValue(&controller.stations));
     context->setContextProperty("favorite", QVariant::fromValue(&controller.favorite));
      context->setContextProperty("my", QVariant::fromValue(&controller.my));

    context->setContextProperty("controller", &controller);
    engine.rootContext()->setContextProperty("applicationDirPath", QGuiApplication::applicationDirPath());

    controller.createDateBase();
   controller.readDB();

    //    QList<QObject*> radList;
    //    //    radList.push_back(rad1);
    //    radList.push_back( new Radio("asd1", "asd", "asd", 5,  list));
    //    //       radList.push_back( new Radio("asd2", "asd", "asd", 5,  list));
    //    //         radList.push_back( new Radio("asd3", "asd", "asd", 5,  list));

    //     context->setContextProperty("radio", QVariant::fromValue(&radList));

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
