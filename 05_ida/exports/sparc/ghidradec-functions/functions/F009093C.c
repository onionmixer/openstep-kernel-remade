
/* WARNING: Removing unreachable block (ram,0xf0090acc) */
/* WARNING: Removing unreachable block (ram,0xf00909d0) */
/* WARNING: Removing unreachable block (ram,0xf0090994) */
/* WARNING: Removing unreachable block (ram,0xf0090984) */
/* WARNING: Removing unreachable block (ram,0xf00909c0) */
/* WARNING: Removing unreachable block (ram,0xf0090a90) */
/* WARNING: Removing unreachable block (ram,0xf0090afc) */
/* WARNING: Removing unreachable block (ram,0xf0090970) */

undefined8
_kern_dev_map_phys(int param_1,int param_2,uint param_3,int param_4,uint *param_5,int param_6)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 uVar4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  uint uVar6;
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
  if (*(int *)((int)register0x00000038 + 0x5c) == 0) {
    uVar4 = 2;
  }
  else {
    uVar4 = 1;
    if (*(int *)((int)register0x00000038 + 0x5c) != 1) {
      uVar4 = 0;
    }
  }
  _objc_msgSend(param_1,paDevicedescript_1);
  _objc_msgSend();
  iVar2 = param_1;
  _objc_msgSend();
  if (0 < iVar2) {
    _objc_msgSend(param_1,paObjectat,0);
    _objc_msgSend((undefined *)((int)register0x00000038 + -0x10));
                    /* WARNING: Does not return */
    pcVar1 = (code *)IllegalInstructionTrap(8);
    (*pcVar1)();
  }
  if (iVar2 == 0) {
    uVar5 = 0xfffffd3f;
  }
  else {
    if (param_6 == 0) {
      uVar3 = *param_5 & ~_page_mask;
    }
    else {
      uVar3 = *(uint *)(param_2 + 0x14);
    }
    *param_5 = uVar3;
    if (((param_2 != _kernel_map) || (param_6 != 0)) || (uVar5 = 0, 0xfffff < *param_5)) {
      iVar2 = param_2;
      _vm_map_find(param_2,0,0,param_5,param_4,param_6);
      uVar5 = 0xfffffd25;
      if (iVar2 == 0) {
        uVar6 = *param_5 & ~_page_mask;
        uVar3 = param_4 + _page_mask & ~_page_mask;
        _vm_map_inherit(param_2,uVar6,uVar6 + uVar3,2);
        param_3 = param_3 & ~_page_mask;
        for (; uVar3 != 0; uVar3 = uVar3 - _page_size) {
          _pmap_enter_cache_spec(*(undefined4 *)(param_2 + 0x24),uVar6,param_3,3,1,uVar4);
          uVar6 = uVar6 + _page_size;
          param_3 = param_3 + _page_size;
        }
        uVar5 = 0;
      }
    }
  }
  return CONCAT44(param_2,uVar5);
}
