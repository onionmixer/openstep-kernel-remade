
void sub_40683B6(void)

{
  int iVar1;
  undefined4 uStack_8;
  
loc_40683C4:
  do {
    if (dword_40B4F62 == 0) {
      _assert_wait(&_eventMsg,1);
      _thread_block();
    }
    dword_40B4F62 = 0;
  } while (_eventsOpen == 0);
  iVar1 = _ipc_kmsg_get_from_kernel(&_eventMsg,unk_40B1232._0_4_,0,&uStack_8);
  if (iVar1 == 0) goto loc_4068420;
  goto loc_4068440;
loc_4068420:
  _ipc_kmsg_copyin_compat_from_kernel(uStack_8);
  iVar1 = _ipc_mqueue_send(uStack_8,0,0);
  if (iVar1 != 0) {
loc_4068440:
    _printf(aEvmsgthreadpro,iVar1);
  }
  goto loc_40683C4;
}

