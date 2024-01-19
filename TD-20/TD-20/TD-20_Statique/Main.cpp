#include <iostream>

//---------------------------------------------Static Library-------------------------------------------//

#include "Vector.h"

int main()
{	
	Vector2<float> position_2D(100.f, 100.f); //Or Vector2<float> position_2D; -> Default constructor.
	Vector3<float> position_3D(100.f, 100.f, 10.f); //Or Vector3<float> position_3D; -> Default constructor.

	//Got base math functions.

	float dot_product_2D(position_2D.dotProduct(Vector2<float>(100.f, 20.f)));
	float dot_product_3D(position_3D.dotProduct(Vector3<float>(100.f, 20.f, 10.f)));

	std::cout << "2D dot product : " << dot_product_2D << std::endl;
	std::cout << "3D dot product : " << dot_product_3D << std::endl;

	//You have more. You can use getNorme(), getDistance(), lerp(), getAngle() and normalize().

	//Got base overloading operators.
	Vector2<int> int_vector2(Vector2<int>(80, 20) + Vector2<float>(20.f, 80.f)); //As you can no warning about loosing some numbers ( float to int ).

	std::cout << "x : " << int_vector2.x << " y : " << int_vector2.y << std::endl;

	//You have more. You can substract, multiply ( only with a float ), divide ( same as multiply ) and compare if its equal or not.

	return 0;
}

//------------------------------------------------------------------------------------------------------//