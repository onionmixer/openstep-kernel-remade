
/* WARNING: Removing unreachable block (ram,0xf0090f84) */
/* WARNING: Removing unreachable block (ram,0xf0090fac) */
/* WARNING: Removing unreachable block (ram,0xf0090f48) */

undefined8
_kern_IOMapSparcDeviceMemory
          (int param_1,int param_2,uint param_3,int param_4,uint *param_5,uint param_6)

{
  uint uVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  uint uVar4;
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
  if (param_1 == 0) {
    uVar3 = 0xfffffd3f;
  }
  else {
    param_2 = *(int *)(param_2 + 0xc);
    if ((param_6 & 0xff) == 0) {
      uVar1 = *param_5 & ~_page_mask;
    }
    else {
      uVar1 = *(uint *)(param_2 + 0x14);
    }
    *param_5 = uVar1;
    iVar2 = param_2;
    _vm_map_find(param_2,0,0,param_5,param_4,(int)(char)param_6);
    uVar3 = 0xfffffd25;
    if (iVar2 == 0) {
      uVar1 = *param_5 & ~_page_mask;
      uVar4 = param_4 + _page_mask & ~_page_mask;
      _vm_map_inherit(param_2,uVar1,uVar1 + uVar4,2);
      _pmap_enter_range(*(undefined4 *)(param_2 + 0x24),uVar1,param_3 & 0xffffff00,param_3 & 0xf,
                        uVar4,3,0,1);
      uVar3 = 0;
    }
  }
  return CONCAT44(param_2,uVar3);
}

