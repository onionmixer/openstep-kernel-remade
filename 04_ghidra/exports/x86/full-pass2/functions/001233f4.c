/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001233f4 */

undefined1 * _ether_sprintf(byte *param_1)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  
  iVar3 = 0;
  pcVar1 = &DAT_001e58e2;
  do {
    pcVar2 = pcVar1;
    *pcVar2 = s_0123456789abcdef_001dba87[*param_1 >> 4];
    pcVar2[1] = s_0123456789abcdef_001dba87[*param_1 & 0xf];
    param_1 = param_1 + 1;
    pcVar2[2] = ':';
    iVar3 = iVar3 + 1;
    pcVar1 = pcVar2 + 3;
  } while (iVar3 < 6);
  pcVar2[2] = '\0';
  return &DAT_001e58e2;
}

