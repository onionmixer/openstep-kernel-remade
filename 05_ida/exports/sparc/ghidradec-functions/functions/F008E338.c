
/* WARNING: Removing unreachable block (ram,0xf008e3a8) */
/* WARNING: Removing unreachable block (ram,0xf008e380) */
/* WARNING: Removing unreachable block (ram,0xf008e3b0) */
/* WARNING: Removing unreachable block (ram,0xf008e340) */

undefined8 _KernBusInterruptDispatch(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  int iVar2;
  uint uVar3;
  undefined4 unaff_l1;
  undefined4 *puVar4;
  code *pcVar5;
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
  pcVar5 = *(code **)(param_1 + 0x28);
  _KernLockAcquire(*(undefined4 *)(param_1 + 0x1c));
  puVar4 = *(undefined4 **)(*(int *)(param_1 + 0x14) + 4);
  for (iVar2 = *(int *)(param_1 + 0x18); 0 < iVar2; iVar2 = iVar2 + -1) {
    uVar1 = *puVar4;
    puVar4 = puVar4 + 1;
    (*pcVar5)(uVar1,param_2);
  }
  _KernLockAcquire(*(undefined4 *)(param_1 + 0x24));
  uVar3 = 0;
  if (0 < *(int *)(param_1 + 0x18)) {
    uVar3 = (uint)(*(int *)(param_1 + 0x20) == 0);
  }
  _KernLockRelease(*(undefined4 *)(param_1 + 0x24));
  _KernLockRelease(*(undefined4 *)(param_1 + 0x1c));
  return CONCAT44(param_2,uVar3);
}
