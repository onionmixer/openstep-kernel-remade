
void _nb_free_wrapper(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0xc;
  *(undefined2 *)(param_1 + 8) = 0;
  _m_free(param_1);
  return;
}
