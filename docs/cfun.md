# C function
A computer function, also known as a subroutine or procedure, is a block of code that performs a specific task and can be called multiple times throughout a program. The function works by using the stack, a memory structure used for storing data, to manage the execution of the function.

When a function is called, the current state of the program is stored on the stack, including the current values of registers and the program counter. This process is known as "pushing" the current state onto the stack.

Next, the program jumps to the beginning of the function, where the function's code is executed. The function may use variables, known as parameters, to receive data from the calling code and use that data to perform its task. These parameters are passed to the function when it is called, and they are stored in registers or on the stack.

As the function executes, it may also use its own local variables, which are stored on the stack. These variables are only accessible within the function and are not visible to the calling code.

When the function completes its task, it returns control back to the calling code by "popping" the previous state of the program off the stack, restoring the previous values of registers and the program counter. Any return value from the function is also passed back to the calling code through a register or on the stack.

It's worth noting that different architectures and programming languages may implement different variations of the mechanism used for function call and return, but the basic principle remains the same: the stack is used to store the state of the program and to manage the execution of the function.
