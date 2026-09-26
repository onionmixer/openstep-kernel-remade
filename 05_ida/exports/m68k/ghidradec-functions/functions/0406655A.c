
byte _dma_enqueue(int *param_1,undefined4 *param_2)

{
  uint uVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  
  param_2[4] = 0;
  *param_2 = 0;
  if ((param_1[0xb] & 0x5004U) != 4) {
    sub_40664EE(param_1,param_2);
  }
  if (*param_1 == 0) {
    param_1[1] = (int)param_2;
    *param_1 = param_1[1];
  }
  else {
    *(undefined4 **)param_1[1] = param_2;
    param_1[1] = (int)param_2;
  }
  uVar1 = param_1[0xb] & 0x5004;
  cVar5 = 4 < uVar1;
  cVar4 = SBORROW4(4,uVar1);
  cVar2 = (int)(4 - uVar1) < 0;
  cVar3 = '\0';
  bVar6 = cVar5;
  if (uVar1 == 4) {
    cVar2 = (int)param_1 < 0;
    cVar3 = param_1 == (int *)0x0;
    cVar4 = '\0';
    bVar6 = 0;
    _dma_start(param_1,param_2,param_1[8]);
  }
  return cVar5 << 4 | cVar2 << 3 | cVar3 << 2 | cVar4 << 1 | bVar6;
}
