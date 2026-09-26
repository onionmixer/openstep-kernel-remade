
/* WARNING: Removing unreachable block (ram,0xf000e7ec) */
/* WARNING: Removing unreachable block (ram,0xf000e7ac) */
/* WARNING: Removing unreachable block (ram,0xf000e6ec) */
/* WARNING: Removing unreachable block (ram,0xf000e6c4) */
/* WARNING: Removing unreachable block (ram,0xf000e6d8) */
/* WARNING: Removing unreachable block (ram,0xf000e79c) */
/* WARNING: Removing unreachable block (ram,0xf000e7d4) */
/* WARNING: Removing unreachable block (ram,0xf000e808) */
/* WARNING: Removing unreachable block (ram,0xf000e6b8) */

undefined8 _enterpgrp(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  undefined4 unaff_l0;
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
  puVar2 = param_2;
  _pgfind();
  iVar1 = (int)*(sword *)(param_1 + 0x30);
  _get_posix_proc();
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x14;
    _kalloc();
    if (param_3 == 0) {
      piVar5 = *(int **)(*(int *)(iVar1 + 0x10) + 8);
      puVar2[2] = piVar5;
      *piVar5 = *piVar5 + 1;
    }
    else {
      puVar3 = (undefined4 *)0x10;
      _kalloc();
      puVar3[1] = param_1;
      *puVar3 = 1;
      puVar3[2] = 0;
      *(undefined2 *)(puVar3 + 3) = 0;
      *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) & 0xbfffffff;
      puVar2[2] = puVar3;
    }
    puVar2[3] = param_2;
    *puVar2 = (&_pgrphash)[(uint)param_2 & 0x3f];
    (&_pgrphash)[(uint)param_2 & 0x3f] = puVar2;
    puVar2[4] = 0;
    puVar2[1] = 0;
  }
  else if (puVar2[3] == *(int *)(*(int *)(iVar1 + 0x10) + 0xc)) goto locret_F000E82C;
  if ((*(uint *)(param_1 + 0x14) & 0x4000) != 0) {
    _fixjobc(param_1,puVar2,1);
    _fixjobc(param_1,*(undefined4 *)(iVar1 + 0x10),0);
  }
  piVar5 = (int *)(*(int *)(iVar1 + 0x10) + 4);
  if (piVar5 == (int *)0x0) {
loc_F000E7EC:
    _panic(aEnterpgrpCanTF);
  }
  else {
    iVar4 = *piVar5;
    while (iVar4 != param_1) {
      iVar4 = (int)*(sword *)(iVar4 + 0x30);
      _get_posix_proc();
      piVar5 = (int *)(iVar4 + 0xc);
      if (piVar5 == (int *)0x0) goto loc_F000E7EC;
      iVar4 = *piVar5;
    }
    *piVar5 = *(int *)(iVar1 + 0xc);
  }
  if (*(int *)(*(int *)(iVar1 + 0x10) + 4) == 0) {
    _pgdelete(*(int *)(iVar1 + 0x10));
    *(undefined4 **)(iVar1 + 0x10) = puVar2;
  }
  else {
    *(undefined4 **)(iVar1 + 0x10) = puVar2;
  }
  *(undefined4 *)(iVar1 + 0xc) = puVar2[1];
  puVar2[1] = param_1;
  *(sword *)(param_1 + 0x2e) = (sword)*(undefined4 *)(*(int *)(iVar1 + 0x10) + 0xc);
locret_F000E82C:
  return CONCAT44(param_2,param_1);
}

