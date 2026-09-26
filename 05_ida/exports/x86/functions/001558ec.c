/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1558ec. */
kern_return_t __cdecl mach_port_request_notification(
        ipc_space_t task,
        mach_port_name_t name,
        mach_msg_id_t msgid,
        mach_port_mscount_t sync,
        mach_port_t notify,
        mach_msg_type_name_t notifyPoly,
        mach_port_t *previous)
{
  kern_return_t result; // eax
  int v8; // eax
  volatile __int32 *v9; // [esp+Ch] [ebp-Ch] BYREF
  int v10; // [esp+10h] [ebp-8h] BYREF
  volatile __int32 *v11; // [esp+14h] [ebp-4h] BYREF

  if ( !task ) /*0x155906*/
    return 16; /*0x15590d*/
  if ( notify == -1 ) /*0x155917*/
    return 20; /*0x15591e*/
  if ( msgid == 70 ) /*0x155927*/
  {
    result = ipc_object_translate(task, name, 1, &v9); /*0x1559a7*/
    if ( result ) /*0x1559b1*/
      return result; /*0x1559b1*/
    ipc_port_nsrequest((int)v9, sync, notify, (_DWORD *)notifyPoly); /*0x1559ba*/
    return 0; /*0x1559bf*/
  }
  if ( msgid > 70 ) /*0x155929*/
  {
    if ( msgid != 72 ) /*0x155937*/
      return 18; /*0x155949*/
    result = ipc_right_dnrequest(task, name, sync != 0, notify, (_DWORD *)notifyPoly); /*0x1559d6*/
    if ( !result ) /*0x1559dd*/
      return 0; /*0x1559dd*/
  }
  else
  {
    if ( msgid != 69 || sync ) /*0x155942*/
      return 18; /*0x155942*/
    result = ipc_object_translate(task, name, 1, &v11); /*0x15595b*/
    if ( !result ) /*0x155965*/
    {
      ipc_port_pdrequest((int)v11, notify, &v10); /*0x155970*/
      v8 = v10; /*0x155978*/
      if ( v10 ) /*0x15597d*/
      {
        if ( (v10 & 1) != 0 ) /*0x155981*/
        {
          LOBYTE(v8) = v10 & 0xFE; /*0x155983*/
          ipc_port_release_send(v8); /*0x155986*/
          v10 = 0; /*0x15598b*/
        }
      }
      *(_DWORD *)notifyPoly = v10; /*0x155995*/
      return 0; /*0x1559df*/
    }
  }
  return result; /*0x1559e4*/
}
