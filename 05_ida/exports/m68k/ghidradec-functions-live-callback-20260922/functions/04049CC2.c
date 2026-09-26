
undefined4 _mach_ports_lookup(int param_1,int *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else {
    puVar2 = (undefined4 *)_kalloc(0x10);
    if (puVar2 == (undefined4 *)0x0) {
      uVar1 = 6;
    }
    else if (*(int *)(param_1 + 0x5c) == 0) {
      _kfree(puVar2,0x10);
      uVar1 = 4;
    }
    else {
      iVar3 = 0;
      puVar4 = puVar2;
      do {
        uVar1 = _ipc_port_copy_send(*(undefined4 *)(param_1 + 0x6c + iVar3 * 4));
        *puVar4 = uVar1;
        iVar3 = iVar3 + 1;
        puVar4 = puVar4 + 1;
      } while (iVar3 < 4);
      *param_2 = (int)puVar2;
      *param_3 = 4;
      uVar1 = 0;
    }
  }
  return uVar1;
}

