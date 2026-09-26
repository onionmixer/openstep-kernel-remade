
undefined4 _exc_server(int param_1,int param_2)

{
  *(undefined *)(param_2 + 3) = 1;
  *(undefined4 *)(param_2 + 4) = 0x20;
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_2 + 0xc) = 0;
  *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(int *)(param_2 + 0x14) = *(int *)(param_1 + 0x14) + 100;
  *(undefined4 *)(param_2 + 0x18) = 0x2200018;
  *(undefined4 *)(param_2 + 0x1c) = 0xfffffed1;
  if (*(int *)(param_1 + 0x14) != 0x960) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  off_40AD0EE(param_1,param_2);
}

