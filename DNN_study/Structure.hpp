
#include <vector>

template <typename T>
struct Matrix
{
    int rows;
    int cols;

    std::vector<T> data;

    Matrix(int r, int c)
        : rows(r), cols(c), data(r* c)
    {
    }

    T& operator()(int r, int c)
    {
        return data[r * cols + c];
    }
};

//actual network structure
//pretrained weights and biases
struct Network
{
	std::vector<Matrix<float>> weights;
    std::vector<Matrix<float>> bias;

	Network(const std::vector<int>& layer_sizes)
	{
        //maybe I could squeeze some optimization here by using single for loop
		//but since this is only done once at the start of the program, I don't think it matters
		for (size_t i = 0; i < layer_sizes.size() - 1; ++i)
		{
            weights.emplace_back(layer_sizes[i], layer_sizes[i + 1]);
		}
        for (size_t i = 0; i < layer_sizes.size(); ++i)
        {
            bias.emplace_back(1, layer_sizes[i]);
        }
	}

};


//actual value of nodes in the network
//which changes depending on the input
struct NetData
{
    std::vector<Matrix<float>> nodes;
    NetData(const std::vector<int>& layer_sizes)
	{
        for (size_t i = 0; i < layer_sizes.size(); ++i)
        {
            nodes.emplace_back(1, layer_sizes[i]);
        }
	}
};

