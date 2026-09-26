
void _mon_exit(void)

{
  int iVar1;
  word in_stack_00000000;
  
  if ((in_stack_00000000 & 0x2000) == 0) {
    iVar1 = _suser();
    if (iVar1 == 0) {
      return;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x04002282. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_reboot_vector)();
  return;
}
