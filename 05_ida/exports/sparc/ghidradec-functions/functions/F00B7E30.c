
/* WARNING: Removing unreachable block (ram,0xf00b7ef0) */
/* WARNING: Removing unreachable block (ram,0xf00b7ebc) */
/* WARNING: Removing unreachable block (ram,0xf00b7e78) */
/* WARNING: Removing unreachable block (ram,0xf00b7e50) */
/* WARNING: Removing unreachable block (ram,0xf00b7eac) */
/* WARNING: Removing unreachable block (ram,0xf00b7edc) */
/* WARNING: Removing unreachable block (ram,0xf00b7ef8) */
/* WARNING: Removing unreachable block (ram,0xf00b7e44) */

undefined8 _esp_dump_cmd(int param_1,undefined4 param_2)

{
  byte bVar1;
  undefined uVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  undefined *puVar4;
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
  puVar4 = *(undefined **)(param_1 + 0x20);
  _printf(aCmdDumpForTarg,*(undefined2 *)(param_1 + 8),*(undefined *)(param_1 + 10));
  _printf(&aCdb);
  iVar3 = 0;
  if (*(char *)(param_1 + 99) == '\0') {
    bVar1 = *(byte *)(param_1 + 0x29);
  }
  else {
    do {
      iVar3 = iVar3 + 1;
      _printf(&a0xX_0,*puVar4);
      puVar4 = puVar4 + 1;
    } while (iVar3 < (int)(uint)*(byte *)(param_1 + 99));
    bVar1 = *(byte *)(param_1 + 0x29);
  }
  if ((bVar1 & 0x10) == 0) {
    _printf(&DAT_f011edd0);
    uVar2 = *(undefined *)(param_1 + 0x29);
  }
  else {
    _printf(aStatus0xX,(int)**(char **)(param_1 + 0x1c));
    uVar2 = *(undefined *)(param_1 + 0x29);
  }
  _printf(aPktState0xBPkt,uVar2,_state_bits,*(undefined4 *)(param_1 + 0x14),
          *(undefined *)(param_1 + 0x2a));
  _printf(aCmdFlags0xXCmd,*(undefined2 *)(param_1 + 0x5c),*(undefined4 *)(param_1 + 0x58));
  _esp_dump_datasegs(param_1);
  return CONCAT44(param_2,param_1);
}
