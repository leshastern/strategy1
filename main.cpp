#include <iostream>
#include <string>
using namespace std;

class Car
{
public:
	virtual string use() const = 0;
};

class Context
{
private:
	Strategy* strategy_;
	
public:
	Context(Strategy* strategy = nullptr) : strategy_(strategy)
	{
	}
	~Context()
	{
		delete this->strategy_;
	}

	void set_strategy(Strategy* strategy)
	{
		delete this->strategy_;
		this->strategy_ = strategy;
	}
	
	void DoSomeBusinessLogic() const
	{
		
		string result = this->strategy_->DoAlgorithm();
		cout << result << endl;
	}
};


class Electricity : public Car
{
public:
	string use() const override
	{
		return "Cash payment";
	}
};

class Gas : public Car
{
public:
	string use() const override
	{
		return "Card payment";
	}
};

class Petrol : public Car
{
public:
	string use() const override
	{
		return "Error: invalid data";
	}
};

int main()
{
	int cost;
	cout << "Enter purchase value\n";
	cin >> cost;

	Context* context = new Context();

	if (cost < 5000) context->set_strategy(new Card);
	else context->set_strategy(new Card);

	context->DoSomeBusinessLogic();
	delete context;

	system("PAUSE");
	return 0;
}