#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>
#include <cfloat>
#include <QVector>
#include <QDebug>

class Matrix
{
public:
	Matrix() {_h = 0; _w = 0;}
	Matrix(size_t h, size_t w);

	size_t h() const {return _h;}
	size_t w() const {return _w;}
	double &m(size_t i, size_t j) {return _m[_w * i + j];}
	double const &m(size_t i, size_t j) const {return _m.at(_w * i + j);}

	bool isNull() const {return (_h == 0 || _w == 0);}

	bool eliminate(double epsilon = DBL_EPSILON);
	Matrix augemented(const Matrix &M) const;

private:
	QVector<double> _m;
	size_t _h;
	size_t _w;
};

#ifndef QT_NO_DEBUG
QDebug operator<<(QDebug dbg, const Matrix &matrix);
#endif // QT_NO_DEBUG

#endif // MATRIX_H
