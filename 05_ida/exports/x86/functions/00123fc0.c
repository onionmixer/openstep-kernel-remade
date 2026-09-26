/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x123fc0. */
_DWORD *__cdecl in_addmulti(int a1, int a2)
{
  _DWORD *v2; // eax
  _DWORD *v3; // ebx
  _DWORD *v4; // esi
  int *v5; // eax
  int v6; // edi
  int v8; // [esp+Ch] [ebp-24h]
  _BYTE v9[16]; // [esp+10h] [ebp-20h] BYREF
  __int16 v10; // [esp+20h] [ebp-10h]
  int v11; // [esp+24h] [ebp-Ch]

  v8 = splnet(); /*0x123fce*/
  v2 = (_DWORD *)in_ifaddr; /*0x123fd1*/
  if ( !in_ifaddr ) /*0x123fd8*/
    goto LABEL_10; /*0x123fd8*/
  do /*0x123fe9*/
  {
    if ( v2[8] == a2 ) /*0x123fe2*/
      break; /*0x123fe2*/
    v2 = (_DWORD *)v2[16]; /*0x123fe4*/
  }
  while ( v2 ); /*0x123fe9*/
  if ( !v2 ) /*0x123fed*/
    goto LABEL_10; /*0x123fed*/
  v3 = (_DWORD *)v2[17]; /*0x123fef*/
  if ( !v3 ) /*0x123ff4*/
    goto LABEL_10; /*0x123ff4*/
  do /*0x124004*/
  {
    if ( *v3 == a1 ) /*0x123ffd*/
      break; /*0x123ffd*/
    v3 = (_DWORD *)v3[5]; /*0x123fff*/
  }
  while ( v3 ); /*0x124004*/
  if ( v3 ) /*0x124008*/
  {
    ++v3[3]; /*0x12400a*/
  }
  else
  {
LABEL_10:
    v4 = (_DWORD *)in_ifaddr; /*0x124014*/
    if ( !in_ifaddr ) /*0x12401c*/
      goto LABEL_15; /*0x12401c*/
    do /*0x12402d*/
    {
      if ( v4[8] == a2 ) /*0x124026*/
        break; /*0x124026*/
      v4 = (_DWORD *)v4[16]; /*0x124028*/
    }
    while ( v4 ); /*0x12402d*/
    if ( !v4 || (v5 = m_getclr(0, 15), (v6 = (int)v5) == 0) ) /*0x124043*/
    {
LABEL_15:
      splx(v8); /*0x124049*/
      return nullptr; /*0x124050*/
    }
    v3 = (int *)((char *)v5 + v5[1]); /*0x124056*/
    *v3 = a1; /*0x12405c*/
    v3[1] = a2; /*0x124061*/
    v3[3] = 1; /*0x124064*/
    v3[2] = v4; /*0x12406b*/
    v3[5] = v4[17]; /*0x124071*/
    v4[17] = v3; /*0x124074*/
    v10 = 2; /*0x12407a*/
    v11 = a1; /*0x124083*/
    if ( *(_DWORD *)(a2 + 56) && !if_ioctl(a2, 0x80206931, (int)v9) ) /*0x1240a0*/
    {
      igmp_joingroup(v3); /*0x1240b5*/
    }
    else
    {
      v4[17] = v3[5]; /*0x1240a5*/
      m_free(v6); /*0x1240a9*/
      v3 = nullptr; /*0x1240ae*/
    }
  }
  splx(v8); /*0x1240c1*/
  return v3; /*0x1240cb*/
}
