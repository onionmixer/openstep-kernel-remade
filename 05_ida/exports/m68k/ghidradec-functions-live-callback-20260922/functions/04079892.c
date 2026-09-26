
void _od_creq_timeout(int param_1)

{
  *(undefined2 *)(param_1 + 10) = 0;
  _wakeup(_od_creq_timeout);
  return;
}

