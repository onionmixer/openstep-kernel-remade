
int _mach_port_dnrequest_info(int param_1,undefined4 param_2,uint *param_3,int *param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iStack_8;
  
  if (param_1 == 0) {
    iVar1 = 0x10;
  }
  else {
    iVar1 = _ipc_object_translate(param_1,param_2,1,&iStack_8);
    if (iVar1 == 0) {
      iVar1 = *(int *)(iStack_8 + 0x28);
      if (iVar1 == 0) {
        uVar4 = 0;
        iVar3 = 0;
      }
      else {
        uVar4 = **(uint **)(iVar1 + 4);
        uVar2 = 1;
        iVar3 = 0;
        if (1 < uVar4) {
          do {
            if (*(int *)(iVar1 + 0xc) != 0) {
              iVar3 = iVar3 + 1;
            }
            uVar2 = uVar2 + 1;
            iVar1 = iVar1 + 8;
          } while (uVar2 < uVar4);
        }
      }
      *param_3 = uVar4;
      *param_4 = iVar3;
      iVar1 = 0;
    }
  }
  return iVar1;
}
