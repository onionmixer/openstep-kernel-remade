
void _scsi_restart(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  for (puVar1 = (undefined4 *)*param_1; puVar1 != param_1; puVar1 = (undefined4 *)puVar1[2]) {
    puVar2 = (undefined4 *)puVar1[2];
    puVar3 = (undefined4 *)puVar1[3];
    if (puVar2 == param_1) {
      param_1[1] = puVar3;
    }
    else {
      puVar2[3] = puVar3;
    }
    if (puVar3 == param_1) {
      *param_1 = puVar2;
    }
    else {
      puVar3[2] = puVar2;
    }
    *(undefined *)((int)puVar1 + 0x4f) = 5;
    *(byte *)(puVar1 + 9) = *(byte *)(puVar1 + 9) & 0x5f;
    (**(code **)(puVar1[5] + 0x16))(puVar1);
  }
  return;
}
