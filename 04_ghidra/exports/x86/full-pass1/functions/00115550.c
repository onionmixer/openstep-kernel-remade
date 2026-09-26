/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00115550 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint _soreceive(int param_1,undefined4 *param_2,int param_3,uint param_4,int *param_5)

{
  short sVar1;
  code *pcVar2;
  ushort uVar3;
  short sVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  int local_1c;
  undefined4 local_18;
  int local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = 0;
  iVar9 = *(int *)(param_1 + 0xc);
  if (param_5 != (int *)0x0) {
    *param_5 = 0;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  if ((param_4 & 1) != 0) {
    iVar5 = _m_get(1,1);
    local_8 = (**(code **)(iVar9 + 0x1c))(param_1,0xd,iVar5,param_4 & 2,0);
    if (local_8 == 0) {
      do {
        iVar9 = *(int *)(param_3 + 0x14);
        if ((int)*(short *)(iVar5 + 8) < *(int *)(param_3 + 0x14)) {
          iVar9 = (int)*(short *)(iVar5 + 8);
        }
        local_8 = _uiomove(iVar5 + *(int *)(iVar5 + 4),iVar9,0,param_3);
        iVar5 = _m_free(iVar5);
      } while (((*(int *)(param_3 + 0x14) != 0) && (local_8 == 0)) && (iVar5 != 0));
    }
    if (iVar5 == 0) {
      return local_8;
    }
    _m_freem(iVar5);
    return local_8;
  }
  do {
    uVar3 = *(ushort *)(param_1 + 0x38);
    if ((uVar3 & 1) != 0) {
      do {
        *(ushort *)(param_1 + 0x38) = uVar3 | 2;
        _sleep(param_1 + 0x38);
        uVar3 = *(ushort *)(param_1 + 0x38);
      } while ((uVar3 & 1) != 0);
    }
    *(byte *)(param_1 + 0x38) = *(byte *)(param_1 + 0x38) | 1;
    local_c = _splnet();
    if (*(short *)(param_1 + 0x24) != 0) {
      _active_u[0x6a] = _active_u[0x6a] + 1;
      puVar8 = *(undefined4 **)(param_1 + 0x30);
      if (puVar8 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
        _panic(s_receive_1_001db310);
      }
      local_18 = puVar8[0x1f];
      if ((*(byte *)(iVar9 + 10) & 2) == 0) {
LAB_0011585e:
        if ((puVar8 != (undefined4 *)0x0) && (*(short *)((int)puVar8 + 10) == 0xc)) {
          if ((*(byte *)(iVar9 + 10) & 0x10) == 0) {
                    /* WARNING: Subroutine does not return */
            _panic(s_receive_2_001db32b);
          }
          if ((param_4 & 2) == 0) {
            *(short *)(param_1 + 0x24) = *(short *)(param_1 + 0x24) - *(short *)(puVar8 + 2);
            sVar4 = *(short *)(param_1 + 0x28);
            *(short *)(param_1 + 0x28) = sVar4 + -0x80;
            if (0x7c < (uint)puVar8[1]) {
              *(short *)(param_1 + 0x28) = sVar4 + -0x480;
            }
            if (param_5 == (int *)0x0) {
              uVar6 = _splimp();
              if (*(short *)((int)puVar8 + 10) == 0) {
                    /* WARNING: Subroutine does not return */
                _panic(s_mfree_001db335);
              }
              *(short *)(&DAT_001e917c + *(short *)((int)puVar8 + 10) * 2) =
                   *(short *)(&DAT_001e917c + *(short *)((int)puVar8 + 10) * 2) + -1;
              _DAT_001e917c = _DAT_001e917c + 1;
              *(undefined2 *)((int)puVar8 + 10) = 0;
              if (0x7f < (uint)puVar8[1]) {
                _mclput(puVar8);
              }
              *(undefined4 *)(param_1 + 0x30) = *puVar8;
              *puVar8 = _mfree;
              puVar8[1] = 0;
              puVar8[0x1f] = 0;
              _mfree = puVar8;
              _splx(uVar6);
              if (_m_want != 0) {
                _m_want = 0;
                _wakeup(&_mfree);
              }
            }
            else {
              *param_5 = (int)puVar8;
              *(undefined4 *)(param_1 + 0x30) = *puVar8;
              *puVar8 = 0;
            }
            puVar8 = *(undefined4 **)(param_1 + 0x30);
            if (puVar8 != (undefined4 *)0x0) {
              puVar8[0x1f] = local_18;
            }
          }
          else {
            if (param_5 != (int *)0x0) {
              iVar5 = _m_copy(puVar8,0,(int)*(short *)(puVar8 + 2));
              *param_5 = iVar5;
            }
            puVar8 = (undefined4 *)*puVar8;
          }
        }
      }
      else {
        if (*(short *)((int)puVar8 + 10) != 8) {
                    /* WARNING: Subroutine does not return */
          _panic(s_receive_1a_001db31a);
        }
        if ((param_4 & 2) != 0) {
          if (param_2 != (undefined4 *)0x0) {
            uVar6 = _m_copy(puVar8,0,(int)*(short *)(puVar8 + 2));
            *param_2 = uVar6;
          }
          puVar8 = (undefined4 *)*puVar8;
          goto LAB_0011585e;
        }
        *(short *)(param_1 + 0x24) = *(short *)(param_1 + 0x24) - *(short *)(puVar8 + 2);
        sVar4 = *(short *)(param_1 + 0x28);
        *(short *)(param_1 + 0x28) = sVar4 + -0x80;
        if (0x7c < (uint)puVar8[1]) {
          *(short *)(param_1 + 0x28) = sVar4 + -0x480;
        }
        if (param_2 == (undefined4 *)0x0) {
          uVar6 = _splimp();
          if (*(short *)((int)puVar8 + 10) == 0) {
                    /* WARNING: Subroutine does not return */
            _panic(s_mfree_001db325);
          }
          *(short *)(&DAT_001e917c + *(short *)((int)puVar8 + 10) * 2) =
               *(short *)(&DAT_001e917c + *(short *)((int)puVar8 + 10) * 2) + -1;
          _DAT_001e917c = _DAT_001e917c + 1;
          *(undefined2 *)((int)puVar8 + 10) = 0;
          if (0x7f < (uint)puVar8[1]) {
            _mclput(puVar8);
          }
          *(undefined4 *)(param_1 + 0x30) = *puVar8;
          *puVar8 = _mfree;
          puVar8[1] = 0;
          puVar8[0x1f] = 0;
          _mfree = puVar8;
          _splx(uVar6);
          if (_m_want != 0) {
            _m_want = 0;
            _wakeup(&_mfree);
          }
          puVar8 = *(undefined4 **)(param_1 + 0x30);
        }
        else {
          *param_2 = puVar8;
          puVar8 = (undefined4 *)*puVar8;
          *(undefined4 *)*param_2 = 0;
          *(undefined4 **)(param_1 + 0x30) = puVar8;
        }
        if (puVar8 != (undefined4 *)0x0) {
          puVar8[0x1f] = local_18;
          goto LAB_0011585e;
        }
      }
      local_1c = 0;
      local_10 = 0;
      goto LAB_00115b43;
    }
    if (*(ushort *)(param_1 + 0x56) != 0) {
      local_8 = (uint)*(ushort *)(param_1 + 0x56);
      *(undefined2 *)(param_1 + 0x56) = 0;
      goto LAB_00115bd0;
    }
    if ((*(ushort *)(param_1 + 6) & 0x20) != 0) goto LAB_00115bd0;
    if (((*(ushort *)(param_1 + 6) & 2) == 0) &&
       ((*(byte *)(*(int *)(param_1 + 0xc) + 10) & 4) != 0)) {
      local_8 = 0x39;
      goto LAB_00115bd0;
    }
    if (*(int *)(param_3 + 0x14) == 0) goto LAB_00115bd0;
    if ((*(byte *)(param_1 + 7) & 1) != 0) break;
    uVar3 = *(ushort *)(param_1 + 0x38);
    *(ushort *)(param_1 + 0x38) = uVar3 & 0xfffe;
    if ((uVar3 & 2) != 0) {
      *(ushort *)(param_1 + 0x38) = uVar3 & 0xfffc;
      _wakeup(param_1 + 0x38);
    }
    _sbwait(param_1 + 0x24);
    _splx(local_c);
  } while( true );
  local_8 = 0x23;
  if (((*(byte *)(*_active_u + 0x16) & 2) != 0) && ((*(byte *)(param_3 + 0x11) & 0x20) != 0)) {
    local_8 = 0xb;
  }
  goto LAB_00115bd0;
  while (sVar4 = *(short *)(param_1 + 0x58) - sVar4, *(short *)(param_1 + 0x58) = sVar4, sVar4 != 0)
  {
LAB_00115b43:
    do {
      if (((puVar8 == (undefined4 *)0x0) || (*(int *)(param_3 + 0x14) < 1)) || (local_8 != 0))
      goto LAB_00115b5a;
      if (1 < (ushort)(*(short *)((int)puVar8 + 10) - 1U)) {
                    /* WARNING: Subroutine does not return */
        _panic(s_receive_3_001db33b);
      }
      iVar5 = *(int *)(param_3 + 0x14);
      *(byte *)(param_1 + 6) = *(byte *)(param_1 + 6) & 0xbf;
      if ((*(ushort *)(param_1 + 0x58) != 0) &&
         (iVar7 = (uint)*(ushort *)(param_1 + 0x58) - local_10, iVar7 < iVar5)) {
        iVar5 = iVar7;
      }
      if (*(short *)(puVar8 + 2) - local_1c < iVar5) {
        iVar5 = *(short *)(puVar8 + 2) - local_1c;
      }
      _splx(local_c);
      local_8 = _uiomove((int)puVar8 + local_1c + puVar8[1],iVar5,0,param_3);
      local_c = _splnet();
      sVar4 = (short)iVar5;
      if (iVar5 == *(short *)(puVar8 + 2) - local_1c) {
        if ((param_4 & 2) == 0) {
          local_18 = puVar8[0x1f];
          *(short *)(param_1 + 0x24) = *(short *)(param_1 + 0x24) - *(short *)(puVar8 + 2);
          sVar1 = *(short *)(param_1 + 0x28);
          *(short *)(param_1 + 0x28) = sVar1 + -0x80;
          if (0x7c < (uint)puVar8[1]) {
            *(short *)(param_1 + 0x28) = sVar1 + -0x480;
          }
          uVar6 = _splimp();
          if (*(short *)((int)puVar8 + 10) == 0) {
                    /* WARNING: Subroutine does not return */
            _panic(s_mfree_001db345);
          }
          *(short *)(&DAT_001e917c + *(short *)((int)puVar8 + 10) * 2) =
               *(short *)(&DAT_001e917c + *(short *)((int)puVar8 + 10) * 2) + -1;
          _DAT_001e917c = _DAT_001e917c + 1;
          *(undefined2 *)((int)puVar8 + 10) = 0;
          if (0x7f < (uint)puVar8[1]) {
            _mclput(puVar8);
          }
          *(undefined4 *)(param_1 + 0x30) = *puVar8;
          *puVar8 = _mfree;
          puVar8[1] = 0;
          puVar8[0x1f] = 0;
          _mfree = puVar8;
          _splx(uVar6);
          if (_m_want != 0) {
            _m_want = 0;
            _wakeup(&_mfree);
          }
          puVar8 = *(undefined4 **)(param_1 + 0x30);
          if (puVar8 != (undefined4 *)0x0) {
            puVar8[0x1f] = local_18;
          }
        }
        else {
          puVar8 = (undefined4 *)*puVar8;
          local_1c = 0;
        }
      }
      else if ((param_4 & 2) == 0) {
        puVar8[1] = puVar8[1] + iVar5;
        *(short *)(puVar8 + 2) = *(short *)(puVar8 + 2) - sVar4;
        *(short *)(param_1 + 0x24) = *(short *)(param_1 + 0x24) - sVar4;
      }
      else {
        local_1c = local_1c + iVar5;
      }
    } while (*(short *)(param_1 + 0x58) == 0);
    if ((param_4 & 2) != 0) {
      local_10 = local_10 + iVar5;
      goto LAB_00115b43;
    }
  }
  *(byte *)(param_1 + 6) = *(byte *)(param_1 + 6) | 0x40;
LAB_00115b5a:
  if ((param_4 & 2) == 0) {
    if (puVar8 == (undefined4 *)0x0) {
      *(undefined4 *)(param_1 + 0x30) = local_18;
    }
    else if ((*(byte *)(iVar9 + 10) & 1) != 0) {
      _sbdroprecord(param_1 + 0x24);
    }
    if (((*(byte *)(iVar9 + 10) & 8) != 0) && (*(int *)(param_1 + 8) != 0)) {
      (**(code **)(iVar9 + 0x1c))(param_1,8,0,0,0);
    }
    if ((((local_8 == 0) && (param_5 != (int *)0x0)) && (*param_5 != 0)) &&
       (pcVar2 = *(code **)(*(int *)(iVar9 + 4) + 0xc), pcVar2 != (code *)0x0)) {
      local_8 = (*pcVar2)(*param_5);
    }
  }
LAB_00115bd0:
  uVar3 = *(ushort *)(param_1 + 0x38);
  *(ushort *)(param_1 + 0x38) = uVar3 & 0xfffe;
  if ((uVar3 & 2) != 0) {
    *(ushort *)(param_1 + 0x38) = uVar3 & 0xfffc;
    _wakeup(param_1 + 0x38);
  }
  _splx(local_c);
  return local_8;
}

