/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00123784 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

int __analysis_fragment_00123784(void)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 *unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  
  iVar6 = *(int *)(unaff_EBP + -0x14);
  if (unaff_EBX == (undefined4 *)0x0) {
    *(int *)(unaff_EBP + -0x14) = iVar6;
    iVar3 = _m_getclr(1);
    iVar6 = *(int *)(unaff_EBP + -0x14);
    if (iVar3 == 0) {
      return 0x37;
    }
    if (_in_ifaddr == 0) {
      _in_ifaddr = *(int *)(iVar3 + 4) + iVar3;
    }
    else {
      iVar5 = *(int *)(_in_ifaddr + 0x40);
      iVar1 = _in_ifaddr;
      while (iVar5 != 0) {
        iVar1 = *(int *)(iVar1 + 0x40);
        iVar5 = *(int *)(iVar1 + 0x40);
      }
      *(int *)(iVar1 + 0x40) = *(int *)(iVar3 + 4) + iVar3;
    }
    unaff_EBX = (undefined4 *)(iVar3 + *(int *)(iVar3 + 4));
    iVar3 = *(int *)(iVar6 + 0x18);
    if (iVar3 == 0) {
      *(undefined4 **)(iVar6 + 0x18) = unaff_EBX;
    }
    else {
      iVar5 = *(int *)(iVar3 + 0x24);
      while (iVar5 != 0) {
        iVar3 = *(int *)(iVar3 + 0x24);
        iVar5 = *(int *)(iVar3 + 0x24);
      }
      *(undefined4 **)(iVar3 + 0x24) = unaff_EBX;
    }
    unaff_EBX[8] = iVar6;
    *(undefined2 *)unaff_EBX = 2;
    if ((*(byte *)(iVar6 + 0xc) & 8) == 0) {
      _in_interfaces = _in_interfaces + 1;
    }
  }
  if (unaff_EDI == -0x7fdf96de) {
    uVar4 = unaff_EBX[0xf];
    unaff_EBX[0xf] = uVar4 & 0xfffffffd;
    if ((*(byte *)(iVar6 + 0xc) & 1) != 0) {
      unaff_EBX[0xf] = uVar4 & 0xfffffffd | 4;
      iVar3 = 0;
      do {
        *(int *)(unaff_EBP + -0x14) = iVar6;
        iVar5 = _icmp_sendMaskPacket(iVar6,0x11);
        iVar6 = *(int *)(unaff_EBP + -0x14);
        if (iVar5 != 0) {
          return iVar5;
        }
        if ((*(byte *)(unaff_EBX + 0xf) & 4) == 0) {
          return 0;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 5);
    }
    return 0x32;
  }
  if (unaff_EDI < -0x7fdf96dd) {
    if (unaff_EDI != -0x7fdf96f2) {
      if (unaff_EDI < -0x7fdf96f1) {
        if (unaff_EDI == -0x7fdf96f4) {
          *(ushort *)(iVar6 + 0xc) = *(ushort *)(iVar6 + 0xc) & 0x7fff;
          iVar6 = _in_ifinit(iVar6,unaff_EBX);
          return iVar6;
        }
      }
      else {
        if (unaff_EDI == -0x7fdf96ed) {
          if ((*(byte *)(iVar6 + 0xc) & 2) != 0) {
            unaff_EBX[4] = *(undefined4 *)(unaff_ESI + 0x10);
            unaff_EBX[5] = *(undefined4 *)(unaff_ESI + 0x14);
            unaff_EBX[6] = *(undefined4 *)(unaff_ESI + 0x18);
            unaff_EBX[7] = *(undefined4 *)(unaff_ESI + 0x1c);
            return 0;
          }
          return 0x16;
        }
        if (unaff_EDI == -0x7fdf96ea) {
          unaff_EBX[0xf] = unaff_EBX[0xf] & 0xfffffff9;
          uVar4 = *(uint *)(unaff_ESI + 0x14);
          uVar4 = uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
          unaff_EBX[0xd] = uVar4;
          if (uVar4 == 0) {
            return 0;
          }
          *(byte *)(unaff_EBX + 0xf) = *(byte *)(unaff_EBX + 0xf) | 2;
          _icmp_sendMaskPacket(iVar6,0x12);
          return 0;
        }
      }
      goto LAB_00123aa8;
    }
    if ((*(byte *)(iVar6 + 0xc) & 0x10) != 0) {
      *(undefined4 *)(unaff_EBP + -0x10) = unaff_EBX[4];
      *(undefined4 *)(unaff_EBP + -0xc) = unaff_EBX[5];
      *(undefined4 *)(unaff_EBP + -8) = unaff_EBX[6];
      *(undefined4 *)(unaff_EBP + -4) = unaff_EBX[7];
      unaff_EBX[4] = *(undefined4 *)(unaff_ESI + 0x10);
      unaff_EBX[5] = *(undefined4 *)(unaff_ESI + 0x14);
      unaff_EBX[6] = *(undefined4 *)(unaff_ESI + 0x18);
      unaff_EBX[7] = *(undefined4 *)(unaff_ESI + 0x1c);
      if ((*(int *)(iVar6 + 0x38) != 0) && (iVar6 = _if_ioctl(iVar6,0x8020690e), iVar6 != 0)) {
        unaff_EBX[4] = *(undefined4 *)(unaff_EBP + -0x10);
        unaff_EBX[5] = *(undefined4 *)(unaff_EBP + -0xc);
        unaff_EBX[6] = *(undefined4 *)(unaff_EBP + -8);
        unaff_EBX[7] = *(undefined4 *)(unaff_EBP + -4);
        return iVar6;
      }
      if ((*(byte *)(unaff_EBX + 0xf) & 1) == 0) {
        return 0;
      }
      _rtinit(unaff_EBP + -0x10,unaff_EBX,0x8030720b);
      _rtinit(unaff_EBX + 4,unaff_EBX,0x8030720a,5);
      return 0;
    }
  }
  else {
    if (unaff_EDI == -0x3fdf96f1) {
      bVar2 = *(byte *)(iVar6 + 0xc) & 0x10;
    }
    else {
      if (unaff_EDI < -0x3fdf96f0) {
        if (unaff_EDI == -0x3fdf96f3) {
          *(undefined4 *)(unaff_ESI + 0x10) = *unaff_EBX;
          *(undefined4 *)(unaff_ESI + 0x14) = unaff_EBX[1];
          *(undefined4 *)(unaff_ESI + 0x18) = unaff_EBX[2];
          *(undefined4 *)(unaff_ESI + 0x1c) = unaff_EBX[3];
          return 0;
        }
LAB_00123aa8:
        if ((iVar6 != 0) && (*(int *)(iVar6 + 0x38) != 0)) {
          iVar6 = _if_ioctl(iVar6);
          return iVar6;
        }
        return 0x2d;
      }
      if (unaff_EDI != -0x3fdf96ee) {
        if (unaff_EDI == -0x3fdf96eb) {
          *(undefined2 *)(unaff_ESI + 0x10) = 2;
          uVar4 = unaff_EBX[0xd];
          *(uint *)(unaff_ESI + 0x14) =
               uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
          return 0;
        }
        goto LAB_00123aa8;
      }
      bVar2 = *(byte *)(iVar6 + 0xc) & 2;
    }
    if (bVar2 != 0) {
      *(undefined4 *)(unaff_ESI + 0x10) = unaff_EBX[4];
      *(undefined4 *)(unaff_ESI + 0x14) = unaff_EBX[5];
      *(undefined4 *)(unaff_ESI + 0x18) = unaff_EBX[6];
      *(undefined4 *)(unaff_ESI + 0x1c) = unaff_EBX[7];
      return 0;
    }
  }
  return 0x16;
}

