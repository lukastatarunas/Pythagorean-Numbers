#include <iostream>

int main()
{
	float firstArray[4], secondArray[4], thirdArray[4], resultArray[4];

	for (auto a = 1; a <= 1000; a += 4)
	{

		for (auto b = 2; b <= 1000; b += 4)
		{
			firstArray[0] = a;
			firstArray[1] = a + 1;
			firstArray[2] = a + 2;
			firstArray[3] = a + 3;
			secondArray[0] = b;
			secondArray[1] = b + 1;
			secondArray[2] = b + 2;
			secondArray[3] = b + 3;
			{

				__asm
				{
					movups xmm0, firstArray // xmm0 = firstArray = 1 2 3 4
					movups xmm1, secondArray // xmm1 = secondArray = 2 3 4 5
					movups xmm2, xmm0 // xmm2 = 1 2 3 4
					movaps xmm3, xmm1 // xmm3 = 2 3 4 5
					mulps xmm2, xmm2 // xmm2 = 1 4 9 16
					mulps xmm3, xmm3 // xmm3 = 4 9 16 25
					movups xmm4, xmm3 // xmm4 = 4 9 16 25
					addps xmm4, xmm2 // xmm4 = 5 13 25 41
					movups xmm5, xmm4 // xmm5 = 5 13 25 41
					sqrtps xmm5, xmm5 // xmm5 = 2.23 3.6 5 6.4
					roundps xmm5, xmm5, 1 // rounds off
					movups thirdArray, xmm5   // thirdArray = 2 3 5 6
					mulps xmm5, xmm5 // xmm5 = 4 9 25 36
					subps xmm5, xmm4 // xmm5 = -1 -4 0 -5
					movups resultArray, xmm5 // resultArray = -1 -4 0 -5
				}

				for (auto i = 0; i < 4; i++)
				{
					if (resultArray[i] == 0) // number is in that position where zero is found!
						std::cout << "1st value:" << firstArray[i] << "   2nd value:" << secondArray[i] << "   3rd value:" << thirdArray[i] << std::endl;
				}
			}
		}
	}
}
