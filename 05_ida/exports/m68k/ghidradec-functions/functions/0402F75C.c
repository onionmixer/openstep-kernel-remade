
void _svc_run(int *param_1)

{
  do {
    while (*(sword *)(*param_1 + 0x22) != 0) {
      _svc_getreq(param_1);
      _Rpccnt = _Rpccnt + 1;
    }
    _sbwait(*param_1 + 0x22);
  } while( true );
}
