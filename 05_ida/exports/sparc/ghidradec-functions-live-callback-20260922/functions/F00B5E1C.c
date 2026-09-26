
/* WARNING: Removing unreachable block (ram,0xf00b5e7c) */

undefined8 _esp_handle_more_msgin(int param_1,undefined4 param_2)

{
  undefined uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
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
  if ((*(byte *)(param_1 + 0x44) & 0x10) == 0) {
    uVar1 = *(undefined *)(param_1 + 0x41);
  }
  else {
    if ((*(byte *)(param_1 + 0x43) & 7) == 7) {
      *(undefined *)(*(int *)(param_1 + 0x9c) + 0xc) = 0x10;
      uVar2 = 0xffffffff;
      *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
      uVar1 = 7;
      goto loc_F00B5E94;
    }
    if (*(char *)(param_1 + 0x5c) != '\0') {
      _esplog(param_1,4,aPrematureEndOf);
    }
    uVar1 = *(undefined *)(param_1 + 0x41);
  }
  uVar2 = 2;
  *(undefined *)(param_1 + 0x42) = uVar1;
  uVar1 = 0x1a;
loc_F00B5E94:
  *(undefined *)(param_1 + 0x41) = uVar1;
  return CONCAT44(param_2,uVar2);
}

