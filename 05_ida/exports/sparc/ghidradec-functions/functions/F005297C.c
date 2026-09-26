
/* WARNING: Removing unreachable block (ram,0xf0052b28) */
/* WARNING: Removing unreachable block (ram,0xf0052a80) */
/* WARNING: Removing unreachable block (ram,0xf0052a28) */
/* WARNING: Removing unreachable block (ram,0xf00529b8) */
/* WARNING: Removing unreachable block (ram,0xf00529a4) */
/* WARNING: Removing unreachable block (ram,0xf0052a10) */
/* WARNING: Removing unreachable block (ram,0xf0052a60) */
/* WARNING: Removing unreachable block (ram,0xf0052ab0) */
/* WARNING: Removing unreachable block (ram,0xf0052b88) */
/* WARNING: Removing unreachable block (ram,0xf005298c) */

undefined8 sub_F005297C(int param_1,undefined *param_2,int param_3,undefined4 param_4)

{
  sword sVar1;
  word wVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar6;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar7;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
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
  iVar5 = *(int *)(param_1 + 0x30);
  iVar7 = *(int *)(param_3 + 0x30);
  iVar6 = iVar5;
  _iaccess(iVar5,0x80);
  if ((iVar6 != 0) ||
     (iVar6 = iVar5, _dirlook(iVar5,param_2,(undefined *)((int)register0x00000038 + -0xc)),
     iVar6 != 0)) goto locret_F0052B90;
  _iunlock(*(undefined4 *)((int)register0x00000038 + -0xc));
  if (((*(word *)(iVar5 + 100) & 0x200) == 0) ||
     (((sVar1 = *(sword *)(*(int *)(_active_u + 0x1c) + 2), sVar1 == 0 ||
       (sVar1 == *(sword *)(iVar5 + 0x68))) ||
      (iVar6 = 1, *(sword *)(*(int *)((int)register0x00000038 + -0xc) + 0x68) == sVar1)))) {
    puVar4 = param_2;
    _strcmp(param_2,&asc_F010F208);
    if (puVar4 != (undefined *)0x0) {
      puVar4 = param_2;
      _strcmp(param_2,&asc_F010F210);
      if ((puVar4 != (undefined *)0x0) && (iVar5 != *(int *)((int)register0x00000038 + -0xc))) {
        iVar6 = iVar7;
        _direnter(iVar7,param_4,2,iVar5,*(int *)((int)register0x00000038 + -0xc),0,0);
        iVar3 = iVar6 + 1;
        if (iVar6 == 0) {
          iVar6 = iVar5;
          _dirremove(iVar5,param_2,*(undefined4 *)((int)register0x00000038 + -0xc),0);
          iVar3 = iVar6 + -2;
        }
        if (iVar3 == 0) {
          iVar6 = 0;
        }
        goto loc_F0052A98;
      }
    }
    iVar6 = 0x16;
  }
loc_F0052A98:
  if ((*(word *)(iVar5 + 0x44) & 0x46) != 0) {
    *(word *)(iVar5 + 0x44) = *(word *)(iVar5 + 0x44) | 8;
    param_2 = DAT_f0135000;
    _microtime(&_iuniqtime);
    if ((*(word *)(iVar5 + 0x44) & 4) != 0) {
      *(undefined4 *)(iVar5 + 0x74) = _iuniqtime;
    }
    if ((*(word *)(iVar5 + 0x44) & 2) != 0) {
      *(undefined4 *)(iVar5 + 0x7c) = _iuniqtime;
    }
    if ((*(word *)(iVar5 + 0x44) & 0x40) == 0) {
      wVar2 = *(word *)(iVar5 + 0x44);
    }
    else {
      *(undefined4 *)(iVar5 + 0x4c) = 0;
      *(undefined4 *)(iVar5 + 0x84) = _iuniqtime;
      wVar2 = *(word *)(iVar5 + 0x44);
    }
    *(word *)(iVar5 + 0x44) = wVar2 & 0xffb9;
  }
  if ((*(word *)(iVar7 + 0x44) & 0x46) != 0) {
    *(word *)(iVar7 + 0x44) = *(word *)(iVar7 + 0x44) | 8;
    _microtime(&_iuniqtime);
    if ((*(word *)(iVar7 + 0x44) & 4) != 0) {
      *(undefined4 *)(iVar7 + 0x74) = _iuniqtime;
    }
    if ((*(word *)(iVar7 + 0x44) & 2) != 0) {
      *(undefined4 *)(iVar7 + 0x7c) = _iuniqtime;
    }
    if ((*(word *)(iVar7 + 0x44) & 0x40) == 0) {
      wVar2 = *(word *)(iVar7 + 0x44);
    }
    else {
      *(undefined4 *)(iVar7 + 0x4c) = 0;
      *(undefined4 *)(iVar7 + 0x84) = _iuniqtime;
      wVar2 = *(word *)(iVar7 + 0x44);
    }
    *(word *)(iVar7 + 0x44) = wVar2 & 0xffb9;
  }
  _irele(*(undefined4 *)((int)register0x00000038 + -0xc));
locret_F0052B90:
  return CONCAT44(param_2,iVar6);
}
