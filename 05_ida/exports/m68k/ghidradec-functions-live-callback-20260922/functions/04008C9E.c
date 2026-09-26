
void _sigstack(void)

{
  int *piVar1;
  int iVar2;
  undefined uVar3;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  piVar1 = *(int **)(dword_40B57D4 + 0x24);
  iVar2 = piVar1[1];
  if (iVar2 != 0) {
    uVar3 = _copyoutmsg(_active_u + 0x13e,iVar2,8);
    *(undefined *)(dword_40B57D4 + 100) = uVar3;
    if (*(char *)(dword_40B57D4 + 100) != '\0') {
      return;
    }
  }
  iVar2 = *piVar1;
  if (iVar2 != 0) {
    uVar3 = _copyinmsg(iVar2,&uStack_c,8);
    *(undefined *)(dword_40B57D4 + 100) = uVar3;
    iVar2 = _active_u;
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      *(undefined4 *)(_active_u + 0x13e) = uStack_c;
      *(undefined4 *)(iVar2 + 0x142) = uStack_8;
    }
  }
  return;
}

