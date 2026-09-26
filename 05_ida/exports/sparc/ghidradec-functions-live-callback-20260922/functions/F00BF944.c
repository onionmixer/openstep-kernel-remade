
/* WARNING: Removing unreachable block (ram,0xf00bf9c4) */
/* WARNING: Removing unreachable block (ram,0xf00bf99c) */
/* WARNING: Removing unreachable block (ram,0xf00bf97c) */
/* WARNING: Removing unreachable block (ram,0xf00bf9b4) */
/* WARNING: Removing unreachable block (ram,0xf00bf9e0) */
/* WARNING: Removing unreachable block (ram,0xf00bf964) */

undefined8 +[EventSrcPCKeyboard probe](int param_1,undefined4 param_2)

{
  undefined (*pauVar1) [9];
  undefined7 *puVar2;
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
  if (dword_F0120AE8 == 0) {
    _objc_msgSend(param_1,paAlloc);
    puVar2 = paNxlock;
    dword_F0120AE8 = param_1;
    _objc_msgSend(paNxlock,paNew);
    pauVar1 = paSetname;
    iVar3 = dword_F0120AE8;
    *(undefined7 **)(dword_F0120AE8 + 0x124) = puVar2;
    _objc_msgSend(iVar3,pauVar1,aEventsrcpckeyb_0);
    _objc_msgSend(dword_F0120AE8,paSetdevicekind,aEventsrcpckeyb_1);
    iVar3 = dword_F0120AE8;
    _objc_msgSend(dword_F0120AE8,paInit);
    if (iVar3 == 0) {
      _objc_msgSend(dword_F0120AE8,paFree);
    }
  }
  return CONCAT44(param_2,dword_F0120AE8);
}

