
void sub_407CA92(int *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = *(int *)(*param_1 + 8);
  iVar1 = *(int *)((int)param_1 + 0xd2);
  iVar4 = *(int *)((int)param_1 + 0xca);
  uVar2 = *(uint *)(iVar4 + 4);
  if (uVar2 == 0) {
    param_1[2] = param_1[2] & 0xfffffffb;
    _printf(aDeviceReturnsI);
    *(undefined4 *)(iVar4 + 4) = 0x200;
  }
  else if ((param_1[2] & 4U) == 0) {
    *(undefined4 *)((int)param_1 + 0xe) = 1;
    iVar5 = (int)*(sword *)(*(int *)(iVar5 + 0x10) + 0xc);
    if (-1 < iVar5) {
      *(undefined4 *)(_dk_bps + iVar5 * 4) = 0x7d000;
    }
  }
  else {
    uVar3 = *(uint *)(iVar1 + 0x5c);
    if ((uVar3 < uVar2) || (uVar3 % uVar2 != 0)) {
      param_1[2] = param_1[2] & 0xfffffffb;
      _printf(aFsBlockNotMult);
      _printf(aFsBlockDDevBlo,*(undefined4 *)(iVar1 + 0x5c),*(undefined4 *)(iVar4 + 4));
    }
    else {
      *(uint *)((int)param_1 + 0xe) = uVar3 / uVar2;
      iVar5 = (int)*(sword *)(*(int *)(iVar5 + 0x10) + 0xc);
      if (-1 < iVar5) {
        if (*(int *)(iVar1 + 0x6c) < 0x3c) {
          iVar4 = 0x3c;
        }
        else {
          iVar4 = *(int *)(iVar1 + 0x6c) / 0x3c;
        }
        *(int *)(_dk_bps + iVar5 * 4) = iVar4 * *(int *)(iVar1 + 100) * *(int *)(iVar1 + 0x5c);
      }
    }
  }
  return;
}
