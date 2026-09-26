/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00194140 */

undefined4 FUN_00194140(void)

{
  bool bVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  undefined1 *puVar11;
  int iVar12;
  int local_20;
  uint local_1c;
  int local_18;
  int local_14;
  
  iVar12 = 0;
  local_14 = 0;
  local_18 = 0;
  bVar1 = false;
  pcVar3 = (char *)_IOMalloc();
  iVar4 = _objc_msgSend();
  iVar5 = _objc_msgSend(iVar4);
  pcVar6 = (char *)_objc_msgSend(iVar4,PTR_s_valueForStringKey__001f9308,s_Class_Names_001e2aa5);
  if (pcVar6 == (char *)0x0) {
    pcVar6 = (char *)_objc_msgSend();
  }
  _objc_msgSend();
  _objc_msgSend();
  iVar10 = -1;
  do {
    if (iVar10 == 0) break;
    iVar10 = iVar10 + -1;
    cVar2 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar2 != '\0');
  _IOFree();
  iVar10 = _objc_msgSend(iVar4,PTR_s_valueForStringKey__001f9308);
  _sprintf(pcVar3,s__sKernBus_001e2acb);
  _objc_getClass();
  puVar11 = &stack0xffffffbc;
  local_20 = 0;
  local_1c = 0;
  do {
    uVar7 = _objc_msgSend();
    if (uVar7 <= local_1c) {
LAB_00194570:
      _IOFree();
      _objc_msgSend();
      if (iVar5 != 0) {
        _objc_msgSend();
      }
      if (iVar10 != 0) {
        _objc_msgSend();
      }
      if (local_20 == 0) {
        _objc_msgSend();
        _objc_msgSend();
        puVar11 = &stack0xffffffa4;
        _objc_msgSend();
LAB_001946c5:
        *(undefined **)(puVar11 + -4) = PTR_s_free_001f921c;
        *(int *)(puVar11 + -8) = local_14;
        *(undefined4 *)(puVar11 + -0xc) = 0x1946d4;
        _objc_msgSend();
LAB_001946d4:
        uVar9 = 0;
      }
      else {
        uVar9 = 1;
      }
      return uVar9;
    }
    _objc_msgSend();
    iVar8 = _objc_getClass();
    if (iVar8 == 0) {
      _IOLog();
      _IOLog();
      goto LAB_00194644;
    }
    if (!bVar1) {
      if (iVar5 != 0) {
        iVar8 = _objc_msgSend();
        if (iVar8 == -1) {
          iVar8 = 0x136;
        }
        if (iVar8 < 0x137) {
          _IOLog();
          _IOLog();
          goto LAB_00194644;
        }
      }
      bVar1 = true;
    }
    cVar2 = _objc_msgSend();
    if (cVar2 != '\0') {
      local_20 = 1;
      goto LAB_00194570;
    }
    uVar7 = _objc_msgSend();
    if (uVar7 == 0) {
      iVar12 = _objc_msgSend();
      if (iVar12 != 0) {
        iVar8 = _objc_msgSend();
        if (iVar8 == 0) {
          _objc_msgSend();
        }
        _objc_msgSend();
        iVar8 = _objc_msgSend();
        if (iVar8 != 0) {
          _objc_msgSend();
          local_14 = _objc_msgSend();
          if (local_14 != 0) {
            _objc_msgSend();
            _sprintf(pcVar3,s_IO_sDeviceDescription_001e2be6);
            uVar9 = _objc_getClass(pcVar3);
            uVar9 = _objc_msgSend(uVar9,PTR_s_alloc_001f9210,PTR_s__initWithDelegate__001f9458,
                                  iVar12);
            local_18 = _objc_msgSend(uVar9);
            if (local_18 != 0) {
              _create_dev_port();
              _objc_msgSend();
              goto LAB_00194518;
            }
            goto LAB_00194644;
          }
        }
      }
LAB_0019461e:
      _IOLog();
LAB_00194644:
      if (iVar5 != 0) {
        _objc_msgSend();
      }
      if (iVar10 != 0) {
        _objc_msgSend();
      }
      if (iVar4 != 0) {
        _objc_msgSend();
      }
      if (local_18 != 0) {
        _objc_msgSend();
      }
      if (iVar12 != 0) {
        _objc_msgSend();
      }
      if (local_14 == 0) goto LAB_001946d4;
      goto LAB_001946c5;
    }
    if (2 < uVar7) goto LAB_0019461e;
    _objc_msgSend();
    iVar12 = _objc_msgSend();
    if (iVar12 == 0) goto LAB_00194644;
    _objc_msgSend();
    local_18 = _objc_msgSend();
    if (local_18 == 0) goto LAB_00194644;
LAB_00194518:
    cVar2 = _objc_msgSend();
    if (cVar2 == '\0') {
      _IOLog();
    }
    else {
      iVar8 = _objc_msgSend();
      if (iVar8 == 0) {
        local_20 = local_20 + 1;
      }
    }
    local_1c = local_1c + 1;
  } while( true );
}

