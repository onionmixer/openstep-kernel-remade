
void sub_407BB30(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = *param_1;
  iVar2 = *(int *)(*(int *)(iVar1 + 0x10) + 8);
  iVar3 = *(int *)((int)param_1 + 0x226);
  if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aScmsginNoCurre);
  }
  if (*(char *)((int)param_1 + 0x21f) == '\x01') {
    *(undefined *)((int)param_1 + 0x236) = 8;
    goto loc_407BC40;
  }
  switch(*(undefined *)((int)param_1 + 0x236)) {
  case :
    break;
  :
    if (*(char *)((int)param_1 + 0x236) < '\0') break;
    goto loc_407BC2C;
  case :
    *(undefined4 *)(iVar3 + 0x32) = *(undefined4 *)((int)param_1 + 0x22a);
    uVar4 = *(undefined4 *)((int)param_1 + 0x22e);
    *(undefined4 *)(iVar3 + 0x46) = uVar4;
    *(undefined4 *)(iVar3 + 0x36) = uVar4;
    *(int *)(iVar3 + 0x3a) = *(int *)((int)param_1 + 0x232) + -1;
    break;
  case :
    *(undefined4 *)((int)param_1 + 0x22a) = *(undefined4 *)(iVar3 + 0x32);
    *(undefined4 *)((int)param_1 + 0x22e) = *(undefined4 *)(iVar3 + 0x36);
    *(int *)((int)param_1 + 0x232) = *(int *)(iVar3 + 0x3a) + 1;
    break;
  case :
    if (((*(byte *)(iVar3 + 0x24) & 0x10) != 0) && (*(char *)(param_1 + 0x3f) != '\0')) break;
    *(undefined *)((int)param_1 + 0x236) = 8;
loc_407BC2C:
    sub_407BC86(param_1,7,3);
    break;
  case :
    _printf(aScMessageRejec);
    break;
  case :
  case :
    sub_407BCB6(iVar1,0,aLinkedCommand);
  }
loc_407BC40:
  if ((*(byte *)((int)param_1 + 0x225) & 8) == 0) {
    sub_407BCB6(iVar1,0,aScmsginNoFuncc);
  }
  else {
    *(undefined *)((int)param_1 + 0x21e) = 7;
    *(undefined *)(iVar2 + 3) = 0x12;
    *(int *)(iVar1 + 0x5c) = _hz * *(int *)(iVar3 + 0x42);
    *(undefined *)(iVar1 + 0x5b) = 1;
  }
  return;
}
