/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00144f08 */

int FUN_00144f08(int param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int local_8;
  
  iVar1 = *(int *)(param_1 + 0x30);
  iVar2 = _direnter(iVar1,param_2,0,0,0,param_3,&local_8);
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
  if (iVar2 == 0) {
    *param_4 = local_8 + 0xc;
    if ((*(ushort *)(local_8 + 0x44) & 0x46) != 0) {
      *(ushort *)(local_8 + 0x44) = *(ushort *)(local_8 + 0x44) | 8;
      _microtime(&_iuniqtime);
      if ((*(byte *)(local_8 + 0x44) & 4) != 0) {
        *(undefined4 *)(local_8 + 0x74) = _iuniqtime;
      }
      if ((*(byte *)(local_8 + 0x44) & 2) != 0) {
        *(undefined4 *)(local_8 + 0x7c) = _iuniqtime;
      }
      if ((*(byte *)(local_8 + 0x44) & 0x40) != 0) {
        *(undefined4 *)(local_8 + 0x4c) = 0;
        *(undefined4 *)(local_8 + 0x84) = _iuniqtime;
      }
      *(byte *)(local_8 + 0x44) = *(byte *)(local_8 + 0x44) & 0xb9;
    }
    _iunlock(local_8);
  }
  else if (iVar2 == 0x11) {
    _iput(local_8);
  }
  return iVar2;
}

