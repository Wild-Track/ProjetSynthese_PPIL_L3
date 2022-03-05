#pragma once

#include "FormVisitor.h"

class DrawJava : public FormVisitor
{
public:
	void visite(const FormGroup* form) const;
	void visite(const Circle* form) const;
	void visite(const Cross* form) const;
	void visite(const Segment* form) const;
	void visite(const Triangle* form) const;
	void visite(const polygon::Polygon* form) const;

	void drawOnServer(string data) const;
};

