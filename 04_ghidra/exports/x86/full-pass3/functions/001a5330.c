/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a5330 */

void FUN_001a5330(int param_1)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  int local_c;
  undefined *local_8;
  
  pcVar2 = *(char **)(param_1 + 4);
  if (pcVar2 != (char *)0x0) {
    uVar3 = 0xffffffff;
    pcVar4 = pcVar2;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    _IOFree(pcVar2,~uVar3);
  }
  local_c = param_1;
  local_8 = PTR_s_Object_001fa0e0;
  _objc_msgSendSuper(&local_c,PTR_s_free_001f921c);
  return;
}

