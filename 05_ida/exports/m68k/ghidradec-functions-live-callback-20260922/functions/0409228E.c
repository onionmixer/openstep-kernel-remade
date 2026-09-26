
void _set_timer(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  _ns_untimeout(dword_40B55C0,0);
  _ns_timeout(dword_40B55C0,0,param_2,param_3,0);
  return;
}

