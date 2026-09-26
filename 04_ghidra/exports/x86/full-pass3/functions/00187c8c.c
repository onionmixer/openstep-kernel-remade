/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00187c8c */

void _set_timer(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  
  if (param_1 == 0) {
    uVar5 = __udivdi3(param_2 + 9999999,param_3 + (uint)(0xff676980 < param_2),10000000,0);
    iVar4 = (int)((ulonglong)uVar5 >> 0x20);
    uVar1 = (uint)uVar5;
    iVar3 = ((iVar4 << 5 | uVar1 >> 0x1b) - iVar4) - (uint)(uVar1 * 0x20 < uVar1);
    iVar4 = ((((iVar3 * 0x40 | uVar1 * 0x1f >> 0x1a) - iVar3) - (uint)(uVar1 * 0x7c0 < uVar1 * 0x1f)
             ) * 8 | uVar1 * 0x7a1 >> 0x1d) + iVar4 + (uint)CARRY4(uVar1 * 0x3d08,uVar1);
    uVar2 = _splusclock();
    DAT_001e75dc = uVar1 * 10000000 + DAT_001e75d0;
    DAT_001e75e0 = (((iVar4 * 4 | uVar1 * 0x3d09 >> 0x1e) + iVar4 +
                    (uint)CARRY4(uVar1 * 0xf424,uVar1 * 0x3d09)) * 0x80 | uVar1 * 0x1312d >> 0x19) +
                   DAT_001e75d4 + (uint)CARRY4(uVar1 * 10000000,DAT_001e75d0);
    _splx(uVar2);
  }
  return;
}

