
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _start(void)

{
  undefined4 uVar1;
  
  _DAT_00000472 = 0x1234;
  _gdt_init();
  _idt_init();
  _i386_init();
  _startup_early();
  uVar1 = _setup_main();
  _start_initial_context(uVar1);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

