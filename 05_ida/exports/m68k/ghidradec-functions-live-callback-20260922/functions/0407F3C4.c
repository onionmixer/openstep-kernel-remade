
undefined4 _sfa_arbitrate(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  if ((param_2[4] & 1) == 0) {
    if ((*(int *)(param_1 + 0x1a) != 0) &&
       ((((*(byte *)((int)param_2 + 0x13) & 4) != 0 || ((*(byte *)(param_1 + 0x11) & 1) != 0)) ||
        (*(int *)(param_1 + 0x16) != 0)))) {
      puVar1 = *(undefined4 **)(param_1 + 10);
      if (puVar1 == (undefined4 *)(param_1 + 6)) {
        *puVar1 = param_2;
      }
      else {
        puVar1[2] = param_2;
      }
      param_2[3] = puVar1;
      param_2[2] = param_1 + 6;
      *(undefined4 **)(param_1 + 10) = param_2;
      *(char *)(param_1 + 4) = *(char *)(param_1 + 4) + '\x01';
      if ((*(byte *)((int)param_2 + 0x13) & 4) != 0) {
        *(int *)(param_1 + 0x16) = *(int *)(param_1 + 0x16) + 1;
      }
      return 1;
    }
    *(int *)(param_1 + 0x1a) = *(int *)(param_1 + 0x1a) + 1;
    if ((*(byte *)((int)param_2 + 0x13) & 4) != 0) {
      *(uint *)(param_1 + 0xe) = *(uint *)(param_1 + 0xe) | 1;
    }
    param_2[4] = param_2[4] | 1;
  }
  else if (((param_2[4] & 4) != 0) && ((*(byte *)(param_1 + 0x11) & 1) == 0)) {
                    /* WARNING: Subroutine does not return */
    _panic(aSfaArbitrateOn);
  }
  (*(code *)*param_2)(param_2[1]);
  return 0;
}

