
/* WARNING: Removing unreachable block (ram,0xf00d4418) */
/* WARNING: Removing unreachable block (ram,0xf00d43c4) */
/* WARNING: Removing unreachable block (ram,0xf00d4394) */
/* WARNING: Removing unreachable block (ram,0xf00d43f4) */
/* WARNING: Removing unreachable block (ram,0xf00d4428) */
/* WARNING: Removing unreachable block (ram,0xf00d4358) */

undefined8 -[EventDriver attachEventSource:](int param_1,undefined4 param_2,uint param_3)

{
  undefined6 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined *puVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar5;
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
  uVar5 = param_3;
  _objc_getClass();
  puVar1 = paProbe_0;
  if (uVar5 == 0) {
    puVar4 = aSSNoSuchClass;
  }
  else {
    uVar2 = uVar5;
    _objc_msgSend(uVar5,paRespondsto,paProbe_0);
    if ((uVar2 & 0xff) == 0) {
      puVar4 = aSSDoesNotRespo;
    }
    else {
      _objc_msgSend(uVar5,puVar1);
      if (uVar5 == 0) {
        puVar4 = aSProbeOfSFaile;
      }
      else {
        iVar3 = param_1;
        _objc_msgSend(param_1,paRegisterevents,uVar5);
        if (iVar3 != 0) goto locret_F00D4430;
        puVar4 = aSBecomeownerOf;
      }
    }
  }
  uVar5 = 0;
  _objc_msgSend(param_1,paName);
  _IOLog(puVar4,param_1,param_3);
locret_F00D4430:
  return CONCAT44(param_2,uVar5);
}
