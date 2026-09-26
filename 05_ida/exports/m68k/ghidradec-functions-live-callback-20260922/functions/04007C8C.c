
undefined4 * _crcopy(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_crget();
  *puVar1 = *param_1;
  puVar1[1] = param_1[1];
  puVar1[2] = param_1[2];
  puVar1[3] = param_1[3];
  puVar1[4] = param_1[4];
  puVar1[5] = param_1[5];
  puVar1[6] = param_1[6];
  puVar1[7] = param_1[7];
  puVar1[8] = param_1[8];
  puVar1[9] = param_1[9];
  *(undefined2 *)(puVar1 + 10) = *(undefined2 *)(param_1 + 10);
  _crfree(param_1);
  *(undefined2 *)puVar1 = 1;
  return puVar1;
}

