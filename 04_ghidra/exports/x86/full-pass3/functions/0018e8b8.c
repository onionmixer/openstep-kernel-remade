/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018e8b8 */

undefined4 _get_thread_exceptstate(int param_1,undefined4 *param_2,uint *param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  if (*param_3 < 2) {
    uVar1 = 4;
  }
  else {
    iVar3 = *(int *)(*(int *)(param_1 + 0x28) + 0x70);
    if (iVar3 == 0) {
      iVar3 = _kalloc(0xe0);
      *(int *)(*(int *)(param_1 + 0x28) + 0x70) = iVar3;
      puVar2 = (undefined4 *)(iVar3 + 0x84);
      puVar5 = &DAT_001d15e0;
      puVar6 = puVar2;
      for (iVar4 = 0x17; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      *(undefined4 *)(iVar3 + 0xc4) = 0x200;
      *(undefined2 *)(iVar3 + 0xc0) = 99;
      *(undefined2 *)(iVar3 + 0xcc) = 0x6b;
      *(undefined2 *)(iVar3 + 0x90) = 0x6b;
      *(undefined2 *)(iVar3 + 0x8c) = 0x6b;
      *(undefined2 *)(iVar3 + 0x88) = 0;
      *(undefined2 *)(iVar3 + 0x84) = 0;
    }
    else {
      puVar2 = (undefined4 *)(iVar3 + 0x84);
    }
    *param_2 = puVar2[0xc];
    param_2[1] = puVar2[0xd];
    *param_3 = 2;
    uVar1 = 0;
  }
  return uVar1;
}

