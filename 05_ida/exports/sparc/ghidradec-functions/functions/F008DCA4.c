
/* WARNING: Removing unreachable block (ram,0xf008dce0) */
/* WARNING: Removing unreachable block (ram,0xf008dd0c) */
/* WARNING: Removing unreachable block (ram,0xf008dd50) */

undefined8
-[KernBusMemoryRangeMapping initWithRange:subRange:inTarget:cache:]
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,int param_5)

{
  code *pcVar1;
  undefined *puVar2;
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
  if (param_5 == 0) {
    _objc_msgSend(param_1,paFree,param_3);
  }
  else {
    puVar2 = (undefined *)((int)register0x00000038 + -0x10);
    *(undefined4 *)((int)register0x00000038 + -0x20) = *param_4;
    *(undefined4 *)((int)register0x00000038 + -0x1c) = param_4[1];
    *(undefined4 *)((int)register0x00000038 + -0x10) = param_1;
    *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141c18;
    _objc_msgSendSuper(puVar2,paInitwithrangeS,param_3,
                       (undefined *)((int)register0x00000038 + -0x20));
    if (puVar2 != (undefined *)0x0) {
      _objc_msgSend((undefined *)((int)register0x00000038 + -0x18),param_1,paMappedrange_0);
                    /* WARNING: Does not return */
      pcVar1 = (code *)IllegalInstructionTrap(8);
      (*pcVar1)();
    }
    param_1 = 0;
  }
  return CONCAT44(param_2,param_1);
}
