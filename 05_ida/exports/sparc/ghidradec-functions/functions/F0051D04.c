
/* WARNING: Removing unreachable block (ram,0xf0052068) */
/* WARNING: Removing unreachable block (ram,0xf0052010) */
/* WARNING: Removing unreachable block (ram,0xf0051f84) */
/* WARNING: Removing unreachable block (ram,0xf0051f1c) */
/* WARNING: Removing unreachable block (ram,0xf0051f0c) */
/* WARNING: Removing unreachable block (ram,0xf0051ee0) */
/* WARNING: Removing unreachable block (ram,0xf0051e4c) */
/* WARNING: Removing unreachable block (ram,0xf0051da4) */
/* WARNING: Removing unreachable block (ram,0xf0051dd8) */
/* WARNING: Removing unreachable block (ram,0xf0051e9c) */
/* WARNING: Removing unreachable block (ram,0xf0051ef8) */
/* WARNING: Removing unreachable block (ram,0xf0051f14) */
/* WARNING: Removing unreachable block (ram,0xf0051f48) */
/* WARNING: Removing unreachable block (ram,0xf0051fd4) */
/* WARNING: Removing unreachable block (ram,0xf0052048) */
/* WARNING: Removing unreachable block (ram,0xf0052070) */
/* WARNING: Removing unreachable block (ram,0xf0051d20) */

undefined8 sub_F0051D04(int param_1,int *param_2,int param_3)

{
  sword sVar1;
  sword sVar2;
  int iVar3;
  word wVar5;
  word wVar6;
  int iVar4;
  undefined4 unaff_l0;
  int iVar7;
  undefined4 unaff_l1;
  int iVar8;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar9;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar10;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar8 = 0;
  iVar3 = (int)*(sword *)(*_active_u + 0x30);
  _get_posix_proc();
  iVar9 = 0;
  if (*(sword *)(param_2 + 5) != -1) {
loc_F0051D9C:
    iVar9 = 0x16;
    goto locret_F0052078;
  }
  if (param_2[7] != -1) {
    iVar9 = 0x16;
    goto locret_F0052078;
  }
  if (*(sword *)(param_2 + 0xe) != -1) {
    iVar9 = 0x16;
    goto locret_F0052078;
  }
  if (param_2[0xf] != -1) {
    iVar9 = 0x16;
    goto locret_F0052078;
  }
  if (param_2[3] != -1) {
    iVar9 = 0x16;
    goto locret_F0052078;
  }
  if (param_2[4] != -1) {
    iVar9 = 0x16;
    goto locret_F0052078;
  }
  if (*param_2 != -1) goto loc_F0051D9C;
  iVar7 = *(int *)(param_1 + 0x30);
  _ilock(iVar7);
  if (*(sword *)(param_2 + 1) == -1) {
    sVar1 = *(sword *)((int)param_2 + 6);
loc_F0051E7C:
    if (sVar1 == -1) {
      if (*(sword *)(param_2 + 2) != -1) {
        sVar2 = *(sword *)(param_2 + 2);
        goto loc_F0051E9C;
      }
      iVar4 = param_2[6];
    }
    else {
      sVar2 = *(sword *)(param_2 + 2);
loc_F0051E9C:
      iVar9 = iVar7;
      sub_F0052080(iVar7,(int)sVar1,(int)sVar2);
      if (iVar9 != 0) goto loc_F0052068;
      iVar4 = param_2[6];
    }
    if (iVar4 == -1) {
loc_F0051F0C:
      _iunlock(iVar7);
      _mfs_fsync(param_1);
      _ilock(iVar7);
      if (param_2[8] == -1) {
        iVar4 = param_2[10];
      }
      else {
        iVar8 = (int)*(sword *)(iVar7 + 0x68);
        iVar9 = 0;
        if ((*(sword *)(param_3 + 2) != iVar8) && (_suser(), iVar8 == 0)) {
          iVar9 = (int)*(char *)(dword_F0133DDC + 0x38);
        }
        if (iVar9 == 0) {
          iVar4 = param_2[8];
        }
        else {
          if ((-1 < *(int *)(iVar3 + 0x18)) || (iVar9 = iVar7, _iaccess(iVar7,0x80), iVar9 != 0))
          goto loc_F0052068;
          *(undefined *)(dword_F0133DDC + 0x38) = 0;
          iVar4 = param_2[8];
        }
        iVar8 = 1;
        *(int *)(iVar7 + 0x74) = iVar4;
        iVar4 = param_2[10];
      }
      if (iVar4 != -1) {
        iVar4 = (int)*(sword *)(iVar7 + 0x68);
        iVar9 = 0;
        if ((*(sword *)(param_3 + 2) != iVar4) && (_suser(), iVar4 == 0)) {
          iVar9 = (int)*(char *)(dword_F0133DDC + 0x38);
        }
        if (iVar9 == 0) {
          iVar3 = param_2[10];
        }
        else {
          if ((-1 < *(int *)(iVar3 + 0x18)) || (iVar9 = iVar7, _iaccess(iVar7,0x80), iVar9 != 0))
          goto loc_F0052068;
          *(undefined *)(dword_F0133DDC + 0x38) = 0;
          iVar3 = param_2[10];
        }
        iVar8 = iVar8 + 1;
        *(int *)(iVar7 + 0x7c) = iVar3;
      }
      if (iVar8 != 0) {
        _getthetime((undefined *)((int)register0x00000038 + -0x10));
        *(undefined4 *)(iVar7 + 0x84) = *(undefined4 *)((int)register0x00000038 + -0x10);
        *(word *)(iVar7 + 0x44) = *(word *)(iVar7 + 0x44) | 8;
      }
    }
    else if ((*(word *)(iVar7 + 100) & 0xf000) == 0x4000) {
      iVar9 = 0x15;
    }
    else {
      iVar9 = iVar7;
      _iaccess(iVar7,0x80);
      if ((iVar9 == 0) && (iVar9 = iVar7, _itrunc(iVar7,param_2[6]), iVar9 == 0)) goto loc_F0051F0C;
    }
  }
  else {
    iVar4 = (int)*(sword *)(iVar7 + 0x68);
    bVar10 = true;
    if (*(sword *)(param_3 + 2) != iVar4) {
      _suser();
      bVar10 = true;
      if (iVar4 == 0) {
        iVar9 = (int)*(char *)(dword_F0133DDC + 0x38);
        bVar10 = iVar9 == 0;
      }
    }
    if (bVar10) {
      wVar5 = *(word *)(iVar7 + 100) & 0xf000;
      *(word *)(iVar7 + 100) = wVar5;
      wVar6 = *(word *)(param_2 + 1);
      *(word *)(iVar7 + 100) = wVar5 | wVar6 & 0xfff;
      if (*(sword *)(param_3 + 2) == 0) {
loc_F0051E6C:
        wVar6 = *(word *)(iVar7 + 0x44);
      }
      else {
        if (wVar5 != 0x4000) {
          *(word *)(iVar7 + 100) = wVar5 | wVar6 & 0xdff;
        }
        iVar4 = (int)*(sword *)(iVar7 + 0x6a);
        _groupmember();
        if (iVar4 == 0) {
          *(word *)(iVar7 + 100) = *(word *)(iVar7 + 100) & 0xfbff;
          goto loc_F0051E6C;
        }
        wVar6 = *(word *)(iVar7 + 0x44);
      }
      *(word *)(iVar7 + 0x44) = wVar6 | 0x40;
      sVar1 = *(sword *)((int)param_2 + 6);
      goto loc_F0051E7C;
    }
  }
loc_F0052068:
  _iupdat(iVar7,1);
  _iunlock(iVar7);
locret_F0052078:
  return CONCAT44(param_2,iVar9);
}
