/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cacdc */

void __NXRemoveHandler(int param_1)

{
  int *piVar1;
  
  piVar1 = &DAT_001e551c;
  do {
    if (*piVar1 == param_1) {
      *piVar1 = *(int *)(param_1 + 0x48);
      return;
    }
    piVar1 = (int *)piVar1[5];
  } while (piVar1 != (int *)0x0);
  FUN_001caa08(param_1,0);
  return;
}

