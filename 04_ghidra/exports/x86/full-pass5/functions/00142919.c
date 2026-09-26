/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00142919 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00142919(void)

{
  ushort uVar1;
  int iVar2;
  int unaff_EBX;
  int iVar3;
  int unaff_EBP;
  int unaff_ESI;
  int iVar4;
  ushort unaff_DI;
  int iStack00000008;
  
  do {
    *(undefined1 *)(unaff_EBX + 0xd0) = 0;
    iStack00000008 = unaff_EBP + -8;
    _getthetime();
    *(undefined4 *)(unaff_EBX + 0x20) = *(undefined4 *)(unaff_EBP + -8);
    _sbupdate();
    do {
      unaff_ESI = *(int *)(unaff_ESI + 0x20);
      if (unaff_ESI == 0) {
        iVar3 = _inode_list;
        if (_inode_list != 0) goto LAB_0014294c;
        goto LAB_001429b6;
      }
    } while ((((unaff_DI != 0xffff) &&
              (unaff_DI != (*(ushort *)(unaff_EBP + -0xc) & *(ushort *)(unaff_ESI + 4)))) ||
             (*(int *)(unaff_ESI + 0xc) == 0)) ||
            ((*(short *)(unaff_ESI + 4) == -1 ||
             (unaff_EBX = *(int *)(*(int *)(unaff_ESI + 0xc) + 0x20),
             *(char *)(unaff_EBX + 0xd0) == '\0'))));
    if (*(char *)(unaff_EBX + 0xd2) != '\0') {
      iStack00000008 = unaff_EBX + 0xd4;
      _printf(s_fs____s_001de0ac);
                    /* WARNING: Subroutine does not return */
      _panic(s_update__ro_fs_mod_001de0b5);
    }
  } while( true );
LAB_0014294c:
  if (unaff_DI == 0xffff) {
LAB_00142985:
    uVar1 = *(ushort *)(iVar3 + 0x44);
    if ((((uVar1 & 1) == 0) && ((uVar1 & 0x100) != 0)) && ((uVar1 & 0x4e) != 0)) {
      *(byte *)(iVar3 + 0x44) = *(byte *)(iVar3 + 0x44) | 1;
      *(short *)(iVar3 + 0x12) = *(short *)(iVar3 + 0x12) + 1;
      iStack00000008 = 0;
      _iupdat();
      _iput();
    }
  }
  else if (unaff_DI == (*(ushort *)(unaff_EBP + -0xc) & *(ushort *)(iVar3 + 0x46))) {
    iVar4 = *(int *)(iVar3 + 0xc) + 0x18;
    iStack00000008 = iVar4;
    iVar2 = _lock_try_write();
    if (iVar2 == 1) {
      iStack00000008 = iVar4;
      _lock_done();
      _mfs_fsync();
    }
    goto LAB_00142985;
  }
  iVar3 = *(int *)(iVar3 + 8);
  if (iVar3 == 0) {
LAB_001429b6:
    _updlock = 0;
    iStack00000008 = (int)*(short *)(unaff_EBP + -0xc);
    _bflush();
    return;
  }
  goto LAB_0014294c;
}

