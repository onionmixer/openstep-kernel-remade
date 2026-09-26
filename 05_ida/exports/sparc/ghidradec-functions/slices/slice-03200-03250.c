/* GHIDRADEC_FUNCTION index=3200 start=0xf00f15d0 */

/* WARNING: Removing unreachable block (ram,0xf00f1858) */
/* WARNING: Removing unreachable block (ram,0xf00f1828) */
/* WARNING: Removing unreachable block (ram,0xf00f17d0) */
/* WARNING: Removing unreachable block (ram,0xf00f16e0) */
/* WARNING: Removing unreachable block (ram,0xf00f1640) */
/* WARNING: Removing unreachable block (ram,0xf00f1650) */
/* WARNING: Removing unreachable block (ram,0xf00f1758) */
/* WARNING: Removing unreachable block (ram,0xf00f1814) */
/* WARNING: Removing unreachable block (ram,0xf00f1844) */
/* WARNING: Removing unreachable block (ram,0xf00f1860) */
/* WARNING: Removing unreachable block (ram,0xf00f15e8) */

undefined8 _objc_unregisterModule(undefined4 *param_1,code *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 unaff_l0;
  undefined4 uVar5;
  undefined4 unaff_l1;
  uint uVar6;
  int iVar7;
  undefined4 unaff_l3;
  int iVar8;
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
  puVar1 = param_1;
  _getsectdatafromheader(param_1,&aObjc,aModuleInfo,(undefined *)((int)register0x00000038 + -0xc));
  puVar4 = puVar1;
  for (iVar8 = *(int *)((int)register0x00000038 + -0xc);
      (puVar4 != (undefined4 *)0x0 && (iVar8 != 0)); iVar8 = iVar8 - iVar2) {
    iVar2 = puVar4[3];
    uVar6 = (uint)*(word *)(iVar2 + 8);
    if (uVar6 < uVar6 + *(word *)(iVar2 + 10)) {
      do {
        iVar2 = *(int *)(uVar6 * 4 + iVar2 + 0xc);
        if (param_2 != (code *)0x0) {
          _objc_getClass(*(undefined4 *)(iVar2 + 4));
          (*param_2)();
        }
        sub_F00F0C7C(iVar2);
        uVar6 = uVar6 + 1;
        iVar2 = puVar4[3];
      } while ((int)uVar6 < (int)((uint)*(word *)(iVar2 + 8) + (uint)*(word *)(iVar2 + 10)));
      iVar2 = puVar4[1];
    }
    else {
      iVar2 = puVar4[1];
    }
    puVar4 = (undefined4 *)((int)puVar4 + iVar2);
  }
  puVar4 = puVar1;
  for (iVar8 = *(int *)((int)register0x00000038 + -0xc);
      (puVar4 != (undefined4 *)0x0 && (iVar8 != 0)); iVar8 = iVar8 - iVar2) {
    iVar7 = 0;
    iVar2 = puVar4[3];
    if (*(sword *)(iVar2 + 8) == 0) {
      iVar2 = puVar4[1];
    }
    else {
      iVar3 = 0;
      do {
        uVar5 = *(undefined4 *)(iVar3 + iVar2 + 0xc);
        if (param_2 != (code *)0x0) {
          (*param_2)(uVar5,0);
        }
        sub_F00F0C40(uVar5);
        iVar7 = iVar7 + 1;
        iVar2 = puVar4[3];
        iVar3 = iVar7 * 4;
      } while (iVar7 < (int)(uint)*(word *)(iVar2 + 8));
      iVar2 = puVar4[1];
    }
    puVar4 = (undefined4 *)((int)puVar4 + iVar2);
  }
  puVar4 = puVar1;
  for (iVar8 = *(int *)((int)register0x00000038 + -0xc);
      (puVar4 != (undefined4 *)0x0 && (iVar8 != 0)); iVar8 = iVar8 - iVar2) {
    iVar2 = puVar4[3];
    uVar6 = (uint)*(word *)(iVar2 + 8);
    if (uVar6 < uVar6 + *(word *)(iVar2 + 10)) {
      do {
        __objc_remove_category(*(undefined4 *)(uVar6 * 4 + iVar2 + 0xc),*puVar4);
        uVar6 = uVar6 + 1;
        iVar2 = puVar4[3];
      } while ((int)uVar6 < (int)((uint)*(word *)(iVar2 + 8) + (uint)*(word *)(iVar2 + 10)));
      iVar2 = puVar4[1];
    }
    else {
      iVar2 = puVar4[1];
    }
    puVar4 = (undefined4 *)((int)puVar4 + iVar2);
  }
  for (iVar8 = *(int *)((int)register0x00000038 + -0xc);
      (puVar1 != (undefined4 *)0x0 && (iVar8 != 0)); iVar8 = iVar8 - iVar2) {
    iVar7 = 0;
    iVar2 = puVar1[3];
    if (*(sword *)(iVar2 + 8) == 0) {
      iVar2 = puVar1[1];
    }
    else {
      iVar3 = 0;
      do {
        __objc_removeClass(*(undefined4 *)(iVar3 + iVar2 + 0xc));
        iVar7 = iVar7 + 1;
        iVar2 = puVar1[3];
        iVar3 = iVar7 * 4;
      } while (iVar7 < (int)(uint)*(word *)(iVar2 + 8));
      iVar2 = puVar1[1];
    }
    puVar1 = (undefined4 *)((int)puVar1 + iVar2);
  }
  puVar4 = param_1;
  _getsectdatafromheader
            (param_1,&aObjc,aMethVarNames,(undefined *)((int)register0x00000038 + -0x10));
  if (puVar4 != (undefined4 *)0x0) {
    __sel_unloadSelectors();
  }
  puVar4 = param_1;
  _getsectdatafromheader
            (param_1,&aObjc,aSelectorStrs,(undefined *)((int)register0x00000038 + -0x10));
  if (puVar4 != (undefined4 *)0x0) {
    __sel_unloadSelectors();
  }
  __objc_removeHeader(param_1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3201 start=0xf00f1870 */

/* WARNING: Removing unreachable block (ram,0xf00f18f8) */
/* WARNING: Removing unreachable block (ram,0xf00f1968) */

sqword _objc_msgSend(int *param_1,uint param_2,undefined4 param_3,undefined4 param_4,
                    undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE_00;
  int in_o7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar2;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  uint *puVar3;
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
  if ((__objc_multithread_mask & (uint)param_1) == 0) {
    if (param_1 == (int *)0x0) {
      if ((*(uint *)(in_o7 + 8) & 0xffc00000) == 0) {
        return (qword)param_2 << 0x20;
      }
      return (qword)param_2 << 0x20;
    }
    do {
      iVar1 = _messageLock;
      _messageLock = 1;
    } while (iVar1 != 0);
    UNRECOVERED_JUMPTABLE_00 = (code *)*param_1;
    uVar2 = param_2;
    do {
      uVar2 = uVar2 & **(uint **)(UNRECOVERED_JUMPTABLE_00 + 0x20);
      puVar3 = (uint *)(*(uint **)(UNRECOVERED_JUMPTABLE_00 + 0x20))[uVar2 + 2];
      if (puVar3 == (uint *)0x0) {
        __class_lookupMethodAndLoadCache(UNRECOVERED_JUMPTABLE_00,param_2);
loc_F00F1970:
        _messageLock = 0;
                    /* WARNING: Could not recover jumptable at 0xf00f1974. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)(param_1,param_2,param_3,param_4,param_5,param_6);
        return CONCAT44(param_2,param_1);
      }
      if (*puVar3 == param_2) {
        UNRECOVERED_JUMPTABLE_00 = (code *)puVar3[2];
        goto loc_F00F1970;
      }
      uVar2 = uVar2 + 1;
    } while( true );
  }
  UNRECOVERED_JUMPTABLE_00 = (code *)*param_1;
  uVar2 = param_2;
  do {
    uVar2 = uVar2 & **(uint **)(UNRECOVERED_JUMPTABLE_00 + 0x20);
    puVar3 = (uint *)(*(uint **)(UNRECOVERED_JUMPTABLE_00 + 0x20))[uVar2 + 2];
    if (puVar3 == (uint *)0x0) {
      __class_lookupMethodAndLoadCache(UNRECOVERED_JUMPTABLE_00,param_2);
loc_F00F1900:
                    /* WARNING: Could not recover jumptable at 0xf00f1900. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE_00)(param_1,param_2,param_3,param_4,param_5,param_6);
      return CONCAT44(param_2,param_1);
    }
    if (*puVar3 == param_2) {
      UNRECOVERED_JUMPTABLE_00 = (code *)puVar3[2];
      goto loc_F00F1900;
    }
    uVar2 = uVar2 + 1;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=3202 start=0xf00f197c */

/* WARNING: Removing unreachable block (ram,0xf00f1a84) */
/* WARNING: Removing unreachable block (ram,0xf00f1a08) */

undefined8
_objc_msgSendSuper(int *param_1,uint param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5,undefined4 param_6)

{
  char cVar1;
  code *UNRECOVERED_JUMPTABLE_00;
  undefined4 uVar2;
  int in_o7;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  uint uVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  uint *puVar5;
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
  iVar3 = *param_1;
  *(int *)((int)register0x00000038 + 0x44) = iVar3;
  if (iVar3 == 0) {
    if ((*(uint *)(in_o7 + 8) & 0xffc00000) != 0) {
      return CONCAT44(param_2,param_1);
    }
    return CONCAT44(param_2,param_1);
  }
  UNRECOVERED_JUMPTABLE_00 = (code *)param_1[1];
  if (__objc_multithread_mask != 0) {
    uVar4 = param_2;
    while( true ) {
      uVar4 = uVar4 & **(uint **)(UNRECOVERED_JUMPTABLE_00 + 0x20);
      puVar5 = (uint *)(*(uint **)(UNRECOVERED_JUMPTABLE_00 + 0x20))[uVar4 + 2];
      if (puVar5 == (uint *)0x0) {
        __class_lookupMethodAndLoadCache(UNRECOVERED_JUMPTABLE_00,param_2);
                    /* WARNING: Could not recover jumptable at 0xf00f1a18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar2 = *(undefined4 *)((int)register0x00000038 + 0x44);
        (*UNRECOVERED_JUMPTABLE_00)(uVar2,param_2,param_3,param_4,param_5,param_6);
        return CONCAT44(param_2,uVar2);
      }
      if (*puVar5 == param_2) break;
      uVar4 = uVar4 + 1;
    }
                    /* WARNING: Could not recover jumptable at 0xf00f1a24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = *(undefined4 *)((int)register0x00000038 + 0x44);
    (*(code *)puVar5[2])(uVar2,param_2,param_3,param_4,param_5,param_6);
    return CONCAT44(param_2,uVar2);
  }
  do {
    cVar1 = _messageLock._0_1_;
    _messageLock = CONCAT13(0xff,_messageLock._1_3_);
  } while (cVar1 != '\0');
  uVar4 = param_2;
  while( true ) {
    uVar4 = uVar4 & **(uint **)(UNRECOVERED_JUMPTABLE_00 + 0x20);
    puVar5 = (uint *)(*(uint **)(UNRECOVERED_JUMPTABLE_00 + 0x20))[uVar4 + 2];
    if (puVar5 == (uint *)0x0) {
      __class_lookupMethodAndLoadCache(UNRECOVERED_JUMPTABLE_00,param_2);
      _messageLock = 0;
                    /* WARNING: Could not recover jumptable at 0xf00f1a98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = *(undefined4 *)((int)register0x00000038 + 0x44);
      (*UNRECOVERED_JUMPTABLE_00)(uVar2,param_2,param_3,param_4,param_5,param_6);
      return CONCAT44(param_2,uVar2);
    }
    if (*puVar5 == param_2) break;
    uVar4 = uVar4 + 1;
  }
  _messageLock = 0;
                    /* WARNING: Could not recover jumptable at 0xf00f1aa8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = *(undefined4 *)((int)register0x00000038 + 0x44);
  (*(code *)puVar5[2])(uVar2,param_2,param_3,param_4,param_5,param_6);
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=3203 start=0xf00f1ab0 */

/* WARNING: Removing unreachable block (ram,0xf00f1af0) */

undefined8
__objc_msgForward(undefined4 param_1,undefined (*param_2) [10],undefined4 param_3,undefined4 param_4
                 ,undefined4 param_5,undefined4 param_6)

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
  if (param_2 == paForward) {
    __objc_error(param_1,param_2,param_2);
    return CONCAT44(param_2,param_1);
  }
  *(undefined4 *)((int)register0x00000038 + 0x44) = param_1;
  *(undefined (**) [10])((int)register0x00000038 + 0x48) = param_2;
  *(undefined4 *)((int)register0x00000038 + 0x4c) = param_3;
  *(undefined4 *)((int)register0x00000038 + 0x50) = param_4;
  *(undefined4 *)((int)register0x00000038 + 0x54) = param_5;
  *(undefined4 *)((int)register0x00000038 + 0x58) = param_6;
  _objc_msgSend(param_1,paForward,param_2,(undefined4 *)((int)register0x00000038 + 0x44));
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3204 start=0xf00f1b14 */

/* WARNING: Removing unreachable block (ram,0xf00f1bd0) */
/* WARNING: Removing unreachable block (ram,0xf00f1bb4) */

undefined8
_objc_msgSendv(undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
              undefined4 param_6)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  int in_o7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 *puVar6;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 *puVar7;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  uVar2 = 0xffffffa0;
  if (param_3 + -0x1c != 0 && 0x1b < param_3) {
    uVar2 = -(param_3 + -0x1c) - 0x60U & 0xfffffff8;
  }
  puVar5 = (undefined *)register0x00000038;
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
  iVar3 = param_3;
  iVar4 = param_4;
  if ((((param_3 != 8) && (iVar3 = *(int *)(param_4 + 8), param_3 != 0xc)) &&
      (iVar4 = *(int *)(param_4 + 0xc), param_3 != 0x10)) &&
     (param_5 = *(undefined4 *)(param_4 + 0x10), param_3 != 0x14)) {
    param_6 = *(undefined4 *)(param_4 + 0x14);
    param_3 = param_3 + -0x18;
    if (param_3 != 0) {
      puVar6 = (undefined4 *)(param_4 + 0x18);
      puVar7 = (undefined4 *)(&stack0x0000005c + uVar2);
      do {
        param_3 = param_3 + -4;
        *puVar7 = *puVar6;
        puVar7 = puVar7 + 1;
        puVar6 = puVar6 + 1;
      } while (param_3 != 0);
    }
  }
  if ((*(uint *)(in_o7 + 8) & 0xffc00000) != 0) {
    _objc_msgSend(param_1,param_2,iVar3,iVar4,param_5,param_6);
    return CONCAT44(param_2,param_1);
  }
  *(undefined4 *)(auStackX_0 + uVar2 + 0x40) = *(undefined4 *)(puVar5 + 0x40);
  _objc_msgSend(param_1,param_2,iVar3,iVar4,param_5,param_6);
                    /* WARNING: Does not return */
  pcVar1 = (code *)IllegalInstructionTrap(0);
  (*pcVar1)();
}
/* GHIDRADEC_FUNCTION index=3205 start=0xf00f1be4 */

/* WARNING: Removing unreachable block (ram,0xf00f1bf8) */

undefined8
_getsectdatafromheaderinfo(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
  iVar1 = *param_1;
  _getsectdatafromheader(iVar1,param_2,param_3,param_4);
  if (iVar1 != 0) {
    iVar1 = iVar1 + param_1[4];
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=3206 start=0xf00f1cd0 */

undefined4 _objc_getClasses(void)

{
  return dword_F012F12C;
}
/* GHIDRADEC_FUNCTION index=3207 start=0xf00f1cf8 */

void _objc_setClassHandler(void *param_1)

{
  off_F012F148 = param_1;
  return;
}
/* GHIDRADEC_FUNCTION index=3208 start=0xf00f1d04 */

/* WARNING: Removing unreachable block (ram,0xf00f1d48) */
/* WARNING: Removing unreachable block (ram,0xf00f1d1c) */

undefined8 _objc_getClass(int param_1,undefined4 param_2)

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
  *(int *)((int)register0x00000038 + -0x28) = param_1;
  iVar1 = dword_F012F12C;
  _NXHashGet(dword_F012F12C,(undefined *)((int)register0x00000038 + -0x30));
  if ((iVar1 == 0) && ((*off_F012F148)(), param_1 != 0)) {
    iVar1 = dword_F012F12C;
    _NXHashGet(dword_F012F12C,(undefined *)((int)register0x00000038 + -0x30));
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=3209 start=0xf00f1d5c */

/* WARNING: Removing unreachable block (ram,0xf00f1d6c) */

undefined8 _objc_lookUpClass(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
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
  *(undefined4 *)((int)register0x00000038 + -0x28) = param_1;
  uVar1 = dword_F012F12C;
  _NXHashGet(dword_F012F12C,(undefined *)((int)register0x00000038 + -0x30));
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=3210 start=0xf00f1d7c */

/* WARNING: Removing unreachable block (ram,0xf00f1d80) */

undefined8 _objc_getMetaClass(undefined4 *param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  _objc_getClass();
  if (param_1 == (undefined4 *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *param_1;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=3211 start=0xf00f1da0 */

/* WARNING: Removing unreachable block (ram,0xf00f1dfc) */

undefined8 _objc_addClass(int *param_1,undefined4 param_2)

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
  if (param_1[8] == 0) {
    param_1[8] = (int)_emptyCache;
    param_1[4] = 1;
    iVar1 = *param_1;
  }
  else {
    iVar1 = *param_1;
  }
  if (*(int *)(iVar1 + 0x20) == 0) {
    *(undefined **)(iVar1 + 0x20) = _emptyCache;
    *(undefined4 *)(*param_1 + 0x10) = 2;
  }
  _NXHashInsert(dword_F012F12C,param_1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3212 start=0xf00f1e0c */

/* WARNING: Removing unreachable block (ram,0xf00f1e18) */

undefined8 __objc_removeClass(undefined4 param_1,undefined4 param_2)

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
  _NXHashRemove(dword_F012F12C,param_1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3213 start=0xf00f1e28 */

/* WARNING: Removing unreachable block (ram,0xf00f1e9c) */
/* WARNING: Removing unreachable block (ram,0xf00f1ed0) */
/* WARNING: Removing unreachable block (ram,0xf00f1e94) */

undefined8 _objc_getModules(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
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
  if (dword_F0133CEC == (int *)0x0) {
    uVar5 = 0;
    piVar1 = (int *)0x0;
    if (dword_F012F128 != 0) {
      do {
        piVar1 = *(int **)(dword_F012F124 + uVar5 * 0x18 + 8);
        dword_F0133CE8 = dword_F0133CE8 + (int)piVar1;
        uVar5 = uVar5 + 1;
      } while (uVar5 < dword_F012F128);
    }
    __objc_create_zone();
    piVar2 = piVar1;
    __objc_create_zone();
    (*(code *)piVar1[1])();
    dword_F0133CEC = piVar2;
    if (piVar2 == (int *)0x0) {
      __objc_fatal(aUnableToAlloca_0);
    }
    uVar5 = 0;
    piVar1 = dword_F0133CEC;
    if (dword_F012F128 == 0) {
      *dword_F0133CEC = 0;
    }
    else {
      do {
        iVar3 = dword_F012F124 + uVar5 * 0x18;
        iVar6 = *(int *)(iVar3 + 4);
        uVar4 = 0;
        if (*(int *)(iVar3 + 8) != 0) {
          do {
            *piVar1 = iVar6 + uVar4 * 0x10;
            uVar4 = uVar4 + 1;
            piVar1 = piVar1 + 1;
          } while (uVar4 < *(uint *)(dword_F012F124 + uVar5 * 0x18 + 8));
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < dword_F012F128);
      *piVar1 = 0;
    }
  }
  return CONCAT44(param_2,dword_F0133CEC);
}
/* GHIDRADEC_FUNCTION index=3214 start=0xf00f1f84 */

/* WARNING: Removing unreachable block (ram,0xf00f1fb8) */
/* WARNING: Removing unreachable block (ram,0xf00f1fe8) */
/* WARNING: Removing unreachable block (ram,0xf00f1fb0) */
/* WARNING: Removing unreachable block (ram,0xf00f2028) */
/* WARNING: Removing unreachable block (ram,0xf00f1fe0) */

undefined8 _objc_addModule(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
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
  dword_F0133CE8 = dword_F0133CE8 + 1;
  if (dword_F0133CEC == (undefined4 *)0x0) {
    puVar2 = dword_F0133CEC;
    __objc_create_zone();
    puVar3 = puVar2;
    __objc_create_zone();
    (*(code *)puVar2[1])();
    dword_F0133CEC = puVar3;
  }
  else {
    puVar2 = dword_F0133CEC;
    __objc_create_zone();
    puVar3 = puVar2;
    __objc_create_zone();
    (*(code *)*puVar2)();
    dword_F0133CEC = puVar3;
  }
  if (dword_F0133CEC == (undefined4 *)0x0) {
    __objc_fatal(aUnableToReallo);
  }
  puVar2 = dword_F0133CEC;
  iVar1 = dword_F0133CE8;
  dword_F0133CEC[dword_F0133CE8 + -1] = param_1;
  puVar2[iVar1] = 0;
  return CONCAT44(param_2,puVar2);
}
/* GHIDRADEC_FUNCTION index=3215 start=0xf00f2058 */

/* WARNING: Removing unreachable block (ram,0xf00f20cc) */
/* WARNING: Removing unreachable block (ram,0xf00f2098) */
/* WARNING: Removing unreachable block (ram,0xf00f2080) */
/* WARNING: Removing unreachable block (ram,0xf00f20bc) */
/* WARNING: Removing unreachable block (ram,0xf00f20dc) */
/* WARNING: Removing unreachable block (ram,0xf00f205c) */

undefined8 __objc_remove_category(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
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
  puVar1 = (undefined4 *)param_1[1];
  _objc_getClass();
  if (puVar1 == (undefined4 *)0x0) {
    __objc_inform(aUnableToRemove,*param_1);
    __objc_inform(aClassSNotLinke_0,param_1[1]);
  }
  else {
    if (param_1[2] == 0) {
      iVar2 = param_1[3];
    }
    else {
      _class_removeMethods();
      iVar2 = param_1[3];
    }
    if (iVar2 != 0) {
      _class_removeMethods(*puVar1);
    }
    if ((4 < param_2) && (param_1[4] != 0)) {
      __class_removeProtocols(puVar1);
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3216 start=0xf00f20ec */

/* WARNING: Removing unreachable block (ram,0xf00f21cc) */
/* WARNING: Removing unreachable block (ram,0xf00f21b4) */
/* WARNING: Removing unreachable block (ram,0xf00f219c) */
/* WARNING: Removing unreachable block (ram,0xf00f21c4) */
/* WARNING: Removing unreachable block (ram,0xf00f21d4) */
/* WARNING: Removing unreachable block (ram,0xf00f20f0) */

undefined8 __objc_add_category(undefined4 *param_1,int param_2)

{
  int *piVar1;
  undefined *puVar2;
  undefined4 *puVar3;
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
  piVar1 = (int *)param_1[1];
  _objc_getClass();
  if (piVar1 == (int *)0x0) {
    __objc_inform(aUnableToAddCat,*param_1);
    puVar2 = aClassSNotLinke_0;
  }
  else {
    if ((int *)param_1[2] == (int *)0x0) {
      puVar3 = (undefined4 *)param_1[3];
    }
    else {
      *(int *)param_1[2] = piVar1[7];
      piVar1[7] = param_1[2];
      puVar3 = (undefined4 *)param_1[3];
    }
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = *(undefined4 *)(*piVar1 + 0x1c);
      *(undefined4 *)(*piVar1 + 0x1c) = param_1[3];
    }
    if ((param_2 < 5) || ((int *)param_1[4] == (int *)0x0)) goto loc_F00F21CC;
    if (4 < *(int *)(*piVar1 + 0xc)) {
      *(int *)param_1[4] = piVar1[9];
      piVar1[9] = param_1[4];
      *(undefined4 *)(*piVar1 + 0x24) = param_1[4];
      goto loc_F00F21CC;
    }
    __objc_inform(aUnableToAddPro,*param_1);
    puVar2 = aClassSMustBeRe_0;
  }
  __objc_inform(puVar2,param_1[1]);
loc_F00F21CC:
  _objc_getClass(param_1[1]);
  __objc_flush_caches();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3217 start=0xf00f247c */

/* WARNING: Removing unreachable block (ram,0xf00f24a0) */

undefined8 __nameForHeader(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
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
  if (param_1 == 0) {
    iVar1 = *_NXArgv;
  }
  else {
    iVar1 = *(int *)(param_1 + 0xc);
    if (iVar1 == 3) {
      sub_F00F2420();
      piVar2 = (int *)(iVar1 + 0x1c);
      piVar3 = (int *)((int)piVar2 + *(int *)(iVar1 + 0x14));
      if (piVar2 < piVar3) {
        iVar1 = *piVar2;
        while( true ) {
          if (iVar1 == 6) {
            if (piVar2[4] == param_1) {
              iVar1 = (int)piVar2 + piVar2[2];
              goto locret_F00F2508;
            }
            iVar1 = piVar2[1];
          }
          else {
            iVar1 = piVar2[1];
          }
          piVar2 = (int *)((int)piVar2 + iVar1);
          if (piVar3 <= piVar2) break;
          iVar1 = *piVar2;
        }
        iVar1 = 0;
      }
      else {
        iVar1 = 0;
      }
    }
    else {
      iVar1 = *_NXArgv;
    }
  }
locret_F00F2508:
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=3218 start=0xf00f29cc */

/* WARNING: Removing unreachable block (ram,0xf00f2ae8) */
/* WARNING: Removing unreachable block (ram,0xf00f2ab4) */
/* WARNING: Removing unreachable block (ram,0xf00f2a28) */
/* WARNING: Removing unreachable block (ram,0xf00f2a5c) */
/* WARNING: Removing unreachable block (ram,0xf00f2adc) */
/* WARNING: Removing unreachable block (ram,0xf00f2b44) */
/* WARNING: Removing unreachable block (ram,0xf00f2a20) */

undefined8 __objc_headerVector(int *param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar3;
  uint uVar4;
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
  uVar2 = dword_F012F124;
  if (dword_F012F124 == 0) {
    iVar3 = 0;
    iVar1 = *param_1;
    uVar4 = 0;
    while (iVar1 != 0) {
      dword_F012F128 = dword_F012F128 + 1;
      iVar3 = iVar3 + 1;
      uVar4 = dword_F012F128;
      iVar1 = param_1[iVar3];
    }
    __objc_create_zone();
    uVar2 = uVar4;
    __objc_create_zone();
    (**(code **)(uVar4 + 4))();
    if (uVar2 == 0) {
      __objc_fatal(aUnableToAlloca_0);
    }
    uVar4 = 0;
    if (dword_F012F128 != 0) {
      iVar3 = 0;
      do {
        iVar1 = (iVar3 + uVar4) * 8;
        *(int *)(uVar2 + iVar1) = param_1[uVar4];
        iVar1 = uVar2 + iVar1;
        *(undefined4 *)(iVar1 + 0x10) = 0;
        iVar3 = param_1[uVar4];
        _getsectdatafromheader
                  (iVar3,&aObjc,aModuleInfo,(undefined *)((int)register0x00000038 + -0xc));
        *(int *)(iVar1 + 4) = iVar3;
        *(uint *)(iVar1 + 8) = *(uint *)((int)register0x00000038 + -0xc) >> 4;
        iVar3 = param_1[uVar4];
        _getsectdatafromheader
                  (iVar3,&aObjc,aRuntimeSetup,(undefined *)((int)register0x00000038 + -0xc));
        *(int *)(iVar1 + 0xc) = iVar3;
        iVar3 = param_1[uVar4];
        sub_F00F2900();
        if (iVar3 == 0) {
          *(undefined4 *)(uVar2 + uVar4 * 0x18 + 0x14) = 0;
        }
        else {
          *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(iVar3 + 0x24);
        }
        uVar4 = uVar4 + 1;
        iVar3 = uVar4 * 2;
      } while (uVar4 < dword_F012F128);
    }
    _qsort(uVar2,dword_F012F128,0x18,sub_F00F2974);
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=3219 start=0xf00f2b54 */

undefined4 __objc_headerCount(void)

{
  return dword_F012F128;
}
/* GHIDRADEC_FUNCTION index=3220 start=0xf00f2b60 */

/* WARNING: Removing unreachable block (ram,0xf00f2b88) */
/* WARNING: Removing unreachable block (ram,0xf00f2c04) */
/* WARNING: Removing unreachable block (ram,0xf00f2bc0) */
/* WARNING: Removing unreachable block (ram,0xf00f2bfc) */
/* WARNING: Removing unreachable block (ram,0xf00f2c0c) */
/* WARNING: Removing unreachable block (ram,0xf00f2b90) */
/* WARNING: Removing unreachable block (ram,0xf00f2bb8) */

undefined8 __objc_addHeader(undefined4 param_1,undefined4 param_2)

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
  dword_F012F128 = dword_F012F128 + 1;
  if (dword_F012F124 == 0) {
    iVar2 = dword_F012F124;
    __objc_create_zone();
    iVar1 = iVar2;
    __objc_create_zone();
    (**(code **)(iVar2 + 4))();
    dword_F012F124 = iVar1;
  }
  else {
    iVar2 = dword_F012F124;
    __objc_create_zone();
    iVar1 = iVar2;
    __objc_create_zone();
    (**(code **)(iVar2 + 4))();
    dword_F012F124 = iVar1;
    _memcpy();
    __objc_create_zone();
    __objc_create_zone();
    (**(code **)(iVar1 + 8))();
  }
  iVar2 = dword_F012F128 * 0x18 + dword_F012F124;
  *(undefined4 *)(iVar2 + -0x18) = param_1;
  *(undefined4 *)(iVar2 + -0x14) = 0;
  *(undefined4 *)(iVar2 + -0x10) = 0;
  *(undefined4 *)(iVar2 + -0xc) = 0;
  *(undefined4 *)(iVar2 + -8) = 0;
  *(undefined4 *)(iVar2 + -4) = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3221 start=0xf00f2c60 */

/* WARNING: Removing unreachable block (ram,0xf00f2d38) */
/* WARNING: Removing unreachable block (ram,0xf00f2d30) */

undefined8 __objc_removeHeader(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
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
  
  iVar1 = (int)dword_F012F124;
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
  uVar7 = 0;
  if (dword_F012F128 != (undefined4 *)0x0) {
    uVar8 = (int)dword_F012F128 - 1;
    iVar3 = 0;
    do {
      if ((*(int *)(iVar1 + (iVar3 + uVar7) * 8) == param_1) && (uVar7 < uVar8)) {
        uVar2 = (int)dword_F012F128 - 1;
        uVar6 = uVar7;
        do {
          iVar3 = uVar6 * 0x18 + iVar1;
          *(undefined4 *)(iVar1 + uVar6 * 0x18) = *(undefined4 *)(iVar3 + 0x18);
          *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(iVar3 + 0x1c);
          *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar3 + 0x20);
          *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar3 + 0x24);
          *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(iVar3 + 0x28);
          uVar6 = uVar6 + 1;
          *(undefined4 *)(iVar3 + 0x14) = *(undefined4 *)(iVar3 + 0x2c);
        } while (uVar6 < uVar2);
      }
      uVar7 = uVar7 + 1;
      iVar3 = uVar7 * 2;
    } while (uVar7 < dword_F012F128);
  }
  puVar4 = (undefined4 *)((int)dword_F012F128 - 1);
  dword_F012F128 = puVar4;
  __objc_create_zone();
  puVar5 = puVar4;
  __objc_create_zone();
  (*(code *)*puVar4)();
  dword_F012F124 = puVar5;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3222 start=0xf00f32c4 */

void _objc_setMultithreaded(char param_1)

{
  if (param_1 == '\x01') {
    __objc_multithread_mask = 0;
  }
  else {
    __objc_multithread_mask = 0xffffffff;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=3223 start=0xf00f32f4 */

/* WARNING: Removing unreachable block (ram,0xf00f34c0) */
/* WARNING: Removing unreachable block (ram,0xf00f3468) */
/* WARNING: Removing unreachable block (ram,0xf00f33b8) */
/* WARNING: Removing unreachable block (ram,0xf00f3354) */
/* WARNING: Removing unreachable block (ram,0xf00f3304) */
/* WARNING: Removing unreachable block (ram,0xf00f3318) */
/* WARNING: Removing unreachable block (ram,0xf00f339c) */
/* WARNING: Removing unreachable block (ram,0xf00f342c) */
/* WARNING: Removing unreachable block (ram,0xf00f3474) */
/* WARNING: Removing unreachable block (ram,0xf00f3508) */
/* WARNING: Removing unreachable block (ram,0xf00f32f8) */

undefined8 __objcInit(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  uint uVar4;
  int iVar5;
  undefined4 unaff_l1;
  undefined4 *puVar6;
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
  bool bVar7;
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
  iVar3 = param_1;
  sub_F00F25A4();
  dword_F012F12C = iVar3;
  _getmachheaders();
  if (iVar3 != 0) {
    uVar4 = 0;
    iVar1 = iVar3;
    __objc_headerVector();
    dword_F012F124 = iVar1;
    if (dword_F012F128 != 0) {
      iVar1 = 0;
      do {
        sub_F00F2D6C((iVar1 + uVar4) * 8 + dword_F012F124);
        uVar4 = uVar4 + 1;
        iVar1 = uVar4 * 2;
      } while (uVar4 < dword_F012F128);
    }
    uVar4 = 0;
    if (dword_F012F128 != 0) {
      iVar1 = 0;
      do {
        sub_F00F352C((iVar1 + uVar4) * 8 + dword_F012F124);
        uVar4 = uVar4 + 1;
        iVar1 = uVar4 * 2;
      } while (uVar4 < dword_F012F128);
    }
    _free(iVar3);
  }
  uVar4 = 0;
  if (dword_F012F128 != 0) {
    do {
      iVar1 = dword_F012F124 + uVar4 * 0x18;
      iVar3 = *(int *)(iVar1 + 8);
      puVar6 = *(undefined4 **)(iVar1 + 4);
      if (iVar3 != 0) {
        do {
          iVar5 = 0;
          iVar1 = puVar6[3];
          if (*(sword *)(iVar1 + 8) != 0) {
            iVar2 = 0;
            do {
              __class_install_relationships(*(undefined4 *)(iVar2 + iVar1 + 0xc),*puVar6);
              iVar5 = iVar5 + 1;
              iVar1 = puVar6[3];
              iVar2 = iVar5 * 4;
            } while (iVar5 < (int)(uint)*(word *)(iVar1 + 8));
          }
          bVar7 = iVar3 != 1;
          puVar6 = puVar6 + 4;
          iVar3 = iVar3 + -1;
        } while (bVar7);
      }
      sub_F00F26F0(uVar4 * 0x18 + dword_F012F124);
      sub_F00F276C(uVar4 * 0x18 + dword_F012F124);
      uVar4 = uVar4 + 1;
    } while (uVar4 < dword_F012F128);
  }
  uVar4 = 0;
  if (dword_F012F128 != 0) {
    iVar3 = 0;
    do {
      sub_F00F27CC((iVar3 + uVar4) * 8 + dword_F012F124);
      uVar4 = uVar4 + 1;
      iVar3 = uVar4 * 2;
    } while (uVar4 < dword_F012F128);
  }
  uVar4 = 0;
  if (dword_F012F128 != 0) {
    iVar3 = 0;
    do {
      sub_F00F31B0((iVar3 + uVar4) * 8 + dword_F012F124);
      uVar4 = uVar4 + 1;
      iVar3 = uVar4 * 2;
    } while (uVar4 < dword_F012F128);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3224 start=0xf00f3598 */

uint __strhash(byte *param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (*param_1 == 0) {
      return uVar1;
    }
    uVar1 = uVar1 ^ *param_1;
    if (param_1[1] == 0) {
      return uVar1;
    }
    uVar1 = uVar1 ^ (uint)param_1[1] << 8;
    if (param_1[2] == 0) {
      return uVar1;
    }
    uVar1 = uVar1 ^ (uint)param_1[2] << 0x10;
    if (param_1[3] == 0) break;
    uVar1 = uVar1 ^ (uint)param_1[3] << 0x18;
    param_1 = param_1 + 4;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=3225 start=0xf00f3608 */

undefined4 _sel_isMapped(int param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined (*pauVar4) [28];
  
  pauVar4 = off_F012F16C;
  if (param_1 != 0) {
    while (pauVar4 != (undefined (*) [28])0x0) {
      if (((undefined (*) [28])0xf012f14f < pauVar4) && (pauVar4 < unk_F012F150)) {
        return 1;
      }
      if (pauVar4 == &unk_F012F150) {
        uVar3 = 0;
        pauVar4 = (undefined (*) [28])DAT_f012f154._20_4_;
        if (DAT_f012f154._0_4_ != 0) {
          iVar1 = 0;
          do {
            piVar2 = *(int **)(DAT_f012f154._16_4_ + iVar1);
            if (piVar2 != (int *)0x0) {
              iVar1 = piVar2[1];
              while( true ) {
                if (param_1 == iVar1) {
                  return 1;
                }
                piVar2 = (int *)*piVar2;
                if (piVar2 == (int *)0x0) break;
                iVar1 = piVar2[1];
              }
            }
            uVar3 = uVar3 + 1;
            iVar1 = uVar3 * 4;
          } while (uVar3 < (uint)DAT_f012f154._0_4_);
        }
      }
      else {
        pauVar4 = *(undefined (**) [28])(*pauVar4 + 0x18);
      }
    }
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=3226 start=0xf00f36dc */

void _sel_getName(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=3227 start=0xf00f36e4 */

/* WARNING: Removing unreachable block (ram,0xf00f3860) */
/* WARNING: Removing unreachable block (ram,0xf00f3840) */
/* WARNING: Removing unreachable block (ram,0xf00f37ec) */
/* WARNING: Removing unreachable block (ram,0xf00f3854) */
/* WARNING: Removing unreachable block (ram,0xf00f3894) */
/* WARNING: Removing unreachable block (ram,0xf00f37ac) */

undefined8 __sel_registerName(byte *param_1,undefined4 param_2)

{
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  int iVar6;
  undefined4 unaff_l0;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 unaff_l1;
  undefined *puVar9;
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
  if (param_1 == (byte *)0x0) {
    param_1 = (byte *)0x0;
locret_F00F38E8:
    return CONCAT44(param_2,param_1);
  }
  uVar5 = 0;
  pbVar4 = param_1;
  while( true ) {
    if (*pbVar4 == 0) break;
    uVar5 = uVar5 ^ *pbVar4;
    if (pbVar4[1] == 0) break;
    uVar5 = uVar5 ^ (uint)pbVar4[1] << 8;
    if (pbVar4[2] == 0) break;
    uVar5 = uVar5 ^ (uint)pbVar4[2] << 0x10;
    if (pbVar4[3] == 0) break;
    uVar5 = uVar5 ^ (uint)pbVar4[3] << 0x18;
    pbVar4 = pbVar4 + 4;
  }
  if (off_F012F16C != (undefined *)0x0) {
    pbVar4 = *(byte **)(off_F012F16C + 0xc);
    puVar9 = off_F012F16C;
    while( true ) {
      if ((pbVar4 <= param_1) && (param_1 < *(byte **)(puVar9 + 0x10))) goto locret_F00F38E8;
      uVar1 = uVar5;
      .urem(uVar5,*(undefined4 *)(puVar9 + 4));
      puVar7 = *(undefined4 **)(*(int *)(puVar9 + 0x14) + uVar1 * 4);
      if (puVar7 != (undefined4 *)0x0) {
        pbVar4 = (byte *)puVar7[1];
        while( true ) {
          if (*param_1 == *pbVar4) {
            pbVar2 = param_1;
            _strcmp(param_1,pbVar4);
            if (pbVar2 == (byte *)0x0) {
              param_1 = (byte *)puVar7[1];
              goto locret_F00F38E8;
            }
            puVar7 = (undefined4 *)*puVar7;
          }
          else {
            puVar7 = (undefined4 *)*puVar7;
          }
          if (puVar7 == (undefined4 *)0x0) break;
          pbVar4 = (byte *)puVar7[1];
        }
      }
      if (puVar9 == unk_F012F150) {
        DAT_f012f158._0_4_ = DAT_f012f158._0_4_ + 1;
        if ((undefined8 *)DAT_f012f158._12_4_ == &unk_F00FA388) {
          DAT_f012f154._0_4_ = 0x335;
          uVar8 = 0xcd4;
          sub_F00F355C();
          DAT_f012f158._12_4_ = uVar8;
          _memset();
          .urem(uVar5,DAT_f012f154._0_4_);
          uVar1 = uVar5;
        }
        uVar8 = *(undefined4 *)(DAT_f012f158._12_4_ + uVar1 * 4);
        if ((iRamf012f174 == 0) || (0x27 < iRamf012f178)) {
          iVar3 = 0x140;
          sub_F00F355C();
          iRamf012f178 = 0;
          iRamf012f174 = iVar3;
        }
        iVar3 = iRamf012f178 * 8;
        iVar6 = iVar3 + iRamf012f174;
        iRamf012f178 = iRamf012f178 + 1;
        *(undefined4 *)(iVar3 + iRamf012f174) = uVar8;
        *(byte **)(iVar6 + 4) = param_1;
        *(int *)(DAT_f012f158._12_4_ + uVar1 * 4) = iVar6;
        goto locret_F00F38E8;
      }
      puVar9 = *(undefined **)(puVar9 + 0x18);
      if (puVar9 == (undefined *)0x0) break;
      pbVar4 = *(byte **)(puVar9 + 0xc);
    }
  }
                    /* WARNING: Subroutine does not return */
  _abort();
}
/* GHIDRADEC_FUNCTION index=3228 start=0xf00f38f0 */

/* WARNING: Removing unreachable block (ram,0xf00f3908) */
/* WARNING: Removing unreachable block (ram,0xf00f3910) */
/* WARNING: Removing unreachable block (ram,0xf00f38f4) */

undefined8 _sel_registerName(int param_1,undefined4 param_2)

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
  iVar1 = param_1;
  _sel_getUid();
  if (iVar1 == 0) {
    _NXUniqueString(param_1);
    __sel_registerName();
    iVar1 = param_1;
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=3229 start=0xf00f3920 */

/* WARNING: Removing unreachable block (ram,0xf00f3964) */

void __sel_unloadSelectors(void)

{
  int *piVar1;
  uint uVar2;
  
  uVar2 = 0;
  while (uVar2 < (uint)DAT_f012f154._0_4_) {
    if (*(int *)(uVar2 * 4 + DAT_f012f164._0_4_) == 0) {
      uVar2 = uVar2 + 1;
    }
    else {
      piVar1 = *(int **)(uVar2 * 4 + DAT_f012f164._0_4_);
      do {
        piVar1 = (int *)*piVar1;
      } while (piVar1 != (int *)0x0);
      uVar2 = uVar2 + 1;
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=3230 start=0xf00f39a0 */

/* WARNING: Removing unreachable block (ram,0xf00f3a8c) */
/* WARNING: Removing unreachable block (ram,0xf00f3a50) */

undefined8 _sel_getUid(byte *param_1,undefined4 param_2)

{
  uint uVar1;
  byte *pbVar2;
  byte *pbVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined4 *puVar5;
  undefined4 unaff_l1;
  int iVar6;
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
  if (param_1 == (byte *)0x0) {
    param_1 = (byte *)0x0;
  }
  else {
    uVar4 = 0;
    pbVar3 = param_1;
    while( true ) {
      if (*pbVar3 == 0) break;
      uVar4 = uVar4 ^ *pbVar3;
      if (pbVar3[1] == 0) break;
      uVar4 = uVar4 ^ (uint)pbVar3[1] << 8;
      if (pbVar3[2] == 0) break;
      uVar4 = uVar4 ^ (uint)pbVar3[2] << 0x10;
      if (pbVar3[3] == 0) break;
      uVar4 = uVar4 ^ (uint)pbVar3[3] << 0x18;
      pbVar3 = pbVar3 + 4;
    }
    if (off_F012F16C != 0) {
      pbVar3 = *(byte **)(off_F012F16C + 0xc);
      iVar6 = off_F012F16C;
      while( true ) {
        if ((pbVar3 <= param_1) && (param_1 < *(byte **)(iVar6 + 0x10))) goto locret_F00F3AC4;
        uVar1 = uVar4;
        .urem(uVar4,*(undefined4 *)(iVar6 + 4));
        puVar5 = *(undefined4 **)(*(int *)(iVar6 + 0x14) + uVar1 * 4);
        if (puVar5 == (undefined4 *)0x0) {
          iVar6 = *(int *)(iVar6 + 0x18);
        }
        else {
          pbVar3 = (byte *)puVar5[1];
          while( true ) {
            if (*param_1 == *pbVar3) {
              pbVar2 = param_1;
              _strcmp(param_1,pbVar3);
              if (pbVar2 == (byte *)0x0) {
                param_1 = (byte *)puVar5[1];
                goto locret_F00F3AC4;
              }
              puVar5 = (undefined4 *)*puVar5;
            }
            else {
              puVar5 = (undefined4 *)*puVar5;
            }
            if (puVar5 == (undefined4 *)0x0) break;
            pbVar3 = (byte *)puVar5[1];
          }
          iVar6 = *(int *)(iVar6 + 0x18);
        }
        if (iVar6 == 0) break;
        pbVar3 = *(byte **)(iVar6 + 0xc);
      }
    }
    param_1 = (byte *)0x0;
  }
locret_F00F3AC4:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3231 start=0xf00f3acc */

/* WARNING: Removing unreachable block (ram,0xf00f3ad8) */
/* WARNING: Removing unreachable block (ram,0xf00f3ad0) */

undefined8 __sel_init(undefined4 *param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined *puVar2;
  undefined4 *puVar3;
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
  puVar3 = param_1;
  _NXDefaultMallocZone();
  puVar1 = puVar3;
  _NXDefaultMallocZone();
  (*(code *)puVar3[1])();
  *puVar1 = param_1;
  puVar1[1] = 0x335;
  puVar1[2] = 0;
  puVar1[3] = param_2;
  puVar1[4] = param_2 + param_3;
  puVar1[5] = param_4;
  puVar3 = &off_F012F16C;
  puVar2 = off_F012F16C;
  if (off_F012F16C != (undefined *)0x0) {
    while (puVar2 != unk_F012F150) {
      puVar3 = (undefined4 *)(puVar2 + 0x18);
      if (*(int *)(puVar2 + 0x18) == 0) goto locret_F00F3B58;
      puVar2 = (undefined *)*puVar3;
    }
    puVar1[6] = unk_F012F150;
    *puVar3 = puVar1;
  }
locret_F00F3B58:
  return CONCAT44(param_2 + param_3,param_1);
}
/* GHIDRADEC_FUNCTION index=3232 start=0xf00f3b60 */

/* WARNING: Removing unreachable block (ram,0xf00f3ba4) */
/* WARNING: Removing unreachable block (ram,0xf00f3b80) */

undefined8 _port_allocate_EXTERNAL(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined *puVar2;
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
  *(undefined *)((int)register0x00000038 + -0x2d) = 1;
  *(undefined4 *)((int)register0x00000038 + -0x2c) = 0x18;
  uVar1 = 0x100;
  *(undefined4 *)((int)register0x00000038 + -0x28) = 0x100;
  *(undefined4 *)((int)register0x00000038 + -0x20) = param_1;
  puVar2 = (undefined *)((int)register0x00000038 + -0x30);
  _mig_get_reply_port();
  *(undefined4 *)((int)register0x00000038 + -0x24) = uVar1;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0x81c;
  uVar1 = 0;
  _msg_rpc(puVar2,0,0x28,0,0);
  if (puVar2 == (undefined *)0x0) {
    if (*(int *)((int)register0x00000038 + -0x1c) == 0x880) {
      if (((((*(int *)((int)register0x00000038 + -0x2c) == 0x28) &&
            (*(char *)((int)register0x00000038 + -0x2d) == '\x01')) ||
           ((puVar2 = (undefined *)0xfffffed4, *(int *)((int)register0x00000038 + -0x2c) == 0x20 &&
            ((*(char *)((int)register0x00000038 + -0x2d) == '\x01' &&
             (*(int *)((int)register0x00000038 + -0x14) != 0)))))) &&
          (puVar2 = (undefined *)0xfffffed4, *(int *)((int)register0x00000038 + -0x18) == 0x2200018)
          ) && ((puVar2 = *(undefined **)((int)register0x00000038 + -0x14),
                puVar2 == (undefined *)0x0 &&
                (puVar2 = (undefined *)0xfffffed4,
                *(int *)((int)register0x00000038 + -0x10) == 0x2200018)))) {
        *param_2 = *(undefined4 *)((int)register0x00000038 + -0xc);
        puVar2 = *(undefined **)((int)register0x00000038 + -0x14);
      }
    }
    else {
      puVar2 = (undefined *)0xfffffed3;
    }
  }
  else if (puVar2 == (undefined *)0xffffff36) {
    _mig_dealloc_reply_port();
    return CONCAT44(uVar1,puVar2);
  }
  return CONCAT44(param_2,puVar2);
}
/* GHIDRADEC_FUNCTION index=3233 start=0xf00f3c6c */

/* WARNING: Removing unreachable block (ram,0xf00f3cc0) */
/* WARNING: Removing unreachable block (ram,0xf00f3c9c) */

undefined8 _port_deallocate_EXTERNAL(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar2;
  undefined4 unaff_i1;
  undefined *puVar3;
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
  *(undefined4 *)((int)register0x00000038 + -0xc) = param_2;
  *(undefined *)((int)register0x00000038 + -0x25) = 1;
  *(undefined4 *)((int)register0x00000038 + -0x24) = 0x20;
  *(undefined4 *)((int)register0x00000038 + -0x20) = 0x100;
  uVar1 = 0x2200018;
  *(undefined4 *)((int)register0x00000038 + -0x18) = param_1;
  puVar3 = (undefined *)((int)register0x00000038 + -0x28);
  *(undefined4 *)((int)register0x00000038 + -0x10) = 0x2200018;
  _mig_get_reply_port();
  *(undefined4 *)((int)register0x00000038 + -0x1c) = uVar1;
  *(undefined4 *)((int)register0x00000038 + -0x14) = 0x81d;
  uVar1 = 0;
  puVar2 = puVar3;
  _msg_rpc(puVar3,0,0x20,0,0);
  if (puVar2 == (undefined *)0x0) {
    if (*(int *)((int)register0x00000038 + -0x14) == 0x881) {
      puVar2 = (undefined *)0xfffffed4;
      if (((*(int *)((int)register0x00000038 + -0x24) == 0x20) &&
          (((*(char *)((int)register0x00000038 + -0x25) == '\x01' ||
            ((*(char *)((int)register0x00000038 + -0x25) == '\x01' &&
             (*(int *)((int)register0x00000038 + -0xc) != 0)))) &&
           (puVar2 = (undefined *)0xfffffed4, *(int *)((int)register0x00000038 + -0x10) == 0x2200018
           )))) && (puVar2 = *(undefined **)((int)register0x00000038 + -0xc),
                   puVar2 == (undefined *)0x0)) {
        puVar2 = (undefined *)0x0;
      }
    }
    else {
      puVar2 = (undefined *)0xfffffed3;
    }
  }
  else if (puVar2 == (undefined *)0xffffff36) {
    _mig_dealloc_reply_port();
    return CONCAT44(uVar1,puVar2);
  }
  return CONCAT44(puVar3,puVar2);
}
/* GHIDRADEC_FUNCTION index=3234 start=0xf00f3d68 */

/* WARNING: Removing unreachable block (ram,0xf00f3dcc) */
/* WARNING: Removing unreachable block (ram,0xf00f3da8) */

undefined8 _port_set_add_EXTERNAL(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar2;
  undefined4 unaff_i1;
  undefined *puVar3;
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
  *(undefined4 *)((int)register0x00000038 + -0x14) = param_2;
  *(undefined4 *)((int)register0x00000038 + -0xc) = param_3;
  *(undefined *)((int)register0x00000038 + -0x2d) = 1;
  *(undefined4 *)((int)register0x00000038 + -0x2c) = 0x28;
  *(undefined4 *)((int)register0x00000038 + -0x28) = 0x100;
  *(undefined4 *)((int)register0x00000038 + -0x20) = param_1;
  puVar3 = (undefined *)((int)register0x00000038 + -0x30);
  uVar1 = 0x2200018;
  *(undefined4 *)((int)register0x00000038 + -0x18) = 0x2200018;
  *(undefined4 *)((int)register0x00000038 + -0x10) = 0x2200018;
  _mig_get_reply_port();
  *(undefined4 *)((int)register0x00000038 + -0x24) = uVar1;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0x822;
  uVar1 = 0;
  puVar2 = puVar3;
  _msg_rpc(puVar3,0,0x20,0,0);
  if (puVar2 == (undefined *)0x0) {
    if (*(int *)((int)register0x00000038 + -0x1c) == 0x886) {
      puVar2 = (undefined *)0xfffffed4;
      if (((*(int *)((int)register0x00000038 + -0x2c) == 0x20) &&
          (((*(char *)((int)register0x00000038 + -0x2d) == '\x01' ||
            ((*(char *)((int)register0x00000038 + -0x2d) == '\x01' &&
             (*(int *)((int)register0x00000038 + -0x14) != 0)))) &&
           (puVar2 = (undefined *)0xfffffed4, *(int *)((int)register0x00000038 + -0x18) == 0x2200018
           )))) && (puVar2 = *(undefined **)((int)register0x00000038 + -0x14),
                   puVar2 == (undefined *)0x0)) {
        puVar2 = (undefined *)0x0;
      }
    }
    else {
      puVar2 = (undefined *)0xfffffed3;
    }
  }
  else if (puVar2 == (undefined *)0xffffff36) {
    _mig_dealloc_reply_port();
    return CONCAT44(uVar1,puVar2);
  }
  return CONCAT44(puVar3,puVar2);
}
/* GHIDRADEC_FUNCTION index=3235 start=0xf00f3e74 */

/* WARNING: Removing unreachable block (ram,0xf00f3eb8) */
/* WARNING: Removing unreachable block (ram,0xf00f3e94) */

undefined8 _port_set_allocate_EXTERNAL(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined *puVar2;
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
  *(undefined *)((int)register0x00000038 + -0x2d) = 1;
  *(undefined4 *)((int)register0x00000038 + -0x2c) = 0x18;
  uVar1 = 0x100;
  *(undefined4 *)((int)register0x00000038 + -0x28) = 0x100;
  *(undefined4 *)((int)register0x00000038 + -0x20) = param_1;
  puVar2 = (undefined *)((int)register0x00000038 + -0x30);
  _mig_get_reply_port();
  *(undefined4 *)((int)register0x00000038 + -0x24) = uVar1;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0x820;
  uVar1 = 0;
  _msg_rpc(puVar2,0,0x28,0,0);
  if (puVar2 == (undefined *)0x0) {
    if (*(int *)((int)register0x00000038 + -0x1c) == 0x884) {
      if (((((*(int *)((int)register0x00000038 + -0x2c) == 0x28) &&
            (*(char *)((int)register0x00000038 + -0x2d) == '\x01')) ||
           ((puVar2 = (undefined *)0xfffffed4, *(int *)((int)register0x00000038 + -0x2c) == 0x20 &&
            ((*(char *)((int)register0x00000038 + -0x2d) == '\x01' &&
             (*(int *)((int)register0x00000038 + -0x14) != 0)))))) &&
          (puVar2 = (undefined *)0xfffffed4, *(int *)((int)register0x00000038 + -0x18) == 0x2200018)
          ) && ((puVar2 = *(undefined **)((int)register0x00000038 + -0x14),
                puVar2 == (undefined *)0x0 &&
                (puVar2 = (undefined *)0xfffffed4,
                *(int *)((int)register0x00000038 + -0x10) == 0x2200018)))) {
        *param_2 = *(undefined4 *)((int)register0x00000038 + -0xc);
        puVar2 = *(undefined **)((int)register0x00000038 + -0x14);
      }
    }
    else {
      puVar2 = (undefined *)0xfffffed3;
    }
  }
  else if (puVar2 == (undefined *)0xffffff36) {
    _mig_dealloc_reply_port();
    return CONCAT44(uVar1,puVar2);
  }
  return CONCAT44(param_2,puVar2);
}
/* GHIDRADEC_FUNCTION index=3236 start=0xf00f3f80 */

/* WARNING: Removing unreachable block (ram,0xf00f3fd4) */
/* WARNING: Removing unreachable block (ram,0xf00f3fb0) */

undefined8 _port_set_deallocate_EXTERNAL(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar2;
  undefined4 unaff_i1;
  undefined *puVar3;
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
  *(undefined4 *)((int)register0x00000038 + -0xc) = param_2;
  *(undefined *)((int)register0x00000038 + -0x25) = 1;
  *(undefined4 *)((int)register0x00000038 + -0x24) = 0x20;
  *(undefined4 *)((int)register0x00000038 + -0x20) = 0x100;
  uVar1 = 0x2200018;
  *(undefined4 *)((int)register0x00000038 + -0x18) = param_1;
  puVar3 = (undefined *)((int)register0x00000038 + -0x28);
  *(undefined4 *)((int)register0x00000038 + -0x10) = 0x2200018;
  _mig_get_reply_port();
  *(undefined4 *)((int)register0x00000038 + -0x1c) = uVar1;
  *(undefined4 *)((int)register0x00000038 + -0x14) = 0x821;
  uVar1 = 0;
  puVar2 = puVar3;
  _msg_rpc(puVar3,0,0x20,0,0);
  if (puVar2 == (undefined *)0x0) {
    if (*(int *)((int)register0x00000038 + -0x14) == 0x885) {
      puVar2 = (undefined *)0xfffffed4;
      if (((*(int *)((int)register0x00000038 + -0x24) == 0x20) &&
          (((*(char *)((int)register0x00000038 + -0x25) == '\x01' ||
            ((*(char *)((int)register0x00000038 + -0x25) == '\x01' &&
             (*(int *)((int)register0x00000038 + -0xc) != 0)))) &&
           (puVar2 = (undefined *)0xfffffed4, *(int *)((int)register0x00000038 + -0x10) == 0x2200018
           )))) && (puVar2 = *(undefined **)((int)register0x00000038 + -0xc),
                   puVar2 == (undefined *)0x0)) {
        puVar2 = (undefined *)0x0;
      }
    }
    else {
      puVar2 = (undefined *)0xfffffed3;
    }
  }
  else if (puVar2 == (undefined *)0xffffff36) {
    _mig_dealloc_reply_port();
    return CONCAT44(uVar1,puVar2);
  }
  return CONCAT44(puVar3,puVar2);
}
/* GHIDRADEC_FUNCTION index=3237 start=0xf00f407c */

/* WARNING: Removing unreachable block (ram,0xf00f40dc) */
/* WARNING: Removing unreachable block (ram,0xf00f40b8) */

undefined8 _task_set_special_port_EXTERNAL(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar2;
  undefined4 unaff_i1;
  undefined *puVar3;
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
  *(undefined4 *)((int)register0x00000038 + -0x14) = param_2;
  *(undefined4 *)((int)register0x00000038 + -0xc) = param_3;
  *(undefined *)((int)register0x00000038 + -0x2d) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x2c) = 0x28;
  *(undefined4 *)((int)register0x00000038 + -0x28) = 0x100;
  *(undefined4 *)((int)register0x00000038 + -0x20) = param_1;
  puVar3 = (undefined *)((int)register0x00000038 + -0x30);
  uVar1 = 0x6200018;
  *(undefined4 *)((int)register0x00000038 + -0x18) = 0x2200018;
  *(undefined4 *)((int)register0x00000038 + -0x10) = 0x6200018;
  _mig_get_reply_port();
  *(undefined4 *)((int)register0x00000038 + -0x24) = uVar1;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0x80b;
  uVar1 = 0;
  puVar2 = puVar3;
  _msg_rpc(puVar3,0,0x20,0,0);
  if (puVar2 == (undefined *)0x0) {
    if (*(int *)((int)register0x00000038 + -0x1c) == 0x86f) {
      puVar2 = (undefined *)0xfffffed4;
      if (((*(int *)((int)register0x00000038 + -0x2c) == 0x20) &&
          (((*(char *)((int)register0x00000038 + -0x2d) == '\x01' ||
            ((*(char *)((int)register0x00000038 + -0x2d) == '\x01' &&
             (*(int *)((int)register0x00000038 + -0x14) != 0)))) &&
           (puVar2 = (undefined *)0xfffffed4, *(int *)((int)register0x00000038 + -0x18) == 0x2200018
           )))) && (puVar2 = *(undefined **)((int)register0x00000038 + -0x14),
                   puVar2 == (undefined *)0x0)) {
        puVar2 = (undefined *)0x0;
      }
    }
    else {
      puVar2 = (undefined *)0xfffffed3;
    }
  }
  else if (puVar2 == (undefined *)0xffffff36) {
    _mig_dealloc_reply_port();
    return CONCAT44(uVar1,puVar2);
  }
  return CONCAT44(puVar3,puVar2);
}
/* GHIDRADEC_FUNCTION index=3238 start=0xf00f4184 */

/* WARNING: Removing unreachable block (ram,0xf00f41d8) */
/* WARNING: Removing unreachable block (ram,0xf00f41b4) */

undefined8
_thread_get_special_port_EXTERNAL(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar2;
  undefined4 unaff_i1;
  undefined *puVar3;
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
  *(undefined4 *)((int)register0x00000038 + -0x14) = param_2;
  *(undefined *)((int)register0x00000038 + -0x2d) = 1;
  *(undefined4 *)((int)register0x00000038 + -0x2c) = 0x20;
  *(undefined4 *)((int)register0x00000038 + -0x28) = 0x100;
  uVar1 = 0x2200018;
  *(undefined4 *)((int)register0x00000038 + -0x20) = param_1;
  puVar3 = (undefined *)((int)register0x00000038 + -0x30);
  *(undefined4 *)((int)register0x00000038 + -0x18) = 0x2200018;
  _mig_get_reply_port();
  *(undefined4 *)((int)register0x00000038 + -0x24) = uVar1;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0x813;
  uVar1 = 0;
  puVar2 = puVar3;
  _msg_rpc(puVar3,0,0x28,0,0);
  if (puVar2 == (undefined *)0x0) {
    if (*(int *)((int)register0x00000038 + -0x1c) == 0x877) {
      if (((((*(int *)((int)register0x00000038 + -0x2c) == 0x28) &&
            (*(char *)((int)register0x00000038 + -0x2d) == '\0')) ||
           ((puVar2 = (undefined *)0xfffffed4, *(int *)((int)register0x00000038 + -0x2c) == 0x20 &&
            ((*(char *)((int)register0x00000038 + -0x2d) == '\x01' &&
             (*(int *)((int)register0x00000038 + -0x14) != 0)))))) &&
          (puVar2 = (undefined *)0xfffffed4, *(int *)((int)register0x00000038 + -0x18) == 0x2200018)
          ) && ((puVar2 = *(undefined **)((int)register0x00000038 + -0x14),
                puVar2 == (undefined *)0x0 &&
                (puVar2 = (undefined *)0xfffffed4,
                *(int *)((int)register0x00000038 + -0x10) == 0x6200018)))) {
        *param_3 = *(undefined4 *)((int)register0x00000038 + -0xc);
        puVar2 = *(undefined **)((int)register0x00000038 + -0x14);
      }
    }
    else {
      puVar2 = (undefined *)0xfffffed3;
    }
  }
  else if (puVar2 == (undefined *)0xffffff36) {
    _mig_dealloc_reply_port();
    return CONCAT44(uVar1,puVar2);
  }
  return CONCAT44(puVar3,puVar2);
}
/* GHIDRADEC_FUNCTION index=3239 start=0xf00f42a0 */

/* WARNING: Removing unreachable block (ram,0xf00f4300) */
/* WARNING: Removing unreachable block (ram,0xf00f42dc) */

undefined8
_thread_set_special_port_EXTERNAL(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar2;
  undefined4 unaff_i1;
  undefined *puVar3;
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
  *(undefined4 *)((int)register0x00000038 + -0x14) = param_2;
  *(undefined4 *)((int)register0x00000038 + -0xc) = param_3;
  *(undefined *)((int)register0x00000038 + -0x2d) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x2c) = 0x28;
  *(undefined4 *)((int)register0x00000038 + -0x28) = 0x100;
  *(undefined4 *)((int)register0x00000038 + -0x20) = param_1;
  puVar3 = (undefined *)((int)register0x00000038 + -0x30);
  uVar1 = 0x6200018;
  *(undefined4 *)((int)register0x00000038 + -0x18) = 0x2200018;
  *(undefined4 *)((int)register0x00000038 + -0x10) = 0x6200018;
  _mig_get_reply_port();
  *(undefined4 *)((int)register0x00000038 + -0x24) = uVar1;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0x814;
  uVar1 = 0;
  puVar2 = puVar3;
  _msg_rpc(puVar3,0,0x20,0,0);
  if (puVar2 == (undefined *)0x0) {
    if (*(int *)((int)register0x00000038 + -0x1c) == 0x878) {
      puVar2 = (undefined *)0xfffffed4;
      if (((*(int *)((int)register0x00000038 + -0x2c) == 0x20) &&
          (((*(char *)((int)register0x00000038 + -0x2d) == '\x01' ||
            ((*(char *)((int)register0x00000038 + -0x2d) == '\x01' &&
             (*(int *)((int)register0x00000038 + -0x14) != 0)))) &&
           (puVar2 = (undefined *)0xfffffed4, *(int *)((int)register0x00000038 + -0x18) == 0x2200018
           )))) && (puVar2 = *(undefined **)((int)register0x00000038 + -0x14),
                   puVar2 == (undefined *)0x0)) {
        puVar2 = (undefined *)0x0;
      }
    }
    else {
      puVar2 = (undefined *)0xfffffed3;
    }
  }
  else if (puVar2 == (undefined *)0xffffff36) {
    _mig_dealloc_reply_port();
    return CONCAT44(uVar1,puVar2);
  }
  return CONCAT44(puVar3,puVar2);
}
/* GHIDRADEC_FUNCTION index=3240 start=0xf00f43a8 */

/* WARNING: Removing unreachable block (ram,0xf00f440c) */
/* WARNING: Removing unreachable block (ram,0xf00f43e8) */

undefined8 _vm_deallocate_EXTERNAL(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar2;
  undefined4 unaff_i1;
  undefined *puVar3;
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
  *(undefined4 *)((int)register0x00000038 + -0x14) = param_2;
  *(undefined4 *)((int)register0x00000038 + -0xc) = param_3;
  *(undefined *)((int)register0x00000038 + -0x2d) = 1;
  *(undefined4 *)((int)register0x00000038 + -0x2c) = 0x28;
  *(undefined4 *)((int)register0x00000038 + -0x28) = 0x100;
  *(undefined4 *)((int)register0x00000038 + -0x20) = param_1;
  puVar3 = (undefined *)((int)register0x00000038 + -0x30);
  uVar1 = 0x2200018;
  *(undefined4 *)((int)register0x00000038 + -0x18) = 0x2200018;
  *(undefined4 *)((int)register0x00000038 + -0x10) = 0x2200018;
  _mig_get_reply_port();
  *(undefined4 *)((int)register0x00000038 + -0x24) = uVar1;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0x7e7;
  uVar1 = 0;
  puVar2 = puVar3;
  _msg_rpc(puVar3,0,0x20,0,0);
  if (puVar2 == (undefined *)0x0) {
    if (*(int *)((int)register0x00000038 + -0x1c) == 0x84b) {
      puVar2 = (undefined *)0xfffffed4;
      if (((*(int *)((int)register0x00000038 + -0x2c) == 0x20) &&
          (((*(char *)((int)register0x00000038 + -0x2d) == '\x01' ||
            ((*(char *)((int)register0x00000038 + -0x2d) == '\x01' &&
             (*(int *)((int)register0x00000038 + -0x14) != 0)))) &&
           (puVar2 = (undefined *)0xfffffed4, *(int *)((int)register0x00000038 + -0x18) == 0x2200018
           )))) && (puVar2 = *(undefined **)((int)register0x00000038 + -0x14),
                   puVar2 == (undefined *)0x0)) {
        puVar2 = (undefined *)0x0;
      }
    }
    else {
      puVar2 = (undefined *)0xfffffed3;
    }
  }
  else if (puVar2 == (undefined *)0xffffff36) {
    _mig_dealloc_reply_port();
    return CONCAT44(uVar1,puVar2);
  }
  return CONCAT44(puVar3,puVar2);
}
/* GHIDRADEC_FUNCTION index=3241 start=0xf00f44b4 */

/* WARNING: Removing unreachable block (ram,0xf00f4518) */
/* WARNING: Removing unreachable block (ram,0xf00f44f4) */

undefined8
_vm_read_EXTERNAL(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined4 *param_5)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar2;
  undefined4 unaff_i1;
  undefined *puVar3;
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
  *(undefined4 *)((int)register0x00000038 + -0x1c) = param_2;
  *(undefined4 *)((int)register0x00000038 + -0x14) = param_3;
  *(undefined *)((int)register0x00000038 + -0x35) = 1;
  *(undefined4 *)((int)register0x00000038 + -0x34) = 0x28;
  *(undefined4 *)((int)register0x00000038 + -0x30) = 0x100;
  *(undefined4 *)((int)register0x00000038 + -0x28) = param_1;
  puVar3 = (undefined *)((int)register0x00000038 + -0x38);
  uVar1 = 0x2200018;
  *(undefined4 *)((int)register0x00000038 + -0x20) = 0x2200018;
  *(undefined4 *)((int)register0x00000038 + -0x18) = 0x2200018;
  _mig_get_reply_port();
  *(undefined4 *)((int)register0x00000038 + -0x2c) = uVar1;
  *(undefined4 *)((int)register0x00000038 + -0x24) = 0x7ea;
  uVar1 = 0;
  puVar2 = puVar3;
  _msg_rpc(puVar3,0,0x30,0,0);
  if (puVar2 == (undefined *)0x0) {
    if (*(int *)((int)register0x00000038 + -0x24) == 0x84e) {
      if (((((*(int *)((int)register0x00000038 + -0x34) == 0x30) &&
            (*(char *)((int)register0x00000038 + -0x35) == '\0')) ||
           ((puVar2 = (undefined *)0xfffffed4, *(int *)((int)register0x00000038 + -0x34) == 0x20 &&
            ((*(char *)((int)register0x00000038 + -0x35) == '\x01' &&
             (*(int *)((int)register0x00000038 + -0x1c) != 0)))))) &&
          (puVar2 = (undefined *)0xfffffed4, *(int *)((int)register0x00000038 + -0x20) == 0x2200018)
          ) && (((puVar2 = *(undefined **)((int)register0x00000038 + -0x1c),
                 puVar2 == (undefined *)0x0 &&
                 (puVar2 = (undefined *)0xfffffed4,
                 (*(uint *)((int)register0x00000038 + -0x18) & 0xc) == 4)) &&
                (*(int *)((int)register0x00000038 + -0x14) == 0x90008)))) {
        *param_4 = *(undefined4 *)((int)register0x00000038 + -0xc);
        *param_5 = *(undefined4 *)((int)register0x00000038 + -0x10);
        puVar2 = *(undefined **)((int)register0x00000038 + -0x1c);
      }
    }
    else {
      puVar2 = (undefined *)0xfffffed3;
    }
  }
  else if (puVar2 == (undefined *)0xffffff36) {
    _mig_dealloc_reply_port();
    return CONCAT44(uVar1,puVar2);
  }
  return CONCAT44(puVar3,puVar2);
}
/* GHIDRADEC_FUNCTION index=3242 start=0xf00f4600 */

/* WARNING: Removing unreachable block (ram,0xf00f4664) */
/* WARNING: Removing unreachable block (ram,0xf00f4640) */

undefined8 _port_set_backlog_EXTERNAL(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar2;
  undefined4 unaff_i1;
  undefined *puVar3;
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
  *(undefined4 *)((int)register0x00000038 + -0x14) = param_2;
  *(undefined4 *)((int)register0x00000038 + -0xc) = param_3;
  *(undefined *)((int)register0x00000038 + -0x2d) = 1;
  *(undefined4 *)((int)register0x00000038 + -0x2c) = 0x28;
  *(undefined4 *)((int)register0x00000038 + -0x28) = 0x100;
  *(undefined4 *)((int)register0x00000038 + -0x20) = param_1;
  puVar3 = (undefined *)((int)register0x00000038 + -0x30);
  uVar1 = 0x2200018;
  *(undefined4 *)((int)register0x00000038 + -0x18) = 0x2200018;
  *(undefined4 *)((int)register0x00000038 + -0x10) = 0x2200018;
  _mig_get_reply_port();
  *(undefined4 *)((int)register0x00000038 + -0x24) = uVar1;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0x81e;
  uVar1 = 0;
  puVar2 = puVar3;
  _msg_rpc(puVar3,0,0x20,0,0);
  if (puVar2 == (undefined *)0x0) {
    if (*(int *)((int)register0x00000038 + -0x1c) == 0x882) {
      puVar2 = (undefined *)0xfffffed4;
      if (((*(int *)((int)register0x00000038 + -0x2c) == 0x20) &&
          (((*(char *)((int)register0x00000038 + -0x2d) == '\x01' ||
            ((*(char *)((int)register0x00000038 + -0x2d) == '\x01' &&
             (*(int *)((int)register0x00000038 + -0x14) != 0)))) &&
           (puVar2 = (undefined *)0xfffffed4, *(int *)((int)register0x00000038 + -0x18) == 0x2200018
           )))) && (puVar2 = *(undefined **)((int)register0x00000038 + -0x14),
                   puVar2 == (undefined *)0x0)) {
        puVar2 = (undefined *)0x0;
      }
    }
    else {
      puVar2 = (undefined *)0xfffffed3;
    }
  }
  else if (puVar2 == (undefined *)0xffffff36) {
    _mig_dealloc_reply_port();
    return CONCAT44(uVar1,puVar2);
  }
  return CONCAT44(puVar3,puVar2);
}
/* GHIDRADEC_FUNCTION index=3243 start=0xf00f470c */

/* WARNING: Removing unreachable block (ram,0xf00f4784) */
/* WARNING: Removing unreachable block (ram,0xf00f4760) */

undefined8
_vm_allocate_EXTERNAL(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
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
  undefined *puVar2;
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
  *(undefined4 *)((int)register0x00000038 + -0x20) = 0x2200018;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = *param_2;
  *(undefined4 *)((int)register0x00000038 + -0x18) = 0x2200018;
  *(undefined4 *)((int)register0x00000038 + -0x14) = param_3;
  *(undefined4 *)((int)register0x00000038 + -0xc) = param_4;
  *(undefined4 *)((int)register0x00000038 + -0x34) = 0x30;
  *(undefined4 *)((int)register0x00000038 + -0x28) = param_1;
  puVar2 = (undefined *)((int)register0x00000038 + -0x38);
  *(undefined4 *)((int)register0x00000038 + -0x10) = 0x200018;
  *(undefined *)((int)register0x00000038 + -0x35) = 1;
  uVar1 = 0x100;
  *(undefined4 *)((int)register0x00000038 + -0x30) = 0x100;
  _mig_get_reply_port();
  *(undefined4 *)((int)register0x00000038 + -0x2c) = uVar1;
  *(undefined4 *)((int)register0x00000038 + -0x24) = 0x7e5;
  uVar1 = 0;
  _msg_rpc(puVar2,0,0x28,0,0);
  if (puVar2 == (undefined *)0x0) {
    if (*(int *)((int)register0x00000038 + -0x24) == 0x849) {
      if (((((*(int *)((int)register0x00000038 + -0x34) == 0x28) &&
            (*(char *)((int)register0x00000038 + -0x35) == '\x01')) ||
           ((puVar2 = (undefined *)0xfffffed4, *(int *)((int)register0x00000038 + -0x34) == 0x20 &&
            ((*(char *)((int)register0x00000038 + -0x35) == '\x01' &&
             (*(int *)((int)register0x00000038 + -0x1c) != 0)))))) &&
          (puVar2 = (undefined *)0xfffffed4, *(int *)((int)register0x00000038 + -0x20) == 0x2200018)
          ) && ((puVar2 = *(undefined **)((int)register0x00000038 + -0x1c),
                puVar2 == (undefined *)0x0 &&
                (puVar2 = (undefined *)0xfffffed4,
                *(int *)((int)register0x00000038 + -0x18) == 0x2200018)))) {
        *param_2 = *(undefined4 *)((int)register0x00000038 + -0x14);
        puVar2 = *(undefined **)((int)register0x00000038 + -0x1c);
      }
    }
    else {
      puVar2 = (undefined *)0xfffffed3;
    }
  }
  else if (puVar2 == (undefined *)0xffffff36) {
    _mig_dealloc_reply_port();
    return CONCAT44(uVar1,puVar2);
  }
  return CONCAT44(param_2,puVar2);
}
/* GHIDRADEC_FUNCTION index=3244 start=0xf00f484c */

/* WARNING: Removing unreachable block (ram,0xf00f48d0) */
/* WARNING: Removing unreachable block (ram,0xf00f48ac) */

undefined8
_vm_protect_EXTERNAL
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar2;
  undefined4 unaff_i1;
  undefined *puVar3;
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
  *(undefined4 *)((int)register0x00000038 + -0x24) = param_2;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = param_3;
  *(undefined4 *)((int)register0x00000038 + -0x14) = param_4;
  *(undefined4 *)((int)register0x00000038 + -0xc) = param_5;
  *(undefined *)((int)register0x00000038 + -0x3d) = 1;
  *(undefined4 *)((int)register0x00000038 + -0x3c) = 0x38;
  *(undefined4 *)((int)register0x00000038 + -0x38) = 0x100;
  *(undefined4 *)((int)register0x00000038 + -0x30) = param_1;
  *(undefined4 *)((int)register0x00000038 + -0x28) = 0x2200018;
  *(undefined4 *)((int)register0x00000038 + -0x20) = 0x2200018;
  puVar3 = (undefined *)((int)register0x00000038 + -0x40);
  uVar1 = 0x2200018;
  *(undefined4 *)((int)register0x00000038 + -0x18) = 0x200018;
  *(undefined4 *)((int)register0x00000038 + -0x10) = 0x2200018;
  _mig_get_reply_port();
  *(undefined4 *)((int)register0x00000038 + -0x34) = uVar1;
  *(undefined4 *)((int)register0x00000038 + -0x2c) = 0x7e8;
  uVar1 = 0;
  puVar2 = puVar3;
  _msg_rpc(puVar3,0,0x20,0,0);
  if (puVar2 == (undefined *)0x0) {
    if (*(int *)((int)register0x00000038 + -0x2c) == 0x84c) {
      puVar2 = (undefined *)0xfffffed4;
      if (((*(int *)((int)register0x00000038 + -0x3c) == 0x20) &&
          (((*(char *)((int)register0x00000038 + -0x3d) == '\x01' ||
            ((*(char *)((int)register0x00000038 + -0x3d) == '\x01' &&
             (*(int *)((int)register0x00000038 + -0x24) != 0)))) &&
           (puVar2 = (undefined *)0xfffffed4, *(int *)((int)register0x00000038 + -0x28) == 0x2200018
           )))) && (puVar2 = *(undefined **)((int)register0x00000038 + -0x24),
                   puVar2 == (undefined *)0x0)) {
        puVar2 = (undefined *)0x0;
      }
    }
    else {
      puVar2 = (undefined *)0xfffffed3;
    }
  }
  else if (puVar2 == (undefined *)0xffffff36) {
    _mig_dealloc_reply_port();
    return CONCAT44(uVar1,puVar2);
  }
  return CONCAT44(puVar3,puVar2);
}
/* GHIDRADEC_FUNCTION index=3245 start=0xf00f4978 */

/* WARNING: Removing unreachable block (ram,0xf00f49f0) */
/* WARNING: Removing unreachable block (ram,0xf00f49cc) */

undefined8
_vm_write_EXTERNAL(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar2;
  undefined4 unaff_i1;
  undefined *puVar3;
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
  *(undefined4 *)((int)register0x00000038 + -0x1c) = param_2;
  *(undefined4 *)((int)register0x00000038 + -0xc) = param_3;
  *(undefined *)((int)register0x00000038 + -0x35) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x34) = 0x30;
  *(undefined4 *)((int)register0x00000038 + -0x30) = 0x100;
  *(undefined4 *)((int)register0x00000038 + -0x28) = param_1;
  *(undefined4 *)((int)register0x00000038 + -0x20) = 0x2200018;
  puVar3 = (undefined *)((int)register0x00000038 + -0x38);
  *(undefined4 *)((int)register0x00000038 + -0x18) = 4;
  uVar1 = 0;
  *(undefined4 *)((int)register0x00000038 + -0x14) = 0x90008;
  *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x10) = param_4;
  _mig_get_reply_port();
  *(undefined4 *)((int)register0x00000038 + -0x2c) = uVar1;
  *(undefined4 *)((int)register0x00000038 + -0x24) = 0x7eb;
  uVar1 = 0;
  puVar2 = puVar3;
  _msg_rpc(puVar3,0,0x20,0,0);
  if (puVar2 == (undefined *)0x0) {
    if (*(int *)((int)register0x00000038 + -0x24) == 0x84f) {
      puVar2 = (undefined *)0xfffffed4;
      if (((*(int *)((int)register0x00000038 + -0x34) == 0x20) &&
          (((*(char *)((int)register0x00000038 + -0x35) == '\x01' ||
            ((*(char *)((int)register0x00000038 + -0x35) == '\x01' &&
             (*(int *)((int)register0x00000038 + -0x1c) != 0)))) &&
           (puVar2 = (undefined *)0xfffffed4, *(int *)((int)register0x00000038 + -0x20) == 0x2200018
           )))) && (puVar2 = *(undefined **)((int)register0x00000038 + -0x1c),
                   puVar2 == (undefined *)0x0)) {
        puVar2 = (undefined *)0x0;
      }
    }
    else {
      puVar2 = (undefined *)0xfffffed3;
    }
  }
  else if (puVar2 == (undefined *)0xffffff36) {
    _mig_dealloc_reply_port();
    return CONCAT44(uVar1,puVar2);
  }
  return CONCAT44(puVar3,puVar2);
}
/* GHIDRADEC_FUNCTION index=3246 start=0xf0006e8c */

void sub_F0006E8C(void)

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
  func_0xf0006ec8();
  return;
}
/* GHIDRADEC_FUNCTION index=3247 start=0xf0006e98 */

/* WARNING: Removing unreachable block (ram,0xf0006f04) */
/* WARNING: Removing unreachable block (ram,0xf0006ed8) */

undefined8 sub_F0006E98(uint param_1,uint param_2,uint param_3,uint param_4)

{
  bool bVar1;
  uint uVar2;
  undefined4 unaff_l0;
  uint uVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  uint uVar4;
  undefined4 unaff_l4;
  int iVar5;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  uint uVar6;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar7;
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
  uVar4 = param_3 ^ param_2;
  if (((int)(param_3 | param_2) < 0) &&
     ((-1 < (int)param_3 || (param_3 = -param_3, (int)param_2 < 0)))) {
    bVar7 = param_1 != 0;
    param_1 = -param_1;
    param_2 = -(uint)bVar7 - param_2;
  }
  if (param_2 < param_3) {
    uVar6 = 0;
    param_4 = param_2;
  }
  else {
    .udiv(param_2,param_3);
    uVar6 = param_2;
    if ((int)param_4 < 0) {
      param_4 = param_4 + param_3;
    }
  }
  if (param_4 == 0) {
    .udiv(param_1,param_3);
    uVar3 = param_1;
  }
  else {
    uVar3 = 0;
    bVar7 = CARRY4(param_1,param_1);
    iVar5 = 0x20;
    while( true ) {
      param_1 = param_1 * 2;
      uVar2 = param_4 * 2;
      bVar1 = CARRY4(param_4,param_4);
      param_4 = param_4 * 2 + (uint)bVar7;
      uVar3 = uVar3 * 2;
      if ((bVar1 || CARRY4(uVar2,(uint)bVar7)) || (param_3 <= param_4)) {
        param_4 = param_4 - param_3;
        uVar3 = uVar3 + 1;
      }
      if (iVar5 < 2) break;
      bVar7 = CARRY4(param_1,param_1);
      iVar5 = iVar5 + -1;
    }
  }
  if ((int)uVar4 < 0) {
    bVar7 = uVar3 != 0;
    uVar3 = -uVar3;
    uVar6 = -(uint)bVar7 - uVar6;
  }
  return CONCAT44(uVar6,uVar3);
}
/* GHIDRADEC_FUNCTION index=3248 start=0xf0007114 */

/* WARNING: Control flow encountered unimplemented instructions */

void sub_F0007114(int param_1)

{
  if (0xf < param_1) {
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}
/* GHIDRADEC_FUNCTION index=3249 start=0xf00071d8 */

/* WARNING: Control flow encountered unimplemented instructions */

void sub_F00071D8(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (0xf < param_3) {
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}

