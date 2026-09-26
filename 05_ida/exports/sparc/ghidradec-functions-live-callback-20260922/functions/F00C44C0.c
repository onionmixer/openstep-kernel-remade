
/* WARNING: Removing unreachable block (ram,0xf00c45ec) */
/* WARNING: Removing unreachable block (ram,0xf00c45d0) */
/* WARNING: Removing unreachable block (ram,0xf00c459c) */
/* WARNING: Removing unreachable block (ram,0xf00c455c) */
/* WARNING: Removing unreachable block (ram,0xf00c4518) */
/* WARNING: Removing unreachable block (ram,0xf00c44e4) */
/* WARNING: Removing unreachable block (ram,0xf00c450c) */
/* WARNING: Removing unreachable block (ram,0xf00c4550) */
/* WARNING: Removing unreachable block (ram,0xf00c456c) */
/* WARNING: Removing unreachable block (ram,0xf00c45b0) */
/* WARNING: Removing unreachable block (ram,0xf00c45e0) */
/* WARNING: Removing unreachable block (ram,0xf00c4538) */
/* WARNING: Removing unreachable block (ram,0xf00c44d4) */

undefined8
-[SPARCKernDeviceDescription parseIntrResourceByKey:]
          (uint param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined *puVar3;
  undefined5 *puVar4;
  undefined (*pauVar5) [13];
  undefined4 *puVar6;
  undefined4 unaff_l0;
  int iVar7;
  undefined4 uVar8;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined5 *puVar9;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  puVar1 = paBus_0;
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
  iVar7 = *(int *)(param_1 + 0x24);
  uVar2 = param_1;
  _objc_msgSend(param_1,paBus_0);
  _objc_msgSend();
  if (uVar2 == 0) {
    puVar3 = aSCouldnTLocate_1;
  }
  else {
    puVar9 = paList;
    _objc_msgSend(paList,paAlloc);
    _objc_msgSend();
    puVar6 = *(undefined4 **)(iVar7 + 0x1c);
    if (puVar6 != (undefined4 *)0x0) {
      uVar8 = *puVar6;
      _objc_msgSend(param_1,puVar1);
      _objc_msgSend();
      _objc_msgSend();
      pauVar5 = paReserveitem;
      if ((param_1 & 0xff) != 0) {
        pauVar5 = (undefined (*) [13])paShareitem;
      }
      _objc_msgSend(uVar2,pauVar5,uVar8);
      puVar4 = puVar9;
      _objc_msgSend(puVar9,paAddobject,uVar2);
      if (puVar4 == (undefined5 *)0x0) {
        _printf(aSCouldnTReserv_1,param_3,uVar8);
        _objc_msgSend(puVar9,paFreeobjects);
        _objc_msgSend();
      }
      goto locret_F00C45F8;
    }
    puVar3 = aSCouldnTLocate_2;
  }
  _printf(puVar3,param_3);
  puVar9 = (undefined5 *)0x0;
locret_F00C45F8:
  return CONCAT44(param_2,puVar9);
}

