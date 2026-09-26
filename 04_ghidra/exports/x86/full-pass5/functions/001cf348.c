/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cf348 */

void FUN_001cf348(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  int iStack_14;
  
  iStack_14 = param_2;
  uStack_18 = 0x1cf35a;
  puVar1 = (undefined4 *)FUN_001cf25c();
  uStack_18 = param_3;
  uStack_1c = 0x1cf362;
  piVar2 = (int *)FUN_001cf25c();
  uStack_1c = *puVar1;
  uVar3 = __nameForHeader();
  iVar4 = __nameForHeader(*piVar2);
  __objc_inform("Both %s and %s have implementations of class %s.",uVar3,iVar4,
                *(undefined4 *)(param_2 + 8));
  if (*(int *)(*piVar2 + 0xc) == 3) {
    iStack_14 = param_2;
    uStack_18 = param_1;
    uStack_1c = 0x1cf3a3;
    _NXHashInsert();
    piVar5 = &uStack_1c;
    uStack_1c = uVar3;
  }
  else {
    piVar5 = &iStack_14;
    iStack_14 = iVar4;
  }
  *(char **)((int)piVar5 + -4) = "Using implementation from %s.";
  *(undefined4 *)((int)piVar5 + -8) = 0x1cf3b3;
  __objc_inform();
  return;
}

