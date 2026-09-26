/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001558ec */

kern_return_t
_mach_port_request_notification
          (ipc_space_t task,mach_port_name_t name,mach_msg_id_t msgid,mach_port_mscount_t sync,
          mach_port_t notify,mach_msg_type_name_t notifyPoly,mach_port_t *previous)

{
  kern_return_t kVar1;
  int iVar2;
  undefined4 local_10;
  uint local_c;
  undefined4 local_8;
  
  if (task == 0) {
    return 0x10;
  }
  if (notify == 0xffffffff) {
    return 0x14;
  }
  if (msgid == 0x46) {
    iVar2 = _ipc_object_translate(task,name,1,&local_10);
    if (iVar2 != 0) {
      return iVar2;
    }
    _ipc_port_nsrequest(local_10,sync,notify,notifyPoly);
LAB_001559df:
    kVar1 = 0;
  }
  else {
    if (msgid < 0x47) {
      if ((msgid == 0x45) && (sync == 0)) {
        iVar2 = _ipc_object_translate(task,name,1,&local_8);
        if (iVar2 != 0) {
          return iVar2;
        }
        _ipc_port_pdrequest(local_8,notify,&local_c);
        if ((local_c != 0) && ((local_c & 1) != 0)) {
          _ipc_port_release_send(local_c & 0xfffffffe);
          local_c = 0;
        }
        *(uint *)notifyPoly = local_c;
        goto LAB_001559df;
      }
    }
    else if (msgid == 0x48) {
      iVar2 = _ipc_right_dnrequest(task,name,sync != 0,notify,notifyPoly);
      if (iVar2 != 0) {
        return iVar2;
      }
      goto LAB_001559df;
    }
    kVar1 = 0x12;
  }
  return kVar1;
}

