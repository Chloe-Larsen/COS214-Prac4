#ifndef INSPECTION_H
#define INSPECTION_H

class ShippingUnit; // forward declaration breaks the cycle

// Iterator interface
class Inspection
{
public:
	virtual ~Inspection();
	virtual void first() = 0;
	virtual void next() = 0;
	virtual bool isDone() = 0;
	virtual ShippingUnit *currentItem() = 0;
};

#endif
