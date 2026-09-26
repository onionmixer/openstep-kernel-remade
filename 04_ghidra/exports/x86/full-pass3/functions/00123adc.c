/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00123adc */

int _in_ifinit(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined2 local_24 [2];
  uint local_20;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  uVar6 = param_3[1];
  uVar2 = uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 | uVar6 << 0x18;
  uVar3 = _splimp();
  local_14 = *param_2;
  local_10 = param_2[1];
  local_c = param_2[2];
  local_8 = param_2[3];
  *param_2 = *param_3;
  param_2[1] = param_3[1];
  param_2[2] = param_3[2];
  param_2[3] = param_3[3];
  if ((*(int *)(param_1 + 0x38) == 0) || (iVar4 = _if_ioctl(param_1,0x8020690c,param_2), iVar4 == 0)
     ) {
    _bzero(local_24,0x10);
    local_24[0] = 2;
    if ((*(byte *)(param_2 + 0xf) & 1) != 0) {
      if ((*(ushort *)(param_1 + 0xc) & 8) == 0) {
        if ((*(ushort *)(param_1 + 0xc) & 0x10) == 0) {
          uVar1 = param_2[0xc];
          for (iVar4 = _in_ifaddr;
              (iVar4 != 0 && (*(uint *)(iVar4 + 0x28) != (*(uint *)(iVar4 + 0x2c) & uVar1)));
              iVar4 = *(int *)(iVar4 + 0x40)) {
          }
          local_20 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18
          ;
          uVar7 = 0;
          puVar5 = (undefined4 *)local_24;
        }
        else {
          uVar7 = 4;
          puVar5 = param_2 + 4;
        }
      }
      else {
        uVar7 = 4;
        puVar5 = &local_14;
      }
      _rtinit(puVar5,&local_14,0x8030720b,uVar7);
      param_2[0xf] = param_2[0xf] & 0xfffffffe;
    }
    if ((int)uVar2 < 0) {
      if ((uVar6 << 0x18 & 0xc0000000) == 0x80000000) {
        param_2[0xb] = 0xffff0000;
      }
      else {
        param_2[0xb] = 0xffffff00;
      }
    }
    else {
      param_2[0xb] = 0xff000000;
    }
    param_2[10] = uVar2 & param_2[0xb];
    uVar6 = param_2[0xd];
    param_2[0xd] = uVar6 | param_2[0xb];
    param_2[0xc] = (uVar6 | param_2[0xb]) & uVar2;
    if ((*(byte *)(param_1 + 0xc) & 2) != 0) {
      *(undefined2 *)(param_2 + 4) = 2;
      uVar6 = param_2[0xc];
      iVar4 = _in_ifaddr;
      if ((int)uVar6 < 0) {
        uVar2 = 0xff;
        if ((uVar6 & 0xc0000000) == 0x80000000) {
          uVar2 = 0xffff;
        }
      }
      else {
        uVar2 = 0xffffff;
      }
      for (; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x40)) {
        if (*(uint *)(iVar4 + 0x28) == (*(uint *)(iVar4 + 0x2c) & uVar6)) {
          uVar2 = ~*(uint *)(iVar4 + 0x34);
          break;
        }
      }
      uVar6 = uVar6 | uVar2;
      param_2[5] = uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 | uVar6 << 0x18;
      uVar6 = ~param_2[0xb] | param_2[10];
      param_2[0xe] = uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 | uVar6 << 0x18
      ;
    }
    if ((*(ushort *)(param_1 + 0xc) & 8) == 0) {
      if ((*(ushort *)(param_1 + 0xc) & 0x10) == 0) {
        uVar6 = param_2[0xc];
        for (iVar4 = _in_ifaddr;
            (iVar4 != 0 && (*(uint *)(iVar4 + 0x28) != (*(uint *)(iVar4 + 0x2c) & uVar6)));
            iVar4 = *(int *)(iVar4 + 0x40)) {
        }
        local_20 = uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 | uVar6 << 0x18;
        uVar7 = 1;
        puVar5 = (undefined4 *)local_24;
      }
      else {
        uVar7 = 5;
        puVar5 = param_2 + 4;
      }
    }
    else {
      uVar7 = 5;
      puVar5 = param_2;
    }
    _rtinit(puVar5,param_2,0x8030720a,uVar7);
    *(byte *)(param_2 + 0xf) = *(byte *)(param_2 + 0xf) | 1;
    _in_addmulti(0x10000e0,param_1);
    _splx(uVar3);
    iVar4 = 0;
  }
  else {
    _splx(uVar3);
    *param_2 = local_14;
    param_2[1] = local_10;
    param_2[2] = local_c;
    param_2[3] = local_8;
  }
  return iVar4;
}

