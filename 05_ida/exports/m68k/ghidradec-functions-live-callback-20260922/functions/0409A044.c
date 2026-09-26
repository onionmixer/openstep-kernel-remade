
void _unix_syscall(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iStack_14;
  word *pwStack_10;
  int *piStack_c;
  
  iVar2 = _active_threads;
  iStack_14 = 0;
  puVar1 = *(undefined4 **)(_active_threads + 0x80);
  iVar3 = *param_1;
  if ((iVar3 < 0) || (_nsysent <= iVar3)) {
    pwStack_10 = (word *)DAT_40add4c;
  }
  else {
    pwStack_10 = (word *)(_sysent + iVar3 * 8);
  }
  if (**(int **)(*(int *)(_active_threads + 0xc) + 0x30) == 0) {
    _exception(5,0x10000,0);
  }
  *puVar1 = param_1;
  *(int **)(*(int *)(iVar2 + 0x24) + 0x48) = param_1;
  *(undefined *)(puVar1 + 0x19) = 0;
  piStack_c = param_1 + 1;
  if (pwStack_10 == (word *)_sysent) {
    iVar3 = *piStack_c;
    piStack_c = param_1 + 2;
    if ((iVar3 < 0) || (_nsysent <= iVar3)) {
      pwStack_10 = (word *)DAT_40add4c;
    }
    else {
      pwStack_10 = (word *)(_sysent + iVar3 * 8);
    }
  }
  if (0 < (sword)*pwStack_10) {
    _bcopy(piStack_c,puVar1 + 1,(int)((uint)*pwStack_10 << 0x10) >> 0xe);
  }
  puVar1[0x17] = 0;
  iVar3 = _setjmp(puVar1 + 10);
  if (iVar3 == 0) {
    *(undefined *)((int)puVar1 + 0x65) = 3;
    *(undefined *)((int)puVar1 + 0x6a) = 0;
    *(undefined4 *)((int)puVar1 + 0x66) = 0;
    (**(code **)(pwStack_10 + 2))();
    iStack_14 = (int)*(char *)(puVar1 + 0x19);
  }
  else if ((*(char *)(*(int *)(_active_threads + 0x80) + 100) == '\0') &&
          (*(char *)(*(int *)(_active_threads + 0x80) + 0x65) != '\x02')) {
    iStack_14 = 4;
  }
  _unix_syscall_return(iStack_14);
  return;
}

