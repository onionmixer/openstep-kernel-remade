/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00181a60 */

int FUN_00181a60(int param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  size_t sVar4;
  char *pcVar5;
  int local_10;
  int local_c;
  undefined *local_8;
  
  local_c = param_1;
  local_8 = PTR_s_Object_001f9ff0;
  _objc_msgSendSuper(&local_c,PTR_s_init_001f924c);
  cVar1 = *param_3;
  while ((cVar1 != '\0' && ((*param_3 == ' ' || ((byte)(*param_3 - 9U) < 2))))) {
    param_3 = param_3 + 1;
    cVar1 = *param_3;
  }
  cVar1 = *param_3;
  pcVar5 = param_3;
  while (cVar1 != '\0') {
    do {
      if ((*pcVar5 != ' ') && (1 < (byte)(*pcVar5 - 9U))) break;
      pcVar5 = pcVar5 + 1;
    } while (*pcVar5 != '\0');
    if (*pcVar5 == '\0') break;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    while( true ) {
      if (*pcVar5 == '\0') goto LAB_00181af0;
      if ((*pcVar5 == ' ') || ((byte)(*pcVar5 - 9U) < 2)) break;
      pcVar5 = pcVar5 + 1;
    }
    cVar1 = *pcVar5;
  }
LAB_00181af0:
  uVar2 = _IOMalloc(*(int *)(param_1 + 8) * 4);
  *(undefined4 *)(param_1 + 4) = uVar2;
  local_10 = 0;
  do {
    if ((param_3 == (char *)0x0) || (*param_3 == '\0')) {
      return param_1;
    }
    pcVar5 = param_3;
    if (*param_3 != ' ') {
      while (1 < (byte)(*pcVar5 - 9U)) {
        pcVar5 = pcVar5 + 1;
        if ((*pcVar5 == '\0') || (*pcVar5 == ' ')) break;
      }
    }
    sVar4 = (int)pcVar5 - (int)param_3;
    pcVar3 = (char *)_IOMalloc(sVar4 + 1);
    *(char **)(*(int *)(param_1 + 4) + local_10 * 4) = pcVar3;
    _strncpy(pcVar3,param_3,sVar4);
    pcVar3[sVar4] = '\0';
    cVar1 = *pcVar5;
    param_3 = pcVar5;
    while ((cVar1 != '\0' && ((*param_3 == ' ' || ((byte)(*param_3 - 9U) < 2))))) {
      param_3 = param_3 + 1;
      cVar1 = *param_3;
    }
    local_10 = local_10 + 1;
  } while( true );
}

