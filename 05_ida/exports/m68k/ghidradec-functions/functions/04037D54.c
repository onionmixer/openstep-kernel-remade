
int _itrunc(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  char cVar9;
  word wVar10;
  int iVar11;
  uint uVar12;
  sword sVar14;
  uint uVar13;
  int iVar15;
  undefined *puVar16;
  undefined *puVar17;
  int iVar18;
  int iStack_fa;
  undefined auStack_f6 [8];
  undefined auStack_ee [36];
  undefined auStack_ca [66];
  uint uStack_88;
  int aiStack_6c [11];
  int aiStack_40 [12];
  int aiStack_10 [3];
  
  iStack_fa = 0;
  iVar15 = 0;
  wVar10 = *(word *)(param_1 + 0x42);
  *(word *)(param_1 + 0x42) = wVar10 & 0xfffe;
  if ((wVar10 & 0x10) != 0) {
    *(word *)(param_1 + 0x42) = wVar10 & 0xffee;
    _wakeup(param_1);
  }
  iVar4 = _mfs_trunc(param_1 + 0xc,param_2);
  while ((*(word *)(param_1 + 0x42) & 1) != 0) {
    *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x10;
    _sleep(param_1,10);
  }
  *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 1;
  if (((*(word *)(param_1 + 0x62) & 0xf000) == 0xa000) && ((*(byte *)(param_1 + 0xc9) & 1) != 0)) {
    iVar4 = 0xe;
    iVar15 = param_1 + 0x38;
    do {
      do {
        *(undefined4 *)(iVar15 + 0x8a) = 0;
        iVar15 = iVar15 + -4;
        wVar10 = (word)((uint)iVar4 >> 0x10);
        sVar14 = (sword)iVar4 + -1;
        iVar4 = CONCAT22(wVar10,sVar14);
      } while (sVar14 != -1);
      iVar4 = (uint)wVar10 * 0x10000 + -1;
    } while (wVar10 != 0);
    *(undefined4 *)(param_1 + 0xc6) = 0;
    *(undefined4 *)(param_1 + 0x6e) = 0;
loc_4037E04:
    *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x42;
    _iupdat(param_1,1);
    return 0;
  }
  if (*(uint *)(param_1 + 0x6e) == param_2) goto loc_4037E04;
  iVar18 = *(int *)(param_1 + 0x4e);
  uVar12 = param_2 & ~*(uint *)(iVar18 + 0x48);
  uVar13 = param_2 - 1 >> (*(uint *)(iVar18 + 0x50) & 0x3f);
  if (*(uint *)(param_1 + 0x6e) < param_2) {
    if (uVar12 == 0) {
      uVar12 = *(uint *)(iVar18 + 0x30);
    }
    iVar15 = _bmap(param_1,uVar13,0,uVar12,&iStack_fa);
    if ((*(char *)(dword_40B57D4 + 100) == '\0') || (-1 < iVar15)) {
      *(uint *)(param_1 + 0x6e) = param_2;
      wVar10 = *(word *)(param_1 + 0x42);
      *(word *)(param_1 + 0x42) = wVar10 | 0x40;
      *(word *)(param_1 + 0x42) = wVar10 | 0x48;
      _microtime(&_iuniqtime);
      if ((*(byte *)(param_1 + 0x43) & 4) != 0) {
        *(undefined4 *)(param_1 + 0x72) = _iuniqtime;
      }
      if ((*(byte *)(param_1 + 0x43) & 2) != 0) {
        *(undefined4 *)(param_1 + 0x7a) = _iuniqtime;
      }
      if ((*(byte *)(param_1 + 0x43) & 0x40) != 0) {
        *(undefined4 *)(param_1 + 0x4a) = 0;
        *(undefined4 *)(param_1 + 0x82) = _iuniqtime;
      }
      *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) & 0xffb9;
    }
    if (iStack_fa != 0) {
      _iupdat(param_1,1);
    }
  }
  else {
    uVar5 = (*(int *)(iVar18 + 0x30) + param_2) - 1 >> (*(uint *)(iVar18 + 0x50) & 0x3f);
    iVar3 = uVar5 - 1;
    aiStack_10[0] = uVar5 - 0xd;
    aiStack_10[1] = aiStack_10[0] - *(int *)(iVar18 + 0x74);
    aiStack_10[2] = aiStack_10[1] - *(int *)(iVar18 + 0x74) * *(int *)(iVar18 + 0x74);
    iVar6 = (**(code **)(*(int *)(param_1 + 0x28) + 0x80))(param_1 + 0xc);
    iVar1 = *(int *)(iVar18 + 0x30);
    uVar8 = *(uint *)(param_1 + 0x6e);
    if (uVar12 == 0) {
      *(uint *)(param_1 + 0x6e) = param_2;
    }
    else {
      iVar11 = _bmap(param_1,uVar13,0,uVar12,0);
      iVar11 = iVar11 << (*(uint *)(iVar18 + 100) & 0x3f);
      cVar9 = *(char *)(dword_40B57D4 + 100);
      if ((cVar9 != '\0') || (iVar11 < 0)) goto loc_40382B2;
      *(uint *)(param_1 + 0x6e) = param_2;
      if (((int)uVar13 < 0xc) && (param_2 < uVar13 + 1 << (*(uint *)(iVar18 + 0x50) & 0x3f))) {
        uVar13 = *(uint *)(iVar18 + 0x4c) &
                 (*(int *)(iVar18 + 0x34) + (param_2 & ~*(uint *)(iVar18 + 0x48))) - 1;
      }
      else {
        uVar13 = *(uint *)(iVar18 + 0x30);
      }
      uVar2 = *(undefined4 *)(param_1 + 0x3e);
      if (**(int **)(param_1 + 0xc) != 0) {
        _vnode_uncache(param_1 + 0xc);
      }
      if (iVar4 == 0) {
        iVar4 = _bread(uVar2,iVar11,uVar13);
        if ((*(byte *)(iVar4 + 3) & 4) != 0) {
          *(undefined *)(dword_40B57D4 + 100) = 5;
          *(uint *)(param_1 + 0x6e) = uVar8;
          _brelse(iVar4);
          return 5;
        }
        _bzero(*(int *)(iVar4 + 0x20) + uVar12,uVar13 - uVar12);
        _bdwrite(iVar4);
      }
    }
    _bcopy(param_1,auStack_f6,0xe6);
    iVar11 = 2;
    iVar4 = param_1 + 8;
    do {
      if (aiStack_10[iVar11] < 0) {
        *(undefined4 *)(iVar4 + 0xba) = 0;
        aiStack_10[iVar11] = -1;
      }
      iVar4 = iVar4 + -4;
      wVar10 = (word)((uint)iVar11 >> 0x10);
      sVar14 = (sword)iVar11 + -1;
      iVar11 = CONCAT22(wVar10,sVar14);
    } while ((sVar14 != -1) || (iVar11 = (uint)wVar10 * 0x10000 + -1, wVar10 != 0));
    iVar4 = 0xb;
    if (iVar3 < 0xb) {
      iVar11 = param_1 + 0x2c;
      do {
        *(undefined4 *)(iVar11 + 0x8a) = 0;
        iVar11 = iVar11 + -4;
        iVar4 = iVar4 + -1;
      } while (iVar3 < iVar4);
    }
    *(uint *)(param_1 + 0x6e) = param_2;
    *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x42;
    uStack_88 = uVar8;
    _iupdat(param_1,1);
    puVar17 = auStack_f6;
    iVar4 = 2;
    puVar16 = auStack_ee;
    do {
      iVar11 = *(int *)(puVar16 + 0xba);
      if (iVar11 != 0) {
        iVar7 = _indirtrunc(puVar17,iVar11,aiStack_10[iVar4],iVar4);
        iVar15 = iVar7 + iVar15;
        if (aiStack_10[iVar4] < 0) {
          *(undefined4 *)(puVar16 + 0xba) = 0;
          _free_block(puVar17,iVar11,*(undefined4 *)(iVar18 + 0x30));
          iVar15 = iVar1 / iVar6 + iVar15;
        }
      }
      if (-1 < aiStack_10[iVar4]) goto loc_403823E;
      puVar16 = puVar16 + -4;
      wVar10 = (word)((uint)iVar4 >> 0x10);
      sVar14 = (sword)iVar4 + -1;
      iVar4 = CONCAT22(wVar10,sVar14);
    } while ((sVar14 != -1) || (iVar4 = (uint)wVar10 * 0x10000 + -1, wVar10 != 0));
    iVar4 = 0xb;
    if (iVar3 < 0xb) {
      puVar16 = auStack_ca;
      do {
        iVar1 = *(int *)(puVar16 + 0x8a);
        if (iVar1 != 0) {
          *(undefined4 *)(puVar16 + 0x8a) = 0;
          if ((iVar4 < 0xc) && (uStack_88 < (uint)(iVar4 + 1 << (*(uint *)(iVar18 + 0x50) & 0x3f))))
          {
            uVar12 = *(uint *)(iVar18 + 0x4c) &
                     (*(int *)(iVar18 + 0x34) + (uStack_88 & ~*(uint *)(iVar18 + 0x48))) - 1;
          }
          else {
            uVar12 = *(uint *)(iVar18 + 0x30);
          }
          _free_block(puVar17,iVar1,uVar12);
          uVar13 = (**(code **)(*(int *)(param_1 + 0x28) + 0x80))(param_1 + 0xc);
          iVar15 = uVar12 / uVar13 + iVar15;
        }
        puVar16 = puVar16 + -4;
        iVar4 = iVar4 + -1;
      } while (iVar3 < iVar4);
    }
    if ((-1 < iVar3) && (aiStack_6c[iVar3] != 0)) {
      if ((iVar3 < 0xc) && (uStack_88 < uVar5 << (*(uint *)(iVar18 + 0x50) & 0x3f))) {
        uVar12 = *(uint *)(iVar18 + 0x4c) &
                 (*(int *)(iVar18 + 0x34) + (uStack_88 & ~*(uint *)(iVar18 + 0x48))) - 1;
      }
      else {
        uVar12 = *(uint *)(iVar18 + 0x30);
      }
      uStack_88 = param_2;
      if ((iVar3 < 0xc) && (param_2 < uVar5 << (*(uint *)(iVar18 + 0x50) & 0x3f))) {
        uVar13 = *(uint *)(iVar18 + 0x4c) &
                 (*(int *)(iVar18 + 0x34) + (param_2 & ~*(uint *)(iVar18 + 0x48))) - 1;
      }
      else {
        uVar13 = *(uint *)(iVar18 + 0x30);
      }
      if (uVar13 == 0) {
                    /* WARNING: Subroutine does not return */
        _panic(aItruncNewspace);
      }
      if (uVar13 != uVar12) {
        _free_block(puVar17,aiStack_6c[iVar3] + (uVar13 >> (*(uint *)(iVar18 + 0x54) & 0x3f)),
                    uVar12 - uVar13);
        uVar8 = (**(code **)(*(int *)(param_1 + 0x28) + 0x80))(param_1 + 0xc);
        iVar15 = (uVar12 - uVar13) / uVar8 + iVar15;
      }
    }
loc_403823E:
    iVar4 = 0;
    puVar16 = puVar17;
    iVar18 = param_1;
    do {
      if (*(int *)(puVar16 + 0xba) != *(int *)(iVar18 + 0xba)) {
                    /* WARNING: Subroutine does not return */
        _panic(&aItrunc1);
      }
      iVar18 = iVar18 + 4;
      puVar16 = puVar16 + 4;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 3);
    iVar4 = 0;
    iVar18 = param_1;
    do {
      if (*(int *)(puVar17 + 0x8a) != *(int *)(iVar18 + 0x8a)) {
                    /* WARNING: Subroutine does not return */
        _panic(&aItrunc2);
      }
      iVar18 = iVar18 + 4;
      puVar17 = puVar17 + 4;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0xc);
    iVar15 = *(int *)(param_1 + 0xca) - iVar15;
    *(int *)(param_1 + 0xca) = iVar15;
    if (iVar15 < 0) {
      *(undefined4 *)(param_1 + 0xca) = 0;
    }
    *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x40;
  }
  cVar9 = *(char *)(dword_40B57D4 + 100);
loc_40382B2:
  return (int)cVar9;
}
