/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00102934 */

void _task_name(char *param_1)

{
  char cVar1;
  uint uVar2;
  size_t sVar3;
  char *pcVar4;
  
  uVar2 = 0xffffffff;
  pcVar4 = param_1;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  sVar3 = 0x11;
  if (~uVar2 - 1 < 0x11) {
    sVar3 = ~uVar2;
  }
  _bcopy(param_1,(void *)(_active_u + 8),sVar3);
  return;
}

