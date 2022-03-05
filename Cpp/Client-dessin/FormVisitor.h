#pragma once

#include "Form.h"
#include "Cross.h"
#include "Circle.h"
#include "Segment.h"
#include "FormGroup.h"

class FormVisitor
{
public:
	virtual void visite(const FormGroup* form) const = 0;
	virtual void visite(const Circle* form) const = 0;
	virtual void visite(const Cross* form) const = 0;
	virtual void visite(const Segment* form) const = 0;
	/*virtual void visite(const Triangle* form) = 0;
	virtual void visite(const Polygone* form) = 0;*/
};
