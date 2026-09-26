
void _ipc_marequest_destroy(uint *param_1)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  
  uVar1 = *param_1;
  iVar6 = 0;
  uVar5 = param_1[1];
  uVar3 = param_1[2];
  if (uVar5 != 0) {
    puVar7 = (uint *)(_ipc_marequest_table +
                     (_ipc_marequest_mask & (uVar5 & 0xff) + (uVar5 >> 8) + (uVar1 >> 4)) * 4);
    while ((puVar2 = (uint *)*puVar7, puVar2 != (uint *)0x0 &&
           ((uVar1 != *puVar2 || (uVar5 != puVar2[1]))))) {
      puVar7 = puVar2 + 3;
    }
    *puVar7 = puVar2[3];
    if (*(int *)(uVar1 + 4) == 0) {
      uVar5 = 0;
    }
    else {
      iVar4 = _ipc_entry_lookup(uVar1,uVar5);
      *(byte *)(iVar4 + 1) = *(byte *)(iVar4 + 1) & 0xdf;
      if (uVar3 == 0) {
        iVar6 = _ipc_port_copy_send(*(undefined4 *)(uVar1 + 0x3c));
      }
    }
  }
  _ipc_space_release(uVar1);
  _zfree(_ipc_marequest_zone,param_1);
  if (uVar3 == 0) {
    if ((iVar6 != 0) && (iVar6 != -1)) {
      _ipc_notify_msg_accepted_compat(iVar6,uVar5);
    }
  }
  else {
    _ipc_notify_msg_accepted(uVar3,uVar5);
  }
  return;
}
