/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011dc54 */

int _namesetattr(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int local_8;
  
  iVar1 = _lookupname(param_1,0,param_2,0,&local_8);
  if (iVar1 == 0) {
    if ((*(byte *)(*(int *)(local_8 + 0x24) + 0xc) & 1) == 0) {
      iVar1 = (**(code **)(*(int *)(local_8 + 0x1c) + 0x18))
                        (local_8,param_3,*(undefined4 *)(_active_u + 0x1c));
    }
    else {
      iVar1 = 0x1e;
    }
    _vn_rele(local_8);
  }
  return iVar1;
}

