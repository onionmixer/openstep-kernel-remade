
/* WARNING: Removing unreachable block (ram,0xf0086230) */
/* WARNING: Removing unreachable block (ram,0xf00861d0) */
/* WARNING: Removing unreachable block (ram,0xf0086254) */
/* WARNING: Removing unreachable block (ram,0xf0086144) */
/* WARNING: Removing unreachable block (ram,0xf0086170) */
/* WARNING: Removing unreachable block (ram,0xf00861c0) */
/* WARNING: Removing unreachable block (ram,0xf00861f8) */
/* WARNING: Removing unreachable block (ram,0xf0086264) */
/* WARNING: Removing unreachable block (ram,0xf0086134) */

undefined8
_vm_region(int param_1,int *param_2,uint *param_3,undefined4 *param_4,undefined4 *param_5,
          undefined4 *param_6)

{
  uint uVar1;
  undefined4 unaff_l0;
  int iVar2;
  int iVar3;
  undefined4 unaff_l1;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 unaff_l3;
  uint *puVar6;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar7;
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
  puVar6 = *(uint **)((int)register0x00000038 + 0x5c);
  puVar4 = *(undefined4 **)((int)register0x00000038 + 0x60);
  piVar5 = *(int **)((int)register0x00000038 + 100);
  if (param_1 == 0) {
    uVar7 = 4;
  }
  else {
    iVar2 = *param_2;
    _lock_read(param_1);
    iVar3 = param_1;
    _vm_map_lookup_entry(param_1,iVar2,(undefined *)((int)register0x00000038 + -0xc));
    iVar2 = *(int *)((int)register0x00000038 + -0xc);
    if (iVar3 == 0) {
      iVar2 = *(int *)(*(int *)((int)register0x00000038 + -0xc) + 4);
      if (iVar2 == param_1 + 0xc) {
        _lock_done(param_1);
        uVar7 = 3;
        goto locret_F0086270;
      }
      uVar7 = *(undefined4 *)(iVar2 + 0x1c);
    }
    else {
      uVar7 = *(undefined4 *)(iVar2 + 0x1c);
    }
    iVar3 = *(int *)(iVar2 + 8);
    *param_4 = uVar7;
    *param_5 = *(undefined4 *)(iVar2 + 0x20);
    *param_6 = *(undefined4 *)(iVar2 + 0x24);
    *param_2 = iVar3;
    *param_3 = *(int *)(iVar2 + 0xc) - iVar3;
    uVar1 = *(uint *)(iVar2 + 0x18);
    param_2 = *(int **)(iVar2 + 0x14);
    if ((int)uVar1 < 0) {
      iVar3 = *(int *)(iVar2 + 0x10);
      _lock_read(iVar3);
      _vm_map_lookup_entry(iVar3,param_2,(undefined *)((int)register0x00000038 + -0xc));
      if ((uint)(*(int *)(*(int *)((int)register0x00000038 + -0xc) + 0xc) - (int)param_2) < *param_3
         ) {
        *param_3 = *(int *)(*(int *)((int)register0x00000038 + -0xc) + 0xc) - (int)param_2;
      }
      uVar7 = *(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0x10);
      _vm_object_name();
      *puVar4 = uVar7;
      *piVar5 = (int)param_2 +
                (*(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x14) -
                *(int *)(*(int *)((int)register0x00000038 + -0xc) + 8));
      *puVar6 = (uint)(*(int *)(iVar3 + 0x30) != 1);
      _lock_done(iVar3);
    }
    else {
      *puVar6 = 0;
      if ((uVar1 & 0x20000000) == 0) {
        uVar7 = *(undefined4 *)(iVar2 + 0x10);
        _vm_object_name();
        *puVar4 = uVar7;
      }
      else {
        *puVar4 = 0;
      }
      *piVar5 = (int)param_2;
    }
    _lock_done(param_1);
    uVar7 = 0;
  }
locret_F0086270:
  return CONCAT44(param_2,uVar7);
}
