/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00143934 */

undefined4 FUN_00143934(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x128) + 0xc) + 0x20);
  if (*(int *)(iVar1 + 0x55c) != 0x11954) {
                    /* WARNING: Subroutine does not return */
    _panic(s_ufs_statfs_001de473);
  }
  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(iVar1 + 0x34);
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(iVar1 + 0x28);
  iVar2 = *(int *)(iVar1 + 0xc4) * *(int *)(iVar1 + 0x38) + *(int *)(iVar1 + 0xcc);
  *(int *)(param_2 + 0xc) = iVar2;
  *(int *)(param_2 + 0x10) =
       ((100 - *(int *)(iVar1 + 0x3c)) * *(int *)(iVar1 + 0x28)) / 100 -
       (*(int *)(iVar1 + 0x28) - iVar2);
  *(int *)(param_2 + 0x14) = *(int *)(iVar1 + 0x2c) * *(int *)(iVar1 + 0xb8);
  *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(iVar1 + 200);
  _bcopy((void *)(param_1 + 0x14),(void *)(param_2 + 0x1c),8);
  return 0;
}

