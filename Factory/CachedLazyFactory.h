#pragma once
#include "BasicFactory.h"

class CachedLazyFactory: public BasicFactory
{
protected:
	std::shared_ptr<Product> createFooProduct() const
	{
		return std::make_shared<FooProduct>();
	}

public:
	CachedLazyFactory() = default;
	~CachedLazyFactory() override = default;	

	std::shared_ptr<Product> getProduct()
	{
		if(!product)
			product = createFooProduct();
		return product;
	}

private:
	std::shared_ptr<Product> product;
};
