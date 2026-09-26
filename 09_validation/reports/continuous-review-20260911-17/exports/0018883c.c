
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __regparm2 _dma_xfer_chan(undefined4 param_1,undefined4 param_2,uint param_3,int param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined2 uVar8;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  uint uVar9;
  uint uVar10;
  uint local_8;
  
  if ((_dma_assigned_bits >> (param_3 & 0x1f) & 1) != 0) {
    iVar4 = _eisa_present();
    if (iVar4 == 0) {
      *(byte *)(param_4 + 0x14) = *(byte *)(param_4 + 0x14) | 0x30;
    }
    iVar4 = _dma_xfer(param_4,&local_8);
    param_2 = 0;
    if (iVar4 != 0) {
      *(uint *)(param_4 + 8) = param_3;
      *(byte *)(param_4 + 0x14) = *(byte *)(param_4 + 0x14) | 4;
      bVar2 = (byte)param_3;
      if ((_dma_assigned_bits >> (param_3 & 0x1f) & 1) != 0) {
        uVar9 = (uint)(3 < (int)param_3);
        bVar3 = (&_dma_cmd_regs)[uVar9];
        (&_dma_cmd_regs)[uVar9] = bVar3 | 4;
        _us_spin(1);
        uVar8 = __dma_chip_port;
        if (uVar9 != 0) {
          uVar8 = DAT_001e18a0;
        }
        out(uVar8,bVar3 | 4);
        LOCK();
        _DAT_001e75ec = _DAT_001e75ec + 1;
        UNLOCK();
        _us_spin(1);
        uVar8 = DAT_001e18a4;
        if ((int)param_3 < 4) {
          uVar8 = DAT_001e1896;
        }
        out(uVar8,bVar2 & 3 | 4);
        LOCK();
        _DAT_001e75ec = _DAT_001e75ec + 1;
        UNLOCK();
        uVar9 = (uint)(3 < (int)param_3);
        bVar3 = (&_dma_cmd_regs)[uVar9];
        (&_dma_cmd_regs)[uVar9] = bVar3 & 0xfb;
        _us_spin(1);
        uVar8 = __dma_chip_port;
        if (uVar9 != 0) {
          uVar8 = DAT_001e18a0;
        }
        out(uVar8,bVar3 & 0xfb);
        LOCK();
        _DAT_001e75ec = _DAT_001e75ec + 1;
        UNLOCK();
      }
      if ((*(byte *)(param_4 + 0x14) & 8) == 0) {
        if ((_dma_assigned_bits >> (param_3 & 0x1f) & 1) != 0) {
          bVar3 = (&_dma_write_regs)[param_3 * 2];
          (&_dma_write_regs)[param_3 * 2] = bVar3 & 0xf3 | 8;
          uVar9 = (uint)(3 < (int)param_3);
          bVar1 = (&_dma_cmd_regs)[uVar9];
          (&_dma_cmd_regs)[uVar9] = bVar1 | 4;
          _us_spin(1);
          uVar8 = __dma_chip_port;
          if (uVar9 != 0) {
            uVar8 = DAT_001e18a0;
          }
          out(uVar8,bVar1 | 4);
          LOCK();
          _DAT_001e75ec = _DAT_001e75ec + 1;
          UNLOCK();
          _us_spin(1);
          uVar8 = DAT_001e18a6;
          if ((int)param_3 < 4) {
            uVar8 = DAT_001e1898;
          }
          out(uVar8,bVar2 & 3 | bVar3 & 0xf0 | 8);
          LOCK();
          _DAT_001e75ec = _DAT_001e75ec + 1;
          UNLOCK();
          uVar9 = (uint)(3 < (int)param_3);
          bVar3 = (&_dma_cmd_regs)[uVar9] & 0xfb;
          (&_dma_cmd_regs)[uVar9] = bVar3;
          _us_spin(1);
          uVar8 = __dma_chip_port;
          if (uVar9 != 0) {
            uVar8 = DAT_001e18a0;
          }
          goto LAB_00188b2e;
        }
      }
      else if ((_dma_assigned_bits >> (param_3 & 0x1f) & 1) != 0) {
        bVar3 = (&_dma_write_regs)[param_3 * 2];
        (&_dma_write_regs)[param_3 * 2] = bVar3 & 0xf3 | 4;
        uVar9 = (uint)(3 < (int)param_3);
        bVar1 = (&_dma_cmd_regs)[uVar9];
        (&_dma_cmd_regs)[uVar9] = bVar1 | 4;
        _us_spin(1);
        uVar8 = __dma_chip_port;
        if (uVar9 != 0) {
          uVar8 = DAT_001e18a0;
        }
        out(uVar8,bVar1 | 4);
        LOCK();
        _DAT_001e75ec = _DAT_001e75ec + 1;
        UNLOCK();
        _us_spin(1);
        uVar8 = DAT_001e18a6;
        if ((int)param_3 < 4) {
          uVar8 = DAT_001e1898;
        }
        out(uVar8,bVar2 & 3 | bVar3 & 0xf0 | 4);
        LOCK();
        _DAT_001e75ec = _DAT_001e75ec + 1;
        UNLOCK();
        uVar9 = (uint)(3 < (int)param_3);
        bVar3 = (&_dma_cmd_regs)[uVar9] & 0xfb;
        (&_dma_cmd_regs)[uVar9] = bVar3;
        _us_spin(1);
        uVar8 = __dma_chip_port;
        if (uVar9 != 0) {
          uVar8 = DAT_001e18a0;
        }
LAB_00188b2e:
        out(uVar8,bVar3);
        LOCK();
        _DAT_001e75ec = _DAT_001e75ec + 1;
        UNLOCK();
      }
      uVar9 = local_8;
      if (((byte)(&DAT_001f74f1)[param_3 * 2] >> 2 & 3) == 1) {
        uVar9 = CONCAT22((short)(local_8 >> 0x10),(short)(local_8 >> 1)) & 0xffff7fff;
      }
      uVar10 = (uint)(3 < (int)param_3);
      bVar3 = (&_dma_cmd_regs)[uVar10];
      (&_dma_cmd_regs)[uVar10] = bVar3 | 4;
      _us_spin(1);
      uVar8 = __dma_chip_port;
      if (uVar10 != 0) {
        uVar8 = DAT_001e18a0;
      }
      out(uVar8,bVar3 | 4);
      LOCK();
      _DAT_001e75ec = _DAT_001e75ec + 1;
      UNLOCK();
      _us_spin(1);
      uVar8 = DAT_001e18a8;
      if ((int)param_3 < 4) {
        uVar8 = DAT_001e189a;
      }
      out(uVar8,0xff);
      LOCK();
      _DAT_001e75ec = _DAT_001e75ec + 1;
      UNLOCK();
      _us_spin(1);
      iVar4 = param_3 * 10;
      out(*(undefined2 *)(&__dma_chan_port + iVar4),(char)uVar9);
      LOCK();
      _DAT_001e75ec = _DAT_001e75ec + 1;
      UNLOCK();
      _us_spin(1);
      out(*(undefined2 *)(&__dma_chan_port + iVar4),(char)(uVar9 >> 8));
      LOCK();
      _DAT_001e75ec = _DAT_001e75ec + 1;
      UNLOCK();
      _us_spin(1);
      out(*(undefined2 *)(&DAT_001e1844 + iVar4),(char)(uVar9 >> 0x10));
      LOCK();
      _DAT_001e75ec = _DAT_001e75ec + 1;
      UNLOCK();
      iVar6 = _eisa_present();
      if (iVar6 != 0) {
        _us_spin(1);
        out(*(undefined2 *)(&DAT_001e1846 + iVar4),(char)(uVar9 >> 0x18));
        LOCK();
        _DAT_001e75ec = _DAT_001e75ec + 1;
        UNLOCK();
      }
      uVar9 = (uint)(3 < (int)param_3);
      bVar3 = (&_dma_cmd_regs)[uVar9];
      (&_dma_cmd_regs)[uVar9] = bVar3 & 0xfb;
      _us_spin(1);
      uVar8 = __dma_chip_port;
      if (uVar9 != 0) {
        uVar8 = DAT_001e18a0;
      }
      out(uVar8,bVar3 & 0xfb);
      LOCK();
      _DAT_001e75ec = _DAT_001e75ec + 1;
      UNLOCK();
      uVar9 = *(uint *)(param_4 + 4);
      if (((byte)(&DAT_001f74f1)[param_3 * 2] >> 2 & 3) == 1) {
        uVar9 = uVar9 >> 1;
      }
      iVar4 = uVar9 - 1;
      uVar9 = (uint)(3 < (int)param_3);
      bVar3 = (&_dma_cmd_regs)[uVar9];
      (&_dma_cmd_regs)[uVar9] = bVar3 | 4;
      _us_spin(1);
      uVar8 = __dma_chip_port;
      if (uVar9 != 0) {
        uVar8 = DAT_001e18a0;
      }
      out(uVar8,bVar3 | 4);
      LOCK();
      _DAT_001e75ec = _DAT_001e75ec + 1;
      UNLOCK();
      _us_spin(1);
      uVar8 = DAT_001e18a8;
      if ((int)param_3 < 4) {
        uVar8 = DAT_001e189a;
      }
      out(uVar8,0xff);
      LOCK();
      _DAT_001e75ec = _DAT_001e75ec + 1;
      UNLOCK();
      _us_spin(1);
      iVar6 = param_3 * 10;
      out(*(undefined2 *)(&DAT_001e1848 + iVar6),(char)iVar4);
      LOCK();
      _DAT_001e75ec = _DAT_001e75ec + 1;
      UNLOCK();
      _us_spin(1);
      out(*(undefined2 *)(&DAT_001e1848 + iVar6),(char)((uint)iVar4 >> 8));
      LOCK();
      _DAT_001e75ec = _DAT_001e75ec + 1;
      UNLOCK();
      iVar7 = _eisa_present();
      if (iVar7 != 0) {
        _us_spin(1);
        out(*(undefined2 *)(&DAT_001e184a + iVar6),(char)((uint)iVar4 >> 0x10));
        LOCK();
        _DAT_001e75ec = _DAT_001e75ec + 1;
        UNLOCK();
      }
      uVar9 = (uint)(3 < (int)param_3);
      bVar3 = (&_dma_cmd_regs)[uVar9];
      (&_dma_cmd_regs)[uVar9] = bVar3 & 0xfb;
      _us_spin(1);
      uVar8 = __dma_chip_port;
      if (uVar9 != 0) {
        uVar8 = DAT_001e18a0;
      }
      param_2 = CONCAT22(extraout_var,uVar8);
      out(uVar8,bVar3 & 0xfb);
      LOCK();
      _DAT_001e75ec = _DAT_001e75ec + 1;
      UNLOCK();
      if ((int)param_3 < 4) {
        __prev_tcstatus0 =
             __prev_tcstatus0 & (-2 << (bVar2 & 0x1f) | 0xfffffffeU >> 0x20 - (bVar2 & 0x1f));
      }
      else {
        bVar3 = bVar2 - 4 & 0x1f;
        __prev_tcstatus1 = __prev_tcstatus1 & (-2 << bVar3 | 0xfffffffeU >> 0x20 - bVar3);
      }
      if ((_dma_assigned_bits >> (param_3 & 0x1f) & 1) != 0) {
        uVar9 = (uint)(3 < (int)param_3);
        bVar3 = (&_dma_cmd_regs)[uVar9];
        (&_dma_cmd_regs)[uVar9] = bVar3 | 4;
        _us_spin(1);
        uVar8 = __dma_chip_port;
        if (uVar9 != 0) {
          uVar8 = DAT_001e18a0;
        }
        out(uVar8,bVar3 | 4);
        LOCK();
        _DAT_001e75ec = _DAT_001e75ec + 1;
        UNLOCK();
        _us_spin(1);
        uVar8 = DAT_001e18a4;
        if ((int)param_3 < 4) {
          uVar8 = DAT_001e1896;
        }
        out(uVar8,bVar2 & 3);
        LOCK();
        _DAT_001e75ec = _DAT_001e75ec + 1;
        UNLOCK();
        uVar9 = (uint)(3 < (int)param_3);
        bVar2 = (&_dma_cmd_regs)[uVar9];
        (&_dma_cmd_regs)[uVar9] = bVar2 & 0xfb;
        _us_spin(1);
        uVar8 = __dma_chip_port;
        if (uVar9 != 0) {
          uVar8 = DAT_001e18a0;
        }
        param_2 = CONCAT22(extraout_var_00,uVar8);
        out(uVar8,bVar2 & 0xfb);
        LOCK();
        _DAT_001e75ec = _DAT_001e75ec + 1;
        UNLOCK();
      }
      uVar5 = 1;
      goto LAB_00188ecf;
    }
  }
  uVar5 = 0;
LAB_00188ecf:
  return CONCAT44(param_2,uVar5);
}

