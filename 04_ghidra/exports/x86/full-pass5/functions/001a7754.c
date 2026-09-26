/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a7754 */

void FUN_001a7754(void)

{
  int iVar1;
  undefined4 *puVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint local_8;
  
  local_8 = 1;
  do {
    FUN_001a7970();
    puVar2 = DAT_001e86d8;
    iVar4 = _vol_check_manual_poll();
    for (; (undefined4 **)puVar2 != &DAT_001e86d8; puVar2 = (undefined4 *)puVar2[6]) {
      _objc_msgSend(*puVar2,PTR_s_name_001f9228);
      uVar6 = *puVar2;
      uVar5 = _objc_msgSend(uVar6,PTR_s_lastReadyState_001f9c70);
      if ((uVar5 != 0) &&
         (((cVar3 = _objc_msgSend(*puVar2,PTR_s_needsManualPolling_001f9c38), cVar3 == '\0' ||
           (iVar4 != 0)) || (local_8 = uVar5, uVar5 == 3)))) {
        local_8 = _objc_msgSend(uVar6,PTR_s_updateReadyState_001f9cbc);
      }
      if (uVar5 < 3) {
        if ((uVar5 != 0) && (local_8 == 0)) {
          _objc_msgSend(uVar6,PTR_s_setLastReadyState__001f9c6c,0);
          if (*(char *)((int)puVar2 + 0xd) != '\0') {
            _vol_panel_remove(puVar2[4]);
          }
          _objc_msgSend(uVar6,PTR_s_updatePhysicalParameters_001f93e4);
          _objc_msgSend(uVar6,PTR_s_diskBecameReady_001f9c14);
          uVar7 = _objc_msgSend(PTR_s_IODeviceDescription_001f9da0,PTR_s_new_001f9468);
          _objc_msgSend(uVar7,PTR_s_setDirectDevice__001f9cc0,uVar6);
          cVar3 = _objc_msgSend(PTR_s_IODiskPartition_001f9ddc,PTR_s_probe__001f9460,uVar7);
          if (cVar3 == '\0') {
            _objc_msgSend(uVar7,PTR_s_free_001f921c);
          }
          if (*(char *)((int)puVar2 + 0xd) == '\0') {
            FUN_001a7c70(uVar6,(int)*(short *)(puVar2 + 1),(int)*(short *)((int)puVar2 + 6));
          }
          else {
            *(undefined1 *)((int)puVar2 + 0xd) = 0;
          }
        }
      }
      else if (uVar5 == 3) {
        if (local_8 == 0) {
          iVar1 = puVar2[2];
          puVar2[2] = iVar1 + -1;
          if (iVar1 == 1) {
            uVar6 = _objc_msgSend(uVar6,PTR_s_unit_001f9c28,0,"","",0,puVar2 + 4);
            _vol_panel_request(0,6,1,0,puVar2[5],uVar6);
            *(undefined1 *)(puVar2 + 3) = 1;
          }
        }
        else {
          _objc_msgSend(uVar6,PTR_s_setLastReadyState__001f9c6c,2);
          if (*(char *)(puVar2 + 3) != '\0') {
            *(undefined1 *)(puVar2 + 3) = 0;
            _vol_panel_remove(puVar2[4]);
          }
        }
      }
    }
    _IOSleep(1000);
  } while( true );
}

