/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014482c */

int FUN_0014482c(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_8;
  
  iVar3 = *(int *)(param_1 + 0x30);
  iVar2 = _dirlook(iVar3,param_2,&local_8);
  if ((*(ushort *)(iVar3 + 0x44) & 0x46) != 0) {
    *(ushort *)(iVar3 + 0x44) = *(ushort *)(iVar3 + 0x44) | 8;
    _microtime(&_iuniqtime);
    if ((*(byte *)(iVar3 + 0x44) & 4) != 0) {
      *(undefined4 *)(iVar3 + 0x74) = _iuniqtime;
    }
    if ((*(byte *)(iVar3 + 0x44) & 2) != 0) {
      *(undefined4 *)(iVar3 + 0x7c) = _iuniqtime;
    }
    if ((*(byte *)(iVar3 + 0x44) & 0x40) != 0) {
      *(undefined4 *)(iVar3 + 0x4c) = 0;
      *(undefined4 *)(iVar3 + 0x84) = _iuniqtime;
    }
    *(byte *)(iVar3 + 0x44) = *(byte *)(iVar3 + 0x44) & 0xb9;
  }
  if (iVar2 == 0) {
    *param_3 = local_8 + 0xc;
    if (((*(ushort *)(local_8 + 100) & 0x4240) == 0x200) && (_stickyhack != 0)) {
      *(byte *)(local_8 + 0x10) = *(byte *)(local_8 + 0x10) | 0x80;
    }
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
    iVar3 = *param_3;
    iVar1 = *(int *)(iVar3 + 0x28);
    if ((iVar1 - 3U < 2) || (iVar1 - 8U < 2)) {
      iVar3 = _specvp(iVar3,(int)*(short *)(iVar3 + 0x2c),iVar1);
      _vn_rele(*param_3);
      *param_3 = iVar3;
    }
  }
  return iVar2;
}

