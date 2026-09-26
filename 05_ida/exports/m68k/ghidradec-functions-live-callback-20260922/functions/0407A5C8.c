
undefined4 _od_make_empty(void)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)0x0;
  puVar1 = _od_drive;
  do {
    if ((*(word *)((int)puVar1 + 0x18) & 0x5000) == 0x1000) break;
    if (((*(word *)((int)puVar1 + 0x18) & 0x4000) != 0) &&
       ((piVar2 == (int *)0x0 || (*(int *)puVar1 < *piVar2)))) {
      piVar2 = (int *)puVar1;
    }
    puVar1 = (undefined *)((int)puVar1 + 0x20);
  } while (puVar1 < &_od_empty);
  if ((undefined4 *)puVar1 == &_od_empty) {
    if (piVar2 == (int *)0x0) {
      return 0xffffffff;
    }
    if ((*(byte *)(piVar2 + 6) & 4) != 0) {
      return 0;
    }
    iVar3 = (int)(sword)((sword)((piVar2[2] + -0x40c3ec8) * -0x2593f69b >> 1) << 3 |
                        (sword)_od_blk_major << 8);
    _od_sync(iVar3);
    _od_cmd(iVar3,0xf1,0,0,0,0,0,0,0,0);
  }
  return 1;
}

