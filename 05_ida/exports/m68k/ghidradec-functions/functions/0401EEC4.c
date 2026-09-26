
int _in_control(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  byte bVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  puVar6 = (undefined4 *)0x0;
  puVar3 = _in_ifaddr;
  if (param_4 != 0) {
    while ((puVar6 = puVar3, puVar6 != (undefined4 *)0x0 && (param_4 != puVar6[8]))) {
      puVar3 = (undefined4 *)puVar6[0x10];
    }
  }
  if (param_2 == -0x7fdf96ed) {
    iVar4 = _suser();
    if (iVar4 == 0) goto loc_401EFF8;
loc_401F008:
    if (puVar6 == (undefined4 *)0x0) {
      return 0x31;
    }
  }
  else {
    if (param_2 < -0x7fdf96ec) {
      if ((param_2 != -0x7fdf96f4) && (param_2 != -0x7fdf96f2)) goto loc_401F008;
    }
    else if (param_2 != -0x7fdf96de) {
      if (-0x7fdf96de < param_2) {
        if (param_2 != -0x3fdf96df) goto loc_401F008;
        goto loc_401F012;
      }
      if (param_2 != -0x7fdf96ea) goto loc_401F008;
    }
    iVar4 = _suser();
    if (iVar4 == 0) {
loc_401EFF8:
      return (int)*(char *)(dword_40B57D4 + 100);
    }
    if (param_4 == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(aInControl);
    }
    if (puVar6 == (undefined4 *)0x0) {
      iVar4 = _m_getclr(1,0xd);
      if (iVar4 == 0) {
        return 0x37;
      }
      if (_in_ifaddr == (undefined4 *)0x0) {
        _in_ifaddr = (undefined4 *)(*(int *)(iVar4 + 4) + iVar4);
      }
      else {
        iVar1 = _in_ifaddr[0x10];
        puVar6 = _in_ifaddr;
        while (iVar1 != 0) {
          puVar6 = (undefined4 *)puVar6[0x10];
          iVar1 = puVar6[0x10];
        }
        puVar6[0x10] = *(int *)(iVar4 + 4) + iVar4;
      }
      puVar6 = (undefined4 *)(*(int *)(iVar4 + 4) + iVar4);
      iVar4 = *(int *)(param_4 + 0x16);
      if (iVar4 == 0) {
        *(undefined4 **)(param_4 + 0x16) = puVar6;
      }
      else {
        iVar1 = *(int *)(iVar4 + 0x24);
        while (iVar1 != 0) {
          iVar4 = *(int *)(iVar4 + 0x24);
          iVar1 = *(int *)(iVar4 + 0x24);
        }
        *(undefined4 **)(iVar4 + 0x24) = puVar6;
      }
      puVar6[8] = param_4;
      *(undefined2 *)puVar6 = 2;
      if ((*(byte *)(param_4 + 0xd) & 8) == 0) {
        _in_interfaces = _in_interfaces + 1;
      }
    }
  }
loc_401F012:
  if (param_2 == -0x7fdf96de) {
    uVar5 = puVar6[0xf];
    puVar6[0xf] = uVar5 & 0xfffffffd;
    if ((*(byte *)(param_4 + 0xd) & 1) != 0) {
      puVar6[0xf] = uVar5 & 0xfffffffd | 4;
      uVar5 = 0;
      do {
        if ((int)uVar5 < 6) {
          iVar4 = (1 << (uVar5 & 0x3f)) >> 1;
        }
        else {
          iVar4 = 0x20;
        }
        iVar4 = _icmp_sendMaskPacket(param_4,0x11,iVar4);
        if (iVar4 != 0) {
          return iVar4;
        }
        if ((*(byte *)((int)puVar6 + 0x3f) & 4) == 0) {
          return 0;
        }
        uVar5 = uVar5 + 1;
      } while ((int)uVar5 < 5);
    }
    return 0x32;
  }
  if (param_2 < -0x7fdf96dd) {
    if (param_2 != -0x7fdf96f2) {
      if (param_2 < -0x7fdf96f1) {
        if (param_2 == -0x7fdf96f4) {
          *(word *)(param_4 + 0xc) = *(word *)(param_4 + 0xc) & 0x7fff;
          iVar4 = _in_ifinit(param_4,puVar6,param_3 + 0x10);
          return iVar4;
        }
      }
      else {
        if (param_2 == -0x7fdf96ed) {
          if ((*(byte *)(param_4 + 0xd) & 2) != 0) {
            puVar6[4] = *(undefined4 *)(param_3 + 0x10);
            puVar6[5] = *(undefined4 *)(param_3 + 0x14);
            puVar6[6] = *(undefined4 *)(param_3 + 0x18);
            puVar6[7] = *(undefined4 *)(param_3 + 0x1c);
            return 0;
          }
          return 0x16;
        }
        if (param_2 == -0x7fdf96ea) {
          puVar6[0xf] = puVar6[0xf] & 0xfffffff9;
          iVar4 = *(int *)(param_3 + 0x14);
          puVar6[0xd] = iVar4;
          if (iVar4 == 0) {
            return 0;
          }
          puVar6[0xf] = puVar6[0xf] | 2;
          _icmp_sendMaskPacket(param_4,0x12,0);
          return 0;
        }
      }
      goto loc_401F23A;
    }
    if ((*(byte *)(param_4 + 0xd) & 0x10) != 0) {
      uStack_14 = puVar6[4];
      uStack_10 = puVar6[5];
      uStack_c = puVar6[6];
      uStack_8 = puVar6[7];
      puVar6[4] = *(undefined4 *)(param_3 + 0x10);
      puVar6[5] = *(undefined4 *)(param_3 + 0x14);
      puVar6[6] = *(undefined4 *)(param_3 + 0x18);
      puVar6[7] = *(undefined4 *)(param_3 + 0x1c);
      if ((*(int *)(param_4 + 0x36) != 0) &&
         (iVar4 = _if_ioctl(param_4,0x8020690e,puVar6), iVar4 != 0)) {
        puVar6[4] = uStack_14;
        puVar6[5] = uStack_10;
        puVar6[6] = uStack_c;
        puVar6[7] = uStack_8;
        return iVar4;
      }
      if ((*(byte *)((int)puVar6 + 0x3f) & 1) == 0) {
        return 0;
      }
      _rtinit(&uStack_14,puVar6,0x8030720b,4);
      _rtinit(puVar6 + 4,puVar6,0x8030720a,5);
      return 0;
    }
  }
  else {
    if (param_2 == -0x3fdf96f1) {
      bVar2 = *(byte *)(param_4 + 0xd) & 0x10;
    }
    else {
      if (param_2 < -0x3fdf96f0) {
        if (param_2 == -0x3fdf96f3) {
          *(undefined4 *)(param_3 + 0x10) = *puVar6;
          *(undefined4 *)(param_3 + 0x14) = puVar6[1];
          *(undefined4 *)(param_3 + 0x18) = puVar6[2];
          *(undefined4 *)(param_3 + 0x1c) = puVar6[3];
          return 0;
        }
loc_401F23A:
        if ((param_4 != 0) && (*(int *)(param_4 + 0x36) != 0)) {
          iVar4 = _if_ioctl(param_4,param_2,param_3);
          return iVar4;
        }
        return 0x2d;
      }
      if (param_2 != -0x3fdf96ee) {
        if (param_2 == -0x3fdf96eb) {
          *(undefined2 *)(param_3 + 0x10) = 2;
          *(undefined4 *)(param_3 + 0x14) = puVar6[0xd];
          return 0;
        }
        goto loc_401F23A;
      }
      bVar2 = *(byte *)(param_4 + 0xd) & 2;
    }
    if (bVar2 != 0) {
      *(undefined4 *)(param_3 + 0x10) = puVar6[4];
      *(undefined4 *)(param_3 + 0x14) = puVar6[5];
      *(undefined4 *)(param_3 + 0x18) = puVar6[6];
      *(undefined4 *)(param_3 + 0x1c) = puVar6[7];
      return 0;
    }
  }
  return 0x16;
}
