/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00142de8 */

int _getmp(short param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = _mounttab;
  while( true ) {
    if (iVar2 == 0) {
      return 0;
    }
    if ((*(int *)(iVar2 + 0xc) != 0) && (*(short *)(iVar2 + 4) == param_1)) break;
    iVar2 = *(int *)(iVar2 + 0x20);
  }
  iVar1 = *(int *)(*(int *)(iVar2 + 0xc) + 0x20);
  if (*(int *)(iVar1 + 0x55c) == 0x11954) {
    return iVar2;
  }
  _printf(s_dev___0x_x__fs____s_001de0fa,(int)param_1,iVar1 + 0xd4);
                    /* WARNING: Subroutine does not return */
  _panic(s_getmp__bad_magic_001de10f);
}

