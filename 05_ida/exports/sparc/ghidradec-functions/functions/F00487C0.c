
/* WARNING: Removing unreachable block (ram,0xf0048928) */
/* WARNING: Removing unreachable block (ram,0xf00488ec) */
/* WARNING: Removing unreachable block (ram,0xf00488a8) */
/* WARNING: Removing unreachable block (ram,0xf0048860) */
/* WARNING: Removing unreachable block (ram,0xf0048800) */
/* WARNING: Removing unreachable block (ram,0xf0048858) */
/* WARNING: Removing unreachable block (ram,0xf0048898) */
/* WARNING: Removing unreachable block (ram,0xf00488c4) */
/* WARNING: Removing unreachable block (ram,0xf0048918) */
/* WARNING: Removing unreachable block (ram,0xf004893c) */
/* WARNING: Removing unreachable block (ram,0xf00487f4) */

undefined8 _alloc(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
  int iVar6;
  undefined4 unaff_l3;
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
  iVar6 = *(int *)(param_1 + 0x50);
  if ((*(uint *)(iVar6 + 0x30) < param_3) || ((param_3 & ~*(uint *)(iVar6 + 0x4c)) != 0)) {
    _printf(aDev0xXBsizeDSi,(int)*(sword *)(param_1 + 0x46),*(uint *)(iVar6 + 0x30),param_3,
            iVar6 + 0xd4);
    _panic(aAllocBadSize);
  }
  if ((param_3 != *(uint *)(iVar6 + 0x30)) || (*(int *)(iVar6 + 0xc4) != 0)) {
    if (*(sword *)(*(int *)(_active_u + 0x1c) + 2) == 0) {
      iVar1 = *(int *)(iVar6 + 0x24);
    }
    else {
      iVar5 = *(int *)(iVar6 + 0xc4);
      iVar1 = *(int *)(iVar6 + 0x28);
      uVar4 = *(undefined4 *)(iVar6 + 0x60);
      iVar3 = *(int *)(iVar6 + 0xcc);
      .umul(iVar1,*(undefined4 *)(iVar6 + 0x3c));
      .div();
      if (((iVar5 << ((byte)uVar4 & 0x1f)) + iVar3) - iVar1 < 1) goto loc_F004893C;
      iVar1 = *(int *)(iVar6 + 0x24);
    }
    if (iVar1 <= param_2) {
      param_2 = 0;
    }
    if (param_2 == 0) {
      iVar1 = *(int *)(param_1 + 0x48);
      .udiv(iVar1,*(undefined4 *)(iVar6 + 0xb8));
    }
    else {
      iVar1 = param_2;
      .div(param_2,*(undefined4 *)(iVar6 + 0xbc));
    }
    iVar3 = param_1;
    _hashalloc(param_1,iVar1,param_2,param_3,_alloccg);
    if (0 < iVar3) {
      iVar1 = param_1 + 0xc;
      (**(code **)(*(int *)(param_1 + 0x28) + 0x80))(iVar1);
      uVar2 = param_3;
      .div(param_3,iVar1);
      *(uint *)(param_1 + 0xcc) = *(int *)(param_1 + 0xcc) + uVar2;
      *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 0x42;
      iVar1 = *(int *)(param_1 + 0x40);
      _getblk(iVar1,iVar3 << ((byte)*(undefined4 *)(iVar6 + 100) & 0x1f),param_3);
      _bzero(*(undefined4 *)(iVar1 + 0x20),*(undefined4 *)(iVar1 + 0x14));
      *(undefined4 *)(iVar1 + 0x28) = 0;
      goto locret_F0048948;
    }
  }
loc_F004893C:
  _fsfull(iVar6,1);
  iVar1 = 0;
locret_F0048948:
  return CONCAT44(param_2,iVar1);
}
