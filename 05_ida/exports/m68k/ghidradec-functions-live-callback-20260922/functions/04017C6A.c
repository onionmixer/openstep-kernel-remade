
uint * _getblk(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  
  if (param_1 == 0) {
    _printf(aVp0xXBlkno0xXS,0,param_2,param_3);
                    /* WARNING: Subroutine does not return */
    _panic(aGetblkIllegalV);
  }
  uVar2 = param_2;
  if ((int)param_2 < 0) {
    uVar2 = param_2 + 7;
  }
  iVar1 = (param_1 + ((int)uVar2 >> 3) & 0xf) * 0xc;
loc_4017CC4:
  do {
    for (puVar4 = *(uint **)(_bufhash + iVar1 + 4); (uint *)(_bufhash + iVar1) != puVar4;
        puVar4 = (uint *)puVar4[1]) {
      if (((param_2 == puVar4[9]) && (param_1 == puVar4[0x10])) && ((*puVar4 & 0x10000) == 0)) {
        if ((*puVar4 & 8) == 0) {
          *(uint *)(puVar4[4] + 0xc) = puVar4[3];
          *(uint *)(puVar4[3] + 0x10) = puVar4[4];
          *puVar4 = *puVar4 | 8;
          if ((param_3 == puVar4[5]) || (iVar3 = _brealloc(puVar4,param_3), iVar3 != 0)) {
            *(word *)((int)puVar4 + 2) = *(word *)((int)puVar4 + 2) | 0x8000;
            return puVar4;
          }
        }
        else {
          *puVar4 = *puVar4 | 0x40;
          _sleep(puVar4,0x15);
        }
        goto loc_4017CC4;
      }
    }
    puVar4 = (uint *)_getnewbuf();
    _bfree(puVar4);
    *(uint *)(puVar4[2] + 4) = puVar4[1];
    *(uint *)(puVar4[1] + 8) = puVar4[2];
    sub_4018552(puVar4,param_1);
    *(undefined2 *)((int)puVar4 + 0x1e) = *(undefined2 *)(param_1 + 0x2c);
    puVar4[9] = param_2;
    *(undefined2 *)(puVar4 + 7) = 0;
    puVar4[10] = 0;
    puVar4[1] = *(uint *)(_bufhash + iVar1 + 4);
    puVar4[2] = (uint)(_bufhash + iVar1);
    *(uint **)(*(int *)(_bufhash + iVar1 + 4) + 8) = puVar4;
    *(uint **)(_bufhash + iVar1 + 4) = puVar4;
    iVar3 = _brealloc(puVar4,param_3);
    if (iVar3 != 0) {
      return puVar4;
    }
  } while( true );
}

