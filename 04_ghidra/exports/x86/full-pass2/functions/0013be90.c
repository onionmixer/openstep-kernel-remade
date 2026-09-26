/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013be90 */

int _ialloc(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x50);
  if (((*(short *)(*(int *)(_active_u + 0x1c) + 2) == 0) ||
      (*(int *)(iVar1 + 0x94) < *(int *)(iVar1 + 200))) && (*(int *)(iVar1 + 200) != 0)) {
    if (*(int *)(iVar1 + 0x2c) * *(uint *)(iVar1 + 0xb8) <= param_2) {
      param_2 = 0;
    }
    iVar2 = _hashalloc(param_1,param_2 / *(uint *)(iVar1 + 0xb8),param_2,param_3,_ialloccg);
    if (iVar2 != 0) {
      iVar3 = _iget((int)*(short *)(param_1 + 0x46),*(undefined4 *)(param_1 + 0x50),iVar2);
      if (iVar3 == 0) {
        _ifree(param_1,iVar2,0);
        return 0;
      }
      if (*(ushort *)(iVar3 + 100) != 0) {
        _printf(s_mode___0_o__inum____d__fs____s_001ddb2c,(uint)*(ushort *)(iVar3 + 100),
                *(undefined4 *)(iVar3 + 0x48),iVar1 + 0xd4);
                    /* WARNING: Subroutine does not return */
        _panic(s_ialloc__dup_alloc_001ddb4c);
      }
      if (*(int *)(iVar3 + 0xcc) != 0) {
        _printf(s_free_inode__s__d_had__d_blocks_001ddb5e,iVar1 + 0xd4,iVar2,*(int *)(iVar3 + 0xcc))
        ;
        *(undefined4 *)(iVar3 + 0xcc) = 0;
      }
      *(undefined4 *)(iVar3 + 200) = 0;
      return iVar3;
    }
  }
  if ((*(byte *)(iVar1 + 0xd3) & 2) == 0) {
    _fserr(iVar1,s_out_of_inodes_001dd9d3);
  }
  *(byte *)(iVar1 + 0xd3) = *(byte *)(iVar1 + 0xd3) | 2;
  if ((*(byte *)(_active_u + 0x260) & 8) == 0) {
    _uprintf(s__s___s_001dda0e,iVar1 + 0xd4,s_create_symlink_failed__no_inodes_001dd9e1);
  }
  if (*(int *)(DAT_001e875c + 0x6c) == 0) {
    *(int *)(DAT_001e875c + 0x6c) = iVar1;
    *(undefined1 *)(DAT_001e875c + 0x70) = 2;
  }
  *(undefined1 *)(DAT_001e875c + 0x68) = 0x1c;
  return 0;
}

