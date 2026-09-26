
void _logwakeup(void)

{
  if (_log_open != 0) {
    _calloutEntryDispatch(dword_40B67F0);
  }
  return;
}
