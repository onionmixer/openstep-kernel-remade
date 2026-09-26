/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00158fc8 */

int _mig_strncpy(char *dest,char *src,int len)

{
  char cVar1;
  int in_EAX;
  int iVar2;
  
  if (0 < len) {
    iVar2 = 1;
    if (1 < len) {
      do {
        cVar1 = *src;
        in_EAX = CONCAT31((int3)((uint)in_EAX >> 8),cVar1);
        *dest = cVar1;
        src = src + 1;
        dest = dest + 1;
        if (cVar1 == '\0') {
          return in_EAX;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < len);
    }
    *dest = '\0';
  }
  return in_EAX;
}

