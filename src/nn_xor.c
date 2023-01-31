#include <math.h>
#include <stdio.h>

#define INPUT_SIZE 2
#define HIDDEN_SIZE 3
#define OUTPUT_SIZE 1
#define NUM_SAMPLES 4
#define LEARNING_RATE 0.1

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

void backpropagation(double *inputs, double *targets, double *weights_1,
                     double *weights_2) {
  double outputs[OUTPUT_SIZE];
  neural_network(inputs, weights_1, weights_2, outputs);

  // Compute error for output layer
  double error_output[OUTPUT_SIZE];
  for (int i = 0; i < OUTPUT_SIZE; i++) {
    error_output[i] = targets[i] - outputs[i];
  }

  // Compute error for hidden layer
  double error_hidden[HIDDEN_SIZE];
  for (int i = 0; i < HIDDEN_SIZE; i++) {
    double sum = 0;
    for (int j = 0; j < OUTPUT_SIZE; j++) {
      sum += error_output[j] * weights_2[j * HIDDEN_SIZE + i];
    }
    error_hidden[i] = sum * outputs[i] * (1 - outputs[i]);
  }

  // Update weights for output layer
  for (int i = 0; i < OUTPUT_SIZE; i++) {
    for (int j = 0; j < HIDDEN_SIZE; j++) {
      weights_2[i * HIDDEN_SIZE + j] +=
          LEARNING_RATE * error_output[i] * outputs[j];
    }
  }

  // Update weights for hidden layer
  for (int i = 0; i < HIDDEN_SIZE; i++) {
    for (int j = 0; j < INPUT_SIZE; j++) {
      weights_1[i * INPUT_SIZE + j] +=
          LEARNING_RATE * error_hidden[i] * inputs[j];
    }
  }
}
int main() {
  double inputs[NUM_SAMPLES][INPUT_SIZE] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
  double targets[NUM_SAMPLES][OUTPUT_SIZE] = {{0}, {1}, {1}, {0}};
  double weights_1[HIDDEN_SIZE][INPUT_SIZE] = {
      {0.1, 0.1}, {0.2, 0.2}, {0.3, 0.3}};
  double weights_2[OUTPUT_SIZE][HIDDEN_SIZE] = {{0.4, 0.5, 0.6}};
  for (int epoch = 0; epoch < 10000; epoch++) {
    for (int i = 0; i < NUM_SAMPLES; i++) {
      backpropagation(inputs[i], targets[i], (double *)weights_1,
                      (double *)weights_2);
    }
  }

  for (int i = 0; i < NUM_SAMPLES; i++) {
    double outputs[OUTPUT_SIZE];
    neural_network(inputs[i], (double *)weights_1, (double *)weights_2,
                   outputs);
    printf("inputs: [%d, %d], outputs: [%lf]\n", (int)inputs[i][0],
           (int)inputs[i][1], outputs[0]);
  }

  return 0;
}
