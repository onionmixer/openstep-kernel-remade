/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ca6dc */

undefined4 FUN_001ca6dc(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < param_4) {
    do {
      iVar2 = iVar3 * 0x14;
      if ((*(int *)(param_3 + iVar2) < 2) && (*(int *)(param_3 + 8 + iVar2) != 0)) {
        piVar1 = (int *)(param_3 + 8 + iVar2);
        *piVar1 = *piVar1 + -4;
      }
      iVar2 = iVar3 * 0x14;
      if ((*(int *)(param_3 + iVar2) == 0) && (*(int *)(param_3 + 8 + iVar2) != 0)) {
        __objc_inform("Unable to install protocols by name...\n");
        __objc_inform("Protocol %s must be recompiled.\n",*(undefined4 *)(param_3 + 4 + iVar2));
      }
      *(undefined4 *)(param_3 + iVar3 * 0x14) = param_1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_4);
  }
  return param_1;
}

