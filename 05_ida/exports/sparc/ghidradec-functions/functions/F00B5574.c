
/* WARNING: Removing unreachable block (ram,0xf00b55b4) */
/* WARNING: Removing unreachable block (ram,0xf00b55cc) */
/* WARNING: Removing unreachable block (ram,0xf00b55f8) */

undefined8 _esp_handle_clearing(int param_1,undefined4 param_2)

{
  undefined2 uVar1;
  undefined4 unaff_l0;
  uint uVar2;
  undefined4 unaff_l1;
  int iVar3;
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
  iVar3 = *(int *)(*(sword *)(param_1 + 0xb2) * 4 + param_1 + 0xb8);
  uVar2 = (uint)*(byte *)(param_1 + 0x54);
  if (*(char *)(param_1 + 0x44) == ' ') {
    _esp_chip_disconnect(param_1);
    uVar4 = 3;
    if (uVar2 == 4) {
      *(byte *)(iVar3 + 0x2a) = *(byte *)(iVar3 + 0x2a) | 1;
      *(word *)(iVar3 + 0x5c) = *(word *)(iVar3 + 0x5c) | 0x10;
      uVar4 = 5;
      *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0x90) + 1;
      *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + 1;
      *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
      *(undefined *)(param_1 + 0x41) = 0;
      *(undefined2 *)(param_1 + 0xb0) = *(undefined2 *)(param_1 + 0xb2);
      *(undefined2 *)(param_1 + 0xb2) = 0xffff;
    }
    *(undefined *)(param_1 + 0x52) = 0xff;
    *(undefined *)(param_1 + 0x53) = 0;
  }
  else if ((uVar2 - 10 & 0xff) < 2) {
    *(undefined *)(param_1 + 0x52) = 0xff;
    *(undefined *)(param_1 + 0x53) = 0;
    uVar4 = 3;
  }
  else {
    uVar1 = *(undefined2 *)(iVar3 + 8);
    _scsi_mname(uVar2);
    _esplog(param_1,4,aTargetDDidnTDi,uVar1,uVar2);
    *(undefined *)(iVar3 + 0x28) = 3;
    uVar4 = 6;
  }
  return CONCAT44(param_2,uVar4);
}
