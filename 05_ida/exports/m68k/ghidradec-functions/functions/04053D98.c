
void _swapper_init(void)

{
  dword_40C2B6C = &_swapin_queue;
  _swapin_queue = &_swapin_queue;
  return;
}

