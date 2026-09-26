
void _pmap_update(void)

{
  _pflush_super();
  if (_active_threads != 0) {
    _pflush_user();
  }
  return;
}
