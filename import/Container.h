#ifndef CONTAINER_H
#define CONTAINER_H

#include "CargoGroup.h"
class Container : public CargoGroup
{
private:
	int containerId;

public:
	Container(int id, int containerId);
	virtual ~Container();
};

#endif
