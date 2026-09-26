//Default calling convention set to: default


//const undefined _cpu_type;


/* WARNING: Control flow encountered unimplemented instructions */
/* <ghidradec_select> */

void _pflush_super(void)

{
  if (_cpu_type != '\0') {
    pushInvalidateCaches(3);
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}

