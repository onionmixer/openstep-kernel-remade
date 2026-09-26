/* GHIDRADEC_FUNCTION index=1250 start=0x4046e9e */

undefined4 _port_deallocate(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined auStack_10 [4];
  uint uStack_c;
  undefined4 uStack_8;
  
  if ((((param_1 != 0) && (iVar1 = _ipc_right_lookup_write(param_1,param_2,&uStack_8), iVar1 == 0))
      && (iVar1 = _ipc_right_info(param_1,param_2,uStack_8,&uStack_c,auStack_10), iVar1 == 0)) &&
     ((uStack_c & 0x170000) != 0)) {
    _ipc_right_destroy(param_1,param_2,uStack_8);
    return 0;
  }
  return 4;
}
/* GHIDRADEC_FUNCTION index=1251 start=0x4046f12 */

int _port_set_backlog(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uStack_8;
  
  if ((param_1 == 0) || (0xf < param_3 - 1U)) {
    iVar1 = 4;
  }
  else {
    iVar1 = _port_translate_compat(param_1,param_2,&uStack_8);
    if (iVar1 == 0) {
      _ipc_port_set_qlimit(uStack_8,param_3);
      iVar1 = 0;
    }
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1252 start=0x4046f5e */

int _port_set_backup(int param_1,undefined4 param_2,uint param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  uint uStack_c;
  undefined4 uStack_8;
  
  if (param_1 == 0) {
    iVar1 = 4;
  }
  else {
    if (param_3 == 0xffffffff) {
      uVar2 = 0;
    }
    else {
      uVar2 = 0;
      if (param_3 != 0) {
        uVar2 = param_3 | 1;
      }
    }
    iVar1 = _port_translate_compat(param_1,param_2,&uStack_8);
    if (iVar1 == 0) {
      _ipc_port_pdrequest(uStack_8,uVar2,&uStack_c);
      if (uStack_c != 0) {
        if ((uStack_c & 1) == 0) {
          _ipc_notify_send_once(uStack_c);
          uStack_c = 0;
        }
        else {
          uStack_c = uStack_c & 0xfffffffe;
        }
      }
      *param_4 = uStack_c;
      iVar1 = 0;
    }
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1253 start=0x4046fec */

undefined4
_port_status(int param_1,undefined4 param_2,int *param_3,undefined4 *param_4,undefined4 *param_5,
            undefined4 *param_6,undefined4 *param_7)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined auStack_10 [4];
  uint uStack_c;
  int iStack_8;
  
  if ((((param_1 == 0) || (iVar4 = _ipc_right_lookup_write(param_1,param_2,&iStack_8), iVar4 != 0))
      || (iVar4 = _ipc_right_info(param_1,param_2,iStack_8,&uStack_c,auStack_10), iVar4 != 0)) ||
     ((uStack_c & 0x170000) == 0)) {
    return 4;
  }
  if ((uStack_c & 0x20000) == 0) {
    *param_6 = 0;
    *param_7 = 0;
    *param_3 = 0;
    *param_4 = 0xffffffff;
    *param_5 = 0;
    return 0;
  }
  iVar4 = *(int *)(iStack_8 + 4);
  piVar1 = *(int **)(iVar4 + 0x2c);
  if (piVar1 != (int *)0x0) {
    if (piVar1[1] < 0) {
      iVar5 = piVar1[2];
      goto loc_40470A0;
    }
    _ipc_pset_remove(piVar1,iVar4);
    if (*piVar1 == 0) {
      _zfree((&_ipc_object_zones)[*(word *)(piVar1 + 1) & 0x7fff],piVar1);
    }
  }
  iVar5 = 0;
loc_40470A0:
  uVar2 = *(undefined4 *)(iVar4 + 0x38);
  uVar3 = *(undefined4 *)(iVar4 + 0x34);
  *param_6 = 1;
  *param_7 = 1;
  *param_3 = iVar5;
  *param_4 = uVar3;
  *param_5 = uVar2;
  return 0;
}
/* GHIDRADEC_FUNCTION index=1254 start=0x40470e6 */

undefined4 _port_set_allocate(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined auStack_8 [4];
  
  if (param_1 != 0) {
    iVar1 = _ipc_pset_alloc(param_1,param_2,auStack_8);
    if (iVar1 == 0) {
      return 0;
    }
    if (iVar1 == 6) {
      return 6;
    }
  }
  return 4;
}
/* GHIDRADEC_FUNCTION index=1255 start=0x4047110 */

int _port_set_deallocate(int param_1,undefined4 param_2)

{
  int iVar1;
  int iStack_8;
  
  if (param_1 != 0) {
    iVar1 = _ipc_right_lookup_write(param_1,param_2,&iStack_8);
    if (iVar1 != 0) {
      return iVar1;
    }
    if ((*(byte *)(iStack_8 + 1) & 8) != 0) {
      iVar1 = _ipc_right_destroy(param_1,param_2,iStack_8);
      return iVar1;
    }
  }
  return 4;
}
/* GHIDRADEC_FUNCTION index=1256 start=0x4047162 */

undefined4 _port_set_add(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined auStack_10 [4];
  uint uStack_c;
  int iStack_8;
  
  if (((param_1 != 0) && (iVar1 = _ipc_right_lookup_write(param_1,param_3,&iStack_8), iVar1 == 0))
     && (iVar1 = _ipc_right_info(param_1,param_3,iStack_8,&uStack_c,auStack_10), iVar1 == 0)) {
    if ((uStack_c & 0x20000) == 0) {
      if ((uStack_c & 0x170000) == 0) {
        return 4;
      }
      return 7;
    }
    uVar2 = *(undefined4 *)(iStack_8 + 4);
    iStack_8 = _ipc_entry_lookup(param_1,param_2);
    if ((iStack_8 != 0) && ((*(byte *)(iStack_8 + 1) & 8) != 0)) {
      uVar2 = _ipc_pset_move(param_1,uVar2,*(undefined4 *)(iStack_8 + 4));
      return uVar2;
    }
  }
  return 4;
}
/* GHIDRADEC_FUNCTION index=1257 start=0x4047208 */

undefined4 _port_set_remove(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined auStack_10 [4];
  uint uStack_c;
  int iStack_8;
  
  if (((param_1 == 0) || (iVar1 = _ipc_right_lookup_write(param_1,param_2,&iStack_8), iVar1 != 0))
     || (iVar1 = _ipc_right_info(param_1,param_2,iStack_8,&uStack_c,auStack_10), iVar1 != 0)) {
    return 4;
  }
  if ((uStack_c & 0x20000) != 0) {
    uVar2 = _ipc_pset_move(param_1,*(undefined4 *)(iStack_8 + 4),0);
    return uVar2;
  }
  if ((uStack_c & 0x170000) == 0) {
    return 4;
  }
  return 7;
}
/* GHIDRADEC_FUNCTION index=1258 start=0x404728c */

int _port_set_status(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = _mach_port_get_set_status(param_1,param_2,param_3,param_4);
  if ((iVar1 != 0) && (iVar1 != 6)) {
    iVar1 = 4;
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1259 start=0x40472b6 */

undefined4 _port_insert_send(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if ((((param_1 != 0) && (param_3 != 0)) && (param_3 != -1)) && ((param_2 != 0 && (param_2 != -1)))
     ) {
    iVar1 = _ipc_object_copyout_name_compat(param_1,param_2,0x11,param_3);
    if (iVar1 == 6) {
      return 6;
    }
    if (iVar1 < 7) {
      if (iVar1 == 0) {
        return 0;
      }
    }
    else {
      if (iVar1 == 0xd) {
        return 0xd;
      }
      if (iVar1 == 0x15) {
        return 5;
      }
    }
  }
  return 4;
}
/* GHIDRADEC_FUNCTION index=1260 start=0x4047314 */

undefined4 _port_extract_send(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if ((param_1 != 0) && (iVar1 = _ipc_object_copyin_compat(param_1,param_2,6,1,param_3), iVar1 == 0)
     ) {
    return 0;
  }
  return 4;
}
/* GHIDRADEC_FUNCTION index=1261 start=0x4047340 */

undefined4 _port_insert_receive(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if ((((param_1 != 0) && (param_3 != 0)) && (param_3 != -1)) && ((param_2 != 0 && (param_2 != -1)))
     ) {
    iVar1 = _ipc_object_copyout_name_compat(param_1,param_2,0x10,param_3);
    if (iVar1 == 6) {
      return 6;
    }
    if (iVar1 < 7) {
      if (iVar1 == 0) {
        return 0;
      }
    }
    else {
      if (iVar1 == 0xd) {
        return 0xd;
      }
      if (iVar1 == 0x15) {
        return 5;
      }
    }
  }
  return 4;
}
/* GHIDRADEC_FUNCTION index=1262 start=0x404739e */

undefined4 _port_extract_receive(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if ((param_1 != 0) && (iVar1 = _ipc_object_copyin_compat(param_1,param_2,5,1,param_3), iVar1 == 0)
     ) {
    return 0;
  }
  return 4;
}
/* GHIDRADEC_FUNCTION index=1263 start=0x40473ca */

void _ast_init(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=1264 start=0x40473d2 */

undefined4 _ast_check(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  byte bVar6;
  int iVar7;
  word wVar8;
  sword sVar10;
  int *piVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  bool bVar16;
  uint uVar9;
  
  iVar4 = _processor_ptr;
  iVar7 = _active_threads;
  uVar9 = *(uint *)(_processor_ptr + 0x110);
  bVar15 = 1 < uVar9;
  if (uVar9 != 1) {
    if ((int)uVar9 < 2) {
      bVar14 = false;
      bVar12 = (int)uVar9 < 0;
      bVar13 = true;
      bVar16 = false;
      if (uVar9 != 0) {
loc_4047590:
                    /* WARNING: Subroutine does not return */
        _panic(aAstCheckBadPro);
      }
    }
    else {
      bVar15 = 3 < uVar9;
      bVar14 = SBORROW4(3,uVar9);
      bVar12 = (int)(3 - uVar9) < 0;
      bVar13 = uVar9 == 3;
      bVar16 = bVar15;
      if (3 < (int)uVar9) goto loc_4047590;
    }
    goto loc_404759C;
  }
  iVar1 = *_active_u;
  if ((iVar1 != 0) &&
     (((*(char *)(iVar1 + 0x17) != '\0' ||
       (((_active_threads != 0 &&
         (uVar9 = *(uint *)(*(int *)(_active_threads + 0x80) + 0x72) | *(uint *)(iVar1 + 0x18),
         uVar9 != 0)) &&
        (((*(byte *)(iVar1 + 0x2b) & 0x10) != 0 ||
         ((uVar9 & ~(*(uint *)(iVar1 + 0x1c) | *(uint *)(iVar1 + 0x20))) != 0)))))) &&
      (_need_ast = _need_ast | 0x20, _need_ast != 0)))) {
    pbVar5 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
    *pbVar5 = *pbVar5 | 0x10;
  }
  _need_ast = *(uint *)(iVar7 + 0x174) | _need_ast;
  if (_need_ast != 0) {
    pbVar5 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
    *pbVar5 = *pbVar5 | 0x10;
  }
  bVar12 = (int)_need_ast < 0;
  bVar13 = _need_ast == 0;
  bVar14 = false;
  uVar9 = _need_ast;
  bVar16 = false;
  if (!bVar13) goto loc_404759C;
  if (((*(byte *)(iVar7 + 0x4b) & 2) == 0) && (*(int *)(iVar4 + 0x104) < 1)) {
    iVar1 = *(int *)(iVar4 + 0x128);
    if ((*(byte *)(iVar1 + 0x15b) & 2) == 0) {
      bVar14 = false;
      bVar12 = *(int *)(iVar4 + 0x120) < 0;
      bVar13 = *(int *)(iVar4 + 0x120) == 0;
      bVar16 = false;
      if (!bVar13) goto loc_404759C;
      bVar14 = false;
      bVar12 = *(int *)(iVar1 + 0x104) < 0;
      iVar4 = *(int *)(iVar1 + 0x104);
      bVar13 = iVar4 == 0;
      bVar16 = false;
      if (iVar4 < 1) goto loc_404759C;
      uVar9 = *(uint *)(iVar1 + 0x100);
      piVar11 = (int *)(iVar1 + uVar9 * 8);
      if (piVar11 == (int *)*piVar11) {
        piVar11 = (int *)(iVar1 + uVar9 * 8);
        if (-1 < (int)uVar9) {
          do {
            if (piVar11 != (int *)*piVar11) break;
            piVar11 = piVar11 + -2;
            wVar8 = (word)(uVar9 >> 0x10);
            sVar10 = (sword)uVar9 + -1;
            uVar9 = CONCAT22(wVar8,sVar10);
          } while ((sVar10 != -1) || (uVar9 = (uint)wVar8 * 0x10000 - 1, wVar8 != 0));
        }
        *(uint *)(iVar1 + 0x100) = uVar9;
      }
      uVar2 = *(uint *)(iVar1 + 0x100);
      uVar3 = *(uint *)(iVar7 + 0x54);
      bVar15 = uVar2 < uVar3;
      bVar14 = SBORROW4(uVar2,uVar3);
      bVar12 = (int)(uVar2 - uVar3) < 0;
      bVar13 = uVar2 == uVar3;
      bVar16 = bVar15;
      if ((int)uVar2 < (int)uVar3) goto loc_404759C;
    }
    else {
      uVar2 = *(uint *)(iVar1 + 0x100);
      uVar3 = *(uint *)(iVar7 + 0x54);
      uVar9 = *(uint *)(iVar7 + 0x5c);
      if (((uVar9 == 2) || (2 < (int)uVar9)) || (uVar9 != 1)) {
        if (((*(int *)(iVar1 + 0x104) == 0) || (bVar15 = uVar3 < uVar2, (int)uVar2 < (int)uVar3)) ||
           (((int)uVar2 <= (int)uVar3 && (*(int *)(iVar4 + 0x120) != 0)))) goto loc_4047512;
      }
      else if (((*(int *)(iVar4 + 0x120) != 0) || (*(int *)(iVar1 + 0x104) < 1)) ||
              (bVar15 = uVar3 < uVar2, (int)uVar2 < (int)uVar3)) {
loc_4047512:
        uVar2 = *(uint *)(iVar7 + 0x5c);
        bVar15 = 2 < uVar2;
        bVar14 = SBORROW4(2,uVar2);
        bVar12 = (int)(2 - uVar2) < 0;
        bVar13 = false;
        bVar16 = bVar15;
        if (uVar2 == 2) {
          *(undefined4 *)(iVar4 + 0x120) = 1;
          bVar12 = false;
          bVar13 = false;
          bVar14 = false;
          bVar16 = false;
        }
        goto loc_404759C;
      }
    }
  }
  _need_ast = _need_ast | 4;
  uVar9 = _need_ast;
  bVar14 = false;
  bVar12 = (int)_need_ast < 0;
  bVar13 = _need_ast == 0;
  bVar16 = false;
  if (!bVar13) {
    pbVar5 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
    bVar6 = *pbVar5;
    bVar13 = (bVar6 & 0x10) == 0;
    *pbVar5 = bVar6 | 0x10;
  }
loc_404759C:
  return CONCAT22((sword)(uVar9 >> 0x10),
                  (word)(byte)(bVar15 << 4 | bVar12 << 3 | bVar13 << 2 | bVar14 << 1 | bVar16));
}
/* GHIDRADEC_FUNCTION index=1265 start=0x40475aa */

void _exception_with_continuation
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = _active_threads;
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aException);
  }
  *(undefined4 *)(_active_threads + 0x34) = param_4;
  piVar1 = *(int **)(iVar2 + 0xac);
  if (((piVar1 == (int *)0x0) || (piVar1 == (int *)0xffffffff)) || (-1 < piVar1[1])) {
    _exception_try_task(param_1,param_2,param_3);
  }
  else {
    *piVar1 = *piVar1 + 1;
    piVar1[6] = piVar1[6] + 1;
    *(int *)(iVar2 + 0xc0) = param_1;
    *(undefined4 *)(iVar2 + 0xc4) = param_2;
    *(undefined4 *)(iVar2 + 200) = param_3;
    uVar3 = _retrieve_task_self_fast(*(undefined4 *)(iVar2 + 0xc),param_1,param_2,param_3);
    uVar3 = _retrieve_thread_self_fast(iVar2,uVar3);
    _exception_raise(piVar1,uVar3);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1266 start=0x404763e */

void _exception(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = _active_threads;
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aException);
  }
  *(code **)(_active_threads + 0x34) = _thread_exception_return;
  piVar1 = *(int **)(iVar2 + 0xac);
  if (((piVar1 == (int *)0x0) || (piVar1 == (int *)0xffffffff)) || (-1 < piVar1[1])) {
    _exception_try_task(param_1,param_2,param_3);
  }
  else {
    *piVar1 = *piVar1 + 1;
    piVar1[6] = piVar1[6] + 1;
    *(int *)(iVar2 + 0xc0) = param_1;
    *(undefined4 *)(iVar2 + 0xc4) = param_2;
    *(undefined4 *)(iVar2 + 200) = param_3;
    uVar3 = _retrieve_task_self_fast(*(undefined4 *)(iVar2 + 0xc),param_1,param_2,param_3);
    uVar3 = _retrieve_thread_self_fast(iVar2,uVar3);
    _exception_raise(piVar1,uVar3);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1267 start=0x40476d4 */

void _exception_from_kernel(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  
  iVar6 = _active_threads;
  uVar1 = *(undefined4 *)(_active_threads + 0x34);
  uVar2 = *(undefined4 *)(_active_threads + 0xc0);
  uVar3 = *(undefined4 *)(_active_threads + 0xc4);
  uVar4 = *(undefined4 *)(_active_threads + 200);
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aException);
  }
  *(undefined4 *)(_active_threads + 0x34) = 0;
  piVar5 = *(int **)(iVar6 + 0xac);
  if (((piVar5 == (int *)0x0) || (piVar5 == (int *)0xffffffff)) || (-1 < piVar5[1])) {
    _exception_try_task(param_1,param_2,param_3);
  }
  else {
    *piVar5 = *piVar5 + 1;
    piVar5[6] = piVar5[6] + 1;
    *(int *)(iVar6 + 0xc0) = param_1;
    *(undefined4 *)(iVar6 + 0xc4) = param_2;
    *(undefined4 *)(iVar6 + 200) = param_3;
    uVar7 = _retrieve_task_self_fast(*(undefined4 *)(iVar6 + 0xc),param_1,param_2,param_3);
    uVar7 = _retrieve_thread_self_fast(iVar6,uVar7);
    _exception_raise(piVar5,uVar7);
  }
  *(undefined4 *)(iVar6 + 0x34) = uVar1;
  *(undefined4 *)(iVar6 + 0xc0) = uVar2;
  *(undefined4 *)(iVar6 + 0xc4) = uVar3;
  *(undefined4 *)(iVar6 + 200) = uVar4;
  return;
}
/* GHIDRADEC_FUNCTION index=1268 start=0x4047788 */

void _exception_try_task(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = _active_threads;
  iVar1 = *(int *)(_active_threads + 0xc);
  piVar2 = *(int **)(iVar1 + 100);
  if (((piVar2 == (int *)0x0) || (piVar2 == (int *)0xffffffff)) || (-1 < piVar2[1])) {
    _exception_no_server();
  }
  else {
    *piVar2 = *piVar2 + 1;
    piVar2[6] = piVar2[6] + 1;
    *(undefined4 *)(iVar3 + 0xc0) = 0;
    uVar4 = _retrieve_task_self_fast(iVar1,param_1,param_2,param_3);
    uVar4 = _retrieve_thread_self_fast(iVar3,uVar4);
    _exception_raise(piVar2,uVar4);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1269 start=0x40477f4 */

void _exception_no_server(void)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = _active_threads;
  uVar1 = *(uint *)(_active_threads + 0x177);
  while ((uVar1 & 0x3ffffff) >> 0x18 != 0) {
    _thread_halt_self();
    uVar1 = *(uint *)(iVar2 + 0x177);
  }
  _task_terminate(*(undefined4 *)(iVar2 + 0xc));
  _thread_halt_self();
  return;
}
/* GHIDRADEC_FUNCTION index=1270 start=0x404782e */

void _exception_raise(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                     undefined4 param_5,undefined4 param_6)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  undefined4 uVar12;
  code *pcVar13;
  int *piVar14;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iVar6 = _ipc_kmsg_cache;
  iVar5 = _active_threads;
  if (_ipc_kmsg_cache == 0) {
    iVar6 = _kalloc(0x100);
    if (iVar6 == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(aExceptionRaise);
    }
    *(undefined4 *)(iVar6 + 8) = 0x100;
    *(undefined4 *)(iVar6 + 0xc) = 0;
  }
  else {
    _ipc_kmsg_cache = 0;
  }
  *(undefined4 *)(iVar6 + 0x10) = 0;
  piVar7 = *(int **)(iVar5 + 0xb8);
  if (piVar7 == (int *)0x0) {
    piVar7 = (int *)_ipc_port_alloc_special(_ipc_space_reply);
    if ((piVar7 == (int *)0x0) || (*(int *)(iVar5 + 0xb8) != 0)) {
                    /* WARNING: Subroutine does not return */
      _panic(aExceptionRaise);
    }
    *(int **)(iVar5 + 0xb8) = piVar7;
  }
  piVar7[7] = piVar7[7] + 1;
  *piVar7 = *piVar7 + 2;
  *(int **)(iVar5 + 0xbc) = piVar7;
  if ((param_1[1] < 0) && (param_1[2] != _ipc_space_kernel)) {
    if (param_1[0xb] == 0) {
      piVar14 = param_1 + 0xf;
    }
    else {
      piVar14 = (int *)(param_1[0xb] + 0xc);
    }
    iVar2 = piVar14[1];
    if (((iVar2 != 0) && (*(int *)(iVar5 + 0x34) != 0)) &&
       ((*(code **)(iVar2 + 0x30) == _mach_msg_continue ||
        (((*(code **)(iVar2 + 0x30) == _mach_msg_receive_continue &&
          (0x3f < *(uint *)(iVar2 + 0x98))) && ((*(byte *)(iVar2 + 0xc2) & 2) == 0)))))) {
      iVar8 = _thread_handoff(iVar5,_exception_raise_continue,iVar2);
      if (iVar8 != 0) {
        iVar8 = piVar7[0x10];
        if (iVar8 == 0) {
          piVar7[0x10] = iVar5;
        }
        else {
          iVar9 = *(int *)(iVar8 + 0x90);
          *(int *)(iVar5 + 0x8c) = iVar8;
          *(int *)(iVar5 + 0x90) = iVar9;
          *(int *)(iVar8 + 0x90) = iVar5;
          *(int *)(iVar9 + 0x8c) = iVar5;
        }
        *(undefined4 *)(iVar5 + 0x94) = 0x10004001;
        *(undefined4 *)(iVar5 + 0x98) = 0xffffffff;
        iVar8 = *(int *)(iVar2 + 0x8c);
        if (iVar2 == iVar8) {
          piVar14[1] = 0;
        }
        else {
          iVar9 = *(int *)(iVar2 + 0x90);
          piVar14[1] = iVar8;
          *(int *)(iVar8 + 0x90) = iVar9;
          *(int *)(iVar9 + 0x8c) = iVar8;
          *(int *)(iVar2 + 0x8c) = iVar2;
          *(int *)(iVar2 + 0x90) = iVar2;
        }
        piVar14 = *(int **)(iVar2 + 0xd0);
        iVar8 = *piVar14;
        *piVar14 = iVar8 + -1;
        if (iVar8 == 1) {
          _zfree((&_ipc_object_zones)[*(word *)(piVar14 + 1) & 0x7fff],piVar14);
        }
        puVar4 = (undefined4 *)(iVar6 + 0x14);
        iVar8 = *(int *)(*(int *)(iVar2 + 0xc) + 0x7c);
        *puVar4 = 0x80001112;
        *(undefined4 *)(iVar6 + 0x18) = 0x40;
        *(undefined4 *)(iVar6 + 0x24) = 0;
        *(undefined4 *)(iVar6 + 0x28) = 0x960;
        *(undefined4 *)(iVar6 + 0x2c) = _exc_port_proto;
        *(undefined4 *)(iVar6 + 0x34) = _exc_port_proto;
        *(undefined4 *)(iVar6 + 0x3c) = _exc_code_proto;
        *(undefined4 *)(iVar6 + 0x40) = param_4;
        *(undefined4 *)(iVar6 + 0x44) = _exc_code_proto;
        *(undefined4 *)(iVar6 + 0x48) = param_5;
        *(undefined4 *)(iVar6 + 0x4c) = _exc_code_proto;
        *(undefined4 *)(iVar6 + 0x50) = param_6;
        if (*(uint *)(iVar2 + 0xc4) < 0x40) {
          *puVar4 = 0x80001211;
          *(int **)(iVar6 + 0x1c) = param_1;
          *(int **)(iVar6 + 0x20) = piVar7;
          *(undefined4 *)(iVar6 + 0x30) = param_2;
          *(undefined4 *)(iVar6 + 0x38) = param_3;
          _ipc_kmsg_destroy(iVar6);
          _thread_syscall_return(0x10004004);
        }
        if (param_1[1] < 0) goto loc_4047AE8;
        do {
          do {
            *puVar4 = 0x80001211;
            *(int **)(iVar6 + 0x1c) = param_1;
            *(int **)(iVar6 + 0x20) = piVar7;
            iVar9 = _ipc_kmsg_copyout_header(puVar4,iVar8,0);
            if (iVar9 == 0) goto loc_4047B7A;
            *(undefined4 *)(iVar6 + 0x30) = param_2;
            *(undefined4 *)(iVar6 + 0x38) = param_3;
            _ipc_kmsg_copyout_dest(iVar6,iVar8);
            _ipc_kmsg_put(*(undefined4 *)(iVar2 + 0xbc),iVar6,0x18);
            _thread_syscall_return(iVar9);
loc_4047AE8:
          } while (-1 < piVar7[1]);
          iVar9 = *(int *)(iVar8 + 0xc);
          iVar3 = *(int *)(iVar9 + 8);
        } while (iVar3 == 0);
        puVar1 = (uint *)(iVar9 + iVar3 * 0x10);
        *(uint *)(iVar9 + 8) = puVar1[2];
        puVar1[2] = 0;
        uVar10 = *puVar1;
        *(uint *)(iVar6 + 0x1c) = uVar10 + 0x1000000 >> 0x18 | iVar3 << 8;
        *puVar1 = uVar10 + 0x1000000 | 0x40001;
        puVar1[1] = (uint)piVar7;
        *param_1 = *param_1 + -1;
        iVar9 = 0;
        if (iVar8 == param_1[2]) {
          iVar9 = param_1[3];
        }
        *(int *)(iVar6 + 0x20) = iVar9;
        iVar9 = param_1[6];
        param_1[6] = iVar9 + -1;
        if ((iVar9 == 1) && (iVar9 = param_1[8], iVar9 != 0)) {
          param_1[8] = 0;
          _ipc_notify_no_senders(iVar9,param_1[5]);
        }
loc_4047B7A:
        uVar10 = _ipc_kmsg_copyout_object(iVar8,param_2,0x11,iVar6 + 0x30);
        uVar11 = _ipc_kmsg_copyout_object(iVar8,param_3,0x11,iVar6 + 0x38);
        if ((uVar11 | uVar10) != 0) {
          _ipc_kmsg_put(*(undefined4 *)(iVar2 + 0xbc),iVar6,*(undefined4 *)(iVar6 + 0x18));
          _thread_syscall_return(uVar11 | uVar10 | 0x1000400c);
        }
        *(undefined4 *)(iVar6 + 0x10) = 0;
        iVar8 = _copyoutmsg(iVar6 + 0x14,*(undefined4 *)(iVar2 + 0xbc),0x40);
        if ((iVar8 != 0) || (_ipc_kmsg_cache != 0)) {
          uVar12 = _ipc_kmsg_put(*(undefined4 *)(iVar2 + 0xbc),iVar6,*(undefined4 *)(iVar6 + 0x18));
          _thread_syscall_return(uVar12);
        }
        _ipc_kmsg_cache = iVar6;
        _thread_syscall_return(0);
      }
    }
  }
  _exception_raise_misses = _exception_raise_misses + 1;
  *(undefined4 *)(iVar6 + 0x14) = 0x80001211;
  *(undefined4 *)(iVar6 + 0x18) = 0x40;
  *(int **)(iVar6 + 0x1c) = param_1;
  *(int **)(iVar6 + 0x20) = piVar7;
  *(undefined4 *)(iVar6 + 0x24) = 0;
  *(undefined4 *)(iVar6 + 0x28) = 0x960;
  *(undefined4 *)(iVar6 + 0x2c) = _exc_port_proto;
  *(undefined4 *)(iVar6 + 0x30) = param_2;
  *(undefined4 *)(iVar6 + 0x34) = _exc_port_proto;
  *(undefined4 *)(iVar6 + 0x38) = param_3;
  *(undefined4 *)(iVar6 + 0x3c) = _exc_code_proto;
  *(undefined4 *)(iVar6 + 0x40) = param_4;
  *(undefined4 *)(iVar6 + 0x44) = _exc_code_proto;
  *(undefined4 *)(iVar6 + 0x48) = param_5;
  *(undefined4 *)(iVar6 + 0x4c) = _exc_code_proto;
  *(undefined4 *)(iVar6 + 0x50) = param_6;
  _ipc_mqueue_send(iVar6,0x10000,0,0);
  if (piVar7[1] < 0) {
    pcVar13 = (code *)0x0;
    if (*(int *)(iVar5 + 0x34) != 0) {
      pcVar13 = _exception_raise_continue;
    }
    uVar12 = _ipc_mqueue_receive(piVar7 + 0xf,0,0xffffffff,0,0,pcVar13,&uStack_8,&uStack_c);
  }
  else {
    uStack_c = 0;
    uStack_8 = 0;
    uVar12 = 0x10004009;
  }
  _exception_raise_continue_slow(uVar12,uStack_8,uStack_c);
  return;
}
/* GHIDRADEC_FUNCTION index=1271 start=0x4047d08 */

undefined4 _exception_parse_reply(int param_1)

{
  undefined4 uVar1;
  
  if ((((*(int *)(param_1 + 0x14) == 0x12) && (*(int *)(param_1 + 0x18) == 0x20)) &&
      (*(int *)(param_1 + 0x28) == 0x9c4)) && (*(int *)(param_1 + 0x2c) == _exc_code_proto)) {
    uVar1 = *(undefined4 *)(param_1 + 0x30);
    if ((*(int *)(param_1 + 8) == 0x100) && (_ipc_kmsg_cache == 0)) {
      _ipc_kmsg_cache = param_1;
    }
    else if (*(int *)(param_1 + 8) < 1) {
      _ipc_kmsg_free(param_1);
    }
    else {
      _kfree(param_1,*(int *)(param_1 + 8));
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x1c) = 0;
    _ipc_kmsg_destroy(param_1);
    uVar1 = 0xfffffed3;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1272 start=0x4047d8c */

void _exception_raise_continue(void)

{
  undefined4 uVar1;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uVar1 = _ipc_mqueue_receive(*(int *)(_active_threads + 0xbc) + 0x3c,0,0xffffffff,0,1,
                              _exception_raise_continue,&uStack_8,&uStack_c);
  _exception_raise_continue_slow(uVar1,uStack_8,uStack_c);
  return;
}
/* GHIDRADEC_FUNCTION index=1273 start=0x4047dd6 */

void _exception_raise_continue_slow(int param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = _active_threads;
  iVar3 = *(int *)(_active_threads + 0xbc);
  iVar4 = iVar3 + 0x3c;
  while (param_1 == 0x10004005) {
    while ((*(uint *)(iVar1 + 0x177) & 0x3ffffff) >> 0x18 != 0) {
      if ((iVar3 != 0) && (iVar3 != -1)) {
        _ipc_object_release(iVar3);
      }
      *(undefined4 *)(iVar1 + 0xbc) = 0;
      iVar4 = 0;
      _thread_halt_self_with_continuation(0);
      iVar3 = *(int *)(iVar1 + 0xb8);
      *(int *)(iVar1 + 0xbc) = iVar3;
      if ((iVar3 != 0) && (iVar3 != -1)) {
        _ipc_object_reference(iVar3);
        iVar4 = iVar3 + 0x3c;
      }
    }
    if (((iVar3 == 0) || (iVar3 == -1)) || (-1 < *(int *)(iVar3 + 4))) {
      param_1 = 0x10004009;
      break;
    }
    pcVar2 = (code *)0x0;
    if (*(int *)(iVar1 + 0x34) != 0) {
      pcVar2 = _exception_raise_continue;
    }
    param_1 = _ipc_mqueue_receive(iVar4,0,0xffffffff,0,0,pcVar2,&param_2,&stack0x0000000c);
  }
  if ((iVar3 != 0) && (iVar3 != -1)) {
    _ipc_object_release(iVar3);
  }
  if (param_1 == 0) {
    _ipc_port_release_sonce(iVar3);
    param_1 = _exception_parse_reply(param_2);
    if (param_1 != 0) goto loc_4047EC8;
  }
  else {
loc_4047EC8:
    if (param_1 != 0x10004009) goto loc_4047EE0;
  }
  if (*(int *)(iVar1 + 0x34) == 0) {
    return;
  }
  _call_continuation(*(int *)(iVar1 + 0x34));
loc_4047EE0:
  if (*(int *)(iVar1 + 0xc0) == 0) {
    _exception_no_server();
  }
  else {
    _exception_try_task(*(int *)(iVar1 + 0xc0),*(undefined4 *)(iVar1 + 0xc4),
                        *(undefined4 *)(iVar1 + 200));
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1274 start=0x4047f10 */

void _exception_raise_continue_fast(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _active_threads;
  param_1[7] = param_1[7] + -1;
  *param_1 = *param_1 + -2;
  iVar2 = _exception_parse_reply(param_2);
  if (iVar2 == 0) {
    if (*(int *)(iVar1 + 0x34) != 0) {
      _call_continuation(*(int *)(iVar1 + 0x34));
    }
    _thread_exception_return();
  }
  else {
    if (*(int *)(iVar1 + 0xc0) != 0) {
      _exception_try_task(*(int *)(iVar1 + 0xc0),*(undefined4 *)(iVar1 + 0xc4),
                          *(undefined4 *)(iVar1 + 200));
    }
    _exception_no_server();
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1275 start=0x4047f76 */

undefined4 _host_processors(int param_1,undefined4 *param_2,uint *param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else {
    uVar5 = 0;
    iVar3 = 0;
    piVar6 = &_machine_slot;
    do {
      if (*piVar6 != 0) {
        uVar5 = uVar5 + 1;
      }
      piVar6 = piVar6 + 8;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 1);
    if (uVar5 == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(aHostProcessors);
    }
    puVar2 = (undefined4 *)_kalloc(uVar5 << 2);
    if (puVar2 == (undefined4 *)0x0) {
      uVar1 = 6;
    }
    else {
      iVar3 = 0;
      puVar9 = &_processor_ptr;
      piVar6 = &_machine_slot;
      puVar7 = puVar2;
      do {
        puVar8 = puVar7;
        if (*piVar6 != 0) {
          puVar8 = puVar7 + 1;
          *puVar7 = *puVar9;
        }
        puVar9 = puVar9 + 1;
        piVar6 = piVar6 + 8;
        iVar3 = iVar3 + 1;
        puVar7 = puVar8;
      } while (iVar3 < 1);
      *param_3 = uVar5;
      *param_2 = puVar2;
      uVar4 = 0;
      if (uVar5 != 0) {
        do {
          uVar1 = _convert_processor_to_port(*puVar2);
          *puVar2 = uVar1;
          uVar4 = uVar4 + 1;
          puVar2 = puVar2 + 1;
        } while (uVar4 < uVar5);
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1276 start=0x4048022 */

undefined4 _host_info(int param_1,int param_2,int *param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  
  if (param_1 != 0) {
    if (param_2 != 2) {
      if (param_2 < 3) {
        if (param_2 != 1) {
          return 4;
        }
        if (*param_4 < 5) {
          return 5;
        }
        *param_3 = dword_40C22D0;
        param_3[1] = dword_40C22D4;
        param_3[2] = dword_40C22D8;
        iVar1 = _master_processor;
        param_3[3] = (&dword_40B5DCC)[*(int *)(_master_processor + 0x13c) * 8];
        param_3[4] = (&dword_40B5DD0)[*(int *)(iVar1 + 0x13c) * 8];
        uVar2 = 5;
      }
      else if (param_2 == 3) {
        if (*param_4 < 2) {
          return 5;
        }
        iVar1 = _tick / 1000;
        *param_3 = iVar1;
        param_3[1] = iVar1;
        uVar2 = 2;
      }
      else {
        if (param_2 != 4) {
          return 4;
        }
        if (*param_4 < 6) {
          return 5;
        }
        _bcopy(_avenrun,param_3,0xc);
        _bcopy(_mach_factor,param_3 + 3,0xc);
        uVar2 = 6;
      }
      *param_4 = uVar2;
      return 0;
    }
    if (*param_4 != 0) {
      *param_4 = 0;
      iVar1 = 0;
      piVar3 = &_machine_slot;
      do {
        piVar4 = param_3;
        if ((*piVar3 != 0) && ((&dword_40B5DD4)[iVar1 * 8] != 0)) {
          piVar4 = param_3 + 1;
          *param_3 = iVar1;
          *param_4 = *param_4 + 1;
        }
        piVar3 = piVar3 + 8;
        iVar1 = iVar1 + 1;
        param_3 = piVar4;
      } while (iVar1 < 1);
      return 0;
    }
  }
  return 4;
}
/* GHIDRADEC_FUNCTION index=1277 start=0x404814a */

undefined4 _host_kernel_version(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else {
    _strncpy(param_2,_version,0x200);
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1278 start=0x4048172 */

undefined4 _host_processor_sets(int param_1,int *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else {
    puVar2 = (undefined4 *)_kalloc(4);
    if (puVar2 == (undefined4 *)0x0) {
      uVar1 = 6;
    }
    else {
      _pset_reference(_default_pset);
      uVar1 = _convert_pset_name_to_port(_default_pset);
      *puVar2 = uVar1;
      *param_2 = (int)puVar2;
      *param_3 = 1;
      uVar1 = 0;
    }
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1279 start=0x40481ce */

undefined4 _host_processor_set_priv(int param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    *param_3 = 0;
    uVar1 = 4;
  }
  else {
    *param_3 = param_2;
    _pset_reference(param_2);
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1280 start=0x40481fa */

void _ipc_host_init(void)

{
  int iVar1;
  
  iVar1 = _ipc_port_alloc_special(_ipc_space_kernel);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aIpcHostInit);
  }
  _ipc_kobject_set(iVar1,&_realhost,3);
  _realhost = iVar1;
  iVar1 = _ipc_port_alloc_special(_ipc_space_kernel);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aIpcHostInit);
  }
  _ipc_kobject_set(iVar1,&_realhost,4);
  dword_40B67DC = iVar1;
  _ipc_pset_init(_default_pset);
  _ipc_pset_enable(_default_pset);
  _ipc_processor_init(_master_processor);
  return;
}
/* GHIDRADEC_FUNCTION index=1281 start=0x404829c */

void _mach_host_self(void)

{
  undefined4 uVar1;
  
  uVar1 = _ipc_port_make_send(_realhost);
  _ipc_port_copyout_send(uVar1,*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x7c));
  return;
}
/* GHIDRADEC_FUNCTION index=1282 start=0x40482c6 */

void _host_self(void)

{
  undefined4 uVar1;
  
  uVar1 = _ipc_port_make_send(_realhost);
  _ipc_port_copyout_send_compat(uVar1,*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x7c));
  return;
}
/* GHIDRADEC_FUNCTION index=1283 start=0x40482f0 */

void _ipc_processor_init(int param_1)

{
  int iVar1;
  
  iVar1 = _ipc_port_alloc_special(_ipc_space_kernel);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aIpcProcessorIn);
  }
  *(int *)(param_1 + 0x138) = iVar1;
  _ipc_kobject_set(iVar1,param_1,5);
  return;
}
/* GHIDRADEC_FUNCTION index=1284 start=0x404833a */

void _ipc_pset_init(int param_1)

{
  int iVar1;
  
  iVar1 = _ipc_port_alloc_special(_ipc_space_kernel);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aIpcPsetInit);
  }
  *(int *)(param_1 + 0x14c) = iVar1;
  iVar1 = _ipc_port_alloc_special(_ipc_space_kernel);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aIpcPsetInit);
  }
  *(int *)(param_1 + 0x150) = iVar1;
  return;
}
/* GHIDRADEC_FUNCTION index=1285 start=0x4048394 */

void _ipc_pset_enable(int param_1)

{
  if (*(int *)(param_1 + 0x148) != 0) {
    _ipc_kobject_set(*(undefined4 *)(param_1 + 0x14c),param_1,6);
    _ipc_kobject_set(*(undefined4 *)(param_1 + 0x150),param_1,7);
    *(int *)(param_1 + 0x13c) = *(int *)(param_1 + 0x13c) + 2;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1286 start=0x40483d4 */

void _ipc_pset_disable(int param_1)

{
  _ipc_kobject_set(*(undefined4 *)(param_1 + 0x14c),0,0);
  _ipc_kobject_set(*(undefined4 *)(param_1 + 0x150),0,0);
  *(int *)(param_1 + 0x13c) = *(int *)(param_1 + 0x13c) + -2;
  return;
}
/* GHIDRADEC_FUNCTION index=1287 start=0x404840a */

void _ipc_pset_terminate(int param_1)

{
  _ipc_port_dealloc_special(*(undefined4 *)(param_1 + 0x14c),_ipc_space_kernel);
  _ipc_port_dealloc_special(*(undefined4 *)(param_1 + 0x150),_ipc_space_kernel);
  return;
}
/* GHIDRADEC_FUNCTION index=1288 start=0x4048440 */

undefined4 _processor_set_default(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else {
    *param_2 = _default_pset;
    _pset_reference(_default_pset);
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1289 start=0x404846a */

undefined4 _xxx_processor_set_default_priv(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else {
    *param_2 = _default_pset;
    _pset_reference(_default_pset);
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1290 start=0x4048494 */

undefined4 _convert_port_to_host(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((((param_1 != 0) && (param_1 != -1)) && ((int)*(uint *)(param_1 + 4) < 0)) &&
     ((*(uint *)(param_1 + 4) & 0xffff) - 3 < 2)) {
    uVar1 = *(undefined4 *)(param_1 + 0x10);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1291 start=0x40484cc */

undefined4 _convert_port_to_host_priv(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((((param_1 != 0) && (param_1 != -1)) && (*(int *)(param_1 + 4) < 0)) &&
     ((sword)*(int *)(param_1 + 4) == 4)) {
    uVar1 = *(undefined4 *)(param_1 + 0x10);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1292 start=0x40484fa */

undefined4 _convert_port_to_processor(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((((param_1 != 0) && (param_1 != -1)) && (*(int *)(param_1 + 4) < 0)) &&
     ((sword)*(int *)(param_1 + 4) == 5)) {
    uVar1 = *(undefined4 *)(param_1 + 0x10);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1293 start=0x4048528 */

undefined4 _convert_port_to_pset(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((((param_1 != 0) && (param_1 != -1)) && (*(int *)(param_1 + 4) < 0)) &&
     ((sword)*(int *)(param_1 + 4) == 6)) {
    uVar1 = *(undefined4 *)(param_1 + 0x10);
    _pset_reference(uVar1);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1294 start=0x4048560 */

undefined4 _convert_port_to_pset_name(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((((param_1 != 0) && (param_1 != -1)) && ((int)*(uint *)(param_1 + 4) < 0)) &&
     ((*(uint *)(param_1 + 4) & 0xffff) - 6 < 2)) {
    uVar1 = *(undefined4 *)(param_1 + 0x10);
    _pset_reference(uVar1);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1295 start=0x40485a0 */

void _convert_host_to_port(undefined4 *param_1)

{
  _ipc_port_make_send(*param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=1296 start=0x40485b4 */

void _convert_processor_to_port(int param_1)

{
  _ipc_port_make_send(*(undefined4 *)(param_1 + 0x138));
  return;
}
/* GHIDRADEC_FUNCTION index=1297 start=0x40485ca */

undefined4 _convert_pset_to_port(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x148) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = _ipc_port_make_send(*(undefined4 *)(param_1 + 0x14c));
  }
  _pset_deallocate(param_1);
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1298 start=0x4048604 */

undefined4 _convert_pset_name_to_port(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x148) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = _ipc_port_make_send(*(undefined4 *)(param_1 + 0x150));
  }
  _pset_deallocate(param_1);
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1299 start=0x404863e */

undefined * _ipc_kobject_server(undefined *param_1)

{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  int iVar4;
  code *pcVar5;
  undefined **ppuVar6;
  undefined *puStack_1c;
  undefined *puStack_18;
  
  puStack_18 = (undefined *)0x800;
  puStack_1c = (undefined *)0x4048658;
  puVar3 = (undefined *)_kalloc();
  if (puVar3 == (undefined *)0x0) {
    puStack_18 = aIpcKobjectServ;
    puStack_1c = (undefined *)0x404866c;
    _printf();
    ppuVar6 = &puStack_1c;
    puStack_1c = param_1;
    goto loc_40487F6;
  }
  *(undefined4 *)(puVar3 + 8) = 0x800;
  *(undefined4 *)(puVar3 + 0xc) = 0;
  *(undefined4 *)(puVar3 + 0x10) = 0;
  *(uint *)(puVar3 + 0x14) = (uint)(byte)param_1[0x16];
  *(undefined4 *)(puVar3 + 0x18) = 0x20;
  *(undefined4 *)(puVar3 + 0x1c) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(puVar3 + 0x20) = 0;
  *(undefined4 *)(puVar3 + 0x24) = 0;
  *(int *)(puVar3 + 0x28) = *(int *)(param_1 + 0x28) + 100;
  *(undefined4 *)(puVar3 + 0x2c) = dword_40AF788;
  puStack_18 = param_1;
  puStack_1c = (undefined *)0x40486b6;
  iVar4 = _netipc_msg_send();
  if (iVar4 == 0) {
    puVar1 = param_1 + 0x14;
    puStack_1c = (undefined *)0x40486d2;
    puStack_18 = puVar1;
    pcVar5 = (code *)_mach_server_routine();
    if (pcVar5 == (code *)0x0) {
      puStack_1c = (undefined *)0x40486e2;
      puStack_18 = puVar1;
      pcVar5 = (code *)_mach_port_server_routine();
      if (pcVar5 == (code *)0x0) {
        puStack_1c = (undefined *)0x40486f2;
        puStack_18 = puVar1;
        pcVar5 = (code *)_mach_host_server_routine();
        if (pcVar5 == (code *)0x0) {
          puStack_1c = (undefined *)0x4048702;
          puStack_18 = puVar1;
          pcVar5 = (code *)_mach_debug_server_routine();
          if (pcVar5 == (code *)0x0) {
            puStack_18 = puVar3 + 0x14;
            puStack_1c = puVar1;
            iVar4 = _ipc_kobject_notify();
            if (iVar4 == 0) {
              *(undefined4 *)(puVar3 + 0x30) = 0xfffffed1;
            }
            goto loc_4048732;
          }
        }
      }
    }
    puStack_18 = puVar3 + 0x14;
    puStack_1c = param_1 + 0x14;
    (*pcVar5)();
  }
  else {
    *(undefined4 *)(puVar3 + 0x30) = 0xfffffecf;
  }
loc_4048732:
  puVar2 = (undefined4 *)(param_1 + 0x1c);
  if (param_1[0x17] == '\x11') {
    puStack_18 = (undefined *)*puVar2;
    puStack_1c = (undefined *)0x4048752;
    _ipc_port_release_send();
  }
  else {
    if (param_1[0x17] != '\x12') {
      puStack_18 = aIpcObjectDestr;
                    /* WARNING: Subroutine does not return */
      puStack_1c = (undefined *)0x404876a;
      _panic();
    }
    puStack_18 = (undefined *)*puVar2;
    puStack_1c = (undefined *)0x404875c;
    _ipc_port_release_sonce();
  }
  *puVar2 = 0;
  iVar4 = *(int *)(puVar3 + 0x30);
  if ((iVar4 == 0) || (iVar4 == -0x131)) {
    *(undefined4 *)(param_1 + 0x10) = 0;
    if ((*(int *)(param_1 + 8) == 0x100) && (_ipc_kmsg_cache == (undefined *)0x0)) {
      _ipc_kmsg_cache = param_1;
    }
    else {
      puStack_18 = *(undefined **)(param_1 + 8);
      if ((int)puStack_18 < 1) {
        puStack_18 = param_1;
        puStack_1c = (undefined *)0x40487a6;
        _ipc_kmsg_free();
      }
      else {
        puStack_1c = param_1;
        _kfree();
      }
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x20) = 0;
    puStack_18 = param_1;
    puStack_1c = (undefined *)0x40487ce;
    _ipc_kmsg_destroy();
  }
  if (iVar4 == -0x131) {
    puStack_18 = *(undefined **)(puVar3 + 8);
    if ((int)puStack_18 < 1) {
      puStack_1c = (undefined *)0x40487e6;
      puStack_18 = puVar3;
      _ipc_kmsg_free();
      return (undefined *)0x0;
    }
    puStack_1c = puVar3;
    _kfree();
    return (undefined *)0x0;
  }
  if ((*(int *)(puVar3 + 0x1c) != 0) && (*(int *)(puVar3 + 0x1c) != -1)) {
    return puVar3;
  }
  ppuVar6 = &puStack_18;
  puStack_18 = puVar3;
loc_40487F6:
  *(undefined4 *)((int)ppuVar6 + -4) = 0x40487fc;
  _ipc_kmsg_destroy();
  return (undefined *)0x0;
}

