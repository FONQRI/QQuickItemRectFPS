#include "PainterRectItemQQI.h"

#include "RectSGNode.h"

#include <iostream>

class GraphNode : public QSGNode {
  public:
	RectSGNode *background;
};

PainterRectItemQQI::PainterRectItemQQI()
	: numberOfRectangles(10000), rectangleSize(512)
{
	setFlag(ItemHasContents, true);
}

QSGNode *PainterRectItemQQI::updatePaintNode(QSGNode *oldNode,
						 UpdatePaintNodeData *)
{
	GraphNode *node = static_cast<GraphNode *>(oldNode);

	QRectF rect = boundingRect();

	if (rect.isEmpty()) {
		delete node;
		return 0;
	}

	if (!node) {
		node = new GraphNode();

		node->background = new RectSGNode();

		node->appendChildNode(node->background);
	}

	node->background->repaint(rect, numberOfRectangles, rectangleSize, m_color);

	return node;
}

void PainterRectItemQQI::geometryChanged(const QRectF &newGeometry,
					 const QRectF &oldGeometry)
{
	update();
	QQuickItem::geometryChanged(newGeometry, oldGeometry);
}
