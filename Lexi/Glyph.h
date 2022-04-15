
class Point;
class Window;
class Rectangle;

class Glyph {

protected:

	// Apperance 
	virtual void Draw(Window *);
	virtual void Bounds(Rectangle &);

	// Hit detection
	virtual bool Intersects(const Point &);

	// Structure
	virtual void insert(Glyph *, int);
	virtual void remove(Glyph *);
	virtual Glyph* child(int);
	virtual Glyph* parent();
	
};
