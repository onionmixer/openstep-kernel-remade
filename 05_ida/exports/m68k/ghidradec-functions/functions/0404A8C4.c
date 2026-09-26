
void _swapoutStack(int param_1)

{
  int iVar1;
  undefined8 **ppuVar2;
  undefined8 *puStack_c;
  
  dword_40C2334 = dword_40C2334 + 1;
  puStack_c = &_stack_queue_lock;
  _lock_write();
  *(undefined4 *)(param_1 + -4) = 1;
  iVar1 = _canSwap((undefined8 *)(param_1 + -0xc));
  ppuVar2 = (undefined8 **)&stack0xfffffff8;
  if (iVar1 != 0) {
    puStack_c = (undefined8 *)(param_1 + -0xc);
    _doSwapout();
    ppuVar2 = &puStack_c;
  }
  *(undefined8 **)((int)ppuVar2 + -4) = &_stack_queue_lock;
  *(undefined4 *)((int)ppuVar2 + -8) = 0x404a90c;
  _lock_done();
  return;
}
