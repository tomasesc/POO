#ifndef COLORPROPERTIES_H
#define COLORPROPERTIES_H

#include <QColor>

class ColorProperties {
public:
    inline QColor getColor() const { return penColor; }
    inline void setColor(const QColor &color) { penColor = color; }

private:
    QColor penColor = Qt::black;
    int penWidth = 2;

    friend class Pintura;
};

#endif // COLORPROPERTIES_H
