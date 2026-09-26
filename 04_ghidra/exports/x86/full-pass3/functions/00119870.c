/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00119870 */

void _vfs_remove(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  piVar1 = _rootvfs;
  if (_rootvfs == param_1) {
                    /* WARNING: Subroutine does not return */
    _panic(s_vfs_remove__unmounting_root_001db4ed);
  }
  do {
    piVar4 = piVar1;
    if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_vfs_remove__vfs_not_found_001db52f);
    }
    piVar1 = (int *)*piVar4;
  } while (piVar1 != param_1);
  *piVar4 = *piVar1;
  iVar2 = piVar1[2];
  if (*(int *)(iVar2 + 0xc) == 0) {
    piVar1 = (int *)(iVar2 + 0x10);
    iVar3 = *(int *)(iVar2 + 0x10);
    while (iVar3 != 0) {
      piVar4 = (int *)*piVar1;
      if (piVar4 == param_1) goto LAB_001198da;
      piVar1 = piVar4 + 0x48;
      iVar3 = piVar4[0x48];
    }
    if ((int *)*piVar1 != param_1) {
                    /* WARNING: Subroutine does not return */
      _panic(s_vfs_remove__can_t_find_vfs_in_en_001db509);
    }
LAB_001198da:
    *piVar1 = param_1[0x48];
    _microtime(iVar2 + 0x14);
  }
  else {
    *(undefined4 *)(iVar2 + 0xc) = 0;
  }
  _vfs_unlock(param_1);
  return;
}

