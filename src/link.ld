OUTPUT_ARCH( "riscv" )

SECTIONS
{

  . = 0x10000000;
  .text ALIGN(8) : { *(.text) }

  .data ALIGN(8) :
  {
    *(.data)
  }
  .sdata ALIGN(8) :
  {
    PROVIDE( __global_pointer$ = . + 0x800 );
    *(.sdata)
  }
  
  _edata = .;
  
  .bss ALIGN(8) :
  {
    *(.sbss)
    *(.bss)
    PROVIDE(_end = .);
  }

	PROVIDE(exit = .);
  _exit = exit;
  
  	end = .;


  /*Тут стек c 0x10020000*/
  . = 0x10020000;

  . = 0x10021000; /*Начало кучи*/
  
  
  .heap ALIGN(8) :
  {
  *(.heap)  
  heap_335_start = .;
  /*Тут куча*/
  heap_335_end = 0x100FFFFF; /*0xFFFFF = 1Мб  ОЗУ в ПЛИС (то есть max address = 0x100FFFFF)*/
  }
  
 
 /*Память ГОСТ*/
  	rst = 0x60000040;

}