/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010407c */

int _fcntl(int param_1,int param_2,...)

{
  uint *puVar1;
  byte bVar2;
  int *piVar3;
  undefined1 uVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  byte *pbVar10;
  uint uVar11;
  undefined4 uVar12;
  uint local_1c;
  short local_18 [2];
  int local_14;
  int local_10;
  
  uVar8 = DAT_001e875c;
  puVar1 = *(uint **)(DAT_001e875c + 0x24);
  uVar11 = *puVar1;
  if ((((uint)_active_u[0x57] <= uVar11) ||
      (iVar9 = *(int *)(_active_u[0x54] + uVar11 * 4), iVar9 == 0)) || (iVar9 == -0x10000))
  goto LAB_00104383;
  pbVar10 = (byte *)(uVar11 + _active_u[0x55]);
  uVar11 = puVar1[1];
  switch(uVar11) {
  case 0:
    if (0xff < puVar1[2]) goto LAB_001043ca;
    iVar6 = _ufalloc(puVar1[2]);
    if (iVar6 < 0) {
      return iVar6;
    }
    if (*(int *)(_active_u[0x54] + *puVar1 * 4) == iVar9) {
      bVar2 = *pbVar10;
      _expand_fdlist(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x38),iVar6);
      *(int *)(_active_u[0x54] + iVar6 * 4) = iVar9;
      *(byte *)(iVar6 + _active_u[0x55]) = bVar2 & 0xfe;
      *(short *)(iVar9 + 0xe) = *(short *)(iVar9 + 0xe) + 1;
      piVar3 = _active_u;
      if (iVar6 <= _active_u[0x56]) {
        return (int)_active_u;
      }
      _active_u[0x56] = iVar6;
      return (int)piVar3;
    }
    *(undefined4 *)(_active_u[0x54] + iVar6 * 4) = 0;
    goto LAB_00104383;
  case 1:
    *(uint *)(DAT_001e875c + 0x60) = *pbVar10 & 1;
    break;
  case 2:
    uVar8 = CONCAT31((int3)(uVar11 >> 8),(char)puVar1[2]) & 0xffffff01;
    *pbVar10 = *pbVar10 & 0xfe | (byte)uVar8;
    break;
  case 3:
    *(int *)(DAT_001e875c + 0x60) = *(int *)(iVar9 + 8) + -1;
    break;
  case 4:
    if ((*(byte *)(*_active_u + 0x16) & 2) == 0) {
      uVar11 = *(uint *)(iVar9 + 8) & 0x21b3;
    }
    else {
      uVar11 = *(uint *)(iVar9 + 8) & 0x400031b3;
    }
    uVar7 = puVar1[2] + 1;
    local_1c = (uVar7 & 4) >> 2;
    uVar4 = _fioctl(iVar9,0x8004667e,&local_1c);
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar4;
    uVar8 = DAT_001e875c;
    if (*(char *)(DAT_001e875c + 0x68) == '\0') {
      local_1c = (uVar7 & 0x40) >> 6;
      uVar4 = _fioctl(iVar9,0x8004667d,&local_1c);
      *(undefined1 *)(DAT_001e875c + 0x68) = uVar4;
      uVar8 = DAT_001e875c;
      if (*(char *)(DAT_001e875c + 0x68) == '\0') {
        *(uint *)(iVar9 + 8) = uVar11 | uVar7 & 0xffffde4c;
      }
      else {
        local_1c = *(uint *)(iVar9 + 8) >> 2 & 1;
        uVar8 = _fioctl(iVar9,0x8004667e,&local_1c);
      }
    }
    break;
  case 5:
    uVar4 = _fgetown(iVar9,DAT_001e875c + 0x60);
    goto LAB_001042e5;
  case 6:
    uVar4 = _fsetown(iVar9,puVar1[2]);
LAB_001042e5:
    uVar8 = DAT_001e875c;
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar4;
    break;
  case 7:
  case 8:
  case 9:
    if (*(short *)(iVar9 + 0xc) == 1) {
      if (((*(byte *)(*_active_u + 0x16) & 2) == 0) ||
         (*(int *)(*(int *)(iVar9 + 0x18) + 0x28) != 1)) goto LAB_001043ca;
      cVar5 = _copyin(puVar1[2],local_18,0x14);
      uVar11 = DAT_001e875c;
      *(char *)(DAT_001e875c + 0x68) = cVar5;
      if (cVar5 != '\0') {
        return uVar11;
      }
      if (local_18[0] == 2) {
        if (puVar1[1] != 7) {
          bVar2 = *(byte *)(iVar9 + 8) & 2;
joined_r0x00104381:
          if (bVar2 == 0) goto LAB_00104383;
        }
      }
      else if (local_18[0] < 3) {
        if (local_18[0] != 1) goto LAB_001043ca;
        if (puVar1[1] != 7) {
          bVar2 = *(byte *)(iVar9 + 8) & 1;
          goto joined_r0x00104381;
        }
      }
      else if (local_18[0] != 3) goto LAB_001043ca;
      cVar5 = _rewhence(local_18,iVar9,0);
      uVar11 = DAT_001e875c;
      *(char *)(DAT_001e875c + 0x68) = cVar5;
      if (cVar5 != '\0') {
        return uVar11;
      }
      if (local_10 < 0) {
        local_14 = local_14 + local_10;
        local_10 = -local_10;
      }
      if (-1 < local_14) {
        if ((puVar1[1] != 7) && (local_18[0] != 3)) {
          *pbVar10 = *pbVar10 | 4;
          *(uint *)(*_active_u + 0x28) = *(uint *)(*_active_u + 0x28) | 0x20000000;
        }
        cVar5 = (**(code **)(*(int *)(*(int *)(iVar9 + 0x18) + 0x1c) + 0x60))
                          (*(int *)(iVar9 + 0x18),local_18,puVar1[1],*(undefined4 *)(iVar9 + 0x20),
                           (int)*(short *)(*_active_u + 0x30));
        uVar11 = DAT_001e875c;
        *(char *)(DAT_001e875c + 0x68) = cVar5;
        if (cVar5 != '\0') {
          return uVar11;
        }
        if (puVar1[1] != 7) {
          return uVar11;
        }
        if (local_18[0] == 3) {
          uVar12 = 2;
          uVar11 = puVar1[2];
        }
        else {
          uVar12 = 0x14;
          uVar11 = puVar1[2];
        }
        iVar9 = _copyout(local_18,uVar11,uVar12);
        *(char *)(DAT_001e875c + 0x68) = (char)iVar9;
        return iVar9;
      }
LAB_001043ca:
      uVar11 = DAT_001e875c;
      *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
      return uVar11;
    }
LAB_00104383:
    uVar8 = DAT_001e875c;
    *(undefined1 *)(DAT_001e875c + 0x68) = 9;
    break;
  default:
    *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
    uVar8 = uVar11;
  }
  return uVar8;
}

