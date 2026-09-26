
/* WARNING: Removing unreachable block (ram,0xf00bc4ac) */
/* WARNING: Removing unreachable block (ram,0xf00bc480) */
/* WARNING: Removing unreachable block (ram,0xf00bc400) */
/* WARNING: Removing unreachable block (ram,0xf00bc3c8) */
/* WARNING: Removing unreachable block (ram,0xf00bc3e4) */
/* WARNING: Removing unreachable block (ram,0xf00bc460) */
/* WARNING: Removing unreachable block (ram,0xf00bc494) */
/* WARNING: Removing unreachable block (ram,0xf00bc4c0) */
/* WARNING: Removing unreachable block (ram,0xf00bc3b0) */

undefined8 +[kmDevice new](int param_1,undefined4 param_2)

{
  undefined (*pauVar1) [11];
  undefined (*pauVar2) [9];
  undefined7 *puVar3;
  undefined4 uVar4;
  int iVar5;
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
  if (dword_F0132074 == 0) {
    dword_F0132070 = 0;
    dword_F0132074 = 1;
  }
  _objc_msgSend(param_1,paAlloc);
  puVar3 = paNxlock;
  _objc_msgSend(paNxlock,paNew);
  pauVar1 = paMethodfor;
  *(undefined7 **)(param_1 + 0x108) = puVar3;
  _objc_msgSend();
  uVar4 = *(undefined4 *)(param_1 + 0x108);
  dword_F0132068 = puVar3;
  _objc_msgSend(uVar4,pauVar1,paUnlock);
  dword_F013206C = uVar4;
  *(undefined4 *)(param_1 + 0x120) = 0;
  *(undefined4 *)(param_1 + 0x110) = 0;
  iVar5 = param_1 + 4;
  while (pauVar2 = paSetunit, param_1 <= iVar5 + -4) {
    *(undefined4 *)(iVar5 + 0x108) = 0;
    iVar5 = iVar5 + -4;
  }
  if (dword_F0132060 == 0) {
    _kmId = param_1;
  }
  iVar5 = _kmId;
  *(undefined4 *)(param_1 + 0x10c) = _basicConsole;
  _objc_msgSend(iVar5,pauVar2);
  dword_F0132060 = dword_F0132060 + 1;
  _sprintf((undefined *)((int)register0x00000038 + -0x28),aKmdeviceD);
  _objc_msgSend(_kmId,paSetname,(undefined *)((int)register0x00000038 + -0x28));
  _objc_msgSend(_kmId,paSetdevicekind,aKmdevice_0);
  _objc_msgSend(_kmId,paSetlocation,0);
  return CONCAT44(param_2,param_1);
}

