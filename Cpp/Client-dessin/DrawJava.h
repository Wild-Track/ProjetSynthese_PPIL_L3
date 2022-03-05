#pragma once

#include "FormVisitor.h"

class DrawJava : public FormVisitor
{
public:
	void visite(const FormGroup* form) const;
	void visite(const Circle* form) const;
	void visite(const Cross* form) const;
	void visite(const Segment* form) const;
	/*virtual void visite(const Triangle* form) = 0;
	virtual void visite(const Polygone* form) = 0;*/

	void drawOnServer(string data) const;
};

