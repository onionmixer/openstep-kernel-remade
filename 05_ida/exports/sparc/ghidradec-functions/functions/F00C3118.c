
/* WARNING: Removing unreachable block (ram,0xf00c3210) */
/* WARNING: Removing unreachable block (ram,0xf00c31ec) */
/* WARNING: Removing unreachable block (ram,0xf00c31c8) */
/* WARNING: Removing unreachable block (ram,0xf00c3194) */
/* WARNING: Removing unreachable block (ram,0xf00c3318) */
/* WARNING: Removing unreachable block (ram,0xf00c3304) */
/* WARNING: Removing unreachable block (ram,0xf00c32f0) */
/* WARNING: Removing unreachable block (ram,0xf00c32ac) */
/* WARNING: Removing unreachable block (ram,0xf00c327c) */
/* WARNING: Removing unreachable block (ram,0xf00c324c) */
/* WARNING: Removing unreachable block (ram,0xf00c3150) */
/* WARNING: Removing unreachable block (ram,0xf00c313c) */
/* WARNING: Removing unreachable block (ram,0xf00c3148) */
/* WARNING: Removing unreachable block (ram,0xf00c3164) */
/* WARNING: Removing unreachable block (ram,0xf00c325c) */
/* WARNING: Removing unreachable block (ram,0xf00c32a4) */
/* WARNING: Removing unreachable block (ram,0xf00c32cc) */
/* WARNING: Removing unreachable block (ram,0xf00c32fc) */
/* WARNING: Removing unreachable block (ram,0xf00c3324) */
/* WARNING: Removing unreachable block (ram,0xf00c3180) */
/* WARNING: Removing unreachable block (ram,0xf00c31a8) */
/* WARNING: Removing unreachable block (ram,0xf00c31dc) */
/* WARNING: Removing unreachable block (ram,0xf00c3200) */
/* WARNING: Removing unreachable block (ram,0xf00c322c) */
/* WARNING: Removing unreachable block (ram,0xf00c312c) */

undefined8 _probeNativeDevices(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  undefined (*pauVar2) [19];
  undefined5 *puVar3;
  int iVar4;
  int iVar5;
  undefined (*pauVar6) [14];
  undefined (*pauVar7) [14];
  undefined (*pauVar8) [14];
  undefined (*pauVar9) [12];
  undefined (*pauVar10) [12];
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar11;
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
  bVar1 = false;
  puVar3 = paList;
  _objc_msgSend(paList,paAlloc);
  iVar11 = 1;
  _objc_msgSend();
  _autoConfigTables = puVar3;
  sub_F00C3C24();
  iVar4 = 0x80;
  _IOMalloc();
  pauVar2 = paValueforstring;
  while (iVar5 = iVar11, _findBootConfigString(), iVar5 != 0) {
    pauVar6 = paIoconfigtable;
    _objc_msgSend(paIoconfigtable,paNewforconfigda);
    pauVar7 = pauVar6;
    _objc_msgSend();
    if ((pauVar7 != (undefined (*) [14])0x0) &&
       (pauVar8 = pauVar7, _strcmp(), pauVar8 == (undefined (*) [14])0x0)) {
      pauVar8 = pauVar6;
      _objc_msgSend(pauVar6,pauVar2,aBusType_0);
      _sprintf(iVar4,aSkernbus,pauVar8);
      iVar5 = iVar4;
      _strcmp(iVar4,aSparckernbus_0);
      if (iVar5 == 0) {
        bVar1 = true;
      }
      _objc_getClass(iVar4);
      _objc_msgSend();
    }
    if (pauVar7 != (undefined (*) [14])0x0) {
      _objc_msgSend(pauVar6,paFreestring,pauVar7);
    }
    iVar11 = iVar11 + 1;
  }
  if (!bVar1) {
    _objc_getClass(aSparckernbus_1);
    _objc_msgSend();
  }
  pauVar10 = paKernbus;
  pauVar9 = paKernbus;
  _objc_msgSend(paKernbus,paLookupbusclass,&aSparc);
  _defaultBusClass = pauVar9;
  if (pauVar9 == (undefined (*) [12])0x0) {
    _sprintf(iVar4,aMissingSKernel,&aSparc_0);
    _panic(iVar4);
  }
  iVar11 = 1;
  _objc_msgSend(pauVar10,paLookupbusinsta,&aSparc_1,0);
  pauVar9 = paIodevice_0;
  _defaultBus = pauVar10;
  _objc_msgSend(paIodevice_0,paDriverkitversi_0);
  _printf(aDriverkitVersi,pauVar9);
  while (iVar5 = iVar11, _findBootConfigString(), iVar5 != 0) {
    iVar11 = iVar11 + 1;
    sub_F00C3334();
  }
  _IOFree(iVar4,0x80);
  return CONCAT44(param_2,param_1);
}
