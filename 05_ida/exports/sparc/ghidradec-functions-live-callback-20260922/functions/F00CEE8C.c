
/* WARNING: Removing unreachable block (ram,0xf00cef00) */
/* WARNING: Removing unreachable block (ram,0xf00cf01c) */
/* WARNING: Removing unreachable block (ram,0xf00cefb8) */
/* WARNING: Removing unreachable block (ram,0xf00cef68) */
/* WARNING: Removing unreachable block (ram,0xf00cef44) */
/* WARNING: Removing unreachable block (ram,0xf00cef20) */
/* WARNING: Removing unreachable block (ram,0xf00cef58) */
/* WARNING: Removing unreachable block (ram,0xf00cef80) */
/* WARNING: Removing unreachable block (ram,0xf00ceff4) */
/* WARNING: Removing unreachable block (ram,0xf00ceee8) */
/* WARNING: Removing unreachable block (ram,0xf00cef10) */
/* WARNING: Removing unreachable block (ram,0xf00ceeac) */

undefined8
-[SCSIDisk deviceRwCommon:block:length:buffer:client:pending:actualLength:]
          (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,int param_5
          ,undefined4 param_6)

{
  undefined (*pauVar1) [11];
  undefined (*pauVar2) [14];
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  int iVar6;
  undefined4 unaff_l4;
  undefined4 uVar7;
  undefined4 unaff_l5;
  undefined4 *puVar8;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar9;
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
  uVar7 = *(undefined4 *)((int)register0x00000038 + 0x5c);
  iVar6 = *(int *)((int)register0x00000038 + 0x60);
  puVar8 = *(undefined4 **)((int)register0x00000038 + 100);
  puVar9 = param_1;
  _objc_msgSend(param_1,paIsdiskready,1);
  if (puVar9 == (undefined4 *)0xfffffbb2) {
    puVar9 = (undefined4 *)0xfffffbb2;
  }
  else if (puVar9 == (undefined4 *)0x0) {
    puVar9 = param_1;
    _objc_msgSend(param_1,paIsformatted);
    if (((uint)puVar9 & 0xff) == 0) {
      puVar9 = (undefined4 *)0xfffffbb3;
    }
    else {
      puVar3 = param_1;
      _objc_msgSend(param_1,paBlocksize);
      puVar4 = param_1;
      _objc_msgSend(param_1,paDisksize);
      iVar5 = param_5;
      urem(param_5,puVar3);
      puVar9 = (undefined4 *)0xffffffff;
      if (iVar5 == 0) {
        udiv(param_5,puVar3);
        if ((puVar4 < (undefined4 *)((int)param_4 + param_5)) &&
           (param_5 = (int)puVar4 - (int)param_4, puVar4 <= param_4)) {
          puVar9 = (undefined4 *)0xfffffd3e;
        }
        else {
          puVar3 = param_1;
          _objc_msgSend(param_1,paAllocsdbuf,iVar6);
          *puVar3 = param_3;
          puVar3[1] = param_4;
          puVar3[2] = param_5;
          puVar3[3] = param_6;
          puVar3[4] = uVar7;
          pauVar2 = paEnqueuesdbuf;
          puVar3[8] = puVar3[8] | 0x80000000;
          puVar9 = param_1;
          _objc_msgSend(param_1,pauVar2,puVar3);
          pauVar1 = paFreesdbuf;
          if (iVar6 == 0) {
            *puVar8 = puVar3[9];
            _objc_msgSend(param_1,pauVar1);
          }
        }
      }
    }
  }
  else {
    puVar8 = param_1;
    _objc_msgSend(param_1,paName);
    _objc_msgSend(param_1,paStringfromretu,puVar9);
    _IOLog(aSDevicerwcommo,puVar8,param_1);
  }
  return CONCAT44(param_2,puVar9);
}

