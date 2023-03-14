#include "BasicFactory.h"
#include "CachedLazyFactory.h"

int main() {

	// We use the same creator object to create different types of products
	CachedLazyFooFactory foo_creator;
	BarFactory bar_creator;
	BazFactory baz_creator;

	Client client;
	client.use(foo_creator);
	client.use(bar_creator);
	client.use(baz_creator);

	client.use(foo_creator);
	client.use(bar_creator);
	client.use(baz_creator);

}
