/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00104788 */

int _ufavail(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0;
  do {
    if ((iVar2 < *(int *)(_active_u + 0x15c)) &&
       (*(int *)(*(int *)(_active_u + 0x150) + iVar2 * 4) == 0)) {
      iVar1 = iVar1 + 1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x100);
  return iVar1;
}

