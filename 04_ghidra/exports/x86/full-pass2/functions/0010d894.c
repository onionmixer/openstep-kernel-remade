/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010d894 */

undefined4 _soo_ioctl(int param_1,int param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 0x18);
  if (param_2 == 0x200073ff) {
    *(byte *)(iVar1 + 6) = *(byte *)(iVar1 + 6) | 0x80;
  }
  else if (param_2 < 0x20007400) {
    if (param_2 == -0x7ffb9982) {
      if (*param_3 == 0) {
        *(ushort *)(iVar1 + 6) = *(ushort *)(iVar1 + 6) & 0xfeff;
      }
      else {
        *(ushort *)(iVar1 + 6) = *(ushort *)(iVar1 + 6) | 0x100;
      }
    }
    else if (param_2 < -0x7ffb9981) {
      if (param_2 != -0x7ffb9983) {
LAB_0010d964:
        uVar2 = param_2 >> 8 & 0xff;
        if (uVar2 == 0x69) {
          uVar3 = _ifioctl(iVar1,param_2,param_3);
          return uVar3;
        }
        if (uVar2 == 0x72) {
          uVar3 = _rtioctl(param_2,param_3);
          return uVar3;
        }
        uVar3 = (**(code **)(*(int *)(iVar1 + 0xc) + 0x1c))(iVar1,0xb,param_2,param_3,0);
        return uVar3;
      }
      if (*param_3 == 0) {
        *(ushort *)(iVar1 + 6) = *(ushort *)(iVar1 + 6) & 0xfdff;
      }
      else {
        *(ushort *)(iVar1 + 6) = *(ushort *)(iVar1 + 6) | 0x200;
      }
    }
    else {
      if (param_2 != -0x7ffb8cf8) goto LAB_0010d964;
      *(short *)(iVar1 + 0x5a) = (short)*param_3;
    }
  }
  else if (param_2 == 0x40047307) {
    *param_3 = *(ushort *)(iVar1 + 6) >> 6 & 1;
  }
  else {
    if (param_2 < 0x40047308) {
      if (param_2 != 0x4004667f) goto LAB_0010d964;
      uVar2 = (uint)*(ushort *)(iVar1 + 0x24);
    }
    else {
      if (param_2 != 0x40047309) goto LAB_0010d964;
      uVar2 = (uint)*(short *)(iVar1 + 0x5a);
    }
    *param_3 = uVar2;
  }
  return 0;
}

