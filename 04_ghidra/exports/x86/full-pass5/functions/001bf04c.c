/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bf04c */

void FUN_001bf04c(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 4) == 0xa8) && (*(char *)(param_1 + 3) == '\0')) {
    if ((*(int *)(param_1 + 0x18) == 0x10012006) &&
       ((*(int *)(param_1 + 0x20) == 0x10400808 && (*(int *)(param_1 + 100) == 0x10400808)))) {
      uVar1 = _EvFrameBufferDevicePort
                        (*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x1c),
                         param_1 + 0x24,param_1 + 0x68,param_2 + 0x24);
      *(undefined4 *)(param_2 + 0x1c) = uVar1;
    }
    else {
      *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
    }
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined4 *)(param_2 + 0x20) = 0x10012006;
      *(undefined1 *)(param_2 + 3) = 0;
      *(undefined4 *)(param_2 + 4) = 0x28;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

