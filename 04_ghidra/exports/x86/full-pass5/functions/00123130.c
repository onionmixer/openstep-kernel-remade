/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00123130 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _revarpinput(int param_1,undefined4 *param_2)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined2 local_1c;
  undefined1 local_1a [6];
  undefined1 auStack_14 [6];
  undefined2 local_e;
  
  param_2[1] = param_2[1] + 4;
  sVar1 = *(short *)(param_2 + 2);
  *(short *)(param_2 + 2) = sVar1 + -4;
  puVar10 = param_2;
  if ((short)(sVar1 + -4) == 0) {
    uVar6 = _splimp();
    if (*(short *)((int)param_2 + 10) == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_mfree_001dba2c);
    }
    *(short *)(&DAT_001e917c + *(short *)((int)param_2 + 10) * 2) =
         *(short *)(&DAT_001e917c + *(short *)((int)param_2 + 10) * 2) + -1;
    _DAT_001e917c = _DAT_001e917c + 1;
    *(undefined2 *)((int)param_2 + 10) = 0;
    if (0x7f < (uint)param_2[1]) {
      _mclput(param_2);
    }
    puVar10 = (undefined4 *)*param_2;
    *param_2 = _mfree;
    param_2[1] = 0;
    param_2[0x1f] = 0;
    _mfree = param_2;
    _splx(uVar6);
    if (_m_want != 0) {
      _m_want = 0;
      _wakeup(&_mfree);
    }
  }
  iVar3 = puVar10[1];
  if ((((0x1b < *(ushort *)(puVar10 + 2)) && (-1 < *(char *)(param_1 + 0xc))) &&
      (uVar2 = *(ushort *)((int)puVar10 + iVar3 + 2), (ushort)(uVar2 >> 8 | uVar2 << 8) == 0x800))
     && ((_revarp != 0 &&
         (uVar2 = *(ushort *)((int)puVar10 + iVar3 + 6), (ushort)(uVar2 >> 8 | uVar2 << 8) == 3))))
  {
    puVar9 = (undefined4 *)&_arptab;
    puVar8 = &DAT_001e9c84;
    do {
      if (((puVar8[7] & 4) != 0) &&
         (iVar7 = _bcmp(puVar8,(void *)((int)puVar10 + iVar3 + 0x12),6), iVar7 == 0)) break;
      puVar8 = puVar8 + 0x14;
      puVar9 = puVar9 + 5;
    } while (puVar9 < &_master_processor);
    if (puVar9 < &_master_processor) {
      _bcopy((void *)((int)puVar10 + iVar3 + 8),local_1a,6);
      _bcopy(puVar9,(void *)((int)puVar10 + iVar3 + 0x18),4);
      iVar7 = *(int *)(param_1 + 0x18);
      if (iVar7 != 0) {
        do {
          if (*(int *)(iVar7 + 0x20) == param_1) {
            _bcopy((void *)(iVar7 + 4),(void *)((int)puVar10 + iVar3 + 0xe),4);
            break;
          }
          iVar7 = *(int *)(iVar7 + 0x24);
        } while (iVar7 != 0);
        if (iVar7 != 0) {
          _bcopy((void *)(param_1 + 0x60),(void *)((int)puVar10 + iVar3 + 8),6);
          _bcopy((void *)(param_1 + 0x60),auStack_14,6);
          local_e = 0x8035;
          *(undefined2 *)((int)puVar10 + iVar3 + 6) = 0x400;
          local_1c = 0;
          if (_revarpdebug != 0) {
            uVar4 = *(uint *)((int)puVar10 + iVar3 + 0xe);
            uVar5 = *(uint *)((int)puVar10 + iVar3 + 0x18);
            _printf(s_revarp_reply_to__X_from__X_001dba4d,
                    uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18,
                    uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18)
            ;
          }
          (**(code **)(param_1 + 0x34))(param_1,puVar10,&local_1c);
          return;
        }
      }
      if (_revarpdebug != 0) {
        _printf(s_revarp__can_t_find_ifaddr_001dba32);
      }
    }
  }
  _m_freem(puVar10);
  return;
}

