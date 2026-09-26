
/* WARNING: Removing unreachable block (ram,0xf008def4) */
/* WARNING: Removing unreachable block (ram,0xf008de88) */
/* WARNING: Removing unreachable block (ram,0xf008de44) */
/* WARNING: Removing unreachable block (ram,0xf008ded8) */
/* WARNING: Removing unreachable block (ram,0xf008de58) */
/* WARNING: Removing unreachable block (ram,0xf008ddfc) */

undefined8
__KernBusMemoryCreateMapping
          (uint param_1,int param_2,uint *param_3,int param_4,uint param_5,int param_6)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined4 uVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar4;
  undefined4 unaff_i3;
  int iVar5;
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
  iVar5 = *(int *)(param_4 + 0xc);
  _vm_map_reference(iVar5);
  if ((param_5 & 0xff) == 0) {
    uVar1 = *param_3 & ~_page_mask;
  }
  else {
    uVar1 = *(uint *)(iVar5 + 0x14);
  }
  *param_3 = uVar1;
  iVar3 = iVar5;
  _vm_map_find(iVar5,0,0,param_3,param_2,(int)(char)param_5);
  if (iVar3 == 0) {
    uVar4 = *param_3 & ~_page_mask;
    uVar1 = param_2 + _page_mask & ~_page_mask;
    _vm_map_inherit(iVar5,uVar4,uVar4 + uVar1,2);
    param_1 = param_1 & ~_page_mask;
    if (param_6 == 0) {
      uVar2 = 2;
    }
    else {
      uVar2 = 1;
      if (param_6 != 1) {
        uVar2 = 0;
      }
    }
    for (; uVar1 != 0; uVar1 = uVar1 - _page_size) {
      _pmap_enter_cache_spec(*(undefined4 *)(iVar5 + 0x24),uVar4,param_1,3,1,uVar2);
      uVar4 = uVar4 + _page_size;
      param_1 = param_1 + _page_size;
    }
    _vm_map_deallocate(iVar5);
    iVar3 = 0;
    param_2 = 0;
  }
  else {
    _vm_map_deallocate(iVar5);
  }
  return CONCAT44(param_2,iVar3);
}

