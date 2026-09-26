/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00145f04 */

undefined4 _ipc_entry_get(int param_1,uint *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  undefined4 uVar5;
  
  iVar1 = *(int *)(param_1 + 0x14);
  iVar2 = *(int *)(iVar1 + 8);
  if (iVar2 == 0) {
    uVar5 = 3;
  }
  else {
    puVar4 = (uint *)(iVar2 * 0x10 + iVar1);
    *(uint *)(iVar1 + 8) = puVar4[2];
    uVar3 = *puVar4;
    *puVar4 = uVar3 + 0x1000000;
    puVar4[2] = 0;
    *param_2 = iVar2 << 8 | uVar3 + 0x1000000 >> 0x18;
    *param_3 = puVar4;
    uVar5 = 0;
  }
  return uVar5;
}

