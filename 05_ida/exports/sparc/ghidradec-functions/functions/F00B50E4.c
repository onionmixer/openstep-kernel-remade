
/* WARNING: Removing unreachable block (ram,0xf00b51b8) */
/* WARNING: Removing unreachable block (ram,0xf00b50fc) */

undefined8 _esp_handle_unknown(int param_1,undefined4 param_2)

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
  if ((*(byte *)(param_1 + 0x44) & 0x20) != 0) {
    _esp_chip_disconnect(param_1);
    uVar2 = 3;
    *(undefined *)(*(int *)(*(sword *)(param_1 + 0xb2) * 4 + param_1 + 0xb8) + 0x28) = 0x14;
    goto locret_F00B51D0;
  }
  switch(*(byte *)(param_1 + 0x43) & 7) {
  case :
  case :
    uVar1 = 9;
    break;
  case :
    uVar1 = 1;
    break;
  case :
    uVar2 = 0xffffffff;
    *(undefined *)(*(int *)(param_1 + 0x9c) + 0xc) = 1;
    *(undefined *)(*(int *)(param_1 + 0x9c) + 0xc) = 0x11;
    *(undefined *)(param_1 + 0x41) = 0xb;
    goto locret_F00B51D0;
  :
    _esp_printstate(param_1,aUnknownBusPhas);
    uVar2 = 8;
    goto locret_F00B51D0;
  case :
    uVar1 = 3;
    break;
  case :
    uVar1 = 5;
  }
  *(undefined *)(param_1 + 0x41) = uVar1;
  uVar2 = 2;
locret_F00B51D0:
  return CONCAT44(param_2,uVar2);
}
