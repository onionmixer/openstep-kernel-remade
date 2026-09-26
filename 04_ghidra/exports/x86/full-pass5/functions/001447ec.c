/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001447ec */

undefined4 FUN_001447ec(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x30);
  _ilock(uVar1);
  _syncip(uVar1);
  _iunlock(uVar1);
  return 0;
}

