
/* WARNING: Removing unreachable block (ram,0xf00cb50c) */
/* WARNING: Removing unreachable block (ram,0xf00cb4e0) */
/* WARNING: Removing unreachable block (ram,0xf00cb48c) */
/* WARNING: Removing unreachable block (ram,0xf00cb464) */
/* WARNING: Removing unreachable block (ram,0xf00cb52c) */
/* WARNING: Removing unreachable block (ram,0xf00cb428) */
/* WARNING: Removing unreachable block (ram,0xf00cb448) */
/* WARNING: Removing unreachable block (ram,0xf00cb474) */
/* WARNING: Removing unreachable block (ram,0xf00cb4cc) */
/* WARNING: Removing unreachable block (ram,0xf00cb4f8) */
/* WARNING: Removing unreachable block (ram,0xf00cb51c) */
/* WARNING: Removing unreachable block (ram,0xf00cb40c) */

undefined8
-[IOEthernet initFromDeviceDescription:](int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined (*pauVar1) [10];
  undefined *puVar2;
  int iVar3;
  undefined (*pauVar4) [10];
  undefined7 *puVar5;
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
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf01420a0;
  _objc_msgSendSuper(puVar2,paInitfromdevice,param_3);
  if (puVar2 == (undefined *)0x0) {
    param_1 = 0;
  }
  else {
    iVar3 = param_1;
    _objc_msgSend(param_1,paStartiothread);
    if (iVar3 == 0) {
      pauVar4 = paDrivercmd;
      _objc_msgSend(paDrivercmd,paAlloc);
      pauVar1 = paInitport;
      iVar3 = param_1;
      _objc_msgSend(param_1,paInterruptport_0);
      _objc_msgSend(pauVar4,pauVar1,iVar3);
      *(undefined (**) [10])(param_1 + 300) = pauVar4;
      puVar5 = paNxlock;
      _objc_msgSend(paNxlock,paNew);
      *(undefined7 **)(param_1 + 0x138) = puVar5;
      *(int *)(param_1 + 0x148) = param_1 + 0x144;
      *(int *)(param_1 + 0x144) = param_1 + 0x144;
      iVar3 = dword_F01330C4;
      dword_F01330C4 = dword_F01330C4 + 1;
      _sprintf((undefined *)((int)register0x00000038 + -0x18),&aSD,&unk_F012ECB8,iVar3);
      _objc_msgSend(param_1,paSetname,(undefined *)((int)register0x00000038 + -0x18));
      _objc_msgSend(param_1,paSetdevicekind,aEthernet);
      _objc_msgSend(param_1,paSetunit,iVar3);
      _objc_msgSend(param_1,paRegisterdevice);
    }
    else {
      _objc_msgSend(param_1,paFree);
      param_1 = 0;
    }
  }
  return CONCAT44(param_2,param_1);
}

