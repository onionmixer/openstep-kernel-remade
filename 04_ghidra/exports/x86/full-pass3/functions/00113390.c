/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00113390 */

/* WARNING: Removing unreachable block (ram,0x001133c8) */

char * _nextc3(int *param_1,int param_2,uint *param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  if ((*param_1 == 0) || (pcVar3 = (char *)(param_2 + 1), (char *)param_1[2] == pcVar3)) {
    pcVar3 = (char *)0x0;
  }
  else {
    if (((uint)pcVar3 & 0x3f) == 0) {
      pcVar3 = (char *)(*(int *)(param_2 + -0x3f) + 0xc);
    }
    cVar1 = *pcVar3;
    *param_3 = (int)cVar1;
    iVar2 = (int)((uint)pcVar3 & 0x3f) >> 3;
    if (((uint)(int)*(char *)(((uint)pcVar3 & 0xffffffc0) + 4 + iVar2) >>
         (((uint)pcVar3 & 0x3f) + iVar2 * -8 & 0x1f) & 1) != 0) {
      *param_3 = (int)cVar1 | 0x100;
    }
  }
  return pcVar3;
}

