/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010d050 */

int _ioctl(int param_1,ulong param_2,...)

{
  byte *pbVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined1 uVar7;
  uint uVar8;
  uint local_84 [32];
  
  iVar6 = DAT_001e875c;
  puVar2 = *(uint **)(DAT_001e875c + 0x24);
  uVar8 = *puVar2;
  if (*(uint *)(_active_u + 0x15c) <= uVar8) {
LAB_0010d09c:
    *(undefined1 *)(DAT_001e875c + 0x68) = 9;
    return iVar6;
  }
  iVar3 = *(int *)(_active_u + 0x150);
  iVar4 = *(int *)(iVar3 + uVar8 * 4);
  if ((iVar4 == 0) || (iVar4 == -0x10000)) goto LAB_0010d09c;
  if ((*(byte *)(iVar4 + 8) & 3) == 0) {
    *(undefined1 *)(DAT_001e875c + 0x68) = 9;
    return iVar3;
  }
  uVar5 = puVar2[1];
  if (uVar5 == 0x20006601) {
    iVar6 = *(int *)(_active_u + 0x154);
    pbVar1 = (byte *)(uVar8 + iVar6);
    *pbVar1 = *pbVar1 | 1;
    return iVar6;
  }
  if (uVar5 == 0x20006602) {
    iVar6 = *(int *)(_active_u + 0x154);
    pbVar1 = (byte *)(uVar8 + iVar6);
    *pbVar1 = *pbVar1 & 0xfe;
    return iVar6;
  }
  uVar8 = (uVar5 & 0x1fffffff) >> 0x10;
  if (0x80 < uVar8) {
    *(undefined1 *)(DAT_001e875c + 0x68) = 0xe;
    return uVar8;
  }
  if ((int)uVar5 < 0) {
    if (uVar8 == 0) {
LAB_0010d1ac:
      local_84[0] = puVar2[2];
    }
    else {
      uVar7 = _copyin(puVar2[2],local_84,uVar8);
      *(undefined1 *)(DAT_001e875c + 0x68) = uVar7;
      if (*(char *)(DAT_001e875c + 0x68) != '\0') {
        return DAT_001e875c;
      }
    }
  }
  else if (((uVar5 & 0x40000000) == 0) || (uVar8 == 0)) {
    if ((uVar5 & 0x20000000) != 0) goto LAB_0010d1ac;
  }
  else {
    _bzero(local_84,uVar8);
  }
  if (uVar5 == 0x8004667d) {
    uVar7 = _fset(iVar4,0x40,local_84[0]);
    goto LAB_0010d276;
  }
  if ((int)uVar5 < -0x7ffb9982) {
    if (uVar5 == 0x8004667c) {
      uVar7 = _fsetown(iVar4,local_84[0]);
      goto LAB_0010d276;
    }
  }
  else {
    if (uVar5 == 0x8004667e) {
      uVar7 = _fset(iVar4,4,local_84[0]);
      goto LAB_0010d276;
    }
    if (uVar5 == 0x4004667b) {
      uVar7 = _fgetown(iVar4,local_84);
      goto LAB_0010d276;
    }
  }
  uVar7 = (**(code **)(*(int *)(iVar4 + 0x14) + 4))(iVar4,uVar5,local_84);
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar7;
  if (*(char *)(DAT_001e875c + 0x68) != '\0') {
    return DAT_001e875c;
  }
  if ((uVar5 & 0x40000000) == 0) {
    return DAT_001e875c;
  }
  if (uVar8 == 0) {
    return DAT_001e875c;
  }
  uVar7 = _copyout(local_84,puVar2[2],uVar8);
LAB_0010d276:
  iVar6 = DAT_001e875c;
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar7;
  return iVar6;
}

