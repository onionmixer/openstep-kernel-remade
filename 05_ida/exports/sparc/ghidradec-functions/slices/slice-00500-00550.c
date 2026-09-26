/* GHIDRADEC_FUNCTION index=500 start=0xf0023d48 */

/* WARNING: Removing unreachable block (ram,0xf0023f40) */
/* WARNING: Removing unreachable block (ram,0xf0023f14) */
/* WARNING: Removing unreachable block (ram,0xf0023e8c) */
/* WARNING: Removing unreachable block (ram,0xf0023d68) */
/* WARNING: Removing unreachable block (ram,0xf0023e80) */
/* WARNING: Removing unreachable block (ram,0xf0023ec0) */
/* WARNING: Removing unreachable block (ram,0xf0023f34) */
/* WARNING: Removing unreachable block (ram,0xf0023f78) */
/* WARNING: Removing unreachable block (ram,0xf0023d50) */

undefined8 _vfs_mountroot(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  undefined4 unaff_l0;
  int *piVar4;
  undefined4 unaff_l1;
  undefined4 *puVar5;
  undefined4 unaff_l3;
  undefined *puVar6;
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
  bool bVar7;
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
  puVar5 = (undefined4 *)0x0;
  puVar2 = (undefined4 *)0x12c;
  _kalloc();
  puVar6 = (undefined *)&_rootfs;
  _rootvfs = puVar2;
  _vfssw_lookup();
  puVar2 = _rootvfs;
  if ((undefined5 *)puVar6 == (undefined5 *)0x0) {
    puVar6 = _vfssw;
    bVar7 = true;
    if (_vfsNVFS <= _vfssw) goto loc_F0023E74;
    piVar4 = (int *)(_vfssw + 4);
    puVar2 = puVar5;
    do {
      puVar5 = _rootvfs;
      if (*piVar4 != 0) {
        *_rootvfs = 0;
        puVar5[1] = *piVar4;
        puVar5[3] = 0;
        puVar5[7] = 0;
        puVar5[0x4a] = 0;
        puVar5[0x48] = 0;
        *(undefined2 *)(puVar5 + 0x49) = *(undefined2 *)(*(int *)(_active_u + 0x1c) + 2);
        (**(code **)(puVar5[1] + 0x18))(puVar5,&_rootvp,DAT_f01352f0);
        bVar7 = true;
        puVar2 = puVar5;
        if (puVar5 == (undefined4 *)0x0) goto loc_F0023E74;
      }
      puVar6 = (undefined *)((int)puVar6 + 8);
      piVar4 = piVar4 + 2;
      puVar5 = puVar2;
    } while (puVar6 < _vfsNVFS);
  }
  else {
    *_rootvfs = 0;
    puVar2[1] = *(undefined4 *)((int)puVar6 + 4);
    puVar2[3] = 0;
    puVar2[7] = 0;
    puVar2[0x4a] = 0;
    puVar2[0x48] = 0;
    *(undefined2 *)(puVar2 + 0x49) = *(undefined2 *)(*(int *)(_active_u + 0x1c) + 2);
    (**(code **)(puVar2[1] + 0x18))(puVar2,&_rootvp,DAT_f01352f0);
    puVar5 = puVar2;
  }
  bVar7 = puVar5 == (undefined4 *)0x0;
loc_F0023E74:
  if (!bVar7) {
    _printf(aVfsMountrootEr,puVar5);
    _panic(aVfsMountrootCa);
  }
  puVar2 = _rootvfs;
  (**(code **)(_rootvfs[1] + 8))(_rootvfs,&_rootdir);
  if (puVar2 != (undefined4 *)0x0) {
    _panic(aVfsMountrootCa_0);
  }
  *(int *)(_active_u + 0x15c) = _rootdir;
  *(sword *)(*(int *)(_active_u + 0x15c) + 6) = *(sword *)(*(int *)(_active_u + 0x15c) + 6) + 1;
  *(undefined4 *)(_active_u + 0x160) = 0;
  puVar3 = _rootname;
  if ((_rootname[0] != '\0') &&
     (_lookupname(_rootname,1,1,0,(undefined *)((int)register0x00000038 + -0xc)),
     puVar3 == (undefined *)0x0)) {
    _rootdir = *(int *)((int)register0x00000038 + -0xc);
    _vn_rele(*(undefined4 *)(_active_u + 0x15c));
    _vn_rele(*(undefined4 *)(_active_u + 0x15c));
    iVar1 = _rootdir;
    *(int *)(_active_u + 0x15c) = _rootdir;
    *(sword *)(iVar1 + 6) = *(sword *)(iVar1 + 6) + 1;
  }
  DAT_f0135378._0_4_ = _rootvp;
  _strcpy(&_rootfs,*(undefined4 *)puVar6);
  DAT_f0135374._0_4_ = 0;
  DAT_f0135370._0_4_ = 1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=501 start=0xf0023f94 */

/* WARNING: Removing unreachable block (ram,0xf0023fcc) */
/* WARNING: Removing unreachable block (ram,0xf0023ff0) */
/* WARNING: Removing unreachable block (ram,0xf0023f98) */

undefined8 _vfs_add(int param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  puVar2 = param_2;
  _vfs_lock();
  if (puVar2 == (undefined4 *)0x0) {
    if (param_1 == 0) {
      _rootvfs = param_2;
      *param_2 = 0;
    }
    else {
      if (*(int *)(param_1 + 0xc) != 0) {
        _vfs_unlock(param_2);
        puVar2 = (undefined4 *)0x10;
        goto locret_F00240B8;
      }
      if ((param_3 & 0x8000) == 0) {
        *(undefined4 **)(param_1 + 0xc) = param_2;
      }
      else {
        param_2[0x48] = *(undefined4 *)(param_1 + 0x10);
        *(undefined4 **)(param_1 + 0x10) = param_2;
        _microtime(param_1 + 0x14);
      }
      puVar2 = _rootvfs;
      *param_2 = *_rootvfs;
      *puVar2 = param_2;
    }
    param_2[2] = param_1;
    if ((param_3 & 1) == 0) {
      uVar1 = param_2[3] & 0xfffffffe;
    }
    else {
      uVar1 = param_2[3] | 1;
    }
    param_2[3] = uVar1;
    if ((param_3 & 2) == 0) {
      uVar1 = param_2[3] & 0xfffffff7;
    }
    else {
      uVar1 = param_2[3] | 8;
    }
    param_2[3] = uVar1;
    if ((param_3 & 8) == 0) {
      uVar1 = param_2[3] & 0xffffffef;
    }
    else {
      uVar1 = param_2[3] | 0x10;
    }
    param_2[3] = uVar1;
    if ((param_3 & 0x20) == 0) {
      uVar1 = param_2[3] & 0xffffffdf;
    }
    else {
      uVar1 = param_2[3] | 0x20;
    }
    param_2[3] = uVar1;
    puVar2 = (undefined4 *)0x0;
    param_2[3] = param_2[3] & 0xffffff7f;
  }
locret_F00240B8:
  return CONCAT44(param_2,puVar2);
}
/* GHIDRADEC_FUNCTION index=502 start=0xf00240c0 */

/* WARNING: Removing unreachable block (ram,0xf0024170) */
/* WARNING: Removing unreachable block (ram,0xf0024194) */
/* WARNING: Removing unreachable block (ram,0xf0024160) */
/* WARNING: Removing unreachable block (ram,0xf0024178) */
/* WARNING: Removing unreachable block (ram,0xf00240dc) */

undefined8 _vfs_remove(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 unaff_l0;
  undefined4 *puVar5;
  undefined4 unaff_l1;
  int iVar6;
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
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  if (param_1 == _rootvfs) {
    _panic(aVfsRemoveUnmou);
  }
  if (_rootvfs == (undefined4 *)0x0) {
loc_F0024190:
    _panic(aVfsRemoveVfsNo);
  }
  else {
    puVar5 = (undefined4 *)*_rootvfs;
    puVar3 = _rootvfs;
    while (puVar2 = puVar5, puVar2 != param_1) {
      if (puVar2 == (undefined4 *)0x0) goto loc_F0024190;
      puVar3 = puVar2;
      puVar5 = (undefined4 *)*puVar2;
    }
    *puVar3 = *puVar2;
    iVar6 = puVar2[2];
    if (*(int *)(iVar6 + 0xc) == 0) {
      puVar5 = (undefined4 *)(iVar6 + 0x10);
      iVar1 = *(int *)(iVar6 + 0x10);
      while (iVar1 != 0) {
        puVar3 = (undefined4 *)*puVar5;
        if (puVar3 == param_1) {
          puVar3 = (undefined4 *)*puVar5;
          goto loc_F0024154;
        }
        puVar5 = puVar3 + 0x48;
        iVar1 = puVar3[0x48];
      }
      puVar3 = (undefined4 *)*puVar5;
loc_F0024154:
      if (puVar3 == param_1) {
        uVar4 = param_1[0x48];
      }
      else {
        _panic(aVfsRemoveCanTF);
        uVar4 = param_1[0x48];
      }
      *puVar5 = uVar4;
      _microtime(iVar6 + 0x14);
    }
    else {
      *(undefined4 *)(iVar6 + 0xc) = 0;
    }
    _vfs_unlock(param_1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=503 start=0xf00241a4 */

undefined8 _vfs_lock(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  if ((*(uint *)(param_1 + 0xc) & 2) == 0) {
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 2;
    uVar1 = 0;
  }
  else {
    uVar1 = 0x10;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=504 start=0xf00241cc */

/* WARNING: Removing unreachable block (ram,0xf0024208) */
/* WARNING: Removing unreachable block (ram,0xf00241e4) */

undefined8 _vfs_unlock(int param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  if ((*(uint *)(param_1 + 0xc) & 2) == 0) {
    _panic(aVfsUnlock);
    uVar1 = *(uint *)(param_1 + 0xc);
  }
  else {
    uVar1 = *(uint *)(param_1 + 0xc);
  }
  *(uint *)(param_1 + 0xc) = uVar1 & 0xfffffffd;
  if ((uVar1 & 4) != 0) {
    *(uint *)(param_1 + 0xc) = uVar1 & 0xfffffff9;
    _wakeup(param_1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=505 start=0xf0024218 */

undefined8 _getvfs(int *param_1)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  puVar2 = _rootvfs;
  if (_rootvfs != (undefined4 *)0x0) {
    iVar1 = _rootvfs[5];
    do {
      if (iVar1 == *param_1) {
        if (puVar2[6] == param_1[1]) break;
        puVar2 = (undefined4 *)*puVar2;
      }
      else {
        puVar2 = (undefined4 *)*puVar2;
      }
      if (puVar2 == (undefined4 *)0x0) break;
      iVar1 = puVar2[5];
    } while( true );
  }
  return CONCAT44(param_1,puVar2);
}
/* GHIDRADEC_FUNCTION index=506 start=0xf0024274 */

undefined8 _vafsidtovfs(int param_1,int *param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  int *piVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
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
  if (_rootvfs == (int *)0x0) {
    piVar3 = (int *)0x16;
  }
  else {
    iVar1 = _rootvfs[1];
    piVar2 = _rootvfs;
    while (piVar3 = piVar2,
          (**(code **)(iVar1 + 8))(piVar2,(undefined *)((int)register0x00000038 + -0x4c)),
          piVar3 == (int *)0x0) {
      piVar3 = *(int **)((int)register0x00000038 + -0x4c);
      (**(code **)(piVar3[7] + 0x14))
                (piVar3,(undefined *)((int)register0x00000038 + -0x48),
                 *(undefined4 *)(_active_u + 0x1c));
      if (piVar3 != (int *)0x0) break;
      if (param_1 == *(int *)((int)register0x00000038 + -0x3c)) {
        *param_2 = (int)piVar2;
        piVar3 = (int *)0x0;
        break;
      }
      piVar2 = (int *)*piVar2;
      if (piVar2 == (int *)0x0) {
        piVar3 = (int *)0x16;
        break;
      }
      iVar1 = piVar2[1];
    }
  }
  return CONCAT44(param_2,piVar3);
}
/* GHIDRADEC_FUNCTION index=507 start=0xf0024310 */

/* WARNING: Removing unreachable block (ram,0xf00243a4) */
/* WARNING: Removing unreachable block (ram,0xf002438c) */

undefined8 _vfs_getmajor(undefined *param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
  undefined *puVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  iVar3 = 0;
  if (0 < _vfsNVFS + 0xfef4028 >> 3) {
    iVar2 = 0;
    do {
      unk_F012F404[iVar2] =
           unk_F012F404[iVar2] | (byte)(1 << ((char)iVar3 + (char)iVar2 * -8 & 0x1fU));
      iVar3 = iVar3 + 1;
      iVar2 = iVar3 >> 3;
    } while (iVar3 < _vfsNVFS + 0xfef4028 >> 3);
  }
  puVar1 = unk_F012F404;
  _vfs_getnum(unk_F012F404,0x10);
  puVar4 = puVar1 + 0x80;
  if (puVar1 == (undefined *)0xffffffff) {
    _vfs_fixedmajor(param_1);
    puVar4 = param_1;
  }
  return CONCAT44(param_2,puVar4);
}
/* GHIDRADEC_FUNCTION index=508 start=0xf00243b8 */

undefined8 _vfs_fixedmajor(int param_1,undefined *param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  puVar2 = _vfssw;
  if (_vfssw < _vfsNVFS) {
    iVar1 = DAT_f010bfdc._0_4_;
    puVar3 = puVar2;
    while ((puVar2 = puVar3, param_2 = _vfsNVFS, iVar1 != *(int *)(param_1 + 4) &&
           (puVar2 = puVar3 + 8, puVar2 < _vfsNVFS))) {
      iVar1 = *(int *)(puVar3 + 0xc);
      puVar3 = puVar2;
    }
  }
  return CONCAT44(param_2,((int)(puVar2 + 0xfef4028) >> 3) + 0x80);
}
/* GHIDRADEC_FUNCTION index=509 start=0xf0024418 */

/* WARNING: Removing unreachable block (ram,0xf0024448) */

undefined8 _vfs_putmajor(int param_1,int param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  param_2 = param_2 + -0x80;
  if (*(int *)(param_1 + 4) != *(int *)(DAT_f010bfdc + param_2 * 8)) {
    _vfs_putnum(unk_F012F404,param_2);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=510 start=0xf0024458 */

undefined8 _vfs_getnum(byte *param_1,int param_2)

{
  byte bVar1;
  byte *pbVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  byte *pbVar4;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  pbVar2 = param_1 + param_2;
  iVar3 = -1;
  if (param_1 < pbVar2) {
    bVar1 = *param_1;
    pbVar4 = param_1;
    while( true ) {
      if (bVar1 != 0xff) {
        param_2 = 0;
        bVar1 = *pbVar4;
        while( true ) {
          if (((int)(char)bVar1 >> ((byte)param_2 & 0x1f) & 1U) == 0) {
            *pbVar4 = bVar1 | (byte)(1 << ((byte)param_2 & 0x1f));
            iVar3 = ((int)pbVar4 - (int)param_1) * 8 + param_2;
            goto locret_F00244E0;
          }
          param_2 = param_2 + 1;
          if (7 < param_2) break;
          bVar1 = *pbVar4;
        }
      }
      pbVar4 = pbVar4 + 1;
      if (pbVar2 <= pbVar4) break;
      bVar1 = *pbVar4;
    }
    iVar3 = -1;
  }
locret_F00244E0:
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=511 start=0xf00244e8 */

undefined8 _vfs_putnum(int param_1,uint param_2)

{
  char cVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  iVar2 = param_1;
  if (-1 < (int)param_2) {
    iVar2 = (int)param_2 >> 3;
    cVar1 = (char)param_2;
    param_2 = (uint)*(byte *)(param_1 + iVar2);
    *(byte *)(param_1 + iVar2) =
         *(byte *)(param_1 + iVar2) & ~(byte)(1 << (cVar1 + (char)iVar2 * -8 & 0x1fU));
  }
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=512 start=0xf0024520 */

/* WARNING: Removing unreachable block (ram,0xf0024598) */
/* WARNING: Removing unreachable block (ram,0xf0024554) */
/* WARNING: Removing unreachable block (ram,0xf00245c8) */
/* WARNING: Removing unreachable block (ram,0xf0024544) */

undefined8 _bread(uint *param_1,undefined4 param_2,int param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  _bstats = _bstats + 1;
  if (param_3 == 0) {
    _panic(aBreadSize0);
  }
  _getblk(param_1,param_2,param_3);
  if ((*param_1 & 2) == 0) {
    *param_1 = *param_1 | 1;
    if ((int)param_1[6] < (int)param_1[5]) {
      _panic(&aBread);
    }
    (**(code **)(*(int *)(param_1[0x10] + 0x1c) + 0x54))(param_1);
    *(int *)(_active_u + 0x198) = *(int *)(_active_u + 0x198) + 1;
    _biowait(param_1);
  }
  else {
    DAT_f01353b4._0_4_ = DAT_f01353b4._0_4_ + 1;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=513 start=0xf00245d8 */

/* WARNING: Removing unreachable block (ram,0xf0024754) */
/* WARNING: Removing unreachable block (ram,0xf00246d0) */
/* WARNING: Removing unreachable block (ram,0xf0024698) */
/* WARNING: Removing unreachable block (ram,0xf0024618) */
/* WARNING: Removing unreachable block (ram,0xf0024650) */
/* WARNING: Removing unreachable block (ram,0xf00246b4) */
/* WARNING: Removing unreachable block (ram,0xf0024708) */
/* WARNING: Removing unreachable block (ram,0xf0024744) */
/* WARNING: Removing unreachable block (ram,0xf00245fc) */

undefined8
_breada(uint *param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  uint *puVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint *puVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  puVar2 = (uint *)0x0;
  DAT_f01353b8._0_4_ = DAT_f01353b8._0_4_ + 1;
  puVar1 = param_1;
  _incore(param_1,param_2);
  if (puVar1 == (uint *)0x0) {
    puVar2 = param_1;
    _getblk(param_1,param_2,param_3);
    if ((*puVar2 & 2) == 0) {
      *puVar2 = *puVar2 | 1;
      if ((int)puVar2[6] < (int)puVar2[5]) {
        _panic(&aBreada);
      }
      (**(code **)(*(int *)(puVar2[0x10] + 0x1c) + 0x54))(puVar2);
      *(int *)(_active_u + 0x198) = *(int *)(_active_u + 0x198) + 1;
    }
    else {
      DAT_f01353b8._4_4_ = DAT_f01353b8._4_4_ + 1;
    }
  }
  if ((param_4 != 0) && (puVar1 = param_1, _incore(param_1,param_4), puVar1 == (uint *)0x0)) {
    puVar1 = param_1;
    _getblk(param_1,param_4,param_5);
    if ((*puVar1 & 2) == 0) {
      *puVar1 = *puVar1 | 0x101;
      if ((int)puVar1[6] < (int)puVar1[5]) {
        _panic(aBreadrabp);
      }
      (**(code **)(*(int *)(puVar1[0x10] + 0x1c) + 0x54))(puVar1);
      *(int *)(_active_u + 0x198) = *(int *)(_active_u + 0x198) + 1;
    }
    else {
      _brelse();
      DAT_f01353b8._8_4_ = DAT_f01353b8._8_4_ + 1;
    }
  }
  if (puVar2 == (uint *)0x0) {
    _bread(param_1,param_2,param_3);
  }
  else {
    _biowait(puVar2);
    param_1 = puVar2;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=514 start=0xf0024768 */

/* WARNING: Removing unreachable block (ram,0xf00247d4) */
/* WARNING: Removing unreachable block (ram,0xf00247dc) */
/* WARNING: Removing unreachable block (ram,0xf00247ac) */

undefined8 _bwrite(uint *param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
  uint uVar2;
  undefined4 unaff_l1;
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
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  uVar2 = *param_1;
  *param_1 = uVar2 & 0xfffffdf8;
  if ((uVar2 & 0x200) == 0) {
    *(int *)(_active_u + 0x19c) = *(int *)(_active_u + 0x19c) + 1;
  }
  if ((int)param_1[6] < (int)param_1[5]) {
    _panic(&aBwrite);
    uVar1 = param_1[0x10];
  }
  else {
    uVar1 = param_1[0x10];
  }
  (**(code **)(*(int *)(uVar1 + 0x1c) + 0x54))(param_1);
  if ((uVar2 & 0x100) == 0) {
    _biowait(param_1);
    _brelse(param_1);
  }
  else if ((uVar2 & 0x200) != 0) {
    *param_1 = *param_1 | 0x80;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=515 start=0xf0024804 */

/* WARNING: Removing unreachable block (ram,0xf0024838) */

undefined8 _bdwrite(uint *param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  if ((*param_1 & 0x200) == 0) {
    *(int *)(_active_u + 0x19c) = *(int *)(_active_u + 0x19c) + 1;
    uVar1 = *param_1;
  }
  else {
    uVar1 = *param_1;
  }
  *param_1 = uVar1 | 0x202;
  _brelse();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=516 start=0xf0024848 */

/* WARNING: Removing unreachable block (ram,0xf0024858) */

undefined8 _bawrite(uint *param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  *param_1 = *param_1 | 0x100;
  _bwrite();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=517 start=0xf0024868 */

/* WARNING: Removing unreachable block (ram,0xf0024900) */
/* WARNING: Removing unreachable block (ram,0xf00248a0) */
/* WARNING: Removing unreachable block (ram,0xf00248f8) */
/* WARNING: Removing unreachable block (ram,0xf00249bc) */
/* WARNING: Removing unreachable block (ram,0xf002487c) */

undefined8 _brelse(uint *param_1,undefined4 param_2)

{
  uint *puVar1;
  uint uVar2;
  undefined *puVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  if ((*param_1 & 0x40) != 0) {
    _wakeup(param_1);
  }
  if ((_bfreelist & 0x40) != 0) {
    _bfreelist = _bfreelist & 0xffffffbf;
    _wakeup(&_bfreelist);
  }
  if ((*param_1 & 0x400200) == 0x400000) {
    *param_1 = *param_1 | 0x10000;
    uVar2 = *param_1;
  }
  else {
    uVar2 = *param_1;
  }
  puVar1 = (uint *)0x20000;
  if ((uVar2 & 4) != 0) {
    puVar1 = (uint *)(uVar2 & 0xfffffffb);
    if ((uVar2 & 0x20000) == 0) {
      puVar1 = param_1;
      sub_F0025690(param_1);
    }
    else {
      *param_1 = (uint)puVar1;
    }
  }
  _splusclock();
  if ((int)param_1[6] < 1) {
    puVar3 = unk_F0133EAC;
  }
  else {
    uVar2 = *param_1;
    if ((uVar2 & 0x10004) == 0) {
      if ((uVar2 & 0x20000) == 0) {
        if ((uVar2 & 0x80) == 0) {
          puVar3 = unk_F0133E24;
        }
        else {
          puVar3 = unk_F0133E68;
        }
      }
      else {
        puVar3 = (undefined *)&_bfreelist;
      }
      *(uint **)(*(int *)((int)puVar3 + 0x10) + 0xc) = param_1;
      param_1[4] = *(uint *)((int)puVar3 + 0x10);
      *(uint **)((int)puVar3 + 0x10) = param_1;
      param_1[3] = (uint)puVar3;
      goto loc_F00249A8;
    }
    puVar3 = unk_F0133E68;
  }
  *(uint **)(*(int *)(puVar3 + 0xc) + 0x10) = param_1;
  param_1[3] = *(uint *)(puVar3 + 0xc);
  *(uint **)(puVar3 + 0xc) = param_1;
  param_1[4] = (uint)puVar3;
loc_F00249A8:
  *param_1 = *param_1 & 0xffbffe37;
  _splx(puVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=518 start=0xf00249cc */

undefined8 _incore(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint *puVar4;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  uVar1 = param_2;
  if ((int)param_2 < 0) {
    uVar1 = param_2 + 7;
  }
  iVar2 = (param_1 + ((int)uVar1 >> 3) & 0xf) * 0xc;
  puVar4 = *(uint **)(_bufhash + iVar2 + 4);
  if (puVar4 == (uint *)(_bufhash + iVar2)) {
    uVar3 = 0;
  }
  else {
    uVar1 = puVar4[9];
    while( true ) {
      if (uVar1 == param_2) {
        if (puVar4[0x10] == param_1) {
          if ((*puVar4 & 0x10000) == 0) {
            uVar3 = 1;
            goto locret_F0024A60;
          }
          puVar4 = (uint *)puVar4[1];
        }
        else {
          puVar4 = (uint *)puVar4[1];
        }
      }
      else {
        puVar4 = (uint *)puVar4[1];
      }
      if (puVar4 == (uint *)(_bufhash + iVar2)) break;
      uVar1 = puVar4[9];
    }
    uVar3 = 0;
  }
locret_F0024A60:
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=519 start=0xf0024a68 */

/* WARNING: Removing unreachable block (ram,0xf0024bf4) */
/* WARNING: Removing unreachable block (ram,0xf0024bc8) */
/* WARNING: Removing unreachable block (ram,0xf0024b7c) */
/* WARNING: Removing unreachable block (ram,0xf0024b4c) */
/* WARNING: Removing unreachable block (ram,0xf0024b34) */
/* WARNING: Removing unreachable block (ram,0xf0024a94) */
/* WARNING: Removing unreachable block (ram,0xf0024b10) */
/* WARNING: Removing unreachable block (ram,0xf0024b3c) */
/* WARNING: Removing unreachable block (ram,0xf0024b54) */
/* WARNING: Removing unreachable block (ram,0xf0024b94) */
/* WARNING: Removing unreachable block (ram,0xf0024bd0) */
/* WARNING: Removing unreachable block (ram,0xf0024c2c) */
/* WARNING: Removing unreachable block (ram,0xf0024a88) */

undefined8 _getblk(uint *param_1,uint *param_2,uint param_3)

{
  uint *puVar1;
  undefined *puVar2;
  uint *puVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint *puVar5;
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
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  if (param_1 == (uint *)0x0) {
    _printf(aVp0xXBlkno0xXS,0,param_2,param_3);
    _panic(aGetblkIllegalV);
  }
  puVar1 = param_2;
  if ((int)param_2 < 0) {
    puVar1 = (uint *)((int)param_2 + 7);
  }
  iVar4 = ((uint)((int)param_1 + ((int)puVar1 >> 3)) & 0xf) * 0xc;
  puVar2 = _bufhash;
  puVar5 = (uint *)(_bufhash + iVar4);
  puVar1 = *(uint **)(_bufhash + iVar4 + 4);
loc_F0024AD4:
  do {
    if (puVar1 != puVar5) {
      puVar2 = (undefined *)puVar1[9];
      while( true ) {
        if ((uint *)puVar2 == param_2) {
          puVar2 = (undefined *)puVar1[0x10];
          if ((uint *)puVar2 == param_1) {
            puVar2 = (undefined *)*puVar1;
            if (((uint)puVar2 & 0x10000) == 0) {
              _splusclock();
              if ((*puVar1 & 8) != 0) {
                *puVar1 = *puVar1 | 0x40;
                _sleep(puVar1,0x15);
                _splx();
                puVar1 = *(uint **)(_bufhash + iVar4 + 4);
                goto loc_F0024AD4;
              }
              _splx(puVar2);
              _spltty();
              *(uint *)(puVar1[4] + 0xc) = puVar1[3];
              *(uint *)(puVar1[3] + 0x10) = puVar1[4];
              *puVar1 = *puVar1 | 8;
              _splx();
              if ((puVar1[5] == param_3) ||
                 (puVar3 = puVar1, _brealloc(puVar1,param_3), puVar3 != (uint *)0x0)) {
                *puVar1 = *puVar1 | 0x8000;
                goto locret_F0024C40;
              }
              puVar1 = *(uint **)(_bufhash + iVar4 + 4);
              puVar2 = (undefined *)0x0;
              goto loc_F0024AD4;
            }
            puVar1 = (uint *)puVar1[1];
          }
          else {
            puVar1 = (uint *)puVar1[1];
          }
        }
        else {
          puVar1 = (uint *)puVar1[1];
        }
        if (puVar1 == puVar5) break;
        puVar2 = (undefined *)puVar1[9];
      }
    }
    _getnewbuf();
    _bfree();
    *(uint *)(*(uint *)((int)puVar2 + 8) + 4) = *(uint *)((int)puVar2 + 4);
    *(uint *)(*(uint *)((int)puVar2 + 4) + 8) = *(uint *)((int)puVar2 + 8);
    sub_F002565C(puVar2,param_1);
    *(undefined2 *)((int)puVar2 + 0x1e) = *(undefined2 *)(param_1 + 0xb);
    *(uint **)((int)puVar2 + 0x24) = param_2;
    *(undefined2 *)((int)puVar2 + 0x1c) = 0;
    *(uint *)((int)puVar2 + 0x28) = 0;
    *(uint *)((int)puVar2 + 4) = *(uint *)(_bufhash + iVar4 + 4);
    *(uint **)((int)puVar2 + 8) = puVar5;
    *(undefined **)(*(int *)(_bufhash + iVar4 + 4) + 8) = puVar2;
    *(undefined **)(_bufhash + iVar4 + 4) = puVar2;
    puVar3 = (uint *)puVar2;
    _brealloc(puVar2,param_3);
    puVar1 = (uint *)puVar2;
    if (puVar3 != (uint *)0x0) {
locret_F0024C40:
      return CONCAT44(param_2,puVar1);
    }
    puVar1 = *(uint **)(_bufhash + iVar4 + 4);
    puVar2 = (undefined *)0x0;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=520 start=0xf0024c48 */

/* WARNING: Removing unreachable block (ram,0xf0024ca4) */
/* WARNING: Removing unreachable block (ram,0xf0024c68) */
/* WARNING: Removing unreachable block (ram,0xf0024c80) */
/* WARNING: Removing unreachable block (ram,0xf0024cd0) */
/* WARNING: Removing unreachable block (ram,0xf0024c60) */

undefined8 _geteblk(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  uint *puVar2;
  uint *puVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  puVar1 = (undefined *)(uint *)0xf010bc00;
  if (0x2000 < param_1) {
    puVar1 = aGeteblkSizeToo;
    _panic();
  }
  do {
    puVar2 = (uint *)puVar1;
    _getnewbuf();
    *puVar2 = *puVar2 | 0x10000;
    _bfree();
    *(uint *)(puVar2[2] + 4) = puVar2[1];
    *(uint *)(puVar2[1] + 8) = puVar2[2];
    sub_F0025690(puVar2);
    *(undefined2 *)(puVar2 + 7) = 0;
    puVar2[10] = 0;
    puVar2[1] = DAT_f0133e6c._0_4_;
    puVar2[2] = (uint)unk_F0133E68;
    *(uint **)(DAT_f0133e6c._0_4_ + 8) = puVar2;
    puVar3 = puVar2;
    DAT_f0133e6c._0_4_ = puVar2;
    _brealloc(puVar2,param_1);
    puVar1 = (undefined *)(uint *)0x0;
  } while (puVar3 == (uint *)0x0);
  return CONCAT44(param_2,puVar2);
}
/* GHIDRADEC_FUNCTION index=521 start=0xf0024cec */

/* WARNING: Removing unreachable block (ram,0xf0024f08) */
/* WARNING: Removing unreachable block (ram,0xf0024eec) */
/* WARNING: Removing unreachable block (ram,0xf0024ed0) */
/* WARNING: Removing unreachable block (ram,0xf0024ea0) */
/* WARNING: Removing unreachable block (ram,0xf0024d70) */
/* WARNING: Removing unreachable block (ram,0xf0024e70) */
/* WARNING: Removing unreachable block (ram,0xf0024dc8) */
/* WARNING: Removing unreachable block (ram,0xf0024e88) */
/* WARNING: Removing unreachable block (ram,0xf0024d78) */
/* WARNING: Removing unreachable block (ram,0xf0024ea8) */
/* WARNING: Removing unreachable block (ram,0xf0024d88) */
/* WARNING: Removing unreachable block (ram,0xf0024d3c) */
/* WARNING: Removing unreachable block (ram,0xf0024d14) */
/* WARNING: Removing unreachable block (ram,0xf0024db8) */

undefined8 _brealloc(uint *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 unaff_l0;
  uint *puVar6;
  undefined4 unaff_l1;
  uint uVar7;
  uint uVar8;
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
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  if (param_2 == param_1[5]) {
    param_1 = (uint *)0x1;
  }
  else {
    uVar2 = *param_1;
    if ((uVar2 & 0x200) == 0) {
      if ((int)param_2 < (int)param_1[5]) {
        if ((uVar2 & 0x20000) != 0) {
          _panic(aBrealloc);
        }
      }
      else {
        uVar5 = param_1[0x10];
        *param_1 = uVar2 & 0xfffffffd;
        if (uVar5 != 0) {
          (**(code **)(*(int *)(uVar5 + 0x1c) + 0x80))();
          if ((int)uVar5 < 0) {
            _panic(aCouldnTDetermi);
          }
          uVar8 = param_1[9];
          uVar2 = param_2;
          .div(param_2,uVar5);
          uVar3 = uVar8;
          if ((int)uVar8 < 0) {
            uVar3 = uVar8 + 7;
          }
          iVar4 = (param_1[0x10] + ((int)uVar3 >> 3) & 0xf) * 0xc;
          puVar6 = *(uint **)(_bufhash + iVar4 + 4);
loc_F0024E10:
          if (puVar6 != (uint *)(_bufhash + iVar4)) {
            iVar1 = (int)puVar6 - (int)param_1;
            do {
              if (iVar1 == 0) {
                puVar6 = (uint *)puVar6[1];
              }
              else if (puVar6[0x10] == param_1[0x10]) {
                if ((*puVar6 & 0x10000) == 0) {
                  uVar3 = puVar6[5];
                  if (uVar3 == 0) {
                    puVar6 = (uint *)puVar6[1];
                  }
                  else {
                    uVar7 = puVar6[9];
                    if ((int)(uVar8 + uVar2 + -1) < (int)uVar7) {
                      puVar6 = (uint *)puVar6[1];
                    }
                    else {
                      .div(uVar3,uVar5);
                      iVar1 = uVar7 + uVar3;
                      if ((int)uVar8 < iVar1) {
                        _splusclock();
                        if ((*puVar6 & 8) != 0) {
                          *puVar6 = *puVar6 | 0x40;
                          _sleep(puVar6,0x15);
                          _splx(iVar1);
                          puVar6 = *(uint **)(_bufhash + iVar4 + 4);
                          goto loc_F0024E10;
                        }
                        _splx();
                        _spltty();
                        *(uint *)(puVar6[4] + 0xc) = puVar6[3];
                        *(uint *)(puVar6[3] + 0x10) = puVar6[4];
                        *puVar6 = *puVar6 | 8;
                        _splx();
                        if ((*puVar6 & 0x200) != 0) goto loc_F0024D88;
                        *puVar6 = *puVar6 | 0x10000;
                        _brelse(puVar6);
                        puVar6 = (uint *)puVar6[1];
                      }
                      else {
                        puVar6 = (uint *)puVar6[1];
                      }
                    }
                  }
                }
                else {
                  puVar6 = (uint *)puVar6[1];
                }
              }
              else {
                puVar6 = (uint *)puVar6[1];
              }
              iVar1 = (int)puVar6 - (int)param_1;
              if (puVar6 == (uint *)(_bufhash + iVar4)) break;
            } while( true );
          }
        }
      }
      _allocbuf(param_1,param_2);
    }
    else {
      _bwrite(param_1);
      param_1 = (uint *)0x0;
    }
  }
  return CONCAT44(param_2,param_1);
loc_F0024D88:
  _bwrite(puVar6);
  puVar6 = *(uint **)(_bufhash + iVar4 + 4);
  goto loc_F0024E10;
}
/* GHIDRADEC_FUNCTION index=522 start=0xf0024f1c */

/* WARNING: Removing unreachable block (ram,0xf0024f80) */
/* WARNING: Removing unreachable block (ram,0xf0024fc4) */
/* WARNING: Removing unreachable block (ram,0xf0024f94) */
/* WARNING: Removing unreachable block (ram,0xf0024f9c) */
/* WARNING: Removing unreachable block (ram,0xf0024fe0) */
/* WARNING: Removing unreachable block (ram,0xf0024f88) */
/* WARNING: Removing unreachable block (ram,0xf0024f20) */

undefined8 _getnewbuf(uint *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  while( true ) {
    while( true ) {
      _splusclock();
      puVar1 = (undefined4 *)DAT_f0133e74._0_4_;
      puVar2 = (undefined4 *)unk_F0133E68;
      while ((puVar3 = puVar2, puVar1 == puVar2 && (puVar3 = puVar2 + -0x11, &_bfreelist < puVar3)))
      {
        puVar1 = (undefined4 *)puVar2[-0xe];
        puVar2 = puVar3;
      }
      if (puVar3 != &_bfreelist) break;
      _bfreelist = _bfreelist | 0x40;
      _sleep(&_bfreelist,0x15);
      _splx(param_1);
    }
    _splx(param_1);
    param_1 = (uint *)puVar3[3];
    _spltty();
    *(uint *)(param_1[4] + 0xc) = param_1[3];
    *(uint *)(param_1[3] + 0x10) = param_1[4];
    *param_1 = *param_1 | 8;
    _splx();
    if ((*param_1 & 0x200) == 0) break;
    *param_1 = *param_1 | 0x100;
    _bwrite();
  }
  *param_1 = 8;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=523 start=0xf0024ffc */

/* WARNING: Removing unreachable block (ram,0xf0025050) */
/* WARNING: Removing unreachable block (ram,0xf0025000) */

undefined8 _getnewbuf_count(undefined4 param_1,undefined4 param_2)

{
  undefined3 *puVar1;
  undefined3 *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  iVar3 = 0;
  _spltty();
  puVar2 = (undefined3 *)DAT_f0133e74._0_4_;
  puVar1 = (undefined3 *)unk_F0133E68;
  while( true ) {
    for (; puVar2 != puVar1; puVar2 = *(undefined3 **)(puVar2 + 3)) {
      iVar3 = iVar3 + 1;
    }
    if (puVar1 + -0x11 < &DAT_f0133de1) break;
    puVar2 = *(undefined3 **)(puVar1 + -0xe);
    puVar1 = puVar1 + -0x11;
  }
  _splx();
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=524 start=0xf0025060 */

/* WARNING: Removing unreachable block (ram,0xf0025098) */
/* WARNING: Removing unreachable block (ram,0xf0025080) */
/* WARNING: Removing unreachable block (ram,0xf00250b8) */
/* WARNING: Removing unreachable block (ram,0xf0025064) */

undefined8 _biowait(uint *param_1,undefined4 param_2)

{
  uint *puVar1;
  uint uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  puVar1 = param_1;
  _splusclock();
  uVar2 = *param_1;
  while ((uVar2 & 2) == 0) {
    _sleep(param_1,0x14);
    uVar2 = *param_1;
  }
  _splx(puVar1);
  if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
    puVar1 = param_1;
    _geterror();
    *(char *)(dword_F0133DDC + 0x38) = (char)puVar1;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=525 start=0xf00250d0 */

/* WARNING: Removing unreachable block (ram,0xf0025138) */
/* WARNING: Removing unreachable block (ram,0xf0025128) */
/* WARNING: Removing unreachable block (ram,0xf00250e4) */

undefined8 _biodone(uint *param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  if ((*param_1 & 2) != 0) {
    _panic(aDupBiodone);
  }
  uVar1 = *param_1;
  *param_1 = uVar1 | 2;
  if ((uVar1 & 0x200000) == 0) {
    if ((uVar1 & 0x100) == 0) {
      *param_1 = uVar1 & 0xffffffbf | 2;
      _wakeup(param_1);
    }
    else {
      _brelse(param_1);
    }
  }
  else {
    *param_1 = uVar1 & 0xffdfffff | 2;
    (*(code *)param_1[0xc])(param_1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=526 start=0xf0025148 */

/* WARNING: Removing unreachable block (ram,0xf00252a4) */
/* WARNING: Removing unreachable block (ram,0xf0025274) */
/* WARNING: Removing unreachable block (ram,0xf0025250) */
/* WARNING: Removing unreachable block (ram,0xf0025224) */
/* WARNING: Removing unreachable block (ram,0xf0025178) */
/* WARNING: Removing unreachable block (ram,0xf002520c) */
/* WARNING: Removing unreachable block (ram,0xf0025248) */
/* WARNING: Removing unreachable block (ram,0xf002526c) */
/* WARNING: Removing unreachable block (ram,0xf002529c) */
/* WARNING: Removing unreachable block (ram,0xf00252b4) */
/* WARNING: Removing unreachable block (ram,0xf002516c) */

undefined8 _blkflush(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
  uint uVar5;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint *puVar6;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  uVar1 = param_1;
  (**(code **)(*(int *)(param_1 + 0x1c) + 0x80))();
  if ((int)uVar1 < 0) {
    _panic(aCouldnTDetermi_0);
  }
  .udiv(param_3,uVar1);
  iVar4 = param_2;
  if (param_2 < 0) {
    iVar4 = param_2 + 7;
  }
  iVar4 = (param_1 + (iVar4 >> 3) & 0xf) * 0xc;
  puVar6 = *(uint **)(_bufhash + iVar4 + 4);
loc_F00251BC:
  if (puVar6 == (uint *)(_bufhash + iVar4)) {
locret_F00252CC:
    return CONCAT44(param_2,param_1);
  }
  uVar2 = puVar6[0x10];
  do {
    if (uVar2 == param_1) {
      if ((*puVar6 & 0x10000) == 0) {
        uVar2 = puVar6[5];
        if (uVar2 == 0) {
          puVar6 = (uint *)puVar6[1];
        }
        else {
          uVar5 = puVar6[9];
          if (param_2 + param_3 + -1 < (int)uVar5) {
            puVar6 = (uint *)puVar6[1];
          }
          else {
            .div(uVar2,uVar1);
            iVar3 = uVar5 + uVar2;
            if (param_2 < iVar3) {
              _splusclock();
              uVar2 = *puVar6;
              if ((uVar2 & 8) != 0) {
                *puVar6 = uVar2 | 0x40;
                _sleep(puVar6,0x15);
                _splx(iVar3);
                puVar6 = *(uint **)(_bufhash + iVar4 + 4);
                goto loc_F00251BC;
              }
              if ((uVar2 & 0x200) != 0) break;
              _splx(iVar3);
              puVar6 = (uint *)puVar6[1];
            }
            else {
              puVar6 = (uint *)puVar6[1];
            }
          }
        }
      }
      else {
        puVar6 = (uint *)puVar6[1];
      }
    }
    else {
      puVar6 = (uint *)puVar6[1];
    }
    if (puVar6 == (uint *)(_bufhash + iVar4)) goto locret_F00252CC;
    uVar2 = puVar6[0x10];
  } while( true );
  _splx(iVar3);
  _spltty();
  *(uint *)(puVar6[4] + 0xc) = puVar6[3];
  *(uint *)(puVar6[3] + 0x10) = puVar6[4];
  *puVar6 = *puVar6 | 8;
  _splx();
  _bwrite(puVar6);
  puVar6 = *(uint **)(_bufhash + iVar4 + 4);
  goto loc_F00251BC;
}
/* GHIDRADEC_FUNCTION index=527 start=0xf00252d4 */

/* WARNING: Removing unreachable block (ram,0xf00253a0) */
/* WARNING: Removing unreachable block (ram,0xf0025390) */
/* WARNING: Removing unreachable block (ram,0xf0025368) */
/* WARNING: Removing unreachable block (ram,0xf0025398) */
/* WARNING: Removing unreachable block (ram,0xf00253c8) */
/* WARNING: Removing unreachable block (ram,0xf00252d8) */

undefined8 _bflush(uint *param_1,undefined4 param_2,word param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 unaff_l0;
  uint *puVar4;
  undefined4 unaff_l1;
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
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  puVar1 = param_1;
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
    puVar1 = param_1;
  }
loc_F00252D8:
  _splusclock();
  puVar4 = (uint *)DAT_f0133dec._0_4_;
  puVar2 = &_bfreelist;
joined_r0xf002530c:
  do {
    while( true ) {
      while (puVar4 == puVar2) {
        if (&DAT_f0133eab < puVar2 + 0x11) {
          _splx(param_1);
          return CONCAT44(param_2,puVar1);
        }
        puVar4 = (uint *)puVar2[0x14];
        puVar2 = puVar2 + 0x11;
      }
      if ((word)param_2 == 0xffff) break;
      if ((word)param_2 == (*(word *)((int)puVar4 + 0x1e) & param_3)) {
        uVar3 = *puVar4;
        goto loc_F0025340;
      }
      puVar4 = (uint *)puVar4[3];
    }
    uVar3 = *puVar4;
loc_F0025340:
    if ((uVar3 & 0x200) == 0) {
      puVar4 = (uint *)puVar4[3];
      goto joined_r0xf002530c;
    }
    if ((puVar1 == (uint *)puVar4[0x10]) || (puVar1 == (uint *)0x0)) break;
    puVar4 = (uint *)puVar4[3];
  } while( true );
  *puVar4 = uVar3 | 0x100;
  _spltty();
  *(uint *)(puVar4[4] + 0xc) = puVar4[3];
  *(uint *)(puVar4[3] + 0x10) = puVar4[4];
  *puVar4 = *puVar4 | 8;
  _splx();
  _splx(param_1);
  _bwrite();
  param_1 = puVar4;
  goto loc_F00252D8;
}
/* GHIDRADEC_FUNCTION index=528 start=0xf00253d8 */

/* WARNING: Removing unreachable block (ram,0xf00253e4) */
/* WARNING: Removing unreachable block (ram,0xf00253dc) */

undefined8 _brelvp_wakeup(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  _brelse(param_1);
  sub_F0025690(param_1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=529 start=0xf00253f4 */

/* WARNING: Removing unreachable block (ram,0xf00254bc) */
/* WARNING: Removing unreachable block (ram,0xf00254a4) */
/* WARNING: Removing unreachable block (ram,0xf0025494) */
/* WARNING: Removing unreachable block (ram,0xf002546c) */
/* WARNING: Removing unreachable block (ram,0xf002549c) */
/* WARNING: Removing unreachable block (ram,0xf00254b4) */
/* WARNING: Removing unreachable block (ram,0xf00254ec) */
/* WARNING: Removing unreachable block (ram,0xf00253f8) */

undefined8 _binvalfree(uint *param_1,undefined4 param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  undefined4 unaff_l0;
  uint *puVar5;
  undefined4 unaff_l1;
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
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  puVar1 = param_1;
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
    puVar1 = param_1;
  }
loc_F00253F8:
  _splusclock();
  puVar4 = &_bfreelist;
  puVar5 = (uint *)DAT_f0133dec._0_4_;
  do {
    if (puVar5 != puVar4) {
      puVar2 = (uint *)puVar5[0x10];
      while( true ) {
        if ((puVar1 == puVar2) || (puVar1 == (uint *)0x0)) {
          uVar3 = *puVar5;
          if ((uVar3 & 0x200) == 0) {
            *puVar5 = uVar3 | 0x10000;
            sub_F0025690(puVar5);
            _splx(param_1);
          }
          else {
            puVar5[0xc] = (uint)_brelvp_wakeup;
            *puVar5 = uVar3 | 0x200100;
            _spltty();
            *(uint *)(puVar5[4] + 0xc) = puVar5[3];
            *(uint *)(puVar5[3] + 0x10) = puVar5[4];
            *puVar5 = *puVar5 | 8;
            _splx();
            _splx(param_1);
            _bwrite();
            param_1 = puVar5;
          }
          goto loc_F00253F8;
        }
        puVar5 = (uint *)puVar5[3];
        if (puVar5 == puVar4) break;
        puVar2 = (uint *)puVar5[0x10];
      }
    }
    if (&DAT_f0133eab < puVar4 + 0x11) {
      _splx(param_1);
      return CONCAT44(param_2,puVar1);
    }
    puVar5 = (uint *)puVar4[0x14];
    puVar4 = puVar4 + 0x11;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=530 start=0xf00254fc */

/* WARNING: Removing unreachable block (ram,0xf0025568) */
/* WARNING: Removing unreachable block (ram,0xf0025560) */
/* WARNING: Removing unreachable block (ram,0xf0025590) */
/* WARNING: Removing unreachable block (ram,0xf0025500) */

undefined8 _btrash(uint param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  uVar1 = param_1;
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
    uVar1 = param_1;
  }
loc_F0025500:
  _splusclock();
  puVar3 = &_bfreelist;
  puVar4 = (uint *)DAT_f0133dec._0_4_;
  do {
    if (puVar4 != puVar3) {
      uVar2 = puVar4[0x10];
      while( true ) {
        if ((uVar1 == uVar2) || (uVar1 == 0)) {
          *puVar4 = *puVar4 & 0xfffffdff | 0x10000;
          sub_F0025690();
          _splx(param_1);
          goto loc_F0025500;
        }
        puVar4 = (uint *)puVar4[3];
        if (puVar4 == puVar3) break;
        uVar2 = puVar4[0x10];
      }
    }
    if (&DAT_f0133eab < puVar3 + 0x11) {
      _splx(param_1);
      return CONCAT44(param_2,uVar1);
    }
    puVar4 = (uint *)puVar3[0x14];
    puVar3 = puVar3 + 0x11;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=531 start=0xf00255a0 */

undefined8 _geterror(uint *param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  iVar1 = 0;
  if (((*param_1 & 4) != 0) && (iVar1 = (int)*(sword *)(param_1 + 7), iVar1 == 0)) {
    iVar1 = 5;
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=532 start=0xf00255d0 */

/* WARNING: Removing unreachable block (ram,0xf0025628) */

undefined8 _binval(uint param_1,undefined4 param_2)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
loc_F00255D8:
  puVar2 = (uint *)DAT_f0133f04._0_4_;
  puVar3 = (uint *)_bufhash;
  do {
    if (puVar2 != puVar3) {
      uVar1 = puVar2[0x10];
      while( true ) {
        if (uVar1 == param_1) {
          if ((*puVar2 & 0x10000) == 0) {
            *puVar2 = *puVar2 | 0x10000;
            sub_F0025690(puVar2);
            goto loc_F00255D8;
          }
          puVar2 = (uint *)puVar2[1];
        }
        else {
          puVar2 = (uint *)puVar2[1];
        }
        if (puVar2 == puVar3) break;
        uVar1 = puVar2[0x10];
      }
    }
    if (DAT_f0133f04 + 0xbb < puVar3 + 3) {
      return CONCAT44(param_2,param_1);
    }
    puVar2 = (uint *)puVar3[4];
    puVar3 = puVar3 + 3;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=533 start=0xf00256b4 */

undefined8 _dnlc_init(int param_1,int param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined *puVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar5;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  dword_F01355D8 = &_nc_lru;
  dword_F01355DC = &_nc_lru;
  iVar5 = 0;
  if (0 < _ncsize) {
    param_2 = 0;
    do {
      param_1 = _ncache;
      puVar1 = dword_F01355D8;
      iVar5 = iVar5 + 1;
      puVar3 = (undefined8 *)(_ncache + param_2);
      puVar2 = puVar3;
      *(undefined8 **)(puVar3 + 1) = dword_F01355D8;
      dword_F01355D8 = puVar2;
      *(undefined8 **)((int)puVar1 + 0xc) = puVar3;
      *(undefined8 **)((int)puVar3 + 0xc) = &_nc_lru;
      *(undefined8 **)((int)puVar3 + 4) = puVar3;
      *(undefined8 **)(param_1 + param_2) = puVar3;
      *(undefined4 *)(puVar3 + 2) = 0;
      *(undefined4 *)((int)puVar3 + 0x14) = 0;
      *(undefined *)((int)puVar3 + 0x44) = 0;
      param_2 = param_2 + 0x48;
    } while (iVar5 < _ncsize);
  }
  iVar5 = 0;
  puVar4 = _nc_hash;
  do {
    *(undefined **)(puVar4 + 4) = puVar4;
    *(undefined **)puVar4 = puVar4;
    iVar5 = iVar5 + 1;
    puVar4 = puVar4 + 8;
  } while (iVar5 < 0x40);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=534 start=0xf002575c */

/* WARNING: Removing unreachable block (ram,0xf00258dc) */
/* WARNING: Removing unreachable block (ram,0xf00258a8) */
/* WARNING: Removing unreachable block (ram,0xf00257cc) */
/* WARNING: Removing unreachable block (ram,0xf0025890) */
/* WARNING: Removing unreachable block (ram,0xf00258c0) */
/* WARNING: Removing unreachable block (ram,0xf0025910) */
/* WARNING: Removing unreachable block (ram,0xf0025774) */

undefined8 _dnlc_enter(int param_1,char *param_2,int param_3,sword *param_4)

{
  char cVar1;
  char cVar2;
  char cVar3;
  int *piVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  if (_doingcache != 0) {
    pcVar5 = param_2;
    _strlen();
    if ((int)pcVar5 < 0x21) {
      cVar1 = (pcVar5 + (int)param_2)[-1];
      cVar2 = *param_2;
      iVar6 = param_1;
      sub_F0025EC0(param_1,param_2,pcVar5,(uint)(pcVar5 + param_1 + (int)cVar2 + (int)cVar1) & 0x3f,
                   param_4);
      piVar4 = dword_F01355D8;
      if (iVar6 == 0) {
        if (dword_F01355D8 == (int *)&_nc_lru) {
          DAT_f0135600._8_4_ = DAT_f0135600._8_4_ + 1;
        }
        else {
          *(int *)(dword_F01355D8[3] + 8) = dword_F01355D8[2];
          *(int *)(piVar4[2] + 0xc) = piVar4[3];
          *(int *)(*piVar4 + 4) = piVar4[1];
          *(int *)piVar4[1] = *piVar4;
          iVar6 = piVar4[4];
          if (piVar4[5] != 0) {
            if (iVar6 != 0) {
              DAT_f0135600._16_4_ = DAT_f0135600._16_4_ + -1;
            }
            if (piVar4[5] == 0) {
              iVar6 = piVar4[4];
            }
            else {
              _vn_rele();
              iVar6 = piVar4[4];
            }
          }
          if (iVar6 == 0) {
            iVar6 = piVar4[0xf];
          }
          else {
            _vn_rele();
            iVar6 = piVar4[0xf];
          }
          if (iVar6 == 0) {
            cVar3 = *(char *)(piVar4 + 0x11);
          }
          else {
            _crfree();
            cVar3 = *(char *)(piVar4 + 0x11);
          }
          if (cVar3 == '\0') {
            piVar4[5] = param_1;
          }
          else {
            _kfree(piVar4[0x10],(int)*(sword *)((int)piVar4 + 0x46));
            piVar4[5] = param_1;
          }
          *(sword *)(param_1 + 6) = *(sword *)(param_1 + 6) + 1;
          piVar4[4] = param_3;
          *(sword *)(param_3 + 6) = *(sword *)(param_3 + 6) + 1;
          *(char *)(piVar4 + 6) = (char)pcVar5;
          _bcopy(param_2,(int)piVar4 + 0x19);
          *(undefined *)(piVar4 + 0x11) = 0;
          *(undefined2 *)((int)piVar4 + 0x46) = 0;
          piVar4[0x10] = 0;
          piVar4[0xf] = (int)param_4;
          if (param_4 != (sword *)0x0) {
            *param_4 = *param_4 + 1;
          }
          iVar6 = dword_F01355DC;
          iVar7 = *(int *)(dword_F01355DC + 8);
          iVar8 = ((uint)(pcVar5 + param_1 + (int)cVar2 + (int)cVar1) & 0x3f) * 8;
          *(int **)(dword_F01355DC + 8) = piVar4;
          piVar4[2] = iVar7;
          *(int **)(iVar7 + 0xc) = piVar4;
          piVar4[3] = iVar6;
          *piVar4 = *(int *)(_nc_hash + iVar8);
          piVar4[1] = (int)(_nc_hash + iVar8);
          *(int **)(*(int *)(_nc_hash + iVar8) + 4) = piVar4;
          *(int **)(_nc_hash + iVar8) = piVar4;
          DAT_f0135600._16_4_ = DAT_f0135600._16_4_ + 1;
          DAT_f01355f8._0_4_ = DAT_f01355f8._0_4_ + 1;
        }
      }
      else {
        DAT_f01355fc._0_4_ = DAT_f01355fc._0_4_ + 1;
      }
    }
    else {
      DAT_f0135600._0_4_ = DAT_f0135600._0_4_ + 1;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=535 start=0xf00259a8 */

/* WARNING: Removing unreachable block (ram,0xf00259ec) */
/* WARNING: Removing unreachable block (ram,0xf00259ac) */

undefined8 _dnlc_lookupSymLink(char *param_1,int param_2)

{
  char *pcVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  pcVar1 = param_1;
  _strlen();
  if ((int)pcVar1 < 0x21) {
    iVar2 = param_2;
    sub_F0025EC0(param_2,param_1,pcVar1,
                 (uint)(pcVar1 + param_2 + (int)*param_1 + (int)(pcVar1 + (int)param_1)[-1]) & 0x3f,
                 0xffffffff);
  }
  else {
    iVar2 = 0;
  }
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=536 start=0xf0025a00 */

/* WARNING: Removing unreachable block (ram,0xf0025a74) */
/* WARNING: Removing unreachable block (ram,0xf0025a54) */
/* WARNING: Removing unreachable block (ram,0xf0025a6c) */
/* WARNING: Removing unreachable block (ram,0xf0025a9c) */
/* WARNING: Removing unreachable block (ram,0xf0025a18) */

undefined8 _dnlc_enterSymLink(int param_1,undefined4 param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  int iVar4;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  iVar4 = param_3[2];
  if ((iVar4 != 0) && (_dnlc_lookupSymLink(param_1,param_2), param_1 != 0)) {
    if (*(char *)(param_1 + 0x44) != '\0') {
      if ((int)*(sword *)(param_1 + 0x46) == param_3[2]) {
        iVar2 = *param_3;
        _bcmp(iVar2,*(undefined4 *)(param_1 + 0x40));
        if (iVar2 == 0) goto locret_F0025AD8;
        uVar1 = *(undefined4 *)(param_1 + 0x40);
      }
      else {
        uVar1 = *(undefined4 *)(param_1 + 0x40);
      }
      _kfree(uVar1,(int)*(sword *)(param_1 + 0x46));
    }
    iVar2 = iVar4;
    _kalloc();
    *(int *)(param_1 + 0x40) = iVar2;
    if (iVar2 != 0) {
      *(undefined *)(param_1 + 0x44) = 1;
      *(sword *)(param_1 + 0x46) = (sword)iVar4;
      _bcopy(*param_3,*(undefined4 *)(param_1 + 0x40),iVar4);
      *(undefined4 *)(*(int *)(param_1 + 0xc) + 8) = *(undefined4 *)(param_1 + 8);
      *(undefined4 *)(*(int *)(param_1 + 8) + 0xc) = *(undefined4 *)(param_1 + 0xc);
      iVar2 = dword_F01355DC;
      iVar3 = *(int *)(dword_F01355DC + 8);
      *(int *)(dword_F01355DC + 8) = param_1;
      *(int *)(param_1 + 8) = iVar3;
      *(int *)(iVar3 + 0xc) = param_1;
      *(int *)(param_1 + 0xc) = iVar2;
    }
  }
locret_F0025AD8:
  return CONCAT44(iVar4,param_1);
}
/* GHIDRADEC_FUNCTION index=537 start=0xf0025ae0 */

/* WARNING: Removing unreachable block (ram,0xf0025b5c) */
/* WARNING: Removing unreachable block (ram,0xf0025b00) */

undefined8 _dnlc_lookup(int *param_1,char *param_2,undefined4 param_3)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  int *piVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar5;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  if (_doingcache == 0) {
    iVar5 = 0;
  }
  else {
    pcVar1 = param_2;
    _strlen();
    if ((int)pcVar1 < 0x21) {
      pcVar2 = pcVar1 + (int)*param_2 + (int)(pcVar1 + (int)param_2)[-1] + (int)param_1;
      sub_F0025EC0(param_1,param_2,pcVar1,(uint)pcVar2 & 0x3f,param_3);
      if (param_1 == (int *)0x0) {
        iVar5 = 0;
        DAT_f01355f4._0_4_ = DAT_f01355f4._0_4_ + 1;
      }
      else {
        _ncstats._0_4_ = _ncstats._0_4_ + 1;
        *(int *)(param_1[3] + 8) = param_1[2];
        *(int *)(param_1[2] + 0xc) = param_1[3];
        iVar5 = dword_F01355DC;
        iVar3 = *(int *)(dword_F01355DC + 8);
        *(int **)(dword_F01355DC + 8) = param_1;
        param_1[2] = iVar3;
        *(int **)(iVar3 + 0xc) = param_1;
        param_1[3] = iVar5;
        if ((undefined *)param_1[1] == _nc_hash + ((uint)pcVar2 & 0x3f) * 8) {
          iVar5 = param_1[4];
        }
        else {
          *(undefined **)(*param_1 + 4) = (undefined *)param_1[1];
          *(int *)param_1[1] = *param_1;
          piVar4 = *(int **)(param_1[1] + 4);
          *param_1 = *piVar4;
          param_1[1] = (int)piVar4;
          *(int **)(*piVar4 + 4) = param_1;
          *piVar4 = (int)param_1;
          iVar5 = param_1[4];
        }
      }
    }
    else {
      iVar5 = 0;
      DAT_f0135604._0_4_ = DAT_f0135604._0_4_ + 1;
    }
  }
  return CONCAT44(param_2,iVar5);
}
/* GHIDRADEC_FUNCTION index=538 start=0xf0025c28 */

/* WARNING: Removing unreachable block (ram,0xf0025c6c) */
/* WARNING: Removing unreachable block (ram,0xf0025c80) */
/* WARNING: Removing unreachable block (ram,0xf0025c2c) */

undefined8 _dnlc_remove(int param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  pcVar3 = param_2;
  _strlen();
  if ((int)pcVar3 < 0x21) {
    cVar1 = *param_2;
    cVar2 = (pcVar3 + (int)param_2)[-1];
    while (iVar4 = param_1,
          sub_F0025EC0(param_1,param_2,pcVar3,
                       (uint)(pcVar3 + param_1 + (int)cVar1 + (int)cVar2) & 0x3f,0xffffffff),
          iVar4 != 0) {
      sub_F0025DF8();
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=539 start=0xf0025c98 */

/* WARNING: Removing unreachable block (ram,0xf0025d00) */
/* WARNING: Removing unreachable block (ram,0xf0025cf8) */

undefined8 _dnlc_purge(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined4 unaff_l0;
  undefined4 *puVar2;
  undefined4 unaff_l1;
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
  bool bVar3;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  DAT_f013560c._0_4_ = DAT_f013560c._0_4_ + 1;
  do {
    puVar1 = _nc_hash;
    puVar2 = (undefined4 *)_nc_hash._0_4_;
    while (bVar3 = puVar2 == (undefined4 *)puVar1, puVar1 = (undefined *)((int)puVar1 + 8), bVar3) {
      if (_nc_hash + 0x1ff < puVar1) {
        return CONCAT44(param_2,param_1);
      }
      puVar2 = *(undefined4 **)puVar1;
    }
    if ((puVar2[5] == 0) || (puVar2[4] == 0)) {
      _panic(aDnlcPurgeZeroV);
    }
    sub_F0025DF8(puVar2);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=540 start=0xf0025d24 */

/* WARNING: Removing unreachable block (ram,0xf0025d6c) */

undefined8 _dnlc_purge_vp(int param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  do {
    bVar1 = false;
    if (dword_F01355D8 != &_nc_lru) {
      iVar2 = *(int *)((int)dword_F01355D8 + 0x14);
      puVar3 = dword_F01355D8;
      while ((iVar2 != param_1 && (*(int *)(puVar3 + 2) != param_1))) {
        puVar3 = *(undefined8 **)(puVar3 + 1);
        if (puVar3 == &_nc_lru) goto loc_F0025D88;
        iVar2 = *(int *)((int)puVar3 + 0x14);
      }
      sub_F0025DF8(puVar3);
      bVar1 = true;
    }
loc_F0025D88:
    if (!bVar1) {
      return CONCAT44(param_2,param_1);
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=541 start=0xf0025d9c */

/* WARNING: Removing unreachable block (ram,0xf0025dd0) */

undefined8 _dnlc_purge1(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  uVar3 = 0;
  if (dword_F01355D8 != &_nc_lru) {
    iVar1 = *(int *)((int)dword_F01355D8 + 0x14);
    puVar2 = dword_F01355D8;
    while (iVar1 == 0) {
      puVar2 = *(undefined8 **)(puVar2 + 1);
      if (puVar2 == &_nc_lru) {
        uVar3 = 0;
        goto locret_F0025DF0;
      }
      iVar1 = *(int *)((int)puVar2 + 0x14);
    }
    sub_F0025DF8(puVar2);
    uVar3 = 1;
  }
locret_F0025DF0:
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=542 start=0xf0025fb4 */

/* WARNING: Removing unreachable block (ram,0xf0026070) */
/* WARNING: Removing unreachable block (ram,0xf0025fc4) */

undefined8 _vno_rw(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 unaff_l0;
  int *piVar3;
  undefined4 unaff_l1;
  int iVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar5;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  byte bVar6;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  piVar3 = *(int **)(param_1 + 0x18);
  if (param_2 == 1) {
    piVar5 = piVar3;
    _isrofile();
    if (piVar5 != (int *)0x0) {
      piVar5 = (int *)0x1e;
      goto locret_F00260E8;
    }
    iVar2 = piVar3[10];
  }
  else {
    iVar2 = piVar3[10];
  }
  uVar1 = *(uint *)(param_1 + 8);
  bVar6 = iVar2 == 1;
  iVar4 = *(int *)(param_3 + 0x14);
  if ((uVar1 & 8) != 0) {
    bVar6 = bVar6 | 2;
  }
  if ((uVar1 & 0x40000) != 0) {
    bVar6 = bVar6 | 4;
  }
  if (iVar2 == 8) {
    *(sword *)(param_3 + 0x10) = (sword)uVar1;
  }
  piVar5 = piVar3;
  if (((piVar3[10] == 1) && ((*(uint *)(*piVar3 + 0x38) & 0x8000000) != 0)) &&
     ((*(uint *)(*_active_u + 0x14) & 0x4000) == 0)) {
    _mfs_io(piVar3,param_3,param_2,bVar6,*(undefined4 *)(param_1 + 0x20));
  }
  else {
    (**(code **)(piVar3[7] + 8))(piVar3,param_3,param_2,bVar6,*(undefined4 *)(param_1 + 0x20));
  }
  if (piVar5 == (int *)0x0) {
    if ((*(uint *)(param_1 + 8) & 8) == 0) {
      if (piVar3[10] != 8) {
        piVar5 = (int *)0x0;
        goto locret_F00260E8;
      }
      iVar2 = *(int *)(param_3 + 0x14);
    }
    else {
      iVar2 = *(int *)(param_3 + 0x14);
    }
    *(int *)(param_1 + 0x1c) = *(int *)(param_3 + 8) - (iVar4 - iVar2);
    piVar5 = (int *)0x0;
  }
locret_F00260E8:
  return CONCAT44(param_2,piVar5);
}
/* GHIDRADEC_FUNCTION index=543 start=0xf00260f0 */

/* WARNING: Removing unreachable block (ram,0xf002629c) */

undefined8 _vno_ioctl(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
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
  *(int *)((int)register0x00000038 + 0x44) = param_1;
  uVar3 = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)((int)register0x00000038 + 0x48) = param_2;
  *(undefined4 *)((int)register0x00000038 + -0x54) = uVar3;
  *(undefined4 *)((int)register0x00000038 + 0x4c) = param_3;
  uVar3 = *(undefined4 *)(*(int *)((int)register0x00000038 + -0x54) + 0x28);
  *(undefined4 *)((int)register0x00000038 + -0x4c) = 0;
  switch(uVar3) {
  case :
    iVar1 = *(int *)((int)register0x00000038 + 0x48);
    if (iVar1 == -0x3ffb9996) {
      iVar2 = *(int *)((int)register0x00000038 + 0x44);
      *(uint *)((int)register0x00000038 + -0x50) = *(uint *)(iVar2 + 8) & 0x1000;
      iVar1 = **(int **)((int)register0x00000038 + 0x4c);
      if (iVar1 == 1) {
        *(uint *)(iVar2 + 8) = *(uint *)(iVar2 + 8) | 0x1000;
loc_F00261E0:
        iVar2 = *(int *)((int)register0x00000038 + -0x50);
      }
      else {
        if (1 < iVar1) {
          if (iVar1 != 2) {
            uVar3 = 0x16;
            goto locret_F0026328;
          }
          *(uint *)(iVar2 + 8) = *(uint *)(iVar2 + 8) & 0xffffefff;
          goto loc_F00261E0;
        }
        iVar2 = *(int *)((int)register0x00000038 + -0x50);
        if (iVar1 != 0) {
          uVar3 = 0x16;
          goto locret_F0026328;
        }
      }
      if (iVar2 == 0) {
        uVar3 = 2;
      }
      else {
        uVar3 = 1;
      }
      **(undefined4 **)((int)register0x00000038 + 0x4c) = uVar3;
      uVar3 = 0;
      goto locret_F0026328;
    }
    break;
  case :
  case :
    iVar1 = *(int *)((int)register0x00000038 + 0x48);
    break;
  :
    goto def_F0026130;
  case :
  case :
    *(undefined4 *)(dword_F0133DDC + 0x30) = 0;
    iVar1 = dword_F0133DDC + 0x28;
    _setjmp();
    if (iVar1 != 0) {
      if ((_active_u[0x4f] >> (*(char *)(*_active_u + 0x17) - 1U & 0x1f) & 1U) == 0) {
        *(undefined *)(dword_F0133DDC + 0x39) = 2;
        goto loc_F0026324;
      }
      uVar3 = 4;
      goto loc_F0026320;
    }
    uVar3 = *(undefined4 *)((int)register0x00000038 + -0x54);
    (**(code **)(*(int *)(*(int *)((int)register0x00000038 + -0x54) + 0x1c) + 0xc))
              (uVar3,*(undefined4 *)((int)register0x00000038 + 0x48),
               *(undefined4 *)((int)register0x00000038 + 0x4c),
               *(undefined4 *)(*(int *)((int)register0x00000038 + 0x44) + 8),
               *(undefined4 *)(*(int *)((int)register0x00000038 + 0x44) + 0x20));
    *(undefined4 *)((int)register0x00000038 + -0x4c) = uVar3;
    goto loc_F0026324;
  }
  if (iVar1 < -0x7ffb9983) {
def_F0026130:
    uVar3 = 0x19;
loc_F0026320:
    *(undefined4 *)((int)register0x00000038 + -0x4c) = uVar3;
  }
  else if (-0x7ffb9982 < iVar1) {
    uVar3 = 0x19;
    if (iVar1 != 0x4004667f) goto loc_F0026320;
    iVar1 = *(int *)((int)register0x00000038 + -0x54);
    (**(code **)(*(int *)(*(int *)((int)register0x00000038 + -0x54) + 0x1c) + 0x14))
              (iVar1,(undefined *)((int)register0x00000038 + -0x48),_active_u[7]);
    *(int *)((int)register0x00000038 + -0x4c) = iVar1;
    if (iVar1 == 0) {
      **(int **)((int)register0x00000038 + 0x4c) =
           *(int *)((int)register0x00000038 + -0x30) -
           *(int *)(*(int *)((int)register0x00000038 + 0x44) + 0x1c);
    }
  }
loc_F0026324:
  uVar3 = *(undefined4 *)((int)register0x00000038 + -0x4c);
locret_F0026328:
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=544 start=0xf0026330 */

undefined8 _vno_select(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  iVar2 = *(int *)(param_1 + 0x18);
  uVar1 = *(uint *)(iVar2 + 0x28);
  if (uVar1 != 4) {
    if ((uVar1 < 9) || (9 < uVar1)) {
      iVar2 = 1;
      goto locret_F0026384;
    }
    if (uVar1 < 8) {
      iVar2 = 1;
      goto locret_F0026384;
    }
  }
  (**(code **)(*(int *)(iVar2 + 0x1c) + 0x10))(iVar2,param_2,*(undefined4 *)(param_1 + 0x20));
locret_F0026384:
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=545 start=0xf002638c */

undefined8 _vno_stat(int param_1,undefined2 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  bool bVar4;
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
  iVar1 = param_1;
  (**(code **)(*(int *)(param_1 + 0x1c) + 0x14))
            (param_1,(undefined *)((int)register0x00000038 + -0x48),
             *(undefined4 *)(_active_u + 0x1c));
  if (iVar1 != 0) goto locret_F00264FC;
  param_2[4] = *(undefined2 *)((int)register0x00000038 + -0x44);
  param_2[6] = *(undefined2 *)((int)register0x00000038 + -0x42);
  param_2[7] = *(undefined2 *)((int)register0x00000038 + -0x40);
  *param_2 = (sword)*(undefined4 *)((int)register0x00000038 + -0x3c);
  *(undefined4 *)(param_2 + 2) = *(undefined4 *)((int)register0x00000038 + -0x38);
  param_2[5] = *(undefined2 *)((int)register0x00000038 + -0x34);
  *(undefined4 *)(param_2 + 10) = *(undefined4 *)((int)register0x00000038 + -0x30);
  *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)((int)register0x00000038 + -0x2c);
  *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)((int)register0x00000038 + -0x28);
  *(undefined4 *)(param_2 + 0xe) = 0;
  iVar3 = *(int *)(param_1 + 0x14);
  iVar1 = *(int *)((int)register0x00000038 + -0x20);
  if ((iVar3 == 0) &&
     (iVar1 = *(int *)((int)register0x00000038 + -0x20), *(int *)(param_1 + 0x18) == 0)) {
loc_F0026460:
    *(int *)(param_2 + 0x10) = iVar1;
  }
  else if (iVar1 < iVar3) {
    *(int *)(param_2 + 0x10) = iVar3;
  }
  else {
    bVar4 = iVar3 != iVar1;
    iVar1 = *(int *)((int)register0x00000038 + -0x20);
    if ((bVar4) ||
       (iVar1 = *(int *)((int)register0x00000038 + -0x20),
       *(int *)(param_1 + 0x18) <= *(int *)((int)register0x00000038 + -0x1c))) goto loc_F0026460;
    *(int *)(param_2 + 0x10) = iVar3;
  }
  *(undefined4 *)(param_2 + 0x12) = 0;
  *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)((int)register0x00000038 + -0x18);
  *(undefined4 *)(param_2 + 0x16) = 0;
  param_2[8] = *(undefined2 *)((int)register0x00000038 + -0x10);
  *(undefined4 *)(param_2 + 0x1a) = *(undefined4 *)((int)register0x00000038 + -0xc);
  *(undefined4 *)(param_2 + 0x1e) = 0;
  *(undefined4 *)(param_2 + 0x1c) = 0;
  if (*(undefined **)(param_1 + 0x1c) == _ufs_vnodeops) {
    *(undefined4 *)(param_2 + 0x1c) = 0xfeedface;
    uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x30) + 0xd0);
  }
  else {
    if (*(undefined **)(param_1 + 0x1c) != _nfs_vnodeops) {
      iVar1 = 0;
      goto locret_F00264FC;
    }
    iVar1 = *(int *)(param_1 + 0x30);
    if (*(int *)(iVar1 + 0x4c) != *(int *)(param_2 + 2)) {
      iVar1 = 0;
      goto locret_F00264FC;
    }
    *(undefined4 *)(param_2 + 0x1c) = 0xfeedface;
    uVar2 = *(undefined4 *)(iVar1 + 0x50);
  }
  *(undefined4 *)(param_2 + 0x1e) = uVar2;
  iVar1 = 0;
locret_F00264FC:
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=546 start=0xf0026504 */

/* WARNING: Removing unreachable block (ram,0xf0026538) */
/* WARNING: Removing unreachable block (ram,0xf002655c) */
/* WARNING: Removing unreachable block (ram,0xf0026528) */

undefined8 _vno_close(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar2;
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
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  uVar2 = *(undefined4 *)(param_1 + 0x18);
  if ((*(sword *)(param_1 + 0xe) == 1) && ((*(uint *)(param_1 + 8) & 0x180) != 0)) {
    _vno_bsd_unlock(param_1,0x180);
  }
  uVar1 = uVar2;
  _vn_close(uVar2,*(undefined4 *)(param_1 + 8),(int)*(sword *)(param_1 + 0xe));
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
  if (*(sword *)(param_1 + 0xe) == 1) {
    _vn_rele(uVar2);
  }
  return CONCAT44(param_2,(int)*(char *)(dword_F0133DDC + 0x38));
}
/* GHIDRADEC_FUNCTION index=547 start=0xf0026574 */

undefined8 _vno_lockrelease(int param_1,undefined4 param_2)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar6;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar7;
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
  uVar4 = *(uint *)(*_active_u + 0x28);
  if ((uVar4 & 0x20000000) != 0) {
    *(uint *)(*_active_u + 0x28) = uVar4 & 0xdfffffff;
    iVar5 = _active_u[0x55];
    bVar2 = false;
    iVar6 = *(int *)(param_1 + 0x18);
    if (-1 < iVar5) {
      do {
        iVar3 = *(int *)(_active_u[0x53] + iVar5 * 4);
        if (iVar3 == 0) {
          bVar7 = iVar5 + -1 < 0;
        }
        else {
          bVar1 = *(byte *)(_active_u[0x54] + iVar5);
          if ((bVar1 & 4) == 0) {
            bVar7 = iVar5 + -1 < 0;
          }
          else {
            if (*(int *)(iVar3 + 0x18) == iVar6) {
              bVar2 = true;
              *(byte *)(_active_u[0x54] + iVar5) = bVar1 & 0xfb;
            }
            else {
              *(uint *)(*_active_u + 0x28) = *(uint *)(*_active_u + 0x28) | 0x20000000;
            }
            bVar7 = iVar5 + -1 < 0;
          }
        }
        iVar5 = iVar5 + -1;
      } while (!bVar7);
    }
    if (bVar2) {
      *(undefined2 *)((int)register0x00000038 + -0x20) = 3;
      *(undefined2 *)((int)register0x00000038 + -0x1e) = 0;
      *(undefined4 *)((int)register0x00000038 + -0x1c) = 0;
      *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
      (**(code **)(*(int *)(iVar6 + 0x1c) + 0x60))
                (iVar6,(undefined *)((int)register0x00000038 + -0x20),8,_active_u[7],
                 (int)*(sword *)(*_active_u + 0x30));
      goto locret_F0026678;
    }
  }
  iVar6 = 0;
locret_F0026678:
  return CONCAT44(param_2,iVar6);
}
/* GHIDRADEC_FUNCTION index=548 start=0xf0026680 */

/* WARNING: Removing unreachable block (ram,0xf002678c) */
/* WARNING: Removing unreachable block (ram,0xf0026758) */
/* WARNING: Removing unreachable block (ram,0xf0026824) */
/* WARNING: Removing unreachable block (ram,0xf00267d8) */
/* WARNING: Removing unreachable block (ram,0xf00266f0) */

undefined8 _vno_bsd_lock(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
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
  *(int *)((int)register0x00000038 + -0x14) = param_1;
  uVar1 = *(uint *)(param_1 + 8);
  *(uint *)((int)register0x00000038 + 0x48) = param_2;
  if ((((uVar1 & 0x100) == 0) || (uVar4 = 0, (param_2 & 2) == 0)) &&
     (((uVar1 & 0x80) == 0 || (uVar4 = 0, (param_2 & 1) == 0)))) {
    *(undefined4 *)((int)register0x00000038 + -0xc) = 0x23;
    *(undefined4 *)((int)register0x00000038 + -0x1c) =
         *(undefined4 *)(*(int *)((int)register0x00000038 + -0x14) + 0x18);
    if ((*(uint *)((int)register0x00000038 + 0x48) & 2) == 0) {
      *(int *)((int)register0x00000038 + -0xc) = *(int *)((int)register0x00000038 + -0xc) + 1;
    }
    iVar2 = dword_F0133DDC + 0x28;
    _setjmp();
    iVar3 = *(int *)((int)register0x00000038 + -0x1c);
    if (iVar2 == 0) {
      while( true ) {
        while ((*(word *)(iVar3 + 4) & 4) != 0) {
          if ((*(uint *)(*(int *)((int)register0x00000038 + -0x14) + 8) & 0x100) == 0) {
            iVar2 = *(int *)((int)register0x00000038 + -0x1c);
            if ((*(uint *)((int)register0x00000038 + 0x48) & 4) != 0) goto loc_F00267F4;
            uVar4 = *(undefined4 *)((int)register0x00000038 + -0xc);
            iVar3 = iVar2 + 10;
            *(word *)(iVar2 + 4) = *(word *)(iVar2 + 4) | 0x10;
            goto loc_F002678C;
          }
          _vno_bsd_unlock(*(undefined4 *)((int)register0x00000038 + -0x14),0x100);
          iVar3 = *(int *)((int)register0x00000038 + -0x1c);
        }
        if ((*(uint *)((int)register0x00000038 + 0x48) & 2) == 0) break;
        if ((*(word *)(*(int *)((int)register0x00000038 + -0x1c) + 4) & 8) == 0) break;
        if ((*(uint *)(*(int *)((int)register0x00000038 + -0x14) + 8) & 0x80) == 0) {
          if ((*(uint *)((int)register0x00000038 + 0x48) & 4) != 0) {
loc_F00267F4:
            uVar4 = 0x23;
            goto locret_F00268B8;
          }
          iVar3 = *(int *)((int)register0x00000038 + -0x1c);
          uVar4 = 0x23;
          *(word *)(iVar3 + 4) = *(word *)(*(int *)((int)register0x00000038 + -0x1c) + 4) | 0x10;
          iVar3 = iVar3 + 8;
loc_F002678C:
          _sleep(iVar3,uVar4);
          iVar3 = *(int *)((int)register0x00000038 + -0x1c);
        }
        else {
          _vno_bsd_unlock(*(undefined4 *)((int)register0x00000038 + -0x14),0x80);
          iVar3 = *(int *)((int)register0x00000038 + -0x1c);
        }
      }
      if ((*(uint *)(*(int *)((int)register0x00000038 + -0x14) + 8) & 0x100) != 0) {
        _panic(aVnoBsdLock);
      }
      uVar1 = *(uint *)((int)register0x00000038 + 0x48);
      if ((uVar1 & 2) != 0) {
        iVar2 = *(int *)((int)register0x00000038 + -0x1c);
        *(sword *)(iVar2 + 10) = *(sword *)(iVar2 + 10) + 1;
        *(word *)(iVar2 + 4) = *(word *)(iVar2 + 4) | 4;
        *(uint *)(*(int *)((int)register0x00000038 + -0x14) + 8) =
             *(uint *)(*(int *)((int)register0x00000038 + -0x14) + 8) | 0x100;
        uVar1 = *(uint *)((int)register0x00000038 + 0x48);
      }
      uVar4 = 0;
      if (((uVar1 & 1) != 0) &&
         (iVar2 = *(int *)((int)register0x00000038 + -0x1c),
         (*(uint *)(*(int *)((int)register0x00000038 + -0x14) + 8) & 0x80) == 0)) {
        *(sword *)(iVar2 + 8) = *(sword *)(iVar2 + 8) + 1;
        *(word *)(iVar2 + 4) = *(word *)(iVar2 + 4) | 8;
        *(uint *)(*(int *)((int)register0x00000038 + -0x14) + 8) =
             *(uint *)(*(int *)((int)register0x00000038 + -0x14) + 8) | 0x80;
        uVar4 = 0;
      }
    }
    else if ((_active_u[0x4f] >> (*(char *)(*_active_u + 0x17) - 1U & 0x1f) & 1U) == 0) {
      uVar4 = 0;
      *(undefined *)(dword_F0133DDC + 0x39) = 2;
    }
    else {
      uVar4 = 4;
    }
  }
locret_F00268B8:
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=549 start=0xf00268c0 */

/* WARNING: Removing unreachable block (ram,0xf0026968) */
/* WARNING: Removing unreachable block (ram,0xf002693c) */
/* WARNING: Removing unreachable block (ram,0xf00269a8) */
/* WARNING: Removing unreachable block (ram,0xf00268fc) */

undefined8 _vno_bsd_unlock(int param_1,uint param_2)

{
  word wVar1;
  sword sVar3;
  uint uVar2;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
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
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  iVar4 = *(int *)(param_1 + 0x18);
  param_2 = param_2 & *(uint *)(param_1 + 8);
  if ((iVar4 != 0) && (param_2 != 0)) {
    wVar1 = *(word *)(iVar4 + 4);
    if ((param_2 & 0x80) != 0) {
      if ((wVar1 & 8) == 0) {
        _panic(aVnoBsdUnlockSh);
        sVar3 = *(sword *)(iVar4 + 8);
      }
      else {
        sVar3 = *(sword *)(iVar4 + 8);
      }
      *(sword *)(iVar4 + 8) = sVar3 + -1;
      if ((sword)(sVar3 + -1) == 0) {
        *(word *)(iVar4 + 4) = *(word *)(iVar4 + 4) & 0xfff7;
        if ((wVar1 & 0x10) != 0) {
          _wakeup(iVar4 + 8);
        }
        uVar2 = *(uint *)(param_1 + 8);
      }
      else {
        uVar2 = *(uint *)(param_1 + 8);
      }
      *(uint *)(param_1 + 8) = uVar2 & 0xffffff7f;
    }
    if ((param_2 & 0x100) != 0) {
      if ((wVar1 & 4) == 0) {
        _panic(aVnoBsdUnlockEx);
        sVar3 = *(sword *)(iVar4 + 10);
      }
      else {
        sVar3 = *(sword *)(iVar4 + 10);
      }
      *(sword *)(iVar4 + 10) = sVar3 + -1;
      if ((sword)(sVar3 + -1) == 0) {
        *(word *)(iVar4 + 4) = *(word *)(iVar4 + 4) & 0xffeb;
        if ((wVar1 & 0x10) != 0) {
          _wakeup(iVar4 + 10);
        }
        uVar2 = *(uint *)(param_1 + 8);
      }
      else {
        uVar2 = *(uint *)(param_1 + 8);
      }
      *(uint *)(param_1 + 8) = uVar2 & 0xfffffeff;
    }
  }
  return CONCAT44(param_2,param_1);
}

