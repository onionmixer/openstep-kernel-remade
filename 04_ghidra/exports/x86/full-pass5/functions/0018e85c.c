/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018e85c */

undefined4 _get_thread_fpstate(int param_1,undefined4 *param_2,uint *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (*param_3 < 0x1b) {
    uVar2 = 4;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x28);
    _fp_synch(param_1);
    puVar4 = (undefined4 *)(iVar1 + 0x7c);
    puVar5 = param_2;
    for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    puVar4 = (undefined4 *)(iVar1 + 0x98);
    puVar5 = param_2 + 7;
    for (iVar3 = 0x14; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    *param_3 = 0x1b;
    uVar2 = 0;
  }
  return uVar2;
}

