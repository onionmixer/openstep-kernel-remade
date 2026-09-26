
/* WARNING: Removing unreachable block (ram,0xf00c5338) */
/* WARNING: Removing unreachable block (ram,0xf00c52f8) */
/* WARNING: Removing unreachable block (ram,0xf00c52d4) */
/* WARNING: Removing unreachable block (ram,0xf00c52f0) */
/* WARNING: Removing unreachable block (ram,0xf00c531c) */
/* WARNING: Removing unreachable block (ram,0xf00c5340) */
/* WARNING: Removing unreachable block (ram,0xf00c52b4) */

undefined8
-[IODevice getIntValues:forParameter:count:]
          (int param_1,undefined4 param_2,undefined4 *param_3,int param_4,undefined4 *param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
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
  iVar1 = param_4;
  _strcmp(param_4,&aIounit);
  if (iVar1 == 0) {
    uVar2 = *(undefined4 *)(param_1 + 4);
  }
  else {
    iVar1 = param_4;
    _strcmp(param_4,aIoblockmajor);
    if (iVar1 == 0) {
      _objc_msgSend(param_1,paClass);
      sub_F00C47A0();
      uVar3 = 0xfffffd39;
      if (param_1 != 0) goto locret_F00C536C;
      uVar2 = *(undefined4 *)(*(int *)((int)register0x00000038 + -0x14) + 8);
    }
    else {
      _strcmp(param_4,aIocharactermaj);
      if (param_4 != 0) {
        uVar3 = 0xfffffd39;
        goto locret_F00C536C;
      }
      _objc_msgSend(param_1,paClass);
      sub_F00C47A0();
      uVar3 = 0xfffffd39;
      if (param_1 != 0) goto locret_F00C536C;
      uVar2 = *(undefined4 *)(*(int *)((int)register0x00000038 + -0x18) + 0xc);
    }
  }
  uVar3 = 0;
  *param_3 = uVar2;
  *param_5 = 1;
locret_F00C536C:
  return CONCAT44(param_2,uVar3);
}

