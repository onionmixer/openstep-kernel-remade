
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _vfs_mountroot(void)

{
  short *psVar1;
  undefined4 *puVar2;
  undefined **ppuVar3;
  int iVar4;
  undefined **ppuVar5;
  int local_8;
  
  iVar4 = 0;
  _rootvfs = (undefined4 *)_kalloc(0x12a);
  ppuVar3 = (undefined **)_vfssw_lookup(&_rootfs);
  puVar2 = _rootvfs;
  if (ppuVar3 == (undefined **)0x0) {
    ppuVar3 = &_vfssw;
    if (&_vfssw < _vfsNVFS) {
      ppuVar5 = &PTR__ufs_vfsops_040ae79a;
      do {
        puVar2 = _rootvfs;
        if (*ppuVar5 != (undefined *)0x0) {
          *_rootvfs = 0;
          puVar2[1] = *ppuVar5;
          puVar2[3] = 0;
          puVar2[7] = 0;
          *(undefined4 *)((int)puVar2 + 0x126) = 0;
          puVar2[0x48] = 0;
          *(undefined2 *)(puVar2 + 0x49) = *(undefined2 *)(*(int *)(_active_u + 0x1a) + 2);
          iVar4 = (**(code **)(puVar2[1] + 0x18))(puVar2,&_rootvp,&DAT_040b6a9c);
          if (iVar4 == 0) goto LAB_04017116;
        }
        ppuVar5 = ppuVar5 + 2;
        ppuVar3 = ppuVar3 + 2;
      } while (ppuVar3 < _vfsNVFS);
    }
  }
  else {
    *_rootvfs = 0;
    puVar2[1] = ppuVar3[1];
    puVar2[3] = 0;
    puVar2[7] = 0;
    *(undefined4 *)((int)puVar2 + 0x126) = 0;
    puVar2[0x48] = 0;
    *(undefined2 *)(puVar2 + 0x49) = *(undefined2 *)(*(int *)(_active_u + 0x1a) + 2);
    iVar4 = (**(code **)(puVar2[1] + 0x18))(puVar2,&_rootvp,&DAT_040b6a9c);
  }
  if (iVar4 != 0) {
    _printf("vfs_mountroot: error=%d\n",iVar4);
                    /* WARNING: Subroutine does not return */
    _panic("vfs_mountroot: cannot mount root");
  }
LAB_04017116:
  iVar4 = (**(code **)(_rootvfs[1] + 8))(_rootvfs,&_rootdir);
  if (iVar4 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic("vfs_mountroot: cannot find root vnode");
  }
  *(int *)(_active_u + 0x156) = _rootdir;
  psVar1 = (short *)(*(int *)(_active_u + 0x156) + 6);
  *psVar1 = *psVar1 + 1;
  *(undefined4 *)(_active_u + 0x15a) = 0;
  if (_rootname != '\0') {
    iVar4 = _lookupname(&_rootname,1,1,0,&local_8);
    if (iVar4 == 0) {
      _rootdir = local_8;
      _vn_rele(*(undefined4 *)(_active_u + 0x156));
      _vn_rele(*(undefined4 *)(_active_u + 0x156));
      *(int *)(_active_u + 0x156) = _rootdir;
      *(short *)(_rootdir + 6) = *(short *)(_rootdir + 6) + 1;
    }
  }
  _DAT_040b6b24 = _rootvp;
  _strcpy(&_rootfs,*ppuVar3);
  _DAT_040b6b20 = 0;
  _DAT_040b6b1c = 1;
  return;
}

