
void _od_reset(int param_1,int param_2,int param_3)

{
  *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x800000;
  *(byte *)(param_3 + 4) = _disr_shadow | *(byte *)(param_3 + 4) & 0xfc | 1;
  _disr_shadow = _disr_shadow | 1;
  _delay(0x50);
  _disr_shadow = _disr_shadow & 0xfe;
  *(byte *)(param_3 + 4) = _disr_shadow;
  *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x8000000;
  *(undefined *)(param_1 + 0x26c) = *(undefined *)(param_1 + 0x269);
  *(undefined *)(param_1 + 0x268) = 0x13;
  if ((*(word *)(param_2 + 0x18) & 0xa00) == 0x200) {
    _delay(10000000);
    *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x200000;
    _odintr(param_1);
  }
  else {
    *(undefined *)(param_1 + 0x260) = 10;
  }
  return;
}
