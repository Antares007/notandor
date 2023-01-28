SECTIONS
{
  .text : {
    *(.text.red)
    *(.text.blue)
    *(.text.yellow)
    *(.text.white)
    *(.text)
  }
  .data ALIGN(0x10) : {
    *(.data)
    *(.data.*)
    *(.rodata)
    *(.rodata.*)
    *(.bss)
  }
  .text.tail ALIGN(0x10) : {
    *(.text.tail)
  }
}
