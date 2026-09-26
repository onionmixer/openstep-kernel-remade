/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00118d54 */

void _smount(void)

{
  byte *pbVar1;
  ushort uVar2;
  uint *puVar3;
  bool bVar4;
  undefined1 uVar5;
  int *piVar6;
  int iVar7;
  undefined4 *puVar8;
  char *pcVar9;
  undefined **ppuVar10;
  char *pcVar11;
  uint local_20;
  int local_18;
  int local_14;
  undefined1 local_10 [4];
  char *local_c;
  
  puVar3 = *(uint **)(DAT_001e875c + 0x24);
  local_14 = 0;
  piVar6 = (int *)0x0;
  if ((puVar3[2] & 0x10) == 0) {
    piVar6 = &local_14;
  }
  uVar5 = _lookupname(puVar3[1],0,1,piVar6,&local_18);
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar5;
  if (*(char *)(DAT_001e875c + 0x68) != '\0') {
    return;
  }
  if (local_18 == 0) {
    if ((puVar3[2] & 0x10) != 0) {
      if (local_14 != 0) {
        _vn_rele(local_14);
      }
      *(undefined1 *)(DAT_001e875c + 0x68) = 2;
      return;
    }
    local_18 = local_14;
    if ((*(byte *)(*(int *)(local_14 + 0x24) + 0xc) & 0x20) != 0) goto LAB_00118e94;
    puVar3[2] = puVar3[2] | 0x8000;
    local_14 = 0;
  }
  else {
    if (local_14 != 0) {
      _vn_rele(local_14);
    }
    if ((*(byte *)(*(int *)(local_18 + 0x24) + 0xc) & 0x20) != 0) {
LAB_00118e94:
      _vn_rele(local_18);
      *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
      return;
    }
    _dnlc_purge();
    if ((*(short *)(local_18 + 6) != 1) && ((puVar3[2] & 0x10) == 0)) {
LAB_00118e19:
      _vn_rele(local_18);
      *(undefined1 *)(DAT_001e875c + 0x68) = 0x10;
      return;
    }
    if (*(int *)(local_18 + 0x28) != 2) {
      _vn_rele(local_18);
      *(undefined1 *)(DAT_001e875c + 0x68) = 0x14;
      return;
    }
    if ((*(byte *)(local_18 + 4) & 1) == 0) {
      iVar7 = (**(code **)(*(int *)(local_18 + 0x1c) + 0x1c))
                        (local_18,0x80,*(undefined4 *)(_active_u + 0x1c));
      if (iVar7 != 0) {
        _vn_rele(local_18);
        *(char *)(DAT_001e875c + 0x68) = (char)iVar7;
        return;
      }
    }
    else if ((puVar3[2] & 0x10) == 0) goto LAB_00118e19;
  }
  if ((puVar3[2] & 0x14) == 0) {
    if ((4 < *puVar3) ||
       (ppuVar10 = &_vfssw + *(int *)(&DAT_001db450 + *puVar3 * 4) * 2,
       (&PTR__ufs_vfsops_001db644)[*(int *)(&DAT_001db450 + *puVar3 * 4) * 2] == (undefined *)0x0))
    {
      *(undefined1 *)(DAT_001e875c + 0x68) = 0x13;
      goto LAB_00119280;
    }
  }
  else {
    uVar5 = _pn_get(*puVar3,0,local_10);
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar5;
    if (*(char *)(DAT_001e875c + 0x68) != '\0') goto LAB_00119280;
    ppuVar10 = &_vfssw;
    if (&_vfssw < _vfsNVFS) {
      do {
        if ((*ppuVar10 != (char *)0x0) && (iVar7 = _strcmp(local_c,*ppuVar10), iVar7 == 0)) break;
        ppuVar10 = ppuVar10 + 2;
      } while (ppuVar10 < _vfsNVFS);
    }
    if ((undefined **)_vfsNVFS == ppuVar10) {
      *(undefined1 *)(DAT_001e875c + 0x68) = 0x13;
      _vn_rele(local_18);
      _pn_free(local_10);
      return;
    }
    _pn_free(local_10);
  }
  bVar4 = false;
  if ((puVar3[2] & 0x10) == 0) {
    local_20 = 0;
    uVar5 = _pn_get(puVar3[1],0,local_10);
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar5;
    if (*(char *)(DAT_001e875c + 0x68) != '\0') goto LAB_00119280;
    puVar8 = (undefined4 *)_kalloc(300);
    *puVar8 = 0;
    puVar8[1] = ppuVar10[1];
    puVar8[3] = 0;
    puVar8[7] = 0;
    puVar8[0x4a] = 0;
    puVar8[0x48] = 0;
    *(undefined2 *)(puVar8 + 0x49) = *(undefined2 *)(*(int *)(_active_u + 0x1c) + 2);
    pcVar11 = local_c;
    if ((short)puVar3[2] < 0) {
      while (pcVar9 = _index(pcVar11,0x2f), pcVar9 != (char *)0x0) {
        pcVar11 = pcVar9 + 1;
      }
      _strncpy((char *)(puVar8 + 8),pcVar11,0xff);
    }
    else {
      _strncpy((char *)(puVar8 + 8),local_c,0xff);
      if (*(undefined ***)(local_18 + 0x1c) == &_ufs_vnodeops) {
        while ((*(byte *)(*(int *)(local_18 + 0x30) + 0x44) & 1) != 0) {
          pbVar1 = (byte *)(*(int *)(local_18 + 0x30) + 0x44);
          *pbVar1 = *pbVar1 | 0x10;
          _sleep(*(uint *)(local_18 + 0x30));
        }
        pbVar1 = (byte *)(*(int *)(local_18 + 0x30) + 0x44);
        *pbVar1 = *pbVar1 | 1;
        bVar4 = true;
      }
    }
    if (((char *)(puVar8 + 8) != (char *)0x0) &&
       (iVar7 = _strncmp((char *)(puVar8 + 8),s__Net_AppleShare_001db47d,0xf), iVar7 == 0)) {
      puVar8[3] = puVar8[3] | 0x100;
    }
    if (*(short *)(puVar8 + 0x49) != 0) {
      *(byte *)(puVar3 + 2) = (byte)puVar3[2] | 2;
    }
    uVar5 = _vfs_add(local_18,puVar8,puVar3[2]);
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar5;
LAB_001191d1:
    if (*(char *)(DAT_001e875c + 0x68) == '\0') {
      uVar5 = (**(code **)puVar8[1])(puVar8,local_c,puVar3[3]);
      *(undefined1 *)(DAT_001e875c + 0x68) = uVar5;
    }
    if (bVar4) {
      pbVar1 = (byte *)(*(int *)(local_18 + 0x30) + 0x44);
      *pbVar1 = *pbVar1 & 0xfe;
      uVar2 = *(ushort *)(*(int *)(local_18 + 0x30) + 0x44);
      if ((uVar2 & 0x10) != 0) {
        *(ushort *)(*(int *)(local_18 + 0x30) + 0x44) = uVar2 & 0xffef;
        _wakeup(*(undefined4 *)(local_18 + 0x30));
      }
    }
    _pn_free(local_10);
    if (*(char *)(DAT_001e875c + 0x68) == '\0') {
      _vfs_unlock(puVar8);
      if ((puVar3[2] & 0x10) == 0) {
        return;
      }
      puVar8[3] = puVar8[3] & 0xffffffbf;
    }
    else if ((puVar3[2] & 0x10) == 0) {
      _vfs_remove(puVar8);
      _kfree(puVar8,300);
    }
    else {
      puVar8[3] = local_20;
      _vfs_unlock(puVar8);
    }
  }
  else {
    if (_rootvfs != (undefined4 *)0x0) {
      puVar8 = _rootvfs;
      do {
        if (((*(undefined4 **)(local_18 + 0x24) == puVar8) && ((*(byte *)(local_18 + 4) & 1) != 0))
           && (*(int *)(local_18 + 0xc) == 0)) break;
        puVar8 = (undefined4 *)*puVar8;
      } while (puVar8 != (undefined4 *)0x0);
      if (puVar8 != (undefined4 *)0x0) {
        uVar5 = _vfs_lock(puVar8);
        *(undefined1 *)(DAT_001e875c + 0x68) = uVar5;
        if (*(char *)(DAT_001e875c + 0x68) != '\0') goto LAB_00119280;
        uVar5 = _pn_get(puVar3[1],0,local_10);
        *(undefined1 *)(DAT_001e875c + 0x68) = uVar5;
        if (*(char *)(DAT_001e875c + 0x68) != '\0') {
          _vn_rele(local_18);
          _vfs_unlock(puVar8);
          return;
        }
        if ((puVar3[2] & 1) != 0) {
          _printf(s_mount__can_t_remount_ro_001db464);
          *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
          _vfs_unlock(puVar8);
          _vn_rele(local_18);
          _pn_free(local_10);
          return;
        }
        local_20 = puVar8[3];
        puVar8[3] = local_20 & 0xfffffffe | 0x40;
        goto LAB_001191d1;
      }
    }
    *(undefined1 *)(DAT_001e875c + 0x68) = 2;
  }
LAB_00119280:
  _vn_rele(local_18);
  return;
}

