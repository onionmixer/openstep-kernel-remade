
/* WARNING: Removing unreachable block (ram,0xf00c4f64) */
/* WARNING: Removing unreachable block (ram,0xf00c4f8c) */
/* WARNING: Removing unreachable block (ram,0xf00c4f38) */
/* WARNING: Removing unreachable block (ram,0xf00c4e98) */
/* WARNING: Removing unreachable block (ram,0xf00c4fb0) */
/* WARNING: Removing unreachable block (ram,0xf00c4f9c) */
/* WARNING: Removing unreachable block (ram,0xf00c4f70) */
/* WARNING: Removing unreachable block (ram,0xf00c4e84) */

undefined8
+[IODevice addToCdevswFromDescription:open:close:read:write:ioctl:stop:reset:select:mmap:getc:putc:]
          (undefined4 param_1,undefined4 param_2,char *param_3,undefined4 param_4,undefined4 param_5
          ,undefined4 param_6)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 uVar5;
  undefined4 unaff_l1;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 unaff_l3;
  undefined4 uVar8;
  undefined4 unaff_l4;
  undefined4 uVar9;
  undefined4 unaff_l5;
  undefined4 uVar10;
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
  uVar5 = *(undefined4 *)((int)register0x00000038 + 100);
  uVar6 = *(undefined4 *)((int)register0x00000038 + 0x68);
  uVar7 = *(undefined4 *)((int)register0x00000038 + 0x6c);
  uVar8 = *(undefined4 *)((int)register0x00000038 + 0x70);
  uVar9 = *(undefined4 *)((int)register0x00000038 + 0x74);
  uVar10 = *(undefined4 *)((int)register0x00000038 + 0x78);
  _objc_msgSend(param_3,paConfigtable_0);
  _objc_msgSend();
  if (param_3 == (char *)0x0) {
    iVar4 = -1;
  }
  else {
    cVar1 = *param_3;
    iVar4 = 0;
    cVar2 = *param_3;
    while ((cVar1 != '\0' && (param_3 = param_3 + 1, (byte)(cVar2 - 0x30U) < 10))) {
      cVar1 = *param_3;
      iVar4 = iVar4 * 10 + -0x30 + (int)cVar2;
      cVar2 = *param_3;
    }
  }
  iVar3 = iVar4;
  _IOAddToCdevswAt(iVar4,param_4,param_5,param_6,*(undefined4 *)((int)register0x00000038 + 0x5c),
                   *(undefined4 *)((int)register0x00000038 + 0x60),uVar5,uVar6,uVar7,uVar8,uVar9,
                   uVar10);
  if (iVar3 < 0) {
    if (iVar4 < 0) {
      _objc_msgSend(param_1,paName,iVar3);
      _IOLog(aSCouldNotAddTo,param_1);
      uVar5 = 0;
    }
    else {
      _objc_msgSend(param_1,paName,iVar3);
      _IOLog(aSCouldNotAddTo_0,param_1,iVar4);
      uVar5 = 0;
    }
  }
  else {
    _objc_msgSend(param_1,paSetcharacterma,iVar3);
    uVar5 = 1;
  }
  return CONCAT44(param_2,uVar5);
}

