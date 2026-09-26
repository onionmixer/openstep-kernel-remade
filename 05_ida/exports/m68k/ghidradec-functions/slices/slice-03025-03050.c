/* GHIDRADEC_FUNCTION index=3025 start=0x406db14 */

void sub_406DB14(int param_1,undefined4 param_2)

{
  undefined6 *puVar1;
  
  if (_fd_polling_mode == 0) {
    puVar1 = &aWrite_0;
    if ((*(byte *)(param_1 + 0x15f) & 1) != 0) {
      puVar1 = (undefined6 *)&aRead_0;
    }
    _printf(aFdDSectorDDCmd,*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x13c),puVar1,
            *(undefined4 *)(param_1 + 0x9e),_fd_return_values,param_2);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=3026 start=0x406dc10 */

undefined4 sub_406DC10(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined auStack_e [4];
  byte bStack_a;
  
  uVar1 = *(uint *)(param_1 + 0x186);
  iVar2 = *(int *)(param_1 + 0x140);
  sub_406E234(param_1,*(undefined4 *)(param_1 + 0x13c),auStack_e);
  if (*(int *)(param_1 + 0x18c) + 1U < (uint)bStack_a + (uVar1 + iVar2 + -1) / uVar1) {
    uVar4 = uVar1 * ((*(int *)(param_1 + 0x18c) - (uint)bStack_a) + 1);
  }
  else {
    uVar4 = *(uint *)(param_1 + 0x140);
  }
  uVar3 = *(undefined4 *)(param_1 + 0x144);
  *(undefined4 *)(param_1 + 0x164) = 0;
  if ((uVar4 & uVar1 - 1) != 0) {
    _printf(aFdDPartialSect,*(undefined4 *)(param_1 + 0x10));
  }
  *(undefined4 *)(param_1 + 0x148) = *(undefined4 *)(param_1 + 0x13c);
  *(uint *)(param_1 + 0x14c) = uVar4;
  *(undefined4 *)(param_1 + 0x150) = uVar3;
  sub_406DCC0(param_1,param_1 + 0x60,*(undefined4 *)(param_1 + 0x148),
              *(undefined4 *)(param_1 + 0x14c),uVar3,*(uint *)(param_1 + 0x15c) & 1);
  return 0;
}
/* GHIDRADEC_FUNCTION index=3027 start=0x406dcc0 */

void sub_406DCC0(int param_1,undefined *param_2,undefined4 param_3,int param_4,undefined4 param_5,
                int param_6)

{
  byte bVar1;
  byte *pbVar2;
  byte bVar3;
  byte bVar4;
  
  pbVar2 = param_2 + 10;
  _bzero(pbVar2,9);
  sub_406E234(param_1,param_3,pbVar2);
  bVar1 = *pbVar2;
  *pbVar2 = bVar1 & 0x7f;
  bVar3 = (byte)((*(uint *)(param_1 + 0x182) & 1) << 6);
  *pbVar2 = bVar1 & 0x3f | bVar3;
  bVar4 = 5;
  if (param_6 != 0) {
    bVar4 = 6;
  }
  *pbVar2 = bVar4 | bVar1 & 0x20 | bVar3;
  *(uint *)(param_2 + 0xb) =
       *(uint *)(param_2 + 0xb) & 0xfbffffff | ((byte)param_2[0xd] & 1) << 0x1a;
  param_2[0xf] = *(undefined *)(param_1 + 0x18a);
  param_2[0x10] =
       param_2[0xe] +
       (char)((param_4 + -1 + *(uint *)(param_1 + 0x186)) / *(uint *)(param_1 + 0x186)) + -1;
  param_2[0x11] = *(undefined *)(param_1 + 400);
  param_2[0x12] = 0xff;
  *param_2 = *(undefined *)(param_1 + 0x17d);
  *(undefined4 *)(param_2 + 2) = 10000;
  *(undefined4 *)(param_2 + 6) = 1;
  *(undefined4 *)(param_2 + 0x1a) = 9;
  *(undefined4 *)(param_2 + 0x1e) = param_5;
  *(int *)(param_2 + 0x22) = param_4;
  *(undefined4 *)(param_2 + 0x36) = 7;
  if (param_6 == 0) {
    *(uint *)(param_2 + 0x3a) = *(uint *)(param_2 + 0x3a) & 0xfffffffd;
  }
  else {
    *(uint *)(param_2 + 0x3a) = *(uint *)(param_2 + 0x3a) | 2;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=3028 start=0x406e192 */

void sub_406E192(int param_1,undefined *param_2)

{
  word *pwVar1;
  
  pwVar1 = (word *)(param_2 + 10);
  *(undefined *)pwVar1 = 7;
  *pwVar1 = *pwVar1 & 0xff00;
  *param_2 = *(undefined *)(param_1 + 0x17d);
  *(undefined4 *)(param_2 + 2) = 10000;
  *(undefined4 *)(param_2 + 6) = 1;
  *(undefined4 *)(param_2 + 0x1a) = 2;
  *(undefined4 *)(param_2 + 0x1e) = 0;
  *(undefined4 *)(param_2 + 0x22) = 0;
  *(undefined4 *)(param_2 + 0x36) = 2;
  return;
}
/* GHIDRADEC_FUNCTION index=3029 start=0x406e234 */

void sub_406E234(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  
  uVar1 = param_2 / *(uint *)(param_1 + 0x18c);
  *(char *)(param_3 + 2) = (char)(uVar1 / *(byte *)(param_1 + 0x16c));
  *(char *)(param_3 + 3) = (char)(uVar1 % (uint)*(byte *)(param_1 + 0x16c));
  *(char *)(param_3 + 4) = (char)(param_2 % *(uint *)(param_1 + 0x18c)) + '\x01';
  return;
}
/* GHIDRADEC_FUNCTION index=3030 start=0x406ec7c */

void sub_406EC7C(int param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  
  _fd_assign_dv(param_1,(param_2 + -0x40c36fc) * -0x33333333 >> 3);
  *(undefined4 *)(param_1 + 8) = 1;
  uVar1 = *(uint *)(param_1 + 0x124);
  *(uint *)(param_1 + 0x124) = uVar1 & 0xfffffffb;
  if ((uVar1 & 8) != 0) {
    *(uint *)(param_1 + 0x124) = uVar1 & 0xfffffff3;
    _vol_panel_remove(*(undefined4 *)(param_1 + 0x138));
  }
  _fd_basic_cmd(param_3,0x80);
  *(undefined4 *)(param_2 + 0x10) = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=3031 start=0x406ecf4 */

undefined4 sub_406ECF4(int param_1,int param_2)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x168) == *(int *)(param_2 + 0x168)) &&
     ((*(uint *)(param_2 + 0x176) & 3) == (*(uint *)(param_1 + 0x176) & 3))) {
    if ((*(uint *)(param_1 + 0x176) & 2) != 0) {
      if (*(int *)(*(int *)(param_1 + 0x14) + 0x28) != *(int *)(*(int *)(param_2 + 0x14) + 0x28)) {
        return 1;
      }
      iVar1 = _strncmp(*(int *)(param_1 + 0x14) + 0xc,*(int *)(param_2 + 0x14) + 0xc,0x18);
      if (iVar1 != 0) {
        return 1;
      }
    }
    if (((*(byte *)(param_1 + 0x179) & 1) == 0) ||
       ((*(int *)(param_1 + 0x186) == *(int *)(param_2 + 0x186) &&
        (*(int *)(param_1 + 0x17a) == *(int *)(param_2 + 0x17a))))) {
      return 0;
    }
  }
  return 1;
}
/* GHIDRADEC_FUNCTION index=3032 start=0x406ee4e */

int sub_406EE4E(int param_1)

{
  int iVar1;
  undefined *puVar2;
  
  puVar2 = _fd_density_info;
  iVar1 = _fd_density_info._0_4_;
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    if (param_1 == *(int *)puVar2) break;
    puVar2 = (undefined *)((int)puVar2 + 0xc);
    iVar1 = *(int *)puVar2;
  }
  return *(int *)((int)puVar2 + 4);
}
/* GHIDRADEC_FUNCTION index=3033 start=0x406eeb4 */

void sub_406EEB4(int param_1,int param_2)

{
  *(undefined4 *)(param_2 + 0x168) = *(undefined4 *)(param_1 + 0x168);
  *(undefined4 *)(param_2 + 0x16c) = *(undefined4 *)(param_1 + 0x16c);
  *(undefined4 *)(param_2 + 0x170) = *(undefined4 *)(param_1 + 0x170);
  *(undefined4 *)(param_2 + 0x174) = *(undefined4 *)(param_1 + 0x174);
  *(undefined4 *)(param_2 + 0x178) = *(undefined4 *)(param_1 + 0x178);
  *(undefined4 *)(param_2 + 0x17c) = *(undefined4 *)(param_1 + 0x17c);
  *(undefined4 *)(param_2 + 0x180) = *(undefined4 *)(param_1 + 0x180);
  *(undefined4 *)(param_2 + 0x184) = *(undefined4 *)(param_1 + 0x184);
  *(undefined4 *)(param_2 + 0x188) = *(undefined4 *)(param_1 + 0x188);
  *(undefined4 *)(param_2 + 0x18c) = *(undefined4 *)(param_1 + 0x18c);
  *(undefined4 *)(param_2 + 400) = *(undefined4 *)(param_1 + 400);
  *(undefined2 *)(param_2 + 0x194) = *(undefined2 *)(param_1 + 0x194);
  *(undefined4 *)(param_2 + 0x196) = *(undefined4 *)(param_1 + 0x196);
  _bcopy(*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_2 + 0x14),0x1c48);
  return;
}
/* GHIDRADEC_FUNCTION index=3034 start=0x406ef08 */

void sub_406EF08(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar5 = _disk_eject_q;
  if (((undefined4 **)_disk_eject_q != &_disk_eject_q) &&
     (iVar2 = *(int *)(_disk_eject_q[3] + 8), (&DAT_40c370c)[iVar2 * 10] == 0)) {
    puVar1 = (undefined4 *)*_disk_eject_q;
    puVar3 = (undefined4 *)_disk_eject_q[1];
    puVar6 = puVar3;
    if ((undefined4 **)puVar1 != &_disk_eject_q) {
      puVar1[1] = puVar3;
      puVar6 = dword_40C3764;
    }
    dword_40C3764 = puVar6;
    *puVar3 = puVar1;
    iVar4 = (&dword_40C3708)[iVar2 * 10];
    if ((iVar4 != 0) && (*(int *)(iVar4 + 4) == 0)) {
      if (*(sword *)(iVar4 + 0x128) != 0) {
        _update(*(int *)(iVar4 + 0x10) << 3 | _fd_blk_major << 8,0xfffffff8);
      }
      _fd_basic_cmd(iVar4,2);
      if ((*(sword *)(iVar4 + 0x128) == 0) && ((*(byte *)(iVar4 + 0x127) & 4) == 0)) {
        _fd_free_fv(iVar4);
      }
    }
    (&DAT_40c370c)[iVar2 * 10] = puVar5[3];
    sub_406EFD6(puVar5[3],0);
    _kfree(puVar5,0x10);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=3035 start=0x406efd6 */

void sub_406EFD6(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if ((*(byte *)(param_1 + 0x179) & 2) == 0) {
    iVar1 = _vol_panel_disk_num(sub_406F052,*(undefined4 *)(param_1 + 0x10),0,
                                *(undefined4 *)(param_1 + 8),param_1,param_2,param_1 + 0x138);
  }
  else {
    iVar1 = _vol_panel_disk_label
                      (sub_406F052,*(int *)(param_1 + 0x14) + 0xc,0,*(undefined4 *)(param_1 + 8),
                       param_1,param_2,param_1 + 0x138);
  }
  if (iVar1 != 0) {
    _printf(aFdAlertPanelVo,iVar1);
  }
  *(uint *)(param_1 + 0x124) = *(uint *)(param_1 + 0x124) | 8;
  return;
}
/* GHIDRADEC_FUNCTION index=3036 start=0x406f052 */

void sub_406F052(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_kalloc(0x14);
  puVar1[2] = param_1;
  puVar1[3] = param_2;
  puVar1[4] = param_3;
  *dword_40C39D8 = puVar1;
  puVar1[1] = dword_40C39D8;
  *puVar1 = &_vol_abort_q;
  dword_40C39D8 = puVar1;
  return;
}
/* GHIDRADEC_FUNCTION index=3037 start=0x40705d8 */

void sub_40705D8(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (param_1 & 0xffff) >> 8;
  uVar2 = 0;
  if ((uVar1 & 0x40) != 0) {
    uVar2 = 0x80020;
  }
  if ((uVar1 & 0x20) != 0) {
    uVar2 = uVar2 | 0x80040;
  }
  if ((uVar1 & 0x10) != 0) {
    uVar2 = uVar2 | 0x100010;
  }
  if ((uVar1 & 8) != 0) {
    uVar2 = uVar2 | 0x100008;
  }
  if ((uVar1 & 4) != 0) {
    uVar2 = uVar2 | 0x20004;
  }
  if ((uVar1 & 2) != 0) {
    uVar2 = uVar2 | 0x20002;
  }
  if ((uVar1 & 1) != 0) {
    uVar2 = uVar2 | 0x40001;
  }
  _DoSpecialKey(param_1 & 0x7f,-(int)-(param_2 == 0),uVar2);
  return;
}
/* GHIDRADEC_FUNCTION index=3038 start=0x4071a12 */

undefined4 sub_4071A12(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)(dword_40B6974 + param_1 * byte_40B6966 * 4);
  if (byte_40B6966 == '\x04') {
    uVar2 = CONCAT31((uint3)(byte)((uint)puVar1[2] >> 0x18) |
                     (uint3)((word)((uint)puVar1[1] >> 0x10) & 0xff00) |
                     (uint3)((uint)*puVar1 >> 8) & 0xff0000,*(undefined *)(puVar1 + 3));
  }
  else {
    if (byte_40B6966 < '\x05') {
      if (byte_40B6966 == '\x01') {
        return *puVar1;
      }
    }
    else if (byte_40B6966 == '\b') {
      return CONCAT31((uint3)(byte)((word)*(undefined2 *)(puVar1 + 4) >> 8) |
                      (uint3)((word)((uint)puVar1[2] >> 0x10) & 0xff00) |
                      (uint3)((uint)*puVar1 >> 8) & 0xff0000,*(undefined *)(puVar1 + 6));
    }
    uVar2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=3039 start=0x4072534 */

undefined4 sub_4072534(void)

{
  int unaff_A6;
  
  return *(undefined4 *)(unaff_A6 + -0xc);
}
/* GHIDRADEC_FUNCTION index=3040 start=0x4073b56 */

int sub_4073B56(sword param_1,int param_2,sword *param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 0;
  do {
    while (iVar1 = _np_ioctl_common((int)param_1,param_2,param_3,param_4,param_5), iVar1 == 0) {
      if ((((param_2 != -0x3fed8fff) || (*param_3 != 3)) ||
          ((*(byte *)((int)param_3 + 5) & 0x40) == 0)) || (iVar2 = iVar2 + 1, 2 < iVar2)) {
        return 0;
      }
    }
    if (iVar1 != 5) {
      return iVar1;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  _printf(aNp0IoctlErrorF);
  return 5;
}
/* GHIDRADEC_FUNCTION index=3041 start=0x4075ac0 */

void sub_4075AC0(undefined4 param_1)

{
  _od_done(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=3042 start=0x407aa5c */

void sub_407AA5C(int param_1)

{
  undefined4 uVar1;
  undefined auStack_30 [44];
  
  uVar1 = _pmap_kernel(0x40000,10,0,0);
  _dma_list(param_1,param_1 + 0xf8,auStack_30,0x20,uVar1);
  _dma_start(param_1,param_1 + 0xf8,0x40000);
  _delay(10);
  _dma_abort(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=3043 start=0x407adbe */

/* WARNING: Removing unreachable block (ram,0x0407ae4c) */

void sub_407ADBE(int param_1,byte param_2)

{
  undefined uVar1;
  
  *(undefined *)(param_1 + 0x20) = 2;
  _delay(10);
  *(undefined *)(param_1 + 0x20) = 0;
  _delay(10);
  *(byte *)(param_1 + 8) = param_2 & 7 | 0x50;
  uVar1 = 5;
  if (_dma_chip == 0x139) {
    uVar1 = 4;
  }
  *(undefined *)(param_1 + 9) = uVar1;
  *(undefined *)(param_1 + 5) = 0x99;
  *(undefined *)(param_1 + 7) = 0;
  *(undefined *)(param_1 + 6) = 5;
  _delay(10);
  *(undefined *)(param_1 + 0x20) = 0x20;
  return;
}
/* GHIDRADEC_FUNCTION index=3044 start=0x407b1ba */

void sub_407B1BA(int *param_1)

{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  undefined uVar4;
  byte bVar5;
  undefined uVar6;
  int iVar7;
  char cVar8;
  int iVar9;
  int iVar10;
  undefined *puVar11;
  
  iVar2 = *param_1;
  puVar3 = *(undefined **)(*(int *)(iVar2 + 0x10) + 8);
  do {
    *(undefined *)(iVar2 + 0x5b) = 0;
    iVar7 = *(int *)((int)param_1 + 0x226);
    *(undefined *)(iVar2 + 0x5a) = 2;
    if (*(char *)((int)param_1 + 0x21e) == '\x06') {
      _delay(0x14);
      if ((*(byte *)(iVar7 + 0x24) & 8) != 0) {
        iVar9 = 0;
        if (_dma_chip == 0x139) goto loc_407B20E;
        while (iVar9 < 1) {
loc_407B20E:
          while( true ) {
            puVar3[0x20] = 0x3c;
            _delay(5);
            puVar3[0x20] = 0x38;
            _delay(5);
            iVar9 = iVar9 + 1;
            if (_dma_chip != 0x139) break;
            if (7 < iVar9) goto loc_407B240;
          }
        }
loc_407B240:
        _delay(0x14);
      }
      puVar3[0x20] = 0x20;
    }
    *(undefined *)((int)param_1 + 0x223) = puVar3[4];
    *(undefined *)(param_1 + 0x89) = puVar3[6];
    *(undefined *)((int)param_1 + 0x225) = puVar3[5];
    if ((((*(byte *)((int)param_1 + 0x223) & 0x40) == 0) &&
        ((*(byte *)((int)param_1 + 0x225) & 0x40) == 0)) ||
       ((dword_40B4FC2 == 6 && (*(char *)((int)param_1 + 0x21e) == '\t')))) {
      dword_40B4FC2 = (uint)*(byte *)((int)param_1 + 0x21e);
      switch(*(undefined *)((int)param_1 + 0x21e)) {
      case :
        sub_407ADBE(puVar3,*(undefined *)(iVar2 + 0x58));
        sub_407BCB6(iVar2,0,aStrayInterrupt);
        return;
      case :
      case :
loc_407b35e:
        if ((*(byte *)((int)param_1 + 0x225) & 3) == 0) {
          if ((*(byte *)((int)param_1 + 0x225) & 4) == 0) {
            if (*(char *)((int)param_1 + 0x21e) == '\x04') {
              *(undefined *)((int)param_1 + 0x21e) = 0;
            }
            else {
              puVar11 = aBadReselection;
loc_407B704:
              sub_407BCB6(iVar2,0,puVar11);
            }
          }
          else {
            uVar1 = *(byte *)(iVar2 + 0x58) & 0x3f;
            uVar1 = (-2 << uVar1 | 0xfffffffeU >> 0x20 - uVar1) & (uint)(byte)puVar3[2];
            if (uVar1 != 0) {
              cVar8 = '\0';
              for (; (uVar1 & 1) == 0; uVar1 = (int)uVar1 >> 1) {
                cVar8 = cVar8 + '\x01';
              }
              goto loc_407B3AA;
            }
loc_407B44C:
            *(undefined *)((int)param_1 + 0x236) = 8;
            if ((*(byte *)((int)param_1 + 0x225) & 8) == 0) {
              puVar11 = aBadReselect;
              goto loc_407B704;
            }
            sub_407BC86(param_1,6,0);
            *(undefined *)((int)param_1 + 0x21e) = 7;
            puVar3[3] = 0x12;
          }
        }
        else {
          puVar3[3] = 0x27;
          *(undefined *)((int)param_1 + 0x21e) = 0;
        }
        break;
      case :
        if ((*(byte *)((int)param_1 + 0x225) & 0x20) == 0) {
          if (*(byte *)((int)param_1 + 0x225) != 0x18) {
            iVar7 = 0;
            goto loc_407b35e;
          }
          bVar5 = *(byte *)(param_1 + 0x89) & 7;
          if (((*(byte *)(param_1 + 0x89) & 7) != 0) && ((4 < bVar5 || (bVar5 < 2)))) {
            puVar11 = aSelectSeq;
            goto loc_407B704;
          }
          *(undefined *)((int)param_1 + 0x21e) = 3;
          *(undefined *)(iVar7 + 0x4f) = 1;
        }
        else {
          puVar3[3] = 1;
          *(undefined *)((int)param_1 + 0x21e) = 0;
          *(undefined *)(iVar7 + 0x4f) = 2;
        }
        break;
      case :
        puVar3[3] = 0;
        break;
      case :
        if ((*(byte *)((int)param_1 + 0x225) & 0x20) == 0) {
          if ((*(byte *)((int)param_1 + 0x225) & 8) == 0) {
            if ((puVar3[7] & 0x1f) == 1) {
              *(undefined *)(iVar7 + 0x4e) = puVar3[2];
              if ((*(byte *)((int)param_1 + 0x223) & 0x20) != 0) {
                iVar7 = *(int *)((int)param_1 + 0x216);
                *(int *)((int)param_1 + 0x216) = iVar7 + 1;
                if (5 < iVar7 + 1) {
                  puVar11 = aScsiBusParityO_1;
                  goto loc_407B704;
                }
                sub_407BC86(param_1,5,3);
              }
loc_407B688:
              *(undefined *)((int)param_1 + 0x21e) = 3;
              break;
            }
            puVar11 = aFifoLevel2;
          }
          else if ((puVar3[7] & 0x1f) == 2) {
            *(undefined *)(iVar7 + 0x4e) = puVar3[2];
            *(undefined *)((int)param_1 + 0x236) = puVar3[2];
            if ((*(byte *)((int)param_1 + 0x223) & 0x20) == 0) {
              *(undefined *)((int)param_1 + 0x21e) = 3;
              sub_407BB30(param_1);
              break;
            }
            iVar9 = *(int *)((int)param_1 + 0x216);
            *(int *)((int)param_1 + 0x216) = iVar9 + 1;
            if (iVar9 + 1 < 6) goto loc_407B716;
            puVar11 = aScsiBusParityO_0;
          }
          else {
            puVar11 = aFifoLevel;
          }
          goto loc_407B704;
        }
        break;
      case :
        iVar9 = *(int *)((int)param_1 + 0x22e);
        uVar6 = puVar3[1];
        uVar4 = *puVar3;
        *(uint *)((int)param_1 + 0x22e) = (uint)CONCAT11(uVar6,uVar4);
        if ((*(byte *)(iVar7 + 0x24) & 8) == 0) {
          *(uint *)((int)param_1 + 0x22e) = ((byte)puVar3[7] & 0x1f) + (uint)CONCAT11(uVar6,uVar4);
        }
        iVar9 = iVar9 - *(int *)((int)param_1 + 0x22e);
        *(int *)(iVar7 + 0x4a) = iVar9 + *(int *)(iVar7 + 0x4a);
        *(int *)((int)param_1 + 0x22a) = iVar9 + *(int *)((int)param_1 + 0x22a);
        *(undefined *)((int)param_1 + 0x21e) = 3;
        _dma_cleanup(param_1 + 1,*(undefined4 *)((int)param_1 + 0x22e));
        _busdone(*(undefined4 *)(iVar2 + 0x10));
        if (((param_1[0xc] & 0x4000U) != 0) || ((*(byte *)((int)param_1 + 0x223) & 0x20) != 0)) {
          if ((param_1[0xc] & 0x4000U) != 0) {
            *(undefined4 *)((int)param_1 + 0x216) = 6;
          }
          param_1[0xc] = param_1[0xc] & 0xffffbfff;
          iVar7 = *(int *)((int)param_1 + 0x216);
          *(int *)((int)param_1 + 0x216) = iVar7 + 1;
          if (5 < iVar7 + 1) {
            puVar11 = aScsiBusParityE;
            if ((param_1[0xc] & 0x4000U) != 0) {
              puVar11 = aDmaError_0;
            }
            goto loc_407B704;
          }
          sub_407BC86(param_1,5,3);
        }
        break;
      case :
        if (*(char *)((int)param_1 + 0x236) == '\0') {
          *(undefined *)((int)param_1 + 0x21e) = 0;
          *(undefined4 *)(iVar7 + 0x46) = *(undefined4 *)((int)param_1 + 0x22e);
          *(undefined *)(iVar7 + 0x4f) = 4;
        }
        else if (*(char *)((int)param_1 + 0x236) == '\x04') {
          *(undefined *)((int)param_1 + 0x21e) = 0;
          *(int *)(iVar7 + 0x20) = _hz * *(int *)(iVar7 + 0x42);
          *(byte *)(iVar7 + 0x24) = *(byte *)(iVar7 + 0x24) | 0x80;
          *(undefined *)(iVar7 + 0x4f) = 3;
        }
        else {
          *(undefined *)((int)param_1 + 0x21e) = 3;
          puVar3[3] = 0;
          puVar3[3] = 1;
        }
        break;
      case :
        puVar3[3] = 0;
        *(undefined *)((int)param_1 + 0x21e) = *(undefined *)(param_1 + 0x88);
        break;
      case :
        iVar9 = *(int *)((int)param_1 + 0x232);
        uVar6 = puVar3[1];
        uVar4 = *puVar3;
        *(uint *)((int)param_1 + 0x232) = (uint)CONCAT11(uVar6,uVar4);
        iVar9 = iVar9 - (uint)CONCAT11(uVar6,uVar4);
        iVar10 = iVar9 + *(int *)(iVar7 + 0x4a);
        *(int *)(iVar7 + 0x4a) = iVar10;
        if (((*(byte *)(iVar7 + 0x24) & 8) == 0) && (iVar9 != 0)) {
          *(int *)(iVar7 + 0x4a) = iVar10 + -0xf;
        }
        goto loc_407B688;
      case :
        if ((*(byte *)((int)param_1 + 0x225) & 0x20) == 0) {
          if ((puVar3[7] & 0x1f) != 1) {
            puVar11 = aMsginFifoError;
            goto loc_407B704;
          }
          *(undefined *)((int)param_1 + 0x236) = puVar3[2];
          if ((*(byte *)((int)param_1 + 0x223) & 0x20) == 0) {
            sub_407BB30(param_1);
            break;
          }
          iVar9 = *(int *)((int)param_1 + 0x216);
          *(int *)((int)param_1 + 0x216) = iVar9 + 1;
          if (5 < iVar9 + 1) {
            puVar11 = aScsiBusParityO_2;
            goto loc_407B704;
          }
loc_407B716:
          *(undefined *)((int)param_1 + 0x236) = 8;
          sub_407BC86(param_1,9,3);
          *(undefined *)((int)param_1 + 0x21e) = 7;
          puVar3[3] = 0x12;
          *(int *)(iVar2 + 0x5c) = _hz * *(int *)(iVar7 + 0x42);
          *(undefined *)(iVar2 + 0x5b) = 1;
        }
        break;
      case :
        if ((*(byte *)((int)param_1 + 0x225) & 0x20) == 0) {
          if ((puVar3[7] & 0x1f) != 1) {
            puVar11 = aMsginFifoError;
            goto loc_407B704;
          }
          cVar8 = *(char *)((int)param_1 + 0x222);
loc_407B3AA:
          bVar5 = puVar3[2];
          *(byte *)((int)param_1 + 0x236) = bVar5;
          if ((*(byte *)((int)param_1 + 0x223) & 0x20) != 0) {
            *(char *)((int)param_1 + 0x222) = cVar8;
            iVar9 = *(int *)((int)param_1 + 0x216);
            *(int *)((int)param_1 + 0x216) = iVar9 + 1;
            if (iVar9 + 1 < 6) goto loc_407B716;
            puVar11 = aScsiBusParityO;
            goto loc_407B704;
          }
          if ((-1 < (char)bVar5) || (iVar7 = _scsi_reselect(iVar2,cVar8,bVar5 & 7), iVar7 == 0))
          goto loc_407B44C;
          *(byte *)(iVar7 + 0x24) = *(byte *)(iVar7 + 0x24) & 0x7f;
          *(int *)((int)param_1 + 0x226) = iVar7;
          *(undefined4 *)((int)param_1 + 0x22a) = *(undefined4 *)(iVar7 + 0x32);
          *(undefined4 *)((int)param_1 + 0x22e) = *(undefined4 *)(iVar7 + 0x36);
          *(int *)((int)param_1 + 0x232) = *(int *)(iVar7 + 0x3a) + 1;
          *(undefined *)((int)param_1 + 0x21e) = 7;
          puVar3[3] = 0x12;
          *(int *)(iVar2 + 0x5c) = _hz * *(int *)(iVar7 + 0x42);
          *(undefined *)(iVar2 + 0x5b) = 1;
        }
        break;
      :
                    /* WARNING: Subroutine does not return */
        _panic(aScintrBadState);
      }
      if ((*(char *)((int)param_1 + 0x21e) != '\0') &&
         ((*(byte *)((int)param_1 + 0x225) & 0x20) != 0)) {
        *(undefined *)((int)param_1 + 0x21e) = 0;
        if (*(int *)((int)param_1 + 0x226) != 0) {
          *(undefined *)(*(int *)((int)param_1 + 0x226) + 0x4f) = 10;
        }
      }
      if (*(char *)((int)param_1 + 0x21e) == '\x03') {
        sub_407B89A(param_1);
      }
    }
    else {
      sub_407ADBE(puVar3,*(undefined *)(iVar2 + 0x58));
      sub_407BCB6(iVar2,0,aSoftwareError);
    }
    if ((*(char *)((int)param_1 + 0x21e) == '\0') &&
       (puVar3[3] = 0x44, *(char *)((int)param_1 + 0x21e) == '\0')) {
      if (*(int *)((int)param_1 + 0x226) != 0) {
        *(undefined4 *)((int)param_1 + 0x226) = 0;
        _scsi_cintr(iVar2);
      }
      if (*(char *)((int)param_1 + 0x21e) == '\0') {
        *(undefined *)((int)param_1 + 0x21e) = 1;
      }
    }
    if ((*_intrstat & 0x1000) == 0) {
      if ((*(char *)((int)param_1 + 0x21e) == '\x01') && (*(char *)(*param_1 + 0x60) == '\0')) {
        _sfa_relinquish(param_1[0x8e],param_1 + 0x8f,1);
      }
      return;
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=3045 start=0x407b89a */

void sub_407B89A(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  undefined *puVar6;
  undefined4 uVar7;
  
  iVar1 = *param_1;
  iVar2 = *(int *)(*(int *)(iVar1 + 0x10) + 8);
  iVar3 = *(int *)((int)param_1 + 0x226);
  if (((*(byte *)((int)param_1 + 0x223) & 7) != 6) && (*(char *)((int)param_1 + 0x21f) == '\x02')) {
    *(undefined *)((int)param_1 + 0x21f) = 0;
  }
  *(undefined *)(iVar2 + 3) = 1;
  bVar4 = *(byte *)((int)param_1 + 0x223) & 7;
  if (iVar3 != 0) {
    if (bVar4 < 8) goto loc_407B8FA;
loc_407B926:
    iVar5 = *(int *)((int)param_1 + 0x21a);
    puVar6 = (undefined *)(iVar3 + 0x26);
    while (0 < iVar5) {
      *(undefined *)(iVar2 + 2) = *puVar6;
      iVar5 = iVar5 + -1;
      puVar6 = puVar6 + 1;
    }
    for (iVar5 = 0xe - *(int *)((int)param_1 + 0x21a); 0 < iVar5; iVar5 = iVar5 + -1) {
      *(undefined *)(iVar2 + 2) = 0;
    }
    *(undefined *)(iVar2 + 3) = 0;
    *(undefined *)(iVar2 + 3) = 0x10;
    *(undefined *)((int)param_1 + 0x21e) = 3;
    goto loc_407B9EA;
  }
  if (bVar4 != 7) {
    puVar6 = aNoConnection;
    goto loc_407B97C;
  }
loc_407B8FA:
  switch(bVar4) {
  case :
    if ((*(byte *)(iVar3 + 0x24) & 8) == 0) {
      uVar7 = 0;
loc_407B98E:
      sub_407BA0A(param_1,uVar7);
      return;
    }
    break;
  case :
    if ((*(byte *)(iVar3 + 0x24) & 8) != 0) {
      uVar7 = 0x40000;
      goto loc_407B98E;
    }
    break;
  :
    goto loc_407B926;
  case :
    *(undefined *)((int)param_1 + 0x21e) = 5;
    *(undefined *)(iVar2 + 3) = 0x11;
    goto loc_407B9EA;
  case :
    if (*(char *)((int)param_1 + 0x21f) == '\0') {
      *(undefined *)(iVar2 + 2) = 8;
      *(undefined *)(param_1 + 0x88) = 3;
    }
    else {
      *(undefined *)(iVar2 + 2) = *(undefined *)((int)param_1 + 0x221);
      *(undefined *)((int)param_1 + 0x21f) = 2;
    }
    *(undefined *)((int)param_1 + 0x21e) = 8;
    goto loc_407B9E0;
  case :
    if (iVar3 == 0) {
      *(undefined *)((int)param_1 + 0x21e) = 0xb;
    }
    else {
      *(undefined *)((int)param_1 + 0x21e) = 10;
    }
loc_407B9E0:
    *(undefined *)(iVar2 + 3) = 0;
    *(undefined *)(iVar2 + 3) = 0x10;
loc_407B9EA:
    *(int *)(iVar1 + 0x5c) = _hz * *(int *)(iVar3 + 0x42);
    *(undefined *)(iVar1 + 0x5b) = 1;
    return;
  }
  puVar6 = aBadIODirection;
loc_407B97C:
  sub_407BCB6(iVar1,0,puVar6);
  return;
}
/* GHIDRADEC_FUNCTION index=3046 start=0x407ba0a */

void sub_407BA0A(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  
  iVar1 = *param_1;
  puVar4 = *(undefined **)(*(int *)(iVar1 + 0x10) + 8);
  iVar2 = *(int *)((int)param_1 + 0x226);
  if (*(int *)((int)param_1 + 0x22e) == 0) {
    if (*(int *)((int)param_1 + 0x232) != 0) {
      *(undefined *)((int)param_1 + 0x21e) = 9;
      if (param_2 == 0) {
        puVar4[2] = 0;
      }
      *puVar4 = (char)*(undefined4 *)((int)param_1 + 0x232);
      puVar4[1] = (char)((uint)*(undefined4 *)((int)param_1 + 0x232) >> 8);
      puVar4[3] = 0;
      puVar4[3] = 0x98;
      return;
    }
    puVar4 = aTransferLenExc;
  }
  else {
    *(undefined *)((int)param_1 + 0x21e) = 6;
    if (*(int *)((int)param_1 + 0x22e) < 0x10001) {
      _dma_list(param_1 + 1,(int)param_1 + 0xfe,*(undefined4 *)((int)param_1 + 0x22a),
                *(int *)((int)param_1 + 0x22e),*(undefined4 *)(iVar2 + 0x3e),param_2,10,0,0);
      _dma_start(param_1 + 1,(int)param_1 + 0xfe,param_2);
      *puVar4 = (char)*(undefined4 *)((int)param_1 + 0x22e);
      puVar4[1] = (char)((uint)*(undefined4 *)((int)param_1 + 0x22e) >> 8);
      uVar3 = 0x30;
      if (param_2 == 0x40000) {
        uVar3 = 0x38;
      }
      *(undefined4 *)(*(int *)(iVar1 + 0x10) + 0x14) = uVar3;
      _busgo(*(undefined4 *)(iVar2 + 0x10));
      return;
    }
    puVar4 = aDmaLen64k;
  }
  sub_407BCB6(iVar1,0,puVar4);
  return;
}
/* GHIDRADEC_FUNCTION index=3047 start=0x407bb30 */

void sub_407BB30(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = *param_1;
  iVar2 = *(int *)(*(int *)(iVar1 + 0x10) + 8);
  iVar3 = *(int *)((int)param_1 + 0x226);
  if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aScmsginNoCurre);
  }
  if (*(char *)((int)param_1 + 0x21f) == '\x01') {
    *(undefined *)((int)param_1 + 0x236) = 8;
    goto loc_407BC40;
  }
  switch(*(undefined *)((int)param_1 + 0x236)) {
  case :
    break;
  :
    if (*(char *)((int)param_1 + 0x236) < '\0') break;
    goto loc_407BC2C;
  case :
    *(undefined4 *)(iVar3 + 0x32) = *(undefined4 *)((int)param_1 + 0x22a);
    uVar4 = *(undefined4 *)((int)param_1 + 0x22e);
    *(undefined4 *)(iVar3 + 0x46) = uVar4;
    *(undefined4 *)(iVar3 + 0x36) = uVar4;
    *(int *)(iVar3 + 0x3a) = *(int *)((int)param_1 + 0x232) + -1;
    break;
  case :
    *(undefined4 *)((int)param_1 + 0x22a) = *(undefined4 *)(iVar3 + 0x32);
    *(undefined4 *)((int)param_1 + 0x22e) = *(undefined4 *)(iVar3 + 0x36);
    *(int *)((int)param_1 + 0x232) = *(int *)(iVar3 + 0x3a) + 1;
    break;
  case :
    if (((*(byte *)(iVar3 + 0x24) & 0x10) != 0) && (*(char *)(param_1 + 0x3f) != '\0')) break;
    *(undefined *)((int)param_1 + 0x236) = 8;
loc_407BC2C:
    sub_407BC86(param_1,7,3);
    break;
  case :
    _printf(aScMessageRejec);
    break;
  case :
  case :
    sub_407BCB6(iVar1,0,aLinkedCommand);
  }
loc_407BC40:
  if ((*(byte *)((int)param_1 + 0x225) & 8) == 0) {
    sub_407BCB6(iVar1,0,aScmsginNoFuncc);
  }
  else {
    *(undefined *)((int)param_1 + 0x21e) = 7;
    *(undefined *)(iVar2 + 3) = 0x12;
    *(int *)(iVar1 + 0x5c) = _hz * *(int *)(iVar3 + 0x42);
    *(undefined *)(iVar1 + 0x5b) = 1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=3048 start=0x407bc86 */

void sub_407BC86(int *param_1,undefined param_2,undefined param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(*param_1 + 0x10) + 8);
  *(undefined *)((int)param_1 + 0x221) = param_2;
  *(undefined *)(param_1 + 0x88) = param_3;
  *(undefined *)((int)param_1 + 0x21f) = 1;
  *(undefined *)(iVar1 + 3) = 0x1a;
  return;
}
/* GHIDRADEC_FUNCTION index=3049 start=0x407bcb6 */

void sub_407BCB6(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = *(sword *)(*(int *)(param_1 + 0x10) + 4) * 0x250;
  piVar4 = (int *)(_sc_s5c + iVar3);
  iVar1 = *(int *)(*(int *)(*piVar4 + 0x10) + 8);
  *(undefined *)(iVar1 + 0x20) = 0x20;
  _dma_abort(iVar3 + 0x40c5944);
  *(uint *)(_sc_s5c + iVar3 + 0x30) = *(uint *)(_sc_s5c + iVar3 + 0x30) & 0xffffbfff;
  if (_sc_s5c[iVar3 + 0x21e] == '\x06') {
    _busdone(*(undefined4 *)(*piVar4 + 0x10));
  }
  cVar2 = _sc_s5c[iVar3 + 0x21e];
  if (cVar2 != '\0') {
    *(undefined *)(iVar1 + 3) = 3;
    _delay(500000);
    _sc_s5c[iVar3 + 0x21e] = 0;
  }
  _sfa_abort(*(undefined4 *)(_sc_s5c + iVar3 + 0x238),iVar3 + 0x40c5b7c,1);
  iVar1 = *(int *)(_sc_s5c + iVar3 + 0x226);
  if (iVar1 != 0) {
    if (param_2 == 0) {
      *(undefined *)(iVar1 + 0x4f) = 7;
    }
    else {
      *(undefined *)(iVar1 + 0x4f) = 5;
    }
    *(undefined4 *)(_sc_s5c + iVar3 + 0x226) = 0;
    if (cVar2 != '\0') {
      _scsi_cintr(param_1);
    }
  }
  *(undefined *)(*piVar4 + 0x60) = 0;
  _scsi_restart(*piVar4);
  return;
}

