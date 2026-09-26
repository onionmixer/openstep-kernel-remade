/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15dc34. */
int __cdecl receive_ip_datagram(int *a1)
{
  int v1; // ecx
  char *v2; // esi
  int *v3; // eax
  char *v5; // ebx
  int *v6; // eax
  __int16 v7; // dx
  __int16 v8; // dx
  int v9; // edx
  int v10; // edx
  int v11; // ecx
  signed __int32 v12; // ebx
  int *v13; // [esp+Ch] [ebp-24h]
  _DWORD *v14; // [esp+Ch] [ebp-24h]
  char *v15; // [esp+10h] [ebp-20h]
  int v16; // [esp+10h] [ebp-20h]
  unsigned int v17; // [esp+10h] [ebp-20h]
  int v18; // [esp+14h] [ebp-1Ch]
  int v19; // [esp+14h] [ebp-1Ch]
  int v20; // [esp+14h] [ebp-1Ch]
  char *v21; // [esp+28h] [ebp-8h]
  int v22; // [esp+2Ch] [ebp-4h]

  v1 = *a1; /*0x15dc40*/
  v2 = (char *)(*(_DWORD *)(v1 + 4) + v1); /*0x15dc44*/
  v15 = v2; /*0x15dc47*/
  if ( (*v2 & 0xFu) > 5 ) /*0x15dc52*/
  {
    v18 = *a1; /*0x15dc57*/
    ip_stripoptions((unsigned int)v2, 0); /*0x15dc5a*/
    v1 = v18; /*0x15dc62*/
  }
  if ( *(_DWORD *)(v1 + 4) > 0x7Cu || *(_WORD *)(v1 + 8) <= 0x17u ) /*0x15dc70*/
  {
    v3 = m_pullup(v1, 24); /*0x15dc75*/
    v1 = (int)v3; /*0x15dc7a*/
    *a1 = (int)v3; /*0x15dc7c*/
    if ( !v3 ) /*0x15dc83*/
      return 1; /*0x15dc8a*/
    v15 = (char *)v3 + v3[1]; /*0x15dc95*/
  }
  v5 = (char *)&listeners + 8 * (v15[9] & 0xF); /*0x15dcc9*/
  v6 = *((int **)v5 + 1); /*0x15dcd0*/
  v13 = v6; /*0x15dcd3*/
  if ( v6 ) /*0x15dcd8*/
  {
    while ( 1 ) /*0x15dcdc*/
    {
      v7 = *((_WORD *)v6 + 7); /*0x15dcdc*/
      if ( !v7 || *((_WORD *)v15 + 11) == v7 ) /*0x15dce9*/
      {
        v8 = *((_WORD *)v6 + 6); /*0x15dceb*/
        if ( !v8 || *((_WORD *)v15 + 10) == v8 ) /*0x15dcf8*/
        {
          v9 = v6[1]; /*0x15dcfa*/
          if ( !v9 || *((_DWORD *)v15 + 3) == v9 ) /*0x15dd04*/
          {
            v10 = v6[2]; /*0x15dd06*/
            if ( !v10 || *((_DWORD *)v15 + 4) == v10 ) /*0x15dd10*/
              break; /*0x15dd10*/
          }
        }
      }
      v13 = v6; /*0x15dd30*/
      v6 = (int *)*v6; /*0x15dd33*/
      if ( !v6 ) /*0x15dd37*/
        goto LABEL_21; /*0x15dd37*/
    }
    if ( *((int **)v5 + 1) != v6 ) /*0x15dd15*/
    {
      *v13 = *v6; /*0x15dd1c*/
      *v6 = *((_DWORD *)v5 + 1); /*0x15dd21*/
      *((_DWORD *)v5 + 1) = v6; /*0x15dd23*/
    }
    v22 = v6[4]; /*0x15dd29*/
  }
  else
  {
LABEL_21:
    v22 = 0; /*0x15dd39*/
  }
  if ( !v22 ) /*0x15dd44*/
    return 0; /*0x15dd46*/
  v19 = v1; /*0x15dd50*/
  spl0(); /*0x15dd53*/
  v14 = (_DWORD *)zget(mach_net_kmsg_zone); /*0x15dd64*/
  v11 = v19; /*0x15dd6a*/
  if ( v14 ) /*0x15dd6f*/
  {
    v14[2] = -3; /*0x15dd7f*/
    v14[3] = 0; /*0x15dd86*/
    v14[4] = 0; /*0x15dd8d*/
    *((_WORD *)v15 + 1) += 4 * (*v15 & 0xF); /*0x15dda1*/
    *((__int16 *)v15 + 3) >>= 3; /*0x15dda5*/
    v16 = 2004; /*0x15ddaa*/
    v21 = (char *)(v14 + 11); /*0x15ddb4*/
    if ( v19 ) /*0x15ddb9*/
    {
      do /*0x15ddf9*/
      {
        if ( v16 <= 0 ) /*0x15ddc0*/
          break; /*0x15ddc0*/
        v12 = *(__int16 *)(v11 + 8); /*0x15ddc2*/
        if ( v16 < v12 ) /*0x15ddc9*/
          v12 = v16; /*0x15ddcb*/
        v20 = v11; /*0x15ddd9*/
        bcopy((const void *)(*(_DWORD *)(v11 + 4) + v11), v21, v12); /*0x15dddc*/
        v21 += v12; /*0x15dde3*/
        v16 -= v12; /*0x15dde6*/
        v11 = m_free(v20); /*0x15ddf2*/
      }
      while ( v11 ); /*0x15ddf9*/
    }
    v14[4] = v16; /*0x15de01*/
    v17 = v16 & 0xFFFFFFFC; /*0x15de07*/
    v14[4] = v17 - v14[4]; /*0x15de10*/
    qmemcpy(v14 + 5, &dword_1E5BAC, 0x18u); /*0x15de28*/
    v14[6] -= v17; /*0x15de30*/
    v14[7] = v22; /*0x15de36*/
    ipc_object_reference(v22); /*0x15de3a*/
    ipc_mqueue_send((int)v14, 0x10000, 0, 0); /*0x15de4c*/
  }
  else
  {
    m_freem(v19); /*0x15dd72*/
  }
  splnet(); /*0x15de54*/
  return 1; /*0x15de61*/
}
