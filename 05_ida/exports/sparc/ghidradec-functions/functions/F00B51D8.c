
undefined8 _esp_handle_cmd_start(int param_1)

{
  byte bVar1;
  undefined *puVar2;
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
  undefined *puVar4;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  int iVar5;
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
  iVar5 = *(int *)(*(sword *)(param_1 + 0xb2) * 4 + param_1 + 0xb8);
  puVar4 = *(undefined **)(param_1 + 0x9c);
  if ((uint)*(byte *)(iVar5 + 99) < (uint)(*(int *)(iVar5 + 0x2c) - *(int *)(iVar5 + 0x20))) {
    *(undefined *)(iVar5 + 0x28) = 8;
    uVar3 = 6;
  }
  else {
    puVar4[0xc] = 1;
    bVar1 = *(byte *)(param_1 + 0x33);
    *puVar4 = 1;
    if ((bVar1 & 0x40) == 0) {
      puVar4[4] = 0;
    }
    else {
      puVar4[4] = 0;
      puVar4[0x38] = 0;
    }
    puVar2 = *(undefined **)(iVar5 + 0x2c);
    *(undefined **)(iVar5 + 0x2c) = puVar2 + 1;
    puVar4[8] = *puVar2;
    puVar4[0xc] = 0x10;
    uVar3 = 0xffffffff;
    *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
    *(undefined *)(param_1 + 0x41) = 2;
  }
  return CONCAT44(puVar4,uVar3);
}
