/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012d3e0 */

/* WARNING: Type propagation algorithm not settling */

void FUN_0012d3e0(int param_1,int *param_2,uint *param_3,int param_4)

{
  char *pcVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  undefined4 uVar7;
  int local_48 [2];
  ushort local_40;
  int local_2c;
  undefined2 local_c;
  
  pcVar1 = *(char **)(param_1 + 0x20);
  if ((pcVar1 == (char *)0x0) || (*pcVar1 == '\0')) {
    *param_2 = 0xd;
    return;
  }
  FUN_0012dbdc(param_1 + 0x24,local_48 + 1);
  uVar2 = local_40 & 0xf000;
  if (uVar2 == 0x2000) {
    local_48[1] = 4;
    if (local_2c == -1) {
      local_48[1] = 8;
    }
    else {
      local_c = (undefined2)local_2c;
    }
LAB_0012d461:
    local_2c = 0;
  }
  else {
    if (uVar2 == 0x6000) {
      local_48[1] = 3;
      local_c = (undefined2)local_2c;
      goto LAB_0012d461;
    }
    if (uVar2 == 0xc000) {
      local_48[1] = 6;
    }
    else {
      local_48[1] = 1;
    }
  }
  local_40 = local_40 & 0xfff;
  iVar3 = FUN_0012dc2c(param_1,param_3);
  if (iVar3 == 0) {
    *param_2 = 0x46;
    return;
  }
  if (((*param_3 & 1) != 0) ||
     (((*param_3 & 2) != 0 &&
      (iVar4 = FUN_0012dc70(*(int *)(param_4 + 0x1c) + 0x10,param_3 + 6), iVar4 == 0)))) {
    iVar4 = 0x1e;
    goto LAB_0012d5e0;
  }
  if ((local_2c == 0) && (iVar4 = _svckudp_dup(param_4), iVar4 != 0)) {
    uVar7 = *(undefined4 *)(_active_u + 0x1c);
    pcVar6 = *(code **)(*(int *)(iVar3 + 0x1c) + 0x20);
LAB_0012d570:
    iVar4 = (*pcVar6)(iVar3,pcVar1,local_48,uVar7,0,0);
  }
  else {
    iVar4 = (**(code **)(*(int *)(iVar3 + 0x1c) + 0x24))
                      (iVar3,pcVar1,local_48 + 1,0,0x80,local_48,*(undefined4 *)(_active_u + 0x1c));
    if (iVar4 != 0) {
      iVar5 = _svckudp_dup(param_4);
      if (iVar5 == 0) goto LAB_0012d5e0;
      uVar7 = *(undefined4 *)(_active_u + 0x1c);
      pcVar6 = *(code **)(*(int *)(iVar3 + 0x1c) + 0x20);
      goto LAB_0012d570;
    }
    _svckudp_dupsave(param_4);
  }
  if (iVar4 == 0) {
    iVar4 = (**(code **)(*(int *)(local_48[0] + 0x1c) + 0x14))
                      (local_48[0],local_48 + 1,*(undefined4 *)(_active_u + 0x1c));
    if (iVar4 == 0) {
      _vattr_to_nattr(local_48 + 1,param_2 + 9);
      iVar4 = _makefh(param_2 + 1,local_48[0],param_3);
    }
    _vn_rele(local_48[0]);
  }
LAB_0012d5e0:
  *param_2 = iVar4;
  _vn_rele(iVar3);
  return;
}

