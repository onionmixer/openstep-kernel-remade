
undefined4 * _ifunit(char *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  char *pcVar4;
  
  for (pcVar4 = param_1; pcVar4 < param_1 + 0x10; pcVar4 = pcVar4 + 1) {
    if (*pcVar4 == '\0') goto loc_401BE6A;
    if ((byte)(*pcVar4 - 0x30U) < 10) break;
  }
  cVar1 = *pcVar4;
  if ((cVar1 == '\0') || (param_1 + 0x10 == pcVar4)) {
loc_401BE6A:
    puVar2 = (undefined4 *)0x0;
  }
  else {
    for (puVar2 = _ifnet;
        (puVar2 != (undefined4 *)0x0 &&
        (((iVar3 = _bcmp(*puVar2,param_1,(int)pcVar4 - (int)param_1), iVar3 != 0 ||
          (*(int *)((int)puVar2 + 0x12) != 0x1000)) ||
         ((int)*(sword *)(puVar2 + 2) != cVar1 + -0x30))));
        puVar2 = *(undefined4 **)((int)puVar2 + 0x5a)) {
    }
  }
  return puVar2;
}
