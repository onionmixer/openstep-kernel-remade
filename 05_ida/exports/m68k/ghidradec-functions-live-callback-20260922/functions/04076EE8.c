
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte _od_sect_to(int param_1,int param_2)

{
  undefined *puVar1;
  undefined2 uVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  char cVar6;
  
  puVar1 = *(undefined **)(param_1 + 0x210);
  uVar2 = *(undefined2 *)(param_1 + 0x22c);
  bVar3 = *(byte *)(param_1 + 0x264);
  if (*(char *)(param_1 + 0x264) == '\0') {
    *puVar1 = (char)((uint)(*(sword *)(param_1 + 0x22c) + -1) >> 8);
    puVar1[1] = (char)*(undefined2 *)(param_1 + 0x22c) + -1;
    iVar4 = *(sword *)(param_1 + 0x22c) + -2;
    puVar1[2] = 0x1f;
  }
  else {
    *puVar1 = (char)((word)*(undefined2 *)(param_1 + 0x22c) >> 8);
    puVar1[1] = (char)*(undefined2 *)(param_1 + 0x22c);
    iVar4 = *(sword *)(param_1 + 0x22c) + -1;
    puVar1[2] = *(char *)(param_1 + 0x264) - 1U | 0x10;
  }
  puVar1[3] = 1;
  _od_drive_cmd(param_1,param_2,iVar4 >> 0xc | 0xa000,9);
  _od_drive_cmd(param_1,param_2,*(word *)(param_1 + 0x22e) & 0xfff,9);
  puVar1[5] = puVar1[5] & 0xf2;
  puVar1[0xc] = byte_40B1FDB | *(byte *)(param_1 + 0x26f) & 0xfc;
  puVar1[6] = (byte)(param_2 + -0x40c3e18 >> 5) | 0xc0;
  puVar1[7] = 0;
  puVar1[7] = 2;
  uVar5 = 0;
  do {
    _delay(1);
    if (puVar1[3] != '\x01') break;
    uVar5 = uVar5 + 1;
  } while ((int)uVar5 < 100000);
  puVar1[4] = _disr_shadow | 0xfc;
  puVar1[7] = 0;
  *puVar1 = (char)((word)uVar2 >> 8);
  puVar1[1] = (char)uVar2;
  puVar1[2] = bVar3 | 0x10;
  puVar1[3] = 1;
  *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xbfffffff;
  iVar4 = __od_id_r;
  cVar6 = uVar5 < 100000;
  if (uVar5 == 100000) {
    _printf(aOdSectToN1NotF);
  }
  else {
    __od_id_r = 2;
  }
  _od_issue_cmd(param_1,param_2);
  __od_id_r = iVar4;
  return cVar6 << 4 | (iVar4 < 0) << 3 | (iVar4 == 0) << 2;
}

