/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b25d8 */

int FUN_001b25d8(int param_1,undefined4 param_2,short *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x180);
  iVar3 = *(int *)(param_1 + 0x188) + -1;
  if (iVar3 != -1) {
    iVar2 = iVar3 * 0x14;
    do {
      if ((((*(int *)(iVar1 + iVar2) != 0) && (*(short *)(iVar1 + 0xc + iVar2) <= *param_3)) &&
          (*param_3 < *(short *)(iVar1 + 0xe + iVar2))) &&
         ((*(short *)(iVar1 + 0x10 + iVar2) <= param_3[1] &&
          (param_3[1] < *(short *)(iVar1 + 0x12 + iVar2))))) {
        return iVar3;
      }
      iVar2 = iVar2 + -0x14;
      iVar3 = iVar3 + -1;
    } while (iVar3 != -1);
  }
  return -1;
}

