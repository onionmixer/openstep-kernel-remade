
void _set_pri(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = _rem_runq(param_1);
  *(undefined4 *)(param_1 + 0x54) = param_2;
  if (iVar1 != 0) {
    if (param_3 == 0) {
      _run_queue_enqueue(iVar1,param_1);
    }
    else {
      _thread_setrun(param_1,1);
    }
  }
  return;
}

