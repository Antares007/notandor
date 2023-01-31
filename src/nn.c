/*
  In this example, we define a simple feedforward neural network with 2 inputs,
  3 hidden nodes, and 1 output. The neural_network function implements the
  forward pass of the network, which computes the outputs given the inputs and
  the weights. The weights are stored in arrays weights_1 and weights_2. The
  sigmoid function computes the sigmoid activation function, which is used to
  non-linearly transform the input signals. The dot_product function computes
  the dot product of two arrays.

  This is a simple example to illustrate the basic concepts of neural networks.
  In practice, neural networks can be much more complex and may include multiple
  hidden layers, different activation functions, and other features. Training a
  neural network to perform a specific task typically involves adjusting the
  weights to minimize the error between the predicted outputs and the desired
  outputs.
*/
#include <math.h>
#include <stdio.h>

#define INPUT_SIZE 2
#define HIDDEN_SIZE 3
#define OUTPUT_SIZE 1

double sigmoid(double x) { return 1.0 / (1.0 + exp(-x)); }

double dot_product(double *a, double *b, int size) {
  double result = 0;
  for (int i = 0; i < size; i++) {
    result += a[i] * b[i];
  }
  return result;
}

void neural_network(double *inputs, double *weights_1, double *weights_2,
                    double *outputs) {
  // Hidden layer
  double hidden_layer[HIDDEN_SIZE];
  for (int i = 0; i < HIDDEN_SIZE; i++) {
    hidden_layer[i] =
        sigmoid(dot_product(inputs, weights_1 + i * INPUT_SIZE, INPUT_SIZE));
  }

  // Output layer
  for (int i = 0; i < OUTPUT_SIZE; i++) {
    outputs[i] = sigmoid(
        dot_product(hidden_layer, weights_2 + i * HIDDEN_SIZE, HIDDEN_SIZE));
  }
}

int main() {
  double inputs[INPUT_SIZE] = {0.5, 0.1};
  double weights_1[INPUT_SIZE * HIDDEN_SIZE] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6};
  double weights_2[HIDDEN_SIZE * OUTPUT_SIZE] = {0.7, 0.8, 0.9};
  double outputs[OUTPUT_SIZE];

  neural_network(inputs, weights_1, weights_2, outputs);
  printf("Output: %lf\n", outputs[0]);

  return 0;
}
