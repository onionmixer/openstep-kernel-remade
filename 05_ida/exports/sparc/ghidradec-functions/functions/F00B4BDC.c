
/* WARNING: Removing unreachable block (ram,0xf00b4c14) */
/* WARNING: Removing unreachable block (ram,0xf00b4c58) */
/* WARNING: Removing unreachable block (ram,0xf00b4c00) */

undefined8 _esp_dopoll(uint param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  undefined4 unaff_l0;
  int iVar3;
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
  bool bVar5;
  bool bVar6;
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
  iVar3 = 0;
  uVar2 = param_1;
  if (param_2 == 0) {
    uVar2 = 0xaba9400;
    param_2 = 180000000;
  }
  bVar6 = SBORROW4(0,param_2);
  bVar5 = -param_2 < 0;
  if (0 < param_2) {
    do {
      _esp_poll();
      if (uVar2 == 0) {
        _us_spin(100);
        bVar1 = *(byte *)(param_1 + 0x41);
      }
      else {
        bVar1 = *(byte *)(param_1 + 0x41);
      }
      uVar2 = (uint)bVar1;
      bVar6 = SBORROW4(iVar3,param_2);
      bVar5 = iVar3 - param_2 < 0;
      if (uVar2 == 0) break;
      iVar3 = iVar3 + 100;
      bVar6 = SBORROW4(iVar3,param_2);
      bVar5 = iVar3 - param_2 < 0;
    } while (iVar3 < param_2);
  }
  if (bVar5 == bVar6) {
    if (*(char *)(param_1 + 0x41) == '\0') {
      uVar4 = 0;
    }
    else {
      _esp_printstate(param_1,aPolledCommandT);
      uVar4 = 0xffffffff;
    }
  }
  else {
    uVar4 = 0;
  }
  return CONCAT44(param_2,uVar4);
}
