/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00138628 */

undefined4 FUN_00138628(int param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x14) + -4;
  *(int *)(param_1 + 0x14) = iVar2;
  if (-1 < iVar2) {
    uVar1 = **(uint **)(param_1 + 0xc);
    *param_2 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 4;
    return 1;
  }
  return 0;
}

