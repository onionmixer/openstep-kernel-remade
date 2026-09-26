
int _xdrmbuf_getpos(int param_1)

{
  return *(int *)(param_1 + 0xc) -
         (*(int *)(*(int *)(param_1 + 0x10) + 4) + *(int *)(param_1 + 0x10));
}
