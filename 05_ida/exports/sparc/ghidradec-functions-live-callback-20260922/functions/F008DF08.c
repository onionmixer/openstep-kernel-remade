
/* WARNING: Removing unreachable block (ram,0xf008df8c) */
/* WARNING: Removing unreachable block (ram,0xf008df74) */
/* WARNING: Removing unreachable block (ram,0xf008df4c) */
/* WARNING: Removing unreachable block (ram,0xf008df5c) */
/* WARNING: Removing unreachable block (ram,0xf008df7c) */
/* WARNING: Removing unreachable block (ram,0xf008df94) */
/* WARNING: Removing unreachable block (ram,0xf008df34) */

undefined8
-[KernBusInterrupt initForResource:item:withHandler:shareable:]
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
          char param_6)

{
  undefined6 *puVar1;
  undefined5 *puVar2;
  undefined (*pauVar3) [9];
  undefined (*pauVar4) [9];
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
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141c68;
  _objc_msgSendSuper((undefined *)((int)register0x00000038 + -0x10),paInitforresourc_0,param_3,
                     param_4,(int)param_6);
  puVar1 = paAlloc;
  puVar2 = paList;
  _objc_msgSend(paList,paAlloc);
  _objc_msgSend();
  *(undefined5 **)(param_1 + 0x14) = puVar2;
  pauVar4 = paKernlock;
  pauVar3 = paKernlock;
  _objc_msgSend(paKernlock,puVar1);
  _objc_msgSend();
  *(undefined (**) [9])(param_1 + 0x1c) = pauVar3;
  _objc_msgSend(pauVar4,puVar1);
  _objc_msgSend();
  *(undefined (**) [9])(param_1 + 0x24) = pauVar4;
  *(int *)(param_1 + 0x28) = param_5;
  if (param_5 == 0) {
    *(code **)(param_1 + 0x28) = _KernDeviceInterruptDispatch;
  }
  return CONCAT44(param_2,param_1);
}

