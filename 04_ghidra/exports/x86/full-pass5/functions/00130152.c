/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00130152 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

int __analysis_fragment_00130152(void)

{
  short *psVar1;
  int iVar2;
  undefined4 *puVar3;
  int unaff_EBP;
  
  *(undefined4 *)(_active_u + 0x160) = _rootdir;
  psVar1 = (short *)(*(int *)(_active_u + 0x160) + 6);
  *psVar1 = *psVar1 + 1;
  *(undefined4 *)(_active_u + 0x164) = 0;
  iVar2 = _lookupname();
  if ((iVar2 == 0) && (*(int *)(unaff_EBP + -0x168) != 0)) {
    _vn_rele();
    _vn_rele(_rootdir);
    _dnlc_purge();
    puVar3 = (undefined4 *)_kalloc(300);
    *puVar3 = 0;
    puVar3[1] = &_nfs_vfsops;
    puVar3[3] = 0;
    puVar3[7] = 0;
    puVar3[0x4a] = 0;
    puVar3[0x48] = 0;
    *(undefined2 *)(puVar3 + 0x49) = *(undefined2 *)(*(int *)(_active_u + 0x1c) + 2);
    iVar2 = FUN_00130d00(unaff_EBP + -0x164,puVar3,*(undefined4 *)(unaff_EBP + -0x17c),
                         *(undefined4 *)(unaff_EBP + -0x174),*(undefined4 *)(unaff_EBP + -0x178),0,
                         0xffffffff,0);
    if (iVar2 == 0) {
      iVar2 = _vfs_add(*(undefined4 *)(unaff_EBP + -0x168),puVar3);
      if (iVar2 == 0) {
        iVar2 = *(int *)(unaff_EBP + 8);
        *(undefined4 *)(*(int *)(iVar2 + 0x128) + 100) = 6000;
        *(undefined4 *)(*(int *)(iVar2 + 0x128) + 0x6c) = 6000;
        _strncpy((char *)(*(int *)(unaff_EBP + 8) + 0x20),*(char **)(unaff_EBP + -0x13c),0xff);
        _vfs_unlock(*(undefined4 *)(*(int *)(unaff_EBP + -0x164) + 0x24));
        _nfs_netboot_prealloc(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x128));
        _pn_free(unaff_EBP + -0x140);
        iVar2 = 0;
      }
      else {
        FUN_00130f38();
        _pn_free(unaff_EBP + -0x140);
        _kfree(puVar3,300);
      }
    }
    else {
      _pn_free();
      _kfree(puVar3,300);
    }
  }
  else {
    _printf(s_nfs_mountroot__no_place_to_mount_001dc718);
    _vn_rele(*(undefined4 *)(_active_u + 0x160));
    _pn_free(unaff_EBP + -0x140);
  }
  return iVar2;
}

