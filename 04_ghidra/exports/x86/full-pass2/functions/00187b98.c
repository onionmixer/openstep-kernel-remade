/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00187b98 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _clock_value(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00187d48();
  if (param_1 == 0) {
    iVar1 = iVar1 + __time_of_boot;
  }
  else if (param_1 != 1) {
    iVar1 = 0;
  }
  return iVar1;
}

