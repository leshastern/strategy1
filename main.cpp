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
	Car* strategy_;
	
public:
	Context(Car* strategy = nullptr) : strategy_(strategy)
	{
	}
	~Context()
	{
		delete this->strategy_;
	}

	void set_strategy(Car* strategy)
	{
		delete this->strategy_;
		this->strategy_ = strategy;
	}
	
	void DoSomeBusinessLogic() const
	{
		
		string result = this->strategy_->use();
		cout << result << endl;
	}
};


class Electricity : public Car
{
public:
	string use() const override
	{
		return "Electricity";
	}
};

class Gas : public Car
{
public:
	string use() const override
	{
		return "Gas";
	}
};

class Petrol : public Car
{
public:
	string use() const override
	{
		return "Petrol";
	}
};

int main()
{
	int speed;
	cout << "Enter speed (km/h)\n";
	cin >> speed;
        
	Context* context = new Context();
	if (speed == 100) context->set_strategy(new Electricity);
	else if (speed == 200) context->set_strategy();
	else if (speed == 300) context->set_strategy();
	else cout << "Error: invalid data" << endl;
        
	context->DoSomeBusinessLogic();
	delete context;

	system("PAUSE");
	return 0;
}
