
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

