
undefined4 sub_40315CE(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  *(sword *)(param_2 + 0x88) = *(sword *)(param_2 + 0x88) + -1;
  if (param_1 == *(undefined4 **)(param_2 + 0x6a)) {
    *(undefined4 *)(param_2 + 0x6a) = 0;
    uVar1 = 0;
  }
  else {
    uVar1 = *param_1;
  }
  _kmem_free(_kernel_map,param_1,dword_40AF740);
  if (dword_40AF744 <= _fifo_alloc) {
    _wakeup(&_fifo_alloc);
  }
  _fifo_alloc = _fifo_alloc - dword_40AF740;
  return uVar1;
}
