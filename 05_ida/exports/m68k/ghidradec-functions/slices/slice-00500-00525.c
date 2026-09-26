/* GHIDRADEC_FUNCTION index=500 start=0x4017c6a */

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
/* GHIDRADEC_FUNCTION index=501 start=0x4017dd8 */

int _geteblk(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (0x2000 < param_1) {
                    /* WARNING: Subroutine does not return */
    _panic(aGeteblkSizeToo);
  }
  do {
    iVar1 = _getnewbuf();
    *(byte *)(iVar1 + 1) = *(byte *)(iVar1 + 1) | 1;
    _bfree(iVar1);
    *(undefined4 *)(*(int *)(iVar1 + 8) + 4) = *(undefined4 *)(iVar1 + 4);
    *(undefined4 *)(*(int *)(iVar1 + 4) + 8) = *(undefined4 *)(iVar1 + 8);
    sub_4018584(iVar1);
    *(undefined2 *)(iVar1 + 0x1c) = 0;
    *(undefined4 *)(iVar1 + 0x28) = 0;
    *(int *)(iVar1 + 4) = dword_40B5864;
    *(undefined4 **)(iVar1 + 8) = &unk_40B5860;
    *(int *)(dword_40B5864 + 8) = iVar1;
    dword_40B5864 = iVar1;
    iVar2 = _brealloc(iVar1,param_1);
  } while (iVar2 == 0);
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=502 start=0x4017e74 */

undefined4 _brealloc(uint *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  
  if (param_1[5] == param_2) {
    uVar3 = 1;
  }
  else {
    uVar2 = *param_1;
    if ((uVar2 & 0x200) == 0) {
      if ((int)param_2 < (int)param_1[5]) {
        if ((uVar2 & 0x20000) != 0) {
                    /* WARNING: Subroutine does not return */
          _panic(aBrealloc);
        }
      }
      else {
        *param_1 = uVar2 & 0xfffffffd;
        uVar2 = param_1[0x10];
        if (uVar2 != 0) {
          iVar4 = (**(code **)(*(int *)(uVar2 + 0x1c) + 0x80))(uVar2);
          if (iVar4 < 0) {
                    /* WARNING: Subroutine does not return */
            _panic(aCouldnTDetermi);
          }
          uVar2 = param_1[9];
          uVar5 = uVar2;
          if ((int)uVar2 < 0) {
            uVar5 = uVar2 + 7;
          }
          iVar1 = (param_1[0x10] + ((int)uVar5 >> 3) & 0xf) * 0xc;
loc_4017F50:
          puVar6 = *(uint **)(_bufhash + iVar1 + 4);
          if ((uint *)(_bufhash + iVar1) != puVar6) {
            do {
              if ((((param_1 != puVar6) && (puVar6[0x10] == param_1[0x10])) &&
                  ((*puVar6 & 0x10000) == 0)) &&
                 (((puVar6[5] != 0 && ((int)puVar6[9] <= (int)((uVar2 - 1) + (int)param_2 / iVar4)))
                  && ((int)uVar2 < (int)(puVar6[9] + (int)puVar6[5] / iVar4))))) {
                if ((*puVar6 & 8) != 0) {
                  *puVar6 = *puVar6 | 0x40;
                  _sleep(puVar6,0x15);
                  goto loc_4017F50;
                }
                *(uint *)(puVar6[4] + 0xc) = puVar6[3];
                *(uint *)(puVar6[3] + 0x10) = puVar6[4];
                *puVar6 = *puVar6 | 8;
                if ((*puVar6 & 0x200) != 0) goto loc_4017EF2;
                *puVar6 = *puVar6 | 0x10000;
                _brelse(puVar6);
              }
              puVar6 = (uint *)puVar6[1];
              if ((uint *)(_bufhash + iVar1) == puVar6) break;
            } while( true );
          }
        }
      }
      uVar3 = _allocbuf(param_1,param_2);
    }
    else {
      _bwrite(param_1);
      uVar3 = 0;
    }
  }
  return uVar3;
loc_4017EF2:
  _bwrite(puVar6);
  goto loc_4017F50;
}
/* GHIDRADEC_FUNCTION index=503 start=0x4017ffe */

uint * _getnewbuf(void)

{
  uint *puVar1;
  undefined4 *puVar2;
  
  do {
    puVar2 = &unk_40B5860;
    do {
      if (puVar2 != (undefined4 *)puVar2[3]) break;
      puVar2 = puVar2 + -0x11;
    } while (&_bfreelist < puVar2);
    if (puVar2 == &_bfreelist) {
      _bfreelist = _bfreelist | 0x40;
      _sleep(&_bfreelist,0x15);
    }
    else {
      puVar1 = (uint *)puVar2[3];
      *(uint *)(puVar1[4] + 0xc) = puVar1[3];
      *(uint *)(puVar1[3] + 0x10) = puVar1[4];
      *puVar1 = *puVar1 | 8;
      if ((*puVar1 & 0x200) == 0) {
        *puVar1 = 8;
        return puVar1;
      }
      *puVar1 = *puVar1 | 0x100;
      _bwrite(puVar1);
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=504 start=0x40180a8 */

int _getnewbuf_count(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = 0;
  puVar3 = &unk_40B5860;
  do {
    for (puVar1 = (undefined4 *)puVar3[3]; puVar3 != puVar1; puVar1 = (undefined4 *)puVar1[3]) {
      iVar2 = iVar2 + 1;
    }
    puVar3 = puVar3 + -0x11;
  } while (&_bfreelist < puVar3);
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=505 start=0x40180f2 */

word _biowait(int param_1)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  word wVar6;
  
  cVar2 = '\0';
  cVar3 = '\0';
  cVar4 = '\0';
  bVar5 = 0;
  bVar1 = *(byte *)(param_1 + 3);
  while ((bVar1 & 2) == 0) {
    cVar3 = param_1 < 0;
    cVar4 = '\0';
    bVar5 = 0;
    _sleep(param_1,0x14);
    bVar1 = *(byte *)(param_1 + 3);
  }
  wVar6 = (word)(byte)(cVar2 << 4 | cVar3 << 3 | cVar4 << 1 | bVar5);
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    wVar6 = _geterror(param_1);
    *(char *)(dword_40B57D4 + 100) = (char)wVar6;
  }
  return wVar6;
}
/* GHIDRADEC_FUNCTION index=506 start=0x4018154 */

void _biodone(uint *param_1)

{
  uint uVar1;
  
  if ((*param_1 & 2) != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aDupBiodone);
  }
  uVar1 = *param_1;
  *param_1 = uVar1 | 2;
  if ((uVar1 & 0x200000) == 0) {
    if ((uVar1 & 0x100) == 0) {
      *param_1 = uVar1 & 0xffffffbf | 2;
      _wakeup(param_1);
    }
    else {
      _brelse(param_1);
    }
  }
  else {
    *param_1 = uVar1 & 0xffdfffff | 2;
    (*(code *)param_1[0xc])(param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=507 start=0x40181b6 */

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
/* GHIDRADEC_FUNCTION index=508 start=0x40182ca */

undefined4 _bflush(uint param_1,word param_2,word param_3)

{
  uint *puVar1;
  word wVar2;
  undefined2 uVar3;
  uint in_D0;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  
loc_40182DE:
  uVar4 = in_D0 & 0xffff0000;
  puVar5 = &_bfreelist;
  do {
    for (puVar1 = (uint *)puVar5[3]; uVar3 = (undefined2)(uVar4 >> 0x10), puVar5 != puVar1;
        puVar1 = (uint *)puVar1[3]) {
      if ((((param_2 == 0xffff) ||
           (wVar2 = param_3 & *(word *)((int)puVar1 + 0x1e), uVar4 = CONCAT22(uVar3,wVar2),
           wVar2 == param_2)) && (uVar4 = *puVar1, (uVar4 & 0x200) != 0)) &&
         ((param_1 == puVar1[0x10] || (param_1 == 0)))) {
        *puVar1 = uVar4 | 0x100;
        *(uint *)(puVar1[4] + 0xc) = puVar1[3];
        *(uint *)(puVar1[3] + 0x10) = puVar1[4];
        *puVar1 = *puVar1 | 8;
        in_D0 = _bwrite(puVar1);
        goto loc_40182DE;
      }
    }
    puVar6 = puVar5 + 0x11;
    puVar1 = puVar5 + -0x102d618;
    puVar5 = puVar6;
    if (&DAT_40b58a3 < puVar6) {
      return CONCAT22(uVar3,(word)(byte)(((int)puVar1 < 0) << 3 |
                                         (puVar6 == (uint *)((int)&DAT_40b58a3 + 1)) << 2 |
                                        SBORROW4((int)puVar6,0x40b58a4) << 1));
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=509 start=0x401837c */

void _brelvp_wakeup(undefined4 param_1)

{
  _brelse(param_1);
  sub_4018584(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=510 start=0x401839e */

byte _binvalfree(uint param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  
loc_40183AA:
  puVar2 = &_bfreelist;
  do {
    for (puVar1 = (uint *)puVar2[3]; puVar2 != puVar1; puVar1 = (uint *)puVar1[3]) {
      if ((param_1 == puVar1[0x10]) || (param_1 == 0)) {
        if ((*puVar1 & 0x200) == 0) {
          *puVar1 = *puVar1 | 0x10000;
          sub_4018584(puVar1);
        }
        else {
          puVar1[0xc] = (uint)_brelvp_wakeup;
          *puVar1 = *puVar1 | 0x200100;
          *(uint *)(puVar1[4] + 0xc) = puVar1[3];
          *(uint *)(puVar1[3] + 0x10) = puVar1[4];
          *puVar1 = *puVar1 | 8;
          _bwrite(puVar1);
        }
        goto loc_40183AA;
      }
    }
    puVar3 = puVar2 + 0x11;
    puVar1 = puVar2 + -0x102d618;
    puVar2 = puVar3;
    if (&DAT_40b58a3 < puVar3) {
      return ((int)puVar1 < 0) << 3 | (puVar3 == (uint *)((int)&DAT_40b58a3 + 1)) << 2 |
             SBORROW4((int)puVar3,0x40b58a4) << 1;
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=511 start=0x401845c */

byte _btrash(uint param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  
loc_4018468:
  puVar2 = &_bfreelist;
  do {
    for (puVar1 = (uint *)puVar2[3]; puVar2 != puVar1; puVar1 = (uint *)puVar1[3]) {
      if ((param_1 == puVar1[0x10]) || (param_1 == 0)) {
        *puVar1 = *puVar1 & 0xfffffdff | 0x10000;
        sub_4018584(puVar1);
        goto loc_4018468;
      }
    }
    puVar3 = puVar2 + 0x11;
    puVar1 = puVar2 + -0x102d618;
    puVar2 = puVar3;
    if (&DAT_40b58a3 < puVar3) {
      return ((int)puVar1 < 0) << 3 | (puVar3 == (uint *)((int)&DAT_40b58a3 + 1)) << 2 |
             SBORROW4((int)puVar3,0x40b58a4) << 1;
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=512 start=0x40184d2 */

int _geterror(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (((*(byte *)(param_1 + 3) & 4) != 0) && (iVar1 = (int)*(sword *)(param_1 + 0x1c), iVar1 == 0))
  {
    iVar1 = 5;
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=513 start=0x40184f6 */

void _binval(uint param_1)

{
  uint *puVar1;
  undefined *puVar2;
  
loc_4018500:
  puVar2 = _bufhash;
  do {
    for (puVar1 = *(uint **)((int)puVar2 + 4); (uint *)puVar2 != puVar1; puVar1 = (uint *)puVar1[1])
    {
      if ((param_1 == puVar1[0x10]) && ((*puVar1 & 0x10000) == 0)) {
        *puVar1 = *puVar1 | 0x10000;
        sub_4018584(puVar1);
        goto loc_4018500;
      }
    }
    puVar2 = (undefined *)((int)puVar2 + 0xc);
    if (_bufhash + 0xbf < puVar2) {
      return;
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=514 start=0x40185a2 */

void _dnlc_init(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  
  dword_40B6D68 = &_nc_lru;
  dword_40B6D6C = &_nc_lru;
  iVar3 = 0;
  if (0 < _ncsize) {
    iVar6 = 0;
    do {
      puVar1 = dword_40B6D68;
      puVar4 = (undefined8 *)(iVar6 + _ncache);
      puVar2 = puVar4;
      *(undefined8 **)(puVar4 + 1) = dword_40B6D68;
      dword_40B6D68 = puVar2;
      *(undefined8 **)((int)puVar1 + 0xc) = puVar4;
      *(undefined8 **)((int)puVar4 + 0xc) = &_nc_lru;
      *(undefined8 **)((int)puVar4 + 4) = puVar4;
      *(undefined8 **)puVar4 = puVar4;
      *(undefined4 *)(puVar4 + 2) = 0;
      *(undefined4 *)((int)puVar4 + 0x14) = 0;
      *(undefined *)((int)puVar4 + 0x42) = 0;
      iVar6 = iVar6 + 0x46;
      iVar3 = iVar3 + 1;
    } while (iVar3 < _ncsize);
  }
  iVar3 = 0;
  puVar5 = &_nc_hash;
  do {
    puVar5[1] = puVar5;
    *puVar5 = puVar5;
    puVar5 = puVar5 + 2;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x40);
  return;
}
/* GHIDRADEC_FUNCTION index=515 start=0x401862c */

void _dnlc_enter(int param_1,char *param_2,int param_3,sword *param_4)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  if (_doingcache != 0) {
    iVar4 = _strlen(param_2);
    if (iVar4 < 0x21) {
      uVar2 = param_1 + iVar4 + (int)param_2[iVar4 + -1] + (int)*param_2 & 0x3f;
      iVar5 = sub_4018BAE(param_1,param_2,iVar4,uVar2,param_4);
      piVar3 = dword_40B6D68;
      if (iVar5 == 0) {
        if (dword_40B6D68 == (int *)&_nc_lru) {
          dword_40B6D8C = dword_40B6D8C + 1;
        }
        else {
          *(int *)(dword_40B6D68[3] + 8) = dword_40B6D68[2];
          *(int *)(piVar3[2] + 0xc) = piVar3[3];
          *(int *)(*piVar3 + 4) = piVar3[1];
          *(int *)piVar3[1] = *piVar3;
          if (piVar3[5] != 0) {
            if (piVar3[4] != 0) {
              dword_40B6D94 = dword_40B6D94 + -1;
            }
            if (piVar3[5] != 0) {
              _vn_rele(piVar3[5]);
            }
          }
          if (piVar3[4] != 0) {
            _vn_rele(piVar3[4]);
          }
          if (*(int *)((int)piVar3 + 0x3a) != 0) {
            _crfree(*(int *)((int)piVar3 + 0x3a));
          }
          if (*(char *)((int)piVar3 + 0x42) != '\0') {
            _kfree(*(undefined4 *)((int)piVar3 + 0x3e),(int)*(sword *)(piVar3 + 0x11));
          }
          piVar3[5] = param_1;
          *(sword *)(param_1 + 6) = *(sword *)(param_1 + 6) + 1;
          piVar3[4] = param_3;
          *(sword *)(param_3 + 6) = *(sword *)(param_3 + 6) + 1;
          *(char *)(piVar3 + 6) = (char)iVar4;
          _bcopy(param_2,(int)piVar3 + 0x19,iVar4);
          *(undefined *)((int)piVar3 + 0x42) = 0;
          *(undefined2 *)(piVar3 + 0x11) = 0;
          *(undefined4 *)((int)piVar3 + 0x3e) = 0;
          *(sword **)((int)piVar3 + 0x3a) = param_4;
          if (param_4 != (sword *)0x0) {
            *param_4 = *param_4 + 1;
          }
          iVar5 = dword_40B6D6C;
          iVar4 = *(int *)(dword_40B6D6C + 8);
          *(int **)(dword_40B6D6C + 8) = piVar3;
          piVar3[2] = iVar4;
          *(int **)(iVar4 + 0xc) = piVar3;
          piVar3[3] = iVar5;
          piVar1 = &_nc_hash + uVar2 * 2;
          *piVar3 = *piVar1;
          piVar3[1] = (int)piVar1;
          *(int **)(*piVar1 + 4) = piVar3;
          *piVar1 = (int)piVar3;
          dword_40B6D94 = dword_40B6D94 + 1;
          dword_40B6D7C = dword_40B6D7C + 1;
        }
      }
      else {
        dword_40B6D80 = dword_40B6D80 + 1;
      }
    }
    else {
      dword_40B6D84 = dword_40B6D84 + 1;
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=516 start=0x40187b4 */

undefined4 _dnlc_lookupSymLink(char *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _strlen(param_1);
  if (iVar1 < 0x21) {
    uVar2 = sub_4018BAE(param_2,param_1,iVar1,
                        param_2 + iVar1 + (int)param_1[iVar1 + -1] + (int)*param_1 & 0x3f,0xffffffff
                       );
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=517 start=0x401880a */

void _dnlc_enterSymLink(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_3[2];
  if ((iVar1 != 0) && (iVar2 = _dnlc_lookupSymLink(param_1,param_2), iVar2 != 0)) {
    if (*(char *)(iVar2 + 0x42) != '\0') {
      if (((int)*(sword *)(iVar2 + 0x44) == param_3[2]) &&
         (iVar3 = _bcmp(*param_3,*(undefined4 *)(iVar2 + 0x3e),(int)*(sword *)(iVar2 + 0x44)),
         iVar3 == 0)) {
        return;
      }
      _kfree(*(undefined4 *)(iVar2 + 0x3e),(int)*(sword *)(iVar2 + 0x44));
    }
    iVar3 = _kalloc(iVar1);
    *(int *)(iVar2 + 0x3e) = iVar3;
    if (iVar3 != 0) {
      *(undefined *)(iVar2 + 0x42) = 1;
      *(sword *)(iVar2 + 0x44) = (sword)iVar1;
      _bcopy(*param_3,*(undefined4 *)(iVar2 + 0x3e),iVar1);
      *(undefined4 *)(*(int *)(iVar2 + 0xc) + 8) = *(undefined4 *)(iVar2 + 8);
      *(undefined4 *)(*(int *)(iVar2 + 8) + 0xc) = *(undefined4 *)(iVar2 + 0xc);
      iVar3 = dword_40B6D6C;
      iVar1 = *(int *)(dword_40B6D6C + 8);
      *(int *)(dword_40B6D6C + 8) = iVar2;
      *(int *)(iVar2 + 8) = iVar1;
      *(int *)(iVar1 + 0xc) = iVar2;
      *(int *)(iVar2 + 0xc) = iVar3;
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=518 start=0x40188ce */

int _dnlc_lookup(int param_1,char *param_2,undefined4 param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  if (_doingcache == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = _strlen(param_2);
    if (iVar4 < 0x21) {
      uVar2 = param_1 + iVar4 + (int)param_2[iVar4 + -1] + (int)*param_2 & 0x3f;
      piVar5 = (int *)sub_4018BAE(param_1,param_2,iVar4,uVar2,param_3);
      if (piVar5 == (int *)0x0) {
        dword_40B6D78 = dword_40B6D78 + 1;
        iVar4 = 0;
      }
      else {
        _ncstats = _ncstats + 1;
        *(int *)(piVar5[3] + 8) = piVar5[2];
        *(int *)(piVar5[2] + 0xc) = piVar5[3];
        iVar3 = dword_40B6D6C;
        iVar4 = *(int *)(dword_40B6D6C + 8);
        *(int **)(dword_40B6D6C + 8) = piVar5;
        piVar5[2] = iVar4;
        *(int **)(iVar4 + 0xc) = piVar5;
        piVar5[3] = iVar3;
        if (&_nc_hash + uVar2 * 2 != (undefined4 *)piVar5[1]) {
          *(undefined4 **)(*piVar5 + 4) = (undefined4 *)piVar5[1];
          *(int *)piVar5[1] = *piVar5;
          piVar1 = *(int **)(piVar5[1] + 4);
          *piVar5 = *piVar1;
          piVar5[1] = (int)piVar1;
          *(int **)(*piVar1 + 4) = piVar5;
          *piVar1 = (int)piVar5;
        }
        iVar4 = piVar5[4];
      }
    }
    else {
      dword_40B6D88 = dword_40B6D88 + 1;
      iVar4 = 0;
    }
  }
  return iVar4;
}
/* GHIDRADEC_FUNCTION index=519 start=0x40189b8 */

void _dnlc_remove(int param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = _strlen(param_2);
  if (iVar3 < 0x21) {
    cVar1 = *param_2;
    cVar2 = param_2[iVar3 + -1];
    while( true ) {
      iVar4 = sub_4018BAE(param_1,param_2,iVar3,param_1 + iVar3 + (int)cVar2 + (int)cVar1 & 0x3f,
                          0xffffffff);
      if (iVar4 == 0) break;
      sub_4018AFE(iVar4);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=520 start=0x4018a1e */

void _dnlc_purge(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  dword_40B6D90 = dword_40B6D90 + 1;
  while( true ) {
    puVar2 = &_nc_hash;
    while (puVar1 = (undefined4 *)*puVar2, puVar2 == puVar1) {
      puVar2 = puVar2 + 2;
      if (&DAT_40b6d5f < puVar2) {
        return;
      }
    }
    if ((puVar1[5] == 0) || (puVar1[4] == 0)) break;
    sub_4018AFE(puVar1);
  }
                    /* WARNING: Subroutine does not return */
  _panic(aDnlcPurgeZeroV);
}
/* GHIDRADEC_FUNCTION index=521 start=0x4018a76 */

void _dnlc_purge_vp(int param_1)

{
  undefined8 *puVar1;
  bool bVar2;
  
  do {
    bVar2 = false;
    for (puVar1 = dword_40B6D68; puVar1 != &_nc_lru; puVar1 = *(undefined8 **)(puVar1 + 1)) {
      if ((param_1 == *(int *)((int)puVar1 + 0x14)) || (param_1 == *(int *)(puVar1 + 2))) {
        sub_4018AFE(puVar1);
        bVar2 = true;
        break;
      }
    }
    if (!bVar2) {
      return;
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=522 start=0x4018ac8 */

undefined4 _dnlc_purge1(void)

{
  undefined8 *puVar1;
  
  puVar1 = dword_40B6D68;
  while( true ) {
    if (puVar1 == &_nc_lru) {
      return 0;
    }
    if (*(int *)((int)puVar1 + 0x14) != 0) break;
    puVar1 = *(undefined8 **)(puVar1 + 1);
  }
  sub_4018AFE(puVar1);
  return 1;
}
/* GHIDRADEC_FUNCTION index=523 start=0x4018c5a */

int _vno_rw(int param_1,int param_2,int param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  
  piVar1 = *(int **)(param_1 + 0x16);
  if ((param_2 == 1) && (iVar3 = _isrofile(piVar1), iVar3 != 0)) {
    iVar4 = 0x1e;
  }
  else {
    iVar3 = *(int *)(param_3 + 0x12);
    bVar5 = piVar1[10] == 1;
    uVar2 = *(uint *)(param_1 + 8);
    if ((uVar2 & 8) != 0) {
      bVar5 = bVar5 | 2;
    }
    if ((uVar2 & 0x40000) != 0) {
      bVar5 = bVar5 | 4;
    }
    if (piVar1[10] == 8) {
      *(sword *)(param_3 + 0x10) = (sword)uVar2;
    }
    if (((piVar1[10] == 1) && ((*(byte *)(*piVar1 + 0x34) & 8) != 0)) &&
       ((*(byte *)(*_active_u + 0x16) & 0x40) == 0)) {
      iVar4 = _mfs_io(piVar1,param_3,param_2,bVar5,*(undefined4 *)(param_1 + 0x1e));
    }
    else {
      iVar4 = (**(code **)(piVar1[7] + 8))
                        (piVar1,param_3,param_2,bVar5,*(undefined4 *)(param_1 + 0x1e));
    }
    if (iVar4 == 0) {
      if (((*(byte *)(param_1 + 0xb) & 8) != 0) || (piVar1[10] == 8)) {
        *(int *)(param_1 + 0x1a) = *(int *)(param_3 + 8) - (iVar3 - *(int *)(param_3 + 0x12));
      }
      iVar4 = 0;
    }
  }
  return iVar4;
}
/* GHIDRADEC_FUNCTION index=524 start=0x4018d3c */

int _vno_ioctl(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  undefined auStack_3e [20];
  int iStack_2a;
  
  iVar2 = *(int *)(param_1 + 0x16);
  switch(*(undefined4 *)(iVar2 + 0x28)) {
  case :
    break;
  case :
  case :
    goto loc_4018DFC;
  :
    return 0x19;
  case :
  case :
    *(undefined4 *)(dword_40B57D4 + 0x5c) = 0;
    iVar1 = _setjmp(dword_40B57D4 + 0x28);
    if (iVar1 == 0) {
      iVar2 = (**(code **)(*(int *)(iVar2 + 0x1c) + 0xc))
                        (iVar2,param_2,param_3,*(undefined4 *)(param_1 + 8),
                         *(undefined4 *)(param_1 + 0x1e));
      return iVar2;
    }
    if (*(int *)((int)_active_u + 0x136) << 0x20 - *(char *)(*_active_u + 0x17) < 0) {
      return 4;
    }
    *(undefined *)(dword_40B57D4 + 0x65) = 2;
    return 0;
  }
  if (param_2 == -0x3ffb9996) {
    iVar2 = *param_3;
    if (iVar2 == 1) {
      *(word *)(param_1 + 10) = *(word *)(param_1 + 10) | 0x1000;
    }
    else if (iVar2 < 2) {
      if (iVar2 != 0) {
        return 0x16;
      }
    }
    else {
      if (iVar2 != 2) {
        return 0x16;
      }
      *(word *)(param_1 + 10) = *(word *)(param_1 + 10) & 0xefff;
    }
    if ((*(uint *)(param_1 + 8) & 0x1000) == 0) {
      iVar2 = 2;
    }
    else {
      iVar2 = 1;
    }
    *param_3 = iVar2;
    return 0;
  }
loc_4018DFC:
  if (param_2 < -0x7ffb9983) {
    return 0x19;
  }
  if (-0x7ffb9982 < param_2) {
    if (param_2 != 0x4004667f) {
      return 0x19;
    }
    iVar2 = (**(code **)(*(int *)(iVar2 + 0x1c) + 0x14))
                      (iVar2,auStack_3e,*(undefined4 *)((int)_active_u + 0x1a));
    if (iVar2 != 0) {
      return iVar2;
    }
    *param_3 = iStack_2a - *(int *)(param_1 + 0x1a);
    return 0;
  }
  return 0;
}

