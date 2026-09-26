
void _ipc_kmsg_clean(int param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)(param_1 + 0x14);
  if (*(int *)(param_1 + 0xc) != 0) {
    _ipc_marequest_destroy(*(int *)(param_1 + 0xc));
  }
  iVar2 = *(int *)(param_1 + 0x1c);
  if ((iVar2 != 0) && (iVar2 != -1)) {
    _ipc_object_destroy(iVar2,uVar1 & 0xff);
  }
  iVar2 = *(int *)(param_1 + 0x20);
  if ((iVar2 != 0) && (iVar2 != -1)) {
    _ipc_object_destroy(iVar2,(uVar1 & 0xffff) >> 8);
  }
  if ((int)uVar1 < 0) {
    _ipc_kmsg_clean_body(param_1 + 0x2c,param_1 + *(int *)(param_1 + 0x18) + 0x14);
  }
  return;
}

