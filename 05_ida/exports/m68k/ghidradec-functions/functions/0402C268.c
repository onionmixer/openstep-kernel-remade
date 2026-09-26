
void _async_daemon(void)

{
  uint *puVar1;
  int iVar2;
  bool bVar3;
  
  *(undefined4 *)(_active_threads + 0x74) = 1;
  _stack_privilege(_active_threads);
  dword_40B3568 = dword_40B3568 + 1;
  iVar2 = _setjmp(dword_40B57D4 + 0x28);
  if (iVar2 == 0) {
    do {
      dword_40B3564 = dword_40B3564 + 1;
      while (_async_bufhead == (uint *)0x0) {
        _sleep(&_async_bufhead,0x1a);
      }
      dword_40B3564 = dword_40B3564 + -1;
      puVar1 = _async_bufhead;
      _async_bufhead = (uint *)_async_bufhead[3];
      sub_402C364(puVar1);
    } while( true );
  }
  if (dword_40B3568 == 0) {
    dword_40B3568 = 0;
    puVar1 = _async_bufhead;
    while (_async_bufhead = puVar1, puVar1 != (uint *)0x0) {
      *puVar1 = *puVar1 | 4;
      _async_bufhead = (uint *)puVar1[3];
      _biodone(puVar1);
      puVar1 = _async_bufhead;
    }
  }
  else {
    iVar2 = dword_40B3568 + -1;
    dword_40B3564 = dword_40B3564 + -1;
    bVar3 = dword_40B3568 == 1;
    dword_40B3568 = iVar2;
    puVar1 = _async_bufhead;
    if (bVar3) {
      while (_async_bufhead = puVar1, puVar1 != (uint *)0x0) {
        _async_bufhead = (uint *)puVar1[3];
        sub_402C364(puVar1);
        puVar1 = _async_bufhead;
      }
    }
  }
  return;
}
