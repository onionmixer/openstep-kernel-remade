
/* WARNING: Removing unreachable block (ram,0xf00cb8b0) */
/* WARNING: Removing unreachable block (ram,0xf00cb8c4) */
/* WARNING: Removing unreachable block (ram,0xf00cb89c) */

undefined8 -[IOEthernet isUnwantedMulticastPacket:](int param_1,undefined4 param_2,byte *param_3)

{
  byte bVar1;
  int iVar2;
  bool bVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
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
  bVar3 = true;
  if ((*param_3 & 1) == 0) {
    uVar4 = 0;
  }
  else if (*(char *)(param_1 + 0x129) == '\0') {
    iVar2 = 0;
    bVar1 = *param_3;
    while (iVar2 = iVar2 + 1, bVar1 == 0xff) {
      if (5 < iVar2) goto loc_F00CB87C;
      bVar1 = param_3[iVar2];
    }
    bVar3 = false;
loc_F00CB87C:
    if (bVar3) {
      uVar4 = 0;
    }
    else {
      _objc_msgSend(*(undefined4 *)(param_1 + 0x138),paLock);
      iVar2 = param_1;
      _objc_msgSend(param_1,paSearchmulti,param_3);
      _objc_msgSend(*(undefined4 *)(param_1 + 0x138),paUnlock);
      uVar4 = 0;
      if (iVar2 == 0) {
        uVar4 = 1;
      }
    }
  }
  else {
    uVar4 = 0;
  }
  return CONCAT44(param_2,uVar4);
}
