/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cdd3c */

void __NXLogError(char *param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  
  _vlog(3,param_1,&stack0x00000008);
  uVar2 = 0xffffffff;
  pcVar3 = param_1;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if (param_1[~uVar2 - 2] != '\n') {
    _log(3,"\n");
  }
  return;
}

