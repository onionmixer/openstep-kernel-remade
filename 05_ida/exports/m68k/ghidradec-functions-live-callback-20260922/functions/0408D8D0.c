
void _zsintsetup(void)

{
  undefined uVar1;
  
  uVar1 = 0x30;
  if (_dma_chip == 0x139) {
    uVar1 = 10;
  }
  *(undefined *)(_slot_id_bmap + 0x2018004) = uVar1;
  _install_polled_intr(0x1150,_zsint);
  if ((1 < _console_i - 1U) && (1 < _console_o - 1U)) {
    if (_machine_type == '\0') {
      uVar1 = 0;
      if (_board_rev < 3) {
        uVar1 = 2;
      }
    }
    else {
      uVar1 = 0;
    }
    _delay(1);
    *(undefined *)(_slot_id_bmap + 0x2018001) = 5;
    _delay(1);
    *(undefined *)(_slot_id_bmap + 0x2018001) = uVar1;
    _delay(1);
    *(undefined *)(_slot_id_bmap + 0x2018000) = 5;
    _delay(1);
    *(undefined *)(_slot_id_bmap + 0x2018000) = uVar1;
  }
  return;
}

