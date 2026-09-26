
uint _blkflush(uint param_1,int param_2,uint param_3)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  byte bVar10;
  
  uVar3 = (**(code **)(*(int *)(param_1 + 0x1c) + 0x80))(param_1);
  if ((int)uVar3 < 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aCouldnTDetermi);
  }
  iVar4 = param_2;
  if (param_2 < 0) {
    iVar4 = param_2 + 7;
  }
  uVar2 = param_1 + (iVar4 >> 3) & 0xf;
  uVar5 = uVar2 * 3;
  iVar4 = uVar2 * 0xc;
loc_4018216:
  puVar1 = *(uint **)(_bufhash + iVar4 + 4);
  do {
    if ((uint *)(_bufhash + iVar4) == puVar1) {
      return uVar5;
    }
    if ((((param_1 == puVar1[0x10]) && ((*puVar1 & 0x10000) == 0)) &&
        (uVar5 = puVar1[5], uVar5 != 0)) &&
       (((int)puVar1[9] <= (int)(param_2 + -1 + param_3 / uVar3) &&
        (uVar5 = puVar1[9] + (int)uVar5 / (int)uVar3, param_2 < (int)uVar5)))) {
      cVar6 = '\0';
      uVar5 = *puVar1;
      if ((uVar5 & 8) != 0) {
        *puVar1 = uVar5 | 0x40;
        cVar7 = (int)puVar1 < 0;
        cVar8 = puVar1 == (uint *)0x0;
        cVar9 = '\0';
        bVar10 = 0;
        _sleep(puVar1,0x15);
        uVar5 = (uint)(byte)(cVar6 << 4 | cVar7 << 3 | cVar8 << 2 | cVar9 << 1 | bVar10);
        goto loc_4018216;
      }
      if ((uVar5 & 0x200) != 0) break;
      uVar5 = (uint)(byte)(((int)uVar5 < 0) << 3 | 4);
    }
    puVar1 = (uint *)puVar1[1];
  } while( true );
  *(uint *)(puVar1[4] + 0xc) = puVar1[3];
  *(uint *)(puVar1[3] + 0x10) = puVar1[4];
  *puVar1 = *puVar1 | 8;
  uVar5 = _bwrite(puVar1);
  goto loc_4018216;
}

