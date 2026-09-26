
void _power_callout(undefined4 param_1,int param_2)

{
  undefined8 uVar1;
  
  sub_404EAAE(0);
  if (param_2 == 0) {
    param_2 = _calloutEntryAllocate(_power_callout,0);
  }
  uVar1 = _calloutDeadlineFromInterval(0,1010000000);
  _calloutEntryDispatchDelayed(param_2,uVar1);
  return;
}
