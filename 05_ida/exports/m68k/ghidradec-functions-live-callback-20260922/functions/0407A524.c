
void _od_try_attach(void)

{
  int iVar1;
  word *pwVar2;
  undefined *puVar3;
  
  _od_try_th = _active_threads;
  do {
    puVar3 = _od_drive;
    pwVar2 = &word_40C3E30;
    do {
      if ((*pwVar2 & 0x5000) == 0x1000) {
        *pwVar2 = *pwVar2 | 0x800;
        _odattach(*(undefined4 *)((int)puVar3 + 0x14));
        *pwVar2 = *pwVar2 & 0xf7ff;
      }
      pwVar2 = pwVar2 + 0x10;
      puVar3 = (undefined *)((int)puVar3 + 0x20);
    } while (puVar3 < &_od_empty);
    _assert_wait(0,0);
    iVar1 = _hz;
    if (_od_requested != 0) {
      if (_hz < 0) {
        iVar1 = _hz + 1;
      }
      iVar1 = iVar1 >> 1;
    }
    _thread_set_timeout(iVar1);
    _thread_block();
  } while( true );
}

