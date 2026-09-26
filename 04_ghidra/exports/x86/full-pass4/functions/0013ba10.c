/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013ba10 */

undefined4 _fspause(int param_1)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *(int *)(DAT_001e875c + 0x6c);
  uVar3 = (uint)*(char *)(DAT_001e875c + 0x70);
  *(undefined4 *)(DAT_001e875c + 0x6c) = 0;
  *(undefined1 *)(DAT_001e875c + 0x70) = 0;
  if ((((iVar2 != 0) && (uVar3 != 0)) && (*(char *)(DAT_001e875c + 0x68) == '\x1c')) &&
     (((*(byte *)(_active_u + 0x260) & 8) != 0 && (param_1 == 0)))) {
    *(undefined1 *)(DAT_001e875c + 0x68) = 0;
    pcVar1 = s_file_system_is_full_001dda2e;
    if ((uVar3 & 1) == 0) {
      pcVar1 = s_out_of_inodes_001dda1f;
    }
    iVar2 = _rpsleep(_fssleep,iVar2,uVar3,iVar2 + 0xd4,pcVar1);
    if (iVar2 != 0) {
      return 1;
    }
    *(undefined1 *)(DAT_001e875c + 0x68) = 0x1c;
  }
  return 0;
}

