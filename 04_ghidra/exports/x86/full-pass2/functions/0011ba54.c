/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011ba54 */

int _vno_ioctl(int param_1,int param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined1 local_44 [24];
  int local_2c;
  
  iVar3 = *(int *)(param_1 + 0x18);
  switch(*(undefined4 *)(iVar3 + 0x28)) {
  case 1:
    break;
  case 2:
  case 8:
    goto switchD_0011ba7b_caseD_2;
  default:
    return 0x19;
  case 4:
  case 9:
    *(undefined4 *)(DAT_001e875c + 0x60) = 0;
    iVar2 = _set_label((int *)(DAT_001e875c + 0x28));
    if (iVar2 == 0) {
      iVar3 = (**(code **)(*(int *)(iVar3 + 0x1c) + 0xc))
                        (iVar3,param_2,param_3,*(undefined4 *)(param_1 + 8),
                         *(undefined4 *)(param_1 + 0x20));
      return iVar3;
    }
    if ((_active_u[0x50] >> (*(char *)(*_active_u + 0x17) - 1U & 0x1f) & 1U) != 0) {
      return 4;
    }
    *(undefined1 *)(DAT_001e875c + 0x69) = 2;
    return 0;
  }
  if (param_2 == -0x3ffb9996) {
    uVar1 = *(uint *)(param_1 + 8);
    iVar3 = *param_3;
    if (iVar3 == 1) {
      *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 0x1000;
    }
    else if (iVar3 < 2) {
      if (iVar3 != 0) {
        return 0x16;
      }
    }
    else {
      if (iVar3 != 2) {
        return 0x16;
      }
      *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xffffefff;
    }
    if ((uVar1 & 0x1000) == 0) {
      *param_3 = 2;
    }
    else {
      *param_3 = 1;
    }
    return 0;
  }
switchD_0011ba7b_caseD_2:
  if (param_2 < -0x7ffb9983) {
    return 0x19;
  }
  if (-0x7ffb9982 < param_2) {
    if (param_2 != 0x4004667f) {
      return 0x19;
    }
    iVar3 = (**(code **)(*(int *)(iVar3 + 0x1c) + 0x14))(iVar3,local_44,_active_u[7]);
    if (iVar3 != 0) {
      return iVar3;
    }
    *param_3 = local_2c - *(int *)(param_1 + 0x1c);
    return 0;
  }
  return 0;
}

