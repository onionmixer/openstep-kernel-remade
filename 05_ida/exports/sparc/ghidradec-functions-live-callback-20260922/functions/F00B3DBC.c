
/* WARNING: Removing unreachable block (ram,0xf00b3eac) */
/* WARNING: Removing unreachable block (ram,0xf00b3ea4) */
/* WARNING: Removing unreachable block (ram,0xf00b3e60) */
/* WARNING: Removing unreachable block (ram,0xf00b3e98) */
/* WARNING: Removing unreachable block (ram,0xf00b3e44) */
/* WARNING: Removing unreachable block (ram,0xf00b3e1c) */

undefined8 _esp_start(int param_1,undefined4 param_2)

{
  byte bVar1;
  sword sVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined4 *puVar4;
  undefined4 unaff_l1;
  int iVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar6;
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
  sVar2 = *(sword *)(param_1 + 8);
  bVar1 = *(byte *)(param_1 + 10);
  puVar4 = *(undefined4 **)(param_1 + 4);
  if ((*(word *)(param_1 + 0x5c) & 1) != 0) {
    if ((*(uint *)puVar4[0x28] >> 0x1c < 10) ||
       (uVar3 = 0x40000000, *(uint *)puVar4[0x28] >> 0x1c != 10)) {
      uVar3 = 0x1000000;
    }
    if (uVar3 <= *(uint *)(param_1 + 0x40)) {
      uVar6 = 0xffffffff;
      goto locret_F00B3EB8;
    }
  }
  uVar6 = *puVar4;
  _splr(uVar6);
  iVar5 = (int)(sword)((word)bVar1 | sVar2 << 3);
  if (puVar4[iVar5 + 0x2e] == 0) {
    puVar4[iVar5 + 0x2e] = param_1;
    puVar4[0x21] = puVar4[0x21] + 1;
    _esp_init_cmd(param_1);
    if ((*(uint *)(param_1 + 0x14) & 1) == 0) {
      if ((puVar4[0x20] == 0) && (*(char *)((int)puVar4 + 0x41) == '\0')) {
        _esp_ustart(puVar4,iVar5);
      }
    }
    else {
      _esp_runpoll(puVar4,iVar5);
    }
    _splx(uVar6);
    uVar6 = 1;
  }
  else {
    uVar6 = 0;
    _splx();
  }
locret_F00B3EB8:
  return CONCAT44(param_2,uVar6);
}

