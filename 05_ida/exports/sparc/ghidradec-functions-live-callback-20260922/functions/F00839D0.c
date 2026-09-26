
/* WARNING: Removing unreachable block (ram,0xf0083a6c) */
/* WARNING: Removing unreachable block (ram,0xf0083a40) */
/* WARNING: Removing unreachable block (ram,0xf0083a24) */
/* WARNING: Removing unreachable block (ram,0xf0083a10) */
/* WARNING: Removing unreachable block (ram,0xf0083a2c) */
/* WARNING: Removing unreachable block (ram,0xf0083a58) */
/* WARNING: Removing unreachable block (ram,0xf0083a80) */
/* WARNING: Removing unreachable block (ram,0xf00839ec) */

undefined8
_kmem_suballoc(int param_1,undefined4 *param_2,int *param_3,int param_4,undefined4 param_5)

{
  int iVar1;
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
  uint uVar2;
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
  uVar2 = param_4 + _page_mask & ~_page_mask;
  _vm_object_reference(_vm_submap_object);
  *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(param_1 + 0x14);
  iVar1 = param_1;
  _vm_map_find(param_1,_vm_submap_object,0,(undefined *)((int)register0x00000038 + -0xc),uVar2,1);
  if (iVar1 != 0) {
    _panic(aKmemSuballoc1);
  }
  _pmap_reference(*(undefined4 *)(param_1 + 0x24));
  iVar1 = *(int *)(param_1 + 0x24);
  _vm_map_create(iVar1,*(int *)((int)register0x00000038 + -0xc),
                 *(int *)((int)register0x00000038 + -0xc) + uVar2,param_5);
  if (iVar1 == 0) {
    _panic(aKmemSuballoc2);
  }
  _vm_map_submap(param_1,*(int *)((int)register0x00000038 + -0xc),
                 *(int *)((int)register0x00000038 + -0xc) + uVar2,iVar1);
  if (param_1 != 0) {
    _panic(aKmemSuballoc3);
  }
  *param_2 = *(undefined4 *)((int)register0x00000038 + -0xc);
  *param_3 = *(int *)((int)register0x00000038 + -0xc) + uVar2;
  return CONCAT44(param_2,iVar1);
}

