//#endif // PAINTERRECTITEM_H
#include <QColor>
#include <QObject>
#include <QPainter>
#include <QQuickPaintedItem>

class PainterRectItem : public QQuickPaintedItem {
	Q_OBJECT
	Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
  public:
	explicit PainterRectItem(QQuickItem *parent = nullptr);
	void paint(QPainter *painter) override;
	QColor color() const;
  public slots:
	void setColor(QColor color);

  signals:
	void colorChanged(QColor color);

  private:
	QColor m_color;
};
