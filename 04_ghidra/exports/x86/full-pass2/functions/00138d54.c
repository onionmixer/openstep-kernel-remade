/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00138d54 */

int FUN_00138d54(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  uint uVar2;
  short sVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int local_c;
  uint local_8;
  
  local_c = 0;
  if (*(int *)(param_2 + 8) != 0) {
    _printf(s_fifo_rdwr__non_zero_offset___d_001dd540,*(int *)(param_2 + 8));
  }
  uVar2 = *(uint *)(param_1 + 0x30);
  while ((*(ushort *)(uVar2 + 0x40) & 1) != 0) {
    *(ushort *)(uVar2 + 0x40) = *(ushort *)(uVar2 + 0x40) | 0x10;
    _sleep(uVar2);
  }
  *(byte *)(uVar2 + 0x40) = *(byte *)(uVar2 + 0x40) | 1;
  if (param_3 == 1) {
    local_8 = *(uint *)(param_2 + 0x14);
    if (DAT_001de6b0 < local_8) {
      local_c = 0x16;
    }
    else if (local_8 != 0) {
LAB_00138dd4:
      if (*(short *)(uVar2 + 0x82) == 0) {
        _psignal(*_active_u,(char *)0xd);
        local_c = 0x20;
        goto LAB_0013928a;
      }
      uVar5 = *(uint *)(uVar2 + 0x7c);
      if (_fifoinfo < local_8 + uVar5) {
        if ((*(byte *)(param_2 + 0x10) & 4) != 0) {
          if ((_fifoinfo < local_8) && (uVar5 < _fifoinfo)) {
LAB_00138e74:
            local_8 = _fifoinfo - *(int *)(uVar2 + 0x7c);
            goto LAB_00138e80;
          }
LAB_0013906f:
          local_c = 0x23;
          if ((*(byte *)(*_active_u + 0x16) & 2) != 0) {
            local_c = 0xb;
          }
          goto LAB_0013928a;
        }
        if ((_fifoinfo < local_8) && (uVar5 < _fifoinfo)) goto LAB_00138e74;
        *(byte *)(uVar2 + 0x88) = *(byte *)(uVar2 + 0x88) | 2;
        uVar1 = *(ushort *)(uVar2 + 0x40);
        *(ushort *)(uVar2 + 0x40) = uVar1 & 0xfffe;
        if ((uVar1 & 0x10) != 0) {
          *(ushort *)(uVar2 + 0x40) = uVar1 & 0xffee;
          _wakeup(uVar2);
        }
        uVar5 = uVar2 + 0x80;
        while( true ) {
          _sleep(uVar5);
          if ((*(ushort *)(uVar2 + 0x40) & 1) == 0) break;
          *(ushort *)(uVar2 + 0x40) = *(ushort *)(uVar2 + 0x40) | 0x10;
          uVar5 = uVar2;
        }
        *(byte *)(uVar2 + 0x40) = *(byte *)(uVar2 + 0x40) | 1;
LAB_00139008:
        local_8 = *(uint *)(param_2 + 0x14);
      }
      else {
LAB_00138e80:
        if ((int)*(short *)(uVar2 + 0x84) - (int)*(short *)(uVar2 + 0x86) != *(int *)(uVar2 + 0x7c))
        {
          _printf(s_fifo_write__ptr_mismatch___size__001dd560,*(int *)(uVar2 + 0x7c),
                  (int)*(short *)(uVar2 + 0x84),(int)*(short *)(uVar2 + 0x86));
        }
        if (DAT_001de6b4 < *(short *)(uVar2 + 0x86)) {
          _printf(s_fifo_write__rptr_too_big___rptr__001dd596,(int)*(short *)(uVar2 + 0x86));
        }
        if (*(short *)(uVar2 + 0x8a) * DAT_001de6b4 < (int)*(short *)(uVar2 + 0x84)) {
          _printf(s_fifo_write__wptr_too_big___wptr__001dd5ba,(int)*(short *)(uVar2 + 0x84),
                  (int)*(short *)(uVar2 + 0x8a));
        }
        while ((uint)(*(short *)(uVar2 + 0x8a) * DAT_001de6b4 - (int)*(short *)(uVar2 + 0x84)) <
               local_8) {
          puVar4 = (undefined4 *)FUN_00139458(uVar2);
          if (puVar4 == (undefined4 *)0x0) goto LAB_00139008;
          *puVar4 = 0;
          if (*(int *)(uVar2 + 0x68) == 0) {
            *(undefined4 **)(uVar2 + 0x68) = puVar4;
          }
          else {
            **(undefined4 **)(uVar2 + 0x6c) = puVar4;
          }
          *(undefined4 **)(uVar2 + 0x6c) = puVar4;
        }
        puVar4 = *(undefined4 **)(uVar2 + 0x68);
        for (iVar6 = (int)*(short *)(uVar2 + 0x84); DAT_001de6b4 <= iVar6;
            iVar6 = iVar6 - DAT_001de6b4) {
          puVar4 = (undefined4 *)*puVar4;
        }
        for (; local_8 != 0; local_8 = local_8 - uVar5) {
          uVar5 = local_8;
          if ((uint)(DAT_001de6b4 - iVar6) < local_8) {
            uVar5 = DAT_001de6b4 - iVar6;
          }
          local_c = _uiomove(iVar6 + (int)puVar4,uVar5,1,param_2);
          if (local_c != 0) goto LAB_0013928a;
          *(int *)(uVar2 + 0x7c) = *(int *)(uVar2 + 0x7c) + uVar5;
          *(short *)(uVar2 + 0x84) = *(short *)(uVar2 + 0x84) + (short)uVar5;
          iVar6 = 0;
          puVar4 = (undefined4 *)*puVar4;
        }
        _smark(uVar2,0x42);
        if ((*(ushort *)(uVar2 + 0x88) & 1) != 0) {
          *(ushort *)(uVar2 + 0x88) = *(ushort *)(uVar2 + 0x88) & 0xfffe;
          _wakeup(uVar2 + 0x82);
        }
        if (*(int *)(uVar2 + 0x70) != 0) {
          _selwakeup(*(int *)(uVar2 + 0x70),*(byte *)(uVar2 + 0x88) & 4);
          _thread_deallocate(*(undefined4 *)(uVar2 + 0x70));
          *(byte *)(uVar2 + 0x88) = *(byte *)(uVar2 + 0x88) & 0xfb;
          *(undefined4 *)(uVar2 + 0x70) = 0;
        }
      }
      if (local_8 == 0) goto LAB_0013928a;
      goto LAB_00138dd4;
    }
  }
  else {
    local_8 = *(uint *)(param_2 + 0x14);
    if (local_8 != 0) {
      while (uVar5 = *(uint *)(uVar2 + 0x7c), uVar5 == 0) {
        if (*(short *)(uVar2 + 0x80) == 0) goto LAB_0013928a;
        if ((*(byte *)(param_2 + 0x10) & 4) != 0) goto LAB_0013906f;
        *(byte *)(uVar2 + 0x88) = *(byte *)(uVar2 + 0x88) | 1;
        uVar1 = *(ushort *)(uVar2 + 0x40);
        *(ushort *)(uVar2 + 0x40) = uVar1 & 0xfffe;
        if ((uVar1 & 0x10) != 0) {
          *(ushort *)(uVar2 + 0x40) = uVar1 & 0xffee;
          _wakeup(uVar2);
        }
        uVar5 = uVar2 + 0x82;
        while( true ) {
          _sleep(uVar5);
          if ((*(ushort *)(uVar2 + 0x40) & 1) == 0) break;
          *(ushort *)(uVar2 + 0x40) = *(ushort *)(uVar2 + 0x40) | 0x10;
          uVar5 = uVar2;
        }
        *(byte *)(uVar2 + 0x40) = *(byte *)(uVar2 + 0x40) | 1;
      }
      if ((int)*(short *)(uVar2 + 0x84) - (int)*(short *)(uVar2 + 0x86) != *(int *)(uVar2 + 0x7c)) {
        _printf(s_fifo_read__ptr_mismatch___size___001dd5e7,*(int *)(uVar2 + 0x7c),
                (int)*(short *)(uVar2 + 0x84),(int)*(short *)(uVar2 + 0x86));
      }
      if (DAT_001de6b4 < *(short *)(uVar2 + 0x86)) {
        _printf(s_fifo_read__rptr_too_big___rptr___001dd61c,(int)*(short *)(uVar2 + 0x86));
      }
      if (*(short *)(uVar2 + 0x8a) * DAT_001de6b4 < (int)*(short *)(uVar2 + 0x84)) {
        _printf(s_fifo_read__wptr_too_big___wptr___001dd63f,(int)*(short *)(uVar2 + 0x84),
                (int)*(short *)(uVar2 + 0x8a));
      }
      iVar7 = (int)*(short *)(uVar2 + 0x86);
      iVar6 = *(int *)(uVar2 + 0x68);
      if (uVar5 < local_8) {
        local_8 = uVar5;
      }
      while (local_8 != 0) {
        uVar5 = local_8;
        if ((uint)(DAT_001de6b4 - iVar7) < local_8) {
          uVar5 = DAT_001de6b4 - iVar7;
        }
        local_c = _uiomove(iVar7 + iVar6,uVar5,0,param_2);
        if (local_c != 0) goto LAB_0013928a;
        *(int *)(uVar2 + 0x7c) = *(int *)(uVar2 + 0x7c) - uVar5;
        sVar3 = (short)uVar5 + *(short *)(uVar2 + 0x86);
        *(short *)(uVar2 + 0x86) = sVar3;
        local_8 = local_8 - uVar5;
        if (DAT_001de6b4 < sVar3) {
          _printf(s_fifo_read__rptr_after_uiomove_to_001dd66b,(int)sVar3);
        }
        iVar7 = 0;
        if (DAT_001de6b4 == *(short *)(uVar2 + 0x86)) {
          *(undefined2 *)(uVar2 + 0x86) = 0;
          iVar6 = FUN_00139560(iVar6,uVar2);
          *(int *)(uVar2 + 0x68) = iVar6;
          *(short *)(uVar2 + 0x84) = *(short *)(uVar2 + 0x84) - (short)DAT_001de6b4;
          iVar7 = 0;
        }
      }
      _smark(uVar2,4);
      if ((*(ushort *)(uVar2 + 0x88) & 2) != 0) {
        *(ushort *)(uVar2 + 0x88) = *(ushort *)(uVar2 + 0x88) & 0xfffd;
        _wakeup(uVar2 + 0x80);
      }
      if (*(int *)(uVar2 + 0x74) != 0) {
        _selwakeup(*(int *)(uVar2 + 0x74),*(byte *)(uVar2 + 0x88) & 8);
        _thread_deallocate(*(undefined4 *)(uVar2 + 0x74));
        *(byte *)(uVar2 + 0x88) = *(byte *)(uVar2 + 0x88) & 0xf7;
        *(undefined4 *)(uVar2 + 0x74) = 0;
      }
    }
  }
LAB_0013928a:
  uVar1 = *(ushort *)(uVar2 + 0x40);
  *(ushort *)(uVar2 + 0x40) = uVar1 & 0xfffe;
  if ((uVar1 & 0x10) != 0) {
    *(ushort *)(uVar2 + 0x40) = uVar1 & 0xffee;
    _wakeup(uVar2);
  }
  *(undefined4 *)(param_2 + 8) = 0;
  return local_c;
}

