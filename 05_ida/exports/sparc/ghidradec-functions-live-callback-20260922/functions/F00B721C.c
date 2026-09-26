
/* WARNING: Removing unreachable block (ram,0xf00b727c) */
/* WARNING: Removing unreachable block (ram,0xf00b7268) */
/* WARNING: Removing unreachable block (ram,0xf00b7288) */
/* WARNING: Removing unreachable block (ram,0xf00b7244) */

undefined8 _esp_reset_recovery(int param_1,undefined4 param_2)

{
  char cVar1;
  sword sVar3;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar4;
  undefined4 uVar5;
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
  uVar4 = (uint)*(word *)(param_1 + 0xb2);
  if (*(sword *)(param_1 + 0xb2) == -1) {
    uVar4 = 0;
  }
  cVar1 = *(char *)(param_1 + 0x83);
  _bcopy(param_1 + 0xb8,(undefined *)((int)register0x00000038 + -0x108),0x100);
  if (1 < (byte)(*(char *)(param_1 + 0x41) - 0x1cU)) {
    _esp_internal_reset(param_1,3);
    _esplog(param_1,5,aUnexpectedScsi);
  }
  _esp_internal_reset(param_1,0x10);
  sVar3 = (sword)uVar4;
  *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
  *(undefined *)(param_1 + 0x41) = 0x1f;
  do {
    iVar2 = *(int *)((int)register0x00000038 + ((int)(uVar4 << 0x10) >> 0xe) + -0x108);
    if (iVar2 != 0) {
      if (*(char *)(iVar2 + 0x28) == '\0') {
        *(undefined *)(iVar2 + 0x28) = 4;
      }
      *(undefined4 *)(iVar2 + 0x24) = *(undefined4 *)(iVar2 + 0x40);
      if (*(code **)(iVar2 + 0x10) != (code *)0x0) {
        (**(code **)(iVar2 + 0x10))(iVar2);
      }
    }
    uVar4 = uVar4 + 1 & 0x3f;
  } while (uVar4 != (int)sVar3);
  uVar5 = 0xffffffff;
  *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
  *(undefined *)(param_1 + 0x41) = 0;
  if ((*(int *)(param_1 + 0x84) != 0) && (cVar1 == '\0')) {
    uVar5 = 5;
  }
  return CONCAT44(param_2,uVar5);
}

