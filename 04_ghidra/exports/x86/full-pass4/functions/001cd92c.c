/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cd92c */

int FUN_001cd92c(char *param_1,char param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  
  iVar3 = 0;
  cVar1 = *param_1;
  pcVar2 = param_1;
  do {
    if (cVar1 == '\0') {
      __NXLogError("Object: SubTypeUntil: end of type encountered prematurely\n");
      return 0;
    }
    if ((iVar3 == 0) && (*pcVar2 == param_2)) {
      return (int)pcVar2 - (int)param_1;
    }
    cVar1 = *pcVar2;
    if (cVar1 == '[') {
LAB_001cd988:
      iVar3 = iVar3 + 1;
    }
    else {
      if (cVar1 < '\\') {
        if (cVar1 != '(') {
          if (cVar1 == ')') goto LAB_001cd985;
          goto LAB_001cd989;
        }
        goto LAB_001cd988;
      }
      if (cVar1 == '{') goto LAB_001cd988;
      if (cVar1 < '|') {
        if (cVar1 == ']') {
LAB_001cd985:
          iVar3 = iVar3 + -1;
        }
      }
      else if (cVar1 == '}') goto LAB_001cd985;
    }
LAB_001cd989:
    pcVar2 = pcVar2 + 1;
    cVar1 = *pcVar2;
  } while( true );
}

