#ifndef VECTORTILE_H
#define VECTORTILE_H

#include "img.h"
#include "trefile.h"
#include "trefile.h"
#include "rgnfile.h"
#include "lblfile.h"
#include "netfile.h"

class VectorTile {
public:
	VectorTile() : _tre(0), _rgn(0), _lbl(0), _net(0), _gmp(0) {}
	~VectorTile()
	  {delete _tre; delete _rgn; delete _lbl; delete _net; delete _gmp;}

	bool init();
	void clear() {_tre->clear();}

	const RectC &bounds() const {return _tre->bounds();}

	SubFile *file(SubFile::Type type);
	SubFile *addFile(IMG *img, SubFile::Type type);

	void objects(const RectC &rect, int bits, QList<IMG::Poly> *polygons,
	  QList<IMG::Poly> *lines, QList<IMG::Point> *points) const;

	friend QDebug operator<<(QDebug dbg, const VectorTile &tile);

private:
	bool initGMP();

	TREFile *_tre;
	RGNFile *_rgn;
	LBLFile *_lbl;
	NETFile *_net;
	SubFile *_gmp;
};

#ifndef QT_NO_DEBUG
QDebug operator<<(QDebug dbg, const VectorTile &tile);
#endif // QT_NO_DEBUG

#endif // VECTORTILE_H
