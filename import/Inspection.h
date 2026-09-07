#ifndef INSPECTION_H
#define INSPECTION_H

class ShippingUnit;

class Inspection
{
public:
	Inspection();
	virtual ~Inspection();
	virtual void first() = 0;
	virtual void next() = 0;
	virtual bool isDone() = 0;
	virtual ShippingUnit *currentItem() = 0;
};

#endif
