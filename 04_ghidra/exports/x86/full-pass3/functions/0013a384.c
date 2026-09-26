/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013a384 */

int _spec_fsync(vnop_fsync_args *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 in_stack_00000008;
  
  iVar1 = *(int *)(param_1 + 0x30);
  if ((((*(byte *)(iVar1 + 0x40) & 0x46) != 0) || (*(int *)(param_1 + 0x28) == 3)) &&
     (iVar2 = *(int *)(iVar1 + 0x38), iVar2 != 0)) {
    iVar3 = _kalloc(0x40);
    iVar4 = (**(code **)(*(int *)(*(int *)(iVar1 + 0x38) + 0x1c) + 0x14))
                      (*(int *)(iVar1 + 0x38),iVar3,in_stack_00000008);
    if (iVar4 == 0) {
      iVar4 = _kalloc(0x40);
      _vattr_null(iVar4);
      if ((*(int *)(iVar1 + 0x4c) < *(int *)(iVar3 + 0x20)) ||
         ((*(int *)(iVar3 + 0x20) == *(int *)(iVar1 + 0x4c) &&
          (*(int *)(iVar1 + 0x50) < *(int *)(iVar3 + 0x24))))) {
        uVar6 = *(undefined4 *)(iVar3 + 0x20);
        uVar5 = *(undefined4 *)(iVar3 + 0x24);
      }
      else {
        uVar6 = *(undefined4 *)(iVar1 + 0x4c);
        uVar5 = *(undefined4 *)(iVar1 + 0x50);
      }
      *(undefined4 *)(iVar4 + 0x20) = uVar6;
      *(undefined4 *)(iVar4 + 0x24) = uVar5;
      if ((*(int *)(iVar1 + 0x54) < *(int *)(iVar3 + 0x28)) ||
         ((*(int *)(iVar3 + 0x28) == *(int *)(iVar1 + 0x54) &&
          (*(int *)(iVar1 + 0x58) < *(int *)(iVar3 + 0x2c))))) {
        uVar6 = *(undefined4 *)(iVar3 + 0x28);
        uVar5 = *(undefined4 *)(iVar3 + 0x2c);
      }
      else {
        uVar6 = *(undefined4 *)(iVar1 + 0x54);
        uVar5 = *(undefined4 *)(iVar1 + 0x58);
      }
      *(undefined4 *)(iVar4 + 0x28) = uVar6;
      *(undefined4 *)(iVar4 + 0x2c) = uVar5;
      (**(code **)(*(int *)(iVar2 + 0x1c) + 0x18))(iVar2,iVar4,in_stack_00000008);
      _kfree(iVar4,0x40);
    }
    _kfree(iVar3,0x40);
    (**(code **)(*(int *)(iVar2 + 0x1c) + 0x48))(iVar2,in_stack_00000008);
  }
  return 0;
}

