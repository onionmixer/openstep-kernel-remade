
undefined4 * FUN_00124cb8(undefined4 *param_1,void *param_2)

{
  int iVar1;
  char *pcVar2;
  undefined4 *unaff_EBX;
  undefined4 *puVar3;
  char local_24;
  char local_23 [15];
  undefined1 local_14 [16];
  
  pcVar2 = &local_24;
  _strcpy(pcVar2,(char *)*param_1);
  while (local_24 != '\0') {
    pcVar2 = pcVar2 + 1;
    local_24 = *pcVar2;
  }
  *pcVar2 = (char)*(undefined2 *)(param_1 + 2) + '0';
  pcVar2[1] = '\0';
  _bcopy(param_2,local_14,0x10);
  pcVar2 = &local_24;
  puVar3 = unaff_EBX;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    puVar3 = puVar3 + 1;
  }
  return unaff_EBX;
}

