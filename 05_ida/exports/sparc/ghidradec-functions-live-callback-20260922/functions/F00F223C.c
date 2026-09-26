
/* WARNING: Removing unreachable block (ram,0xf00f22f8) */
/* WARNING: Removing unreachable block (ram,0xf00f22c8) */
/* WARNING: Removing unreachable block (ram,0xf00f22ac) */
/* WARNING: Removing unreachable block (ram,0xf00f229c) */
/* WARNING: Removing unreachable block (ram,0xf00f22c0) */
/* WARNING: Removing unreachable block (ram,0xf00f22d0) */
/* WARNING: Removing unreachable block (ram,0xf00f2254) */
/* WARNING: Removing unreachable block (ram,0xf00f2240) */

undefined8 sub_F00F223C(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  undefined4 unaff_l0;
  int *piVar5;
  undefined4 unaff_l1;
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
  iVar1 = *(int *)(param_1 + 4);
  _objc_lookUpClass();
  if (iVar1 == 0) {
    if (dword_F012F14C == (int *)0x0) {
      *(undefined4 *)((int)register0x00000038 + -0x18) = uRamf00f0ad8;
      *(code **)((int)register0x00000038 + -0x14) = __mapStrIsEqual;
      *(code **)((int)register0x00000038 + -0x10) = __mapNoFree;
      uVar2 = 0;
      *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
      piVar5 = (int *)((int)register0x00000038 + -0x18);
      __objc_create_zone();
      _NXCreateMapTableFromZone(piVar5,0x80,uVar2);
      dword_F012F14C = piVar5;
    }
    piVar5 = dword_F012F14C;
    _NXMapGet(dword_F012F14C,*(undefined4 *)(param_1 + 4));
    piVar3 = piVar5;
    __objc_create_zone();
    piVar4 = piVar3;
    __objc_create_zone();
    (*(code *)piVar3[1])();
    *piVar4 = (int)piVar5;
    piVar4[1] = param_1;
    piVar4[2] = param_2;
    _NXMapInsert(dword_F012F14C,*(undefined4 *)(param_1 + 4));
  }
  else {
    __objc_add_category(param_1,param_2);
  }
  return CONCAT44(param_2,param_1);
}

