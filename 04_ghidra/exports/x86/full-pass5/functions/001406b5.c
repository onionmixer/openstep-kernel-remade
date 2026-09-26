/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001406b5 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_001406b5(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *unaff_EBX;
  int iVar5;
  
  do {
    *(int *)(*unaff_EBX + 4) = unaff_EBX[1];
    *(int *)unaff_EBX[1] = *unaff_EBX;
    unaff_EBX = _ifreeh;
    if (_ifreeh == (int *)0x0) {
      _ifreeh = (int *)0x0;
      iVar3 = _inode_list;
      iVar5 = _inode_list;
      while (iVar4 = iVar3, iVar4 != 0) {
        if (*(short *)(iVar4 + 0x44) < 0) {
          if (iVar5 == iVar4) {
            iVar5 = *(int *)(iVar4 + 8);
            _inode_list = iVar5;
          }
          else {
            *(undefined4 *)(iVar5 + 8) = *(undefined4 *)(iVar4 + 8);
          }
          iVar3 = *(int *)(iVar4 + 8);
          _zfree(_vm_info_zone);
          _zfree(_inode_zone,iVar4);
        }
        else {
          iVar3 = *(int *)(iVar4 + 8);
          iVar5 = iVar4;
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
    unaff_EBX[0x18] = 0;
    _mfs_uncache();
    *(undefined2 *)(unaff_EBX + 0x11) = 0x8000;
    *(byte *)(unaff_EBX + 0x11) = *(byte *)(unaff_EBX + 0x11) | 1;
  } while (*(short *)((int)unaff_EBX + 0x12) == 0);
                    /* WARNING: Subroutine does not return */
  _panic(s_free_inode_isn_t_001ddfb0);
}

