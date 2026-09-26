
/* WARNING: Removing unreachable block (ram,0xf00ef708) */
/* WARNING: Removing unreachable block (ram,0xf00ef6f4) */
/* WARNING: Removing unreachable block (ram,0xf00ef720) */
/* WARNING: Removing unreachable block (ram,0xf00ef6e4) */

undefined8 sub_F00EF6A4(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined *puVar2;
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
  if (dword_F012F0DC == (undefined *)0x0) {
    *(code **)((int)register0x00000038 + -0x18) = __mapStrHash;
    *(code **)((int)register0x00000038 + -0x14) = __mapStrIsEqual;
    *(code **)((int)register0x00000038 + -0x10) = __mapNoFree;
    uVar1 = 0;
    *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
    puVar2 = (undefined *)((int)register0x00000038 + -0x18);
    __objc_create_zone();
    _NXCreateMapTableFromZone(puVar2,8,uVar1);
    dword_F012F0DC = puVar2;
  }
  puVar2 = dword_F012F0DC;
  _NXMapGet(dword_F012F0DC,*(undefined4 *)(param_1 + 8));
  if (puVar2 == (undefined *)0x0) {
    _NXMapInsert(dword_F012F0DC,*(undefined4 *)(param_1 + 8),param_1);
  }
  return CONCAT44(param_2,param_1);
}
