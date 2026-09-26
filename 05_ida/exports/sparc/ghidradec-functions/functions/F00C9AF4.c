
/* WARNING: Removing unreachable block (ram,0xf00c9bfc) */
/* WARNING: Removing unreachable block (ram,0xf00c9bc0) */
/* WARNING: Removing unreachable block (ram,0xf00c9b58) */
/* WARNING: Removing unreachable block (ram,0xf00c9b84) */
/* WARNING: Removing unreachable block (ram,0xf00c9b2c) */
/* WARNING: Removing unreachable block (ram,0xf00c9b3c) */
/* WARNING: Removing unreachable block (ram,0xf00c9b9c) */
/* WARNING: Removing unreachable block (ram,0xf00c9b6c) */
/* WARNING: Removing unreachable block (ram,0xf00c9be8) */
/* WARNING: Removing unreachable block (ram,0xf00c9c18) */
/* WARNING: Removing unreachable block (ram,0xf00c9b04) */

undefined8
-[IODirectDevice mapMemoryRange:to:findSpace:cache:]
          (int param_1,undefined4 param_2,uint param_3,int *param_4,uint param_5,undefined4 param_6)

{
  undefined (*pauVar1) [29];
  undefined (*pauVar2) [19];
  uint uVar3;
  int iVar4;
  undefined (**ppauVar5) [20];
  int iVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar8;
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
  uVar3 = *(uint *)(param_1 + 0x108);
  piVar7 = *(int **)(param_1 + 0x11c);
  _objc_msgSend(uVar3,paNummemoryrange);
  if (param_3 < uVar3) {
    iVar4 = *(int *)(param_1 + 0x114);
    _objc_msgSend(iVar4,paResourcesforke,aMemoryMaps);
    _objc_msgSend();
    pauVar2 = paMapintargetCac;
    pauVar1 = paMaptoaddressIn;
    if ((param_5 & 0xff) == 0) {
      ppauVar5 = &paSearchreserveq;
      iVar6 = *param_4;
      _current_task_EXTERNAL();
      _objc_msgSend(iVar4,pauVar1,iVar6,ppauVar5,param_6);
    }
    else {
      ppauVar5 = &paSearchreserveq;
      _current_task_EXTERNAL();
      _objc_msgSend(iVar4,pauVar2,ppauVar5,param_6);
    }
    if (iVar4 == 0) {
      uVar8 = 0xfffffd43;
    }
    else {
      iVar6 = iVar4;
      _objc_msgSend(iVar4,paAddress_1);
      *param_4 = iVar6;
      iVar6 = *piVar7;
      if (iVar6 == 0) {
        iVar6 = paHashtable;
        _objc_msgSend(paHashtable,paAlloc);
        _objc_msgSend();
        *piVar7 = iVar6;
        iVar6 = *piVar7;
      }
      _objc_msgSend(iVar6,paInsertkeyValue,*param_4,iVar4);
      uVar8 = 0;
    }
  }
  else {
    uVar8 = 0xfffffd3e;
  }
  return CONCAT44(param_2,uVar8);
}
