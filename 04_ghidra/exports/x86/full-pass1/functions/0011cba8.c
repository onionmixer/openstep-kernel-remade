/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011cba8 */

int _chdir(char *param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 local_8;
  
  uVar1 = _chdirec(**(undefined4 **)(DAT_001e875c + 0x24),&local_8);
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar1;
  iVar2 = DAT_001e875c;
  if (*(char *)(DAT_001e875c + 0x68) == '\0') {
    _vn_rele(*(undefined4 *)(_active_u + 0x160));
    iVar2 = _active_u;
    *(undefined4 *)(_active_u + 0x160) = local_8;
  }
  return iVar2;
}

