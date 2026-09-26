
undefined * _ipc_kobject_server(undefined *param_1)

{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  int iVar4;
  code *pcVar5;
  undefined **ppuVar6;
  undefined *puStack_1c;
  undefined *puStack_18;
  
  puStack_18 = (undefined *)0x800;
  puStack_1c = (undefined *)0x4048658;
  puVar3 = (undefined *)_kalloc();
  if (puVar3 == (undefined *)0x0) {
    puStack_18 = aIpcKobjectServ;
    puStack_1c = (undefined *)0x404866c;
    _printf();
    ppuVar6 = &puStack_1c;
    puStack_1c = param_1;
    goto loc_40487F6;
  }
  *(undefined4 *)(puVar3 + 8) = 0x800;
  *(undefined4 *)(puVar3 + 0xc) = 0;
  *(undefined4 *)(puVar3 + 0x10) = 0;
  *(uint *)(puVar3 + 0x14) = (uint)(byte)param_1[0x16];
  *(undefined4 *)(puVar3 + 0x18) = 0x20;
  *(undefined4 *)(puVar3 + 0x1c) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(puVar3 + 0x20) = 0;
  *(undefined4 *)(puVar3 + 0x24) = 0;
  *(int *)(puVar3 + 0x28) = *(int *)(param_1 + 0x28) + 100;
  *(undefined4 *)(puVar3 + 0x2c) = dword_40AF788;
  puStack_18 = param_1;
  puStack_1c = (undefined *)0x40486b6;
  iVar4 = _netipc_msg_send();
  if (iVar4 == 0) {
    puVar1 = param_1 + 0x14;
    puStack_1c = (undefined *)0x40486d2;
    puStack_18 = puVar1;
    pcVar5 = (code *)_mach_server_routine();
    if (pcVar5 == (code *)0x0) {
      puStack_1c = (undefined *)0x40486e2;
      puStack_18 = puVar1;
      pcVar5 = (code *)_mach_port_server_routine();
      if (pcVar5 == (code *)0x0) {
        puStack_1c = (undefined *)0x40486f2;
        puStack_18 = puVar1;
        pcVar5 = (code *)_mach_host_server_routine();
        if (pcVar5 == (code *)0x0) {
          puStack_1c = (undefined *)0x4048702;
          puStack_18 = puVar1;
          pcVar5 = (code *)_mach_debug_server_routine();
          if (pcVar5 == (code *)0x0) {
            puStack_18 = puVar3 + 0x14;
            puStack_1c = puVar1;
            iVar4 = _ipc_kobject_notify();
            if (iVar4 == 0) {
              *(undefined4 *)(puVar3 + 0x30) = 0xfffffed1;
            }
            goto loc_4048732;
          }
        }
      }
    }
    puStack_18 = puVar3 + 0x14;
    puStack_1c = param_1 + 0x14;
    (*pcVar5)();
  }
  else {
    *(undefined4 *)(puVar3 + 0x30) = 0xfffffecf;
  }
loc_4048732:
  puVar2 = (undefined4 *)(param_1 + 0x1c);
  if (param_1[0x17] == '\x11') {
    puStack_18 = (undefined *)*puVar2;
    puStack_1c = (undefined *)0x4048752;
    _ipc_port_release_send();
  }
  else {
    if (param_1[0x17] != '\x12') {
      puStack_18 = aIpcObjectDestr;
                    /* WARNING: Subroutine does not return */
      puStack_1c = (undefined *)0x404876a;
      _panic();
    }
    puStack_18 = (undefined *)*puVar2;
    puStack_1c = (undefined *)0x404875c;
    _ipc_port_release_sonce();
  }
  *puVar2 = 0;
  iVar4 = *(int *)(puVar3 + 0x30);
  if ((iVar4 == 0) || (iVar4 == -0x131)) {
    *(undefined4 *)(param_1 + 0x10) = 0;
    if ((*(int *)(param_1 + 8) == 0x100) && (_ipc_kmsg_cache == (undefined *)0x0)) {
      _ipc_kmsg_cache = param_1;
    }
    else {
      puStack_18 = *(undefined **)(param_1 + 8);
      if ((int)puStack_18 < 1) {
        puStack_18 = param_1;
        puStack_1c = (undefined *)0x40487a6;
        _ipc_kmsg_free();
      }
      else {
        puStack_1c = param_1;
        _kfree();
      }
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x20) = 0;
    puStack_18 = param_1;
    puStack_1c = (undefined *)0x40487ce;
    _ipc_kmsg_destroy();
  }
  if (iVar4 == -0x131) {
    puStack_18 = *(undefined **)(puVar3 + 8);
    if ((int)puStack_18 < 1) {
      puStack_1c = (undefined *)0x40487e6;
      puStack_18 = puVar3;
      _ipc_kmsg_free();
      return (undefined *)0x0;
    }
    puStack_1c = puVar3;
    _kfree();
    return (undefined *)0x0;
  }
  if ((*(int *)(puVar3 + 0x1c) != 0) && (*(int *)(puVar3 + 0x1c) != -1)) {
    return puVar3;
  }
  ppuVar6 = &puStack_18;
  puStack_18 = puVar3;
loc_40487F6:
  *(undefined4 *)((int)ppuVar6 + -4) = 0x40487fc;
  _ipc_kmsg_destroy();
  return (undefined *)0x0;
}

