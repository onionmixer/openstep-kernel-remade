
char _set_timeout(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined8 uVar2;
  
  cVar1 = '\0';
  uVar2 = _ticks_to_ns_time(param_2);
  uVar2 = _calloutDeadlineFromInterval(uVar2);
  _calloutEntryDispatchDelayed(param_1,uVar2);
  *(undefined4 *)(param_1 + 0x2c) = 1;
  return cVar1 << 4;
}
