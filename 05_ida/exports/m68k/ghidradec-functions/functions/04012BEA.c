
void _soaccept(int param_1,undefined4 param_2)

{
  if ((*(byte *)(param_1 + 7) & 1) == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aSoacceptNofdre);
  }
  *(word *)(param_1 + 6) = *(word *)(param_1 + 6) & 0xfffe;
  (**(code **)(*(int *)(param_1 + 0xc) + 0x1a))(param_1,5,0,param_2,0);
  return;
}

