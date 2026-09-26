
int _kernel_thread(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iStack_8;
  
  _thread_create(param_1,&iStack_8);
  _thread_deallocate(iStack_8);
  _thread_start(iStack_8,param_2);
  *(undefined4 *)(iStack_8 + 0xbc) = param_3;
  _thread_doswapin(iStack_8);
  *(undefined4 *)(iStack_8 + 0x50) = 0x1f;
  *(undefined4 *)(iStack_8 + 0x4c) = 0x18;
  *(undefined4 *)(iStack_8 + 0x54) = 0x18;
  _thread_resume(iStack_8);
  return iStack_8;
}
