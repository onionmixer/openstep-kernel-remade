
void _bzero(undefined4 *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  word wVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (0 < (int)param_2) {
    uVar2 = -(int)param_1 & 3;
    uVar1 = uVar2;
    while ((uVar1 != 0 && (wVar3 = (sword)uVar2 - 1, uVar2 = (uint)wVar3, wVar3 != 0xffff))) {
      *(undefined *)param_1 = 0;
      param_2 = param_2 - 1;
      param_1 = (undefined4 *)((int)param_1 + 1);
      uVar1 = param_2;
    }
    uVar2 = param_2;
    puVar4 = param_1;
    switch(param_2 & 0x1c) {
    case :
      goto loc_4092e58;
    case :
      goto loc_4092e56;
    case :
      goto loc_4092e54;
    case :
      goto loc_4092e52;
    case :
      goto loc_4092e50;
    case :
      goto loc_4092e4e;
    case :
      goto loc_4092e4c;
    }
    while (param_2 = uVar2 - 0x20, 0x1f < (int)uVar2) {
      param_1 = puVar4 + 1;
      *puVar4 = 0;
loc_4092e4c:
      puVar4 = param_1 + 1;
      *param_1 = 0;
loc_4092e4e:
      param_1 = puVar4 + 1;
      *puVar4 = 0;
loc_4092e50:
      puVar4 = param_1 + 1;
      *param_1 = 0;
loc_4092e52:
      param_1 = puVar4 + 1;
      *puVar4 = 0;
loc_4092e54:
      puVar4 = param_1 + 1;
      *param_1 = 0;
loc_4092e56:
      param_1 = puVar4 + 1;
      *puVar4 = 0;
loc_4092e58:
      puVar4 = param_1 + 1;
      *param_1 = 0;
      uVar2 = param_2;
    }
    puVar5 = puVar4;
    if ((param_2 & 2) != 0) {
      puVar5 = (undefined4 *)((int)puVar4 + 2);
      *(undefined2 *)puVar4 = 0;
    }
    if ((param_2 & 1) != 0) {
      *(undefined *)puVar5 = 0;
    }
  }
  return;
}

