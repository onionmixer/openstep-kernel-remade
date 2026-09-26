/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012e6d4 */

void FUN_0012e6d4(int param_1,int *param_2,uint *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((((*(char **)(param_1 + 0x20) != (char *)0x0) && (**(char **)(param_1 + 0x20) != '\0')) &&
      (*(char **)(param_1 + 0x44) != (char *)0x0)) && (**(char **)(param_1 + 0x44) != '\0')) {
    iVar1 = FUN_0012dc2c(param_1,param_3);
    if (iVar1 == 0) {
      *param_2 = 0x46;
      return;
    }
    if (((*param_3 & 1) == 0) &&
       (((*param_3 & 2) == 0 ||
        (iVar2 = FUN_0012dc70(*(int *)(param_4 + 0x1c) + 0x10,param_3 + 6), iVar2 != 0)))) {
      iVar3 = FUN_0012dc2c(param_1 + 0x24,param_3);
      if (iVar3 == 0) {
        *param_2 = 0x46;
        _vn_rele(iVar1);
        return;
      }
      iVar2 = (**(code **)(*(int *)(iVar1 + 0x1c) + 0x30))
                        (iVar1,*(undefined4 *)(param_1 + 0x20),iVar3,*(undefined4 *)(param_1 + 0x44)
                         ,*(undefined4 *)(_active_u + 0x1c));
      _vn_rele(iVar3);
    }
    else {
      iVar2 = 0x1e;
    }
    _vn_rele(iVar1);
    *param_2 = iVar2;
    if (iVar2 == 0) {
      _svckudp_dupsave(param_4);
    }
    else {
      iVar1 = _svckudp_dup(param_4);
      if (iVar1 != 0) {
        *param_2 = 0;
      }
    }
    return;
  }
  *param_2 = 0xd;
  return;
}

