
/* WARNING: Removing unreachable block (ram,0xf008f028) */
/* WARNING: Removing unreachable block (ram,0xf008efdc) */
/* WARNING: Removing unreachable block (ram,0xf008efb0) */
/* WARNING: Removing unreachable block (ram,0xf008ef74) */
/* WARNING: Removing unreachable block (ram,0xf008ef58) */
/* WARNING: Removing unreachable block (ram,0xf008ef30) */
/* WARNING: Removing unreachable block (ram,0xf008ef10) */
/* WARNING: Removing unreachable block (ram,0xf008ef40) */
/* WARNING: Removing unreachable block (ram,0xf008ef6c) */
/* WARNING: Removing unreachable block (ram,0xf008ef94) */
/* WARNING: Removing unreachable block (ram,0xf008efc8) */
/* WARNING: Removing unreachable block (ram,0xf008f008) */
/* WARNING: Removing unreachable block (ram,0xf008f044) */
/* WARNING: Removing unreachable block (ram,0xf008eeec) */

undefined8
-[KernDeviceDescription initFromConfigTable:](int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined6 *puVar1;
  undefined (*pauVar2) [19];
  undefined (*pauVar3) [10];
  undefined (*pauVar4) [10];
  undefined5 *puVar5;
  int iVar6;
  undefined (*pauVar7) [12];
  int iVar8;
  int iVar9;
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
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141ce0;
  _objc_msgSendSuper((undefined *)((int)register0x00000038 + -0x10),paInit);
  pauVar4 = paHashtable;
  *(undefined4 *)(param_1 + 4) = param_3;
  puVar1 = paAlloc;
  *(undefined4 *)(param_1 + 8) = 0;
  pauVar3 = pauVar4;
  _objc_msgSend(pauVar4,puVar1);
  _objc_msgSend();
  *(undefined (**) [10])(param_1 + 0x10) = pauVar3;
  _objc_msgSend(pauVar4,puVar1);
  _objc_msgSend();
  *(undefined (**) [10])(param_1 + 0xc) = pauVar4;
  puVar5 = paList;
  _objc_msgSend(paList,puVar1);
  _objc_msgSend();
  *(undefined5 **)(param_1 + 0x14) = puVar5;
  pauVar2 = paValueforstring;
  iVar6 = *(int *)(param_1 + 4);
  _objc_msgSend(iVar6,paValueforstring,aBusType);
  pauVar7 = paKernbus;
  _objc_msgSend(paKernbus,paLookupbusclass,iVar6);
  *(undefined (**) [12])(param_1 + 0x18) = pauVar7;
  iVar8 = *(int *)(param_1 + 4);
  _objc_msgSend(iVar8,pauVar2,&aBusId);
  if (iVar8 != 0) {
    iVar9 = iVar8;
    sub_F008FA58();
    if (iVar9 != 0) {
      *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)((int)register0x00000038 + -0x14);
    }
  }
  pauVar7 = paKernbus;
  _objc_msgSend(paKernbus,paLookupbusinsta,iVar6,*(undefined4 *)(param_1 + 0x20));
  *(undefined (**) [12])(param_1 + 0x1c) = pauVar7;
  if (iVar8 != 0) {
    _objc_msgSend(*(undefined4 *)(param_1 + 4),paFreestring,iVar8);
  }
  if (iVar6 != 0) {
    _objc_msgSend(*(undefined4 *)(param_1 + 4),paFreestring,iVar6);
  }
  return CONCAT44(param_2,param_1);
}

