/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013a130 */

undefined4 FUN_0013a130(vnop_fsync_args *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = _get_posix_proc((int)*(short *)(*_active_u + 0x30));
  *(byte *)(iVar2 + 0x18) = *(byte *)(iVar2 + 0x18) | 1;
  iVar1 = *(int *)(param_1 + 0x30);
  _sunsave(iVar1);
  if (*(int *)(iVar1 + 0x38) != 0) {
    _spec_fsync(param_1);
    if (*(int *)(iVar1 + 0x38) != 0) {
      _vn_rele(*(int *)(iVar1 + 0x38));
      *(undefined4 *)(iVar1 + 0x38) = 0;
      if (*(int *)(iVar1 + 0x3c) != 0) {
        _vn_rele(*(int *)(iVar1 + 0x3c));
      }
    }
  }
  *(byte *)(iVar2 + 0x18) = *(byte *)(iVar2 + 0x18) & 0xfe;
  _kfree(iVar1,0x68);
  return 0;
}

