
void _m68k_init(int param_1)

{
  char cVar1;
  uint uVar2;
  bool bVar3;
  byte bVar4;
  byte bVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  code *pcVar9;
  uint uVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 *puVar13;
  char *pcVar14;
  int iVar15;
  int iStack_28;
  undefined auStack_24 [32];
  
  iVar11 = *(int *)(param_1 + 4);
  _slot_id = *(int *)(param_1 + 0x1c);
  _slot_id_bmap = *(int *)(param_1 + 0x1c);
  puVar6 = (undefined4 *)_get_vbr();
  _scb = *puVar6;
  off_40ADA18 = (void *)puVar6[1];
  _reboot_vector = puVar6[0x2d];
  off_40ADAC8 = _mon_exit;
  _set_vbr(&_scb);
  uVar10 = *(uint *)(_slot_id + 0x200c000);
  if ((byte)((byte)(uVar10 >> 8) >> 4) == 4) {
    uVar10 = *(uint *)(_slot_id + 0x2200000);
  }
  _cpu_rev = (byte)(uVar10 >> 8);
  _machine_type = _cpu_rev >> 4;
  _board_rev = _cpu_rev & 0xf;
  _cpu_clk = (&byte_40B2BAD)[(uVar10 & 7) * 4];
  switch(_machine_type) {
  case :
    _cpu_type = '\0';
    _dma_chip = 0x139;
    break;
  case :
  case :
  case :
    _cpu_type = '\x01';
    _slot_id_bmap = _slot_id_bmap + 0x100000;
    _dma_chip = 0x139;
    _bmap_chip = _slot_id + 0x20c0000;
    break;
  :
    _cpu_type = '\x01';
    _dma_chip = (word)*(byte *)(_slot_id + 0x200c001);
    _cpu_clk = (&byte_40B2BAD)[(uVar10 & 7 ^ 4) * 4];
    iVar7 = _probe_rl(_slot_id + 0x2210000);
    if (iVar7 != 0) {
      _ncc_chip = 1;
      _cpu_clk = 0x28;
    }
  }
  if (_cpu_type == '\0') {
    _cache = 0x1919;
  }
  else {
    _cache = 0x80008000;
  }
  _intrmask = (undefined4 *)(_slot_id + 0x2007800);
  _intrstat = _slot_id + 0x2007000;
  *_intrmask = 0;
  _intr_mask = 0;
  _eventc_latch = _slot_id_bmap + 0x201a000;
  _eventc_h = _slot_id_bmap + 0x201a001;
  _eventc_m = _slot_id_bmap + 0x201a002;
  _eventc_l = _slot_id_bmap + 0x201a003;
  _scr2 = (uint *)(_slot_id + 0x200d000);
  *_scr2 = *_scr2 & 0x7ffffffe;
  _brightness = _slot_id_bmap + 0x2010000;
  _timer_csr = _slot_id_bmap + 0x2016004;
  _timer_high = _slot_id_bmap + 0x2016000;
  _timer_low = _slot_id_bmap + 0x2016001;
  _mon_global = *(undefined4 *)(param_1 + 4);
  _bcopy(*(undefined4 *)(param_1 + 0x2c),&_etheraddr,6);
  _hostid = CONCAT31(byte_40C9468 | 0x10000 | (uint3)(((uint)byte_40C9467 << 0x10) >> 8),
                     byte_40C9469);
  _strncpy(&_boot_dev,*(undefined4 *)(param_1 + 0x10),8);
  _strncpy(&_boot_file,*(undefined4 *)(param_1 + 0x30),0x40);
  pcVar14 = *(char **)(param_1 + 0x14);
  if (pcVar14 != (char *)0x0) {
    cVar1 = *pcVar14;
    while (cVar1 != '\0') {
      iVar7 = _strncmp(aPagesize_0,pcVar14,9);
      if (iVar7 == 0) {
        _getval(pcVar14 + 8,&_pagesize);
        break;
      }
      iVar7 = _strncmp(&aMem_0,pcVar14,4);
      if (iVar7 == 0) {
        _getval(pcVar14 + 3,&_mem);
        _mem = _mem << 10;
        break;
      }
      pcVar14 = pcVar14 + 1;
      cVar1 = *pcVar14;
    }
  }
  if ((_pagesize == 0x1000) || (_pagesize == 0x2000)) {
    _m68k_page_size = _pagesize;
  }
  else {
    _m68k_page_size = _default_page_size;
  }
  _pmap_set_page_size();
  if (_page_size < _m68k_page_size) {
    _page_size = _m68k_page_size;
  }
  _vm_set_page_size();
  uVar10 = _mem;
  _num_regions = *(int *)(param_1 + 0x24);
  iVar7 = 0;
  bVar3 = false;
  if (0 < _num_regions) {
    uVar2 = -_m68k_page_size;
    iVar15 = 0;
    do {
      if (bVar3) {
        *(undefined4 *)((int)&dword_40C2C40 + iVar15) = 0;
        *(undefined4 *)(DAT_40c2c44 + iVar15) = 0;
        iVar8 = 0;
      }
      else {
        *(undefined4 *)((int)&dword_40C2C40 + iVar15) =
             *(undefined4 *)(*(int *)(param_1 + 0x28) + iVar7 * 8);
        *(undefined4 *)(DAT_40c2c44 + iVar15) =
             *(undefined4 *)(*(int *)(param_1 + 0x28) + 4 + iVar7 * 8);
        iVar8 = *(int *)(DAT_40c2c44 + iVar15) - *(int *)((int)&dword_40C2C40 + iVar15);
      }
      if (((uVar10 != 0) && (!bVar3)) && (uVar10 <= (uint)(_mem_size + iVar8))) {
        *(uint *)(DAT_40c2c44 + iVar15) =
             *(int *)((int)&dword_40C2C40 + iVar15) + (uVar10 - _mem_size);
        bVar3 = true;
      }
      _mem_size = (*(int *)(DAT_40c2c44 + iVar15) - *(int *)((int)&dword_40C2C40 + iVar15)) +
                  _mem_size;
      if (*(int *)(*(int *)(param_1 + 0x28) + iVar7 * 8) != 0) {
        _pmsgbuf = (uVar2 & *(uint *)(*(int *)(param_1 + 0x28) + 4 + iVar7 * 8)) + 0x100;
      }
      iVar15 = iVar15 + 0x1c;
      iVar7 = iVar7 + 1;
    } while (iVar7 < _num_regions);
  }
  _cons_tp = _cons;
  _console_i = *(undefined4 *)(param_1 + 8);
  _console_o = *(int *)(param_1 + 0xc);
  if ((_console_o == 0) || (_console_o != 1)) {
    word_40B6834 = 0xc00;
    bVar3 = false;
    pcVar14 = *(char **)(param_1 + 0x14);
    if (pcVar14 != (char *)0x0) {
      while (iVar7 = _isargsep((int)*pcVar14), iVar7 != 0) {
        pcVar14 = pcVar14 + 1;
      }
      if (*pcVar14 == '-') {
        do {
          cVar1 = *pcVar14;
          if (cVar1 == 's') {
loc_4094FDC:
            bVar3 = true;
          }
          else if (cVar1 < 't') {
            if (cVar1 == 'a') goto loc_4094FDC;
          }
          else if (cVar1 == 'w') goto loc_4094FDC;
          cVar1 = *pcVar14;
          if (cVar1 == '\0') break;
          pcVar14 = pcVar14 + 1;
          iVar7 = _isargsep((int)cVar1);
        } while (iVar7 == 0);
      }
    }
    if ((*(byte *)(iVar11 + 0x171) & 8) != 0) {
      bVar3 = true;
    }
    _kminit();
    if (bVar3) {
      _kmpopup(_mach_title,2,0,0,0);
    }
  }
  else {
    word_40B6834 = 0xb00;
  }
  _boot_args = *(undefined4 *)(param_1 + 0x14);
  _getargs(*(undefined4 *)(param_1 + 0x14),0);
  _printf(aNextRomMonitor,(int)*(sword *)(iVar11 + 0x312),(int)*(sword *)(iVar11 + 0x30a),
          (int)*(sword *)(iVar11 + 0x30c));
  _tick = 1000000 / _hz;
  _tickadj = 240000 / (_hz * 0x3c);
  _mon_reset();
  if (_dma_chip != 0x139) {
    _km_send(0xc5,0xf0000000);
    _mon_rev = (undefined)((uint)*(undefined4 *)(_slot_id + 0x200e008) >> 0x10);
  }
  bVar5 = _cpu_clk;
  bVar4 = _machine_type;
  _master_cpu = 0;
  dword_40B5DD4 = 1;
  iVar11 = 0;
  pcVar9 = _intstacks;
  puVar13 = &_machine_slot;
  puVar6 = &_interrupt_stack;
  do {
    *puVar13 = 1;
    (&DAT_40b5de4)[iVar11 * 8] = (uint)bVar5;
    if (bVar4 == 0) {
      (&dword_40B5DCC)[iVar11 * 8] = 6;
      uVar12 = 1;
    }
    else {
      (&dword_40B5DCC)[iVar11 * 8] = 6;
      uVar12 = 2;
    }
    (&dword_40B5DD0)[iVar11 * 8] = uVar12;
    *puVar6 = pcVar9;
    pcVar9 = pcVar9 + 0x1000;
    puVar13 = puVar13 + 8;
    iVar11 = iVar11 + 1;
    puVar6 = puVar6 + 1;
  } while (iVar11 < 1);
  dword_40C2C40 = _getlastaddr();
  _pmap_bootstrap(_mem_region,_num_regions,&_virtual_avail,&_virtual_end,_pmsgbuf + -0x100);
  _en_bufalloc(0);
  if (_breakpoint != 0) {
    if (_kdb_ipaddr == 0) {
      do {
        _printf(aIpAddress);
        _gets(auStack_24,auStack_24);
        iVar11 = _inet_aton(auStack_24,&iStack_28);
      } while (iVar11 == 0);
      _kdb_ipaddr = iStack_28;
    }
    _printf(aWaitingForConn);
    while (dword_40C9474 == 0) {
      _kdbg_connect(0);
    }
  }
  return;
}

