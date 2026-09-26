
/* WARNING: Removing unreachable block (ram,0xf008ca48) */
/* WARNING: Removing unreachable block (ram,0xf008ca0c) */
/* WARNING: Removing unreachable block (ram,0xf008ca38) */
/* WARNING: Removing unreachable block (ram,0xf008ca5c) */
/* WARNING: Removing unreachable block (ram,0xf008c9e4) */

undefined8
-[KernBusItemResource initWithItemCount:itemBase:itemKind:owner:]
          (int param_1,undefined4 param_2,uint param_3,uint param_4,int param_5,undefined4 param_6)

{
  undefined (*pauVar1) [12];
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
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141bf0;
  _objc_msgSendSuper((undefined *)((int)register0x00000038 + -0x10),paInit);
  if ((param_3 < 0x401) && (param_4 < param_4 + param_3)) {
    *(undefined4 *)(param_1 + 4) = param_6;
    if (param_5 == 0) {
      pauVar1 = paKernbusitem;
      _objc_msgSend(paKernbusitem,paClass);
      *(undefined (**) [12])(param_1 + 0x10) = pauVar1;
    }
    else {
      *(int *)(param_1 + 0x10) = param_5;
    }
    iVar2 = param_3 << 2;
    _IOMalloc();
    *(int *)(param_1 + 0x18) = iVar2;
    *(undefined4 *)(param_1 + 0x14) = 0;
    _bzero(*(undefined4 *)(param_1 + 0x18),param_3 << 2);
    *(uint *)(param_1 + 8) = param_3;
    *(uint *)(param_1 + 0xc) = param_4;
  }
  else {
    _objc_msgSend(param_1,paFree);
  }
  return CONCAT44(param_2,param_1);
}
