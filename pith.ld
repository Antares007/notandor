SECTIONS
{
  .text : {
    *(.text.red);     . = ALIGN(0x10);
    *(.text.blue);    . = ALIGN(0x10);
    *(.text.yellow);  . = ALIGN(0x10);
    *(.text.white);   . = ALIGN(0x10);
    *(.text)
  }
  .data ALIGN(0x10) : {
    *(.data)
    *(.data.*)
    *(.rodata)
    *(.rodata.*)
    *(.bss)
  }
  .text.pith ALIGN(0x10) : {
    *(.text.pith)
  }
}
