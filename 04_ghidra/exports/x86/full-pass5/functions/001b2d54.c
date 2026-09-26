/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b2d54 */

int FUN_001b2d54(int param_1,undefined4 param_2,uint param_3,undefined4 param_4,char param_5)

{
  undefined1 uVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  _IOGetTimestamp(&local_c);
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),PTR_s_lock_001f9220);
  uVar1 = *(undefined1 *)(param_1 + 0x1c0);
  if (*(char *)(param_1 + 0x1d2) == '\0') {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x110),PTR_s_unlock_001f9474);
  }
  else {
    if (((param_3 & 4) != (*(uint *)(*(int *)(param_1 + 0x168) + 8) & 4)) &&
       (uVar1 = 0, (param_3 & 4) != 0)) {
      uVar1 = 0xff;
    }
    _objc_msgSend(*(undefined4 *)(param_1 + 0x110),PTR_s_unlock_001f9474);
    _objc_msgSend(param_1,PTR_s_absolutePointerEvent_at_inProxim_001f996c,param_3,param_4,
                  (int)param_5,uVar1,0x5a,local_c,local_8);
  }
  return param_1;
}

