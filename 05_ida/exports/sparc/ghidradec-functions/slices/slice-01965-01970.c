/* GHIDRADEC_FUNCTION index=1965 start=0xf0090d74 */

/* WARNING: Removing unreachable block (ram,0xf0090dd0) */
/* WARNING: Removing unreachable block (ram,0xf0090df4) */
/* WARNING: Removing unreachable block (ram,0xf0090db0) */

undefined8 _kern_IOMapLockShmem(undefined4 param_1,int param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
  undefined4 uVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar5;
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
  iVar3 = *(int *)(param_2 + 0xc);
  iVar1 = 0;
  if (iVar3 == 0) {
    uVar4 = 0xfffffd38;
    iVar1 = param_2;
  }
  else {
    uVar5 = param_3 + _page_mask & ~_page_mask;
    _vm_object_special(0,sub_F0090D4C,0,*param_4,uVar5);
    iVar2 = iVar3;
    _vm_map_find(iVar3,iVar1,0,param_4,uVar5,0);
    if (iVar2 != 0) {
      _vm_map_find(iVar3,iVar1,0,param_4,uVar5,1);
      uVar4 = 0xfffffd43;
      if (iVar3 != 0) goto locret_F0090E0C;
    }
    uVar4 = 0;
  }
locret_F0090E0C:
  return CONCAT44(iVar1,uVar4);
}
/* GHIDRADEC_FUNCTION index=1966 start=0xf0090e14 */

/* WARNING: Removing unreachable block (ram,0xf0090e7c) */
/* WARNING: Removing unreachable block (ram,0xf0090e94) */
/* WARNING: Removing unreachable block (ram,0xf0090e5c) */

undefined8 _kern_IOUnMapLockShmem(undefined4 param_1,int param_2,int param_3,int *param_4)

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
  int iVar2;
  uint uVar3;
  undefined4 unaff_i1;
  int iVar4;
  undefined4 unaff_i2;
  uint uVar5;
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
  iVar4 = *(int *)(param_2 + 0xc);
  if (iVar4 == 0) {
    iVar2 = -0x2c8;
  }
  else {
    uVar3 = 0;
    uVar5 = param_3 + _page_mask & ~_page_mask;
    iVar1 = *param_4;
    if (uVar5 != 0) {
      do {
        _pmap_remove(*(undefined4 *)(iVar4 + 0x24),iVar1 + uVar3,iVar1 + uVar3 + _page_size);
        uVar3 = uVar3 + _page_size;
        iVar1 = *param_4;
      } while (uVar3 < uVar5);
    }
    iVar2 = iVar4;
    _vm_map_remove(iVar4,iVar1,iVar1 + uVar5);
    if (iVar2 != 0) {
      _IOLog(aIounmaplockshm,iVar2);
    }
  }
  return CONCAT44(iVar4,iVar2);
}
/* GHIDRADEC_FUNCTION index=1967 start=0xf0090ea4 */

/* WARNING: Removing unreachable block (ram,0xf0090ed0) */

undefined8
_kern_IOMapDeviceMemory
          (int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          char param_6)

{
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
  if (param_1 == 0) {
    param_1 = -0x2c1;
  }
  else {
    _kern_dev_map_phys(param_1,*(undefined4 *)(param_2 + 0xc),param_3,param_4,param_5,(int)param_6,
                       *(undefined4 *)((int)register0x00000038 + 0x5c));
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1968 start=0xf0090eec */

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
/* GHIDRADEC_FUNCTION index=1969 start=0xf0090fc0 */

/* WARNING: Removing unreachable block (ram,0xf00910cc) */
/* WARNING: Removing unreachable block (ram,0xf009107c) */
/* WARNING: Removing unreachable block (ram,0xf0091044) */
/* WARNING: Removing unreachable block (ram,0xf0090ff4) */
/* WARNING: Removing unreachable block (ram,0xf0091008) */
/* WARNING: Removing unreachable block (ram,0xf0091050) */
/* WARNING: Removing unreachable block (ram,0xf0091090) */
/* WARNING: Removing unreachable block (ram,0xf00910dc) */
/* WARNING: Removing unreachable block (ram,0xf0090fdc) */

undefined8
_kern_IOGetDeviceConfig(int param_1,int param_2,int *param_3,undefined4 param_4,int *param_5)

{
  code *pcVar1;
  int iVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  int iVar4;
  int iVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar6;
  int iVar7;
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
  if (param_1 == 0) {
    uVar6 = 0xfffffd3f;
  }
  else {
    _objc_msgSend(param_1,paDevicedescript_1);
    iVar5 = param_1;
    _objc_msgSend();
    iVar4 = iVar5;
    _objc_msgSend(iVar5,paCount_0);
    if (0x80 < iVar4) {
      iVar4 = 0x80;
    }
    iVar7 = 0;
    if (iVar4 < 1) {
      *param_3 = iVar4;
    }
    else {
      iVar3 = 0;
      do {
        iVar2 = iVar5;
        _objc_msgSend(iVar5,paObjectat,iVar7);
        iVar7 = iVar7 + 1;
        _objc_msgSend();
        *(int *)(iVar3 + param_2) = iVar2;
        iVar3 = iVar3 + 4;
      } while (iVar7 < iVar4);
      *param_3 = iVar4;
    }
    _objc_msgSend(param_1,paResourcesforke,aMemoryMaps_2);
    iVar5 = param_1;
    _objc_msgSend(param_1,paCount_0);
    if (0x10 < iVar5) {
      iVar5 = 0x10;
    }
    uVar6 = 0;
    if (0 < iVar5) {
      _objc_msgSend(param_1,paObjectat,0);
      _objc_msgSend((undefined *)((int)register0x00000038 + -0x10));
                    /* WARNING: Does not return */
      pcVar1 = (code *)IllegalInstructionTrap(8);
      (*pcVar1)();
    }
    *param_5 = iVar5;
  }
  return CONCAT44(param_2,uVar6);
}

