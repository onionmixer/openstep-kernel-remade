
int _ipc_port_timestamp(void)

{
  int iVar1;
  
  iVar1 = _ipc_port_timestamp_data;
  _ipc_port_timestamp_data = _ipc_port_timestamp_data + 1;
  return iVar1;
}

