
/* WARNING: Control flow encountered unimplemented instructions */

void _pmove_crp(void)

{
  if (_cpu_type != '\0') {
    pushInvalidateCaches(3);
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}
