
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0019b0a8(uint *param_1,undefined2 *param_2)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  undefined1 local_10;
  undefined1 local_c;
  
  out(0x3c4,2);
  LOCK();
  UNLOCK();
  out(0x3c5,2);
  LOCK();
  _DAT_001e8654 = _DAT_001e8654 + 2;
  UNLOCK();
  uVar1 = *param_1;
  bVar2 = (byte)uVar1;
  local_10 = (byte)((uVar1 & 0x8000) >> 0xf);
  local_c = (byte)((uVar1 & 0x2000) >> 0xc);
  local_10 = local_10 | local_c;
  local_c = (byte)((uVar1 & 0x800) >> 9);
  local_10 = local_10 | local_c;
  local_c = (byte)((uVar1 & 0x200) >> 6);
  local_10 = local_10 | local_c;
  local_c = (byte)((uVar1 & 0x80) >> 3);
  bVar3 = local_10 | local_c;
  uVar5 = uVar1 >> 0x10;
  bVar4 = (byte)(uVar1 >> 0x10);
  local_10 = (byte)(uVar1 >> 0x1f);
  local_c = (byte)((uVar5 & 0x2000) >> 0xc);
  local_10 = local_10 | local_c;
  local_c = (byte)((uVar5 & 0x800) >> 9);
  local_10 = local_10 | local_c;
  local_c = (byte)((uVar5 & 0x200) >> 6);
  *param_2 = CONCAT11(~(local_10 | local_c | (byte)((uVar5 & 0x80) >> 3) | bVar4 & 0x20 |
                        (bVar4 & 8) << 3 | (bVar4 & 0xaa) << 6),
                      ~(bVar3 | bVar2 & 0x20 | (bVar2 & 8) << 3 | (bVar2 & 0xaa) << 6));
  out(0x3c4,2);
  LOCK();
  UNLOCK();
  out(0x3c5,1);
  LOCK();
  _DAT_001e8654 = _DAT_001e8654 + 2;
  UNLOCK();
  uVar1 = *param_1;
  bVar2 = (byte)uVar1;
  local_10 = (byte)((uVar1 & 0x4000) >> 0xe);
  local_c = (byte)((uVar1 & 0x1000) >> 0xb);
  local_10 = local_10 | local_c;
  local_c = (byte)(uVar1 >> 8) & 4;
  local_10 = local_10 | local_c;
  local_c = (byte)((uVar1 & 0x100) >> 5);
  local_10 = local_10 | local_c;
  local_c = (byte)((uVar1 & 0x40) >> 2);
  bVar3 = local_10 | local_c;
  uVar5 = uVar1 >> 0x10;
  bVar4 = (byte)(uVar1 >> 0x10);
  local_10 = (byte)((uVar5 & 0x4000) >> 0xe);
  local_c = (byte)((uVar5 & 0x1000) >> 0xb);
  local_10 = local_10 | local_c;
  local_c = (byte)(uVar1 >> 0x18) & 4;
  local_10 = local_10 | local_c;
  local_c = (byte)((uVar5 & 0x100) >> 5);
  bVar4 = ~(local_10 | local_c | (byte)((uVar5 & 0x40) >> 2) | (bVar4 & 0x10) * '\x02' |
            (bVar4 & 4) << 4 | bVar4 << 7);
  *param_2 = CONCAT11(bVar4,~(bVar3 | (bVar2 & 0x10) * '\x02' | (bVar2 & 4) << 4 | bVar2 << 7));
  out(0x3c4,2);
  LOCK();
  UNLOCK();
  out(0x3c5,0xf);
  LOCK();
  _DAT_001e8654 = _DAT_001e8654 + 2;
  UNLOCK();
  return CONCAT44(0x3c5,CONCAT31((uint3)bVar4,0xf));
}

