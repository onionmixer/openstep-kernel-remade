/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a0ac8 */

int _PCPatoi(char *param_1)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  
  iVar3 = 0;
  bVar2 = false;
  while( true ) {
    cVar1 = *param_1;
    if (cVar1 == '+') goto LAB_001a0b00;
    if ('+' < cVar1) break;
    if ((cVar1 != '\t') && (cVar1 != ' ')) goto LAB_001a0b01;
    param_1 = param_1 + 1;
  }
  if (cVar1 == '-') {
    bVar2 = true;
    goto LAB_001a0b00;
  }
LAB_001a0b01:
  for (; (byte)(*param_1 - 0x30U) < 10; param_1 = param_1 + 1) {
    iVar3 = *param_1 + -0x30 + iVar3 * 10;
LAB_001a0b00:
  }
  if (bVar2) {
    iVar3 = -iVar3;
  }
  return iVar3;
}

