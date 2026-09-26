
/* WARNING: Removing unreachable block (ram,0xf00c4370) */
/* WARNING: Removing unreachable block (ram,0xf00c4368) */
/* WARNING: Removing unreachable block (ram,0xf00c4378) */
/* WARNING: Removing unreachable block (ram,0xf00c4318) */

undefined8 _SPARCKernBusInterruptDispatch(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  int iVar1;
  undefined4 unaff_l1;
  int *piVar2;
  int iVar3;
  undefined4 unaff_l3;
  code *pcVar4;
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
  pcVar4 = *(code **)(param_1 + 0x28);
  _KernLockAcquire(*(undefined4 *)(param_1 + 0x1c));
  iVar1 = *(int *)(param_1 + 0x18);
  iVar3 = 0;
  piVar2 = *(int **)(*(int *)(param_1 + 0x14) + 4);
  do {
    if (iVar1 < 1) break;
    iVar1 = iVar1 + -1;
    iVar3 = *piVar2;
    piVar2 = piVar2 + 1;
    (*pcVar4)(iVar3,param_2);
  } while (iVar3 == 0);
  _KernLockAcquire(*(undefined4 *)(param_1 + 0x24));
  _KernLockRelease(*(undefined4 *)(param_1 + 0x24));
  _KernLockRelease(*(undefined4 *)(param_1 + 0x1c));
  return CONCAT44(param_2,iVar3);
}

