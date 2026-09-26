
/* WARNING: Removing unreachable block (ram,0xf00d0d6c) */
/* WARNING: Removing unreachable block (ram,0xf00d0d40) */
/* WARNING: Removing unreachable block (ram,0xf00d0db4) */
/* WARNING: Removing unreachable block (ram,0xf00d0d78) */
/* WARNING: Removing unreachable block (ram,0xf00d0d28) */

undefined8
-[IODisplay getIntValues:forParameter:count:]
          (undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,int *param_5)

{
  int iVar1;
  undefined *puVar2;
  undefined4 unaff_l0;
  int iVar3;
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
  iVar3 = *param_5;
  iVar1 = param_4;
  _strcmp(param_4,aIogetdisplaypo);
  if ((iVar1 == 0) || (iVar1 = param_4, _strcmp(param_4,aIoDisplayGetpo), iVar1 == 0)) {
    if (iVar3 == 0) {
      puVar2 = (undefined *)0xfffffd3e;
    }
    else {
      _objc_msgSend(param_1,paDeviceport_0);
      _IOConvertPort();
      *param_3 = param_1;
      *param_5 = 1;
      puVar2 = (undefined *)0x0;
    }
  }
  else {
    *(undefined4 *)((int)register0x00000038 + -0x10) = param_1;
    puVar2 = (undefined *)((int)register0x00000038 + -0x10);
    *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf01421b8;
    _objc_msgSendSuper(puVar2,paGetintvaluesFo_0,param_3,param_4,param_5);
  }
  return CONCAT44(param_2,puVar2);
}

