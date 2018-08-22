#include <QElapsedTimer>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>

#include "PainterRectItem.h"
#include "PainterRectItemQQI.h"

int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QGuiApplication app(argc, argv);

	QQuickView view;
	int totalDuration = 0;
	int loops = 0;
	QElapsedTimer timer;
	timer.start();
	QObject::connect(&view, &QQuickView::beforeRendering, [&]() {
	totalDuration += timer.elapsed();
	++loops;
		if (totalDuration > 10 * 1000) {
		qDebug() << (1000.0 * loops) / totalDuration << "fps";
		totalDuration = 0;
		loops = 0;
		}
	timer.restart();
	});

	qmlRegisterType<PainterRectItem>("test", 1, 0, "PainterRectItem");
	qmlRegisterType<PainterRectItemQQI>("test2", 1, 0, "PainterRectItemQQI");

	view.setSource(QUrl(QLatin1String("qrc:/main.qml")));
	view.show();
	//	QQmlApplicationEngine engine;
	//	engine.load(QUrl(QLatin1String("qrc:/main.qml")));
	//	if (engine.rootObjects().isEmpty())
	//		return -1;

	return app.exec();
}
