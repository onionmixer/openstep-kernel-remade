/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001312ec */

int FUN_001312ec(undefined4 *param_1,int param_2,int param_3,uint param_4,short *param_5)

{
  int iVar1;
  int iVar2;
  undefined1 local_44 [24];
  undefined4 local_2c;
  
  iVar2 = 0;
  if (param_1[10] != 1) {
    return 0x15;
  }
  iVar1 = param_1[0xc];
  if ((param_3 == 1) || ((param_3 == 0 && (*(int *)(iVar1 + 0x70) == 0)))) {
    *param_5 = *param_5 + 1;
    if (*(int *)(iVar1 + 0x70) != 0) {
      _crfree(*(int *)(iVar1 + 0x70));
    }
    *(short **)(iVar1 + 0x70) = param_5;
    if (*(int *)*param_1 != 0) {
      _vnode_uncache(param_1);
    }
  }
  if (((param_4 & 2) != 0) && (param_3 == 1)) {
    _rlock(iVar1);
    iVar2 = FUN_00131a58(param_1,local_44,param_5);
    if (iVar2 != 0) goto LAB_001313a0;
    *(undefined4 *)(param_2 + 8) = local_2c;
  }
  if (iVar2 == 0) {
    iVar2 = FUN_001313c0(param_1,param_2,param_3,param_4,param_5);
  }
LAB_001313a0:
  if (((param_4 & 2) != 0) && (param_3 == 1)) {
    _runlock(iVar1);
  }
  return iVar2;
}

