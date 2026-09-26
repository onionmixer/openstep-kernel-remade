/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012fbf8 */

char * _newname(void)

{
  char *pcVar1;
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  ushort local_c [4];
  
  pcVar1 = (char *)_kalloc(0xff);
  pcVar2 = &DAT_001dc541;
  pcVar4 = pcVar1;
  do {
    *pcVar4 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar4 = pcVar4 + 1;
  } while (pcVar2 < &DAT_001dc545);
  if (DAT_001e59b0 == 0) {
    _getthetime(local_c);
    DAT_001e59b0 = (uint)local_c[0];
  }
  uVar3 = DAT_001e59b0;
  DAT_001e59b0 = DAT_001e59b0 + 1;
  for (; uVar3 != 0; uVar3 = (int)uVar3 >> 4) {
    *pcVar4 = s_0123456789ABCDEF_001dc546[uVar3 & 0xf];
    pcVar4 = pcVar4 + 1;
  }
  *pcVar4 = '\0';
  return pcVar1;
}

