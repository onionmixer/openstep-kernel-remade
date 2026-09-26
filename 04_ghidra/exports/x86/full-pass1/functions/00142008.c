/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00142008 */

undefined4 _lf_lockctl(undefined4 param_1,short *param_2,int param_3)

{
  int iVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = FUN_001420e4(param_1);
  puVar2 = (undefined2 *)_kalloc(0x1c);
  puVar2[1] = *param_2;
  *(undefined4 *)(puVar2 + 2) = *(undefined4 *)(param_2 + 2);
  if (*(int *)(param_2 + 4) == 0) {
    iVar3 = -1;
  }
  else {
    iVar3 = *(int *)(param_2 + 4) + *(int *)(param_2 + 2) + -1;
  }
  *(int *)(puVar2 + 4) = iVar3;
  uVar4 = _get_posix_proc((int)*(short *)(*_active_u + 0x30));
  *(undefined4 *)(puVar2 + 6) = uVar4;
  *(int *)(puVar2 + 8) = iVar1;
  *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
  *(undefined4 *)(puVar2 + 10) = 0;
  *(undefined4 *)(puVar2 + 0xc) = 0;
  if (param_3 == 7) {
    uVar4 = FUN_00142544(puVar2,param_2);
    FUN_0014286c(puVar2);
  }
  else {
    if (*param_2 != 3) {
      if (param_3 == 8) {
        *puVar2 = 1;
      }
      else {
        *puVar2 = 2;
      }
      uVar4 = FUN_001421b8(puVar2);
      return uVar4;
    }
    uVar4 = FUN_00142434(puVar2);
    FUN_0014286c(puVar2);
  }
  FUN_00142154(iVar1);
  return uVar4;
}

