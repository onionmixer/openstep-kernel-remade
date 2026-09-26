/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015c354 */

char * _getsectdatafromheader(mach_header *mhp,char *segname,char *sectname,uint32_t *size)

{
  section *psVar1;
  char *pcVar2;
  
  psVar1 = _getsectbynamefromheader(mhp,segname,sectname);
  if (psVar1 == (section *)0x0) {
    *size = 0;
    pcVar2 = (char *)0x0;
  }
  else {
    *size = psVar1->size;
    pcVar2 = (char *)psVar1->addr;
  }
  return pcVar2;
}

