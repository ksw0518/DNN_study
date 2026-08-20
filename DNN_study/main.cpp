
#include "Structure.hpp"
#include <iostream>


constexpr auto NETWORK_LAYERS = 3;


int main()
{
	Matrix <int> mat(2, 3);
	mat(0, 0) = 1;
	std::cout << mat(0, 0) << std::endl;

	//just a simple 2->3->1 network for test
	NetData testdata({ 2,3,1 });
	Network testnet({ 2,3,1 });

	//just put junk data to the weights of the network just for the test
	for (int i = 0; i < NETWORK_LAYERS - 1; ++i)
	{
		for(int j = 0; j < testnet.bias[i].cols; ++j)
		{
			for (int k = 0; k < testnet.bias[i+1].cols; ++k)
			{
				testnet.weights[i](j, k) = i + j + k;
			}
		}
	}
	for (int i = 0; i < NETWORK_LAYERS; ++i)
	{
		for (int j = 0; j < testnet.bias[i].cols; ++j)
		{
			testnet.bias[i](0, j) = i + j;
		}
	}
	std::cout << "network initialized"<<std::endl;
	for (int i = 0; i < NETWORK_LAYERS - 1; ++i)
	{
		for (int j = 0; j < testnet.bias[i].cols; ++j)
		{
			for (int k = 0; k < testnet.bias[i + 1].cols; ++k)
			{
				std::cout << "layer " << i <<" weight, from" << j<< " to " << k << " value : " << testnet.weights[i](j, k)<<std::endl;
			}
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < NETWORK_LAYERS; ++i)
	{
		for (int j = 0; j < testnet.bias[i].rows; ++j)
		{
			std::cout << "layer " << i << "bias of neuron " << j << " value : " << testnet.bias[i](0, j) << std::endl;
		}
		std::cout << std::endl;
	}


    std::cout << "Task finished successfully" << std::endl;
}
