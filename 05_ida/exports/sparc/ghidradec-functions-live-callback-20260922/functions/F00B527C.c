
/* WARNING: Removing unreachable block (ram,0xf00b52bc) */

undefined8 _esp_handle_cmd_done(int param_1,undefined4 param_2)

{
  byte bVar1;
  undefined uVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
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
  bVar1 = *(byte *)(param_1 + 0x44);
  iVar3 = *(int *)(*(sword *)(param_1 + 0xb2) * 4 + param_1 + 0xb8);
  *(undefined *)(*(int *)(param_1 + 0x9c) + 0xc) = 0;
  if ((bVar1 & 0x10) == 0) {
    if ((bVar1 & 0x20) == 0) {
      _esp_printstate(param_1,aCmdTransmissio);
      uVar4 = 6;
      goto locret_F00B52EC;
    }
    uVar2 = *(undefined *)(param_1 + 0x41);
  }
  else {
    *(byte *)(iVar3 + 0x29) = *(byte *)(iVar3 + 0x29) | 4;
    uVar2 = *(undefined *)(param_1 + 0x41);
  }
  uVar4 = 2;
  *(undefined *)(param_1 + 0x42) = uVar2;
  *(undefined *)(param_1 + 0x41) = 0x1a;
locret_F00B52EC:
  return CONCAT44(param_2,uVar4);
}

