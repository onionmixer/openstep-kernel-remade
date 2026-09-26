
/* WARNING: Removing unreachable block (ram,0xf00c50a8) */
/* WARNING: Removing unreachable block (ram,0xf00c50d0) */
/* WARNING: Removing unreachable block (ram,0xf00c507c) */
/* WARNING: Removing unreachable block (ram,0xf00c4fe8) */
/* WARNING: Removing unreachable block (ram,0xf00c50f4) */
/* WARNING: Removing unreachable block (ram,0xf00c50e0) */
/* WARNING: Removing unreachable block (ram,0xf00c50b4) */
/* WARNING: Removing unreachable block (ram,0xf00c4fd4) */

undefined8
+[IODevice addToBdevswFromDescription:open:close:strategy:dump:psize:isTape:]
          (undefined4 param_1,undefined4 param_2,char *param_3,undefined4 param_4,undefined4 param_5
          ,undefined4 param_6)

{
  char cVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar6;
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
  cVar2 = *(char *)((int)register0x00000038 + 0x67);
  _objc_msgSend(param_3,paConfigtable_0);
  _objc_msgSend();
  if (param_3 == (char *)0x0) {
    iVar5 = -1;
  }
  else {
    cVar1 = *param_3;
    iVar5 = 0;
    cVar3 = *param_3;
    while ((cVar1 != '\0' && (param_3 = param_3 + 1, (byte)(cVar3 - 0x30U) < 10))) {
      cVar1 = *param_3;
      iVar5 = iVar5 * 10 + -0x30 + (int)cVar3;
      cVar3 = *param_3;
    }
  }
  iVar4 = iVar5;
  _IOAddToBdevswAt(iVar5,param_4,param_5,param_6,*(undefined4 *)((int)register0x00000038 + 0x5c),
                   *(undefined4 *)((int)register0x00000038 + 0x60),(int)cVar2);
  if (iVar4 < 0) {
    if (iVar5 < 0) {
      _objc_msgSend(param_1,paName,iVar4);
      _IOLog(aSCouldNotAddTo_1,param_1);
      uVar6 = 0;
    }
    else {
      _objc_msgSend(param_1,paName,iVar4);
      _IOLog(aSCouldNotAddTo_2,param_1,iVar5);
      uVar6 = 0;
    }
  }
  else {
    _objc_msgSend(param_1,paSetblockmajor,iVar4);
    uVar6 = 1;
  }
  return CONCAT44(param_2,uVar6);
}

