/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15612c. */
int __cdecl port_set_backup(unsigned int a1, unsigned int a2, int a3, _DWORD *a4)
{
  int v4; // ebx
  int result; // eax
  int v6; // edx
  volatile __int32 *v7; // edx
  int v8; // eax
  int v9; // [esp+Ch] [ebp-14h] BYREF
  int v10; // [esp+10h] [ebp-10h] BYREF
  int v11; // [esp+14h] [ebp-Ch] BYREF
  int *v12; // [esp+18h] [ebp-8h] BYREF
  volatile __int32 *v13; // [esp+1Ch] [ebp-4h]

  v4 = a3; /*0x156138*/
  if ( !a1 ) /*0x15613d*/
    return 4; /*0x15613d*/
  if ( a3 == -1 ) /*0x15614f*/
  {
    v4 = 0; /*0x156151*/
  }
  else if ( a3 ) /*0x15615a*/
  {
    LOBYTE(v4) = a3 | 1; /*0x15615c*/
  }
  if ( ipc_right_lookup_write(a1, a2, &v12) || ipc_right_info(a1, a2, v12, &v11, &v10) ) /*0x156185*/
    return 4; /*0x156144*/
  v6 = v11; /*0x156191*/
  if ( (v11 & 0x20000) != 0 ) /*0x15619a*/
  {
    v7 = (volatile __int32 *)v12[1]; /*0x1561bb*/
    do /*0x1561d2*/
    {
      while ( *v7 ) /*0x1561c0*/
        ; /*0x1561c2*/
    }
    while ( _InterlockedExchange(v7, 1) == 1 ); /*0x1561d2*/
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x1561d6*/
    v13 = v7; /*0x1561d9*/
    result = 0; /*0x1561dc*/
  }
  else
  {
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x15619e*/
    result = 4; /*0x1561a1*/
    if ( (v6 & 0x170000) != 0 ) /*0x1561ac*/
      return 7; /*0x1561b3*/
  }
  if ( !result ) /*0x1561e0*/
  {
    ipc_port_pdrequest((int)v13, v4, &v9); /*0x1561eb*/
    v8 = v9; /*0x1561f3*/
    if ( v9 ) /*0x1561f8*/
    {
      if ( (v9 & 1) != 0 ) /*0x1561fc*/
      {
        LOBYTE(v8) = v9 & 0xFE; /*0x1561fe*/
        v9 = v8; /*0x156200*/
      }
      else
      {
        ipc_notify_send_once(v9); /*0x156209*/
        v9 = 0; /*0x15620e*/
      }
    }
    *a4 = v9; /*0x15621b*/
    return 0; /*0x15621d*/
  }
  return result; /*0x156222*/
}
