
void sub_40800CC(void)

{
  uint uVar1;
  uint uVar2;
  word wVar3;
  uint uVar4;
  sword sVar5;
  uint uVar6;
  uint unaff_D5;
  undefined *puVar7;
  uint uStack_24;
  uint *puVar8;
  
  puVar7 = &stack0xffffffe0;
  dword_40B5080 = (_gpflags & 0x1f) >> 4;
  dword_40B5084 = (_gpflags & 0xf) >> 3;
  byte_40C6CED = (undefined)_gpflags;
  if ((_vol_r == dword_40B5088) && (_vol_l == dword_40B508C)) {
    uStack_24 = _gpflags << 0x18;
    _mon_send(0xc4);
    puVar7 = &stack0xffffffe0;
  }
  else {
    _vol_r = _vol_r & 0x3f;
    _vol_l = _vol_l & 0x3f;
    if (_mon_rev != '\0') {
      uStack_24 = _gpflags << 0x18;
      _mon_send(0xc4);
      _delay(200);
      if (_vol_l == _vol_r) {
        uStack_24 = _vol_r << 0x18 | 0xc0000000;
        _mon_send(0xc2);
      }
      else {
        uStack_24 = _vol_r << 0x18 | 0x80000000;
        _mon_send(0xc2);
        _delay(200);
        _mon_send(0xc2,_vol_l << 0x18 | 0x40000000);
      }
      puVar8 = &uStack_24;
      uStack_24 = 200;
      _delay();
      dword_40B5088 = _vol_r;
      dword_40B508C = _vol_l;
      goto loc_4080342;
    }
    unaff_D5 = _gpflags << 0x18;
  }
  do {
    if ((_vol_r == dword_40B5088) && (_vol_l == dword_40B508C)) {
      return;
    }
    if (_vol_l == _vol_r) {
      uVar6 = _vol_r | 0x7c0;
      dword_40B5088 = _vol_r;
loc_4080278:
      dword_40B508C = _vol_l;
    }
    else {
      if (_vol_r == dword_40B5088) {
        uVar6 = _vol_l | 0x740;
        goto loc_4080278;
      }
      uVar6 = _vol_r | 0x780;
      dword_40B5088 = _vol_r;
    }
    *(uint *)(puVar7 + -4) = unaff_D5;
    *(undefined4 *)(puVar7 + -8) = 0xc4;
    *(undefined4 *)(puVar7 + -0xc) = 0x408028e;
    _mon_send();
    *(undefined4 *)(puVar7 + -0xc) = 200;
    *(undefined4 *)(puVar7 + -0x10) = 0x4080298;
    _delay();
    uVar4 = 10;
    do {
      uVar1 = (int)uVar6 >> (uVar4 & 0x3f) & 1;
      uVar2 = unaff_D5;
      if (uVar1 != 0) {
        uVar2 = unaff_D5 | 0x2000000;
      }
      *(uint *)(puVar7 + -4) = uVar2;
      *(undefined4 *)(puVar7 + -8) = 0xc4;
      *(undefined4 *)(puVar7 + -0xc) = 0x40802ba;
      _mon_send();
      *(undefined4 *)(puVar7 + -0xc) = 200;
      *(undefined4 *)(puVar7 + -0x10) = 0x40802c4;
      _delay();
      if (uVar1 == 0) {
        uVar1 = unaff_D5 | 0x4000000;
      }
      else {
        uVar1 = unaff_D5 | 0x6000000;
      }
      *(uint *)(puVar7 + -4) = uVar1;
      *(undefined4 *)(puVar7 + -8) = 0xc4;
      *(undefined4 *)(puVar7 + -0xc) = 0x40802e8;
      _mon_send();
      *(undefined4 *)(puVar7 + -0xc) = 200;
      *(undefined4 *)(puVar7 + -0x10) = 0x40802f2;
      _delay();
      wVar3 = (word)(uVar4 >> 0x10);
      sVar5 = (sword)uVar4 + -1;
      uVar4 = CONCAT22(wVar3,sVar5);
    } while ((sVar5 != -1) || (uVar4 = (uint)wVar3 * 0x10000 - 1, wVar3 != 0));
    *(uint *)(puVar7 + -4) = unaff_D5;
    *(undefined4 *)(puVar7 + -8) = 0xc4;
    *(undefined4 *)(puVar7 + -0xc) = 0x408030e;
    _mon_send();
    *(undefined4 *)(puVar7 + -0xc) = 200;
    *(undefined4 *)(puVar7 + -0x10) = 0x408031a;
    _delay();
    *(uint *)(puVar7 + -0x10) = unaff_D5 | 0x1000000;
    *(undefined4 *)(puVar7 + -0x14) = 0xc4;
    *(undefined4 *)(puVar7 + -0x18) = 0x4080328;
    _mon_send();
    *(undefined4 *)(puVar7 + -0x18) = 200;
    *(undefined4 *)(puVar7 + -0x1c) = 0x408032e;
    _delay();
    *(uint *)(puVar7 + -0x1c) = unaff_D5;
    *(undefined4 *)(puVar7 + -0x20) = 0xc4;
    *(undefined4 *)(puVar7 + -0x24) = 0x4080336;
    _mon_send();
    puVar8 = (uint *)(puVar7 + -4);
    *(undefined4 *)(puVar7 + -4) = 200;
    *(undefined4 *)(puVar7 + -8) = 0x4080342;
    _delay();
loc_4080342:
    puVar7 = (undefined *)((int)puVar8 + 4);
  } while( true );
}

