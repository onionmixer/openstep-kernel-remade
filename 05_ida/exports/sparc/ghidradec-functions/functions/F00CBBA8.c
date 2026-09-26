
/* WARNING: Removing unreachable block (ram,0xf00cbc54) */
/* WARNING: Removing unreachable block (ram,0xf00cbc30) */
/* WARNING: Removing unreachable block (ram,0xf00cbbfc) */
/* WARNING: Removing unreachable block (ram,0xf00cbc44) */
/* WARNING: Removing unreachable block (ram,0xf00cbc84) */
/* WARNING: Removing unreachable block (ram,0xf00cbbe8) */

undefined8
-[IOEthernet attachToNetworkWithAddress:](int param_1,undefined4 param_2,undefined *param_3)

{
  undefined4 uVar1;
  undefined (*pauVar2) [10];
  int iVar3;
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
  *(undefined *)(param_1 + 0x150) = *param_3;
  *(undefined *)(param_1 + 0x151) = param_3[1];
  *(undefined *)(param_1 + 0x152) = param_3[2];
  *(undefined *)(param_1 + 0x153) = param_3[3];
  pauVar2 = paIonetwork;
  *(undefined *)(param_1 + 0x154) = param_3[4];
  uVar1 = paAlloc;
  *(undefined *)(param_1 + 0x155) = param_3[5];
  _objc_msgSend(pauVar2,uVar1);
  iVar3 = param_1;
  _objc_msgSend(param_1,paUnit_0);
  _objc_msgSend(pauVar2,paInitfornetwork,param_1,&unk_F012ECB8,iVar3,a10mbEthernet,0x5dc,0);
  *(undefined (**) [10])(param_1 + 0x14c) = pauVar2;
  _objc_msgSend(param_1,paRegisterasdebu);
  iVar3 = param_1;
  _objc_msgSend(param_1,paName);
  _IOLog(aSEthernetAddre,iVar3,*(undefined *)(param_1 + 0x150),*(undefined *)(param_1 + 0x151),
         *(undefined *)(param_1 + 0x152),*(undefined *)(param_1 + 0x153),
         *(undefined *)(param_1 + 0x154),*(undefined *)(param_1 + 0x155));
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x14c));
}
