/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12a92c. */
int tcp_slowtimo()
{
  int *v0; // edi
  int v1; // edx
  int v2; // esi
  int v3; // ebx
  __int16 v4; // ax
  __int16 v5; // ax
  int v7; // [esp+Ch] [ebp-8h]
  int v8; // [esp+10h] [ebp-4h]

  v8 = splnet(); /*0x12a93a*/
  tcp_maxidle = 8 * tcp_keepintvl; /*0x12a946*/
  v0 = (int *)tcb; /*0x12a94c*/
  if ( tcb ) /*0x12a954*/
  {
    while ( v0 != &tcb ) /*0x12a9bf*/
    {
      v1 = *v0; /*0x12a958*/
      v2 = v0[8]; /*0x12a95a*/
      if ( v2 ) /*0x12a95f*/
      {
        v3 = 0; /*0x12a961*/
        while ( 1 ) /*0x12a964*/
        {
          v4 = *(_WORD *)(v2 + 2 * v3 + 10); /*0x12a964*/
          if ( v4 ) /*0x12a96c*/
          {
            *(_WORD *)(v2 + 2 * v3 + 10) = v4 - 1; /*0x12a972*/
            if ( v4 == 1 ) /*0x12a97b*/
            {
              v7 = v1; /*0x12a98b*/
              tcp_usrreq(*(_DWORD *)(*(_DWORD *)(v2 + 32) + 28), 19, 0, v3, 0); /*0x12a98e*/
              v1 = v7; /*0x12a996*/
              if ( *(int **)(v7 + 4) != v0 ) /*0x12a99c*/
                break; /*0x12a99c*/
            }
          }
          if ( ++v3 > 3 ) /*0x12a9a2*/
          {
            ++*(_WORD *)(v2 + 88); /*0x12a9a4*/
            v5 = *(_WORD *)(v2 + 90); /*0x12a9a8*/
            if ( v5 ) /*0x12a9af*/
              *(_WORD *)(v2 + 90) = v5 + 1; /*0x12a9b3*/
            break; /*0x12a9b3*/
          }
        }
      }
      v0 = (int *)v1; /*0x12a9b7*/
    }
    tcp_iss += 64000; /*0x12a9c1*/
  }
  return splx(v8); /*0x12a9d7*/
}
