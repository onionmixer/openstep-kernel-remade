/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00119538 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _vfs_mountroot(void)

{
  short *psVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  int iVar6;
  int local_8;
  
  iVar6 = 0;
  _rootvfs = (undefined4 *)_kalloc(300);
  ppuVar4 = &_vfssw;
  if (&_vfssw < _vfsNVFS) {
    do {
      iVar3 = _strcmp(&_rootfs,*ppuVar4);
      if (iVar3 == 0) goto LAB_00119585;
      ppuVar4 = ppuVar4 + 2;
    } while (ppuVar4 < _vfsNVFS);
  }
  ppuVar4 = (undefined **)0x0;
LAB_00119585:
  puVar2 = _rootvfs;
  if (ppuVar4 == (undefined **)0x0) {
    ppuVar4 = &_vfssw;
    if (&_vfssw < _vfsNVFS) {
      ppuVar5 = &PTR__ufs_vfsops_001db644;
      do {
        puVar2 = _rootvfs;
        if (*ppuVar5 != (undefined *)0x0) {
          *_rootvfs = 0;
          puVar2[1] = *ppuVar5;
          puVar2[3] = 0;
          puVar2[7] = 0;
          puVar2[0x4a] = 0;
          puVar2[0x48] = 0;
          *(undefined2 *)(puVar2 + 0x49) = *(undefined2 *)(*(int *)(_active_u + 0x1c) + 2);
          iVar6 = (**(code **)(puVar2[1] + 0x18))(puVar2,&_rootvp,&DAT_001e9900);
          if (iVar6 == 0) goto LAB_00119699;
        }
        ppuVar5 = ppuVar5 + 2;
        ppuVar4 = ppuVar4 + 2;
      } while (ppuVar4 < _vfsNVFS);
    }
  }
  else {
    *_rootvfs = 0;
    puVar2[1] = ppuVar4[1];
    puVar2[3] = 0;
    puVar2[7] = 0;
    puVar2[0x4a] = 0;
    puVar2[0x48] = 0;
    *(undefined2 *)(puVar2 + 0x49) = *(undefined2 *)(*(int *)(_active_u + 0x1c) + 2);
    iVar6 = (**(code **)(puVar2[1] + 0x18))(puVar2,&_rootvp,&DAT_001e9900);
  }
  if (iVar6 != 0) {
    _printf(s_vfs_mountroot__error__d_001db48d,iVar6);
                    /* WARNING: Subroutine does not return */
    _panic(s_vfs_mountroot__cannot_mount_root_001db4a6);
  }
LAB_00119699:
  iVar6 = (**(code **)(_rootvfs[1] + 8))(_rootvfs,&_rootdir);
  if (iVar6 == 0) {
    *(int *)(_active_u + 0x160) = _rootdir;
    psVar1 = (short *)(*(int *)(_active_u + 0x160) + 6);
    *psVar1 = *psVar1 + 1;
    *(undefined4 *)(_active_u + 0x164) = 0;
    if ((_rootname != '\0') && (iVar6 = _lookupname(&_rootname,1,1,0,&local_8), iVar6 == 0)) {
      _rootdir = local_8;
      _vn_rele(*(undefined4 *)(_active_u + 0x160));
      _vn_rele(*(undefined4 *)(_active_u + 0x160));
      *(int *)(_active_u + 0x160) = _rootdir;
      *(short *)(_rootdir + 6) = *(short *)(_rootdir + 6) + 1;
    }
    _DAT_001e9988 = _rootvp;
    _strcpy(&_rootfs,*ppuVar4);
    _DAT_001e9984 = 0;
    _DAT_001e9980 = 1;
    return;
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_vfs_mountroot__cannot_find_root_v_001db4c7);
}

