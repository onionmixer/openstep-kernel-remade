
/* WARNING: Removing unreachable block (ram,0xf00a6ecc) */
/* WARNING: Removing unreachable block (ram,0xf00a6eac) */
/* WARNING: Removing unreachable block (ram,0xf00a6eb8) */
/* WARNING: Removing unreachable block (ram,0xf00a6edc) */
/* WARNING: Removing unreachable block (ram,0xf00a6e84) */

undefined8 _getDefaultRoot(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  uint uVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  uint uVar4;
  undefined4 unaff_l3;
  uint uVar5;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar6;
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
  uVar4 = 0;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0;
  if (DAT_f01214f4._0_4_ != -0x58585859) {
    _panic(aGetdefaultroot);
  }
  puVar6 = (undefined *)((int)register0x00000038 + -0x18);
  uVar5 = (uint)DAT_f01214f4[0xb];
  do {
    iVar3 = 0;
    while( true ) {
      _sprintf(puVar6,&aSdD_0,iVar3);
      puVar1 = puVar6;
      _IOGetObjectForDeviceName(puVar6,(undefined *)((int)register0x00000038 + -0x1c));
      uVar2 = *(uint *)((int)register0x00000038 + -0x1c);
      if (puVar1 != (undefined *)0x0) break;
      _objc_msgSend(uVar2,paTarget);
      uVar4 = *(uint *)((int)register0x00000038 + -0x1c);
      _objc_msgSend(uVar4,paInquirydevicet);
      if ((uVar5 == (uVar2 & 0xff)) && (((uVar4 & 0xff) == 5 || ((uVar4 & 0xff) == 0))))
      goto locret_F00A6F38;
      iVar3 = iVar3 + 1;
      uVar4 = uVar2;
      if (0xf < iVar3) break;
    }
    if (((uVar4 & 0xff) == uVar5) && (puVar1 != (undefined *)0x0)) {
      puVar6 = (undefined *)0x0;
locret_F00A6F38:
      return CONCAT44(param_2,puVar6);
    }
  } while( true );
}
