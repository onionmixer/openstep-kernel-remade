/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x155858. */
kern_return_t __cdecl mach_port_move_member(ipc_space_t task, mach_port_name_t member, mach_port_name_t after)
{
  kern_return_t result; // eax
  int v4; // esi
  unsigned int v5; // eax
  int *v6; // eax
  int *v7; // [esp+Ch] [ebp-4h] BYREF

  if ( !task ) /*0x155869*/
    return 16; /*0x155870*/
  result = ipc_right_lookup_write(task, member, &v7); /*0x15587d*/
  if ( !result ) /*0x155887*/
  {
    if ( (*((_BYTE *)v7 + 2) & 2) != 0 ) /*0x155890*/
    {
      v4 = v7[1]; /*0x155892*/
      if ( !after ) /*0x155897*/
      {
        v5 = 0; /*0x155899*/
        return ipc_pset_move(task, v4, v5); /*0x1558da*/
      }
      v6 = ipc_entry_lookup((_DWORD *)task, after); /*0x1558a2*/
      v7 = v6; /*0x1558a7*/
      if ( !v6 ) /*0x1558af*/
      {
        _InterlockedExchange((volatile __int32 *)(task + 8), 0); /*0x1558b3*/
        return 15; /*0x1558bb*/
      }
      if ( (*((_BYTE *)v6 + 2) & 8) != 0 ) /*0x1558c4*/
      {
        v5 = v6[1]; /*0x1558d4*/
        return ipc_pset_move(task, v4, v5); /*0x1558d4*/
      }
    }
    _InterlockedExchange((volatile __int32 *)(task + 8), 0); /*0x1558c8*/
    return 17; /*0x1558cb*/
  }
  return result; /*0x1558e2*/
}
