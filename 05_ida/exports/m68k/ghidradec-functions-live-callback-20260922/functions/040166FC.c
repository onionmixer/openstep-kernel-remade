
void _unp_dispose(int param_1)

{
  if (param_1 != 0) {
    _unp_scan(param_1,_unp_discard);
  }
  return;
}

