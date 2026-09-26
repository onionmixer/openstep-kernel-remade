
/* WARNING: Removing unreachable block (ram,0xf00cc884) */
/* WARNING: Removing unreachable block (ram,0xf00cc860) */
/* WARNING: Removing unreachable block (ram,0xf00cc824) */
/* WARNING: Removing unreachable block (ram,0xf00cc7fc) */
/* WARNING: Removing unreachable block (ram,0xf00cc7d0) */
/* WARNING: Removing unreachable block (ram,0xf00cc794) */
/* WARNING: Removing unreachable block (ram,0xf00cc7e4) */
/* WARNING: Removing unreachable block (ram,0xf00cc810) */
/* WARNING: Removing unreachable block (ram,0xf00cc844) */
/* WARNING: Removing unreachable block (ram,0xf00cc870) */
/* WARNING: Removing unreachable block (ram,0xf00cc894) */
/* WARNING: Removing unreachable block (ram,0xf00cc778) */

undefined8
-[IOTokenRing initFromDeviceDescription:](int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  undefined (*pauVar5) [12];
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
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  puVar2 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf01420f0;
  _objc_msgSendSuper(puVar2,paInitfromdevice,param_3);
  if (puVar2 == (undefined *)0x0) {
    param_1 = 0;
  }
  else {
    iVar3 = param_1;
    _objc_msgSend(param_1,paStartiothread);
    iVar4 = dword_F012ECE4;
    if (iVar3 == 0) {
      dword_F012ECE4 = dword_F012ECE4 + 1;
      _sprintf((undefined *)((int)register0x00000038 + -0x18),&aSD,&aTr,iVar4);
      _objc_msgSend(param_1,paSetname,(undefined *)((int)register0x00000038 + -0x18));
      _objc_msgSend(param_1,paSetdevicekind,aTokenring);
      _objc_msgSend(param_1,paSetunit,iVar4);
      iVar4 = param_1;
      _objc_msgSend(param_1,paGetinstancetab,param_3);
      if (iVar4 == 0) {
        pauVar5 = paDrivercmdtr;
        _objc_msgSend(paDrivercmdtr,paAlloc);
        uVar1 = paInitport;
        iVar4 = param_1;
        _objc_msgSend(param_1,paInterruptport_0);
        _objc_msgSend(pauVar5,uVar1,iVar4);
        *(undefined (**) [12])(param_1 + 0x154) = pauVar5;
        _objc_msgSend(param_1,paSet8025framesi);
        goto locret_F00CC8A0;
      }
    }
    _objc_msgSend(param_1,paFree);
    param_1 = 0;
  }
locret_F00CC8A0:
  return CONCAT44(param_2,param_1);
}
