
byte _thread_run(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  char cVar4;
  
  uVar2 = _processor_ptr;
  uVar1 = _active_threads;
  cVar4 = '\0';
  while( true ) {
    iVar3 = _thread_invoke(uVar1,param_1,param_2);
    if (iVar3 != 0) break;
    param_2 = _thread_select(uVar2);
  }
  return cVar4 << 4 | (iVar3 < 0) << 3 | (iVar3 == 0) << 2;
}

