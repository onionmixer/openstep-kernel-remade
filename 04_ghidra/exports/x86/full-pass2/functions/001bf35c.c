/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bf35c */

void FUN_001bf35c(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 4) - 0x70U < 0x1001) && (*(char *)(param_1 + 3) == '\x01')) {
    if (((*(int *)(param_1 + 0x18) == 0x10012002) &&
        (((*(int *)(param_1 + 0x20) == 0x10400808 && ((*(byte *)(param_1 + 0x67) & 0x30) == 0x30))
         && (*(int *)(param_1 + 0x68) == 0x80008)))) &&
       (*(int *)(param_1 + 4) == (*(int *)(param_1 + 0x6c) + 3U & 0xfffffffc) + 0x70)) {
      uVar1 = _EvSetParameterChar(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x1c),
                                  param_1 + 0x24,param_1 + 0x70,*(int *)(param_1 + 0x6c));
      *(undefined4 *)(param_2 + 0x1c) = uVar1;
    }
    else {
      *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
    }
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined1 *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x20;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

