/* GHIDRADEC_FUNCTION index=1960 start=0xf009093c */

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
/* GHIDRADEC_FUNCTION index=1961 start=0xf0090b24 */

/* WARNING: Removing unreachable block (ram,0xf0090bc4) */
/* WARNING: Removing unreachable block (ram,0xf0090ba0) */
/* WARNING: Removing unreachable block (ram,0xf0090b74) */
/* WARNING: Removing unreachable block (ram,0xf0090b5c) */
/* WARNING: Removing unreachable block (ram,0xf0090b88) */
/* WARNING: Removing unreachable block (ram,0xf0090bb4) */
/* WARNING: Removing unreachable block (ram,0xf0090bd0) */
/* WARNING: Removing unreachable block (ram,0xf0090b3c) */

undefined8 _kern_IOProbeDriver(int param_1,undefined4 param_2,int param_3)

{
  undefined6 *puVar1;
  int iVar2;
  undefined (*pauVar3) [16];
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar4;
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
    uVar4 = 0xfffffd3f;
  }
  else {
    iVar2 = param_3 + 1;
    _IOMalloc();
    if (iVar2 == 0) {
      uVar4 = 0xfffffd25;
    }
    else {
      _bcopy(param_2,iVar2,param_3);
      pauVar3 = paNxconditionloc;
      puVar1 = paAlloc;
      *(undefined *)(iVar2 + param_3) = 0;
      _objc_msgSend(pauVar3,puVar1);
      _objc_msgSend();
      *(undefined (**) [16])((int)register0x00000038 + -0x18) = pauVar3;
      *(int *)((int)register0x00000038 + -0x14) = iVar2;
      _IOForkThread(_configureThread,(undefined *)((int)register0x00000038 + -0x18));
      _objc_msgSend(pauVar3,paLockwhen,1);
      _objc_msgSend(pauVar3,paFree);
      _IOFree(iVar2,param_3 + 1);
      uVar4 = (*(char *)((int)register0x00000038 + -0x10) != '\0') - 1 & 0xfffffd40;
    }
  }
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=1962 start=0xf0090bf0 */

/* WARNING: Removing unreachable block (ram,0xf0090c30) */
/* WARNING: Removing unreachable block (ram,0xf0090c4c) */
/* WARNING: Removing unreachable block (ram,0xf0090c14) */

undefined8 _kern_IOGetDriverConfig(int param_1,uint param_2,uint param_3,int param_4,int *param_5)

{
  uint uVar1;
  uint uVar2;
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
    if (0xfff < param_3) {
      param_3 = 0xfff;
    }
    uVar1 = param_2;
    _findBootConfigString();
    if (uVar1 == 0) {
      uVar3 = 0xfffffd40;
    }
    else {
      uVar2 = uVar1;
      _strlen();
      if (uVar2 < param_3) {
        param_3 = uVar2;
      }
      _bcopy(uVar1,param_4,param_3);
      *(undefined *)(param_4 + param_3) = 0;
      *param_5 = param_3 + 1;
      uVar3 = 0;
    }
  }
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=1963 start=0xf0090c6c */

/* WARNING: Removing unreachable block (ram,0xf0090c80) */

undefined8
_kern_IOGetSystemConfig(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
  _kern_IOGetDriverConfig(param_1,0,param_2,param_3,param_4);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1964 start=0xf0090c90 */

/* WARNING: Removing unreachable block (ram,0xf0090cf0) */
/* WARNING: Removing unreachable block (ram,0xf0090d1c) */
/* WARNING: Removing unreachable block (ram,0xf0090ccc) */
/* WARNING: Removing unreachable block (ram,0xf0090cd4) */
/* WARNING: Removing unreachable block (ram,0xf0090d38) */
/* WARNING: Removing unreachable block (ram,0xf0090d08) */
/* WARNING: Removing unreachable block (ram,0xf0090cb4) */

undefined8 _kern_IOUnloadDriver(int param_1,undefined (*param_2) [14])

{
  undefined (*pauVar1) [14];
  undefined (*pauVar2) [14];
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
    pauVar1 = paIoconfigtable;
    _objc_msgSend(paIoconfigtable,paNewforconfigda,param_2);
    param_2 = pauVar1;
    _objc_msgSend();
    pauVar2 = param_2;
    _objc_getClass();
    if (pauVar2 == (undefined (*) [14])0x0) {
      _IOLog(aIounloaddriver,param_2);
      if (pauVar1 != (undefined (*) [14])0x0) {
        _objc_msgSend(pauVar1,paFree);
      }
      uVar3 = 0xfffffd3e;
    }
    else {
      _objc_msgSend();
      if (pauVar1 == (undefined (*) [14])0x0) {
        uVar3 = 0;
      }
      else {
        _objc_msgSend(pauVar1,paFree);
        uVar3 = 0;
      }
    }
  }
  return CONCAT44(param_2,uVar3);
}

