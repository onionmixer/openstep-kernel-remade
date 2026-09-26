
/* WARNING: Removing unreachable block (ram,0xf00cca14) */
/* WARNING: Removing unreachable block (ram,0xf00cc9f4) */
/* WARNING: Removing unreachable block (ram,0xf00cc998) */
/* WARNING: Removing unreachable block (ram,0xf00cc980) */
/* WARNING: Removing unreachable block (ram,0xf00cc9cc) */
/* WARNING: Removing unreachable block (ram,0xf00cca04) */
/* WARNING: Removing unreachable block (ram,0xf00cca44) */
/* WARNING: Removing unreachable block (ram,0xf00cc93c) */

undefined8
-[IOTokenRing attachToNetworkWithAddress:](int param_1,undefined4 param_2,undefined *param_3)

{
  undefined6 *puVar1;
  undefined5 *puVar2;
  undefined (*pauVar3) [10];
  int iVar4;
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
  _objc_msgSend(param_1,paRegisterdevice);
  *(undefined *)(param_1 + 0x13c) = *param_3;
  *(undefined *)(param_1 + 0x13d) = param_3[1];
  *(undefined *)(param_1 + 0x13e) = param_3[2];
  *(undefined *)(param_1 + 0x13f) = param_3[3];
  pauVar3 = paIonetwork;
  *(undefined *)(param_1 + 0x140) = param_3[4];
  puVar1 = paAlloc;
  *(undefined *)(param_1 + 0x141) = param_3[5];
  _objc_msgSend(pauVar3,puVar1);
  puVar2 = paUnit_0;
  iVar4 = param_1;
  _objc_msgSend(param_1,paUnit_0);
  _objc_msgSend(pauVar3,paInitfornetwork,param_1,&aTr,iVar4,a416mbTokenRing,
                *(undefined4 *)(param_1 + 0x138),0);
  *(undefined (**) [10])(param_1 + 0x150) = pauVar3;
  if ((*(uint *)(param_1 + 0x128) & 0x10000000) != 0) {
    _objc_msgSend(param_1,puVar2);
    _vtrip_config();
  }
  iVar4 = param_1;
  _objc_msgSend(param_1,paName);
  _IOLog(aSTokenRingNode,iVar4,*(undefined *)(param_1 + 0x13c),*(undefined *)(param_1 + 0x13d),
         *(undefined *)(param_1 + 0x13e),*(undefined *)(param_1 + 0x13f),
         *(undefined *)(param_1 + 0x140),*(undefined *)(param_1 + 0x141));
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x150));
}

