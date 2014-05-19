#pragma once

#include <QtWidgets>
#include <array>

namespace Zk {
namespace LevelEditor {

class MeshTriangle;
class MeshTriangleNode;
class MeshLayer;

class MeshTriangleEdge : public QObject, public QGraphicsLineItem
{
	Q_OBJECT;
	
public:
	MeshTriangleEdge(
		MeshLayer * ml,
		std::array<MeshTriangleNode*, 2> ends,
		QGraphicsItem * parent = nullptr
	);
	virtual ~MeshTriangleEdge();
	
	std::array<MeshTriangleNode*, 2> getEnds() const;
	void deactivateExtruding();
	
	void addTriangleLink(MeshTriangle * mt);
	int getTriangleLinkCount() const;
	void remTriangleLink(MeshTriangle * mt);
	
signals:
	void clicked(MeshTriangleEdge * mte, const QPointF & pos);
	void unlinked(MeshTriangleEdge * mte);
	
public slots:
	void updatePosition(MeshTriangleNode * mtn, const QPointF & pos);
	
protected:
	void mousePressEvent(QGraphicsSceneMouseEvent * event);
	
private:
	std::array<MeshTriangleNode*, 2> ends;
	QList<MeshTriangle*> linkedTriangles;
	bool canExtrude;
};

}}