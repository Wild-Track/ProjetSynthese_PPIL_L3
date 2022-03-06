#pragma once

#include "Form.h"
#include "Cross.h"
#include "Circle.h"
#include "Segment.h"
#include "Triangle.h"
#include "Polygon.h"
#include "FormGroup.h"

//! @brief  Classe abstraites du DP Visitor avec les fonctions a implementer
//! 
//! Toutes les fonctionnalites a ajouter tel que librairies graphiques ou encore format de sauvegarde viendront s'ajouter
class FormVisitor
{
public:
	virtual void visite(const FormGroup* form) const = 0;
	virtual void visite(const Circle* form) const = 0;
	virtual void visite(const Cross* form) const = 0;
	virtual void visite(const Segment* form) const = 0;
	virtual void visite(const Triangle* form) const = 0;
	virtual void visite(const polygon::Polygon* form) const = 0;
};

