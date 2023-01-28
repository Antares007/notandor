// clang-format off
int red(      ) __attribute__((section(".text.red")));
int red(      ) {return 1;}
int white(    ) __attribute__((section(".text.white")));
int white(    ) {return 2;}
int yellow(   ) __attribute__((section(".text.yellow")));
int yellow(   ) {return 3;}
int blue(     ) __attribute__((section(".text.blue")));
int blue(     ) {return 4;}
int pith(     ) __attribute__((section(".text.pith")));
int pith(     ) {return 5;}
// clang-format on
/*
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

    00000000  B802000000        mov eax,0x2
    00000005  C3                ret
    00000006  662E0F1F84000000  nop word [cs:rax+rax+0x0]
             -0000
    00000010  B801000000        mov eax,0x1
    00000015  C3                ret
    00000016  662E0F1F84000000  nop word [cs:rax+rax+0x0]
             -0000
    00000020  B804000000        mov eax,0x4
    00000025  C3                ret
    00000026  662E0F1F84000000  nop word [cs:rax+rax+0x0]
             -0000
    00000030  B803000000        mov eax,0x3
    00000035  C3                ret
    00000036  0000              add [rax],al
    00000038  0000              add [rax],al
    0000003A  0000              add [rax],al
    0000003C  0000              add [rax],al
    0000003E  0000              add [rax],al
    00000040  B805000000        mov eax,0x5
    */
