
void _exit(undefined4 param_1)

{
  _do_exit(*_active_u,param_1);
  do {
    _thread_halt_self_with_continuation(0);
  } while( true );
}
