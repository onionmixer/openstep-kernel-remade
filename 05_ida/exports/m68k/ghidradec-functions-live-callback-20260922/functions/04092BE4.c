
void _pmonlogcontextflush(undefined4 param_1,undefined4 param_2)

{
  if (_vm_saved_context_flushed == 0) {
    _vm_saved_context_flushed = 1;
    _pmonlogevent(param_1,param_2,_vm_saved_context_thread,
                  CONCAT22(_vm_saved_context_data0,_vm_saved_context_data1),0);
    _pmonlogevent(param_1,0x20000000,_vm_saved_context_name,dword_40C9484,unk_40C9488);
  }
  return;
}

