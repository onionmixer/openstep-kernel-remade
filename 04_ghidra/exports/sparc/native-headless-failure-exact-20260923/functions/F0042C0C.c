
/* WARNING: Removing unreachable block (ram,0xf0042d04) */
/* WARNING: Removing unreachable block (ram,0xf0042d24) */
/* WARNING: Removing unreachable block (ram,0xf0042d64) */
/* WARNING: Removing unreachable block (ram,0xf0042d78) */
/* WARNING: Removing unreachable block (ram,0xf0042dbc) */
/* WARNING: Removing unreachable block (ram,0xf0042ed4) */
/* WARNING: Removing unreachable block (ram,0xf0042f48) */
/* WARNING: Removing unreachable block (ram,0xf0042f80) */
/* WARNING: Removing unreachable block (ram,0xf00431fc) */
/* WARNING: Removing unreachable block (ram,0xf0043000) */
/* WARNING: Removing unreachable block (ram,0xf0042ef4) */
/* WARNING: Removing unreachable block (ram,0xf0042f08) */
/* WARNING: Removing unreachable block (ram,0xf0042ff0) */
/* WARNING: Removing unreachable block (ram,0xf0043110) */
/* WARNING: Removing unreachable block (ram,0xf004319c) */
/* WARNING: Removing unreachable block (ram,0xf0042de0) */
/* WARNING: Removing unreachable block (ram,0xf0043318) */
/* WARNING: Removing unreachable block (ram,0xf0043358) */
/* WARNING: Removing unreachable block (ram,0xf0043378) */
/* WARNING: Removing unreachable block (ram,0xf00432f4) */
/* WARNING: Removing unreachable block (ram,0xf0042c0c) */
/* WARNING: Removing unreachable block (ram,0xf004339c) */
/* WARNING: Removing unreachable block (ram,0xf0043360) */
/* WARNING: Removing unreachable block (ram,0xf004334c) */
/* WARNING: Removing unreachable block (ram,0xf0043310) */
/* WARNING: Removing unreachable block (ram,0xf0043260) */
/* WARNING: Removing unreachable block (ram,0xf0043124) */
/* WARNING: Removing unreachable block (ram,0xf00430d0) */
/* WARNING: Removing unreachable block (ram,0xf0043098) */
/* WARNING: Removing unreachable block (ram,0xf0042f00) */
/* WARNING: Removing unreachable block (ram,0xf0043034) */
/* WARNING: Removing unreachable block (ram,0xf004321c) */
/* WARNING: Removing unreachable block (ram,0xf0042fa8) */
/* WARNING: Removing unreachable block (ram,0xf0042f9c) */
/* WARNING: Removing unreachable block (ram,0xf0042f28) */
/* WARNING: Removing unreachable block (ram,0xf0042e00) */
/* WARNING: Removing unreachable block (ram,0xf0042d9c) */
/* WARNING: Removing unreachable block (ram,0xf0042d70) */
/* WARNING: Removing unreachable block (ram,0xf0042d30) */
/* WARNING: Removing unreachable block (ram,0xf0042d18) */
/* WARNING: Removing unreachable block (ram,0xf0042ccc) */
/* WARNING: Removing unreachable block (ram,0xf0042c90) */

undefined8
_clntkudp_callit_addr
          (int *param_1,uint param_2,code *param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,int *param_7,undefined4 *param_8)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  div_t *pdVar5;
  code *pcVar6;
  uint *puVar7;
  int iVar8;
  uint *puVar9;
  boolean_t bVar10;
  div_t *pdVar11;
  int *piVar12;
  int iVar13;
  uint uVar14;
  uint *puVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  bool bVar19;
  uint local_res48 [5];
  div_t *in_stack_ffffff60;
  int local_7c;
  undefined4 local_74;
  uint local_6c;
  undefined4 local_3c;
  int local_38;
  undefined4 local_34;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  puVar15 = (uint *)param_1[2];
  local_74 = (uint *)0x0;
  local_6c = puVar15[4];
  uVar16 = puVar15[5];
  iVar17 = *_active_u;
  _rcstat = _rcstat + 1;
  uVar3 = *puVar15;
  local_7c = 2;
  local_res48[0] = param_2;
  while ((uVar3 & 2) != 0) {
    DAT_f013ac54 = DAT_f013ac54 + 1;
    *puVar15 = *puVar15 | 4;
    _sleep((uint)param_1);
    uVar3 = *puVar15;
  }
  uVar3 = *puVar15;
  *puVar15 = uVar3 | 2;
  if ((uVar3 & 0x20) != 0) {
    local_6c = 1;
  }
  _lock_write(_active_u + 8);
  iVar2 = _clntkudpxid;
  iVar8 = _hz;
  _clntkudpxid = _clntkudpxid + 1;
  iVar18 = _active_u[7];
  _active_u[7] = puVar15[0x1d];
  iVar4 = *param_7;
  _umul(iVar4,iVar8);
  iVar13 = param_7[1];
  _umul(iVar13,iVar8);
  pdVar5 = _div(in_stack_ffffff60,iVar13,1000000);
  pdVar11 = (div_t *)((int)&pdVar5->quot + iVar4);
  do {
    _spl5();
    uVar3 = *puVar15;
    if ((uVar3 & 8) != 0) {
      param_2 = 0xf0012c00;
      do {
        *puVar15 = uVar3 | 0x10;
        _timeout(-0xffed218);
        _sleep((uint)(puVar15 + 0x1a));
        _sbflush(uVar16 + 0x24);
        uVar3 = *puVar15;
      } while ((uVar3 & 8) != 0);
      uVar3 = *puVar15;
    }
    *puVar15 = uVar3 | 8;
    _spln(pdVar5);
    pcVar6 = FUN_f00429b0;
    _mclgetx(FUN_f00429b0,puVar15,puVar15[0x1a],0x2260,1);
    puVar9 = puVar15 + 0xd;
    if (pcVar6 == (code *)0x0) {
      puVar15[10] = 0xc;
      puVar15[0xb] = 0x37;
      FUN_f00429b0(puVar15);
      uVar3 = puVar15[10];
    }
    else {
      *(int *)puVar15[0x1a] = iVar2;
      _xdrmbuf_init(puVar9,pcVar6,0);
      if (local_74 == (uint *)0x0) {
        (**(code **)(puVar15[0xe] + 0x14))(puVar9,puVar15[0x19]);
        puVar7 = puVar9;
        (**(code **)(puVar15[0xe] + 4))(puVar9,local_res48);
        if (puVar7 != (uint *)0x0) {
          iVar8 = *param_1;
          (**(code **)(*(int *)(iVar8 + 0x20) + 4))(iVar8,puVar9);
          if ((iVar8 != 0) && (puVar7 = puVar9, (*param_3)(puVar9,param_4), puVar7 != (uint *)0x0))
          {
            (**(code **)(puVar15[0xe] + 0x10))();
            local_74._2_2_ = SUB42(puVar9,0);
            goto LAB_f0042ec8;
          }
        }
        puVar15[10] = 1;
        puVar15[0xb] = 5;
        goto LAB_f0043260;
      }
      (**(code **)(puVar15[0xe] + 0x14))(puVar9,local_74);
      puVar9 = local_74;
LAB_f0042ec8:
      local_74 = puVar9;
      *(undefined2 *)(pcVar6 + 8) = local_74._2_2_;
      uVar3 = uVar16;
      _ku_sendto_mbuf(uVar16,pcVar6,puVar15 + 6);
      puVar15[0xb] = uVar3;
      if (uVar3 == 0) {
        iVar8 = 2;
        uVar3 = 0xfffbbc00;
        do {
          _splnet();
          sVar1 = *(short *)(uVar16 + 0x24);
          while (sVar1 == 0) {
            _timeout(-0xffbcbe8);
            *(ushort *)(uVar16 + 0x38) = *(ushort *)(uVar16 + 0x38) | 4;
            if ((iVar17 == 0) || ((*puVar15 & 0x800) == 0)) {
              param_2 = 0;
              _sleep(uVar16 + 0x24);
            }
            else {
              uVar14 = *(uint *)(iVar17 + 0x1c);
              *(uint *)(iVar17 + 0x1c) = uVar14 | 0xfffbbffa;
              param_2 = _sleep(uVar16 + 0x24);
              *(uint *)(iVar17 + 0x1c) = uVar14;
            }
            _untimeout(_ckuwakeup,puVar15);
            if (param_2 != 0) {
              _spln(uVar3);
              puVar15[10] = 0x12;
              puVar15[0xb] = 4;
              goto LAB_f0043268;
            }
            if ((*puVar15 & 1) != 0) {
              *puVar15 = *puVar15 & 0xfffffffe;
              _spln(uVar3);
              puVar15[10] = 5;
              puVar15[0xb] = 0x3c;
              DAT_f013ac50 = DAT_f013ac50 + 1;
              goto LAB_f0043268;
            }
            sVar1 = *(short *)(uVar16 + 0x24);
          }
          if (*(short *)(uVar16 + 0x56) == 0) {
            uVar14 = uVar16;
            _ku_recvfrom(uVar16,&local_18);
            puVar15[0x1c] = uVar14;
            if (param_8 != (undefined4 *)0x0) {
              *param_8 = local_18;
              param_8[1] = local_14;
              param_8[2] = local_10;
              param_8[3] = local_c;
            }
            _spln(uVar3);
            uVar14 = puVar15[0x1c];
            if (uVar14 != 0) {
              iVar4 = *(int *)(uVar14 + 4);
              uVar3 = puVar15[0x1c];
              puVar15[0x1b] = uVar14 + iVar4;
              if (3 < *(ushort *)(uVar3 + 8)) {
                iVar13 = *(int *)puVar15[0x1a];
                if (*(int *)(uVar14 + iVar4) == iVar13) {
                  _splnet();
                  _sbflush(uVar16 + 0x24);
                  _spln(iVar13);
                  break;
                }
                DAT_f013ac4c = DAT_f013ac4c + 1;
                uVar3 = puVar15[0x1c];
              }
              _m_freem();
            }
          }
          else {
            *(undefined2 *)(uVar16 + 0x56) = 0;
            _spln(uVar3);
          }
          bVar19 = iVar8 != 1;
          iVar8 = iVar8 + -1;
        } while (bVar19);
        if (iVar8 == 0) {
          puVar15[10] = 4;
          puVar15[0xb] = 5;
        }
        else {
          _xdrmbuf_init(puVar15 + 0x13,puVar15[0x1c],1);
          local_3c = __null_auth;
          local_38 = DAT_f013ac24;
          local_34 = DAT_f013ac28;
          local_2c = param_6;
          local_28 = param_5;
          bVar10 = _xdr_replymsg();
          if (bVar10 == 0) {
            puVar15[10] = 2;
            puVar15[0xb] = 5;
LAB_f004325c:
            pcVar6 = (code *)puVar15[0x1c];
          }
          else {
            __seterr_reply();
            if (puVar15[10] == 0) {
              iVar8 = *param_1;
              (**(code **)(*(int *)(iVar8 + 0x20) + 8))(iVar8,&local_3c);
              if (iVar8 == 0) {
                puVar15[10] = 7;
                puVar15[0xb] = 6;
                DAT_f013ac5c = DAT_f013ac5c + 1;
              }
              if (local_38 == 0) goto LAB_f004325c;
              puVar15[0x13] = 2;
              _xdr_opaque_auth(puVar15 + 0x13,&local_3c);
              pcVar6 = (code *)puVar15[0x1c];
            }
            else {
              if (0 < local_7c) {
                iVar8 = *param_1;
                (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))();
                if (iVar8 != 0) {
                  local_7c = local_7c + -1;
                  local_74 = (uint *)0x0;
                  DAT_f013ac58 = DAT_f013ac58 + 1;
                }
                goto LAB_f004325c;
              }
              pcVar6 = (code *)puVar15[0x1c];
            }
          }
LAB_f0043260:
          _m_freem(pcVar6);
        }
      }
      else {
        puVar15[10] = 3;
      }
LAB_f0043268:
      uVar3 = puVar15[10];
    }
    if ((((uVar3 == 0) || (uVar3 == 0x12)) || (uVar3 == 1)) ||
       (local_6c = local_6c - 1, (int)local_6c < 1)) {
      _active_u[7] = iVar18;
      piVar12 = _active_u + 8;
      _lock_done(piVar12);
      _spl5();
      uVar3 = *puVar15;
      if ((uVar3 & 8) != 0) {
        do {
          *puVar15 = uVar3 | 0x10;
          _timeout(-0xffed218);
          _sleep((uint)(puVar15 + 0x1a));
          _sbflush(uVar16 + 0x24);
          uVar3 = *puVar15;
        } while ((uVar3 & 8) != 0);
      }
      _spln(piVar12);
      uVar3 = *puVar15;
      *puVar15 = uVar3 & 0xfffffffd;
      if ((uVar3 & 4) != 0) {
        *puVar15 = uVar3 & 0xfffffff9;
        _wakeup(param_1);
      }
      if (puVar15[10] != 0) {
        DAT_f013ac44 = DAT_f013ac44 + 1;
      }
      return CONCAT44(param_2,puVar15[10]);
    }
    DAT_f013ac48 = DAT_f013ac48 + 1;
    pdVar5 = (div_t *)((int)pdVar11 * 2);
    pdVar11 = (div_t *)(_hz * 0x3c);
    if ((int)pdVar5 + _hz * -0x3c == 0 || (int)pdVar5 < _hz * 0x3c) {
      pdVar11 = pdVar5;
    }
    if ((puVar15[10] == 0xc) || (pdVar5 = pdVar11, puVar15[10] == 3)) {
      pdVar5 = (div_t *)_sleep(0xf0134750);
    }
  } while( true );
}

