/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00143cb0 */

undefined4 FUN_00143cb0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x30);
  _bflush(param_1,0xffffffff,0xffffffff);
  _microtime(&_iuniqtime);
  if ((*(byte *)(iVar1 + 0x44) & 4) != 0) {
    *(undefined4 *)(iVar1 + 0x74) = _iuniqtime;
  }
  if ((*(byte *)(iVar1 + 0x44) & 2) != 0) {
    *(undefined4 *)(iVar1 + 0x7c) = _iuniqtime;
  }
  if ((*(byte *)(iVar1 + 0x44) & 0x40) != 0) {
    *(undefined4 *)(iVar1 + 0x4c) = 0;
    *(undefined4 *)(iVar1 + 0x84) = _iuniqtime;
  }
  *(byte *)(iVar1 + 0x44) = *(byte *)(iVar1 + 0x44) & 0xfd;
  return 0;
}

