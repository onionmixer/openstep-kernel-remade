/* GHIDRADEC_FUNCTION index=2025 start=0x406cf86 */

void _fc_send_byte(int *param_1,undefined param_2)

{
  int iVar1;
  
  iVar1 = sub_406CFE8(param_1,0);
  if (iVar1 == 0) {
    *(undefined *)(*param_1 + 5) = param_2;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2026 start=0x406cfb6 */

void _fc_get_byte(int *param_1,undefined *param_2)

{
  int iVar1;
  
  iVar1 = sub_406CFE8(param_1,0x40);
  if (iVar1 == 0) {
    *param_2 = *(undefined *)(*param_1 + 5);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2027 start=0x406d082 */

void _fc_flpctl_bset(int *param_1,byte param_2)

{
  param_2 = param_2 | *(byte *)((int)param_1 + 0x25);
  *(byte *)((int)param_1 + 0x25) = param_2;
  *(byte *)(*param_1 + 8) = param_2;
  return;
}
/* GHIDRADEC_FUNCTION index=2028 start=0x406d0a0 */

void _fc_flpctl_bclr(int *param_1,byte param_2)

{
  byte bVar1;
  
  bVar1 = *(byte *)((int)param_1 + 0x25) & ~param_2;
  *(byte *)((int)param_1 + 0x25) = bVar1;
  *(byte *)(*param_1 + 8) = bVar1;
  return;
}
/* GHIDRADEC_FUNCTION index=2029 start=0x406d152 */

void _fc_configure(undefined4 param_1)

{
  undefined auStack_5e [2];
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined uStack_54;
  undefined uStack_53;
  byte bStack_52;
  undefined uStack_51;
  undefined4 uStack_44;
  
  _bzero(auStack_5e,0x5a);
  uStack_54 = 0x13;
  uStack_53 = 0;
  bStack_52 = byte_40B14AD | byte_40B14A9 | 0x50;
  uStack_51 = 0;
  uStack_5c = 10000;
  uStack_58 = 1;
  uStack_44 = 4;
  _fc_send_cmd(param_1,auStack_5e);
  return;
}
/* GHIDRADEC_FUNCTION index=2030 start=0x406d1ba */

int _fc_specify(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  byte bVar6;
  int iVar5;
  byte bVar7;
  undefined4 uVar8;
  undefined auStack_5e [2];
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined uStack_54;
  uint uStack_53;
  undefined uStack_4f;
  undefined4 uStack_44;
  
  iVar5 = *param_1;
  _bzero(auStack_5e,0x5a);
  uStack_54 = 3;
  if (param_2 == 2) {
    bVar7 = 0;
    uVar8 = 0;
    if (_machine_type == '\0') {
      _fc_flpctl_bclr(param_1,0x40);
    }
    iVar3 = *(int *)(param_3 + 0x34);
    if (iVar3 < 0x100) {
      iVar2 = iVar3 + 1;
      if (iVar2 < 0) {
        iVar2 = iVar3 + 2;
      }
      iVar2 = iVar2 >> 1;
    }
    else {
      iVar2 = 0;
    }
    uVar4 = CONCAT31((int3)uStack_53,uStack_4f) & 0x1ffffff;
    uStack_53._1_3_ = (uint3)(uVar4 >> 8) | (uint3)((uint)(iVar2 << 0x19) >> 8);
    uStack_53 = CONCAT13((char)((uint)(*(int *)(param_3 + 0x30) * -0x10000000) >> 0x18),
                         uStack_53._1_3_);
    uStack_4f = (undefined)uVar4;
    iVar3 = *(int *)(param_3 + 0x38);
    if (iVar3 < 0x100) {
      iVar2 = iVar3 + 0xf;
      if (iVar2 < 0) {
        iVar2 = iVar3 + 0x1e;
      }
      uVar4 = iVar2 >> 4;
    }
    else {
loc_406D35E:
      uVar4 = 0;
    }
  }
  else if (param_2 < 3) {
    if (param_2 != 1) {
loc_406D36C:
      _printf(aFdBogusDensity,param_2);
      return 4;
    }
    bVar7 = 2;
    uVar8 = 0;
    if (_machine_type == '\0') {
      _fc_flpctl_bset(param_1,0x40);
    }
    iVar3 = *(int *)(param_3 + 0x30) + 1;
    if (iVar3 < 0) {
      iVar3 = *(int *)(param_3 + 0x30) + 2;
    }
    iVar2 = *(int *)(param_3 + 0x34);
    if (iVar2 < 0x200) {
      iVar1 = iVar2 + 3;
      if (iVar1 < 0) {
        iVar1 = iVar2 + 6;
      }
      iVar1 = iVar1 >> 2;
    }
    else {
      iVar1 = 0;
    }
    uVar4 = CONCAT31((int3)uStack_53,uStack_4f) & 0x1ffffff;
    uStack_53._1_3_ = (uint3)(uVar4 >> 8) | (uint3)((uint)(iVar1 << 0x19) >> 8);
    uStack_53 = CONCAT13((char)((uint)((iVar3 >> 1) * -0x10000000) >> 0x18),uStack_53._1_3_);
    uStack_4f = (undefined)uVar4;
    iVar3 = *(int *)(param_3 + 0x38);
    if (0x1ff < iVar3) goto loc_406D35E;
    iVar2 = iVar3 + 0x1f;
    if (iVar2 < 0) {
      iVar2 = iVar3 + 0x3e;
    }
    uVar4 = iVar2 >> 5;
  }
  else {
    if (param_2 != 3) goto loc_406D36C;
    bVar7 = 3;
    uVar8 = 1;
    if (_machine_type == '\0') {
      _fc_flpctl_bset(param_1,0x40);
    }
    iVar3 = 0;
    if (*(int *)(param_3 + 0x34) < 0x80) {
      iVar3 = *(int *)(param_3 + 0x34);
    }
    uVar4 = CONCAT31(uStack_53._1_3_,uStack_4f) & 0x1ffffff;
    uStack_53._1_3_ = (uint3)(uVar4 >> 8) | (uint3)((uint)(iVar3 << 0x19) >> 8);
    uStack_53 = CONCAT13(-(char)(*(int *)(param_3 + 0x30) << 5),uStack_53._1_3_);
    uStack_4f = (undefined)uVar4;
    iVar3 = *(int *)(param_3 + 0x38);
    if (0x7f < iVar3) goto loc_406D35E;
    iVar2 = iVar3 + 7;
    if (iVar2 < 0) {
      iVar2 = iVar3 + 0xe;
    }
    uVar4 = iVar2 >> 3;
  }
  uStack_53 = uStack_53 | (uVar4 & 0xf) << 0x18;
  bVar6 = bVar7;
  if (*(int *)(param_3 + 0x40) == 0) {
    bVar6 = bVar7 | 0x1c;
  }
  *(byte *)(iVar5 + 4) = bVar6;
  *(byte *)(iVar5 + 7) = bVar7;
  uStack_5c = 10000;
  uStack_58 = 1;
  uStack_44 = 3;
  iVar5 = _fc_send_cmd(param_1,auStack_5e);
  if (*(int *)(param_3 + 0x3c) != 0) {
    if (iVar5 != 0) goto loc_406D3D4;
    iVar5 = sub_406D5CE(param_1,1,uVar8);
  }
  if (iVar5 == 0) {
    *(int *)((int)param_1 + 0x25e) = param_2;
    return 0;
  }
loc_406D3D4:
  *(undefined4 *)((int)param_1 + 0x25e) = 0;
  return iVar5;
}
/* GHIDRADEC_FUNCTION index=2031 start=0x406d65c */

undefined8 _fc_flags_bset(int param_1,uint param_2)

{
  uint uVar1;
  char in_XF;
  
  uVar1 = param_2 | *(uint *)(param_1 + 0x18);
  *(uint *)(param_1 + 0x18) = uVar1;
  return CONCAT44(CONCAT22((sword)(uVar1 >> 0x10),
                           (word)(byte)(((int)uVar1 < 0) << 3 | (uVar1 == 0) << 2)),
                  (int)(sword)(word)(byte)(in_XF << 4 | ((int)param_2 < 0) << 3 |
                                          (param_2 == 0) << 2));
}
/* GHIDRADEC_FUNCTION index=2032 start=0x406d688 */

undefined4 _fc_flags_bclr(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = ~param_2 & *(uint *)(param_1 + 0x18);
  *(uint *)(param_1 + 0x18) = uVar1;
  return CONCAT22((sword)(uVar1 >> 0x10),(word)(byte)(((int)uVar1 < 0) << 3 | (uVar1 == 0) << 2));
}
/* GHIDRADEC_FUNCTION index=2033 start=0x406d6b6 */

undefined4 _fd_start(int param_1)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  undefined *puVar9;
  
  puVar3 = (uint *)_disksort_first(param_1 + 0xba);
  if (puVar3 != (uint *)0x0) {
    *(byte *)(param_1 + 0xc6) = *(byte *)(param_1 + 0xc6) | 0x10;
  }
  if ((uint *)(param_1 + 0x18) == puVar3) {
    _bcopy(*(undefined4 *)(param_1 + 0x5c),param_1 + 0x60,0x5a);
    *(undefined4 *)(param_1 + 0x140) = 0;
    goto loc_406D862;
  }
  iVar1 = *(int *)(param_1 + 0x14);
  uVar6 = *(word *)((int)puVar3 + 0x1e) & 7;
  if (1 < uVar6) {
    uVar4 = *(undefined4 *)(param_1 + 0x10);
    puVar9 = aFdDBadFloppyPa;
loc_406D752:
    _printf(puVar9,uVar4);
    if ((*(word *)((int)puVar3 + 0x1e) & 7) == 1) {
      *(undefined2 *)(puVar3 + 7) = 4;
    }
    else {
      *(undefined2 *)(puVar3 + 7) = 0x16;
    }
    *puVar3 = *puVar3 | 4;
    _fd_done(param_1);
    return 1;
  }
  if ((*puVar3 & 1) == 0) {
    *(uint *)(param_1 + 0x15c) = *(uint *)(param_1 + 0x15c) & 0xfffffffe;
  }
  else {
    *(uint *)(param_1 + 0x15c) = *(uint *)(param_1 + 0x15c) | 1;
  }
  if (uVar6 == 1) {
    *(uint *)(param_1 + 0x15c) = *(uint *)(param_1 + 0x15c) | 2;
    *(uint *)(param_1 + 0x13c) = puVar3[9];
    uVar6 = *(uint *)(param_1 + 0x186);
    uVar7 = *(uint *)(param_1 + 0x13c);
    uVar5 = *(uint *)(param_1 + 0x192);
    if (uVar5 < ((puVar3[5] - 1) + uVar6) / uVar6 + uVar7) {
loc_406D7F2:
      *(uint *)(param_1 + 0x140) = uVar6 * (uVar5 - uVar7);
    }
    else {
      *(uint *)(param_1 + 0x140) = puVar3[5];
    }
  }
  else {
    if ((*(byte *)(param_1 + 0x179) & 2) == 0) {
      uVar4 = *(undefined4 *)(param_1 + 0x10);
      puVar9 = aFdDInvalidLabe;
      goto loc_406D752;
    }
    *(uint *)(param_1 + 0x15c) = *(uint *)(param_1 + 0x15c) & 0xfffffffd;
    piVar8 = (int *)(uVar6 * 0x2e + 0xbe + iVar1);
    iVar2 = (int)*(sword *)(iVar1 + 0x70) + *piVar8 + puVar3[9];
    *(int *)(param_1 + 0x13c) = iVar2;
    *(int *)(param_1 + 0x13c) = *(int *)(param_1 + 0x196) * iVar2;
    uVar6 = *(uint *)(iVar1 + 0x5c);
    uVar7 = puVar3[9];
    uVar5 = piVar8[1];
    if ((int)uVar5 < (int)((int)((puVar3[5] - 1) + uVar6) / (int)uVar6 + uVar7)) goto loc_406D7F2;
    *(uint *)(param_1 + 0x140) = puVar3[5];
  }
  *(uint *)(param_1 + 0x144) = puVar3[8];
  if ((*puVar3 & 0x4000010) == 0x10) {
    *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(*(int *)(puVar3[0xb] + 0x66) + 8);
    *(undefined4 *)(param_1 + 0xb0) = *(undefined4 *)(*(int *)(param_1 + 0xb4) + 0x20);
  }
  else {
    uVar4 = _pmap_kernel();
    *(undefined4 *)(param_1 + 0xb0) = uVar4;
  }
  sub_406DC10(param_1,(*(uint *)(param_1 + 0x15c) ^ 1) & 1);
  *(undefined4 *)(param_1 + 0x154) = _fd_inner_retry;
  *(undefined4 *)(param_1 + 0x158) = _fd_outer_retry;
loc_406D862:
  *(undefined4 *)(param_1 + 0x132) = 1;
  uVar4 = _fc_start(param_1);
  return uVar4;
}
/* GHIDRADEC_FUNCTION index=2034 start=0x406d8a6 */

void _fd_intr(int param_1)

{
  uint uVar1;
  undefined6 *puVar2;
  byte bVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  undefined6 *puStack_1c;
  
  bVar3 = *(byte *)(param_1 + 0x6a);
  if ((*(int *)(param_1 + 4) == 0) && (-1 < *(sword *)(dword_40C3710 + 0xc))) {
    uVar1 = (int)*(sword *)(dword_40C3710 + 0xc) & 0x3f;
    _dk_busy = (-2 << uVar1 | 0xfffffffeU >> 0x20 - uVar1) & _dk_busy;
  }
  puStack_1c = (undefined6 *)(param_1 + 0xba);
  iStack_20 = 0x406d8e6;
  iVar4 = _disksort_first();
  piVar7 = (int *)&stack0xffffffe8;
  if (param_1 + 0x18 == iVar4) goto loc_406DB02;
  if (*(uint *)(param_1 + 0xa6) != 0) {
    puVar2 = *(undefined6 **)(param_1 + 0x186);
    if ((byte)((bVar3 & 0x1f) - 5) < 2) {
      *(uint *)(param_1 + 0xa6) = -(int)puVar2 & *(uint *)(param_1 + 0xa6);
    }
    if ((*(int *)(param_1 + 0x9e) == 6) && (*(int *)(param_1 + 0xa6) != 0)) {
      *(int *)(param_1 + 0xa6) = *(int *)(param_1 + 0xa6) - (int)puVar2;
    }
    if (*(int *)(param_1 + 0x164) == 0) {
      *(int *)(param_1 + 0x140) = *(int *)(param_1 + 0x140) - *(int *)(param_1 + 0xa6);
    }
    else {
      iStack_20 = *(int *)(param_1 + 0x160);
      iStack_24 = 0x406d936;
      puStack_1c = puVar2;
      _kfree();
      if (*(int *)(param_1 + 0xa6) == *(int *)(param_1 + 0x14c)) {
        *(int *)(param_1 + 0x140) = *(int *)(param_1 + 0x140) - *(int *)(param_1 + 0x164);
      }
      *(undefined4 *)(param_1 + 0x164) = 0;
    }
    *(int *)(param_1 + 0x144) = *(int *)(param_1 + 0xa6) + *(int *)(param_1 + 0x144);
    if (puVar2 != (undefined6 *)0x0) {
      *(int *)(param_1 + 0x13c) =
           *(uint *)(param_1 + 0xa6) / (uint)puVar2 + *(int *)(param_1 + 0x13c);
    }
  }
  piVar7 = (int *)&stack0xffffffe8;
  switch(*(undefined4 *)(param_1 + 0x9e)) {
  case :
    iVar4 = *(int *)(param_1 + 0x132);
    if (iVar4 == 2) {
      uVar5 = 1;
loc_406D9F8:
      *(undefined4 *)(param_1 + 0x132) = uVar5;
    }
    else {
      if (2 < iVar4) {
        if (iVar4 != 3) goto loc_406DA1E;
        uVar5 = 2;
        goto loc_406D9F8;
      }
      if (iVar4 != 1) {
loc_406DA1E:
        puStack_1c = (undefined6 *)aFdIntrBogusFvp;
                    /* WARNING: Subroutine does not return */
        iStack_20 = 0x406da2a;
        _panic();
      }
    }
    if (*(int *)(param_1 + 0x140) != 0) {
      puStack_1c = (undefined6 *)((*(uint *)(param_1 + 0x15c) ^ 1) & 1);
      piVar6 = &iStack_20;
      iStack_20 = param_1;
      iStack_24 = 0x406da1a;
      sub_406DC10();
loc_406DAEA:
      *(int *)((int)piVar6 + -4) = param_1;
      *(undefined4 *)((int)piVar6 + -8) = 0x406daf2;
      _fc_start();
      return;
    }
    break;
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
    if (*(int *)(param_1 + 0x132) == 2) {
      iVar4 = *(int *)(param_1 + 0x154);
      *(int *)(param_1 + 0x154) = iVar4 + -1;
      if (iVar4 != 1 && -1 < iVar4 + -1) {
        puStack_1c = &aRetry;
        iStack_20 = param_1;
        iStack_24 = 0x406da8e;
        sub_406DB14();
        iStack_24 = 0;
        piVar6 = &iStack_28;
        iStack_28 = param_1;
        sub_406DC10();
        goto loc_406DAEA;
      }
      iVar4 = *(int *)(param_1 + 0x158);
      *(int *)(param_1 + 0x158) = *(int *)(param_1 + 0x158) + -1;
      if (0 < iVar4) {
        puStack_1c = (undefined6 *)aRecalibrate;
        iStack_20 = param_1;
        iStack_24 = 0x406da64;
        sub_406DB14();
        *(undefined4 *)(param_1 + 0x154) = _fd_inner_retry;
        iStack_24 = param_1 + 0x60;
        piVar6 = &iStack_28;
        iStack_28 = param_1;
        sub_406E192();
        *(undefined4 *)(param_1 + 0x132) = 3;
        goto loc_406DAEA;
      }
    }
    else {
      if ((*(byte *)(param_1 + 0x15f) & 1) == 0) {
        puStack_1c = (undefined6 *)0x0;
        iStack_20 = param_1;
        iStack_24 = 0x406dac6;
        sub_406DC10();
        *(undefined4 *)(param_1 + 0x132) = 2;
      }
      else {
        puStack_1c = (undefined6 *)0x1;
        iStack_20 = param_1;
        iStack_24 = 0x406daae;
        iVar4 = sub_406DC10();
        if (iVar4 == 0) {
          *(undefined4 *)(param_1 + 0x132) = 2;
        }
      }
      if ((*(int *)(param_1 + 0x132) != 2) || (*(int *)(param_1 + 0x154) != 0)) {
        puStack_1c = &aRetry;
        piVar6 = &iStack_20;
        iStack_20 = param_1;
        iStack_24 = 0x406daea;
        sub_406DB14();
        goto loc_406DAEA;
      }
    }
  :
    puStack_1c = &aFatal;
    piVar7 = &iStack_20;
    iStack_20 = param_1;
    iStack_24 = 0x406db02;
    sub_406DB14();
  }
loc_406DB02:
  *(int *)((int)piVar7 + -4) = param_1;
  *(undefined4 *)((int)piVar7 + -8) = 0x406db0a;
  _fd_done();
  return;
}
/* GHIDRADEC_FUNCTION index=2035 start=0x406db60 */

void _fd_done(int param_1)

{
  uint *puVar1;
  int iVar2;
  
  puVar1 = (uint *)_disksort_first(param_1 + 0xba);
  if (puVar1 == (uint *)0x0) {
                    /* WARNING: Subroutine does not return */
    _panic(aSddoneNoBufOnS);
  }
  puVar1[10] = *(uint *)(param_1 + 0x140);
  if (*(int *)(param_1 + 0x9e) != 0) {
    if (*(int *)(param_1 + 0x9e) == 0x14) {
      *(undefined2 *)(puVar1 + 7) = 6;
    }
    else {
      *(undefined2 *)(puVar1 + 7) = 5;
    }
  }
  if (*(sword *)(puVar1 + 7) != 0) {
    *puVar1 = *puVar1 | 4;
  }
  _disksort_remove(param_1 + 0xba,puVar1);
  if ((uint *)(param_1 + 0x18) == puVar1) {
    _bcopy(param_1 + 0x60,*(undefined4 *)(param_1 + 0x5c),0x5a);
  }
  _biodone(puVar1);
  *(undefined4 *)(param_1 + 0x132) = 0;
  iVar2 = _disksort_first(param_1 + 0xba);
  if (iVar2 != 0) {
    _fd_start(param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2036 start=0x406dd96 */

undefined4 _fd_get_label(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined auStack_62 [94];
  
  iVar3 = 0;
  if (*(int *)(param_1 + 0x176) == 0) {
    uVar1 = 5;
  }
  else {
    uVar5 = (*(uint *)(param_1 + 0x186) + 0x1c47) / *(uint *)(param_1 + 0x186);
    iVar4 = 0;
    do {
      iVar2 = _fd_live_rw(param_1,iVar3,uVar5,*(undefined4 *)(param_1 + 0x14),1,auStack_62);
      if ((iVar2 == 0) && (iVar2 = _sdchecklabel(*(undefined4 *)(param_1 + 0x14),iVar3), iVar2 != 0)
         ) {
        *(uint *)(param_1 + 0x176) = *(uint *)(param_1 + 0x176) | 2;
        return 0;
      }
      iVar3 = uVar5 + iVar3;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 4);
    *(uint *)(param_1 + 0x176) = *(uint *)(param_1 + 0x176) & 0xfffffffd;
    uVar1 = 1;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2037 start=0x406de1a */

undefined4 _fd_write_label(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined auStack_62 [94];
  
  uVar5 = 0;
  iVar2 = 0;
  if (*(uint *)(param_1 + 0x176) == 0) {
    uVar5 = 5;
  }
  else {
    uVar4 = (*(uint *)(param_1 + 0x186) + 0x1c47) / *(uint *)(param_1 + 0x186);
    *(uint *)(param_1 + 0x176) = *(uint *)(param_1 + 0x176) | 2;
    _fd_setbratio(param_1);
    iVar3 = 0;
    do {
      *(int *)(*(int *)(param_1 + 0x14) + 4) = iVar2;
      iVar1 = _fd_live_rw(param_1,iVar2,uVar4,*(undefined4 *)(param_1 + 0x14),0,auStack_62);
      if (iVar1 != 0) {
        uVar5 = 1;
      }
      iVar2 = uVar4 + iVar2;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 4);
  }
  return uVar5;
}
/* GHIDRADEC_FUNCTION index=2038 start=0x406de98 */

int _fd_live_rw(int param_1,int param_2,int param_3,int param_4,int param_5,uint *param_6)

{
  sword sVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)_kalloc(0x44);
  if (piVar2 == (int *)0x0) {
    return 0xc;
  }
  _bzero(piVar2,0x44);
  piVar2[9] = param_2;
  piVar2[8] = param_4;
  piVar2[5] = *(int *)(param_1 + 0x186) * param_3;
  *piVar2 = -(int)-(param_5 != 0);
  *(word *)((int)piVar2 + 0x1e) =
       (sword)*(undefined4 *)(param_1 + 0x10) << 3 | (sword)_fd_raw_major << 8 | 1;
  iVar3 = _fdstrategy(piVar2);
  if ((iVar3 == 0) && (_fd_polling_mode == 0)) {
    _biowait(piVar2);
  }
  if (*(uint *)(param_1 + 0x186) != 0) {
    *param_6 = (uint)piVar2[10] / *(uint *)(param_1 + 0x186);
  }
  if ((*piVar2 & 4) != 0) {
    sVar1 = *(sword *)(piVar2 + 7);
    if (sVar1 == 6) {
      iVar3 = 0x14;
    }
    else {
      if (sVar1 < 7) {
        if (sVar1 == 5) {
          iVar3 = 8;
          goto loc_406DF78;
        }
      }
      else {
        if (sVar1 == 0x16) {
          iVar3 = 4;
          goto loc_406DF78;
        }
        if (sVar1 == 0x1e) {
          iVar3 = 0xd;
          goto loc_406DF78;
        }
      }
      iVar3 = 0xb;
    }
  }
loc_406DF78:
  _kfree(piVar2,0x44);
  return iVar3;
}
/* GHIDRADEC_FUNCTION index=2039 start=0x406df90 */

void _fd_raw_rw(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  undefined auStack_5e [90];
  
  _bzero(auStack_5e,0x5a);
  sub_406DCC0(param_1,auStack_5e,param_2,*(int *)(param_1 + 0x186) * param_3,param_4,param_5);
  _fd_command(param_1,auStack_5e);
  return;
}
/* GHIDRADEC_FUNCTION index=2040 start=0x406dfec */

int _fd_readid(int param_1,word param_2,undefined4 *param_3)

{
  int iVar1;
  undefined auStack_5e [2];
  undefined4 uStack_5c;
  undefined4 uStack_58;
  word wStack_54;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_28;
  undefined4 uStack_24;
  int iStack_20;
  
  _bzero(auStack_5e,0x5a);
  wStack_54 = wStack_54 & 0x8afb | 0xa00 | (word)((*(uint *)(param_1 + 0x182) & 1) << 0xe) |
              (param_2 & 1) << 2;
  auStack_5e[0] = *(undefined *)(param_1 + 0x17d);
  uStack_5c = 10000;
  uStack_58 = 1;
  uStack_44 = 2;
  uStack_40 = 0;
  uStack_3c = 0;
  uStack_28 = 7;
  uStack_24 = 0;
  iVar1 = _fd_command(param_1,auStack_5e);
  *param_3 = uStack_38;
  param_3[1] = uStack_34;
  if ((iStack_20 == 0) && (iStack_20 = 4, iVar1 == 0)) {
    iStack_20 = 0;
  }
  return iStack_20;
}
/* GHIDRADEC_FUNCTION index=2041 start=0x406e08c */

void _fd_get_status(undefined4 param_1,undefined2 *param_2)

{
  undefined auStack_5e [2];
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined2 uStack_10;
  
  _bzero(auStack_5e,0x5a);
  uStack_58 = 5;
  uStack_5c = 10000;
  _fd_command(param_1,auStack_5e);
  *param_2 = uStack_10;
  return;
}
/* GHIDRADEC_FUNCTION index=2042 start=0x406e0d2 */

void _fd_recal(undefined4 param_1)

{
  undefined auStack_5e [90];
  
  sub_406E192(param_1,auStack_5e);
  _fd_command(param_1,auStack_5e);
  return;
}
/* GHIDRADEC_FUNCTION index=2043 start=0x406e102 */

void _fd_seek(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined auStack_5e [90];
  
  _bzero(auStack_5e,0x5a);
  _fd_gen_seek(*(undefined4 *)(param_1 + 0x17a),auStack_5e,param_2,param_3);
  _fd_command(param_1,auStack_5e);
  return;
}
/* GHIDRADEC_FUNCTION index=2044 start=0x406e14a */

int _fd_basic_cmd(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined auStack_5e [2];
  undefined4 uStack_5c;
  undefined4 uStack_58;
  int iStack_20;
  
  _bzero(auStack_5e,0x5a);
  uStack_58 = param_2;
  uStack_5c = 10000;
  iVar1 = _fd_command(param_1,auStack_5e);
  if (iVar1 == 0) {
    iVar1 = iStack_20;
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=2045 start=0x406e1d8 */

void _fd_gen_seek(undefined param_1,undefined *param_2,undefined param_3,byte param_4)

{
  param_2[10] = 0xf;
  param_2[0xb] = (param_4 & 1) << 2 | param_2[0xb] & 3;
  param_2[0xc] = param_3;
  *param_2 = param_1;
  *(undefined4 *)(param_2 + 2) = 10000;
  *(undefined4 *)(param_2 + 6) = 1;
  *(undefined4 *)(param_2 + 0x1a) = 3;
  *(undefined4 *)(param_2 + 0x1e) = 0;
  *(undefined4 *)(param_2 + 0x22) = 0;
  *(undefined4 *)(param_2 + 0x36) = 2;
  return;
}
/* GHIDRADEC_FUNCTION index=2046 start=0x406e286 */

int _fd_new_fv(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = _kalloc(0x19a);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aFdNewFvCouldnT);
  }
  _bzero(iVar1,0x19a);
  *(undefined4 *)(iVar1 + 4) = 1;
  *(undefined4 *)(iVar1 + 0x10) = param_1;
  iVar2 = (*(code *)&loc_406F0A2)();
  iVar3 = (*(code *)&loc_406F0A2)();
  iVar2 = _kalloc(-iVar3 & iVar2 + 0x1c47U);
  *(int *)(iVar1 + 0x14) = iVar2;
  if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aFdNewFvCouldnT_0);
  }
  *(undefined4 *)(iVar1 + 0x17a) = 0;
  *(undefined4 *)(iVar1 + 0x176) = 0;
  _disksort_init(iVar1 + 0xba);
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=2047 start=0x406e318 */

void _fd_free_fv(int param_1)

{
  int iVar1;
  int iVar2;
  
  *(undefined4 *)(_fd_volume_p + *(int *)(param_1 + 0x10) * 4) = 0;
  iVar1 = (*(code *)&loc_406F0A2)();
  iVar2 = (*(code *)&loc_406F0A2)();
  _kfree(*(undefined4 *)(param_1 + 0x14),-iVar2 & iVar1 + 0x1c47U);
  _disksort_free(param_1 + 0xba);
  _kfree(param_1,0x19a);
  return;
}
/* GHIDRADEC_FUNCTION index=2048 start=0x406e372 */

void _fd_assign_dv(int param_1,int param_2)

{
  *(int *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 0xc) = (&dword_40C3710)[param_2 * 10];
  (&dword_40C3708)[param_2 * 10] = param_1;
  *(uint *)(param_1 + 0x124) = *(uint *)(param_1 + 0x124) & 0xffffffef;
  return;
}
/* GHIDRADEC_FUNCTION index=2049 start=0x406e3b0 */

void _v2d_map(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined *puVar7;
  undefined7 *puVar8;
  undefined4 auStack_c [2];
  
  iVar5 = 0;
  puVar7 = unk_40C39C6;
  piVar4 = &unk_40C39C2;
  do {
    for (piVar1 = (int *)*piVar4; piVar1 != piVar4; piVar1 = *(int **)((int)piVar1 + 0x12a)) {
      if (piVar1[4] == *(int *)(param_1 + 0x10)) {
        piVar1 = *(int **)puVar7;
        if (piVar1 == piVar4) {
          *piVar4 = param_1;
        }
        else {
          *(int *)((int)piVar1 + 0x12a) = param_1;
        }
        *(int **)(param_1 + 0x12e) = piVar1;
        *(int **)(param_1 + 0x12a) = piVar4;
        *(int *)puVar7 = param_1;
        return;
      }
    }
    puVar7 = (undefined *)((int)puVar7 + 0x262);
    piVar4 = (int *)((int)piVar4 + 0x262);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 1);
  puVar8 = &_fd_drive;
  iVar5 = 0;
  do {
    if ((*(byte *)((int)puVar8 + 0x23) & 1) == 0) break;
    if ((*(int *)((int)puVar8 + 0xc) == 0) && (*(int *)(puVar8 + 2) == 0)) goto loc_406E49E;
    iVar5 = iVar5 + 1;
    puVar8 = puVar8 + 5;
  } while (iVar5 < 1);
  auStack_c[0] = unk_40C3714._0_4_;
  auStack_c[1] = unk_40C3714._4_4_;
  iVar5 = 0;
  puVar8 = &_fd_drive;
  iVar6 = 0;
  do {
    if ((*(byte *)((int)puVar8 + 0x23) & 1) == 0) break;
    iVar2 = _ts_greater(auStack_c,puVar8 + 3);
    if (iVar2 != 0) {
      auStack_c[0] = *(undefined4 *)(puVar8 + 3);
      auStack_c[1] = *(undefined4 *)((int)puVar8 + 0x1c);
      iVar5 = iVar6;
    }
    iVar6 = iVar6 + 1;
    puVar8 = puVar8 + 5;
  } while (iVar6 < 1);
  puVar8 = &_fd_drive + iVar5 * 5;
loc_406E49E:
  puVar3 = (undefined4 *)_kalloc(0x10);
  puVar3[2] = *(undefined4 *)((int)puVar8 + 0xc);
  puVar3[3] = param_1;
  *dword_40C3764 = puVar3;
  puVar3[1] = dword_40C3764;
  *puVar3 = &_disk_eject_q;
  piVar4 = *(int **)(*(int *)(puVar8 + 1) + 0x25a);
  dword_40C3764 = puVar3;
  if (piVar4 == (int *)(*(int *)(puVar8 + 1) + 0x256)) {
    *piVar4 = param_1;
  }
  else {
    *(int *)((int)piVar4 + 0x12a) = param_1;
  }
  *(int **)(param_1 + 0x12e) = piVar4;
  *(int *)(param_1 + 0x12a) = *(int *)(puVar8 + 1) + 0x256;
  *(int *)(*(int *)(puVar8 + 1) + 0x25a) = param_1;
  *(uint *)(param_1 + 0x124) = *(uint *)(param_1 + 0x124) | 8;
  *(int *)(param_1 + 8) = ((int)puVar8 + -0x40c36fc) * -0x33333333 >> 3;
  return;
}

