
void _ipc_task_init(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  word wVar3;
  sword sVar4;
  undefined4 uStack_8;
  
  iVar1 = _ipc_space_create(_ipc_table_entries,&uStack_8);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aIpcTaskInit);
  }
  iVar1 = _ipc_port_alloc_special(_ipc_space_kernel);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aIpcTaskInit);
  }
  *(int *)(param_1 + 0x5c) = iVar1;
  uVar2 = _ipc_port_make_send(iVar1);
  *(undefined4 *)(param_1 + 0x60) = uVar2;
  *(undefined4 *)(param_1 + 0x7c) = uStack_8;
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 100) = 0;
    *(undefined4 *)(param_1 + 0x68) = 0;
    iVar1 = 3;
    do {
      do {
        *(undefined4 *)(param_1 + 0x6c + iVar1 * 4) = 0;
        wVar3 = (word)((uint)iVar1 >> 0x10);
        sVar4 = (sword)iVar1 + -1;
        iVar1 = CONCAT22(wVar3,sVar4);
      } while (sVar4 != -1);
      iVar1 = (uint)wVar3 * 0x10000 + -1;
    } while (wVar3 != 0);
  }
  else {
    iVar1 = 0;
    do {
      uVar2 = _ipc_port_copy_send(*(undefined4 *)(param_2 + 0x6c + iVar1 * 4));
      *(undefined4 *)(param_1 + 0x6c + iVar1 * 4) = uVar2;
      iVar1 = iVar1 + 1;
    } while (iVar1 < 4);
    uVar2 = _ipc_port_copy_send(*(undefined4 *)(param_2 + 100));
    *(undefined4 *)(param_1 + 100) = uVar2;
    uVar2 = _ipc_port_copy_send(*(undefined4 *)(param_2 + 0x68));
    *(undefined4 *)(param_1 + 0x68) = uVar2;
  }
  return;
}

