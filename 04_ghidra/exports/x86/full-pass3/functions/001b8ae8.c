/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b8ae8 */

int FUN_001b8ae8(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x34) == 0) {
    uVar1 = _IOMalloc(0x2000);
    *(undefined4 *)(param_1 + 0x34) = uVar1;
  }
  *(undefined1 *)(*(int *)(param_1 + 0x34) + 3) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x34) + 4) = 0x18;
  *(undefined4 *)(*(int *)(param_1 + 0x34) + 8) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x34) + 0xc) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x34) + 0x10) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x34) + 0x14) = 0;
  return param_1;
}

