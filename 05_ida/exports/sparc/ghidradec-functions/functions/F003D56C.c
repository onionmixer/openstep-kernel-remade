
/* WARNING: Removing unreachable block (ram,0xf003d5c4) */
/* WARNING: Removing unreachable block (ram,0xf003d570) */

undefined8 _newname(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined5 *puVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined *puVar5;
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
  puVar2 = (undefined *)0xff;
  _kalloc();
  puVar3 = &aNfs;
  puVar5 = puVar2;
  do {
    *puVar5 = *(undefined *)puVar3;
    puVar3 = (undefined5 *)((int)puVar3 + 1);
    puVar5 = puVar5 + 1;
  } while (puVar3 < (undefined5 *)((int)&aNfs + 4));
  if (dword_F012F4EC == 0) {
    _getthetime((undefined *)((int)register0x00000038 + -0x10));
    dword_F012F4EC = *(uint *)((int)register0x00000038 + -0x10) & 0xffff;
  }
  iVar1 = dword_F012F4EC + 1;
  for (uVar4 = dword_F012F4EC; dword_F012F4EC = iVar1, uVar4 != 0; uVar4 = (int)uVar4 >> 4) {
    *puVar5 = a0123456789abcd_0[uVar4 & 0xf];
    puVar5 = puVar5 + 1;
    iVar1 = dword_F012F4EC;
  }
  *puVar5 = 0;
  return CONCAT44(param_2,puVar2);
}
