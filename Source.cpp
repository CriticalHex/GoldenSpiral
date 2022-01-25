#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;

sf::RenderWindow window(sf::VideoMode(1000, 1000), "Golden Spiral");

void drawSpiral(float startPos, int spirals) {
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(5, 5));


	float xpos;
	float ypos;
	float radius = 1;
	float angle = 0;
	int ticker = 0; //to change colors
	int adder = 1; //to change colors
	int i = 0; //iterator for loop
	float a = (360 / spirals) * startPos;
	float k = .33;
	float pi = 3.14;


	while (i < 2000) {


		//basic logrithmic spiral (uhuh... basic...)
		//xpos = radius * cos(angle)+500;
		//ypos = radius * sin(angle)+500;

		//more measurable version
		//xpos = a*exp(k*angle) * cos(angle)+500;
		//ypos = a*exp(k*angle) * sin(angle)+500;


		//golden spiral
		xpos = ((sin(angle)) * (a) * (1.618) * (exp(angle / pi)) + (500)); //ahhhh 1.6 is the golden ratio!
		ypos = ((cos(angle)) * (a) * (1.618) * (exp(angle / pi)) + (500));

		//prints out coordinate points at every 90 degree angle
		if (i % 90 == 0)
			cout << "angle is " << angle << ", x and y are " << xpos - 500 << " , " << ypos - 500 << endl;

		angle = (i * pi) / 180; //increase angle (formula is to convert to radians)

		i++;
		//radius++ //uncomment this if you're experimenting with regular logarithmic spirals
		//window.clear();

		//make fun colors (YESSS I wanted to know how you got this cool color pattern!)
		if (ticker > 254 || ticker < 0) {
			adder *= -1;
		}
		ticker += adder;

		rectangle.setFillColor(sf::Color(ticker, 0, 250));
		rectangle.setPosition(xpos, ypos);
		window.draw(rectangle);
		window.display();
	}
}

int main()
{
	//cout << "Eadem mutata resurgo" << endl; //super cool sounding thing to say "I rise again, changed but the same."
	
	int spirals = 13;
	for (int i = 1; i <= spirals; i++) {
		drawSpiral(i,spirals);
	}

	//this keeps it open after it's done drawing
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


	}



}