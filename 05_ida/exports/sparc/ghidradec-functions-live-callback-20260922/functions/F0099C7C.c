
/* WARNING: Removing unreachable block (ram,0xf0099d94) */
/* WARNING: Removing unreachable block (ram,0xf0099d48) */
/* WARNING: Removing unreachable block (ram,0xf0099d1c) */
/* WARNING: Removing unreachable block (ram,0xf0099d08) */
/* WARNING: Removing unreachable block (ram,0xf0099cf4) */
/* WARNING: Removing unreachable block (ram,0xf0099cac) */
/* WARNING: Removing unreachable block (ram,0xf0099c98) */
/* WARNING: Removing unreachable block (ram,0xf0099cc4) */
/* WARNING: Removing unreachable block (ram,0xf0099ce0) */
/* WARNING: Removing unreachable block (ram,0xf0099d64) */
/* WARNING: Removing unreachable block (ram,0xf0099d34) */
/* WARNING: Removing unreachable block (ram,0xf0099da4) */
/* WARNING: Removing unreachable block (ram,0xf0099c90) */

undefined8 _mini_mon(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined *puVar4;
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
  bool bVar5;
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
  puVar4 = (undefined *)((int)register0x00000038 + -0x58);
  puVar1 = puVar4;
  _memcpy(puVar4,aRestartOrHaltT,0x4c);
  _splusclock();
  iVar2 = param_1;
  _strcmp(param_1,&aRestart);
  iVar3 = param_1;
  _strcmp(param_1,&aPanic_0);
  bVar5 = iVar3 == 0;
  if (iVar2 == 0) {
    _DoAlert(param_2,puVar4);
  }
  else {
    _DoAlert(param_2,unk_F0117118);
  }
  if (bVar5) {
    _kmdumplog();
  }
  iVar3 = param_1;
  if (iVar2 == 0) {
    do {
      param_1 = iVar3;
      _kmtrygetc();
      iVar3 = param_1;
      if (param_1 == 0x72) {
        iVar3 = 0;
        _reboot_mach();
      }
      if (param_1 == 0x68) {
        iVar3 = 8;
        _reboot_mach();
      }
    } while (param_1 == -1);
  }
  else {
    do {
      _miniMonLoop(param_1,bVar5,param_3);
    } while (bVar5);
  }
  if (_nmi_stay == 0) {
    _DoRestore();
  }
  _nmi_stay = 0;
  _splx(puVar1);
  return CONCAT44(param_2,param_1);
}

