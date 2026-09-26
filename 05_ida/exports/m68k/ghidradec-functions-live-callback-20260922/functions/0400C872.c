
void _selthreadclear(int *param_1)

{
  if (param_1 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    _panic(aSelthreadclear);
  }
  if (*param_1 != 0) {
    _thread_deallocate_interrupt(*param_1);
  }
  *param_1 = 0;
  return;
}

