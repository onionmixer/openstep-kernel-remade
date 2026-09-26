/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00181bdc */

void FUN_00181bdc(int param_1)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  int local_c;
  undefined *local_8;
  
  uVar4 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    do {
      pcVar2 = *(char **)(*(int *)(param_1 + 4) + uVar4 * 4);
      uVar3 = 0xffffffff;
      pcVar5 = pcVar2;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      _IOFree(pcVar2,~uVar3);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(param_1 + 8));
  }
  _IOFree(*(undefined4 *)(param_1 + 4),*(int *)(param_1 + 8) << 2);
  local_c = param_1;
  local_8 = PTR_s_Object_001f9ff0;
  _objc_msgSendSuper(&local_c,PTR_s_free_001f921c);
  return;
}

