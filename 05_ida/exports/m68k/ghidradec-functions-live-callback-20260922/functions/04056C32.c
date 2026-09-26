
int _kern_serv_port_serv(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_1;
  if (param_2 == *(int *)(iVar1 + 0x4ac)) {
    *(undefined4 *)(iVar1 + 0x4ac) = 0;
  }
  iVar2 = 0;
  iVar3 = iVar1;
  do {
    if (param_2 == *(int *)(iVar3 + 0x18c)) {
      *(undefined4 *)(iVar3 + 0x18c) = 0;
    }
    iVar3 = iVar3 + 0x10;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x32);
  iVar2 = 0;
  iVar3 = iVar1;
  do {
    if (*(int *)(iVar3 + 0x18c) == 0) break;
    iVar3 = iVar3 + 0x10;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x32);
  iVar3 = 6;
  if (iVar2 != 0x32) {
    iVar3 = _port_set_add_EXTERNAL(*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar1 + 0x20),param_2)
    ;
    if (iVar3 == 0) {
      iVar1 = iVar1 + iVar2 * 0x10;
      *(int *)(iVar1 + 0x18c) = param_2;
      *(undefined4 *)(iVar1 + 400) = param_3;
      *(undefined4 *)(iVar1 + 0x194) = param_4;
      *(undefined4 *)(iVar1 + 0x198) = 1;
      iVar3 = 0;
    }
  }
  return iVar3;
}

