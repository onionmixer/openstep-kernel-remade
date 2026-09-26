
void _softint_th(void)

{
  do {
    do {
      _softint_run(4);
    } while (dword_40C957C != 0);
    _thread_sleep(_softint_thread,0,1);
  } while( true );
}

