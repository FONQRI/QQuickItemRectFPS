#include "PainterRectItem.h"

PainterRectItem::PainterRectItem(QQuickItem *parent) {}

void PainterRectItem::paint(QPainter *painter)
{
	painter->save();
	painter->fillRect(QRectF(0.0, 0.0, width(), height()), m_color);
	painter->restore();
}

QColor PainterRectItem::color() const { return m_color; }

void PainterRectItem::setColor(QColor color)
{
	m_color = color;
	emit colorChanged(m_color);
	update();
}
