/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00146b54 */

undefined4 _ipc_hash_local_lookup(int param_1,uint param_2,uint *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (param_2 >> 6) % *(uint *)(param_1 + 0x18);
  while( true ) {
    iVar2 = *(int *)(*(int *)(param_1 + 0x14) + 0xc + uVar3 * 0x10);
    if (iVar2 == 0) {
      return 0;
    }
    iVar1 = iVar2 * 0x10 + *(int *)(param_1 + 0x14);
    if (*(uint *)(iVar1 + 4) == param_2) break;
    uVar3 = uVar3 + 1;
    if (uVar3 == *(uint *)(param_1 + 0x18)) {
      uVar3 = 0;
    }
  }
  *param_3 = (uint)*(byte *)(iVar1 + 3) | iVar2 << 8;
  *param_4 = iVar1;
  return 1;
}

