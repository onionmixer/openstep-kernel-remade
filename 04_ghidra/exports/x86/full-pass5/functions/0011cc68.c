/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011cc68 */

int _chdirec(undefined4 param_1,int *param_2)

{
  int iVar1;
  int local_8;
  
  iVar1 = _lookupname(param_1,0,1,0,&local_8);
  if (iVar1 == 0) {
    if (*(int *)(local_8 + 0x28) == 2) {
      iVar1 = (**(code **)(*(int *)(local_8 + 0x1c) + 0x1c))
                        (local_8,0x40,*(undefined4 *)(_active_u + 0x1c));
      if (iVar1 == 0) {
        *param_2 = local_8;
        return 0;
      }
    }
    else {
      iVar1 = 0x14;
    }
    _vn_rele(local_8);
  }
  return iVar1;
}

