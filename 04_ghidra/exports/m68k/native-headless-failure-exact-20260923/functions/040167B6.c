
void _smount(void)

{
  uint *puVar1;
  ushort uVar2;
  ushort *puVar3;
  bool bVar4;
  undefined1 uVar8;
  int iVar5;
  undefined4 *puVar6;
  char *pcVar7;
  char *pcVar9;
  uint uVar10;
  int *piVar11;
  undefined **ppuVar12;
  int local_18;
  int local_14;
  undefined1 auStack_10 [4];
  char *local_c;
  
  puVar1 = *(uint **)(DAT_040b57d4 + 0x24);
  local_14 = 0;
  piVar11 = (int *)0x0;
  if ((*(byte *)((int)puVar1 + 0xb) & 0x10) == 0) {
    piVar11 = &local_14;
  }
  uVar8 = _lookupname(puVar1[1],0,1,piVar11,&local_18);
  *(undefined1 *)(DAT_040b57d4 + 100) = uVar8;
  if (*(char *)(DAT_040b57d4 + 100) != '\0') {
    return;
  }
  if (local_18 == 0) {
    if ((puVar1[2] & 0x10) != 0) {
      if (local_14 != 0) {
        _vn_rele(local_14);
      }
      *(undefined1 *)(DAT_040b57d4 + 100) = 2;
      return;
    }
    local_18 = local_14;
    if ((*(byte *)(*(int *)(local_14 + 0x24) + 0xf) & 0x20) != 0) goto LAB_04016914;
    puVar1[2] = puVar1[2] | 0x8000;
    local_14 = 0;
  }
  else {
    if (local_14 != 0) {
      _vn_rele(local_14);
    }
    if ((*(byte *)(*(int *)(local_18 + 0x24) + 0xf) & 0x20) != 0) {
LAB_04016914:
      _vn_rele(local_18);
      *(undefined1 *)(DAT_040b57d4 + 100) = 0x16;
      return;
    }
    _dnlc_purge();
    if ((*(short *)(local_18 + 6) != 1) && ((*(byte *)((int)puVar1 + 0xb) & 0x10) == 0)) {
LAB_0401688c:
      _vn_rele(local_18);
      *(undefined1 *)(DAT_040b57d4 + 100) = 0x10;
      return;
    }
    if (*(int *)(local_18 + 0x28) != 2) {
      _vn_rele(local_18);
      *(undefined1 *)(DAT_040b57d4 + 100) = 0x14;
      return;
    }
    if ((*(byte *)(local_18 + 5) & 1) == 0) {
      iVar5 = (**(code **)(*(int *)(local_18 + 0x1c) + 0x1c))
                        (local_18,0x80,*(undefined4 *)(_active_u + 0x1a));
      if (iVar5 != 0) {
        _vn_rele(local_18);
        *(char *)(DAT_040b57d4 + 100) = (char)iVar5;
        return;
      }
    }
    else if ((*(byte *)((int)puVar1 + 0xb) & 0x10) == 0) goto LAB_0401688c;
  }
  if ((puVar1[2] & 0x14) == 0) {
    if ((4 < *puVar1) ||
       (ppuVar12 = &_vfssw + *(int *)(&DAT_040ae782 + *puVar1 * 4) * 2,
       (&PTR__ufs_vfsops_040ae79a)[*(int *)(&DAT_040ae782 + *puVar1 * 4) * 2] == (undefined *)0x0))
    {
      *(undefined1 *)(DAT_040b57d4 + 100) = 0x13;
      goto LAB_04016d1c;
    }
  }
  else {
    uVar8 = _pn_get(*puVar1,0,auStack_10);
    *(undefined1 *)(DAT_040b57d4 + 100) = uVar8;
    if (*(char *)(DAT_040b57d4 + 100) != '\0') goto LAB_04016d1c;
    ppuVar12 = &_vfssw;
    if (&_vfssw < _vfsNVFS) {
      do {
        if ((*ppuVar12 != (char *)0x0) && (iVar5 = _strcmp(local_c,*ppuVar12), iVar5 == 0)) break;
        ppuVar12 = ppuVar12 + 2;
      } while (ppuVar12 < _vfsNVFS);
    }
    if (ppuVar12 == (undefined **)_vfsNVFS) {
      *(undefined1 *)(DAT_040b57d4 + 100) = 0x13;
      _vn_rele(local_18);
      _pn_free(auStack_10);
      return;
    }
    _pn_free(auStack_10);
  }
  bVar4 = false;
  if ((*(byte *)((int)puVar1 + 0xb) & 0x10) == 0) {
    uVar10 = 0;
    uVar8 = _pn_get(puVar1[1],0,auStack_10);
    *(undefined1 *)(DAT_040b57d4 + 100) = uVar8;
    if (*(char *)(DAT_040b57d4 + 100) != '\0') goto LAB_04016d1c;
    puVar6 = (undefined4 *)_kalloc(0x12a);
    *puVar6 = 0;
    puVar6[1] = ppuVar12[1];
    puVar6[3] = 0;
    puVar6[7] = 0;
    *(undefined4 *)((int)puVar6 + 0x126) = 0;
    puVar6[0x48] = 0;
    *(undefined2 *)(puVar6 + 0x49) = *(undefined2 *)(*(int *)(_active_u + 0x1a) + 2);
    pcVar9 = local_c;
    if (*(short *)((int)puVar1 + 10) < 0) {
      while (pcVar7 = _index(pcVar9,0x2f), pcVar7 != (char *)0x0) {
        pcVar9 = pcVar7 + 1;
      }
      _strncpy((char *)(puVar6 + 8),pcVar9,0xff);
    }
    else {
      _strncpy((char *)(puVar6 + 8),local_c,0xff);
      if (*(undefined **)(local_18 + 0x1c) == &_ufs_vnodeops) {
        while ((*(byte *)(*(int *)(local_18 + 0x2e) + 0x43) & 1) != 0) {
          puVar3 = (ushort *)(*(int *)(local_18 + 0x2e) + 0x42);
          *puVar3 = *puVar3 | 0x10;
          _sleep(*(uint *)(local_18 + 0x2e));
        }
        puVar3 = (ushort *)(*(int *)(local_18 + 0x2e) + 0x42);
        *puVar3 = *puVar3 | 1;
        bVar4 = true;
      }
    }
    if (((char *)(puVar6 + 8) != (char *)0x0) &&
       (iVar5 = _strncmp((char *)(puVar6 + 8),"/Net/AppleShare",0xf), iVar5 == 0)) {
      *(ushort *)((int)puVar6 + 0xe) = *(ushort *)((int)puVar6 + 0xe) | 0x100;
    }
    if (*(short *)(puVar6 + 0x49) != 0) {
      puVar1[2] = puVar1[2] | 2;
    }
    uVar8 = _vfs_add(local_18,puVar6,puVar1[2]);
    *(undefined1 *)(DAT_040b57d4 + 100) = uVar8;
LAB_04016c5a:
    if (*(char *)(DAT_040b57d4 + 100) == '\0') {
      uVar8 = (**(code **)puVar6[1])(puVar6,local_c,puVar1[3]);
      *(undefined1 *)(DAT_040b57d4 + 100) = uVar8;
    }
    if (bVar4) {
      puVar3 = (ushort *)(*(int *)(local_18 + 0x2e) + 0x42);
      *puVar3 = *puVar3 & 0xfffe;
      uVar2 = *(ushort *)(*(int *)(local_18 + 0x2e) + 0x42);
      if ((uVar2 & 0x10) != 0) {
        *(ushort *)(*(int *)(local_18 + 0x2e) + 0x42) = uVar2 & 0xffef;
        _wakeup(*(undefined4 *)(local_18 + 0x2e));
      }
    }
    _pn_free(auStack_10);
    if (*(char *)(DAT_040b57d4 + 100) == '\0') {
      _vfs_unlock(puVar6);
      if ((*(byte *)((int)puVar1 + 0xb) & 0x10) == 0) {
        return;
      }
      puVar6[3] = puVar6[3] & 0xffffffbf;
    }
    else if ((*(byte *)((int)puVar1 + 0xb) & 0x10) == 0) {
      _vfs_remove(puVar6);
      _kfree(puVar6,0x12a);
    }
    else {
      puVar6[3] = uVar10;
      _vfs_unlock(puVar6);
    }
  }
  else {
    if (_rootvfs != (undefined4 *)0x0) {
      puVar6 = _rootvfs;
      do {
        if (((puVar6 == *(undefined4 **)(local_18 + 0x24)) && ((*(byte *)(local_18 + 5) & 1) != 0))
           && (*(int *)(local_18 + 0xc) == 0)) break;
        puVar6 = (undefined4 *)*puVar6;
      } while (puVar6 != (undefined4 *)0x0);
      if (puVar6 != (undefined4 *)0x0) {
        uVar8 = _vfs_lock(puVar6);
        *(undefined1 *)(DAT_040b57d4 + 100) = uVar8;
        if (*(char *)(DAT_040b57d4 + 100) != '\0') goto LAB_04016d1c;
        uVar8 = _pn_get(puVar1[1],0,auStack_10);
        *(undefined1 *)(DAT_040b57d4 + 100) = uVar8;
        if (*(char *)(DAT_040b57d4 + 100) != '\0') {
          _vn_rele(local_18);
          _vfs_unlock(puVar6);
          return;
        }
        if ((*(byte *)((int)puVar1 + 0xb) & 1) != 0) {
          _printf("mount: can\'t remount ro\n");
          *(undefined1 *)(DAT_040b57d4 + 100) = 0x16;
          _vfs_unlock(puVar6);
          _vn_rele(local_18);
          _pn_free(auStack_10);
          return;
        }
        uVar10 = puVar6[3];
        puVar6[3] = uVar10 & 0xfffffffe | 0x40;
        goto LAB_04016c5a;
      }
    }
    *(undefined1 *)(DAT_040b57d4 + 100) = 2;
  }
LAB_04016d1c:
  _vn_rele(local_18);
  return;
}

