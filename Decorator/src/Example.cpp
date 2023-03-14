// Concrete class
class VisualComponent 
{
public:
	virtual void draw() {}
	virtual void resize() {}
};

class Decorator : public VisualComponent {
public:
	Decorator(VisualComponent* vc) : visual_component(vc) {}
	virtual void draw() override
	{
		visual_component->draw();
	}
	virtual void resize() override
	{
		visual_component->resize();
	}
private:
	VisualComponent* visual_component;
};


// Subclasses of Decorator define specific decoration
// Bordered visual component class 
class BorderDecorator : public Decorator {
public:
	BorderDecorator(VisualComponent* vc_ptr, int border_width) : Decorator(vc_ptr), width(border_width) {}
	virtual void draw() override 
	{
		Decorator::draw();
		drawBorder(width);
	}
private:
	void drawBorder(int) {}
private:
	int width;
};

// Scrolled visual component class 
class ScrollDecorator : public Decorator {
public:
	ScrollDecorator(VisualComponent* vc_ptr) : Decorator(vc_ptr) {}
	virtual void draw() override 
	{
		Decorator::draw();
		drawScroll();
	}
private:
	void drawScroll() {}
};

// Cropped Window class
class Window {
public:
	// Our way to put a visual component into a window object
	void setContents(VisualComponent * contents) {}
};

int main() {
	auto * vc = new VisualComponent;

	// Memory error
	Window* window = new Window;
	window->setContents(
		new BorderDecorator(
			new ScrollDecorator(vc), 1));
	// ...
	delete window;

}
