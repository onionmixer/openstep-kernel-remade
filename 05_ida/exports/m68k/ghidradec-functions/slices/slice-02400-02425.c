/* GHIDRADEC_FUNCTION index=2400 start=0x4090ce4 */

undefined4 _PMSetPowerManagement(void)

{
  return 0;
}
/* GHIDRADEC_FUNCTION index=2401 start=0x4090cee */

undefined4 _PMRestoreDefaults(void)

{
  return 0;
}
/* GHIDRADEC_FUNCTION index=2402 start=0x4090cf8 */

void _PMUpdateClock(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2403 start=0x4090d00 */

undefined8 __ashldi3(uint param_1,uint param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  
  if (param_4 != 0) {
    uVar1 = 0x20 - param_4;
    if ((int)uVar1 < 1) {
      param_1 = param_2 << (-uVar1 & 0x3f);
      param_2 = 0;
    }
    else {
      uVar1 = param_2 >> (uVar1 & 0x3f);
      param_2 = param_2 << (param_4 & 0x3f);
      param_1 = uVar1 | param_1 << (param_4 & 0x3f);
    }
  }
  return CONCAT44(param_1,param_2);
}
/* GHIDRADEC_FUNCTION index=2404 start=0x4090d4c */

void __bdiv(word *param_1,word *param_2,sword *param_3,word *param_4,uint param_5,uint param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  word wVar4;
  int iVar5;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  word *pwVar10;
  word *pwVar11;
  word *pwVar12;
  word *pwVar13;
  uint auStack_7c [3];
  undefined auStack_70 [4];
  uint auStack_6c [4];
  int aiStack_5c [2];
  word wStack_52;
  sword *psStack_28;
  int iStack_24;
  undefined2 *puStack_20;
  word *pwStack_1c;
  uint uStack_18;
  sword sVar6;
  
  iVar2 = -(param_5 + 3 & 0xfffffffc);
  pwVar10 = (word *)(&stack0xffffffb0 + iVar2);
  iVar3 = -(param_6 + 3 & 0xfffffffc);
  param_5 = param_5 >> 1;
  param_6 = param_6 >> 1;
  iVar1 = param_5 - param_6;
  while (*param_2 == 0) {
    pwVar13 = param_4 + 1;
    *param_4 = 0;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
    param_5 = param_5 - 1;
    param_6 = param_6 - 1;
    param_4 = pwVar13;
    if (param_6 == 0) {
      param_6 = 10 / 0;
    }
  }
  if (param_6 == 1) {
    wVar4 = *param_1;
    uVar7 = (uint)wVar4;
    iStack_24 = 0;
    if (0 < iVar1) {
      do {
        param_1 = param_1 + 1;
        uVar7 = (uint)*param_1 | uVar7 << 0x10;
        *param_3 = (sword)(uVar7 / *param_2);
        uVar7 = uVar7 % (uint)*param_2;
        wVar4 = (word)uVar7;
        iStack_24 = iStack_24 + 1;
        param_3 = param_3 + 1;
      } while (iStack_24 < iVar1);
    }
    *param_4 = wVar4;
  }
  else {
    uVar7 = 0;
    do {
      if ((int)((uint)*param_2 << uVar7 + 0x10) < 0) break;
      uVar7 = uVar7 + 1;
    } while ((int)uVar7 < 0x10);
    *(uint *)(&stack0xffffffac + iVar3 + iVar2) = param_5;
    *(undefined4 *)((int)aiStack_5c + iVar3 + iVar2 + 4) = 0;
    *(undefined **)((int)aiStack_5c + iVar3 + iVar2) = &stack0xffffffb0 + iVar2;
    *(uint *)((int)auStack_6c + iVar3 + iVar2 + 0xc) = uVar7;
    *(word **)((int)auStack_6c + iVar3 + iVar2 + 8) = param_1;
    *(undefined4 *)((int)auStack_6c + iVar3 + iVar2 + 4) = 0x4090e40;
    sub_409100E();
    *(uint *)((int)auStack_6c + iVar3 + iVar2 + 4) = param_6;
    *(undefined4 *)((int)auStack_6c + iVar3 + iVar2) = 0;
    *(undefined **)(auStack_70 + iVar3 + iVar2) = &stack0xffffffb0 + iVar3 + iVar2;
    *(uint *)((int)auStack_7c + iVar3 + iVar2 + 8) = uVar7;
    *(word **)((int)auStack_7c + iVar3 + iVar2 + 4) = param_2;
    *(undefined4 *)((int)auStack_7c + iVar3 + iVar2) = 0x4090e4e;
    sub_409100E();
    pwVar13 = (word *)(&stack0xffffffb2 + iVar2);
    puStack_20 = (undefined2 *)(&stack0xffffffb4 + iVar2);
    iStack_24 = 0;
    if (0 < iVar1) {
      psStack_28 = param_3;
      pwStack_1c = pwVar13;
      do {
        wVar4 = *(word *)(&stack0xffffffb0 + iVar3 + iVar2);
        if (wVar4 == *pwVar10) {
          uVar9 = 0xffff;
          uStack_18 = (uint)wVar4;
          uStack_18 = *pwVar13 + uStack_18;
        }
        else {
          uVar9 = CONCAT22(*pwVar10,*pwVar13);
          uStack_18 = uVar9 % (uint)wVar4;
          uVar9 = uVar9 / wVar4;
        }
        if (uStack_18 < 0x10000) {
          do {
            if (*(word *)(&stack0xffffffb2 + iVar3 + iVar2) * uVar9 <=
                CONCAT22((sword)uStack_18,*puStack_20)) break;
            uVar9 = uVar9 - 1;
            uStack_18 = *(word *)(&stack0xffffffb0 + iVar3 + iVar2) + uStack_18;
          } while (uStack_18 < 0x10000);
        }
        uVar8 = 0;
        iVar5 = param_6 - 1;
        if (-1 < iVar5) {
          pwVar11 = pwStack_1c + iVar5;
          pwVar12 = (word *)(&stack0xffffffb0 + iVar5 * 2 + iVar3 + iVar2);
          do {
            uVar8 = ((uint)*pwVar11 - uVar9 * *pwVar12) + uVar8;
            *pwVar11 = (word)uVar8;
            if (uVar8 < 0x10000) {
              uVar8 = 0;
            }
            else {
              uVar8 = uVar8 >> 0x10 | 0xffff0000;
            }
            pwVar11 = pwVar11 + -1;
            pwVar12 = pwVar12 + -1;
            wVar4 = (word)((uint)iVar5 >> 0x10);
            sVar6 = (sword)iVar5 + -1;
            iVar5 = CONCAT22(wVar4,sVar6);
          } while ((sVar6 != -1) || (iVar5 = (uint)wVar4 * 0x10000 + -1, wVar4 != 0));
        }
        *psStack_28 = (sword)uVar9;
        if ((int)(uVar8 + *pwVar10) < 0) {
          *psStack_28 = (sword)uVar9 + -1;
          uVar9 = 0;
          iVar5 = param_6 - 1;
          if (-1 < iVar5) {
            pwVar11 = pwStack_1c + iVar5;
            pwVar12 = (word *)(&stack0xffffffb0 + iVar5 * 2 + iVar3 + iVar2);
            do {
              do {
                uVar9 = (uint)*pwVar12 + (uint)*pwVar11 + uVar9;
                *pwVar11 = (word)uVar9;
                uVar9 = uVar9 >> 0x10;
                pwVar11 = pwVar11 + -1;
                pwVar12 = pwVar12 + -1;
                wVar4 = (word)((uint)iVar5 >> 0x10);
                sVar6 = (sword)iVar5 + -1;
                iVar5 = CONCAT22(wVar4,sVar6);
              } while (sVar6 != -1);
              iVar5 = (uint)wVar4 * 0x10000 + -1;
            } while (wVar4 != 0);
          }
        }
        pwStack_1c = pwStack_1c + 1;
        psStack_28 = psStack_28 + 1;
        pwVar10 = pwVar10 + 1;
        puStack_20 = puStack_20 + 1;
        pwVar13 = pwVar13 + 1;
        iStack_24 = iStack_24 + 1;
      } while (iStack_24 < iVar1);
    }
    *(uint *)(&stack0xffffffac + iVar3 + iVar2) = param_6 - 1;
    *(int *)((int)aiStack_5c + iVar3 + iVar2 + 4) =
         (int)(uint)*(word *)((int)&wStack_52 + param_5 * 2 + iVar2) >> (uVar7 & 0x3f);
    *(word **)((int)aiStack_5c + iVar3 + iVar2) = param_4 + 1;
    *(uint *)((int)auStack_6c + iVar3 + iVar2 + 0xc) = 0x10 - uVar7;
    *(undefined **)((int)auStack_6c + iVar3 + iVar2 + 8) = &stack0xffffffb0 + iStack_24 * 2 + iVar2;
    *(undefined4 *)((int)auStack_6c + iVar3 + iVar2 + 4) = 0x4090ffe;
    wVar4 = sub_409100E();
    *param_4 = wVar4;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2405 start=0x4091080 */

uint _checksum_16(word *param_1,int param_2)

{
  word wVar1;
  sword sVar2;
  uint uVar3;
  word *pwVar4;
  
  uVar3 = 0;
  param_2 = param_2 + -1;
  if (param_2 != -1) {
    do {
      do {
        pwVar4 = param_1 + 1;
        uVar3 = *param_1 + uVar3;
        wVar1 = (word)((uint)param_2 >> 0x10);
        sVar2 = (sword)param_2 + -1;
        param_2 = CONCAT22(wVar1,sVar2);
        param_1 = pwVar4;
      } while (sVar2 != -1);
      param_2 = (uint)wVar1 * 0x10000 + -1;
    } while (wVar1 != 0);
  }
  uVar3 = (uVar3 & 0xffff) + (uVar3 >> 0x10);
  if (0xffff < uVar3) {
    uVar3 = uVar3 - 0xffff;
  }
  return uVar3 & 0xffff;
}
/* GHIDRADEC_FUNCTION index=2406 start=0x40910d6 */

void _rtc_set_clr(undefined param_1,byte param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = _rtc_read(param_1);
  _rtc_write(param_1,param_3 & param_2 | ~(uint)param_2 & uVar1);
  return;
}
/* GHIDRADEC_FUNCTION index=2407 start=0x4091118 */

void _rtc_set_auto_poweron(int param_1)

{
  undefined4 uVar1;
  
  if (_new_clock_chip != 0) {
    uVar1 = 0;
    if (param_1 != 0) {
      uVar1 = 0xffffffff;
    }
    _rtc_set_clr(0x31,0x20,uVar1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2408 start=0x4091142 */

undefined4 _rtc_intr(void)

{
  byte bVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  while( true ) {
    if ((*_intrstat & 4) == 0) {
      return uVar2;
    }
    bVar1 = _rtc_read(0x30);
    if (-1 < (char)bVar1) break;
    if ((bVar1 & 0x10) != 0) {
      _rtc_set_clr(0x31,4,0xffffffff);
    }
    if ((bVar1 & 4) != 0) {
      _rtc_set_clr(0x31,2,0);
    }
    if ((bVar1 & 2) != 0) {
      _rtc_set_clr(0x31,8,0xffffffff);
    }
    if ((bVar1 & 1) != 0) {
      _rtc_set_clr(0x31,1,0xffffffff);
      uVar2 = 1;
    }
  }
  return 1;
}
/* GHIDRADEC_FUNCTION index=2409 start=0x40911f6 */

undefined4 _rtc_alarm(int *param_1,uint *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  byte bStack_8;
  byte bStack_7;
  byte bStack_6;
  undefined uStack_5;
  
  if (_new_clock_chip == 0) {
    uVar1 = 0x16;
  }
  else {
    if (param_2 != (uint *)0x0) {
      uVar2 = _rtc_read(0x31);
      *param_2 = uVar2 & 0x10;
      _rtc_blkread(0x24,&bStack_8,4);
      param_2[1] = CONCAT31((uint3)bStack_6 |
                            (uint3)(((uint)bStack_7 << 0x10) >> 8) |
                            (uint3)(((uint)bStack_8 << 0x18) >> 8),uStack_5);
    }
    if (param_1 != (int *)0x0) {
      uStack_5 = *(undefined *)((int)param_1 + 7);
      bStack_6 = (byte)((uint)param_1[1] >> 8);
      bStack_7 = *(undefined *)((int)param_1 + 5);
      bStack_8 = *(byte *)(param_1 + 1);
      _rtc_blkwrite(0x24,&bStack_8,4);
      uVar1 = 0;
      if (*param_1 != 0) {
        uVar1 = 0xffffffff;
      }
      _rtc_set_clr(0x31,0x10,uVar1);
    }
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2410 start=0x40912be */

undefined4 _rtc_tick(void)

{
  char cVar3;
  int iVar1;
  int iVar2;
  undefined4 uVar4;
  
  cVar3 = _rtc_read(0x30);
  uVar4 = 0x20;
  if (cVar3 < '\0') {
    uVar4 = 0x23;
  }
  iVar1 = _rtc_read(uVar4);
  while( true ) {
    iVar2 = _rtc_read(uVar4);
    if (iVar2 != iVar1) break;
    _delay(1000);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=2411 start=0x4091308 */

void _rtc_power_down(void)

{
  char cVar1;
  undefined4 uVar2;
  
  if (_new_clock_chip != 0) {
    _rtc_tick();
    _delay(850000);
  }
  cVar1 = _rtc_read(0x30);
  uVar2 = 0x32;
  if (cVar1 < '\0') {
    uVar2 = 0x31;
  }
  _rtc_set_clr(uVar2,0x40,0xffffffff);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2412 start=0x4091356 */

void _startrtclock(void)

{
  undefined4 uVar1;
  undefined auStack_24 [17];
  byte bStack_13;
  
  _nvram_check(auStack_24);
  _new_clock_chip = _rtc_read(0x30);
  _new_clock_chip = _new_clock_chip & 0x80;
  if (_new_clock_chip != 0) {
    uVar1 = 0;
    if ((bStack_13 & 0x40) != 0) {
      uVar1 = 0xffffffff;
    }
    _rtc_set_clr(0x31,0x20,uVar1);
    _rtc_set_clr(0x31,0x80,0xffffffff);
  }
  bStack_13 = bStack_13 & 0x7f | (_new_clock_chip != 0) << 7;
  _nvram_set(auStack_24);
  return;
}
/* GHIDRADEC_FUNCTION index=2413 start=0x40913da */

void _resynctime(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2414 start=0x40913e2 */

int _tm_to_sec(int *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = 0x46;
  iVar2 = 0;
  iVar3 = iVar2;
  if (0x46 < param_1[5]) {
    do {
      iVar2 = iVar3 + 0x16d;
      if ((uVar1 & 3) == 0) {
        iVar2 = iVar3 + 0x16e;
      }
      uVar1 = uVar1 + 1;
      iVar3 = iVar2;
    } while ((int)uVar1 < param_1[5]);
  }
  iVar2 = param_1[3] + (int)(sword)(&unk_40B2890)[param_1[4]] + -1 + iVar2;
  if (((*(uint *)((int)param_1 + 0x17) & 0x3ffffff) >> 0x18 == 0) && (2 < param_1[4])) {
    iVar2 = iVar2 + 1;
  }
  return *param_1 + param_1[2] * 0xe10 + iVar2 * 0x15180 + param_1[1] * 0x3c;
}
/* GHIDRADEC_FUNCTION index=2415 start=0x4091470 */

void _sec_to_tm(int param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  
  iVar1 = (int)(sword)((sword)(param_1 / 0x15180) + (sword)(param_1 >> 0x1f));
  iVar3 = param_1 + (iVar1 - (param_1 >> 0x1f)) * -0x15180;
  iVar1 = iVar1 - (param_1 >> 0x1f);
  if (iVar3 < 0) {
    iVar3 = iVar3 + 0x15180;
    iVar1 = iVar1 + -1;
  }
  *param_2 = iVar3 % 0x3c;
  param_2[1] = (iVar3 / 0x3c) % 0x3c;
  param_2[2] = (iVar3 / 0x3c) / 0x3c;
  if (iVar1 < 0) {
    uVar2 = 0x46;
    while (iVar1 < 0) {
      if ((uVar2 - 1 & 3) == 0) {
        iVar1 = iVar1 + 0x16e;
      }
      else {
        iVar1 = iVar1 + 0x16d;
      }
      uVar2 = uVar2 - 1;
    }
  }
  else {
    uVar2 = 0x46;
    while (0x16c < iVar1) {
      while( true ) {
        if ((uVar2 & 3) == 0) {
          iVar1 = iVar1 + -0x16e;
        }
        else {
          iVar1 = iVar1 + -0x16d;
        }
        uVar2 = uVar2 + 1;
        if ((uVar2 & 3) != 0) break;
        if (iVar1 < 0x16e) goto loc_4091550;
      }
    }
  }
loc_4091550:
  param_2[5] = uVar2;
  puVar4 = unk_40B28AA;
  if ((uVar2 & 3) == 0) {
    puVar4 = unk_40B28C2;
  }
  iVar3 = 0;
  for (; *(sword *)puVar4 <= iVar1; puVar4 = (undefined *)((int)puVar4 + 2)) {
    iVar1 = iVar1 - *(sword *)puVar4;
    iVar3 = iVar3 + 1;
  }
  param_2[4] = iVar3 + 1;
  param_2[3] = iVar1 + 1;
  return;
}
/* GHIDRADEC_FUNCTION index=2416 start=0x409158a */

void _rtc_set(undefined4 *param_1)

{
  undefined uStack_34;
  undefined uStack_33;
  undefined uStack_32;
  undefined uStack_31;
  undefined uStack_30;
  undefined uStack_2f;
  undefined uStack_2e;
  undefined uStack_2c;
  undefined uStack_2b;
  undefined uStack_2a;
  undefined uStack_29;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  if (_new_clock_chip == 0) {
    _sec_to_tm(*param_1,&uStack_28);
    _bzero(&uStack_34,8);
    uStack_34 = _byte_to_bcd(uStack_28);
    uStack_33 = _byte_to_bcd(uStack_24);
    uStack_32 = _byte_to_bcd(uStack_20);
    uStack_31 = 1;
    uStack_30 = _byte_to_bcd(uStack_1c);
    uStack_2f = _byte_to_bcd(uStack_18);
    uStack_2e = _byte_to_bcd(uStack_14);
    _rtc_write(0x31,0x30);
    _rtc_blkwrite(0x20,&uStack_34,8);
    _rtc_write(0x31,0xb0);
  }
  else {
    uStack_29 = *(undefined *)((int)param_1 + 3);
    uStack_2a = (undefined)((uint)*param_1 >> 8);
    uStack_2b = *(undefined *)((int)param_1 + 1);
    uStack_2c = *(undefined *)param_1;
    _rtc_set_clr(0x31,0x80,0);
    _rtc_blkwrite(0x20,&uStack_2c,4);
    _rtc_set_clr(0x31,0x80,0xffffffff);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2417 start=0x409168a */

sqword _rtc_get(void)

{
  uint uVar1;
  uint uVar2;
  byte bStack_34;
  undefined uStack_33;
  undefined uStack_32;
  undefined uStack_30;
  undefined uStack_2f;
  undefined uStack_2e;
  byte bStack_2c;
  byte bStack_2b;
  byte bStack_2a;
  undefined uStack_29;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uVar1 = _rtc_read(0x30);
  if ((uVar1 & 0x10) == 0) {
    if (_new_clock_chip == 0) {
      do {
        _rtc_blkread(0x20,&bStack_34,8);
        uVar2 = (uint)bStack_34;
        uVar1 = _rtc_read(0x20);
      } while (uVar1 != uVar2);
      uStack_28 = _bcd_to_byte(bStack_34);
      uStack_24 = _bcd_to_byte(uStack_33);
      uStack_20 = _bcd_to_byte(uStack_32);
      uStack_1c = _bcd_to_byte(uStack_30);
      uStack_18 = _bcd_to_byte(uStack_2f);
      uStack_14 = _bcd_to_byte(uStack_2e);
      uVar1 = _tm_to_sec(&uStack_28);
    }
    else {
      _rtc_blkread(0x20,&bStack_2c,4);
      uVar1 = CONCAT31((uint3)bStack_2a |
                       (uint3)(((uint)bStack_2b << 0x10) >> 8) |
                       (uint3)(((uint)bStack_2c << 0x18) >> 8),uStack_29);
    }
  }
  else {
    uVar1 = 0;
  }
  return (qword)uVar1 << 0x20;
}
/* GHIDRADEC_FUNCTION index=2418 start=0x409178e */

int _bcd_to_byte(byte param_1)

{
  return (param_1 & 0xf) + (uint)(param_1 >> 4) * 10;
}
/* GHIDRADEC_FUNCTION index=2419 start=0x40917b8 */

byte _byte_to_bcd(byte param_1)

{
  byte bVar1;
  
  bVar1 = 0;
  for (; 9 < param_1; param_1 = param_1 - 10) {
    bVar1 = bVar1 + 0x10;
  }
  return param_1 | bVar1;
}
/* GHIDRADEC_FUNCTION index=2420 start=0x40917e2 */

undefined4 _nvram_check(int param_1)

{
  word wVar1;
  word wVar3;
  undefined4 uVar2;
  
  _bzero(param_1,0x20);
  _rtc_blkread(0,param_1,0x20);
  wVar1 = *(word *)(param_1 + 0x1e);
  *(undefined2 *)(param_1 + 0x1e) = 0;
  wVar3 = _checksum_16(param_1,0x10);
  wVar3 = ~wVar3;
  if ((wVar3 == 0) || (wVar1 != wVar3)) {
    _printf(aNonVolatileMem);
    uVar2 = 0xffffffff;
  }
  else {
    *(word *)(param_1 + 0x1e) = wVar3;
    uVar2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=2421 start=0x409184a */

void _nvram_set(int param_1)

{
  word wVar2;
  int iVar1;
  undefined auStack_24 [32];
  
  *(undefined2 *)(param_1 + 0x1e) = 0;
  wVar2 = _checksum_16(param_1,0x10);
  *(word *)(param_1 + 0x1e) = ~wVar2;
  _rtc_blkwrite(0,param_1,0x20);
  _bcopy(param_1,auStack_24,0x20);
  _nvram_check(param_1);
  iVar1 = _bcmp(auStack_24,param_1,0x20);
  if (iVar1 != 0) {
    _printf(aNonVolatileMem_0);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2422 start=0x40918c6 */

undefined4 _rtc_write(byte param_1,char param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  param_1 = param_1 | 0x80;
  *_scr2 = *_scr2 & 0xfffff9ff | 0x100;
  _delay(1);
  iVar3 = 0;
  do {
    uVar1 = *_scr2 & 0xfffffbff;
    if ((char)param_1 < '\0') {
      uVar1 = uVar1 | 0x400;
    }
    *_scr2 = uVar1;
    _delay(1);
    *_scr2 = uVar1 | 0x200;
    _delay(1);
    *_scr2 = CONCAT22((sword)(uVar1 >> 0x10),(sword)(uVar1 | 0x200)) & 0xfffffdff;
    param_1 = param_1 << 1;
    _delay(1);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  iVar3 = 0;
  do {
    uVar1 = *_scr2 & 0xfffffbff;
    if (param_2 < '\0') {
      uVar1 = uVar1 | 0x400;
    }
    *_scr2 = uVar1;
    _delay(1);
    *_scr2 = uVar1 | 0x200;
    _delay(1);
    *_scr2 = CONCAT22((sword)(uVar1 >> 0x10),(sword)(uVar1 | 0x200)) & 0xfffffdff;
    param_2 = param_2 << 1;
    _delay(1);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  uVar1 = *_scr2;
  uVar2 = uVar1 & 0xfffff8ff;
  *_scr2 = uVar2;
  return CONCAT22((sword)(uVar1 >> 0x10),(word)(byte)(((int)uVar2 < 0) << 3 | (uVar2 == 0) << 2));
}
/* GHIDRADEC_FUNCTION index=2423 start=0x40919fa */

undefined4 _rtc_blkwrite(byte param_1,char *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  char *pcVar5;
  
  param_1 = param_1 | 0x80;
  *_scr2 = *_scr2 & 0xfffff9ff | 0x100;
  _delay(1);
  iVar4 = 0;
  do {
    uVar1 = *_scr2 & 0xfffffbff;
    if ((char)param_1 < '\0') {
      uVar1 = uVar1 | 0x400;
    }
    *_scr2 = uVar1;
    _delay(1);
    *_scr2 = uVar1 | 0x200;
    _delay(1);
    *_scr2 = CONCAT22((sword)(uVar1 >> 0x10),(sword)(uVar1 | 0x200)) & 0xfffffdff;
    param_1 = param_1 << 1;
    _delay(1);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 8);
  while (0 < param_3) {
    param_3 = param_3 + -1;
    pcVar5 = param_2 + 1;
    cVar3 = *param_2;
    iVar4 = 0;
    do {
      uVar1 = *_scr2 & 0xfffffbff;
      if (cVar3 < '\0') {
        uVar1 = uVar1 | 0x400;
      }
      *_scr2 = uVar1;
      _delay(1);
      *_scr2 = uVar1 | 0x200;
      _delay(1);
      *_scr2 = CONCAT22((sword)(uVar1 >> 0x10),(sword)(uVar1 | 0x200)) & 0xfffffdff;
      cVar3 = cVar3 * '\x02';
      _delay(1);
      iVar4 = iVar4 + 1;
      param_2 = pcVar5;
    } while (iVar4 < 8);
  }
  uVar1 = *_scr2;
  uVar2 = uVar1 & 0xfffff8ff;
  *_scr2 = uVar2;
  return CONCAT22((sword)(uVar1 >> 0x10),(word)(byte)(((int)uVar2 < 0) << 3 | (uVar2 == 0) << 2));
}
/* GHIDRADEC_FUNCTION index=2424 start=0x4091b46 */

undefined _rtc_read(undefined param_1)

{
  undefined uVar1;
  
  uVar1 = _rtc_real_read(param_1);
  return uVar1;
}

