
/* WARNING: Removing unreachable block (ram,0xf0058110) */
/* WARNING: Removing unreachable block (ram,0xf0058068) */

undefined8 _ipc_marequest_rename(uint param_1,uint param_2,uint param_3)

{
  int *piVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 unaff_l0;
  int *piVar4;
  undefined4 unaff_l1;
  uint *puVar5;
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
  piVar4 = (int *)(_ipc_marequest_table +
                  ((param_1 >> 4) + (param_2 >> 8) + (param_2 & 0xff) & _ipc_marequest_mask) * 8);
  do {
    do {
    } while (*piVar4 != 0);
    piVar1 = piVar4;
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  puVar5 = (uint *)piVar4[1];
  puVar3 = (uint *)(piVar4 + 1);
  if (puVar5 != (uint *)0x0) {
    uVar2 = *puVar5;
    while ((uVar2 != param_1 || (puVar5[1] != param_2))) {
      puVar3 = puVar5 + 3;
      puVar5 = (uint *)puVar5[3];
      if (puVar5 == (uint *)0x0) break;
      uVar2 = *puVar5;
    }
  }
  *puVar3 = puVar5[3];
  *piVar4 = 0;
  puVar5[1] = param_3;
  piVar4 = (int *)(_ipc_marequest_table +
                  ((param_1 >> 4) + (param_3 >> 8) + (param_3 & 0xff) & _ipc_marequest_mask) * 8);
  do {
    do {
    } while (*piVar4 != 0);
    piVar1 = piVar4;
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  puVar5[3] = piVar4[1];
  piVar4[1] = (int)puVar5;
  *piVar4 = 0;
  return CONCAT44(param_2,param_1);
}
