#include "BasicFactory.h"
#include "CachedLazyFactory.h"

int main() 
{
	Client client;

	// CachedLazyFooFactory foo_creator;
	BarFactory bar_creator;
	BazFactory baz_creator;

	// We use the same client object to create different types of products
	// client.use(foo_creator);
	client.use(bar_creator);
	client.use(baz_creator);
}
