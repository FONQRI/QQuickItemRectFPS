#ifndef RECTSGNODE_H
#define RECTSGNODE_H

#include <QtQuick/QSGFlatColorMaterial>
#include <QtQuick/QSGGeometryNode>

class RectSGNode : public QSGGeometryNode {
  public:
	RectSGNode();

	void repaint(const QRectF &rect, int numberOfRectangles, int rectangleSize,
		 const QColor &color);

  private:
	QSGFlatColorMaterial m_material;
	QSGGeometry m_geometry;
};

#endif // RECTSGNODE_H
