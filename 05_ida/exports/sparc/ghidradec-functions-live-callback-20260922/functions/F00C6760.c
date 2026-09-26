
/* WARNING: Removing unreachable block (ram,0xf00c6860) */
/* WARNING: Removing unreachable block (ram,0xf00c6848) */
/* WARNING: Removing unreachable block (ram,0xf00c680c) */
/* WARNING: Removing unreachable block (ram,0xf00c67dc) */
/* WARNING: Removing unreachable block (ram,0xf00c67f8) */
/* WARNING: Removing unreachable block (ram,0xf00c6838) */
/* WARNING: Removing unreachable block (ram,0xf00c6850) */
/* WARNING: Removing unreachable block (ram,0xf00c6874) */
/* WARNING: Removing unreachable block (ram,0xf00c6780) */

undefined8 -[IODisk registerDevice](uint param_1,undefined4 param_2)

{
  undefined6 *puVar1;
  undefined4 *puVar2;
  undefined7 *puVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined *puVar5;
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
  
  puVar3 = paNxlock;
  puVar2 = paNew;
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
  puVar5 = (undefined *)0x0;
  if (*(char *)(param_1 + 0x116) != '\0') {
    *(undefined4 *)(param_1 + 0x108) = 0;
    _objc_msgSend(puVar3,puVar2);
    *(undefined7 **)(param_1 + 0x11c) = puVar3;
    *(undefined4 *)(param_1 + 0x13c) = 0;
    *(undefined4 *)(param_1 + 0x140) = 0;
    *(undefined4 *)(param_1 + 0x144) = 0;
    *(undefined4 *)(param_1 + 0x148) = 0;
    *(undefined4 *)(param_1 + 0x14c) = 0;
    *(undefined4 *)(param_1 + 0x150) = 0;
    *(undefined4 *)(param_1 + 0x154) = 0;
    *(undefined4 *)(param_1 + 0x158) = 0;
    *(undefined4 *)(param_1 + 0x15c) = 0;
    *(undefined4 *)(param_1 + 0x160) = 0;
    *(undefined4 *)(param_1 + 0x164) = 0;
    *(undefined4 *)(param_1 + 0x168) = 0;
    *(undefined4 *)(param_1 + 0x16c) = 0;
    *(undefined4 *)(param_1 + 0x170) = 0;
    *(uint *)((int)register0x00000038 + -0x10) = param_1;
    puVar5 = (undefined *)((int)register0x00000038 + -0x10);
    *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141ee8;
    _objc_msgSendSuper(puVar5,paRegisterdevice);
    puVar1 = paClass;
    if (puVar5 != (undefined *)0x0) {
      uVar4 = param_1;
      _objc_msgSend(param_1,paClass);
      _objc_msgSend();
      if ((uVar4 & 0xff) == 0) {
        uVar4 = param_1;
        _objc_msgSend(param_1,paName);
        _objc_msgSend(param_1,puVar1);
        _objc_msgSend();
        _IOLog(aWarningSClassS,uVar4,param_1);
      }
      else {
        _volCheckRegister(param_1,(int)*(sword *)(*(int *)(param_1 + 0x118) + 0x22),
                          (int)*(sword *)(*(int *)(param_1 + 0x118) + 0x20));
      }
    }
  }
  return CONCAT44(param_2,puVar5);
}

