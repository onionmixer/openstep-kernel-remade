/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001d0fb4 */

/* WARNING: Removing unreachable block (ram,0x001d109e) */

undefined8 __udivdi3(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  byte bVar4;
  int iVar5;
  byte bVar6;
  uint uVar7;
  uint local_20;
  
  local_20 = param_3;
  if (param_4 == 0) {
    if (param_3 <= param_2) {
      if (param_3 == 0) {
        local_20 = 1 / 0;
      }
      uVar7 = param_2 / local_20;
      iVar5 = (int)(((ulonglong)param_2 % (ulonglong)local_20 << 0x20 | (ulonglong)param_1) /
                   (ulonglong)local_20);
      goto LAB_001d10a6;
    }
    iVar5 = (int)(CONCAT44(param_2,param_1) / (ulonglong)param_3);
  }
  else if (param_2 < param_4) {
LAB_001d101c:
    iVar5 = 0;
  }
  else {
    uVar7 = 0x1f;
    if (param_4 != 0) {
      for (; param_4 >> uVar7 == 0; uVar7 = uVar7 - 1) {
      }
    }
    if ((uVar7 ^ 0x1f) == 0) {
      if ((param_2 <= param_4) && (param_1 < param_3)) goto LAB_001d101c;
      iVar5 = 1;
    }
    else {
      bVar4 = (byte)(uVar7 ^ 0x1f);
      bVar6 = 0x20 - bVar4;
      uVar1 = (ulonglong)(param_4 << (bVar4 & 0x1f) | param_3 >> (bVar6 & 0x1f));
      uVar2 = CONCAT44(param_2 >> (bVar6 & 0x1f),
                       param_2 << (bVar4 & 0x1f) | param_1 >> (bVar6 & 0x1f));
      uVar3 = uVar2 / uVar1;
      iVar5 = (int)uVar3;
      if (CONCAT44((int)(uVar2 % uVar1),param_1 << (bVar4 & 0x1f)) <
          (ulonglong)(param_3 << (bVar4 & 0x1f)) * (uVar3 & 0xffffffff)) {
        iVar5 = iVar5 + -1;
      }
    }
  }
  uVar7 = 0;
LAB_001d10a6:
  return CONCAT44(uVar7,iVar5);
}

