#ifndef ILAYOUT_H
#define ILAYOUT_H

#include <QColor>

class ILayout
{
public:
    virtual void setBackgroundColor(QColor c) = 0;
    virtual void setCadreStrokeColor(QColor c) = 0;
    virtual void setCornerRadius(int radius) = 0;
    virtual void setMargin(int radius) = 0;
};

#endif // ILAYOUT_H
