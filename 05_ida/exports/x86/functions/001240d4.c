/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1240d4. */
int __cdecl in_delmulti(int *a1)
{
  int v1; // esi
  int v2; // eax
  int i; // edx
  int v4; // eax
  _BYTE v6[16]; // [esp+8h] [ebp-20h] BYREF
  __int16 v7; // [esp+18h] [ebp-10h]
  int v8; // [esp+1Ch] [ebp-Ch]

  v1 = splnet(); /*0x1240e4*/
  v2 = a1[3]; /*0x1240e6*/
  a1[3] = v2 - 1; /*0x1240ec*/
  if ( v2 == 1 ) /*0x1240f2*/
  {
    igmp_leavegroup(a1); /*0x1240f5*/
    for ( i = a1[2] + 68; *(int **)i != a1; i = *(_DWORD *)i + 20 ) /*0x124106*/
      ; /*0x12410a*/
    *(_DWORD *)i = *(_DWORD *)(*(_DWORD *)i + 20); /*0x124117*/
    v7 = 2; /*0x124119*/
    v8 = *a1; /*0x124121*/
    if_ioctl(a1[1], 0x80206932, (int)v6); /*0x124131*/
    v4 = (int)a1; /*0x124136*/
    LOBYTE(v4) = (unsigned __int8)a1 & 0x80; /*0x124138*/
    m_free(v4); /*0x12413b*/
  }
  return splx(v1); /*0x12414c*/
}
