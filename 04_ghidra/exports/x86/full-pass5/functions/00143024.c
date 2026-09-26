/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00143024 */

int FUN_00143024(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_10;
  undefined2 local_a;
  undefined4 local_8;
  
  iVar1 = _copyin(param_3,&local_8,4);
  if (iVar1 == 0) {
    iVar1 = FUN_00143b64(local_8,&local_a);
    if (iVar1 == 0) {
      local_10 = _bdevvp((int)local_a);
      if ((*(byte *)((int)&DAT_001e2d08 + (uint)local_a._1_1_ * 0x18 + 1) & 4) != 0) {
        *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) | 1;
      }
      iVar1 = FUN_00143184(&local_10,param_2,param_1);
      if (iVar1 != 0) {
        _vn_rele(local_10);
      }
    }
  }
  return iVar1;
}

