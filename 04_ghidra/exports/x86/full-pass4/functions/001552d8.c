/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001552d8 */

kern_return_t
_mach_port_get_refs(ipc_space_t task,mach_port_name_t name,mach_port_right_t right,
                   mach_port_urefs_t *refs)

{
  kern_return_t kVar1;
  mach_port_urefs_t local_10;
  uint local_c;
  undefined4 local_8;
  
  if (task == 0) {
    kVar1 = 0x10;
  }
  else if (right < 5) {
    kVar1 = _ipc_right_lookup_write(task,name,&local_8);
    if ((kVar1 == 0) && (kVar1 = _ipc_right_info(task,name,local_8,&local_c,&local_10), kVar1 == 0))
    {
      LOCK();
      *(undefined4 *)(task + 8) = 0;
      UNLOCK();
      if ((local_c & 1 << ((char)right + 0x10U & 0x1f)) == 0) {
        *refs = 0;
      }
      else {
        if (right < 4) {
          if (right != 0) {
            *refs = 1;
            return 0;
          }
        }
        else if (right != 4) {
                    /* WARNING: Subroutine does not return */
          _panic(s_mach_port_get_refs__strange_righ_001deada);
        }
        *refs = local_10;
      }
    }
  }
  else {
    kVar1 = 0x12;
  }
  return kVar1;
}

