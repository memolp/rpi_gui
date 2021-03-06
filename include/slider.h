#ifndef SLIDER_H
#define SLIDER_H

#include "widget.h"

enum Slider_orientation{
	SLIDER_TYPE_HORIZONTAL,
	SLIDER_TYPE_VERTICAL
};

class Slider : public Widget
{
	IBbox m_cursor;
	int m_value, m_value_min, m_value_max, m_hold_value;
	Slider_orientation m_type;
	void compute_cursor();
protected:
	virtual void draw();
public:
	Slider(int x=0, int y=0, int width=0, int height=0, const char* name = "", Widget* parent = NULL, Slider_orientation type = SLIDER_TYPE_HORIZONTAL);

	void set_type(Slider_orientation type){m_type = type;}
	void set_range(int min, int max);
	virtual bool accept_drag(int x, int y);
	virtual bool drag_event(int rel_x, int rel_y);
	virtual bool mouse_release_event(int button);
	virtual bool leave_event();
};

#endif
