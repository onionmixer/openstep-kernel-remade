/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00145014 */

undefined4 FUN_00145014(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x30);
  uVar2 = _dirremove(iVar1,param_2,0,1);
  if ((*(ushort *)(iVar1 + 0x44) & 0x46) != 0) {
    *(ushort *)(iVar1 + 0x44) = *(ushort *)(iVar1 + 0x44) | 8;
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
    *(byte *)(iVar1 + 0x44) = *(byte *)(iVar1 + 0x44) & 0xb9;
  }
  return uVar2;
}

