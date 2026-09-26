
/* WARNING: Removing unreachable block (ram,0xf001b990) */
/* WARNING: Removing unreachable block (ram,0xf001b970) */
/* WARNING: Removing unreachable block (ram,0xf001b950) */
/* WARNING: Removing unreachable block (ram,0xf001b958) */
/* WARNING: Removing unreachable block (ram,0xf001b988) */
/* WARNING: Removing unreachable block (ram,0xf001b99c) */
/* WARNING: Removing unreachable block (ram,0xf001b948) */

undefined8 _ptcclose(uint param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  iVar4 = (param_1 & 0xff) * 0x10;
  iVar3 = *(int *)(unk_F012F204 + iVar4 + 8);
  iVar2 = *(int *)(unk_F012F204 + iVar4 + 0xc);
  (**(code **)(DAT_f010b8f0 + *(char *)(iVar3 + 0x47) * 0x30))(iVar3,0);
  uVar1 = *(uint *)(unk_F012F204 + iVar4 + 4);
  if ((uVar1 & 1) != 0) {
    _forceclose((int)*(sword *)(unk_F012F204 + iVar4));
    uVar1 = (uint)*(sword *)(unk_F012F204 + iVar4);
    _ptsclose(uVar1);
  }
  _spltty();
  if (*(int *)(iVar2 + 4) != 0) {
    _selthreadclear(iVar2 + 4);
  }
  if (*(int *)(iVar2 + 8) != 0) {
    _selthreadclear(iVar2 + 8);
  }
  _splx(uVar1);
  *(undefined4 *)(iVar3 + 0x24) = 0;
  _ttynty();
  *(undefined4 *)(iVar3 + 8) = 0;
  return CONCAT44(param_2,iVar4);
}

