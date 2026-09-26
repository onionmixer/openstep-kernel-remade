
/* WARNING: Removing unreachable block (ram,0xf00efac4) */
/* WARNING: Removing unreachable block (ram,0xf00efa5c) */

undefined8 sub_F00EFA04(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
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
  bool bVar4;
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
  puVar3 = (undefined4 *)param_1[1];
  puVar1 = param_1;
  if ((param_1[4] & 2) == 0) {
    puVar1 = (undefined4 *)*param_1;
  }
  if ((puVar1[4] & 4) == 0) {
    if (puVar3 == (undefined4 *)0x0) {
      uVar2 = param_1[4];
    }
    else {
      puVar1 = puVar3;
      if ((puVar3[4] & 2) == 0) {
        puVar1 = (undefined4 *)*puVar3;
      }
      if ((puVar1[4] & 4) == 0) {
        sub_F00EFA04(puVar3);
        uVar2 = param_1[4];
      }
      else {
        uVar2 = param_1[4];
      }
    }
    puVar1 = param_1;
    if ((uVar2 & 2) == 0) {
      puVar1 = (undefined4 *)*param_1;
    }
    if ((puVar1[4] & 4) == 0) {
      bVar4 = false;
      puVar1 = param_1;
      if ((param_1[4] & 2) == 0) {
        puVar1 = (undefined4 *)*param_1;
        bVar4 = (param_1[4] & 2) == 0;
      }
      puVar3 = param_1;
      if (bVar4) {
        puVar3 = (undefined4 *)*param_1;
      }
      puVar1[4] = puVar3[4] | 4;
      _objc_msgSend(param_1,paInitialize);
    }
  }
  return CONCAT44(param_2,param_1);
}
