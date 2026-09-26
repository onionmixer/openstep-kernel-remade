
void _ipc_table_init(void)

{
  _ipc_table_entries = _kalloc(_ipc_table_entries_size << 2);
  _ipc_table_fill(_ipc_table_entries,_ipc_table_entries_size + -1,4,0x10);
  *(undefined4 *)(_ipc_table_entries + -4 + _ipc_table_entries_size * 4) =
       *(undefined4 *)(_ipc_table_entries + -8 + _ipc_table_entries_size * 4);
  _ipc_table_dnrequests = _kalloc(_ipc_table_dnrequests_size << 2);
  _ipc_table_fill(_ipc_table_dnrequests,_ipc_table_dnrequests_size + -1,2,8);
  *(undefined4 *)(_ipc_table_dnrequests + -4 + _ipc_table_dnrequests_size * 4) = 0;
  return;
}

