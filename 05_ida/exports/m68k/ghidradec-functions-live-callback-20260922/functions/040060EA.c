
undefined4 _init_process(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _suser();
  if (iVar1 == 0) {
    uVar2 = 8;
  }
  else {
    iVar1 = *_active_u;
    if (*(int *)(iVar1 + 0x4a) != 0) {
      *(undefined4 *)(*(int *)(iVar1 + 0x4a) + 0x4e) = *(undefined4 *)(iVar1 + 0x4e);
    }
    if (*(int *)(iVar1 + 0x4e) != 0) {
      *(undefined4 *)(*(int *)(iVar1 + 0x4e) + 0x4a) = *(undefined4 *)(iVar1 + 0x4a);
    }
    if (iVar1 == *(int *)(*(int *)(iVar1 + 0x42) + 0x46)) {
      *(undefined4 *)(*(int *)(iVar1 + 0x42) + 0x46) = *(undefined4 *)(iVar1 + 0x4a);
    }
    *(int *)(iVar1 + 0x42) = iVar1;
    *(undefined4 *)(iVar1 + 0x4a) = 0;
    *(undefined4 *)(iVar1 + 0x4e) = 0;
    if (*(sword *)(iVar1 + 0x30) != *(sword *)(iVar1 + 0x2e)) {
      _enterpgrp(iVar1,(int)*(sword *)(iVar1 + 0x30),0);
    }
    *(undefined2 *)(iVar1 + 0x32) = 0;
    uVar2 = 0;
  }
  return uVar2;
}

