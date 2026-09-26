/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00124fe4 */

undefined4 _in_pcbconnect(int param_1,int param_2)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  short *psVar6;
  
  iVar4 = 0;
  psVar6 = (short *)(param_2 + *(int *)(param_2 + 4));
  if (*(short *)(param_2 + 8) != 0x10) {
    return 0x16;
  }
  if (*psVar6 != 2) {
    return 0x2f;
  }
  if (psVar6[1] == 0) {
    return 0x31;
  }
  if (_in_ifaddr != 0) {
    if (*(int *)(psVar6 + 2) == 0) {
      uVar2 = *(undefined4 *)(_in_ifaddr + 4);
    }
    else {
      if ((*(int *)(psVar6 + 2) != -1) || ((*(byte *)(*(int *)(_in_ifaddr + 0x20) + 0xc) & 2) == 0))
      goto LAB_00125050;
      uVar2 = *(undefined4 *)(_in_ifaddr + 0x14);
    }
    *(undefined4 *)(psVar6 + 2) = uVar2;
  }
LAB_00125050:
  if (*(int *)(param_1 + 0x14) != 0) goto LAB_00125192;
  iVar4 = 0;
  piVar5 = (int *)(param_1 + 0x24);
  iVar3 = *(int *)(param_1 + 0x24);
  if (iVar3 == 0) {
LAB_001250a7:
    if ((*(byte *)(*(int *)(param_1 + 0x1c) + 2) & 0x10) == 0) goto LAB_001250b3;
  }
  else {
    if ((*(int *)(param_1 + 0x2c) != *(int *)(psVar6 + 2)) ||
       ((*(byte *)(*(int *)(param_1 + 0x1c) + 2) & 0x10) != 0)) {
      if (*(short *)(iVar3 + 0x26) == 1) {
        _rtfree(iVar3);
      }
      else {
        *(short *)(iVar3 + 0x26) = *(short *)(iVar3 + 0x26) + -1;
      }
      *piVar5 = 0;
      goto LAB_001250a7;
    }
LAB_001250b3:
    if ((*piVar5 == 0) || (*(int *)(*piVar5 + 0x2c) == 0)) {
      *(undefined2 *)(param_1 + 0x28) = 2;
      *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(psVar6 + 2);
      _rtalloc(piVar5);
    }
  }
  if (((*piVar5 == 0) || (iVar3 = *(int *)(*piVar5 + 0x2c), iVar3 == 0)) ||
     ((*(byte *)(iVar3 + 0xc) & 8) != 0)) {
LAB_00125100:
    if (iVar4 == 0) goto LAB_00125104;
  }
  else {
    iVar4 = _in_ifaddr;
    if (_in_ifaddr != 0) {
      do {
        if (*(int *)(iVar4 + 0x20) == iVar3) break;
        iVar4 = *(int *)(iVar4 + 0x40);
      } while (iVar4 != 0);
      goto LAB_00125100;
    }
LAB_00125104:
    sVar1 = psVar6[1];
    psVar6[1] = 0;
    iVar4 = _ifa_ifwithdstaddr(psVar6);
    psVar6[1] = sVar1;
    if (iVar4 == 0) {
      uVar2 = _in_netof(*(undefined4 *)(psVar6 + 2));
      iVar4 = _in_iaonnetof(uVar2);
      if ((iVar4 == 0) && (iVar4 = _in_ifaddr, _in_ifaddr == 0)) {
        return 0x31;
      }
    }
  }
  if ((((*(uint *)(psVar6 + 2) & 0xf0) == 0xe0) && (iVar3 = *(int *)(param_1 + 0x3c), iVar3 != 0))
     && (iVar3 = *(int *)(iVar3 + *(int *)(iVar3 + 4)), iVar3 != 0)) {
    iVar4 = _in_ifaddr;
    if (_in_ifaddr != 0) {
      do {
        if (*(int *)(iVar4 + 0x20) == iVar3) break;
        iVar4 = *(int *)(iVar4 + 0x40);
      } while (iVar4 != 0);
      if (iVar4 != 0) goto LAB_00125192;
    }
    return 0x31;
  }
LAB_00125192:
  iVar3 = *(int *)(param_1 + 0x14);
  if (iVar3 == 0) {
    iVar3 = *(int *)(iVar4 + 4);
  }
  iVar3 = _in_pcblookup(*(undefined4 *)(param_1 + 8),*(undefined4 *)(psVar6 + 2),psVar6[1],iVar3,
                        *(undefined2 *)(param_1 + 0x18),0);
  if (iVar3 == 0) {
    if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x1c) + 0xc) + 10) & 4) != 0) &&
       (psVar6[1] == *(short *)(param_1 + 0x18))) {
      iVar3 = *(int *)(param_1 + 0x14);
      if (iVar3 == 0) {
        iVar3 = *(int *)(iVar4 + 4);
      }
      if (iVar3 == *(int *)(psVar6 + 2)) {
        return 0x3d;
      }
    }
    if (*(int *)(param_1 + 0x14) == 0) {
      if (*(short *)(param_1 + 0x18) == 0) {
        _in_pcbbind(param_1,0);
      }
      *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(iVar4 + 4);
    }
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(psVar6 + 2);
    *(short *)(param_1 + 0x10) = psVar6[1];
    uVar2 = 0;
  }
  else {
    uVar2 = 0x30;
  }
  return uVar2;
}

