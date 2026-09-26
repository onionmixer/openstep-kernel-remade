
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
