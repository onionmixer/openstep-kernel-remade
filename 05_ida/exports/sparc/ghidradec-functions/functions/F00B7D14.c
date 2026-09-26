
/* WARNING: Removing unreachable block (ram,0xf00b7df4) */
/* WARNING: Removing unreachable block (ram,0xf00b7dbc) */
/* WARNING: Removing unreachable block (ram,0xf00b7da0) */
/* WARNING: Removing unreachable block (ram,0xf00b7d48) */
/* WARNING: Removing unreachable block (ram,0xf00b7d3c) */
/* WARNING: Removing unreachable block (ram,0xf00b7d58) */
/* WARNING: Removing unreachable block (ram,0xf00b7db0) */
/* WARNING: Removing unreachable block (ram,0xf00b7dcc) */
/* WARNING: Removing unreachable block (ram,0xf00b7e20) */
/* WARNING: Removing unreachable block (ram,0xf00b7d2c) */

undefined8 _esp_printstate(int param_1,undefined4 param_2)

{
  undefined uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint *puVar4;
  undefined4 unaff_l3;
  int iVar5;
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
  iVar5 = *(int *)(param_1 + 0x9c);
  puVar4 = *(uint **)(param_1 + 0xa0);
  _eprintf(param_1,&aS_5,param_2);
  uVar2 = (uint)*(byte *)(param_1 + 0x41);
  _esp_state_name(uVar2);
  uVar3 = (uint)*(byte *)(param_1 + 0x42);
  _esp_state_name(uVar3);
  _printf(aStateSLastStat,uVar2,uVar3);
  if ((*puVar4 & 0x200) == 0) {
    uVar1 = *(undefined *)(iVar5 + 0x1c);
  }
  else {
    uVar2 = *puVar4 & 0xfffffdff;
    *puVar4 = uVar2;
    uVar1 = *(undefined *)(iVar5 + 0x1c);
    *puVar4 = uVar2 | 0x200;
  }
  _printf(aLatchedStat0xB,*(undefined *)(param_1 + 0x43),_esp_stat_bits,
          *(undefined *)(param_1 + 0x44),_esp_int_bits,uVar1);
  uVar2 = (uint)*(byte *)(param_1 + 0x52);
  _scsi_mname(uVar2);
  uVar3 = (uint)*(byte *)(param_1 + 0x54);
  _scsi_mname(uVar3);
  _printf(aLastMsgOutSLas,uVar2,uVar3);
  _printf(aDmaCsr0xBAddrX,**(undefined4 **)(param_1 + 0xa0),_dmaga_bits,
          (*(undefined4 **)(param_1 + 0xa0))[1],*(undefined4 *)(param_1 + 0xa4),
          *(undefined4 *)(param_1 + 0xa8));
  if ((*(sword *)(param_1 + 0xb2) != -1) &&
     (*(int *)(*(sword *)(param_1 + 0xb2) * 4 + param_1 + 0xb8) != 0)) {
    _esp_dump_cmd();
  }
  return CONCAT44(param_2,param_1);
}

