/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14f804. */
unsigned __int32 __cdecl ipc_right_copyin_undo(_DWORD *a1, unsigned int a2, int *a3, int a4, int a5, int a6)
{
  unsigned __int32 result; // eax
  int v7; // ebx
  unsigned int v8; // ebx

  result = *a3; /*0x14f813*/
  if ( a6 ) /*0x14f819*/
  {
    result = result & 0xFF800000 | 0x100002; /*0x14f820*/
    *a3 = result; /*0x14f825*/
  }
  else if ( (result & 0x1F0000) != 0 ) /*0x14f834*/
  {
    if ( (int *)(result & 0x1F0000) == &dword_100000 ) /*0x14f84e*/
    {
      if ( a4 != 19 ) /*0x14f853*/
        *a3 = ++result; /*0x14f85a*/
    }
    else
    {
      if ( a4 != 19 ) /*0x14f867*/
        *a3 = result + 1; /*0x14f86a*/
      do /*0x14f87e*/
      {
        while ( *(_DWORD *)a5 ) /*0x14f86c*/
          ; /*0x14f86e*/
        result = _InterlockedExchange((volatile __int32 *)a5, 1) ^ 1; /*0x14f879*/
      }
      while ( !result ); /*0x14f87e*/
      if ( *(int *)(a5 + 8) >= 0 ) /*0x14f884*/
      {
        _InterlockedExchange((volatile __int32 *)a5, 0); /*0x14f88c*/
        v7 = *a3; /*0x14f88e*/
        if ( (*a3 & 0x10000) != 0 ) /*0x14f896*/
        {
          if ( (v7 & 0x200000) != 0 ) /*0x14f89e*/
          {
            v7 &= ~0x200000u; /*0x14f8a0*/
            ipc_marequest_cancel((unsigned int)a1, a2); /*0x14f8ae*/
          }
          ipc_hash_delete((int)a1, a5, a2, (int)a3); /*0x14f8c0*/
        }
        ipc_object_release(a5); /*0x14f8c9*/
        if ( (v7 & 0x400000) != 0 ) /*0x14f8d7*/
        {
          a3[2] = 0; /*0x14f8d9*/
          a3[1] = 0; /*0x14f8e0*/
          result = (unsigned __int32)ipc_entry_dealloc(a1, a2, a3); /*0x14f8f0*/
        }
        else
        {
          result = v7 & 0xFFE0FFFF; /*0x14f8fe*/
          v8 = v7 & 0xFFE0FFFF | 0x100000; /*0x14f905*/
          if ( a3[2] ) /*0x14f90b*/
          {
            a3[2] = 0; /*0x14f911*/
            ++v8; /*0x14f918*/
          }
          *a3 = v8; /*0x14f919*/
          a3[1] = 0; /*0x14f91b*/
        }
      }
    }
  }
  else
  {
    result = result & 0xFF800000 | 0x100001; /*0x14f83b*/
    *a3 = result; /*0x14f840*/
  }
  if ( a5 != -1 ) /*0x14f925*/
    return ipc_object_release(a5); /*0x14f928*/
  return result; /*0x14f930*/
}
