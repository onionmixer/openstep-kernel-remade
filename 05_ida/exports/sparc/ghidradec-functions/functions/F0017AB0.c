
/* WARNING: Removing unreachable block (ram,0xf0017b58) */
/* WARNING: Removing unreachable block (ram,0xf0017b14) */
/* WARNING: Removing unreachable block (ram,0xf0017abc) */
/* WARNING: Removing unreachable block (ram,0xf0017ae0) */
/* WARNING: Removing unreachable block (ram,0xf0017b88) */
/* WARNING: Removing unreachable block (ram,0xf0017b78) */
/* WARNING: Removing unreachable block (ram,0xf0017ab4) */

undefined8 _ttselect(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
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
  iVar3 = param_1;
  _ttynty();
  iVar1 = iVar3;
  _spltty();
  if (param_2 == 1) {
    iVar2 = iVar3;
    _ttnread();
    if ((0 < iVar2) ||
       (((*(uint *)(iVar3 + 0x10) & 0x8000) == 0 && ((*(uint *)(param_1 + 0x40) & 0x10) == 0)))) {
loc_F0017B88:
      _splx(iVar1);
      uVar5 = 1;
      goto locret_F0017B94;
    }
    iVar3 = param_1 + 0x28;
    _selthreadcache();
    if (iVar3 != 0) {
      uVar4 = *(uint *)(param_1 + 0x40) | 0x800;
loc_F0017B74:
      *(uint *)(param_1 + 0x40) = uVar4;
    }
  }
  else if (param_2 == 2) {
    if (*(int *)(param_1 + 0x18) <=
        (int)*(sword *)(_ttlowat + (*(byte *)(param_1 + 0x4a) & 0x1f) * 2)) goto loc_F0017B88;
    iVar3 = param_1 + 0x2c;
    _selthreadcache();
    if (iVar3 != 0) {
      uVar4 = *(uint *)(param_1 + 0x40) | 0x1000;
      goto loc_F0017B74;
    }
  }
  _splx(iVar1);
  uVar5 = 0;
locret_F0017B94:
  return CONCAT44(param_2,uVar5);
}
