
/* WARNING: Removing unreachable block (ram,0xf008d5b8) */
/* WARNING: Removing unreachable block (ram,0xf008d604) */
/* WARNING: Removing unreachable block (ram,0xf008d56c) */

undefined8
-[KernBusRangeMapping initWithRange:subRange:]
          (undefined4 param_1,undefined4 param_2,int param_3,uint *param_4)

{
  code *pcVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
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
  if (param_3 != 0) {
    *(undefined4 *)((int)register0x00000038 + -0x10) = param_1;
    *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141b50;
    _objc_msgSendSuper((undefined *)((int)register0x00000038 + -0x10),paInit);
    uVar4 = *param_4;
    *(uint *)((int)register0x00000038 + -0x20) = uVar4;
    uVar3 = param_4[1];
    *(uint *)((int)register0x00000038 + -0x1c) = uVar3;
    uVar3 = uVar4 + uVar3;
    if ((uVar3 == 0) || (bVar2 = false, uVar4 < uVar3)) {
      bVar2 = true;
    }
    if (bVar2) {
      _objc_msgSend((undefined *)((int)register0x00000038 + -0x18),param_3,paRange_0);
                    /* WARNING: Does not return */
      pcVar1 = (code *)IllegalInstructionTrap(8);
      (*pcVar1)();
    }
  }
  _objc_msgSend(param_1,paFree);
  return CONCAT44(param_2,param_1);
}
