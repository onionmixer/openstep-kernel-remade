
void _ipc_notify_init(void)

{
  _ipc_notify_init_port_deleted(&_ipc_notify_port_deleted_template);
  _ipc_notify_init_msg_accepted(&_ipc_notify_msg_accepted_template);
  _ipc_notify_init_port_destroyed(&_ipc_notify_port_destroyed_template);
  _ipc_notify_init_no_senders(&_ipc_notify_no_senders_template);
  _ipc_notify_init_send_once(&_ipc_notify_send_once_template);
  _ipc_notify_init_dead_name(&_ipc_notify_dead_name_template);
  return;
}

