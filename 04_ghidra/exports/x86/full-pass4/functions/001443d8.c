/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001443d8 */

int FUN_001443d8(int param_1,int *param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ushort uVar5;
  int iVar6;
  int local_10;
  undefined4 local_c [2];
  
  local_10 = 0;
  iVar6 = 0;
  iVar3 = _get_posix_proc((int)*(short *)(*_active_u + 0x30));
  if ((((((short)param_2[5] != -1) || (param_2[7] != -1)) || ((short)param_2[0xe] != -1)) ||
      ((param_2[0xf] != -1 || (param_2[3] != -1)))) || ((param_2[4] != -1 || (*param_2 != -1)))) {
    return 0x16;
  }
  iVar2 = *(int *)(param_1 + 0x30);
  _ilock(iVar2);
  if ((short)param_2[1] != -1) {
    if (*(short *)(param_3 + 2) == *(short *)(iVar2 + 0x68)) {
LAB_00144472:
      if (iVar6 != 0) goto LAB_00144648;
    }
    else {
      iVar4 = _suser();
      if (iVar4 == 0) {
        iVar6 = (int)*(char *)(DAT_001e875c + 0x68);
        goto LAB_00144472;
      }
    }
    uVar5 = *(ushort *)(iVar2 + 100) & 0xf000;
    *(ushort *)(iVar2 + 100) = uVar5;
    uVar1 = *(ushort *)(param_2 + 1);
    *(ushort *)(iVar2 + 100) = uVar5 | uVar1 & 0xfff;
    if (*(short *)(param_3 + 2) != 0) {
      if (uVar5 != 0x4000) {
        *(ushort *)(iVar2 + 100) = uVar5 | uVar1 & 0xdff;
      }
      iVar4 = _groupmember((int)*(short *)(iVar2 + 0x6a));
      if (iVar4 == 0) {
        *(ushort *)(iVar2 + 100) = *(ushort *)(iVar2 + 100) & 0xfbff;
      }
    }
    *(byte *)(iVar2 + 0x44) = *(byte *)(iVar2 + 0x44) | 0x40;
  }
  if (((*(short *)((int)param_2 + 6) != -1) || ((short)param_2[2] != -1)) &&
     (iVar6 = FUN_00144664(iVar2,(int)*(short *)((int)param_2 + 6),(int)(short)param_2[2]),
     iVar6 != 0)) goto LAB_00144648;
  if (param_2[6] != -1) {
    if ((*(ushort *)(iVar2 + 100) & 0xf000) == 0x4000) {
      iVar6 = 0x15;
      goto LAB_00144648;
    }
    iVar6 = _iaccess(iVar2,0x80);
    if ((iVar6 != 0) || (iVar6 = _itrunc(iVar2,param_2[6]), iVar6 != 0)) goto LAB_00144648;
  }
  _iunlock(iVar2);
  _mfs_fsync(param_1);
  _ilock(iVar2);
  if (param_2[8] != -1) {
    if (*(short *)(param_3 + 2) == *(short *)(iVar2 + 0x68)) {
      iVar6 = 0;
LAB_0014458e:
      if (iVar6 != 0) {
        if (((*(byte *)(iVar3 + 0x18) & 1) == 0) || (iVar6 = _iaccess(iVar2,0x80), iVar6 != 0))
        goto LAB_00144648;
        *(undefined1 *)(DAT_001e875c + 0x68) = 0;
      }
    }
    else {
      iVar6 = _suser();
      if (iVar6 == 0) {
        iVar6 = (int)*(char *)(DAT_001e875c + 0x68);
        goto LAB_0014458e;
      }
      iVar6 = 0;
    }
    *(int *)(iVar2 + 0x74) = param_2[8];
    local_10 = 1;
  }
  if (param_2[10] != -1) {
    if (*(short *)(param_3 + 2) == *(short *)(iVar2 + 0x68)) {
      iVar6 = 0;
LAB_001445f6:
      if (iVar6 != 0) {
        if (((*(byte *)(iVar3 + 0x18) & 1) == 0) || (iVar6 = _iaccess(iVar2,0x80), iVar6 != 0))
        goto LAB_00144648;
        *(undefined1 *)(DAT_001e875c + 0x68) = 0;
      }
    }
    else {
      iVar6 = _suser();
      if (iVar6 == 0) {
        iVar6 = (int)*(char *)(DAT_001e875c + 0x68);
        goto LAB_001445f6;
      }
      iVar6 = 0;
    }
    *(int *)(iVar2 + 0x7c) = param_2[10];
    local_10 = local_10 + 1;
  }
  if (local_10 != 0) {
    _getthetime(local_c);
    *(undefined4 *)(iVar2 + 0x84) = local_c[0];
    *(byte *)(iVar2 + 0x44) = *(byte *)(iVar2 + 0x44) | 8;
  }
LAB_00144648:
  _iupdat(iVar2,1);
  _iunlock(iVar2);
  return iVar6;
}

