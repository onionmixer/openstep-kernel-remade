
/* WARNING: Removing unreachable block (ram,0xf00c4be0) */
/* WARNING: Removing unreachable block (ram,0xf00c4b70) */
/* WARNING: Removing unreachable block (ram,0xf00c4b44) */
/* WARNING: Removing unreachable block (ram,0xf00c4b8c) */
/* WARNING: Removing unreachable block (ram,0xf00c4bf8) */
/* WARNING: Removing unreachable block (ram,0xf00c4b68) */

undefined8 -[IODevice registerDevice](int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
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
  if (*(char *)(param_1 + 0x58) == '\0') {
    _IOLog(aRegisteringS,param_1 + 8);
  }
  else {
    _IOLog(aRegisteringSAt,param_1 + 8,param_1 + 0x58);
  }
  piVar5 = (int *)0x10;
  _IOMalloc();
  uVar3 = paLock;
  uVar2 = dword_F013303C;
  *piVar5 = param_1;
  _objc_msgSend(uVar2,uVar3);
  iVar4 = dword_F0133030 + 1;
  piVar5[1] = dword_F0133030;
  dword_F0133030 = iVar4;
  if ((int **)dword_F0133034 == &dword_F0133034) {
    dword_F0133034 = piVar5;
    DAT_f0133038 = piVar5;
    piVar5[2] = (int)&dword_F0133034;
    piVar5[3] = (int)&dword_F0133034;
  }
  else {
    piVar5[3] = (int)DAT_f0133038;
    piVar5[2] = (int)&dword_F0133034;
    puVar1 = (undefined4 *)((int)DAT_f0133038 + 8);
    DAT_f0133038 = piVar5;
    *puVar1 = piVar5;
  }
  _objc_msgSend(dword_F013303C,paUnlock);
  _objc_msgSend(paIodevice_0,paConnecttoindir,param_1);
  return CONCAT44(param_2,param_1);
}
