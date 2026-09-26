/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00144970 */

int FUN_00144970(int param_1,undefined4 param_2,int *param_3,int param_4,int param_5,int *param_6,
                int param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_8;
  
  if (*param_3 == 2) {
    return 0x15;
  }
  local_8 = 0;
  iVar3 = *(int *)(param_1 + 0x30);
  if (*(short *)(param_7 + 2) != 0) {
    *(ushort *)(param_3 + 1) = *(ushort *)(param_3 + 1) & 0xfdff;
  }
  iVar2 = _direnter(iVar3,param_2,0,0,0,param_3,&local_8);
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
  iVar3 = local_8;
  if (iVar2 != 0x11) goto LAB_00144a8f;
  if (param_4 == 0) {
    if (((*(ushort *)(local_8 + 100) & 0xf000) != 0x4000) || (-1 < (char)param_5)) {
      if (param_5 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = _iaccess(local_8,param_5);
      }
      goto LAB_00144a5e;
    }
    iVar2 = 0x15;
  }
  else {
LAB_00144a5e:
    if (iVar2 == 0) {
      if (((*(ushort *)(iVar3 + 100) & 0xf000) == 0x8000) && (param_3[6] == 0)) {
        _itrunc(iVar3,0);
      }
      goto LAB_00144a8f;
    }
  }
  _iput(iVar3);
LAB_00144a8f:
  if (iVar2 == 0) {
    *param_6 = iVar3 + 0xc;
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
    _iunlock(iVar3);
    iVar3 = *param_6;
    iVar1 = *(int *)(iVar3 + 0x28);
    if ((iVar1 - 3U < 2) || (iVar1 - 8U < 2)) {
      iVar3 = _specvp(iVar3,(int)*(short *)(iVar3 + 0x2c),iVar1);
      _vn_rele(*param_6);
      *param_6 = iVar3;
    }
    if (param_3 != (int *)0x0) {
      (**(code **)(*(int *)(*param_6 + 0x1c) + 0x14))(*param_6,param_3,param_7);
    }
  }
  return iVar2;
}

