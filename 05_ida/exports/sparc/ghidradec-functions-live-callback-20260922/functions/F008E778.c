
/* WARNING: Removing unreachable block (ram,0xf008e840) */
/* WARNING: Removing unreachable block (ram,0xf008e824) */
/* WARNING: Removing unreachable block (ram,0xf008e7f8) */
/* WARNING: Removing unreachable block (ram,0xf008e7cc) */
/* WARNING: Removing unreachable block (ram,0xf008e7bc) */
/* WARNING: Removing unreachable block (ram,0xf008e7e0) */
/* WARNING: Removing unreachable block (ram,0xf008e814) */
/* WARNING: Removing unreachable block (ram,0xf008e834) */
/* WARNING: Removing unreachable block (ram,0xf008e854) */
/* WARNING: Removing unreachable block (ram,0xf008e788) */

undefined8
-[KernDeviceInterrupt attachToBusInterrupt:withArgument:]
          (int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined4 uVar3;
  int iVar4;
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
  
  puVar1 = paAcquire;
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
  puVar2 = paRelease;
  if (*(int *)(param_1 + 4) == 0) {
    *(int *)(param_1 + 4) = param_3;
    _objc_msgSend(*(undefined4 *)(param_1 + 8),puVar2);
    _objc_msgSend(param_3,paSuspend);
    iVar4 = param_3;
    _objc_msgSend(param_3,paAttachdevicein_0,param_1);
    if (iVar4 != 0) {
      _objc_msgSend(*(undefined4 *)(param_1 + 8),puVar1);
      *(code **)(param_1 + 0xc) = _IOSendInterrupt;
      *(undefined4 *)(param_1 + 0x10) = param_4;
      _objc_msgSend(*(undefined4 *)(param_1 + 8),puVar2);
      _objc_msgSend(param_3,paResume);
      goto locret_F008E85C;
    }
    _objc_msgSend(param_3,paResume);
    _objc_msgSend(*(undefined4 *)(param_1 + 8),puVar1);
    *(undefined4 *)(param_1 + 4) = 0;
    uVar3 = *(undefined4 *)(param_1 + 8);
  }
  else {
    uVar3 = *(undefined4 *)(param_1 + 8);
  }
  param_1 = 0;
  _objc_msgSend(uVar3,puVar2);
locret_F008E85C:
  return CONCAT44(param_2,param_1);
}

