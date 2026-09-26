
/* WARNING: Unknown calling convention */

ifreq_result_bytes * FUN_00124cb8(ifreq_result_bytes *result_buffer,void *ifp,void *sin)

{
  int iVar1;
  char *pcVar2;
  ifreq_result_bytes *piVar3;
  char local_24;
  char local_23 [15];
  undefined1 local_14 [16];
  
  pcVar2 = &local_24;
  _strcpy(pcVar2,*(char **)ifp);
  while (local_24 != '\0') {
    pcVar2 = pcVar2 + 1;
    local_24 = *pcVar2;
  }
  *pcVar2 = (char)*(undefined2 *)((int)ifp + 8) + '0';
  pcVar2[1] = '\0';
  _bcopy(sin,local_14,0x10);
  pcVar2 = &local_24;
  piVar3 = result_buffer;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined4 *)piVar3->name = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    piVar3 = (ifreq_result_bytes *)(piVar3->name + 4);
  }
  return result_buffer;
}

