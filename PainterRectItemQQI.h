#ifndef PAINTERRECTITEMQQI_H
#define PAINTERRECTITEMQQI_H

#include <QColor>
#include <QObject>
#include <QPainter>
#include <QQuickItem>

class PainterRectItemQQI : public QQuickItem {
	Q_OBJECT
	Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)

	QColor m_color;

  public:
	PainterRectItemQQI();

	QColor color() const { return m_color; }

  signals:

	void colorChanged(QColor color);

  public slots:
	void setColor(QColor color)
	{
	if (m_color == color)
		return;

	m_color = color;
	emit colorChanged(m_color);
	update();
	}

  protected:
	QSGNode *updatePaintNode(QSGNode *, UpdatePaintNodeData *);
	void geometryChanged(const QRectF &newGeometry, const QRectF &oldGeometry);
	int numberOfRectangles;
	int rectangleSize = 512;
};

#endif // PAINTERRECTITEMQQI_H
