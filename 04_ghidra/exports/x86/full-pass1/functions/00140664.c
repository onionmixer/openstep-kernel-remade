/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00140664 */

void _inode_cache_clear(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  while( true ) {
    piVar5 = _ifreeh;
    if (_ifreeh == (int *)0x0) {
      _ifreeh = (int *)0x0;
      iVar3 = _inode_list;
      iVar6 = _inode_list;
      while (iVar4 = iVar3, iVar4 != 0) {
        if (*(short *)(iVar4 + 0x44) < 0) {
          if (iVar6 == iVar4) {
            iVar6 = *(int *)(iVar4 + 8);
            _inode_list = iVar6;
          }
          else {
            *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar4 + 8);
          }
          iVar3 = *(int *)(iVar4 + 8);
          _zfree(_vm_info_zone,*(undefined4 *)(iVar4 + 0xc));
          _zfree(_inode_zone,iVar4);
        }
        else {
          iVar3 = *(int *)(iVar4 + 8);
          iVar6 = iVar4;
        }
      }
      return;
    }
    piVar2 = (int *)_ifreeh[0x17];
    if (piVar2 != (int *)0x0) {
      piVar2[0x18] = (int)&_ifreeh;
    }
    piVar1 = _ifreeh + 0x17;
    _ifreeh = piVar2;
    *piVar1 = 0;
    piVar5[0x18] = 0;
    _mfs_uncache(piVar5 + 3);
    *(undefined2 *)(piVar5 + 0x11) = 0x8000;
    *(byte *)(piVar5 + 0x11) = *(byte *)(piVar5 + 0x11) | 1;
    if (*(short *)((int)piVar5 + 0x12) != 0) break;
    *(int *)(*piVar5 + 4) = piVar5[1];
    *(int *)piVar5[1] = *piVar5;
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_free_inode_isn_t_001ddfb0);
}

