
/* WARNING: Control flow encountered unimplemented instructions */
/* WARNING: This function may have set the stack pointer */

void _intstacks(void)

{
                    /* WARNING: Read-only address (ram,0x04001314) is written */
                    /* WARNING: Read-only address (ram,0x04001310) is written */
  uRam04001310 = 0x400132e;
  puRam04001314 = (undefined *)register0x0000003c;
  _m68k_init();
  if (_cpu_type != '\0') {
    invalidateCacheLines(3);
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}

