
/* WARNING: Removing unreachable block (ram,0xf009077c) */
/* WARNING: Removing unreachable block (ram,0xf0090728) */
/* WARNING: Removing unreachable block (ram,0xf00906d8) */
/* WARNING: Removing unreachable block (ram,0xf0090688) */
/* WARNING: Removing unreachable block (ram,0xf0090650) */
/* WARNING: Removing unreachable block (ram,0xf0090600) */
/* WARNING: Removing unreachable block (ram,0xf00905c8) */
/* WARNING: Removing unreachable block (ram,0xf0090578) */
/* WARNING: Removing unreachable block (ram,0xf009058c) */
/* WARNING: Removing unreachable block (ram,0xf00905d4) */
/* WARNING: Removing unreachable block (ram,0xf0090614) */
/* WARNING: Removing unreachable block (ram,0xf009065c) */
/* WARNING: Removing unreachable block (ram,0xf009069c) */
/* WARNING: Removing unreachable block (ram,0xf00906e8) */
/* WARNING: Removing unreachable block (ram,0xf009073c) */
/* WARNING: Removing unreachable block (ram,0xf009078c) */
/* WARNING: Removing unreachable block (ram,0xf0090560) */

undefined8
_kern_IOGetEISADeviceConfig(int param_1,int param_2,int *param_3,int param_4,int *param_5)

{
  code *pcVar1;
  int iVar2;
  undefined4 unaff_l0;
  int iVar3;
  int iVar4;
  undefined4 unaff_l1;
  int iVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  int *piVar6;
  undefined4 unaff_l7;
  int *piVar7;
  undefined4 unaff_i0;
  undefined4 uVar8;
  int iVar9;
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
  piVar6 = *(int **)((int)register0x00000038 + 0x5c);
  piVar7 = *(int **)((int)register0x00000038 + 100);
  if (param_1 == 0) {
    uVar8 = 0xfffffd3f;
  }
  else {
    _objc_msgSend(param_1,paDevicedescript_1);
    iVar4 = param_1;
    _objc_msgSend();
    iVar3 = iVar4;
    _objc_msgSend(iVar4,paCount_0);
    if (7 < iVar3) {
      iVar3 = 7;
    }
    iVar9 = 0;
    if (iVar3 < 1) {
      *param_3 = iVar3;
    }
    else {
      iVar5 = 0;
      do {
        iVar2 = iVar4;
        _objc_msgSend(iVar4,paObjectat,iVar9);
        iVar9 = iVar9 + 1;
        _objc_msgSend();
        *(int *)(iVar5 + param_2) = iVar2;
        iVar5 = iVar5 + 4;
      } while (iVar9 < iVar3);
      *param_3 = iVar3;
    }
    iVar4 = param_1;
    _objc_msgSend(param_1,paResourcesforke,aDmaChannels);
    iVar3 = iVar4;
    _objc_msgSend(iVar4,paCount_0);
    if (4 < iVar3) {
      iVar3 = 4;
    }
    iVar9 = 0;
    if (iVar3 < 1) {
      *param_5 = iVar3;
    }
    else {
      param_2 = 0;
      do {
        iVar5 = iVar4;
        _objc_msgSend(iVar4,paObjectat,iVar9);
        iVar9 = iVar9 + 1;
        _objc_msgSend();
        *(int *)(param_2 + param_4) = iVar5;
        param_2 = param_2 + 4;
      } while (iVar9 < iVar3);
      *param_5 = iVar3;
    }
    iVar4 = param_1;
    _objc_msgSend(param_1,paResourcesforke,aIOPorts);
    iVar3 = iVar4;
    _objc_msgSend(iVar4,paCount_0);
    if (0x14 < iVar3) {
      iVar3 = 0x14;
    }
    if (0 < iVar3) {
      _objc_msgSend(iVar4,paObjectat,0);
      _objc_msgSend((undefined *)((int)register0x00000038 + -0x10));
                    /* WARNING: Does not return */
      pcVar1 = (code *)IllegalInstructionTrap(8);
      (*pcVar1)();
    }
    *piVar6 = iVar3;
    _objc_msgSend(param_1,paResourcesforke,aMemoryMaps_0);
    iVar4 = param_1;
    _objc_msgSend(param_1,paCount_0);
    if (9 < iVar4) {
      iVar4 = 9;
    }
    uVar8 = 0;
    if (0 < iVar4) {
      _objc_msgSend(param_1,paObjectat,0);
      _objc_msgSend((undefined *)((int)register0x00000038 + -0x10));
                    /* WARNING: Does not return */
      pcVar1 = (code *)IllegalInstructionTrap(8);
      (*pcVar1)();
    }
    *piVar7 = iVar4;
  }
  return CONCAT44(param_2,uVar8);
}

