
/* WARNING: Control flow encountered unimplemented instructions */

undefined4 _pmove_tt1(undefined4 *param_1)

{
  if (_cpu_type != '\0') {
    return *param_1;
  }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}
