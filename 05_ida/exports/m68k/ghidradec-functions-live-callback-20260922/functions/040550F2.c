
int _zcram(int *param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  char in_XF;
  bool bVar5;
  
  if (param_2 == (uint *)0x0) {
                    /* WARNING: Subroutine does not return */
    _panic(aZcramMemoryAtZ);
  }
  uVar1 = param_1[6];
  bVar5 = *(char *)(param_1 + 10) < '\0';
  if (bVar5) {
    _lock_write((int)param_1 + 0x2a);
  }
  else {
    *param_1 = (int)(sword)(word)(byte)(in_XF << 4 | bVar5 << 3 |
                                       (*(char *)(param_1 + 10) == '\0') << 2);
  }
  do {
    if (param_3 < uVar1) {
      if (*(char *)(param_1 + 10) < '\0') {
        iVar3 = _lock_done((int)param_1 + 0x2a);
      }
      else {
        iVar3 = *param_1;
      }
      return iVar3;
    }
    puVar2 = (uint *)param_1[2];
    if ((puVar2 == (uint *)0x0) || (param_2 <= puVar2)) {
      puVar2 = (uint *)(param_1 + 3);
    }
    do {
      puVar4 = puVar2;
      puVar2 = (uint *)*puVar4;
      if (puVar2 == (uint *)0x0) break;
    } while (puVar2 < param_2);
    *param_2 = (uint)puVar2;
    *puVar4 = (uint)param_2;
    param_1[2] = (int)param_2;
    param_3 = param_3 - uVar1;
    param_2 = (uint *)(uVar1 + (int)param_2);
    param_1[4] = uVar1 + param_1[4];
  } while( true );
}

