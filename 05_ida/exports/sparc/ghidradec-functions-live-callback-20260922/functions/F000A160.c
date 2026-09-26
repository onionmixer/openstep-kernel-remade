
/* WARNING: Removing unreachable block (ram,0xf000a1cc) */
/* WARNING: Removing unreachable block (ram,0xf000a1a8) */

undefined8 _profil(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 unaff_l0;
  int iVar4;
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
  
  iVar1 = _active_u;
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
  puVar3 = *(undefined4 **)(dword_F0133DDC + 0x24);
  *(undefined4 *)(_active_u + 0x24c) = *puVar3;
  *(undefined4 *)(iVar1 + 0x250) = puVar3[1];
  *(undefined4 *)(iVar1 + 0x254) = puVar3[2];
  puVar3 = (undefined4 *)puVar3[3];
  *(undefined4 **)(iVar1 + 600) = puVar3;
  if (*(int *)(iVar1 + 0x244) == 0) {
    _simple_lock_alloc();
    *(undefined4 **)(iVar1 + 0x244) = puVar3;
    *puVar3 = 0;
  }
  iVar2 = *(int *)(iVar1 + 0x248);
  if (iVar2 == 0) {
    *(undefined4 *)(iVar1 + 0x248) = 0;
  }
  else {
    for (iVar4 = *(int *)(iVar2 + 4); _kfree(iVar2,0x18), iVar4 != 0; iVar4 = *(int *)(iVar4 + 4)) {
      iVar2 = iVar4;
    }
    *(undefined4 *)(iVar1 + 0x248) = 0;
  }
  return CONCAT44(param_2,param_1);
}

