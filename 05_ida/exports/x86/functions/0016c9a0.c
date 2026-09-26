/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16c9a0. */
int __cdecl kern_serv_notify(_DWORD *a1, int a2, int a3)
{
  _DWORD *v3; // ebx
  int v4; // edx
  int result; // eax
  _DWORD *v6; // edx
  _DWORD *v7; // edx
  _DWORD *v8; // ecx
  int v9; // [esp+10h] [ebp-8h] BYREF
  int v10; // [esp+14h] [ebp-4h] BYREF

  v3 = (_DWORD *)*a1; /*0x16c9b2*/
  v4 = *(_DWORD *)(active_threads + 12); /*0x16c9b9*/
  if ( kernel_task == v4 ) /*0x16c9c2*/
  {
    result = get_kern_port(v4, a3, &v10); /*0x16ca42*/
    if ( !result ) /*0x16ca4c*/
    {
      result = get_kern_port(*(_DWORD *)(active_threads + 12), a2, &v9); /*0x16ca5c*/
      if ( !result ) /*0x16ca66*/
      {
        port_request_notification(v10, v9); /*0x16ca70*/
        return 0; /*0x16ca75*/
      }
    }
  }
  else if ( v3[7] == a2 ) /*0x16c9c7*/
  {
    return 0; /*0x16c9c9*/
  }
  else
  {
    v6 = (_DWORD *)v3[304]; /*0x16c9d0*/
    if ( v3 + 304 == v6 ) /*0x16c9de*/
    {
LABEL_8:
      v7 = (_DWORD *)kalloc(0x10u); /*0x16c9f4*/
      *v7 = a2; /*0x16ca00*/
      v7[1] = a3; /*0x16ca05*/
      v8 = (_DWORD *)v3[305]; /*0x16ca08*/
      if ( v3 + 304 == v8 ) /*0x16ca16*/
        v3[304] = v7; /*0x16ca18*/
      else
        v8[2] = v7; /*0x16ca20*/
      v7[3] = v8; /*0x16ca23*/
      v7[2] = v3 + 304; /*0x16ca2c*/
      v3[305] = v7; /*0x16ca2f*/
      return 0; /*0x16ca35*/
    }
    else
    {
      while ( *v6 != a2 || v6[1] != a3 ) /*0x16c9e7*/
      {
        v6 = (_DWORD *)v6[2]; /*0x16c9ed*/
        if ( v3 + 304 == v6 ) /*0x16c9f2*/
          goto LABEL_8; /*0x16c9f2*/
      }
      return 5; /*0x16ca7c*/
    }
  }
  return result; /*0x16ca84*/
}
