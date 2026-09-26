/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a26c8 */

undefined4 FUN_001a26c8(int param_1,int param_2,short param_3)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(*(int *)(param_1 + 0x28) + 0xec);
  iVar2 = 0;
  if (piVar1 != (int *)0x0) {
    iVar2 = *piVar1;
  }
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else if (*(uint *)(iVar2 + 0x84) < 8) {
    iVar2 = iVar2 + 0x88 + *(uint *)(iVar2 + 0x84) * 0x84;
  }
  else {
    iVar2 = 0;
  }
  *(uint *)(param_2 + 0x38) = (uint)(ushort)(param_3 + 1 + *(short *)(param_2 + 0x38));
  *(undefined4 *)(iVar2 + 0x68) = 0;
  return 1;
}

