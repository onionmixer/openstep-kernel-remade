
/* WARNING: Removing unreachable block (ram,0xf0015c90) */
/* WARNING: Removing unreachable block (ram,0xf0015c3c) */
/* WARNING: Removing unreachable block (ram,0xf0015c00) */
/* WARNING: Removing unreachable block (ram,0xf0015bb8) */
/* WARNING: Removing unreachable block (ram,0xf0015bdc) */
/* WARNING: Removing unreachable block (ram,0xf0015c28) */
/* WARNING: Removing unreachable block (ram,0xf0015c84) */
/* WARNING: Removing unreachable block (ram,0xf0015c98) */
/* WARNING: Removing unreachable block (ram,0xf0015b7c) */

undefined8 _select(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar3;
  uint uVar4;
  undefined4 unaff_l3;
  int iVar5;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  iVar1 = dword_F0133DDC;
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
  iVar5 = dword_F0133DDC + 0x58;
  piVar3 = *(int **)(dword_F0133DDC + 0x24);
  _memcpy(iVar5,unk_F00F4B98,0xd0);
  if (0x100 < *piVar3) {
    *piVar3 = 0x100;
  }
  iVar2 = piVar3[1];
  uVar4 = *piVar3 + 0x1fU >> 5;
  if (iVar2 != 0) {
    _copyin(iVar2,iVar5,uVar4 << 2);
    *(int *)(iVar1 + 0x124) = iVar2;
    if (iVar2 != 0) goto loc_F0015C98;
  }
  iVar5 = piVar3[2];
  if (iVar5 != 0) {
    _copyin(iVar5,iVar1 + 0x78,uVar4 << 2);
    *(int *)(iVar1 + 0x124) = iVar5;
    if (iVar5 != 0) goto loc_F0015C98;
  }
  iVar5 = piVar3[3];
  if (iVar5 != 0) {
    _copyin(iVar5,iVar1 + 0x98,uVar4 << 2);
    *(int *)(iVar1 + 0x124) = iVar5;
    if (iVar5 != 0) goto loc_F0015C98;
  }
  iVar5 = piVar3[4];
  iVar2 = iVar1 + 0x118;
  if (iVar5 != 0) {
    _copyin(iVar5,iVar2,8);
    *(int *)(iVar1 + 0x124) = iVar5;
    if (iVar5 == 0) {
      _itimerfix();
      if (iVar2 == 0) {
        if ((*(int *)(iVar1 + 0x118) == 0) && (*(int *)(iVar1 + 0x11c) == 0)) {
          *(undefined4 *)(iVar1 + 0x120) = 1;
        }
        else {
          _getthetime((undefined *)((int)register0x00000038 + -0x10));
          _timevaladd(iVar1 + 0x118,(undefined *)((int)register0x00000038 + -0x10));
        }
      }
      else {
        *(undefined4 *)(iVar1 + 0x124) = 0x16;
      }
    }
  }
loc_F0015C98:
  _selcont();
  return CONCAT44(param_2,param_1);
}
