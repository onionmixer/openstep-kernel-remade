
/* WARNING: Removing unreachable block (ram,0xf008f0dc) */
/* WARNING: Removing unreachable block (ram,0xf008f0c4) */
/* WARNING: Removing unreachable block (ram,0xf008f0ac) */
/* WARNING: Removing unreachable block (ram,0xf008f0d0) */
/* WARNING: Removing unreachable block (ram,0xf008f0f8) */
/* WARNING: Removing unreachable block (ram,0xf008f098) */

undefined8 -[KernDeviceDescription free](int param_1,undefined4 param_2)

{
  undefined5 *puVar1;
  undefined (*pauVar2) [17];
  undefined *puVar3;
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
  
  pauVar2 = paFreekeysValues;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x10),paFreekeysValues,sub_F008EE50,sub_F008EE5C);
  puVar1 = paFree;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x10),paFree);
  _objc_msgSend(*(undefined4 *)(param_1 + 0xc),pauVar2,sub_F008EE50,sub_F008EE7C);
  _objc_msgSend(*(undefined4 *)(param_1 + 0xc),puVar1);
  _objc_msgSend(*(undefined4 *)(param_1 + 0x14),puVar1);
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  puVar3 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141ce0;
  _objc_msgSendSuper(puVar3,puVar1);
  return CONCAT44(param_2,puVar3);
}

