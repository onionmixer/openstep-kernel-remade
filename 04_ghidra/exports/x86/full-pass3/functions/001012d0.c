/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001012d0 */

void * _memchr(void *param_1,int param_2,size_t param_3)

{
  char *pcVar1;
  bool bVar2;
  
  if (param_3 == 0) {
    param_3 = 0;
  }
  else {
    bVar2 = false;
    do {
      pcVar1 = param_1;
      if ((char *)param_3 == (char *)0x0) break;
      param_3 = param_3 + -1;
      pcVar1 = (char *)((int)param_1 + 1);
      bVar2 = (char)param_2 == *(char *)param_1;
      param_1 = pcVar1;
    } while (!bVar2);
    if (bVar2) {
      param_3 = (size_t)(pcVar1 + -1);
    }
  }
  return (void *)param_3;
}

