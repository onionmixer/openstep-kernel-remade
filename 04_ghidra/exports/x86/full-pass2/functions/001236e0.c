/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001236e0 */

int _in_control(undefined4 param_1,int param_2,int param_3,int param_4)

{
  byte bVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar6 = (undefined4 *)0x0;
  puVar2 = _in_ifaddr;
  if (param_4 != 0) {
    while ((puVar6 = puVar2, puVar6 != (undefined4 *)0x0 && (puVar6[8] != param_4))) {
      puVar2 = (undefined4 *)puVar6[0x10];
    }
  }
  if (param_2 == -0x7fdf96ed) {
    iVar5 = _suser();
    if (iVar5 == 0) goto LAB_00123833;
LAB_00123844:
    if (puVar6 == (undefined4 *)0x0) {
      return 0x31;
    }
  }
  else {
    if (param_2 < -0x7fdf96ec) {
      if ((param_2 != -0x7fdf96f4) && (param_2 != -0x7fdf96f2)) goto LAB_00123844;
    }
    else if (param_2 != -0x7fdf96de) {
      if (-0x7fdf96de < param_2) {
        if (param_2 != -0x3fdf96df) goto LAB_00123844;
        goto LAB_00123854;
      }
      if (param_2 != -0x7fdf96ea) goto LAB_00123844;
    }
    iVar5 = _suser();
    if (iVar5 == 0) {
LAB_00123833:
      return (int)*(char *)(DAT_001e875c + 0x68);
    }
    if (param_4 == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_in_control_001dba9c);
    }
    if (puVar6 == (undefined4 *)0x0) {
      iVar5 = _m_getclr(1,0xd);
      if (iVar5 == 0) {
        return 0x37;
      }
      if (_in_ifaddr == (undefined4 *)0x0) {
        _in_ifaddr = (undefined4 *)(*(int *)(iVar5 + 4) + iVar5);
      }
      else {
        iVar4 = _in_ifaddr[0x10];
        puVar6 = _in_ifaddr;
        while (iVar4 != 0) {
          puVar6 = (undefined4 *)puVar6[0x10];
          iVar4 = puVar6[0x10];
        }
        puVar6[0x10] = *(int *)(iVar5 + 4) + iVar5;
      }
      puVar6 = (undefined4 *)(iVar5 + *(int *)(iVar5 + 4));
      iVar5 = *(int *)(param_4 + 0x18);
      if (iVar5 == 0) {
        *(undefined4 **)(param_4 + 0x18) = puVar6;
      }
      else {
        iVar4 = *(int *)(iVar5 + 0x24);
        while (iVar4 != 0) {
          iVar5 = *(int *)(iVar5 + 0x24);
          iVar4 = *(int *)(iVar5 + 0x24);
        }
        *(undefined4 **)(iVar5 + 0x24) = puVar6;
      }
      puVar6[8] = param_4;
      *(undefined2 *)puVar6 = 2;
      if ((*(byte *)(param_4 + 0xc) & 8) == 0) {
        _in_interfaces = _in_interfaces + 1;
      }
    }
  }
LAB_00123854:
  if (param_2 == -0x7fdf96de) {
    uVar3 = puVar6[0xf];
    puVar6[0xf] = uVar3 & 0xfffffffd;
    if ((*(byte *)(param_4 + 0xc) & 1) != 0) {
      puVar6[0xf] = uVar3 & 0xfffffffd | 4;
      iVar5 = 0;
      do {
        if (iVar5 < 6) {
          iVar4 = (1 << ((byte)iVar5 & 0x1f)) >> 1;
        }
        else {
          iVar4 = 0x20;
        }
        iVar4 = _icmp_sendMaskPacket(param_4,0x11,iVar4);
        if (iVar4 != 0) {
          return iVar4;
        }
        if ((*(byte *)(puVar6 + 0xf) & 4) == 0) {
          return 0;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < 5);
    }
    return 0x32;
  }
  if (param_2 < -0x7fdf96dd) {
    if (param_2 != -0x7fdf96f2) {
      if (param_2 < -0x7fdf96f1) {
        if (param_2 == -0x7fdf96f4) {
          *(ushort *)(param_4 + 0xc) = *(ushort *)(param_4 + 0xc) & 0x7fff;
          iVar5 = _in_ifinit(param_4,puVar6,param_3 + 0x10);
          return iVar5;
        }
      }
      else {
        if (param_2 == -0x7fdf96ed) {
          if ((*(byte *)(param_4 + 0xc) & 2) != 0) {
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
          uVar3 = *(uint *)(param_3 + 0x14);
          uVar3 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
          puVar6[0xd] = uVar3;
          if (uVar3 == 0) {
            return 0;
          }
          *(byte *)(puVar6 + 0xf) = *(byte *)(puVar6 + 0xf) | 2;
          _icmp_sendMaskPacket(param_4,0x12,0);
          return 0;
        }
      }
      goto LAB_00123aa8;
    }
    if ((*(byte *)(param_4 + 0xc) & 0x10) != 0) {
      local_14 = puVar6[4];
      local_10 = puVar6[5];
      local_c = puVar6[6];
      local_8 = puVar6[7];
      puVar6[4] = *(undefined4 *)(param_3 + 0x10);
      puVar6[5] = *(undefined4 *)(param_3 + 0x14);
      puVar6[6] = *(undefined4 *)(param_3 + 0x18);
      puVar6[7] = *(undefined4 *)(param_3 + 0x1c);
      if ((*(int *)(param_4 + 0x38) != 0) &&
         (iVar5 = _if_ioctl(param_4,0x8020690e,puVar6), iVar5 != 0)) {
        puVar6[4] = local_14;
        puVar6[5] = local_10;
        puVar6[6] = local_c;
        puVar6[7] = local_8;
        return iVar5;
      }
      if ((*(byte *)(puVar6 + 0xf) & 1) == 0) {
        return 0;
      }
      _rtinit(&local_14,puVar6,0x8030720b,4);
      _rtinit(puVar6 + 4,puVar6,0x8030720a,5);
      return 0;
    }
  }
  else {
    if (param_2 == -0x3fdf96f1) {
      bVar1 = *(byte *)(param_4 + 0xc) & 0x10;
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
LAB_00123aa8:
        if ((param_4 != 0) && (*(int *)(param_4 + 0x38) != 0)) {
          iVar5 = _if_ioctl(param_4,param_2,param_3);
          return iVar5;
        }
        return 0x2d;
      }
      if (param_2 != -0x3fdf96ee) {
        if (param_2 == -0x3fdf96eb) {
          *(undefined2 *)(param_3 + 0x10) = 2;
          uVar3 = puVar6[0xd];
          *(uint *)(param_3 + 0x14) =
               uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
          return 0;
        }
        goto LAB_00123aa8;
      }
      bVar1 = *(byte *)(param_4 + 0xc) & 2;
    }
    if (bVar1 != 0) {
      *(undefined4 *)(param_3 + 0x10) = puVar6[4];
      *(undefined4 *)(param_3 + 0x14) = puVar6[5];
      *(undefined4 *)(param_3 + 0x18) = puVar6[6];
      *(undefined4 *)(param_3 + 0x1c) = puVar6[7];
      return 0;
    }
  }
  return 0x16;
}

