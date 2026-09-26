/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014a0d8 */

void _ipc_marequest_init(void)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  
  if ((_ipc_marequest_size == 0) &&
     (_ipc_marequest_size = _ipc_marequest_max >> 8, _ipc_marequest_size < 0x10)) {
    _ipc_marequest_size = 0x10;
  }
  _ipc_marequest_mask = _ipc_marequest_size - 1;
  if ((_ipc_marequest_mask & _ipc_marequest_size) != 0) {
    uVar2 = 1;
    _ipc_marequest_mask = _ipc_marequest_mask | 1;
    while( true ) {
      _ipc_marequest_size = _ipc_marequest_mask + 1;
      if ((_ipc_marequest_mask & _ipc_marequest_size) == 0) break;
      uVar2 = uVar2 * 2;
      _ipc_marequest_mask = _ipc_marequest_mask | uVar2;
    }
  }
  puVar1 = (undefined4 *)_kalloc(_ipc_marequest_size * 8);
  uVar2 = _ipc_marequest_size;
  uVar3 = 0;
  _ipc_marequest_table = puVar1;
  if (_ipc_marequest_size != 0) {
    do {
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1 = puVar1 + 2;
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar2);
  }
  _ipc_marequest_zone =
       _zinit(0x10,_ipc_marequest_max << 4,0x10,0,s_ipc_msg_accepted_requests_001de714);
  _zchange(_ipc_marequest_zone,0,0,1,0);
  return;
}

