/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001519c8 */

void _ipc_table_init(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 local_18;
  
  iVar2 = _kalloc(_ipc_table_entries_size * 4);
  uVar5 = _page_size;
  uVar3 = _ipc_table_entries_size - 1;
  uVar4 = 0;
  local_18 = 1;
  _ipc_table_entries = iVar2;
  uVar1 = _page_size;
  if (_ipc_table_entries_size != 1) {
    do {
      uVar1 = _page_size;
      if (uVar5 <= local_18) break;
      if (0x3f < local_18) {
        *(uint *)(iVar2 + uVar4 * 4) = local_18 / 0x10;
        uVar4 = uVar4 + 1;
      }
      local_18 = local_18 << 1;
      uVar1 = _page_size;
    } while (uVar4 < uVar3);
  }
  while (uVar4 < uVar3) {
    uVar5 = 0;
    do {
      if (uVar3 <= uVar4) break;
      if (0x3f < local_18) {
        *(uint *)(iVar2 + uVar4 * 4) = local_18 / 0x10;
        uVar4 = uVar4 + 1;
      }
      uVar5 = uVar5 + 1;
      local_18 = local_18 + uVar1;
    } while (uVar5 < 0xf);
    uVar1 = uVar1 * 2;
  }
  *(undefined4 *)(_ipc_table_entries + -4 + _ipc_table_entries_size * 4) =
       *(undefined4 *)(_ipc_table_entries + -8 + _ipc_table_entries_size * 4);
  iVar2 = _kalloc(_ipc_table_dnrequests_size * 4);
  uVar5 = _page_size;
  uVar3 = _ipc_table_dnrequests_size - 1;
  uVar4 = 0;
  local_18 = 1;
  _ipc_table_dnrequests = iVar2;
  uVar1 = _page_size;
  if (_ipc_table_dnrequests_size != 1) {
    do {
      uVar1 = _page_size;
      if (uVar5 <= local_18) break;
      if (0xf < local_18) {
        *(uint *)(iVar2 + uVar4 * 4) = local_18 / 8;
        uVar4 = uVar4 + 1;
      }
      local_18 = local_18 << 1;
      uVar1 = _page_size;
    } while (uVar4 < uVar3);
  }
  do {
    if (uVar3 <= uVar4) {
      *(undefined4 *)(_ipc_table_dnrequests + -4 + _ipc_table_dnrequests_size * 4) = 0;
      return;
    }
    uVar5 = 0;
    do {
      if (uVar3 <= uVar4) break;
      if (0xf < local_18) {
        *(uint *)(iVar2 + uVar4 * 4) = local_18 / 8;
        uVar4 = uVar4 + 1;
      }
      uVar5 = uVar5 + 1;
      local_18 = local_18 + uVar1;
    } while (uVar5 < 0xf);
    uVar1 = uVar1 * 2;
  } while( true );
}

