
void _ipc_marequest_init(void)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  if ((_ipc_marequest_size == 0) &&
     (_ipc_marequest_size = _ipc_marequest_max >> 8, _ipc_marequest_size < 0x10)) {
    _ipc_marequest_size = 0x10;
  }
  _ipc_marequest_mask = _ipc_marequest_size - 1;
  if ((_ipc_marequest_mask & _ipc_marequest_size) != 0) {
    uVar3 = 1;
    while( true ) {
      _ipc_marequest_mask = uVar3 | _ipc_marequest_mask;
      _ipc_marequest_size = _ipc_marequest_mask + 1;
      if ((_ipc_marequest_mask & _ipc_marequest_size) == 0) break;
      uVar3 = uVar3 * 2;
    }
  }
  puVar2 = (undefined4 *)_kalloc(_ipc_marequest_size << 2);
  uVar1 = _ipc_marequest_size;
  uVar3 = 0;
  _ipc_marequest_table = puVar2;
  if (_ipc_marequest_size != 0) {
    do {
      *puVar2 = 0;
      uVar3 = uVar3 + 1;
      puVar2 = puVar2 + 1;
    } while (uVar3 < uVar1);
  }
  _ipc_marequest_zone = _zinit(0x10,_ipc_marequest_max << 4,0x10,0,aIpcMsgAccepted);
  _zchange(_ipc_marequest_zone,0,0,1,0);
  return;
}
