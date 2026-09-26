
void _kern_serv_port_gone(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (iVar2 != 0) {
    if (param_2 == *(int *)(iVar2 + 0x4b0)) {
      *(undefined4 *)(iVar2 + 0x4b0) = 0;
    }
    iVar1 = 0;
    do {
      if (param_2 == *(int *)(iVar2 + 0x18c)) {
        *(undefined4 *)(iVar2 + 0x18c) = 0;
        *(undefined4 *)(iVar2 + 400) = 0;
        return;
      }
      iVar2 = iVar2 + 0x10;
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x32);
  }
  return;
}
