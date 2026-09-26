
/* WARNING: Removing unreachable block (ram,0xf008e9d4) */
/* WARNING: Removing unreachable block (ram,0xf008e9b0) */
/* WARNING: Removing unreachable block (ram,0xf008e994) */
/* WARNING: Removing unreachable block (ram,0xf008e9c4) */
/* WARNING: Removing unreachable block (ram,0xf008e974) */
/* WARNING: Removing unreachable block (ram,0xf008e958) */

undefined8 -[KernDeviceInterrupt detach](int param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar3;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 8),paAcquire);
  iVar3 = *(int *)(param_1 + 4);
  if (iVar3 == 0) {
    _objc_msgSend(*(undefined4 *)(param_1 + 8),paRelease);
    param_1 = 0;
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0;
    uVar2 = paRelease;
    cVar1 = *(char *)(param_1 + 0x18);
    *(undefined *)(param_1 + 0x18) = 0;
    _objc_msgSend(*(undefined4 *)(param_1 + 8),uVar2);
    if (cVar1 == '\0') {
      _objc_msgSend(iVar3,paSuspend);
    }
    _objc_msgSend(iVar3,paDetachdevicein,param_1);
    _objc_msgSend(iVar3,paResume);
  }
  return CONCAT44(param_2,param_1);
}
