/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00121bdc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _rtredirect(ushort *param_1,undefined4 *param_2,uint param_3,void *param_4)

{
  int iVar1;
  uint uVar2;
  uint local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = _ifa_ifwithnet(param_2);
  if (iVar1 == 0) {
    __rtstat = __rtstat + 1;
    return;
  }
  local_14 = *(undefined4 *)param_1;
  local_10 = *(undefined4 *)(param_1 + 2);
  local_c = *(undefined4 *)(param_1 + 4);
  local_8 = *(undefined4 *)(param_1 + 6);
  local_18 = 0;
  _rtalloc(&local_18);
  uVar2 = local_18;
  if (((local_18 == 0) || (iVar1 = _bcmp(param_4,(void *)(local_18 + 0x14),0x10), iVar1 == 0)) &&
     (iVar1 = _ifa_ifwithaddr(param_2), iVar1 == 0)) {
    if (uVar2 != 0) {
      iVar1 = (*(code *)(&PTR__null_netmatch_001db794)[(uint)*param_1 * 2])(&_wildcard,uVar2 + 4);
      if (iVar1 != 0) {
        *(short *)(uVar2 + 0x26) = *(short *)(uVar2 + 0x26) + -1;
        if ((*(uint *)(uVar2 + 0x24) & 0xffff0001) == 0) {
          __rttrash = __rttrash + -1;
          _m_free(uVar2 & 0xffffff80);
        }
        uVar2 = 0;
      }
      if (uVar2 != 0) {
        if ((*(ushort *)(uVar2 + 0x24) & 2) == 0) {
          __rtstat = __rtstat + 1;
        }
        else if (((*(ushort *)(uVar2 + 0x24) & 4) == 0) && ((param_3 & 4) != 0)) {
          _rtinit(param_1,param_2,0x8030720a,param_3 | 0x10);
          _DAT_001e98b2 = _DAT_001e98b2 + 1;
        }
        else {
          *(undefined4 *)(uVar2 + 0x14) = *param_2;
          *(undefined4 *)(uVar2 + 0x18) = param_2[1];
          *(undefined4 *)(uVar2 + 0x1c) = param_2[2];
          *(undefined4 *)(uVar2 + 0x20) = param_2[3];
          *(byte *)(uVar2 + 0x24) = *(byte *)(uVar2 + 0x24) | 0x20;
          _DAT_001e98b4 = _DAT_001e98b4 + 1;
        }
        if (uVar2 == 0) {
                    /* WARNING: Subroutine does not return */
          _panic(s_rtfree_001db950);
        }
        goto LAB_00121d44;
      }
    }
    _rtinit(param_1,param_2,0x8030720a,(byte)param_3 & 4 | 0x12);
    _DAT_001e98b2 = _DAT_001e98b2 + 1;
  }
  else {
    __rtstat = __rtstat + 1;
    if (uVar2 == 0) {
      return;
    }
LAB_00121d44:
    *(short *)(uVar2 + 0x26) = *(short *)(uVar2 + 0x26) + -1;
    if ((*(uint *)(uVar2 + 0x24) & 0xffff0001) == 0) {
      __rttrash = __rttrash + -1;
      _m_free(uVar2 & 0xffffff80);
    }
  }
  return;
}

