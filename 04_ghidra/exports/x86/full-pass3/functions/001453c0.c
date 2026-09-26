/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001453c0 */

undefined4 FUN_001453c0(int param_1,undefined4 param_2,undefined4 *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x30);
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(iVar1 + 0x40);
  }
  if (param_4 != (int *)0x0) {
    iVar2 = _bmap(iVar1,param_2,1,0,0);
    *param_4 = iVar2 << ((byte)*(undefined4 *)(*(int *)(iVar1 + 0x50) + 100) & 0x1f);
  }
  return 0;
}

