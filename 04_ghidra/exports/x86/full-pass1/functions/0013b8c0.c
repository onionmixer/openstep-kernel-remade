/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013b8c0 */

void _fsfull(int param_1,uint param_2)

{
  char *pcVar1;
  char *pcVar2;
  
  if ((param_2 & 1) == 0) {
    if ((param_2 & 2) == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_fsfull_001dda07);
    }
    pcVar1 = s_out_of_inodes_001dd9d3;
    pcVar2 = s_create_symlink_failed__no_inodes_001dd9e1;
  }
  else {
    pcVar1 = s_file_system_full_001dd9a0;
    pcVar2 = s_write_failed__file_system_is_ful_001dd9b1;
  }
  if ((param_2 & (int)*(char *)(param_1 + 0xd3)) == 0) {
    _fserr(param_1,pcVar1);
  }
  *(byte *)(param_1 + 0xd3) = *(byte *)(param_1 + 0xd3) | (byte)param_2;
  if ((*(byte *)(_active_u + 0x260) & 8) == 0) {
    _uprintf(s__s___s_001dda0e,param_1 + 0xd4,pcVar2);
  }
  if (*(int *)(DAT_001e875c + 0x6c) == 0) {
    *(int *)(DAT_001e875c + 0x6c) = param_1;
    *(byte *)(DAT_001e875c + 0x70) = (byte)param_2;
  }
  *(undefined1 *)(DAT_001e875c + 0x68) = 0x1c;
  return;
}

