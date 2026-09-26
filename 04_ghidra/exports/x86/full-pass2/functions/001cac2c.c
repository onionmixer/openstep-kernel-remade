/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cac2c */

void __NXRemoveAltHandler(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = &DAT_001e551c;
  do {
    if (*piVar2 == param_1) {
      piVar1 = (int *)(((param_1 + -1) / 2) * 0xc + piVar2[1]);
      piVar2[3] = ((int)piVar1 - piVar2[1]) * -0x55555555 >> 2;
      *piVar2 = *piVar1;
      return;
    }
    piVar2 = (int *)piVar2[5];
  } while (piVar2 != (int *)0x0);
  FUN_001caa08(param_1,1);
  return;
}

