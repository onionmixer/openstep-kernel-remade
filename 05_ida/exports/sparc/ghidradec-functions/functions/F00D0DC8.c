
/* WARNING: Removing unreachable block (ram,0xf00d0e28) */
/* WARNING: Removing unreachable block (ram,0xf00d0df8) */
/* WARNING: Removing unreachable block (ram,0xf00d0de0) */
/* WARNING: Removing unreachable block (ram,0xf00d0e0c) */
/* WARNING: Removing unreachable block (ram,0xf00d0e60) */
/* WARNING: Removing unreachable block (ram,0xf00d0dd4) */

undefined8
-[IODisplay getCharValues:forParameter:count:]
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,uint *param_5)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
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
  iVar1 = param_1;
  _objc_msgSend(param_1,paDevicedescript_1);
  _objc_msgSend();
  if (iVar1 == 0) {
loc_F00D0E3C:
    *(int *)((int)register0x00000038 + -0x10) = param_1;
  }
  else {
    _objc_msgSend();
    if (iVar1 != 0) {
      iVar2 = iVar1;
      _strlen();
      if (iVar2 + 1U <= *param_5) {
        _strcpy(param_3,iVar1);
        *param_5 = iVar2 + 1U;
        puVar3 = (undefined *)0x0;
        goto locret_F00D0E6C;
      }
      goto loc_F00D0E3C;
    }
    *(int *)((int)register0x00000038 + -0x10) = param_1;
  }
  puVar3 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf01421b8;
  _objc_msgSendSuper(puVar3,paGetcharvaluesF_0,param_3,param_4,param_5);
locret_F00D0E6C:
  return CONCAT44(param_2,puVar3);
}
