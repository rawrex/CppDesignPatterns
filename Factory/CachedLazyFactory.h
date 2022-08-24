#pragma once
#include "BasicFactory.h"

class CachedLazyFactory: public BasicFactory
{
protected:
	virtual Product* createProduct() const = 0;

public:
	std::unique_ptr<Product> Create() const override
	{
		if(!product)
			product = createProduct();
		return std::unique_ptr<Product>(product);
	}

	CachedLazyFactory() = default;
	virtual ~CachedLazyFactory() override = default;	
private:
	mutable Product* product;
};


class CachedLazyFooFactory: public CachedLazyFactory
{
private:
	virtual Product* createProduct() const override
	{
		return new FooProduct;
	}
public:
	// virtual ~CachedLazyFooFactory() override = default;
};
