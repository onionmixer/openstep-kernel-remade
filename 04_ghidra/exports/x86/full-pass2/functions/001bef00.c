/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bef00 */

void FUN_001bef00(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 4) == 0x20) && (*(char *)(param_1 + 3) == '\0')) {
    if (*(int *)(param_1 + 0x18) == 0x10012006) {
      uVar1 = _EvOpen(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x1c));
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

