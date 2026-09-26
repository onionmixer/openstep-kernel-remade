
/* WARNING: Removing unreachable block (ram,0xf00c4c88) */
/* WARNING: Removing unreachable block (ram,0xf00c4c20) */
/* WARNING: Removing unreachable block (ram,0xf00c4c38) */
/* WARNING: Removing unreachable block (ram,0xf00c4c9c) */
/* WARNING: Removing unreachable block (ram,0xf00c4c18) */

undefined8 -[IODevice unregisterDevice](int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
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
  _objc_msgSend(dword_F013303C,paLock);
  iVar1 = param_1;
  sub_F00C4750();
  if (iVar1 != 0) {
    _IOLog(aUnregisteringD,param_1 + 8);
    puVar4 = *(undefined4 **)(iVar1 + 8);
    puVar3 = *(undefined4 **)(iVar1 + 0xc);
    if (puVar4 == &dword_F0133034) {
      puVar2 = &dword_F0133034;
    }
    else {
      puVar2 = puVar4 + 2;
    }
    puVar2[1] = puVar3;
    puVar2 = puVar3 + 2;
    if (puVar3 == &dword_F0133034) {
      puVar2 = &dword_F0133034;
    }
    *puVar2 = puVar4;
    _IOFree(iVar1,0x10);
  }
  _objc_msgSend(dword_F013303C,paUnlock);
  return CONCAT44(param_2,param_1);
}

