
/* WARNING: Removing unreachable block (ram,0xf008ff58) */
/* WARNING: Removing unreachable block (ram,0xf008ff3c) */
/* WARNING: Removing unreachable block (ram,0xf008ff08) */
/* WARNING: Removing unreachable block (ram,0xf008fec0) */
/* WARNING: Removing unreachable block (ram,0xf008fe90) */
/* WARNING: Removing unreachable block (ram,0xf008fe9c) */
/* WARNING: Removing unreachable block (ram,0xf008fed8) */
/* WARNING: Removing unreachable block (ram,0xf008ff1c) */
/* WARNING: Removing unreachable block (ram,0xf008ff4c) */
/* WARNING: Removing unreachable block (ram,0xf008fe78) */
/* WARNING: Removing unreachable block (ram,0xf008fe5c) */

undefined8
-[KernDeviceDescription _parseItemResourceByKey:value:]
          (int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined5 *puVar3;
  undefined (*pauVar4) [13];
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined5 *puVar5;
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
  iVar1 = *(int *)(param_1 + 0x1c);
  _objc_msgSend(iVar1,paLookupresource,param_3);
  if (iVar1 == 0) {
    _printf(aSCouldnTLocate_0,param_3);
    puVar5 = (undefined5 *)0x0;
  }
  else {
    puVar5 = paList;
    _objc_msgSend(paList,paAlloc);
    _objc_msgSend();
    *(int *)((int)register0x00000038 + -0x14) = param_4;
    if (param_4 != 0) {
      _objc_msgSend(param_1,paIsshared,param_3);
      iVar2 = *(int *)((int)register0x00000038 + -0x14);
      while( true ) {
        sub_F008FA58(iVar2,(undefined *)((int)register0x00000038 + -0x14),
                     (undefined *)((int)register0x00000038 + -0x18));
        if (iVar2 == 0) break;
        pauVar4 = (undefined (*) [13])paShareitem;
        if ((char)param_1 == '\0') {
          pauVar4 = paReserveitem;
        }
        iVar2 = iVar1;
        _objc_msgSend(iVar1,pauVar4,*(undefined4 *)((int)register0x00000038 + -0x18));
        puVar3 = puVar5;
        _objc_msgSend(puVar5,paAddobject,iVar2);
        if (puVar3 == (undefined5 *)0x0) {
          _printf(aSCouldnTReserv_0,param_3,*(undefined4 *)((int)register0x00000038 + -0x18));
          _objc_msgSend(puVar5,paFreeobjects);
          _objc_msgSend();
          break;
        }
        iVar2 = *(int *)((int)register0x00000038 + -0x14);
      }
    }
  }
  return CONCAT44(param_2,puVar5);
}

