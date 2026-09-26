/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a9a8c */

undefined4 * FUN_001a9a8c(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = *(undefined4 **)(param_1 + 4);
    *(undefined4 *)(param_1 + 4) = *puVar2;
    iVar1 = *(int *)(param_1 + 0xc);
    *(int *)(param_1 + 0xc) = iVar1 + -1;
    if (iVar1 == 1) {
      *(undefined4 *)(param_1 + 8) = 0;
      *(undefined4 *)(param_1 + 4) = 0;
    }
    *puVar2 = 0;
  }
  return puVar2;
}

