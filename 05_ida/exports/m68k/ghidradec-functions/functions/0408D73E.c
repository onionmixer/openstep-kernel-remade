
void _zsrelease(int param_1)

{
  undefined *puVar1;
  
  if (param_1 == 0) {
    puVar1 = (undefined *)(_slot_id_bmap + 0x2018001);
  }
  else {
    puVar1 = (undefined *)(_slot_id_bmap + 0x2018000);
  }
  _delay(1);
  *puVar1 = 1;
  _delay(1);
  *puVar1 = 0;
  (&_zs_com)[param_1 * 2] = 0;
  (&off_40B243E)[param_1 * 2] = _zi_null;
  return;
}

