
void _pn_free(undefined4 *param_1)

{
  _kfree(*param_1,0x400);
  *param_1 = 0;
  return;
}

