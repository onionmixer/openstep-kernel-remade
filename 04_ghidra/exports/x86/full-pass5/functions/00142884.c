/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00142884 */

void _update(ushort param_1,ushort param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_c [2];
  
  if (_syncprt != 0) {
    _bufstats();
  }
  if (_updlock == 0) {
    _updlock = 1;
    for (iVar3 = _mounttab; iVar2 = _inode_list, iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x20)) {
      if ((((param_1 == 0xffff) || (param_1 == (param_2 & *(ushort *)(iVar3 + 4)))) &&
          (*(int *)(iVar3 + 0xc) != 0)) &&
         ((*(short *)(iVar3 + 4) != -1 &&
          (iVar2 = *(int *)(*(int *)(iVar3 + 0xc) + 0x20), *(char *)(iVar2 + 0xd0) != '\0')))) {
        if (*(char *)(iVar2 + 0xd2) != '\0') {
          _printf(s_fs____s_001de0ac,iVar2 + 0xd4);
                    /* WARNING: Subroutine does not return */
          _panic(s_update__ro_fs_mod_001de0b5);
        }
        *(undefined1 *)(iVar2 + 0xd0) = 0;
        _getthetime(local_c);
        *(undefined4 *)(iVar2 + 0x20) = local_c[0];
        _sbupdate(iVar3);
      }
    }
    for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
      if (param_1 == 0xffff) {
LAB_00142985:
        uVar1 = *(ushort *)(iVar2 + 0x44);
        if ((((uVar1 & 1) == 0) && ((uVar1 & 0x100) != 0)) && ((uVar1 & 0x4e) != 0)) {
          *(byte *)(iVar2 + 0x44) = *(byte *)(iVar2 + 0x44) | 1;
          *(short *)(iVar2 + 0x12) = *(short *)(iVar2 + 0x12) + 1;
          _iupdat(iVar2,0);
          _iput(iVar2);
        }
      }
      else if (param_1 == (param_2 & *(ushort *)(iVar2 + 0x46))) {
        iVar4 = *(int *)(iVar2 + 0xc) + 0x18;
        iVar3 = _lock_try_write(iVar4);
        if (iVar3 == 1) {
          _lock_done(iVar4);
          _mfs_fsync(iVar2 + 0xc);
        }
        goto LAB_00142985;
      }
    }
    _updlock = 0;
    _bflush(0,(int)(short)param_1,(int)(short)param_2);
  }
  return;
}

