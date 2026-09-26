
void _ipc_port_destroy(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined *puVar10;
  uint uStack_24;
  uint *puVar11;
  
  puVar10 = &stack0xffffffe0;
  uVar2 = *(uint *)(param_1 + 0x24);
  if (uVar2 == 0) goto loc_4041058;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  if ((uVar2 & 1) == 0) {
    uStack_24 = uVar2;
    iVar7 = _ipc_port_check_circularity(param_1);
    if (iVar7 == 0) {
      uStack_24 = param_1;
      _ipc_notify_port_destroyed(uVar2);
      return;
    }
    puVar11 = &uStack_24;
    uStack_24 = uVar2;
    _ipc_port_release_sonce();
  }
  else {
    uVar2 = uVar2 & 0xfffffffe;
    uStack_24 = uVar2;
    iVar7 = _ipc_port_check_circularity(param_1);
    if (iVar7 == 0) {
      uStack_24 = param_1;
      _ipc_notify_port_destroyed_compat(uVar2);
      return;
    }
    puVar11 = &uStack_24;
    uStack_24 = uVar2;
    _ipc_port_release_send();
  }
  while( true ) {
    puVar10 = (undefined *)((int)puVar11 + 4);
loc_4041058:
    *(uint *)(puVar10 + -4) = param_1 + 0x44;
    *(undefined4 *)(puVar10 + -8) = 0x4041062;
    iVar7 = _ipc_thread_dequeue();
    if (iVar7 == 0) break;
    *(undefined4 *)(iVar7 + 0x94) = 0;
    puVar11 = (uint *)(puVar10 + -4);
    *(int *)(puVar10 + -4) = iVar7;
    *(undefined4 *)(puVar10 + -8) = 0x4041076;
    _thread_go();
  }
  *(byte *)(param_1 + 4) = *(byte *)(param_1 + 4) & 0x7f;
  *(undefined4 *)(puVar10 + -4) = 0x4041084;
  uVar8 = _ipc_port_timestamp();
  *(undefined4 *)(param_1 + 8) = uVar8;
  if (*(int *)(param_1 + 0x20) != 0) {
    *(int *)(puVar10 + -4) = *(int *)(param_1 + 0x20);
    *(undefined4 *)(puVar10 + -8) = 0x4041096;
    _ipc_notify_send_once();
  }
  while( true ) {
    *(uint *)(puVar10 + -4) = param_1 + 0x3c;
    *(undefined4 *)(puVar10 + -8) = 0x40410a4;
    iVar7 = _ipc_kmsg_dequeue();
    if (iVar7 == 0) break;
    *(uint *)(puVar10 + -4) = param_1;
    *(undefined4 *)(puVar10 + -8) = 0x40410b4;
    _ipc_object_release();
    *(undefined4 *)(iVar7 + 0x1c) = 0;
    *(int *)(puVar10 + -8) = iVar7;
    *(undefined4 *)(puVar10 + -0xc) = 0x40410c0;
    _ipc_kmsg_destroy();
  }
  puVar3 = *(uint **)(param_1 + 0x28);
  if (puVar3 != (uint *)0x0) {
    puVar4 = (uint *)puVar3[1];
    uVar2 = *puVar4;
    uVar9 = 1;
    puVar6 = puVar3;
    if (1 < uVar2) {
      do {
        uVar5 = puVar6[3];
        if (uVar5 != 0) {
          uVar1 = puVar6[2];
          if ((uVar1 & 1) == 0) {
            *(uint *)(puVar10 + -4) = uVar5;
            *(uint *)(puVar10 + -8) = uVar1;
            *(undefined4 *)(puVar10 + -0xc) = 0x404110a;
            _ipc_notify_dead_name();
          }
          else {
            *(uint *)(puVar10 + -4) = uVar5;
            *(uint *)(puVar10 + -8) = uVar1 & 0xfffffffe;
            *(uint *)(puVar10 + -0xc) = param_1;
            *(undefined4 *)(puVar10 + -0x10) = 0x40410fa;
            _ipc_port_delete_compat();
          }
        }
        uVar9 = uVar9 + 1;
        puVar6 = puVar6 + 2;
      } while (uVar9 < uVar2);
    }
    *(uint **)(puVar10 + -4) = puVar3;
    *(uint *)(puVar10 + -8) = *puVar4 << 3;
    *(undefined4 *)(puVar10 + -0xc) = 0x4041122;
    _ipc_table_free();
  }
  if (*(sword *)(param_1 + 6) != 0) {
    *(uint *)(puVar10 + -4) = param_1;
    *(undefined4 *)(puVar10 + -8) = 0x4041132;
    _ipc_kobject_destroy();
  }
  *(uint *)(puVar10 + -4) = param_1;
  *(undefined4 *)(puVar10 + -8) = 0x404113c;
  _ipc_object_release();
  return;
}

