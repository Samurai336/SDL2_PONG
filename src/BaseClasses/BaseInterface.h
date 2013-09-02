#pragma once

#include "../Renderer/MainRender.h"

class BaseInterface
{
public:
	BaseInterface(void);
	virtual ~BaseInterface(void);

	virtual bool Load(){return true; }

	virtual void UpDate(){}

	virtual void Render(MainRender	&theRenderer) {}

	virtual void Cleanup(){}
};

