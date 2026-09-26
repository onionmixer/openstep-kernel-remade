/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012e094 */

void FUN_0012e094(int param_1,int *param_2,uint *param_3,int param_4)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_48;
  undefined4 local_44 [16];
  
  pcVar1 = *(char **)(param_1 + 0x20);
  if ((pcVar1 == (char *)0x0) || (*pcVar1 == '\0')) {
    *param_2 = 0xd;
    return;
  }
  FUN_0012dbdc(param_1 + 0x24,local_44);
  local_44[0] = 2;
  iVar2 = FUN_0012dc2c(param_1,param_3);
  if (iVar2 == 0) {
    *param_2 = 0x46;
    return;
  }
  if (((*param_3 & 1) == 0) &&
     (((*param_3 & 2) == 0 ||
      (iVar3 = FUN_0012dc70(*(int *)(param_4 + 0x1c) + 0x10,param_3 + 6), iVar3 != 0)))) {
    iVar3 = (**(code **)(*(int *)(iVar2 + 0x1c) + 0x34))
                      (iVar2,pcVar1,local_44,&local_48,*(undefined4 *)(_active_u + 0x1c));
    if ((iVar3 == 0x11) && (iVar4 = _svckudp_dup(param_4), iVar4 != 0)) {
      iVar3 = (**(code **)(*(int *)(iVar2 + 0x1c) + 0x20))
                        (iVar2,pcVar1,&local_48,*(undefined4 *)(_active_u + 0x1c),0,0);
      if (iVar3 != 0) goto LAB_0012e1eb;
      iVar3 = (**(code **)(*(int *)(iVar2 + 0x1c) + 0x14))
                        (iVar2,local_44,*(undefined4 *)(_active_u + 0x1c));
    }
    if (iVar3 == 0) {
      _vattr_to_nattr(local_44,param_2 + 9);
      iVar3 = _makefh(param_2 + 1,local_48,param_3);
      _vn_rele(local_48);
      if (iVar3 == 0) {
        _svckudp_dupsave(param_4);
      }
    }
  }
  else {
    iVar3 = 0x1e;
  }
LAB_0012e1eb:
  *param_2 = iVar3;
  _vn_rele(iVar2);
  return;
}

