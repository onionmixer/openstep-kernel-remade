
void _lightning_bolt(undefined4 param_1,int param_2)

{
  undefined8 uVar1;
  
  _thread_wakeup_prim(&_lbolt,0,0);
  if (param_2 == 0) {
    param_2 = _calloutEntryAllocate(_lightning_bolt,0);
  }
  uVar1 = _calloutDeadlineFromInterval(0,1000000000);
  _calloutEntryDispatchDelayed(param_2,uVar1);
  return;
}

