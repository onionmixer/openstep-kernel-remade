/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018e634 */

undefined4 _set_thread_fpstate(int param_1,undefined4 *param_2,uint param_3)

{
  byte *pbVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  if (param_3 < 0x1b) {
    uVar3 = 4;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x28);
    _fp_terminate(param_1);
    puVar5 = param_2;
    puVar6 = (undefined4 *)(iVar2 + 0x7c);
    for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    puVar5 = param_2 + 7;
    puVar6 = (undefined4 *)(iVar2 + 0x98);
    for (iVar4 = 0x14; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    pbVar1 = (byte *)(*(int *)(param_1 + 0x28) + 0xf0);
    *pbVar1 = *pbVar1 | 2;
    uVar3 = 0;
  }
  return uVar3;
}

