// clang-format off
int red(      ) __attribute__((section(".text.red")   ));
int white(    ) __attribute__((section(".text.white") ));
int yellow(   ) __attribute__((section(".text.yellow")));
int blue(     ) __attribute__((section(".text.blue")  ));

int red(      ) { return 1; }
int white(    ) { return 2; }
int yellow(   ) { return 3; }
int blue(     ) { return 4; }

int pith(     ) __attribute__((section(".text.pith")));
int pith(     ) { return 7; }

void *rays[] = {9, red, yellow, white, blue, 6};
void test(void *t, long a, long r, void o(long), void *s) {
  o(a * r);
}

// clang-format on
/*
  dream in colors what does it means?
  tunnel of love.
  Today, we will outline the protocol of the executable word. We will detail two
  versions of the protocol that have already been established in the C
  programming language, making this task straightforward.


The protocol of the "Executable Word" (also known as the protocol of "Aradani")
defines an executable word as a void C function with a set list of parameters
and a corresponding function body. These functions are referred to as
"narative_rolls."

In the first version of the Protocol of Aradani, narative_rolls have three
variables. The parameters are "aradani_text_space," "pith_of_the_sentence," and
the "narative_roll" itself, which holds the machine text.

The machine text is treated as a variable and can be anything, but according to
the rules of the protocol, it must continue execution using the "pith_of_the_sentence.".

In simpler terms, the Protocol of Aradani requires a jump to an address
specified in the "pith_of_the_sentence."




pith_of_the_sentence is a three ray execution mechanism which is represented as
conigous memory_space.














  Let's begin. Let's take action. We have received a message and it is important
  to ensure that the message is complete and has a clear meaning. The question
  now is how we interpret this message to identify the words it contains, the
  language in which it is written and if it was transmitted without any errors.
  Is it a continuation of our previous conversation or is it the start of a
  new journey?

  where to start? how to start? help.
  1. Receive a message
      We can begin here by using epoll to read IP packets and start processing
      them but it is a detailed, code-level thinking.
      From now on, let's aim to use clear and executable language with specific
      terms. It will help us to present our ideas in a way that is easy to
      understand and not overly technical.
      How can we write a sentence in which the execution flows like a river?
      For example, the sentence "receive IP message" clearly defines the task.
      In this case, how can we continue the story?
      "Receive the message. Ensure that the message is complete. Execute the
  message text."


  2. Ensure the message is complete and has a clear meaning
  3. Interpret the message to identify the words it contains
  4. Determine the language in which the message is written
  5. Verify if the message was transmitted without any errors
  6. Determine if the current task or conversation is a continuation of the
     previous one or a new journey.



  What is the executable word?
  By using a new building block called the executable word, we can now do things
  that were once impossible. We can reach new levels of performance, develop
  large-scale distributed systems, and create error-free sentences that can be
  executed.
  The executable word refers to a type of file that is similar to a binary file
  or an array if like. It can be loaded into memory, and the CPU can then jump
  to the starting address to execute the instructions contained within the file.
  In other words, it is a block of instructions that are constructed using
  a set of rules, also known as a protocol.

  well firs we need to dream in colors white, red, blue and yellow.





  What is the sentence?
  A well-written sentence is a group of words that convey a complete thought and
  are competed with a period.

  What is conversation?
  Computer systems can communicate with each other through various forms of
  exchange of information and data, such as command-line interfaces, APIs, or
  natural language processing. These conversations can serve various purposes,
  such as transferring files or synchronizing data, and can range from simple to
  complex in nature. The primary goal of these conversations is to facilitate
  communication and coordination between different parts of the systems or
  between different systems.

00000000  B801000000                  mov eax,0x1
00000005  C3                          ret
00000006  662E0F1F840000000000        nop word [cs:rax+rax+0x0]

00000010  B804000000                  mov eax,0x4
00000015  C3                          ret
00000016  662E0F1F840000000000        nop word [cs:rax+rax+0x0]

00000020  B803000000                  mov eax,0x3
00000025  C3                          ret
00000026  662E0F1F840000000000        nop word [cs:rax+rax+0x0]

00000030  B802000000                  mov eax,0x2
00000035  C3                          ret
00000036  662E0F1F840000000000        nop word [cs:rax+rax+0x0]

00000040  480FAFF2                    imul rsi,rdx
00000044  4889F7                      mov rdi,rsi
00000047  FFE1                        jmp rcx
00000049  0000                        add [rax],al
0000004B  0000                        add [rax],al
0000004D  0000                        add [rax],al
0000004F  0000                        add [rax],al
00000051  0000                        add [rax],al
00000053  0000                        add [rax],al
00000055  0000                        add [rax],al
00000057  0000                        add [rax],al
00000059  0000                        add [rax],al
0000005B  0000                        add [rax],al
0000005D  0000                        add [rax],al
0000005F  0009                        add [rcx],cl
00000061  0000                        add [rax],al
00000063  0000                        add [rax],al
00000065  0000                        add [rax],al
00000067  0000                        add [rax],al
00000069  0000                        add [rax],al
0000006B  0000                        add [rax],al
0000006D  0000                        add [rax],al
0000006F  0020                        add [rax],ah
00000071  0000                        add [rax],al
00000073  0000                        add [rax],al
00000075  0000                        add [rax],al
00000077  0030                        add [rax],dh
00000079  0000                        add [rax],al
0000007B  0000                        add [rax],al
0000007D  0000                        add [rax],al
0000007F  0010                        add [rax],dl
00000081  0000                        add [rax],al
00000083  0000                        add [rax],al
00000085  0000                        add [rax],al
00000087  0006                        add [rsi],al
00000089  0000                        add [rax],al
0000008B  0000                        add [rax],al
0000008D  0000                        add [rax],al
0000008F  00B807000000                add [rax+0x7],bh
00000095  C3                          ret <- last bytw will be removed durink
make script
*/
