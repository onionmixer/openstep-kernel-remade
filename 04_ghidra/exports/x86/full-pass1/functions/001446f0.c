/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001446f0 */

undefined4 FUN_001446f0(int param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = *(uint *)(param_1 + 0x30);
  while ((*(ushort *)(uVar1 + 0x44) & 1) != 0) {
    *(ushort *)(uVar1 + 0x44) = *(ushort *)(uVar1 + 0x44) | 0x10;
    _sleep(uVar1);
  }
  *(byte *)(uVar1 + 0x44) = *(byte *)(uVar1 + 0x44) | 1;
  uVar2 = _iaccess(uVar1,param_2);
  _iunlock(uVar1);
  return uVar2;
}

