
/* WARNING: Removing unreachable block (ram,0xf003d908) */
/* WARNING: Removing unreachable block (ram,0xf003dae8) */
/* WARNING: Removing unreachable block (ram,0xf003dc10) */
/* WARNING: Removing unreachable block (ram,0xf003dd20) */
/* WARNING: Removing unreachable block (ram,0xf003dd08) */
/* WARNING: Removing unreachable block (ram,0xf003dcf8) */
/* WARNING: Removing unreachable block (ram,0xf003dcbc) */
/* WARNING: Removing unreachable block (ram,0xf003dc48) */
/* WARNING: Removing unreachable block (ram,0xf003dc38) */
/* WARNING: Removing unreachable block (ram,0xf003dbe8) */
/* WARNING: Removing unreachable block (ram,0xf003db74) */
/* WARNING: Removing unreachable block (ram,0xf003db48) */
/* WARNING: Removing unreachable block (ram,0xf003db00) */
/* WARNING: Removing unreachable block (ram,0xf003da64) */
/* WARNING: Removing unreachable block (ram,0xf003da2c) */
/* WARNING: Removing unreachable block (ram,0xf003da04) */
/* WARNING: Removing unreachable block (ram,0xf003d988) */
/* WARNING: Removing unreachable block (ram,0xf003d940) */
/* WARNING: Removing unreachable block (ram,0xf003d8e0) */
/* WARNING: Removing unreachable block (ram,0xf003d868) */
/* WARNING: Removing unreachable block (ram,0xf003d8a0) */
/* WARNING: Removing unreachable block (ram,0xf003d920) */
/* WARNING: Removing unreachable block (ram,0xf003d954) */
/* WARNING: Removing unreachable block (ram,0xf003d9a0) */
/* WARNING: Removing unreachable block (ram,0xf003da18) */
/* WARNING: Removing unreachable block (ram,0xf003da40) */
/* WARNING: Removing unreachable block (ram,0xf003daa4) */
/* WARNING: Removing unreachable block (ram,0xf003db0c) */
/* WARNING: Removing unreachable block (ram,0xf003db5c) */
/* WARNING: Removing unreachable block (ram,0xf003dba4) */
/* WARNING: Removing unreachable block (ram,0xf003dc30) */
/* WARNING: Removing unreachable block (ram,0xf003dc40) */
/* WARNING: Removing unreachable block (ram,0xf003dca4) */
/* WARNING: Removing unreachable block (ram,0xf003dcec) */
/* WARNING: Removing unreachable block (ram,0xf003dd00) */
/* WARNING: Removing unreachable block (ram,0xf003dd18) */
/* WARNING: Removing unreachable block (ram,0xf003dd2c) */
/* WARNING: Removing unreachable block (ram,0xf003dc1c) */
/* WARNING: Removing unreachable block (ram,0xf003dad4) */
/* WARNING: Removing unreachable block (ram,0xf003dc24) */
/* WARNING: Removing unreachable block (ram,0xf003d860) */

undefined8 sub_F003D850(int param_1,undefined4 *param_2,char *param_3)

{
  char cVar1;
  bool bVar2;
  undefined *puVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined *puVar6;
  char *pcVar7;
  undefined4 unaff_l3;
  undefined *puVar8;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  char *pcVar9;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
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
  _getfsname(&aRoot,param_3);
  _pn_alloc((undefined *)((int)register0x00000038 + -0x150));
  puVar6 = *(undefined **)((int)register0x00000038 + -0x14c);
  bVar2 = false;
  cVar1 = *param_3;
  while( true ) {
    puVar3 = param_3;
    if (cVar1 == '\0') {
      puVar3 = (undefined *)&aRoot_0;
    }
    sub_F003E1D4(puVar3,(undefined *)((int)register0x00000038 + -0x120),
                 (undefined *)((int)register0x00000038 + -0x18),puVar6);
    if ((puVar3 == (char *)0x3c) && (!bVar2)) {
      pcVar7 = param_3;
      if (*param_3 == '\0') {
        pcVar7 = (char *)&aRoot_1;
      }
      _printf(DAT_f010d0f0._0_4_,pcVar7);
      bVar2 = true;
    }
    if (puVar3 != (char *)0x3c) break;
    cVar1 = *param_3;
  }
  if (puVar3 == (char *)0x0) {
    if (bVar2) {
      _printf(aBootparamRespo);
    }
    pcVar7 = (char *)((int)register0x00000038 + -0x18);
    puVar8 = (undefined *)((int)register0x00000038 + -0x120);
    puVar3 = pcVar7;
    sub_F003E3AC(pcVar7,puVar8,puVar6,(undefined *)((int)register0x00000038 + -0x140));
    if (puVar3 != (char *)0x0) {
      _pn_free((undefined *)((int)register0x00000038 + -0x150));
      puVar8 = aMountRootSSFai;
loc_F003DB70:
      _printf(puVar8,(undefined *)((int)register0x00000038 + -0x120),puVar6,puVar3);
      goto locret_F003DD34;
    }
    puVar3 = (undefined *)((int)register0x00000038 + -0x174);
    sub_F003E87C(puVar3,param_1,pcVar7,(undefined *)((int)register0x00000038 + -0x140),puVar8,0,
                 0xffffffff,0);
    pcVar7 = (char *)0x0;
    if ((puVar3 == (char *)0x0) && (_vfs_add(0,param_1,0), puVar3 = pcVar7, pcVar7 == (char *)0x0))
    {
      *(undefined4 *)(*(int *)(param_1 + 0x128) + 0x60) = 0xe10;
      *(undefined4 *)(*(int *)(param_1 + 0x128) + 100) = 36000;
      bVar2 = false;
      *(undefined4 *)(*(int *)(param_1 + 0x128) + 0x68) = 0xe10;
      *(undefined4 *)(*(int *)(param_1 + 0x128) + 0x6c) = 36000;
      iVar4 = *(int *)((int)register0x00000038 + -0x174);
      *(uint *)(*(int *)(param_1 + 0x128) + 0x14) =
           *(uint *)(*(int *)(param_1 + 0x128) + 0x14) | 0x4000000;
      _vfs_unlock(*(undefined4 *)(iVar4 + 0x24));
      *param_2 = *(undefined4 *)((int)register0x00000038 + -0x174);
      _strcpy(param_3,puVar8);
      *param_3 = ':';
      _strcpy(param_3 + 1,puVar6);
      *(undefined *)((int)register0x00000038 + -0x170) = 0;
      _getfsname(&aPrivate_2,(undefined *)((int)register0x00000038 + -0x170));
      cVar1 = *(char *)((int)register0x00000038 + -0x170);
      while( true ) {
        puVar3 = (undefined *)((int)register0x00000038 + -0x170);
        if (cVar1 == '\0') {
          puVar3 = (undefined *)&aPrivate_3;
        }
        sub_F003E1D4(puVar3,(undefined *)((int)register0x00000038 + -0x120),
                     (undefined *)((int)register0x00000038 + -0x18),puVar6);
        if ((puVar3 == (char *)0x3c) && (!bVar2)) {
          if (*(char *)((int)register0x00000038 + -0x170) == '\0') {
            puVar5 = &aPrivate_4;
          }
          else {
            puVar5 = (undefined8 *)((int)register0x00000038 + -0x170);
          }
          _printf(DAT_f010d0f0._0_4_,puVar5);
          bVar2 = true;
        }
        if (puVar3 != (char *)0x3c) break;
        cVar1 = *(char *)((int)register0x00000038 + -0x170);
      }
      if (puVar3 == (char *)0x0) {
        if (bVar2) {
          _printf(aBootparamRespo_0);
        }
        puVar3 = puVar6;
        _index(puVar6,0x40);
        if (puVar3 == (undefined *)0x0) {
          puVar3 = aPrivate_5;
        }
        else {
          *puVar3 = 0;
          puVar3 = puVar3 + 1;
        }
        pcVar9 = (char *)((int)register0x00000038 + -0x18);
        pcVar7 = pcVar9;
        sub_F003E3AC(pcVar9,(undefined *)((int)register0x00000038 + -0x120),puVar6,
                     (undefined *)((int)register0x00000038 + -0x140));
        if (pcVar7 != (char *)0x0) {
          _pn_free((undefined *)((int)register0x00000038 + -0x150));
          puVar8 = aMountPrivateSS;
          puVar3 = pcVar7;
          goto loc_F003DB70;
        }
        iVar4 = _rootvfs;
        (**(code **)(*(int *)(_rootvfs + 4) + 8))(_rootvfs,&_rootdir);
        if (iVar4 != 0) {
          _panic(aNfsMountrootCa);
        }
        *(undefined4 *)(_active_u + 0x15c) = _rootdir;
        *(sword *)(*(int *)(_active_u + 0x15c) + 6) =
             *(sword *)(*(int *)(_active_u + 0x15c) + 6) + 1;
        *(undefined4 *)(_active_u + 0x160) = 0;
        _lookupname(puVar3,1,1,0,(undefined *)((int)register0x00000038 + -0x178));
        if ((puVar3 == (char *)0x0) && (*(int *)((int)register0x00000038 + -0x178) != 0)) {
          _vn_rele(*(undefined4 *)(_active_u + 0x15c));
          _vn_rele(_rootdir);
          _dnlc_purge();
          param_2 = (undefined4 *)0x12c;
          _kalloc();
          *param_2 = 0;
          param_2[1] = _nfs_vfsops;
          param_2[3] = 0;
          param_2[7] = 0;
          param_2[0x4a] = 0;
          param_2[0x48] = 0;
          puVar3 = (undefined *)((int)register0x00000038 + -0x174);
          *(undefined2 *)(param_2 + 0x49) = *(undefined2 *)(*(int *)(_active_u + 0x1c) + 2);
          sub_F003E87C(puVar3,param_2,pcVar9,(undefined *)((int)register0x00000038 + -0x140),
                       (undefined *)((int)register0x00000038 + -0x120),0,0xffffffff,0);
          pcVar7 = *(char **)((int)register0x00000038 + -0x178);
          if (puVar3 == (char *)0x0) {
            _vfs_add(pcVar7,param_2,0);
            if (pcVar7 == (char *)0x0) {
              *(undefined4 *)(*(int *)(param_1 + 0x128) + 100) = 6000;
              *(undefined4 *)(*(int *)(param_1 + 0x128) + 0x6c) = 6000;
              _strncpy(param_1 + 0x20,*(undefined4 *)((int)register0x00000038 + -0x14c),0xff);
              _vfs_unlock(*(undefined4 *)(*(int *)((int)register0x00000038 + -0x174) + 0x24));
              _nfs_netboot_prealloc(*(undefined4 *)(param_1 + 0x128));
              _pn_free((undefined *)((int)register0x00000038 + -0x150));
              puVar3 = (char *)0x0;
              goto locret_F003DD34;
            }
            sub_F003EAF0(param_2);
            puVar3 = pcVar7;
          }
          _pn_free((undefined *)((int)register0x00000038 + -0x150));
          _kfree(param_2,300);
          goto locret_F003DD34;
        }
        _printf(aNfsMountrootNo);
        _vn_rele(*(undefined4 *)(_active_u + 0x15c));
      }
      else if (puVar3 == (char *)0x16) {
        _printf(aUsingPrivateFr);
        puVar3 = (char *)0x0;
      }
      else {
        _printf(aRpcErrorDuring_0,puVar3);
      }
    }
  }
  else {
    _printf(aRpcErrorDuring,puVar3);
  }
  _pn_free((undefined *)((int)register0x00000038 + -0x150));
locret_F003DD34:
  return CONCAT44(param_2,puVar3);
}
