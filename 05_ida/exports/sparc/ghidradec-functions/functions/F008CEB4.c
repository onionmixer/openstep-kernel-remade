
/* WARNING: Removing unreachable block (ram,0xf008cf4c) */
/* WARNING: Removing unreachable block (ram,0xf008cf20) */
/* WARNING: Removing unreachable block (ram,0xf008cedc) */

undefined8
-[KernBusRangeResource initWithExtent:kind:owner:]
          (int param_1,undefined4 param_2,uint *param_3,int param_4,undefined4 param_5)

{
  bool bVar1;
  uint uVar2;
  undefined (*pauVar3) [12];
  uint uVar4;
  uint uVar5;
  uint uVar6;
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
  uVar6 = *param_3;
  uVar5 = param_3[1];
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141ba0;
  _objc_msgSendSuper((undefined *)((int)register0x00000038 + -0x10),paInit);
  uVar4 = *param_3;
  *(uint *)((int)register0x00000038 + -0x18) = uVar4;
  uVar2 = param_3[1];
  *(uint *)((int)register0x00000038 + -0x14) = uVar2;
  uVar2 = uVar4 + uVar2;
  if ((uVar2 == 0) || (bVar1 = false, uVar4 < uVar2)) {
    bVar1 = true;
  }
  if (bVar1) {
    *(undefined4 *)(param_1 + 4) = param_5;
    if (param_4 == 0) {
      pauVar3 = paKernbusrange;
      _objc_msgSend(paKernbusrange,paClass);
      *(undefined (**) [12])(param_1 + 0x10) = pauVar3;
    }
    else {
      *(int *)(param_1 + 0x10) = param_4;
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(uint *)(param_1 + 0xc) = uVar6 + uVar5;
    *(uint *)(param_1 + 8) = *param_3;
  }
  else {
    _objc_msgSend(param_1,paFree);
  }
  return CONCAT44(param_2,param_1);
}
