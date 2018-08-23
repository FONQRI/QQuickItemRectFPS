#include "RectSGNode.h"

#include <iostream>

RectSGNode::RectSGNode()
	: m_geometry(QSGGeometry::defaultAttributes_Point2D(), 0)
{
	setGeometry(&m_geometry);
	m_geometry.setDrawingMode(GL_TRIANGLES);

	setMaterial(&m_material);
	m_material.setColor(QColor("#222"));
}

#include "qmath.h"

/*
 * The function hardcodes a fixed set of grid lines and scales
 * those to the bounding rect.
 */
void RectSGNode::repaint(const QRectF &rect, int numberOfRectangles,
			 int rectangleSize, const QColor &color)
{
	//	std::clog << "working " << std::endl;
	m_material.setColor(color);
	QSGGeometry *g = geometry();

	g->allocate(numberOfRectangles * 6);

	float x = rect.x();
	float y = rect.y();
	float w = x + rect.width();
	float h = y + rect.height();

	QSGGeometry::Point2D *v = g->vertexDataAsPoint2D();

	auto rowCount = static_cast<int>(qSqrt(numberOfRectangles));

	for (int row = 0; row < rowCount; row++) {
		for (int column = 0; column < rowCount; column++) {
			// TODO pre cal
			auto index = row * 6 * rowCount + column * 6;
			auto rowSize = row * rectangleSize;
			auto colSize = column * rectangleSize;
			v[index].set(rowSize, colSize);

			v[index + 1].set(rowSize + rectangleSize, colSize);

			v[index + 2].set(rowSize + rectangleSize,
					 colSize + rectangleSize);

			v[index + 3].set(rowSize, colSize);

			v[index + 4].set(rowSize, colSize + rectangleSize);

			v[index + 5].set(rowSize + rectangleSize,
					 colSize + rectangleSize);
		}
	}
	// Tell the scenegraph we updated the geometry..
	markDirty(QSGNode::DirtyGeometry);
}
