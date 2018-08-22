//#ifndef PAINTERRECTITEM_H
//#define PAINTERRECTITEM_H

// class PainterRectItem
//{
// public:
//	PainterRectItem();
//};

//#endif // PAINTERRECTITEM_H
#include <QColor>
#include <QObject>
#include <QPainter>
#include <QQuickPaintedItem>

class PainterRectItem : public QQuickPaintedItem {
	Q_OBJECT
	Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
  public:
	explicit PainterRectItem(QQuickItem *parent = nullptr) {}
	void paint(QPainter *painter) override
	{
	painter->save();
	painter->fillRect(QRectF(0.0, 0.0, width(), height()), m_color);
	painter->restore();
	}
	QColor color() const { return m_color; }
  public slots:
	void setColor(QColor color)
	{
	m_color = color;
	emit colorChanged(m_color);
	update();
	}
  signals:
	void colorChanged(QColor color);

  private:
	QColor m_color;
};
