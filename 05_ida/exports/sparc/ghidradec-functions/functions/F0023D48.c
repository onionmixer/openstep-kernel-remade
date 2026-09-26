
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
