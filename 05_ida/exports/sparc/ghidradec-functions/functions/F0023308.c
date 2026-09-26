
/* WARNING: Removing unreachable block (ram,0xf00239e0) */
/* WARNING: Removing unreachable block (ram,0xf00239f0) */
/* WARNING: Removing unreachable block (ram,0xf0023988) */
/* WARNING: Removing unreachable block (ram,0xf002374c) */
/* WARNING: Removing unreachable block (ram,0xf002373c) */
/* WARNING: Removing unreachable block (ram,0xf0023710) */
/* WARNING: Removing unreachable block (ram,0xf00236e4) */
/* WARNING: Removing unreachable block (ram,0xf00238f0) */
/* WARNING: Removing unreachable block (ram,0xf0023810) */
/* WARNING: Removing unreachable block (ram,0xf0023864) */
/* WARNING: Removing unreachable block (ram,0xf00237a0) */
/* WARNING: Removing unreachable block (ram,0xf00235d0) */
/* WARNING: Removing unreachable block (ram,0xf00235bc) */
/* WARNING: Removing unreachable block (ram,0xf0023520) */
/* WARNING: Removing unreachable block (ram,0xf002341c) */
/* WARNING: Removing unreachable block (ram,0xf00233c8) */
/* WARNING: Removing unreachable block (ram,0xf00234e4) */
/* WARNING: Removing unreachable block (ram,0xf00234b4) */
/* WARNING: Removing unreachable block (ram,0xf002337c) */
/* WARNING: Removing unreachable block (ram,0xf002339c) */
/* WARNING: Removing unreachable block (ram,0xf00233e4) */
/* WARNING: Removing unreachable block (ram,0xf0023488) */
/* WARNING: Removing unreachable block (ram,0xf0023578) */
/* WARNING: Removing unreachable block (ram,0xf00235c4) */
/* WARNING: Removing unreachable block (ram,0xf0023774) */
/* WARNING: Removing unreachable block (ram,0xf0023828) */
/* WARNING: Removing unreachable block (ram,0xf00237f0) */
/* WARNING: Removing unreachable block (ram,0xf00238ac) */
/* WARNING: Removing unreachable block (ram,0xf00236b0) */
/* WARNING: Removing unreachable block (ram,0xf0023708) */
/* WARNING: Removing unreachable block (ram,0xf0023728) */
/* WARNING: Removing unreachable block (ram,0xf0023744) */
/* WARNING: Removing unreachable block (ram,0xf0023980) */
/* WARNING: Removing unreachable block (ram,0xf00239a8) */
/* WARNING: Removing unreachable block (ram,0xf00239fc) */
/* WARNING: Removing unreachable block (ram,0xf0023a08) */
/* WARNING: Removing unreachable block (ram,0xf0023340) */

undefined8 _smount(undefined4 param_1,undefined4 param_2)

{
  sword sVar1;
  word wVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  undefined *puVar9;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 *puVar10;
  uint *puVar11;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar12;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  puVar11 = *(uint **)(dword_F0133DDC + 0x24);
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0;
  puVar9 = (undefined *)0x0;
  uVar7 = puVar11[1];
  if ((puVar11[2] & 0x10) == 0) {
    puVar9 = (undefined *)((int)register0x00000038 + -0x1c);
  }
  _lookupname(uVar7,0,1,puVar9,(undefined *)((int)register0x00000038 + -0x20));
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar7;
  if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto locret_F0023A10;
  if (*(int *)((int)register0x00000038 + -0x20) == 0) {
    if ((puVar11[2] & 0x10) != 0) {
      if (*(int *)((int)register0x00000038 + -0x1c) != 0) {
        _vn_rele();
      }
      *(undefined *)(dword_F0133DDC + 0x38) = 2;
      goto locret_F0023A10;
    }
    iVar8 = *(int *)((int)register0x00000038 + -0x1c);
    if ((*(uint *)(*(int *)(iVar8 + 0x24) + 0xc) & 0x20) != 0) goto loc_F00234E4;
    puVar11[2] = puVar11[2] | 0x8000;
    *(int *)((int)register0x00000038 + -0x20) = iVar8;
    *(undefined4 *)((int)register0x00000038 + -0x1c) = 0;
    uVar7 = puVar11[2];
  }
  else {
    iVar8 = *(int *)((int)register0x00000038 + -0x20);
    if (*(int *)((int)register0x00000038 + -0x1c) != 0) {
      _vn_rele();
      iVar8 = *(int *)((int)register0x00000038 + -0x20);
    }
    if ((*(uint *)(*(int *)(iVar8 + 0x24) + 0xc) & 0x20) != 0) {
loc_F00234E4:
      _vn_rele(iVar8);
      *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
      goto locret_F0023A10;
    }
    _dnlc_purge();
    iVar8 = *(int *)((int)register0x00000038 + -0x20);
    if (*(sword *)(iVar8 + 6) != 1) {
      if ((puVar11[2] & 0x10) != 0) {
        iVar4 = *(int *)(iVar8 + 0x28);
        goto loc_F00233D8;
      }
      _vn_rele(iVar8);
loc_F002342C:
      *(undefined *)(dword_F0133DDC + 0x38) = 0x10;
      goto locret_F0023A10;
    }
    iVar4 = *(int *)(iVar8 + 0x28);
loc_F00233D8:
    if (iVar4 != 2) {
      _vn_rele(iVar8);
      *(undefined *)(dword_F0133DDC + 0x38) = 0x14;
      goto locret_F0023A10;
    }
    if ((*(word *)(iVar8 + 4) & 1) == 0) {
      iVar8 = *(int *)((int)register0x00000038 + -0x20);
    }
    else {
      if ((puVar11[2] & 0x10) == 0) {
        _vn_rele(iVar8);
        goto loc_F002342C;
      }
      iVar8 = *(int *)((int)register0x00000038 + -0x20);
    }
    if (((*(word *)(iVar8 + 4) & 1) == 0) || (uVar7 = puVar11[2], (uVar7 & 0x10) == 0)) {
      (**(code **)(*(int *)(iVar8 + 0x1c) + 0x1c))(iVar8,0x80,*(undefined4 *)(_active_u + 0x1c));
      if (iVar8 != 0) {
        _vn_rele(*(undefined4 *)((int)register0x00000038 + -0x20));
        *(char *)(dword_F0133DDC + 0x38) = (char)iVar8;
        goto locret_F0023A10;
      }
      uVar7 = puVar11[2];
    }
  }
  if ((uVar7 & 0x14) == 0) {
    if ((*puVar11 < 5) &&
       (puVar9 = _vfssw + *(int *)(unk_F010BDA8 + *puVar11 * 4) * 8,
       *(int *)(_vfssw + *(int *)(unk_F010BDA8 + *puVar11 * 4) * 8 + 4) != 0)) {
      uVar7 = puVar11[2];
      goto loc_F0023630;
    }
    *(undefined *)(dword_F0133DDC + 0x38) = 0x13;
    goto loc_F0023A04;
  }
  uVar7 = *puVar11;
  _pn_get(uVar7,0,(undefined *)((int)register0x00000038 + -0x18));
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar7;
  uVar5 = *(undefined4 *)((int)register0x00000038 + -0x20);
  if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
    puVar9 = _vfssw;
    iVar8 = _vfssw._0_4_;
    if (_vfssw < _vfsNVFS) {
      do {
        if (iVar8 != 0) {
          iVar8 = *(int *)((int)register0x00000038 + -0x14);
          _strcmp();
          if (iVar8 == 0) break;
        }
        puVar9 = (undefined *)((int)puVar9 + 8);
        if (_vfsNVFS <= puVar9) break;
        iVar8 = *(int *)puVar9;
      } while( true );
    }
    if ((undefined5 *)puVar9 == _vfsNVFS) {
      *(undefined *)(dword_F0133DDC + 0x38) = 0x13;
      _vn_rele(*(undefined4 *)((int)register0x00000038 + -0x20));
      _pn_free((undefined *)((int)register0x00000038 + -0x18));
      goto locret_F0023A10;
    }
    _pn_free((undefined *)((int)register0x00000038 + -0x18));
    uVar7 = puVar11[2];
loc_F0023630:
    bVar3 = false;
    if ((uVar7 & 0x10) == 0) {
      uVar7 = puVar11[1];
      _pn_get(uVar7,0,(undefined *)((int)register0x00000038 + -0x18));
      *(char *)(dword_F0133DDC + 0x38) = (char)uVar7;
      uVar7 = 0;
      if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto loc_F0023A04;
      puVar10 = (undefined4 *)0x12c;
      _kalloc();
      *puVar10 = 0;
      puVar10[1] = *(int *)((int)puVar9 + 4);
      puVar10[3] = 0;
      puVar10[7] = 0;
      puVar10[0x4a] = 0;
      puVar10[0x48] = 0;
      *(undefined2 *)(puVar10 + 0x49) = *(undefined2 *)(*(int *)(_active_u + 0x1c) + 2);
      iVar8 = *(int *)((int)register0x00000038 + -0x14);
      if ((puVar11[2] & 0x8000) == 0) {
        _strncpy(puVar10 + 8,*(undefined4 *)((int)register0x00000038 + -0x14),0xff);
        iVar8 = *(int *)((int)register0x00000038 + -0x20);
        if (*(undefined **)(iVar8 + 0x1c) == _ufs_vnodeops) {
          iVar4 = *(int *)(iVar8 + 0x30);
          while ((*(word *)(iVar4 + 0x44) & 1) != 0) {
            *(word *)(*(int *)(iVar8 + 0x30) + 0x44) =
                 *(word *)(*(int *)(iVar8 + 0x30) + 0x44) | 0x10;
            _sleep(*(undefined4 *)(iVar8 + 0x30),10);
            iVar8 = *(int *)((int)register0x00000038 + -0x20);
            iVar4 = *(int *)(iVar8 + 0x30);
          }
          bVar3 = true;
          *(word *)(*(int *)(*(int *)((int)register0x00000038 + -0x20) + 0x30) + 0x44) =
               *(word *)(*(int *)(*(int *)((int)register0x00000038 + -0x20) + 0x30) + 0x44) | 1;
        }
      }
      else {
        while (iVar4 = iVar8, _index(iVar8,0x2f), iVar4 != 0) {
          iVar8 = iVar4 + 1;
        }
        _strncpy(puVar10 + 8,iVar8,0xff);
      }
      puVar6 = puVar10 + 8;
      if (puVar10 == (undefined4 *)0xffffffe0) {
loc_F00238CC:
        sVar1 = *(sword *)(puVar10 + 0x49);
      }
      else {
        _strncmp(puVar6,aNetAppleshare,0xf);
        if (puVar6 == (undefined4 *)0x0) {
          puVar10[3] = puVar10[3] | 0x100;
          goto loc_F00238CC;
        }
        sVar1 = *(sword *)(puVar10 + 0x49);
      }
      uVar5 = *(undefined4 *)((int)register0x00000038 + -0x20);
      if (sVar1 != 0) {
        puVar11[2] = puVar11[2] | 2;
        uVar5 = *(undefined4 *)((int)register0x00000038 + -0x20);
      }
      _vfs_add(uVar5,puVar10,puVar11[2]);
      *(char *)(dword_F0133DDC + 0x38) = (char)uVar5;
loc_F0023904:
      if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
        puVar6 = puVar10;
        (**(code **)puVar10[1])(puVar10,*(undefined4 *)((int)register0x00000038 + -0x14),puVar11[3])
        ;
        *(char *)(dword_F0133DDC + 0x38) = (char)puVar6;
      }
      iVar8 = *(int *)((int)register0x00000038 + -0x20);
      if (bVar3) {
        *(word *)(*(int *)(iVar8 + 0x30) + 0x44) = *(word *)(*(int *)(iVar8 + 0x30) + 0x44) & 0xfffe
        ;
        wVar2 = *(word *)(*(int *)(iVar8 + 0x30) + 0x44);
        if ((wVar2 & 0x10) != 0) {
          *(word *)(*(int *)(iVar8 + 0x30) + 0x44) = wVar2 & 0xffef;
          _wakeup(*(undefined4 *)(iVar8 + 0x30));
        }
      }
      _pn_free((undefined *)((int)register0x00000038 + -0x18));
      if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
        _vfs_unlock(puVar10);
        uVar5 = *(undefined4 *)((int)register0x00000038 + -0x20);
        if ((puVar11[2] & 0x10) == 0) goto locret_F0023A10;
        puVar10[3] = puVar10[3] & 0xffffffbf;
      }
      else {
        if ((puVar11[2] & 0x10) == 0) {
          _vfs_remove(puVar10);
          _kfree(puVar10,300);
          goto loc_F0023A04;
        }
        puVar10[3] = uVar7;
        _vfs_unlock(puVar10);
        uVar5 = *(undefined4 *)((int)register0x00000038 + -0x20);
      }
    }
    else {
      bVar12 = _rootvfs == (undefined4 *)0x0;
      puVar10 = _rootvfs;
      if (!bVar12) {
        iVar8 = *(int *)((int)register0x00000038 + -0x20);
        do {
          if (*(undefined4 **)(iVar8 + 0x24) == puVar10) {
            if ((*(word *)(iVar8 + 4) & 1) == 0) {
              puVar10 = (undefined4 *)*puVar10;
            }
            else {
              bVar12 = puVar10 == (undefined4 *)0x0;
              if (*(int *)(iVar8 + 0xc) == 0) goto loc_F0023698;
              puVar10 = (undefined4 *)*puVar10;
            }
          }
          else {
            puVar10 = (undefined4 *)*puVar10;
          }
        } while (puVar10 != (undefined4 *)0x0);
        bVar12 = true;
      }
loc_F0023698:
      if (!bVar12) {
        puVar6 = puVar10;
        _vfs_lock();
        *(char *)(dword_F0133DDC + 0x38) = (char)puVar6;
        uVar5 = *(undefined4 *)((int)register0x00000038 + -0x20);
        if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto loc_F0023A08;
        uVar7 = puVar11[1];
        _pn_get(uVar7,0,(undefined *)((int)register0x00000038 + -0x18));
        *(char *)(dword_F0133DDC + 0x38) = (char)uVar7;
        if (*(char *)(dword_F0133DDC + 0x38) != '\0') {
          _vn_rele(*(undefined4 *)((int)register0x00000038 + -0x20));
          _vfs_unlock(puVar10);
          goto locret_F0023A10;
        }
        if ((puVar11[2] & 1) != 0) {
          _printf(aMountCanTRemou);
          *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
          _vfs_unlock(puVar10);
          _vn_rele(*(undefined4 *)((int)register0x00000038 + -0x20));
          _pn_free((undefined *)((int)register0x00000038 + -0x18));
          goto locret_F0023A10;
        }
        uVar7 = puVar10[3];
        puVar10[3] = uVar7 & 0xfffffffe | 0x40;
        goto loc_F0023904;
      }
      *(undefined *)(dword_F0133DDC + 0x38) = 2;
loc_F0023A04:
      uVar5 = *(undefined4 *)((int)register0x00000038 + -0x20);
    }
  }
loc_F0023A08:
  _vn_rele(uVar5);
locret_F0023A10:
  return CONCAT44(param_2,param_1);
}
