
void _vol_start_thread(void)

{
  int iVar1;
  undefined1 auStack_8 [4];
  
  iVar1 = _ipc_port_alloc(*(undefined4 *)(_kernel_task + 0x7c),auStack_8,&DAT_040b06f4);
  if (iVar1 == 0) {
    DAT_040b06f8 = *(undefined4 *)(DAT_040b06f4 + 0xc);
    _kernel_thread(_kernel_task,&LAB_04063fde,0);
    DAT_040b0708 = &PTR_LOOP_040b0704;
    PTR_LOOP_040b0704 = (undefined *)&PTR_LOOP_040b0704;
    DAT_040b070c = 1;
    if (DAT_040b4e81 == '\0') {
      _lock_init(&DAT_040b4e82,1);
      DAT_040b4e81 = '\x01';
    }
  }
  else {
    _printf("vol_start_thread: port_alloc returned %d\n",iVar1);
  }
  return;
}

