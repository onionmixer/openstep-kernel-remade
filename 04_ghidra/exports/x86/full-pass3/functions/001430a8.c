/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001430a8 */

int FUN_001430a8(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  DAT_001de3e8 = DAT_001de3e8 + 1;
  if (DAT_001de3e8 == 1) {
    if (_rootdev == -1) {
      iVar1 = 2;
    }
    else {
      uVar2 = _bdevvp((int)_rootdev);
      *param_2 = uVar2;
      if (_rootrw == 0) {
        *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) | 1;
      }
      iVar1 = FUN_00143184(param_2,&DAT_001de3ec,param_1);
      if (iVar1 == 0) {
        iVar1 = _vfs_add(0,param_1,*(uint *)(param_1 + 0xc) & 1);
        if (iVar1 == 0) {
          _vfs_unlock(param_1);
          _inittodr(*(undefined4 *)
                     (*(int *)(*(int *)(*(int *)(param_1 + 0x128) + 0xc) + 0x20) + 0x20));
          iVar1 = 0;
        }
        else {
          FUN_001437b0(param_1,0);
          _vn_rele(*param_2);
          *param_2 = 0;
        }
      }
      else {
        _vn_rele(*param_2);
        *param_2 = 0;
      }
    }
  }
  else {
    iVar1 = 0x10;
  }
  return iVar1;
}

