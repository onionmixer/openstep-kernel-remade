/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012bf04 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _igmp_joingroup(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar3 = _splnet();
  if ((*param_1 == DAT_001e59ac) || (param_1[1] == _loifp)) {
    param_1[4] = 0;
  }
  else {
    _igmp_sendreport(param_1);
    uVar1 = *(uint *)(_in_ifaddr + 4);
    uVar2 = *param_1;
    param_1[4] = ((uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18)
                  + __ipstat +
                 (uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18))
                 % 0x32 + 1;
    DAT_001dbf44 = 1;
  }
  _splx(uVar3);
  return;
}

