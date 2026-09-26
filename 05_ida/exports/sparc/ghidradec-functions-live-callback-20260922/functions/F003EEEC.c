
/* WARNING: Removing unreachable block (ram,0xf003efcc) */
/* WARNING: Removing unreachable block (ram,0xf003ef88) */
/* WARNING: Removing unreachable block (ram,0xf003ef6c) */
/* WARNING: Removing unreachable block (ram,0xf003ef98) */
/* WARNING: Removing unreachable block (ram,0xf003efec) */
/* WARNING: Removing unreachable block (ram,0xf003ef4c) */

undefined8 sub_F003EEEC(undefined4 *param_1,int param_2,int param_3,uint param_4,sword *param_5)

{
  undefined4 unaff_l0;
  undefined4 *puVar1;
  undefined4 unaff_l1;
  int iVar2;
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
  bool bVar3;
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
  puVar1 = (undefined4 *)0x0;
  if (param_1[10] != 1) {
    puVar1 = (undefined4 *)0x15;
    goto locret_F003EFF8;
  }
  iVar2 = param_1[0xc];
  if ((param_3 == 1) ||
     ((bVar3 = (param_4 & 2) == 0, param_3 == 0 &&
      (bVar3 = (param_4 & 2) == 0, *(int *)(iVar2 + 0x70) == 0)))) {
    *param_5 = *param_5 + 1;
    if (*(int *)(iVar2 + 0x70) == 0) {
      *(sword **)(iVar2 + 0x70) = param_5;
    }
    else {
      _crfree();
      *(sword **)(iVar2 + 0x70) = param_5;
    }
    bVar3 = (param_4 & 2) == 0;
    if (*(int *)*param_1 != 0) {
      _vnode_uncache(param_1);
      bVar3 = (param_4 & 2) == 0;
    }
  }
  if (bVar3) {
loc_F003EFB0:
    bVar3 = puVar1 == (undefined4 *)0x0;
  }
  else {
    bVar3 = true;
    if (param_3 == 1) {
      _rlock(iVar2);
      puVar1 = param_1;
      sub_F003F730(param_1,(undefined *)((int)register0x00000038 + -0x48),param_5);
      bVar3 = false;
      if (puVar1 == (undefined4 *)0x0) {
        *(undefined4 *)(param_2 + 8) = *(undefined4 *)((int)register0x00000038 + -0x30);
        goto loc_F003EFB0;
      }
    }
  }
  if (bVar3) {
    sub_F003F000(param_1,param_2,param_3,param_4,param_5);
    puVar1 = param_1;
  }
  if (((param_4 & 2) != 0) && (param_3 == 1)) {
    _runlock(iVar2);
  }
locret_F003EFF8:
  return CONCAT44(param_2,puVar1);
}

