
void _ipc_kobject_destroy(int param_1)

{
  word wVar1;
  
  wVar1 = *(word *)(param_1 + 6);
  if (wVar1 == 9) {
    _vm_object_pager_wakeup(param_1);
  }
  else if (wVar1 < 10) {
    if (wVar1 == 8) {
      _vm_object_destroy(param_1);
    }
  }
  else if (wVar1 == 0x11) {
    _netipc_ignore(0,param_1);
  }
  return;
}

