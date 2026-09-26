/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001193d4 */

int _unmount(char *param_1,int param_2)

{
  int iVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  int local_8;
  
  uVar2 = _lookupname(**(undefined4 **)(DAT_001e875c + 0x24),0,1,0,&local_8);
  iVar3 = DAT_001e875c;
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
  if (*(char *)(DAT_001e875c + 0x68) == '\0') {
    if ((*(byte *)(local_8 + 4) & 1) == 0) {
      *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
      iVar3 = _vn_rele(local_8);
    }
    else {
      iVar3 = *(int *)(local_8 + 0x24);
      _vn_rele(local_8);
      if ((*(short *)(*(int *)(_active_u + 0x1c) + 2) != *(short *)(iVar3 + 0x124)) &&
         (iVar4 = _suser(), iVar1 = DAT_001e875c, iVar4 == 0)) {
        *(undefined1 *)(DAT_001e875c + 0x68) = 1;
        return iVar1;
      }
      _mfs_cache_clear();
      _vm_object_cache_clear();
      uVar2 = _dounmount(iVar3);
      iVar3 = DAT_001e875c;
      *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
    }
  }
  return iVar3;
}

