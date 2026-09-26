
void sub_406F052(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_kalloc(0x14);
  puVar1[2] = param_1;
  puVar1[3] = param_2;
  puVar1[4] = param_3;
  *dword_40C39D8 = puVar1;
  puVar1[1] = dword_40C39D8;
  *puVar1 = &_vol_abort_q;
  dword_40C39D8 = puVar1;
  return;
}
