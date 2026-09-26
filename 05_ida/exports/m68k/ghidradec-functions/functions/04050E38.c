
byte _thread_block_with_continuation(undefined4 param_1)

{
  byte *pbVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  char cVar6;
  
  uVar3 = _processor_ptr;
  iVar2 = _active_threads;
  cVar6 = '\0';
  _need_ast = _need_ast & 0xfffffffb;
  if (_need_ast == 0) {
    pbVar1 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
    *pbVar1 = *pbVar1 & 0xef;
  }
  do {
    uVar4 = _thread_select(uVar3);
    iVar5 = _thread_invoke(iVar2,param_1,uVar4);
  } while (iVar5 == 0);
  return cVar6 << 4 | (iVar5 < 0) << 3;
}
